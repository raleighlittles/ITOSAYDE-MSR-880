/**
 *  File: main.cpp
 */

#include <iostream>
#include <array>
#include <stdint.h>
#include <chrono>
#include <thread>

#include <libusb-1.0/libusb.h>

#include "usb_wrapper.h"

int main(int argc, char* argv[]) {

    libusb_context* lusb_context = nullptr;

    int rc = libusb_init(&lusb_context);

    libusb_set_option(lusb_context, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_WARNING);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Failed to initialize libusb" << std::endl;
        return -1;
    }

    libusb_device_handle* lusb_dev_hndl = libusb_open_device_with_vid_pid(lusb_context, vendorID, productID);

    if (!lusb_dev_hndl)
    {
        std::cerr << "ERROR: libusb device handler null" << std::endl;
        return -1;
    }

    // libusb wouldn't be able to claim the device if the OS has already claimed it,
    // so check if the device is claimed already by the kernel, and if it is, then ask the kernel to unclaim it

    // Note: We have to do this twice, because the device has 2 'interface numbers' -- not sure why
    // See `bInterfaceNumber`

    for (unsigned int interface_num = 0; interface_num < 2; interface_num++)
    {
        if (libusb_kernel_driver_active(lusb_dev_hndl, interface_num))
        {
            if (libusb_detach_kernel_driver(lusb_dev_hndl, interface_num) != libusb_error::LIBUSB_SUCCESS)
            {
                std::cerr << "ERROR: Failed to detach kernel driver on interface #" << interface_num << std::endl;
                return -1;
            }
        }

        rc = libusb_claim_interface(lusb_dev_hndl, interface_num);
        if (rc != libusb_error::LIBUSB_SUCCESS)
        {
            std::cerr << "ERROR: libusb was unable to claim device on interface= " << interface_num << " , rc =" << rc << std::endl;
            return -1;
        }
    }

    //// ----------------------------------- ////
    //// BEGIN DEVICE-SPECIFIC COMMUNICATION ////
    //// ----------------------------------- ////

    // Hardcoded, got from Wireshark capture of pressing Connect button
    std::array<uint8_t, 8> connect_data = {0x02, 0x00, 0x02, 0x0c, 0x19, 0x17, 0x00, 0x00};
    
    int* bytes_transferred_cnt = nullptr;
    
    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointOut, connect_data.data(), connect_data.size(), bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Couldn't send connect sequence, rc=" << rc << std::endl;
        return -1;
    }

    // Get ready to do a magstripe read
    const unsigned int magstripeReadSize = 24; // TODO Where does this come from??
    unsigned char in_data[magstripeReadSize];
    std::fill(in_data, in_data + magstripeReadSize, 0); // for debug

    // Harcoded, got from Wireshark capture of doing a Magnetic stripe read

    std::array<uint8_t, 8> magstripeReadReq_1 = { 0x1b, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    std::array<uint8_t, 8> magstripeReadReq_2 = { 0x1b, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointOut, magstripeReadReq_1.data(), magstripeReadReq_1.size(), bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Couldn't send magstripe read sequence (pt 1), rc=" << rc << std::endl;
        return -1;
    }

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointOut, in_data, 0, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Couldn't send magstripe read sequence (pt 1), rc=" << rc << std::endl;
        return -1;
    }

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointOut, magstripeReadReq_2.data(), magstripeReadReq_2.size(), bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Couldn't send magstripe read sequence (pt 2), rc=" << rc << std::endl;
        return -1;
    }

    // Now get ready to read data in (though not now...?)

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointOut, in_data, 0, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Reader dropped its URB_INTERRUPT_OUT? rc=" << rc << std::endl;
        return -1;
    }

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, 8, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in, rc=" << rc << std::endl;
        return -1;
    }
    
    // This is where the "header" data gets transmitted
    unsigned char raw_header[8];

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, 8, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #2, rc=" << rc << std::endl;
        return -1;
    }

    // I keep calling this the 'header' -- the reader here will transmit 8 bytes, but I have no idea what they represent
    // It seems to have nothing to do with the actual card information itself
    // Debugging note: This is where the LED goes from green to blue

    const std::string magstripeReadHeader(reinterpret_cast<char*>(raw_header), 8);

    std::cout << "Header=" << magstripeReadHeader << std::endl;

    // Why is the transaction above actually the header??
    for (unsigned int i = 0; i < 8; i++) {
        std::cout << "i=" << i << ", data[i]=" << in_data[i] << std::endl;
    }

    // std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // sleep 

    // Now, here is where the actual card data starts to come in... Reader splits up the data into 3 packets (Why?)

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, magstripeReadSize / 3, bytes_transferred_cnt, 0); // Packet 1 of 3

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #3, rc=" << rc << std::endl;
        return -1;
    }

    // Store the data in the buffer (we'll have to add to it in each transaction)
    std::string magstripeReadData(reinterpret_cast<char*>(in_data), magstripeReadSize / 3);

    // // Tell the reader the first packet was received successfully?
    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, 0, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #4, rc=" << rc << std::endl;
        return -1;
    }

    // Now read the second 8 bytes.. You get the idea.

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, magstripeReadSize / 3, bytes_transferred_cnt, 0); // Packet 2 of 3

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #5, rc=" << rc << std::endl;
        return -1;
    }

    // Append the bytes you received
    magstripeReadData.append(reinterpret_cast<char*>(in_data), magstripeReadSize / 3);

    // Tell the reader the second packet was received successfully
    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, 0, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #6, rc=" << rc << std::endl;
        return -1;
    }

    // Now read the last 8 bytes

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, magstripeReadSize / 3, bytes_transferred_cnt, 0); // Packet 3 of 3

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #7, rc=" << rc << std::endl;
        return -1;
    }

    // Append the bytes you received
   // magstripeReadData.append(reinterpret_cast<char*>(in_data), magstripeReadSize / 3);

    std::cout << "DATA=" << magstripeReadData << std::endl;

    // Tell the reader the third packet was received successfully
    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, 0, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #8, rc=" << rc << std::endl;
        return -1;
    }

    // Calling this the 'footer' -- the reader will transmit 8 bytes, but just like with the 'header',
    // I have no idea what it actually means..

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, 8, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Can't send URB_INTERRUPT in #9, rc=" << rc << std::endl;
        return -1;
    }

    const std::string magstripeFooter(reinterpret_cast<char*>(in_data), 8);

    std::cout << "Footer=" << magstripeFooter << std::endl;

    // Tell the reader that the footer was received (??)

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointIn, in_data, 0, bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Couldn't send magstripe read sequence (pt 1), rc=" << rc << std::endl;
        return -1;
    }

    // Why is this transaction happening again??

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointOut, magstripeReadReq_2.data(), magstripeReadData.size(), bytes_transferred_cnt, 0);
    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Could'nt do 2nd to last transaction, rc=" << rc << std::endl;
        return -1;
    }

    // Tell the reader that the transaction is over??

    rc = libusb_interrupt_transfer(lusb_dev_hndl, endpointOut, in_data, 0, bytes_transferred_cnt, 0);
    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Couldn't send magstripe read sequence (pt 1), rc=" << rc << std::endl;
        return -1;
    }

    return 0;
}