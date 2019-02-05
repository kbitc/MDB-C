#include "mdb.h"

uint16_t block;


/*
 *  Things seem a bit odd, i may be missing a mistake somewhere, 
 *  because the UART has to be in ODD parity mode, to recieve data with the right parity error.
 *  
 *  Basically, I'm not diving into interrupts yet, so interrupts are not used.  If you turn on
 *  the Parity Error interrupt, it has nowhere to go with the interrupt so it just freezes the CPU.
 *
 *  How it currently works, is data is checked for normally.  Rather than reading directly, a function
 *  is called which reads the data, checks the registers for the parity error and uart settings.  Then
 *  it calculates the expected parity for the given byte, and compares this to the UART settings and the
 *  parity error.  It can then tell if the mode bit was set or not, giving us 9 bits of data.
 *
 */

void setup() {
  debug.begin(115200);
  debug.println();
  debug.println("********MDB-9BIT UART********");
  mdb.begin(9600, SERIAL_8O1, 16, 17);
  vmc.begin(9600, SERIAL_8O1, 14, 12);
}

uint16_t rXESP32() {
  unsigned char temporary;
  uint8_t paritySetting;
  uint8_t parityError;
  uint8_t calculatedOddParity;
  calculatedOddParity = 0x00;
  temporary = 0x00;
  paritySetting = (*uart1_conf0_reg & ODD_PARITY);
  parityError = ((*uart1_int_raw_reg & PARITY_ERROR) >> 2);
  temporary = mdb.read();
  /*Calculate what the UART expected the parity bit to be*/
  parityBitCalc(temporary);
  /*Compare the received parity bit, current parity mode, and parity errror, to get the mode bit*/
  if (paritySetting == EVEN_PARITY) {
    debug.printf("Even Parity Mode");
    if (parityError == 0x01) {
      debug.printf(" with parity error.\n");
      if (calculatedOddParity == 0x01)
        return ((0x01 << 8) | temporary);
      return (temporary);
    }
    if (parityError == 0x00) {
      debug.printf(" without parity error.\n");
      if (calculatedOddParity == 0x01)
        return (temporary);
      return ((0x01 << 8) | temporary);
    }
  }
  if (paritySetting == ODD_PARITY) {
    debug.printf("Odd Parity Mode");
    if (parityError == 0x01) {
      debug.printf(" with parity error.\n");
      if (calculatedOddParity == 0x00)
        return ((0x01 << 8) | temporary);
      return (temporary);
    }
    if (parityError == 0x00) {
      debug.printf(" without parity error.\n");
      if (calculatedOddParity == 0x00)
        return (temporary);
      return ((0x01 << 8) | temporary);
    }
  }
}

uint16_t tXHESP32() {
  
}

uint8_t parityBitCalc(uint8_t raw) {
  uint8_t calculatedOddParity;
  calculatedOddParity = 0x01;
  calculatedOddParity ^= (raw & 0x80) >> 7;
  calculatedOddParity ^= (raw & 0x40) >> 6;
  calculatedOddParity ^= (raw & 0x20) >> 5;
  calculatedOddParity ^= (raw & 0x10) >> 4;
  calculatedOddParity ^= (raw & 0x08) >> 3;
  calculatedOddParity ^= (raw & 0x04) >> 2;
  calculatedOddParity ^= (raw & 0x02) >> 1;
  calculatedOddParity ^= raw & 0x01;
  debug.printf("Calculated E Parity = %1X\n", calculatedOddParity);
}

void loop() {
vmc.write(2);
mdb.write(2);
while (!mdb.available()) {
  delay(1);
}
block = rXESP32();
debug.printf("MDB Received: %3X\n", block);
delay(5000);
}
