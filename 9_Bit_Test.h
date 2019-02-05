#ifndef MDB_HEADER
#define MDB_HEADER

#define PARITY_ERROR 0x00000004
#define EVEN_PARITY 0x00000000
#define ODD_PARITY 0x00000001

/*Register addresses for the UART that's running MDB communications*/
extern uint32_t* uart1_conf0_reg;
extern uint32_t* uart1_conf1_reg;
extern uint32_t* uart1_clkdiv_reg;
extern uint32_t* uart1_flow_conf_reg;
extern uint32_t* uart1_swfc_conf_reg;
extern uint32_t* uart1_sleep_conf_reg;
extern uint32_t* uart1_idle_conf_reg;
extern uint32_t* uart1_rs485_conf_reg;
extern uint32_t* uart1_status_reg;  /*Read Only*/
extern uint32_t* uart1_int_raw_reg; /*Read Only*/
extern uint32_t* uart1_int_st_reg;  /*Read Only*/
extern uint32_t* uart1_int_ena_reg;
extern uint32_t* uart1_int_clr_reg; /*Write Only*/
extern uint32_t* uart1_fifo_reg;  /*Read Only*/

uint32_t* uart1_conf0_reg = (uint32_t*)  0x3FF50020;
uint32_t* uart1_conf1_reg = (uint32_t*) 0x3FF50024;
uint32_t* uart1_clkdiv_reg = (uint32_t*) 0x3FF50014;
uint32_t* uart1_flow_conf_reg = (uint32_t*) 0x3FF50034;
uint32_t* uart1_swfc_conf_reg = (uint32_t*) 0x3FF5003C;
uint32_t* uart1_sleep_conf_reg = (uint32_t*) 0x3FF50038;
uint32_t* uart1_idle_conf_reg = (uint32_t*) 0x3FF50040;
uint32_t* uart1_rs485_conf_reg = (uint32_t*) 0x3FF50044;
uint32_t* uart1_status_reg = (uint32_t*) 0x3FF5001C;
uint32_t* uart1_int_raw_reg = (uint32_t*) 0x3FF50004;
uint32_t* uart1_int_st_reg = (uint32_t*) 0x3FF50008;
uint32_t* uart1_int_ena_reg = (uint32_t*) 0x3FF5000C;
uint32_t* uart1_int_clr_reg = (uint32_t*) 0x3FF50010;
uint32_t* uart1_fifo_reg = (uint32_t*) 0x3FF50000;


extern HardwareSerial debug(0);
extern HardwareSerial mdb(1);
extern HardwareSerial vmc(2);
#endif  /*MDB_HEADER*/
