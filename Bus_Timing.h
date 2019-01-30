 #include <esp32-hal.h>
 
 struct transmission {                              //Structure for status/timing flags related to the MDB transmission.
    unsigned char isUnresponsive : 1; //Flag set when transmission completes and non-response time is reached before a response.
    unsigned char isDone : 1;         //Flag set when recieved transmission completes and inter-byte time-out is reached before the next byte, or know end of conversation (poll required before peripheral transmits again).
    unsigned char isResetting : 1;    //Flag set when a 'BUS RESET' is taking place.
    unsigned char isActive : 1;       //Flag set when VMC's TX line goes active, and unset the instant the line goes inactive (used to detect 'BUS RESET').
} transmission;

unsigned long microseconds;//microseconds = Used by the timing method with 'micros()' in order to measure how many microseconds have gone by since the method was last called, rather than how many have gone by since the system started up.
void chronoLogic(unsigned char command, unsigned int address);    //Stopwatch that updates all timing flags.  Update later to have separate timers for each device.

extern unsigned int result;
extern unsigned long micros();
//extern int noInterrupts();
//extern unsigned long interrupts();
