# 2022-03-04

Major issue -- how to relate URB_INTERRUPT seen in wireshark capture against libusb_calls?

As in, should there be one libusb_interrupt transfer for each URB_INTERRUPT seen, or should there only be one libusb_interrupt_transfer per host->target packet?