#include "Cashless.h"

HardwareSerial debug(0); /*USB Debug Communications*/
HardwareSerial mdb(1); /*Used on ESP32 Pins 14 & 12, since 9 & 10 are linked to flash*/
HardwareSerial vmc(2); /*For now it's just to send a  few bytes, but later it'll be a full VMC*/

/*Register addresses for the UART that's running MDB communications*/
uint32_t* uart1_conf0_reg;
uint32_t* uart1_conf1_reg;
uint32_t* uart1_clkdiv_reg;
uint32_t* uart1_flow_conf_reg;
uint32_t* uart1_swfc_conf_reg;
uint32_t* uart1_sleep_conf_reg;
uint32_t* uart1_idle_conf_reg;
uint32_t* uart1_rs485_conf_reg;
uint32_t* uart1_status_reg;  /*Read Only*/
uint32_t* uart1_int_raw_reg; /*Read Only*/
uint32_t* uart1_int_st_reg;  /*Read Only*/
uint32_t* uart1_int_ena_reg;
uint32_t* uart1_int_clr_reg; /*Write Only*/
uint32_t* uart1_fifo_reg;  /*Read Only*/

void setup() {
  uart1_conf0_reg = (uint32_t*)  0x3FF50020;
  uart1_conf1_reg = (uint32_t*) 0x3FF50024;
  uart1_clkdiv_reg = (uint32_t*) 0x3FF50014;
  uart1_flow_conf_reg = (uint32_t*) 0x3FF50034;
  uart1_swfc_conf_reg = (uint32_t*) 0x3FF5003C;
  uart1_sleep_conf_reg = (uint32_t*) 0x3FF50038;
  uart1_idle_conf_reg = (uint32_t*) 0x3FF50040;
  uart1_rs485_conf_reg = (uint32_t*) 0x3FF50044;
  uart1_status_reg = (uint32_t*) 0x3FF5001C;
  uart1_int_raw_reg = (uint32_t*) 0x3FF50004;
  uart1_int_st_reg = (uint32_t*) 0x3FF50008;
  uart1_int_ena_reg = (uint32_t*) 0x3FF5000C;
  uart1_int_clr_reg = (uint32_t*) 0x3FF50010;
  uart1_fifo_reg = (uint32_t*) 0x3FF50000;
  debug.begin(115200);
  debug.println();
  debug.println("********MDB********");
  mdb.begin(9600, SERIAL_8O1, 16, 17);
  vmc.begin(9600, SERIAL_8O1, 14, 12);  /*Currently just to send test bytes, but later will be linked to VMC code*/
}

void loop() {

}


uint8_t rX9BitsAvailable() {
  if (mdb.available())
    return 0x01;
  return 0x00;
}

uint8_t tX9BitsFlush() {
  /*Flush the FIFO*/
}

uint8_t tX9Bits(uint8_t mdbMode, uint8_t mdbData) {
  uint8_t calculatedParity;
  uint8_t tXDone;
  //tXDone();   INSERT CODE HERE TO MAKE SURE THE TX FIFO IS EMPTY
  *uart1_conf0_reg |= ODD_PARITY;
  calculatedParity = parityBitCalc(mdbData);
  tXDone = ((*uart1_int_raw_reg & 0x00004000) >> 14);
  while (tXDone != 0x01) {
    tXDone = ((*uart1_int_raw_reg & 0x00004000) >> 14);
  }
  if (calculatedParity == 0x01) {
    if (mdbMode == 0x01)
      return mdb.write(mdbData);
    *uart1_conf0_reg ^= ODD_PARITY;  /*Set to Even Parity*/
    return mdb.write(mdbData);
  }
  
  //*uart1_fifo_reg = character;
}

uint16_t rX9Bits() {
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
