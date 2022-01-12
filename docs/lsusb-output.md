Bus 001 Device 017: ID 0802:0005 Mako Technologies, LLC STM32 QWERT HID
Device Descriptor:
  bLength                18
  bDescriptorType         1
  bcdUSB               2.00
  bDeviceClass            0 
  bDeviceSubClass         0 
  bDeviceProtocol         0 
  bMaxPacketSize0        64
  idVendor           0x0802 Mako Technologies, LLC
  idProduct          0x0005 
  bcdDevice            2.00
  iManufacturer           1 SZZCS ZCS80
  iProduct                2 STM32 QWERT HID
  iSerial                 3 WÿlQVBg
  bNumConfigurations      1
  Configuration Descriptor:
    bLength                 9
    bDescriptorType         2
    wTotalLength       0x007d
    bNumInterfaces          2
    bConfigurationValue     1
    iConfiguration          0 
    bmAttributes         0xc0
      Self Powered
    MaxPower              100mA
    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        0
      bAlternateSetting       0
      bNumEndpoints           2
      bInterfaceClass         3 Human Interface Device
      bInterfaceSubClass      0 
      bInterfaceProtocol      0 
      iInterface              0 
        HID Device Descriptor:
          bLength                 9
          bDescriptorType        33
          bcdHID               1.10
          bCountryCode            0 Not supported
          bNumDescriptors         1
          bDescriptorType        34 Report
          wDescriptorLength      34
         Report Descriptors: 
           ** UNAVAILABLE **
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x82  EP 2 IN
        bmAttributes            3
          Transfer Type            Interrupt
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0008  1x 8 bytes
        bInterval               1
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x01  EP 1 OUT
        bmAttributes            3
          Transfer Type            Interrupt
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0008  1x 8 bytes
        bInterval               1
    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        1
      bAlternateSetting       0
      bNumEndpoints           3
      bInterfaceClass        11 Chip/SmartCard
      bInterfaceSubClass      0 
      bInterfaceProtocol      0 
      iInterface              1 SZZCS ZCS80
      ChipCard Interface Descriptor:
        bLength                54
        bDescriptorType        33
        bcdCCID              1.10  (Warning: Only accurate for version 1.0)
        nMaxSlotIndex           1
        bVoltageSupport         7  5.0V 3.0V 1.8V 
        dwProtocols             3  T=0 T=1
        dwDefaultClock       3580
        dwMaxiumumClock     14320
        bNumClockSupported      0
        dwDataRate           9946 bps
        dwMaxDataRate      318280 bps
        bNumDataRatesSupp.      0
        dwMaxIFSD             254
        dwSyncProtocols  00000000 
        dwMechanical     00000000 
        dwFeatures       000404BE
          Auto configuration based on ATR
          Auto activation on insert
          Auto voltage selection
          Auto clock change
          Auto baud rate change
          Auto PPS made by CCID
          Auto IFSD exchange
          Short and extended APDU level exchange
        dwMaxCCIDMsgLen       272
        bClassGetResponse    echo
        bClassEnvelope       echo
        wlcdLayout           none
        bPINSupport             0 
        bMaxCCIDBusySlots       3
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x85  EP 5 IN
        bmAttributes            3
          Transfer Type            Interrupt
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0008  1x 8 bytes
        bInterval              16
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x04  EP 4 OUT
        bmAttributes            2
          Transfer Type            Bulk
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0040  1x 64 bytes
        bInterval               0
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x86  EP 6 IN
        bmAttributes            2
          Transfer Type            Bulk
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0040  1x 64 bytes
        bInterval               0
can't get device qualifier: Resource temporarily unavailable
can't get debug descriptor: Resource temporarily unavailable
Device Status:     0x0000
  (Bus Powered)