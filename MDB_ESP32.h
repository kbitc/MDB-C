#ifndef MDB_HEADER
#define MDB_HEADER

#define TXPIN 12
#define RXPIN 14


#define PARITY_ERROR 0x00000004
#define EVEN_PARITY 0x00000000
#define ODD_PARITY 0x00000001



extern void setup();

extern void loop();
extern uint8_t rX9BitsAvailable();
extern uint16_t rX9Bits();
extern uint8_t tX9Bits(uint8_t mdbMode, uint8_t mdbData);
extern uint8_t tX9BitsFlush();


#endif  /*MDB_HEADER*/
