#include "Bus_Timing.h"

uint8_t chronoLogic(uint8_t command) {     /*Think of it like a stopwatch, but it returns a timing status rather than a time*/
  if (command == TIMER_RESET) {
      microseconds = micros();              //Save time of this command's execution.
      return OK;
  }
  else if (command == TIMER_UPDATE) {
    time_elapsed = micros() - microseconds;
    if (time_elapsed > 200000) return T_SETUP;  /*Bus Reset is over*/
    if (time_elapsed > 100000) return T_BREAK;  /*Bus Reset Timer*/
    if (time_elapsed > 5000) return T_RESPONSE; /* #HardwareAdjust Adjusts these values according to your hardware's inaccuracies.  Verify with a Logic Analyzer*/
    if (time_elapsed > 1000) return T_INTER_BYTE;
  }
}
