#include "MDB.h"

TaskHandle_t mdb_task;

void mdb_Task_Code(void * parameter) {
  for(;;) {
    delay(1000);
  long start = millis();
  debug.print("Finish Task1 which runs on Core ");
  debug.print(xPortGetCoreID());
  debug.print(" Time ");
  debug.println(millis() - start);
  }
}

void setup() {
  debug.begin(115200);
  Serial1.begin(9600, SERIAL_8E1, MDB_RX, MDB_TX);
  pinMode(LED, OUTPUT);

  xTaskCreatePinnedToCore(
    mdb_Task_Code,
    "mdb_task",
    1000,
    NULL,
    1,
    &mdb_task,
    0);
}

void loop() {

}
