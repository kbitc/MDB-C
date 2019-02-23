#ifndef COMMUNICATION_FORMAT_HEADER
#define COMMUNICATION_FORMAT_HEADER

#include "PreProcessors.h"
#include "Bus_Timing.h"
#include "MDB_ESP32.h"

extern uint8_t chronoLogic(uint8_t command);

extern unsigned int counter;
extern uint8_t checksum, pointer;
extern uint8_t rX(uint8_t address);                        //Recieves a byte, judges if it needs to recieve the rest of the data, and ends at appropriate time.  Returns status codes.
extern void clearBlock();                                  //Clear all communications related variables.
extern uint8_t tX(unsigned int pointer, uint8_t address);  //Send the data in the block, calculate and insert check byte into location of pointer, uness pointer is zero.  ALways sets mode bit on last byte.
extern uint8_t parityBitCalc(uint8_t raw);

extern union nineBit {             //Union allows writing mode and data bits simultaneously as a short, therefore not overwriting one another.  Bit format: dddddddd_______m
        struct {                        //Structure allows accessing 8 data bits and 1 mode bit separately, as well as setting the parent union's size.
                uint8_t data : 8;             //8 data bits dddddddd most significant byte when written to as a short..
                uint8_t mode : 1;             //1 mode bit  _______m least significant byte when written to as a short.
        } part;                       //Named for readability & organization of code.
        unsigned short whole;
} mBlock[35], sBlock[35];                      /*Array of 9 bit data, MDB has a maximum block size of 36 "bytes"*/

#endif
