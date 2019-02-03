#ifndef SNIFFER_HEADER
#define SNIFFER_HEADER

#include <Arduino.h>
#include "Communication_Format.h"

extern uint8_t sniff(); /*Checks the MDB bus for data & returns a full block if so.*/
extern uint8_t parse(uint8_t); /**/

#endif /*SNIFFER_HEADER*/
