//For use with Arduino IDE & the ESP32 Arduino Core.  It's assumed you're using a cashless payment device

#include <stdio.h>
#include "communication_format.c"    //File used to abstract the MDB communications/timing.
#include "INSERT_PERIPHERAL_FILE_HERE.c"  //File containing all the code & settings for the chosen peripheral

void setup() {
  Serial1.begin(9600, SERIAL_8E1);   //Set up UART1 up with 8 data bits and an even parity to start with.
  delay(1000);
}

void loop() {
 //Insert 'main' code from the peripheral file here.
}
