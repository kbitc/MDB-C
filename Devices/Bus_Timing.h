#ifndef BUS_TIMING_HEADER
#define BUS_TIMING_HEADER

#include <Arduino.h>
#include "PreProcessors.h"

static unsigned long microseconds;
extern unsigned long time_elapsed;
extern uint8_t chronoLogic(uint8_t command);    /*Stopwatch that updates all timing flags*/
extern unsigned long micros();

#endif  /*BUS_TIMING_HEADER*/
