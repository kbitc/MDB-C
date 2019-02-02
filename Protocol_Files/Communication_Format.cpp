#ifndef COMMUNICATION_FORMAT
#define COMMUNICATION_FORMAT

#include "Arduino.h"
#include "Communication_Format.h"

/*  rX() when called directly after indication that data has been received,
 *    retrieves the whole block of data, even if only one byte has been received so far.
 *    It returns a value that indicates whether or not the data is for the device that
 *    called the function.  If the parity byte doesn't match, or the mode bits are in the
 *    wrong place, it returns a value to indicate this error instead.  The parity is only
 *    checked at the beginning and end of the block, though it is very unlikely one ends
 *    up in the middle of a block without triggering a DISORDER return value.
 *  tX() when called directly after loading the block and setting the pointer, sends
 *    the block and automatically adjusts the mode bits according to what device has called
 *    the function.  Upon sending the last byte of the block, tX() calls rX() and listens
 *    for a response.  Return values from rX() are passed through tX().
 */



uint8_t rX(uint8_t address) {                                        //1=ACK, 2=NAK, 3=RET, 4=NO-RESPONSE, 5=Ignored, 6=OK!, 7=Disordered, 8=Distorted
/*Receive the first Byte*/
  clearBlock();
  while (!Serial1.available()) {
    if (chronoLogic(TIMER_UPDATE) == T_RESPONSE)
    return NO_RESPONSE;
  }
  block[counter].whole = Serial1.read();
/*Check if it is one of the three response codes*/
  if (block[0].part.data == ACK)
    return ACK;
  if (block[0].part.data == RET)
    return RET;
  if (block[0].part.data == NAK)
    return NAK;
/*Check the mode bit*/
  if (block[0].part.mode == 0x01) {
    if (address != VMC_ADDRESS) {
      if ((block[0].part.data & 0xf8) != address) /*Check if it is addressed to the calling peripheral*/
        return IGNORED;                           /*Data is intentionally not automatically cleared, as some calling devices such as a sniffer, may want to read anyways*/
    }
    else if (address == VMC_ADDRESS)
      return DISORDERED;                          /*The VMC should never get a block where the first byte has the mode bit set*/
  }
  else if (block[0].part.mode == 0x00) {
    if (address != VMC_ADDRESS) {
      return DISORDERED;                          /*A Peripheral should never get a block where the first byte isn't an address byte*/
    }
  }
/*Retrieve the rest of the block*/
  while (counter != 36)  {
    while (!Serial1.available()) {
      if (chronoLogic(TIMER_UPDATE) == T_INTER_BYTE) {  /*1mS of silence marks the end of a conversation*/
        if (checksum != block[counter].part.data)
          return DISTORTED;
        if (address == VMC_ADDRESS) {
          if (block[counter].part.mode != 0x01)         /*The last byte sent to the VMC always has the mode bit set*/
            return DISORDERED;
          return RECEIVED;
        }
        if (address != VMC_ADDRESS) {
          if (block[counter].part.mode != 0x00)         /*The mode bit is only set on the first byte sent to a peripheral*/
            return DISORDERED;
          return RECEIVED;
        }
      }
    }
    chronoLogic(TIMER_RESET);
    checksum += block[counter].part.data;
    counter++;
    block[counter].whole = Serial1.read();
  }
}

void clearBlock() {
    counter = 0;
    while (counter != 36) {
        block[counter].whole = (0x0000);
        counter++;
    }
    counter = 0;
    checksum = 0x00;
}

uint8_t tX(unsigned int pointer, uint8_t address) {
/*Send All Data*/
  counter = 0;
  checksum = 0x00;
  if (address == VMC_ADDRESS) {
    if (pointer != 0)
      block[counter].whole = (block[counter].whole | 0x100);  /*VMC always sets the mode bit on the first byte, unless it's ACK, NAK, or RET*/
  }
  while (pointer != counter) {
    Serial1.write(block[counter].whole);
    checksum += block[counter].part.data;
    counter++;
    Serial1.flush();
  }
/*Send the last byte*/
  if (address != VMC_ADDRESS)
    block[counter].whole = (block[counter].whole | 0x100 | checksum);  /*Peripheral always marks the end of a block with a mode bit*/
  if (address == VMC_ADDRESS) {
    if (counter != 0)                                                  /*ACK, NAK, and RET don't use a check byte if from the VMC*/
      block[counter].whole = (block[counter].whole | checksum);
  }
  Serial1.write(block[counter].whole);
/*Prepare for a response*/
  chronoLogic(TIMER_RESET);
  return rX(address);
}

#endif
