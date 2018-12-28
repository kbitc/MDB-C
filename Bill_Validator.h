extern ftlType ftl;  //Declare the FTL file here.
extern requestToSend();
extern okToSend();
extern sendBlock();
extern retryDeny();
extern reqToRcv();

extern typedef struct validatorType {
  struct {
    unsigned char billStacked = 0x00;
    unsigned char escrowPosition = 0x10;
    unsigned char billReturned = 0x20;
    unsigned char disabledBillRejected = 0x40;
  } billRouting;                //Bitmasks

  struct {
    unsigned char command = 0x30;
  } reset;
  struct {
    unsigned char command = 0x31;
  } setup;
  struct {
    unsigned char command = 0x32;
  } security;
  struct {
    unsigned char command = 0x33;
    struct {
      unsigned char defectiveMotor : 1 = 0x1;
      unsigned char sensorProblem : 2 = 0x2;
      unsigned char validatorBusy : 2 = 0x3;
      unsigned char romChecksumError : 3 = 0x4;
      unsigned char validatorJammed : 3 = 0x5;
      unsigned char validatorReset : 3 = 0x6;
      unsigned char billRemoved : 3 = 0x7;
      unsigned char cashBoxOutOfPosition : 4 = 0x8;
      unsigned char unitDisabled : 4 = 0x9;
      unsigned char invalidEscrowRequest : 4 = 0xa;
      unsigned char billRejected : 4 = 0xb;
      unsigned char possibleCreditedBillRemoval : 4 0xc;
      //FTL
      unsigned char reqToRcv = 0x1b;
      unsigned char retryDeny = 0x1c;
      unsigned char sendBlock = 0x1d;
      unsigned char okToSend = 0x1e;
      unsigned char reqToSend = 0xf;
    } response;
  } poll;
  struct {
    unsigned char command = 0x34;
  } billType;
  struct {
    unsigned char command = 0x35;
  } escrow;
  struct {
    unsigned char command = 0x36;
  } stacker;
  struct {
    unsigned char command = 0x37;
  } expansion;
} validator;
