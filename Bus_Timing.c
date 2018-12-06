#include "Bus_Timing.h"

void chronoLogic(unsigned char command) {     //Command 0 to reset.  Command 1 to update timing variables.  Think of it like a stopwatch, but it updates flags rather than reporting a time.
	if (!command) {
	    microseconds = micros();              //Save time of this command's execution.
	    transmission.isDone = 0;              //Reset the inter-byte timing flag.
	    transmission.isUnresponsive = 0;      //Reset the non-response timing flag.
	    transmission.isResetting = 0;         //Reset the 'BUS RESET' timing flag.
	    return;
	}
	result = micros() - microseconds;
	if (result > 2144) transmission.isDone = 1;
	if (result > 6144) transmission.isUnresponsive = 1;
	if (result > 101144) transmission.isResetting = 1;
	if (result > 201144) transmission.isResetting = 0;
	return;
}

void serialEvent1() {   								//Possible replacement to RX, hardware calls this when UART recieves data.  Called after current method is finished.
    chronoLogic(0);
    noInterrupts();  									//Disable interrupts from third wire, otherwise it'd interrupt every single bit.
    transmission.isActive = 1;  						//Line might be marked active, since this is a uart frame, it's not a busReset, so make the line inactive.
	result = rX();										//Fetch the rest & pass up the result.
	if (block[counter].part.data != checksum) {
	    result = 0;                                     //0 for failure, checksum doesn't match.
        clearBlock();                                   //Clear the block so corrupt data isn't read.
	}
	if (result == 6)
    interrupts();   									//Turn interrupts back on, and return to the loop.
}

void thirdEvent1() {     								//Called when voltage rises on RX while not listening for UART.
    detachInterrupt(thirdPin);
    attachInterrupt(thirdPin, thirdEvent2, FALLING);    //Look for voltage drop, call 'thirdEvent2()' when one is detected.
    transmission.isActive = 1;                          //Line active.
    chronoLogic(0);                                     //Reset timer.
}

void thirdEvent2() {    								//Called when voltage drops on RX while not listening for UART.
    detachInterrupt(thirdPin);
    attachInterrupt(thirdPin, thirdEvent1, RISING);     //Look for voltage rise, call 'thirdEvent1()' when one is detected.
    transmission.isActive = 0;                          //Line is inactive.
}
