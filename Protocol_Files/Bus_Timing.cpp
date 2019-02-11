#include "Bus_Timing.h"

uint8_t chronoLogic(uint8_t command)
{
        if (command == TIMER_RESET) {
                microseconds = micros(); /*Each device has a local static copy of microseconds*/
                return OKKK;
        }
        else if (command == TIMER_UPDATE) {
                time_elapsed = micros() - microseconds;
        /* #HardwareAdjust Verify timing with a logic analyzer and adjust values if necessary*/
                if (time_elapsed > 200000) return T_SETUP;  /*Bus Reset is over*/
                if (time_elapsed > 100000) return T_BREAK;  /*Bus Reset Timer  */
                if (time_elapsed > 5000) return T_RESPONSE;
                if (time_elapsed > 1000) return T_INTER_BYTE;
        }                   
}
