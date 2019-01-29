//For use with Arduino IDE & the ESP32 Arduino Core.  It's assumed you're using a cashless payment device

#include <stdio.h>
#include <HardwareSerial.h>
#include "communication_format.c"    //File used to abstract the MDB communications/timing.
#include "INSERT_PERIPHERAL_FILE_HERE.c"  //File containing all the code & settings for the chosen peripheral

HardwareSerial USB(0);    //Use a text searching tool to find all instances of "Serial." and replace it with "USB."
HardwareSerial MDB(1);    //User a text searching tool to find all instances of "Serial1." and replace it with "MDB."

void setup() {
  USB.begin(115200);
  MDB.begin(9600, SERIAL_8E1, 28, 29);   //Set up UART1 up with 8 data bits and an even parity to start with.
  delay(10);
  USB.println("Power On");
}

void loop() {
 //Insert 'main' code from the peripheral file here.
}
