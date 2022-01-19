# About

This repository contains a Linux driver for the ITOSAYDE-MSR-880 card reader. This project is a very-early work in progress! See the roadmap for more information.

The main product of this right now is a simple CLI application that allows you to interact with the card reader via USB.

# Background/Context

In January I purchased this card reader and to my dismay, there was no Linux driver. This is my attempt to write one. 

The device does come with a Windows driver, some documentation, a cobbled together 'demo' application (again Windows only), but more importantly it comes an API in the form of a pre-compiled Windows library (DLL file) and a header file.
My initial plan was to reverse-engineer the DLL file, but this fell apart quickly. Instead, I decided to go with a black-box approach, where I used the Windows demo application to interact with this device, monitored USB traffic, and then used that to learn about the device to be able to write a driver for it.
This plan also has a few issues, namely that there are bugs in the manufacturer-provided demo application that make it difficult to use.

# Roadmap

This outlines the features I've implemeneted.

| Feature | Implemented (Y, N, Partially) |
| ------  | -------------   |
| **Magnetic Stripe cards** |         |
| Track 1      |     N      |
| Track 2      |     P, Read only      |
| Track 3   |      N        |
| **Integrated Circuit aka 'Chip' cards / Smart cards** | |
| Reset   |  N |
| ADPU Commands | None |
| Password verification | N |
| Read | N |
| Write | N |
| **RFID/"M1" proximity cards** |
| Read | N |
| Write | N |
| **'Ultralight'/"Contactless" cards** | |
| Read | N |
| Write | N |


# Project Info / Looking to contribute?

Directory breakdown (add ls output here)

* `app` contains the main application for this repository. Right now, it's a simple C++ application (will be ported to Rust someday) that interacts directly with the device via [libusb](https://libusb.info/). See the README in that directory for more information on the application. 
* `disc-contents`: This is where all the manufacturer-provided content - demo application, Windows driver, DLL, API header file - lives. When I purchased the card reader, this came in a separate mini-disc that I'm guessing some people might have thrown away, hence why I thought it was useful to include here).
* `docs` - Miscellaneous documentation, mostly for debugging purposes
* `wireshark` contains wireshark dumps for different activities on the card reader. As I mentioned before, my approach on this project has been: 

1) Run the demo application (in a VM...)
2) Exercise functionality in it, i.e. do a read of a magstripe card or of an IC card, etc.
3) Log the wireshark traffic
4) Analyze wireshark traffic, and recreate that traffic in the code.

The README in the wireshark directory has some information.

Basically, if you're looking to help out, simply look at the list of unimplemented features, find a wireshark dump that covers that case, and start implementing it!
