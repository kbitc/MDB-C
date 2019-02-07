#ifndef COMMUNICATION_FORMAT_HEADER
#define COMMUNICATION_FORMAT_HEADER

#include "PreProcessors.h"
#include "Bus_Timing.h"
#include "MDB_ESP32.h"

extern uint8_t chronoLogic(uint8_t command);

extern unsigned int counter;
extern uint8_t checksum, pointer;
extern uint8_t rX(uint8_t address);                        /*Fetches incoming data, checks what to do with it, gets the full block if needed, reports what's up in its return value*/
extern void clearBlock();                                  /*Clear all data out of the block, possibly unnecessary but will be kept for now*/
extern uint8_t tX(unsigned int pointer, uint8_t address);  /*Send the data in the block, takes care of mode bits, and the check byte uness pointer is zero.  Calls rX() for responses*/
extern uint8_t parityBitCalc(uint8_t raw);

extern union nineBit {             /*Union allows receiving 9 bit data as uint16_t*/
  struct {                         /*Structure allows accessing 8 data bits and 1 mode bit separately*/
    uint8_t data : 8;
    uint8_t mode : 1;
    } part;
    unsigned short whole;
} block[35];                      /*Array of 9 bit data, MDB has a maximum block size of 36 "bytes"*/

#endif
