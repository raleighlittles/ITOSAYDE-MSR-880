// File: USB wrapper

#include <stdint.h>

#ifndef USB_WRAPPER_H
#define USB_WRAPPER_H

static const uint16_t productID = 0x0005;
static const uint16_t vendorID =  0x0802;

static const unsigned char endpointIn = 0x82;
static const unsigned char endpointOut = 0x01;

#endif // USB_WRAPPER_H