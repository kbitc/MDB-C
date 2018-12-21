//Level 1 device accepts bills, Level 2 recycles and has expansion options.

struct {
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

struct {
  unsigned char escrow;               //Bill in escrow, used as a flag, contains the value.
  unsigned char validating : 1;       //Flag for when a bill is in the process of being validated.
  unsigned char attempts : 3;         //Attempts to insert a bill while validator is disabled.

  unsigned char address = 0x30;
  unsigned char validatorFeatureLevel : 2 = 0x2;
  unsigned char vmcFeatureLevel : 2;
  unsigned char countryCurrencyCode[1];
  unsigned char scalingFactor[1];
  unsigned char decimalPlaces;
  unsigned char stackerCapacity[1];
  unsigned char billSecurityLevels[1];
  unsigned char billEscrow;
  unsigned char billTypeCredit[15];
  unsigned char billTypeSecurity;
} validator1;

SETUP() {
  clearBlock();
  block[0].whole = validator1.validatorFeatureLevel
  block[1].whole = validator1.countryCurrencyCode[0];
  block[2].whole = validator1.countryCurrencyCode[1];
  block[3].whole = validator1.scalingFactor[0];
  block[4].whole = validator1.scalingFactor[1];
  block[5].whole = validator1.decimalPlaces;
  block[6].whole = validator1.stackerCapacity[0];
  block[7].whole = validator1.stackerCapacity[1];
  block[8].whole = validator1.billSecurityLevels[0];
  block[9].whole = validator1.billSecurityLevels[1];
  block[10].whole = validator1.billEscrow;
  block[11].whole = validator1.billTypeCredit[0];
  block[12].whole = validator1.billTypeCredit[1];
  block[13].whole = validator1.billTypeCredit[2];
  block[14].whole = validator1.billTypeCredit[3];
  block[15].whole = validator1.billTypeCredit[4];
  block[16].whole = validator1.billTypeCredit[5];
  block[17].whole = validator1.billTypeCredit[6];
  block[18].whole = validator1.billTypeCredit[7];
  block[19].whole = validator1.billTypeCredit[8];
  block[20].whole = validator1.billTypeCredit[9];
  block[21].whole = validator1.billTypeCredit[10];
  block[22].whole = validator1.billTypeCredit[11];
  block[23].whole = validator1.billTypeCredit[12];
  block[24].whole = validator1.billTypeCredit[13];
  block[25].whole = validator1.billTypeCredit[14];
  block[26].whole = validator1.billTypeCredit[15];
  pointer = 16;
  tx();
}                                 //Page 37-38

STACKER() {

}

SECURITY() {
  clearBlock();
  block[0].part.data = validator1.billTypeSecurity[0];
  block[1].part.data = validator1.billTypeSecurity[1];
  tX(2);
}                                 //Page 38

POLL() {
  if (validator1.billValidadtorActivityCounter == 0x00) {
    return;
  }
  counter = 0;
  while (validator1.billValidadtorActivityCounter != counter) {
    block[counter].part.data = validator1.billValdiatorActivity[counter];
    counter++;
  }
  //FTL
  validator.reqToRcv
  validator.retryDeny
  validator.sendBlock
  validator.okToSend
  validator.reqToSend
}
}                       //Page 38-41

void YE() {
  if ((command == validator.reset.command) && (block[0].part.mode == 0x01) && (result == 6)) {
    if (escrow = '0') {
      ejectBill();
    }
    if (validating = '0') {
      ejectBill();
    }
    resetPeripheral();
  }
  if ((command == validator.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.security.command) && (block[0].part.mode == 0x01) && (result == 6)) {
    SECURITY();
  }
  if ((command == validator.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.billType.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.escrow.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.stacker.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.escrow.command) && (block[0].part.mode == 0x01) && (result == 6))
}
