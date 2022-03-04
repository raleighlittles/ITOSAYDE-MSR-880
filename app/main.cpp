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

    libusb_set_option(lusb_context, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_INFO);

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


    // Harcoded, got from Wireshark capture of doing a Magnetic stripe read

    std::array<uint8_t, 8> magstripeReadReq_1 = { 0x1b, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    std::array<uint8_t, 8> magstripeReadReq_2 = { 0x1b, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    rc = libusb_interrupt_transfer(lusb_dev_hndl, 0x01, magstripeReadReq_1.data(), magstripeReadReq_1.size(), bytes_transferred_cnt, 0);

    if (rc != libusb_error::LIBUSB_SUCCESS)
    {
        std::cerr << "ERROR: Couldn't send magstripe read sequence initiation command, rc=" << rc << std::endl;
        return -1;
    }


    return 0;
}