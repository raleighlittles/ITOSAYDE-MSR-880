import usb.core
import usb.util

import pdb

if __name__ == "__main__":

    endpointOut = 0x01

    msr880_usb_device = usb.core.find(idVendor=0x0802, idProduct=0x0005)

    if msr880_usb_device is None:
        raise ValueError("Unable to find device!")
    
    else:
        print("[DEBUG] Connected to USB device")

    if msr880_usb_device.is_kernel_driver_active(0):
        msr880_usb_device.detach_kernel_driver(0)

    if msr880_usb_device.is_kernel_driver_active(1):
        msr880_usb_device.detach_kernel_driver(1)
    
    connectData = [0x02, 0x00, 0x02, 0x0c, 0x19, 0x17, 0x00, 0x00]

    result = msr880_usb_device.write(endpointOut, connectData)

    if result != len(connectData):
        print(f"Error with first interrupt transfer, transmitted {len(connectData)} bytes but only received {result}")

    # Works up to here

    magstripeReadReq_1 = [0x1b, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]

    result = msr880_usb_device.write(endpointOut, magstripeReadReq_1)

    if result != len(magstripeReadReq_1):
        print(f"Error with second interrupt transfer, transmitted {len(magstripeReadReq_1)} bytes but only received {result}")

    # works up to here
        
    magstripeReadReq_2 = [0x1b, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]

    result = msr880_usb_device.write(endpointOut, magstripeReadReq_2)

    if result != len(magstripeReadReq_2):
        print(f"Error with third interrupt transfer, transmitted {len(magstripeReadReq_2)} bytes but only received {result}")