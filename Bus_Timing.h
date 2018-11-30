struct {                              //Structure for status/timing flags related to the MDB transmission.
    unsigned char isUnresponsive : 1; //Flag set when transmission completes and non-response time is reached before a response.
    unsigned char isDone : 1;         //Flag set when recieved transmission completes and inter-byte time-out is reached before the next byte, or know end of conversation (poll required before peripheral transmits again).
    unsigned char isResetting : 1;    //Flag set when a 'BUS RESET' is taking place.
    unsigned char isActive : 1;       //Flag set when VMC's TX line goes active, and unset the instant the line goes inactive (used to detect 'BUS RESET').
} transmission;
int microseconds;//microseconds = Used by the timing method with 'micros()' in order to measure how many microseconds have gone by since the method was last called, rather than how many have gone by since the system started up.
int thirdPin;//thirdPin = The pin name of the GPIO that senses the bus reset.
void thirdEvent1();     //GPIO detects voltage fall.
void thirdEvent2();     //GPIO detects voltage rise.
void chronoLogic(unsigned char command);    //Stopwatch that updates all timing flags.
