#ifndef MDB_HEADER
#define MDB_HEADER

#include <esp32-hal.h>
#include "Cashless.h"

#define LED 25
#define MDB_TX 29
#define MDB_RX 28

extern HardwareSerial debug(0);
extern HardwareSerial mdb(1);
extern TaskHandle_t mdb_task;

extern void mdb_Task_Code(void * parameter);

extern void setup();

extern void loop();

#endif  /*MDB_HEADER*/
