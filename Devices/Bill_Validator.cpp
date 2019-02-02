#include "Communication_Format.c"
#include "Bill_Validator.h"

struct {
  unsigned char escrow;               //Bill in escrow, used as a flag, contains the value.
  unsigned char validating : 1;       //Flag for when a bill is in the process of being validated.
  unsigned char attempts : 3;         //Attempts to insert a bill while validator is disabled.
  unsigned char billAccept[15];             //Set value of bill to flag it as enabled.
  unsigned char billEscrow[15];

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

int hardwareInput() {
  //Input devices to code.
}

int hardwareOutput() {
  //Code to output devices
}

int hardwareError() {
  //Error handling
}

int hardwareReset() {
  //Reset the hardware
}

int hardwareConfigure() {

}

int main() {
}

int setup() {
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
  return tX(16);
}                                 //6.4

int stacker() {

}

int security() {
  clearBlock();
  block[0].part.data = validator1.billTypeSecurity[0];
  block[1].part.data = validator1.billTypeSecurity[1];
  tX(2);
}                                 //6.5

int poll() {
  if (validator1.billValidadtorActivityCounter) {
    counter = 0;
    while (validator1.billValidadtorActivityCounter <= counter) {
      block[counter].part.data = validator1.billValdiatorActivity[counter];
      counter++;
    }
    return tX(counter);
  }
  else if (validator1.ftlPolledResponse) {
    if (validator1.reqToRcv) {
      result = reqToRcv(validator1.address);
      if (result == 0x1)
        validator1.reqToRcv = 0x0;
      return result;
    }
    else if (validator1.retryDeny) {
      result = retryDeny(validator1.address);
      if (result == 0x1)
        validator1.retryDeny = 0x0;
      return result;
    }
    else if (validator1.sendBlock) {
      result = sendBlock(validator1.address);
      if (result == 0x1)
        validator1.sendBlock = 0x0;
      return result;
    }
    else if (validator1.okToSend) {
      result = okToSend(validator1.address);
      if (result == 0x1)
        validator1.okToSend = 0x0;
      return result;
    }
    else if (validator1.reqToSend) {
      result = reqToSend(validator1.address);
      if (result == 0x1)
        validator1.reqToSend = 0x0;
      return result;
    }
  }
}                       //Page 38-41

int reset() {
  if ((command == validator.reset.command) && (block[0].part.mode == 0x01) && (result == 6)) {
    if (escrow = '0') {
      ejectBill();
    }
    if (validating = '0') {
      ejectBill();
    }
    hardwareReset();
  }
  if ((command == validator.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.security.command) && (block[0].part.mode == 0x01) && (result == 6)) {
    security();
  }
  if ((command == validator.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.billType.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.escrow.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.stacker.command) && (block[0].part.mode == 0x01) && (result == 6))
  if ((command == validator.escrow.command) && (block[0].part.mode == 0x01) && (result == 6))
}

int billType() {
  validator1.billEnable block[1].part.data;
}

escrow() {

}

expansion () {

}
