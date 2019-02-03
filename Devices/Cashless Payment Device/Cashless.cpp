#include "Cashless.h"
#include "Cashless_Locals.h"

/*  Setup Notes:
 *  Name this file Cashless#, with the # set to the desired cashless device.
 *  readerFeatureLevel, countryCurrencyCode
 *
 */
/*
 *  Abstract usage notes:
 *  cashless.columnsOnDisplay, cashless.rowsOnDisplay, cashless.displayType 0=7seg,1ascii
 *
 */

 /*
  * Possibly obsolete flags/values
  * isActiveFlag
  * isBusyFlag
  * isOnlineFlag
  *
  */



uint8_t Cashless() {//Change global name
  if (begin)
    startCashless();
  if (reset)
    resetCashless();
  if ()
}

/*7.1*/
uint8_t startCashless (int n) {
  struct cashlessVariables cashless;
  if ((__FILE__ == "Cashless1.cpp") || (__FILE__ == "Cashless1.c"))
    cashless.address = CASHLESS1_ADDRESS;
  else if ((__FILE__ == "Cashless2.cpp") || (__FILE__ == "Cashless2.c"))
    cashless.address = CASHLESS2_ADDRESS;
  else {
    debug.println("Rename the Cashless.cpp to Cashless1.cpp, Cashless2.cpp, or Cashless3.cpp");
    debug.println("The difference is:         Credit Cards,  Mobile Phones,    A battery powered device");
    return 0x01;;
  }
  rESET();
  cashless.justResetFlag = 0x00;  /*The only difference between setup and reset*/
  return 0x00;
}

/*7.2  Incomplete*/
int main() {
  if (mdb.available())
    rxResult = rX(cashless.address);
  if (rxResult == RECEIVED) {
    rxResult = EMPTY;
  /*7.2.1*/
    if (cashless.state == CASHLESS_STATE_INACTIVE) {
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
        return rESET();
      if (block[0].part.data == CASHLESS_SETUP_COMMAND)
        return sETUP();
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
        return pOLL();
      if (block[0].part.data == CASHLESS_VEND_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_READER_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      return 0x01;  /*Error #1*/
    }
    /*7.2.2*/
    if (cashless.state == CASHLESS_STATE_DISABLED) {
      if (block[0].part.data == CASHLESS_READER_COMMAND)
        return rEADER();
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
        return rESET();
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
        return pOLL();
      if (block[0].part.data == CASHLESS_SETUP_COMMAND)
        return sETUP();
      if (block[0].part.data == CASHLESS_VEND_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      return 0x02;;
    }
    /*7.2.3*/
    if (cashless.state == CASHLESS_STATE_ENABLED) {
      if (block[0].part.data == CASHLESS_VEND_COMMAND)
        return vEND();
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
        return rEVALUE();
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
        return eXPANSION();
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
        return pOLL();
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
        return rESET();
      if (block[0].part.data == CASHLESS_READER_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
        cashless.commandOutOfSequenceFlag = 0x0;
      return 0x03;
    }
    /*7.2.4*/
    if (cashless.state == CASHLESS_STATE_SESSIONIDLE) {
      if (block[0].part.data == CASHLESS_VEND_COMMAND)
          return vEND();
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
          return rEVALUE();
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
          return pOLL();
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
          return rESET();
      if (block[0].part.data == CASHLESS_READER_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      return 0x04;
    }
    /*7.2.5  Check the vend state.  Vend is non interruptable, but should respond to a reset or vend command.?*/
    if (cashless.state == CASHLESS_STATE_ALWAYSIDLE) {
      if (block[0].part.data == CASHLESS_VEND_COMMAND) {
        /*if ()
            cashless.state = CASHLESS_STATE_VEND
            cashless.state = CASHLESS_STATE_NEGATIVEVEND;*/
          return vEND();
      }
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
          return rEVALUE();
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
          return pOLL();
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
          return rESET();
      if (block[0].part.data == CASHLESS_READER_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      return 0x05;
    }
    if (cashless.state == CASHLESS_STATE_VEND) {
      if (cashless.isResettingFlag == 0x01)
        terminateSession();
      if (cashless.coinReturnPushed == 0x01) {
        cashless.endSessionFlag == 0x01;
        cashless.coinReturnPushed = 0x00;
      }
      if (block[0].part.data == CASHLESS_VEND_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_READER_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      return 0x06;
    }
    /*7.2.6*/
    if (cashless.state == CASHLESS_STATE_REVALUE) {
      if (cashless.isResettingFlag == 0x01)
        terminateSession();
      if (block[0].part.data == CASHLESS_VEND_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_READER_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      return 0x07;
    }
    /*7.2.7*/
    if (cashless.state == CASHLESS_STATE_NEGATIVEVEND) {
      if (cashless.isResettingFlag == 0x01)
        terminateSession();
      if (block[0].part.data == CASHLESS_VEND_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_REVALUE_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_POLL_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_RESET_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_READER_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      if (block[0].part.data == CASHLESS_EXPANSION_COMMAND)
          cashless.commandOutOfSequenceFlag = 0x0;
      return 0x08;
    }
}
}

/*7.3 Describes the flow of all functions
 *7.3.1
 *7.3.2 Check this over, implemented in main function.
/*7.3.0-7.3. is applied to all mdb side communications, and is more relevant to the VMC source file*/

int beginSession(int n, String data) {  //I don't remember this, it's old code so might be obsolete?
clearBlock();
//block[0].part.data = 0xaa;
//block[1].part.data = 0xc0;
//block[2].part.data = 0x55;
  if (n == '1') {
    //tX(3, cashless1.address);
    cashless1.fundsAvailable[0] = data.charAt(0);
    cashless1.fundsAvailable[1] = data.charAt(1);     //Load minimum known currency.
    if (cashless1.vmcFeatureLevel == 0x02) {
        cashless1.paymentMediaID[0] = data.charAt(2);
        cashless1.paymentMediaID[1] = data.charAt(3);
        cashless1.paymentMediaID[2] = data.charAt(4);
        cashless1.paymentMediaID[3] = data.charAt(5);
        cashless1.paymentType = data.charAt(6);
        cashless1.paymentData[0] = data.charAt(7);
        cashless1.paymentData[1] = data.charAt(8);
    }
    if (cashless1.vmcFeatureLevel == 0x03) {
        cashless1.fundsAvailable[2] = data.charAt(2);
        cashless1.fundsAvailable[3] = data.charAt(3);
        cashless1.paymentMediaID[0] = data.charAt(4);
        cashless1.paymentMediaID[1] = data.charAt(5);
        cashless1.paymentMediaID[2] = data.charAt(6);
        cashless1.paymentMediaID[3] = data.charAt(7);
        cashless1.paymentType = data.charAt(8);
        cashless1.paymentData[0] = data.charAt(9);
        cashless1.paymentData[1] = data.charAt(10);
        cashless1.userLanguage[0] = data.charAt(11);
        cashless1.userLanguage[1] = data.charAt(12);
        cashless1.userCurrencyCode[0] = data.charAt(13);
        cashless1.userCurrencyCode[1] = data.charAt(14);
        cashless1.cardOptions = data.charAt(15);
    }
    cashless1.beginSessionFlag = 0x00;
    cashless1.beginSessionReadyFlag = 0x01;
    return 1;
  }
  if (n == '2') {
    //tX(3, cashless2.address);
    cashless2.fundsAvailable[0] = data.charAt(0);
    cashless2.fundsAvailable[1] = data.charAt(1);     //Load minimum known currency.
    if (cashless2.vmcFeatureLevel == 0x02) {
        cashless2.paymentMediaID[0] = data.charAt(2);
        cashless2.paymentMediaID[1] = data.charAt(3);
        cashless2.paymentMediaID[2] = data.charAt(4);
        cashless2.paymentMediaID[3] = data.charAt(5);
        cashless2.paymentType = data.charAt(6);
        cashless2.paymentData[0] = data.charAt(7);
        cashless2.paymentData[1] = data.charAt(8);
    }
    if (cashless2.vmcFeatureLevel == 0x03) {
        cashless2.fundsAvailable[2] = data.charAt(2);
        cashless2.fundsAvailable[3] = data.charAt(3);
        cashless2.paymentMediaID[0] = data.charAt(4);
        cashless2.paymentMediaID[1] = data.charAt(5);
        cashless2.paymentMediaID[2] = data.charAt(6);
        cashless2.paymentMediaID[3] = data.charAt(7);
        cashless2.paymentType = data.charAt(8);
        cashless2.paymentData[0] = data.charAt(9);
        cashless2.paymentData[1] = data.charAt(10);
        cashless2.userLanguage[0] = data.charAt(11);
        cashless2.userLanguage[1] = data.charAt(12);
        cashless2.userCurrencyCode[0] = data.charAt(13);
        cashless2.userCurrencyCode[1] = data.charAt(14);
        cashless2.cardOptions = data.charAt(15);
    }
    cashless1.beginSessionFlag = 0x00;
    cashless1.beginSessionReadyFlag = 0x01;
    return 1;
  }

}

int sessionCancelRequest(int n, String data) {
  if (n == '1') {
    cashless1.sessionCancelRequestFlag = 0x01;
  }
  if (n == '2') {
    cashless1.sessionCancelRequestFlag = 0x01;
  }
    return 0;
}

int vendApproved(int n, String data) {
  if (n == '1') {
  cashless1.vendAmount[0] = data.charAt(0);
    cashless1.vendAmount[1] = data.charAt(1);
    if (cashless1.vmcFeatureLevel == 0x03) {
        cashless1.vendAmount[2] = data.charAt(2);
        cashless1.vendAmount[3] = data.charAt(3);
    }
    cashless1.vendApprovedFlag = 0x01;
    return 0;
  }
  if (n == '2') {
  cashless2.vendAmount[0] = data.charAt(0);
    cashless2.vendAmount[1] = data.charAt(1);
    if (cashless2.vmcFeatureLevel == 0x03) {
        cashless2.vendAmount[2] = data.charAt(2);
        cashless2.vendAmount[3] = data.charAt(3);
    }
    cashless2.vendApprovedFlag = 0x01;
    return 0;
  }
  return 1;
}

int vendDenied(int n, String data) {
    if (n == '1') {
    cashless1.vendDeniedFlag = 0x00;
  }
  if (n == '2') {
    cashless2.vendDeniedFlag = 0x00;
  }
    return 0;
}

int displayRequest(String data) {
    return 1;
}

int displayCancel(String data) {
    //cashless.displayCancel = 0x01;
    return 1;
}

/*7.4   INCOMPLETE*/
void rESET() {
  if (block[0].part.data == CASHLESS_RESET_COMMAND) { /*rESET() is called for a BUS RESET too, which you don't ACK.*/
    block[0].part.data = ACK;
    pointer = 0;
    tX(pointer, cashless1.address);
  }
  cashless.isResettingFlag = 0x01;
  if (cashless.state = CASHLESS_STATE_VEND)
    return 0;
  if (cashless.state = CASHLESS_STATE_NEGATIVEVEND)
    return 0;
  if (cashless.state = CASHLESS_STATE_REVALUE)
    return 0;

  cashless.displayRequestFlag = 0x00;
  cashless.beginSessionFlag = 0x00;
  cashless.sessionCancelRequestFlag = 0x00;
  cashless.commandOutOfSequenceFlag = 0x00;
  cashless.justResetFlag = 0x1;

  cashless.state = cashless.state.inactive;
}

void pOLL(int n) {
    if (n == '1') {
      if (cashless1.justResetFlag == 0x01) {            //If the peripheral has finished resetting.
          clearBlock();
          block[0].part.data = cashless.poll.response.justReset;
          tX(1, cashless.address);
          clearBlock();
          cashless1.justResetFlag = 0x00;
      }
      else if (cashless1.displayRequestFlag) {  //If cashless device requests to display on the Vending Machine's screen.
          block[0].whole = cashless.poll.response.displayRequest;
          block[1].whole = cashless1.displayTime;
          block[2].whole = cashless1.displayData[0];
          block[3].whole = cashless1.displayData[1];
          block[4].whole = cashless1.displayData[2];
          block[5].whole = cashless1.displayData[3];
          block[6].whole = cashless1.displayData[4];
          block[7].whole = cashless1.displayData[5];
          block[8].whole = cashless1.displayData[6];
          block[9].whole = cashless1.displayData[7];
          block[10].whole = cashless1.displayData[8];
          block[11].whole = cashless1.displayData[9];
          block[12].whole = cashless1.displayData[10];
          block[13].whole = cashless1.displayData[11];
          block[14].whole = cashless1.displayData[12];
          block[15].whole = cashless1.displayData[13];
          block[16].whole = cashless1.displayData[14];
          block[17].whole = cashless1.displayData[15];
          block[18].whole = cashless1.displayData[16];
          block[19].whole = cashless1.displayData[17];
          block[20].whole = cashless1.displayData[18];
          block[21].whole = cashless1.displayData[19];
          block[22].whole = cashless1.displayData[20];
          block[23].whole = cashless1.displayData[21];
          block[24].whole = cashless1.displayData[22];
          block[25].whole = cashless1.displayData[23];
          block[26].whole = cashless1.displayData[24];
          block[27].whole = cashless1.displayData[25];
          block[28].whole = cashless1.displayData[26];
          block[29].whole = cashless1.displayData[27];
          block[30].whole = cashless1.displayData[28];
          block[31].whole = cashless1.displayData[29];
          block[32].whole = cashless1.displayData[30];
          block[33].whole = cashless1.displayData[31];
          pointer = (cashless1.columnsOnDisplay * cashless1.rowsOnDisplay);
          tX(pointer, cashless.address);
          cashless1.displayRequestFlag = 0;
          clearBlock();
          return;
      }          //Requests to display data.
      else if (cashless1.beginSessionFlag) {
          cashless1.state = cashless.state.sessionIdle;
          block[0].whole = cashless.poll.response.beginSession;
          block[1].whole = cashless1.fundsAvailable[0];    //Scaled Currency.
          block[2].whole = cashless1.fundsAvailable[1];
          pointer = 3;
          if (cashless1.vmcFeatureLevel >= (0x02)) {
              block[3].whole = cashless1.paymentMediaID[0];
              block[4].whole = cashless1.paymentMediaID[1];
              block[5].whole = cashless1.paymentMediaID[2];
              block[6].whole = cashless1.paymentMediaID[3];
              block[7].whole = cashless1.paymentType;
              block[8].whole = cashless1.paymentData[0];
              block[9].whole = cashless1.paymentData[1];
              pointer = 10;
              if (cashless1.vmcFeatureLevel == (0x03)) {
                  block[10].whole = cashless1.userLanguage[0];
                  block[11].whole = cashless1.userLanguage[1];
                  block[12].whole = cashless1.userCurrencyCode[0];
                  block[13].whole = cashless1.userCurrencyCode[1];
                  block[14].whole = cashless1.cardOptions;
                  pointer = 15;
              }
          }
          tX(pointer, cashless.address);
          cashless1.beginSessionFlag = 0x1;
      }            //Begins a Vend session.
      else if (cashless1.sessionCancelRequestFlag == 0x01) {
          clearBlock();
          block[0].part.data = cashless.poll.response.sessionCancelRequest;
          result = tX(1, cashless.address);
          if (block[0].part.data == ACK) {
              cashless1.sessionCancelRequestFlag = 0x00;
          }
      }    //Cancels a Vend session.
      else if (cashless1.vendApprovedFlag) {
          block[0].whole = cashless.poll.response.vendApproved;
          block[1].whole = cashless1.vendAmount[0];
          block[2].whole = cashless1.vendAmount[1];
          pointer = 3;
          if (cashless1.vmcFeatureLevel == 0x03) {
              block[3].whole = cashless1.vendAmount[2];
              block[4].whole = cashless1.vendAmount[3];
              pointer = 5;
          }
          tX(pointer, cashless.address);
          cashless1.vendApprovedFlag = 0x00;
      }            //Approves a vend.
      else if (cashless1.vendDeniedFlag == 0x01) {
          block[0].whole = cashless.poll.response.vendDenied;
          tX(1, cashless.address);
          cashless1.vendDeniedFlag = 0x00;
      }              //Denies a vend.
      else if (cashless1.endSessionFlag = 0x01) {
          block[0].whole = cashless.poll.response.endSession;
          tX(1, cashless.address);
      }              //Indicates the reader has returned to the enabled state, follows Session Cancel.
      else if (cashless1.cancelledFlag == 0x01) {
          block[0].whole = cashless.poll.response.cancelled;
          tX(1, cashless.address);
          cashless1.cancelledFlag = 0x00;
      }               //Aborts rEADER activities which occur in the enabled state.
      else if (cashless1.peripheralIDFlag == 0x01) {
          block[0].whole = cashless.poll.response.peripheralID;
          block[1].whole = cashless1.readerManufacturerCode[0];
          block[2].whole = cashless1.readerManufacturerCode[1];
          block[3].whole = cashless1.readerManufacturerCode[3];
          counter = 0;
          while (counter != 11) {
              block[counter + 4].whole = cashless1.readerSerialNumber[counter];
              block[counter + 16].whole = cashless1.readerModelNumber[counter];
              counter++;
          }
          block[28].whole = cashless1.readerSoftwareVersion[0];
          block[29].whole = cashless1.readerSoftwareVersion[1];
          pointer = 30;
          if ((cashless1.vmcFeatureLevel == 0x3) && (cashless1.readerFeatureLevel == 0x3) && (/*optional Feature bits enabled by VMC*/0x01)) { /////////////////////////////////
              block[30].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |
                (cashless1.optionalFeatureBitsEnabled. << 3) |
                (cashless1.optionalFeatureBitsEnabled. << 2) |
                (cashless1.optionalFeatureBitsEnabled. << 1) |
                (cashless1.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[31].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |
                (cashless1.optionalFeatureBitsEnabled. << 3) |
                (cashless1.optionalFeatureBitsEnabled. << 2) |
                (cashless1.optionalFeatureBitsEnabled. << 1) |
                (cashless1.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[32].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |
                (cashless1.optionalFeatureBitsEnabled. << 3) |
                (cashless1.optionalFeatureBitsEnabled. << 2) |
                (cashless1.optionalFeatureBitsEnabled. << 1) |
                (cashless1.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[33].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |*/
                (cashless1.optionalFeatureBitsEnabled.ftl << 3) |
                (cashless1.optionalFeatureBitsEnabled.controlledManualFillPayoutCommands << 2) |
                (cashless1.optionalFeatureBitsEnabled.extendedDiagnosticCommand << 1) |
                (cashless1.optionalFeatureBitsEnabled.alternativePayoutMethod)
              );
              pointer = 34;
          }
          tX(pointer, cashless.address);
          cashless1.peripheralIDFlag = 0x00;
      }            //Response to cashless.expansion.peripheralID.command
      else if (cashless1.malfunctionErrorFlag == 0x01) {
          block[0].whole = cashless.poll.response.malfunctionError;
          block[1].whole = cashless1.errorCodeFlag;
          tX(2, cashless.address);
      }        //Reports an error or malfunction to the VMC.
      else if (cashless1.commandOutOfSequenceFlag == 0x01) {
          block[0].whole = cashless.poll.response.commandOutOfSequence;
          pointer = 1;
          if ((cashless1.vmcFeatureLevel >= 2) && (cashless1.readerFeatureLevel >= 2)) {
              block[1].whole = cashless1.state;
              pointer = 2;
          }
          tX(pointer, cashless.address);
      }        //Tells the VMC that a command was sent out of sequence.
      else if (cashless1.revalueApprovedFlag) {

      }         //     revalue involves putting money back onto a cashless payment source.
      else if (cashless1.revalueDeniedFlag == 0x01) {

      }           //
      else if (cashless1.revalueLimitAmount) {

      }      //
      /*else if (cashless1.userFileData) {
          Do not use, obsolete.
      }          //Obsolete command.*/
      else if (cashless1.timeDateRequestFlag == 0x01) {
          block[0].whole = cashless.poll.response.timeDateRequest;
          tX(1, cashless.address);
      }         //Request time/date from VMC.
      else if (cashless1.dataEntryRequestFlag == 0x01) {  //Request input from machine Keypad.
          block[0].whole = cashless.poll.response.dataEntryRequest;
          block[1].whole = cashless1.dataEntryLengthAndRepeatBit;
          tX(2, cashless.address);
      }        //Request input from VMC Keypad.
      else if (cashless1.dataEntryCancelFlag == 0x01) {
          block[0].whole = cashless.poll.response.dataEntryCancel;
          tX(1, cashless.address);
      }         //Cancel input session.
      else if (cashless1.reqToRcvFlag == 0x01) {
          block[0].whole = cashless.poll.response.reqToRcv;
          block[1].whole = cashless1.ftlDestinationAddress;
          block[2].whole = cashless1.address;
          block[3].whole = cashless1.ftlFileID;
          block[4].whole = cashless1.ftlMaximumLength;
          block[5].whole = cashless1.ftlControl;
          tX(6, cashless.address);
      }                //File Transport Layer
      else if (cashless1.retryDenyFlag == 0x01) {
          block[0].whole = cashless.poll.response.retryDeny;
          block[1].whole = cashless1.ftlDestinationAddress;
          block[2].whole = cashless1.address;
          block[3].whole = cashless1.ftlRetryDeny;
          tX(4, cashless.address);
      }               //File Transport Layer
      else if (cashless1.sendBlockFlag == 0x01) {
          block[0].whole = cashless.poll.response.sendBlock;
          block[1].whole = cashless1.destinationAddress;
          block[2].whole = cashless1.blockNumber;
          block[3].whole = cashless1.ftlData;
          tX(4, cashless.address);
      }               //File Transport Layer
      else if (cashless1.okToSendFlag == 0x01) {
          block[0].whole = cashless.poll.response.okToSend;
          block[1].whole = cashless1.destinationAddress;
          block[2].whole = cashless1.address;
          tX(3, cashless.address);
      }                //File transport Layer
      else if (cashless1.reqToSendFlag == 0x01) {
          block[0].whole = cashless.poll.response.reqToSend;
          block[1].whole = cashless1.destinationAddress;
          block[2].whole = cashless1.address;
          block[3].whole = cashless1.fileID;
          block[4].whole = cashless1.maximumLength;
          block[5].whole = cashless1.control;
          tX(6, cashless.address);
      }               //File Transport Layer
      else if (cashless1.diagnosticResponseFlag == 0x01) {

      }      //
      else if (cashless1.configDataFlag == 0x01) { //CONFIG DATA... I assume this is for compatibility, we don't use this.  Page 14.
          block[0].part.data = cashless.poll.response.readerConfigInfo;   //Lets the VMC know you are replying to CONFIG-DATA, from a previous SETUP command.
      block[1].part.data = cashless1.readerFeatureLevel;  //Tells VMC device supports Level 3.    Page-10
      block[2].part.data = cashless1.countryCurrencyCode[0];  //First half of US country code.        Page-11
      block[3].part.data = cashless1.countryCurrencyCode[1];  //Second half of US country code.       Page-11
      if ((cashless1.vmcFeatureLevel == 0x03) && (cashless1.readerFeatureLevel == 0x03)) {  //IF VMC supports Level 3 MDB.       Page-11
          block[2].part.data = (0x18);  //THEN use ISO4217 country code.    Page-11
          block[3].part.data = (0x40);  //Second half of ISO4217 code.      Page-11
      }
      block[4].part.data = (0x01);  //Sets coin scale to 1 for pennies.     Page-11
      block[5].part.data = (0x02);  //Sets decimal places up for cents.     Page-11
      block[6].part.data = cashless1.applicationMaximumResponseTime;  //Sets maximum response time.      Page-12
      block[7].part.data = cashless1.miscellaneousOptions;  //Sets refunds, multivend, display, and sales reporting.  Page-12
      block[8].part.mode = (0x01);  //Set data length.
      tX(9, cashless.address);  //Transmit Setup response block.
      }              //Sends config data.
      else
          Serial1.write(0x100);
      clearBlock();
    }
    else if (n == '2') {
      if (cashless2.justResetFlag == 0x01) {            //If the peripheral has finished resetting.
          clearBlock();
          block[0].part.data = cashless.poll.response.justReset;
          tX(1, cashless.address);
          clearBlock();
          cashless2.justResetFlag = 0x0;
      }
      else if (cashless2.displayRequestFlag) {  //If cashless device requests to display on the Vending Machine's screen.
          block[0].whole = cashless.poll.response.displayRequest;
          block[1].whole = cashless2.displayTime;
          block[2].whole = cashless2.displayData[0];
          block[3].whole = cashless2.displayData[1];
          block[4].whole = cashless2.displayData[2];
          block[5].whole = cashless2.displayData[3];
          block[6].whole = cashless2.displayData[4];
          block[7].whole = cashless2.displayData[5];
          block[8].whole = cashless2.displayData[6];
          block[9].whole = cashless2.displayData[7];
          block[10].whole = cashless2.displayData[8];
          block[11].whole = cashless2.displayData[9];
          block[12].whole = cashless2.displayData[10];
          block[13].whole = cashless2.displayData[11];
          block[14].whole = cashless2.displayData[12];
          block[15].whole = cashless2.displayData[13];
          block[16].whole = cashless2.displayData[14];
          block[17].whole = cashless2.displayData[15];
          block[18].whole = cashless2.displayData[16];
          block[19].whole = cashless2.displayData[17];
          block[20].whole = cashless2.displayData[18];
          block[21].whole = cashless2.displayData[19];
          block[22].whole = cashless2.displayData[20];
          block[23].whole = cashless2.displayData[21];
          block[24].whole = cashless2.displayData[22];
          block[25].whole = cashless2.displayData[23];
          block[26].whole = cashless2.displayData[24];
          block[27].whole = cashless2.displayData[25];
          block[28].whole = cashless2.displayData[26];
          block[29].whole = cashless2.displayData[27];
          block[30].whole = cashless2.displayData[28];
          block[31].whole = cashless2.displayData[29];
          block[32].whole = cashless2.displayData[30];
          block[33].whole = cashless2.displayData[31];
          pointer = (cashless2.columnsOnDisplay * cashless2.rowsOnDisplay);
          tX(pointer, cashless.address);
          cashless2.displayRequestFlag = 0;
          clearBlock();
          return;
      }          //Requests to display data.
      else if (cashless2.beginSessionFlag) {
          cashless2.state = cashless.state.sessionIdle;
          block[0].whole = cashless.poll.response.beginSession;
          block[1].whole = cashless2.fundsAvailable[0];    //Scaled Currency.
          block[2].whole = cashless2.fundsAvailable[1];
          pointer = 3;
          if (cashless2.vmcFeatureLevel >= (0x02)) {
              block[3].whole = cashless2.paymentMediaID[0];
              block[4].whole = cashless2.paymentMediaID[1];
              block[5].whole = cashless2.paymentMediaID[2];
              block[6].whole = cashless2.paymentMediaID[3];
              block[7].whole = cashless2.paymentType;
              block[8].whole = cashless2.paymentData[0];
              block[9].whole = cashless2.paymentData[1];
              pointer = 10;
              if (cashless2.vmcFeatureLevel == (0x03)) {
                  block[10].whole = cashless2.userLanguage[0];
                  block[11].whole = cashless2.userLanguage[1];
                  block[12].whole = cashless2.userCurrencyCode[0];
                  block[13].whole = cashless2.userCurrencyCode[1];
                  block[14].whole = cashless2.cardOptions;
                  pointer = 15;
              }
          }
          tX(pointer, cashless.address);
          cashless2.beginSessionFlag = 0x1;
      }            //Begins a Vend session.
      else if (cashless2.sessionCancelRequestFlag == 0x01) {
          clearBlock();
          block[0].part.data = cashless.poll.response.sessionCancelRequest;
          result = tX(1, cashless.address);
          if (block[0].part.data == ACK) {
              cashless2.sessionCancelRequestFlag = 0x00;
          }
      }    //Cancels a Vend session.
      else if (cashless2.vendApprovedFlag) {
          block[0].whole = cashless.poll.response.vendApproved;
          block[1].whole = cashless2.vendAmount[0];
          block[2].whole = cashless2.vendAmount[1];
          pointer = 3;
          if (cashless2.vmcFeatureLevel == 0x03) {
              block[3].whole = cashless2.vendAmount[2];
              block[4].whole = cashless2.vendAmount[3];
              pointer = 5;
          }
          tX(pointer, cashless.address);
          cashless2.vendApprovedFlag = 0x00;
      }            //Approves a vend.
      else if (cashless2.vendDeniedFlag == 0x01) {
          block[0].whole = cashless.poll.response.vendDenied;
          tX(1, cashless.address);
          cashless2.vendDeniedFlag = 0x00;
      }              //Denies a vend.
      else if (cashless2.endSessionFlag == 0x01) {
          block[0].whole = cashless.poll.response.endSession;
          tX(1, cashless.address);
      }              //Indicates the reader has returned to the enabled state, follows Session Cancel.
      else if (cashless2.cancelledFlag == 0x01) {
          block[0].whole = cashless.poll.response.cancelled;
          tX(1, cashless.address);
          cashless2.cancelledFlag = 0x00;
      }               //Aborts rEADER activities which occur in the enabled state.
      else if (cashless2.peripheralIDFlag == 0x01) {
          block[0].whole = cashless.poll.response.peripheralID;
          block[1].whole = cashless2.readerManufacturerCode[0];
          block[2].whole = cashless2.readerManufacturerCode[1];
          block[3].whole = cashless2.readerManufacturerCode[3];
          counter = 0;
          while (counter != 11) {
              block[counter + 4].whole = cashless2.readerSerialNumber[counter];
              block[counter + 16].whole = cashless2.readerModelNumber[counter];
              counter++;
          }
          block[28].whole = cashless2.readerSoftwareVersion[0];
          block[29].whole = cashless2.readerSoftwareVersion[1];
          pointer = 30;
          if ((cashless2.vmcFeatureLevel == 0x3) && (cashless2.readerFeatureLevel == 0x3) && (/*optional Feature bits enabled by VMC*/0x01)) { /////////////////////////////////
              block[30].whole = (/*
                (cashless2.optionalFeatureBitsEnabled. << 7) |
                (cashless2.optionalFeatureBitsEnabled. << 6) |
                (cashless2.optionalFeatureBitsEnabled. << 5) |
                (cashless2.optionalFeatureBitsEnabled. << 4) |
                (cashless2.optionalFeatureBitsEnabled. << 3) |
                (cashless2.optionalFeatureBitsEnabled. << 2) |
                (cashless2.optionalFeatureBitsEnabled. << 1) |
                (cashless2.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[31].whole = (/*
                (cashless2.optionalFeatureBitsEnabled. << 7) |
                (cashless2.optionalFeatureBitsEnabled. << 6) |
                (cashless2.optionalFeatureBitsEnabled. << 5) |
                (cashless2.optionalFeatureBitsEnabled. << 4) |
                (cashless2.optionalFeatureBitsEnabled. << 3) |
                (cashless2.optionalFeatureBitsEnabled. << 2) |
                (cashless2.optionalFeatureBitsEnabled. << 1) |
                (cashless2.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[32].whole = (/*
                (cashless2.optionalFeatureBitsEnabled. << 7) |
                (cashless2.optionalFeatureBitsEnabled. << 6) |
                (cashless2.optionalFeatureBitsEnabled. << 5) |
                (cashless2.optionalFeatureBitsEnabled. << 4) |
                (cashless2.optionalFeatureBitsEnabled. << 3) |
                (cashless2.optionalFeatureBitsEnabled. << 2) |
                (cashless2.optionalFeatureBitsEnabled. << 1) |
                (cashless2.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[33].whole = (/*
                (cashless2.optionalFeatureBitsEnabled. << 7) |
                (cashless2.optionalFeatureBitsEnabled. << 6) |
                (cashless2.optionalFeatureBitsEnabled. << 5) |
                (cashless2.optionalFeatureBitsEnabled. << 4) |*/
                (cashless2.optionalFeatureBitsEnabled.ftl << 3) |
                (cashless2.optionalFeatureBitsEnabled.controlledManualFillPayoutCommands << 2) |
                (cashless2.optionalFeatureBitsEnabled.extendedDiagnosticCommand << 1) |
                (cashless2.optionalFeatureBitsEnabled.alternativePayoutMethod)
              );
              pointer = 34;
          }
          tX(pointer, cashless.address);
          cashless2.peripheralIDFlag = 0x00;
      }            //Response to cashless.expansion.peripheralID.command
      else if (cashless2.malfunctionErrorFlag == 0x01) {
          block[0].whole = cashless.poll.response.malfunctionError;
          block[1].whole = cashless2.errorCodeFlag;
          tX(2, cashless.address);
      }        //Reports an error or malfunction to the VMC.
      else if (cashless2.commandOutOfSequenceFlag == 0x01) {
          block[0].whole = cashless.poll.response.commandOutOfSequence;
          pointer = 1;
          if ((cashless2.vmcFeatureLevel >= 2) && (cashless2.readerFeatureLevel >= 2)) {
              block[1].whole = cashless2.state;
              pointer = 2;
          }
          tX(pointer, cashless.address);
      }        //Tells the VMC that a command was sent out of sequence.
      else if (cashless2.revalueApprovedFlag) {

      }         //     revalue involves putting money back onto a cashless payment source.
      else if (cashless2.revalueDeniedFlag == 0x01) {

      }           //
      else if (cashless2.revalueLimitAmount) {

      }      //
      /*else if (cashless2.userFileData) {
          Do not use, obsolete.
      }          //Obsolete command.*/
      else if (cashless2.timeDateRequestFlag == 0x01) {
          block[0].whole = cashless.poll.response.timeDateRequest;
          tX(1, cashless.address);
      }         //Request time/date from VMC.
      else if (cashless2.dataEntryRequestFlag == 0x01) {  //Request input from machine Keypad.
          block[0].whole = cashless.poll.response.dataEntryRequest;
          block[1].whole = cashless2.dataEntryLengthAndRepeatBit;
          tX(2, cashless.address);
      }        //Request input from VMC Keypad.
      else if (cashless2.dataEntryCancelFlag == 0x01) {
          block[0].whole = cashless.poll.response.dataEntryCancel;
          tX(1, cashless.address);
      }         //Cancel input session.
      else if (cashless2.reqToRcvFlag == 0x01) {
          block[0].whole = cashless.poll.response.reqToRcv;
          block[1].whole = cashless2.ftlDestinationAddress;
          block[2].whole = cashless2.address;
          block[3].whole = cashless2.ftlFileID;
          block[4].whole = cashless2.ftlMaximumLength;
          block[5].whole = cashless2.ftlControl;
          tX(6, cashless.address);
      }                //File Transport Layer
      else if (cashless2.retryDenyFlag == 0x01) {
          block[0].whole = cashless.poll.response.retryDeny;
          block[1].whole = cashless2.ftlDestinationAddress;
          block[2].whole = cashless2.address;
          block[3].whole = cashless2.ftlRetryDeny;
          tX(4, cashless.address);
      }               //File Transport Layer
      else if (cashless2.sendBlockFlag == 0x01) {
          block[0].whole = cashless.poll.response.sendBlock;
          block[1].whole = cashless2.destinationAddress;
          block[2].whole = cashless2.blockNumber;
          block[3].whole = cashless2.ftlData;
          tX(4, cashless.address);
      }               //File Transport Layer
      else if (cashless2.okToSendFlag == 0x01) {
          block[0].whole = cashless.poll.response.okToSend;
          block[1].whole = cashless2.destinationAddress;
          block[2].whole = cashless2.address;
          tX(3, cashless.address);
      }                //File transport Layer
      else if (cashless2.reqToSendFlag == 0x01) {
          block[0].whole = cashless.poll.response.reqToSend;
          block[1].whole = cashless2.destinationAddress;
          block[2].whole = cashless2.address;
          block[3].whole = cashless2.fileID;
          block[4].whole = cashless2.maximumLength;
          block[5].whole = cashless2.control;
          tX(6, cashless.address);
      }               //File Transport Layer
      else if (cashless2.diagnosticResponseFlag == 0x01) {

      }      //
      else if (cashless2.configDataFlag == 0x01) { //CONFIG DATA... I assume this is for compatibility, we don't use this.  Page 14.
          block[0].part.data = cashless.poll.response.readerConfigInfo;   //Lets the VMC know you are replying to CONFIG-DATA, from a previous SETUP command.
      block[1].part.data = cashless2.readerFeatureLevel;  //Tells VMC device supports Level 3.    Page-10
      block[2].part.data = cashless2.countryCurrencyCode[0];  //First half of US country code.        Page-11
      block[3].part.data = cashless2.countryCurrencyCode[1];  //Second half of US country code.       Page-11
      if ((cashless2.vmcFeatureLevel == 0x03) && (cashless2.readerFeatureLevel == 0x03)) {  //IF VMC supports Level 3 MDB.       Page-11
          block[2].part.data = (0x18);  //THEN use ISO4217 country code.    Page-11
          block[3].part.data = (0x40);  //Second half of ISO4217 code.      Page-11
      }
      block[4].part.data = (0x01);  //Sets coin scale to 1 for pennies.     Page-11
      block[5].part.data = (0x02);  //Sets decimal places up for cents.     Page-11
      block[6].part.data = cashless2.applicationMaximumResponseTime;  //Sets maximum response time.      Page-12
      block[7].part.data = cashless2.miscellaneousOptions;  //Sets refunds, multivend, display, and sales reporting.  Page-12
      block[8].part.mode = (0x01);  //Set data length.
      tX(9, cashless.address);  //Transmit Setup response block.
      }              //Sends config data.
      else
          block[0].part.data = ACK;
          tX(0, cashless.address);
      clearBlock();
    };
}

void sETUP(int n) {
    if (block[1].part.data == CASHLESS_SETUP_CONFIGDATA_COMMAND) {
      cashless1.vmcFeatureLevel = block[2].part.data;
      cashless1.columnsOnDisplay = block[3].part.data;
      cashless1.rowsOnDisplay = block[4].part.data;
      cashless1.displayType = block[5].part.data;
      clearBlock(); /*Necessary for clearing old mode bits*/
      block[0].part.data = CASHLESS_SETUP_CONFIGDATA_RESPONSE_READERCONFIGDATA;
      block[1].part.data = cashless1.readerFeatureLevel;
      block[2].part.data = cashless1.countryCurrencyCode[0];  //First half of US country code.        Page-11
      block[3].part.data = cashless1.countryCurrencyCode[1];  //Second half of US country code.       Page-11
      if ((cashless1.vmcFeatureLevel == 0x03) && (cashless1.readerFeatureLevel == 0x03)) {  //IF VMC supports Level 3 MDB.       Page-11
        block[2].part.data = cashless1.countryCurrencyCodeLevel3[0];  //THEN use ISO4217 country code.    Page-11
        block[3].part.data = cashless1.countryCurrencyCodeLevel3[1];  //Second half of ISO4217 code.      Page-11
    }
    block[4].part.data = cashless1.scaleFactor;  //Sets the scale factor for the currency.     Page-11
    block[5].part.data = cashless1.decimalPlaces;  //Sets decimal places up for cents.     Page-11
    block[6].part.data = cashless1.applicationMaximumResponseTime;  //Sets maximum response time.      Page-12
    block[7].part.data = cashless1.miscellaneousOptions;  //Sets refunds, multivend, display, and sales reporting.  Page-12
    pointer = 8;
    tX(pointer, cashless.address);  //Transmit Setup response block.
    cashless1.isActiveFlag = 0x01;
    return;
    }
    if (block[1].part.data == CASHLESS_SETUP.maxMinPrices.command) {
        if ((cashless1.state == CASHLESS.state.disabled) && (cashless1.vmcFeatureLevel == 0x03)) {
        cashless1.maximumPrice[0] = block[2].part.data;  //Scaled maximum price.                Page-12
        cashless1.maximumPrice[1] = block[3].part.data;  //Second half of max price.            Page-12
        cashless1.maximumPrice[2] = block[4].part.data;  //Scaled minimum price.                Page-12
        cashless1.maximumPrice[3] = block[5].part.data;  //Second half of min price.            Page-12
        cashless1.minimumPrice[0] = block[6].part.data;  //Scaled maximum price.                Page-12
        cashless1.minimumPrice[1] = block[7].part.data;  //Second half of max price.            Page-12
        cashless1.minimumPrice[2] = block[8].part.data;  //Scaled minimum price.                Page-12
        cashless1.minimumPrice[3] = block[9].part.data;  //Second half of min price.            Page-12
        cashless1.countryCurrencyCode[0] = block[10].part.data;
        cashless1.countryCurrencyCode[1] = block[11].part.data;
        }
        else {
        cashless1.maximumPrice[0] = block[2].part.data;  //Scaled maximum price.                Page-12
        cashless1.maximumPrice[1] = block[3].part.data;  //Second half of max price.            Page-12
        cashless1.minimumPrice[0] = block[4].part.data;  //Scaled minimum price.                Page-12
        cashless1.minimumPrice[1] = block[5].part.data;  //Second half of min price.            Page-12
        }
        clearBlock();
        Serial1.write(0x100);
        cashless1.state = CASHLESS.state.disabled;  //Device is now in the Disabled state, awaiting DEVICE-ENABLE.
        return;
    }
  }
    }
  }
}                                           //Pages 10-13

void vEND(int n) {
  if (n == '1') {
    if (block[1].part.data == CASHLESS.vend.vendRequest.command) {
        cashless1.itemPrice[0] = block[2].part.data;
        cashless1.itemPrice[1] = block[3].part.data;
        cashless1.itemNumber[0] = block[4].part.data;
        cashless1.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ACK;
        tX(0, CASHLESS.address);
    }
    if (block[1].part.data == CASHLESS.vend.vendCancel.command) {
        block[0].whole = CASHLESS.vend.vendCancel.response.vendDenied;
        tX(1, CASHLESS.address);
    }
    if (block[1].part.data == CASHLESS.vend.vendSuccess.command) {
        cashless1.itemNumber[0] = block[2].part.data;
        cashless1.itemNumber[1] = block[3].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless1.address);
    }
    if (block[1].part.data == CASHLESS.vend.vendFailure.command) {
        return;
    }
    if (block[1].part.data == CASHLESS.vend.sessionComplete.command) {
        clearBlock();
        block[0].part.data = CASHLESS.vend.sessionComplete.response.endSession;
        pointer = 1;
        tX(pointer, cashless1.address);
        cashless1.state = CASHLESS.state.enabled;
    }
    if (block[1].part.data == CASHLESS.vend.cashSale.command) {
        cashless1.itemPrice[0] = block[2].part.data;
        cashless1.itemPrice[1] = block[3].part.data;
        cashless1.itemNumber[0] = block[4].part.data;
        cashless1.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
  }
  else if (n == '2') {
    if (block[1].part.data == CASHLESS.vend.vendRequest.command) {
        cashless2.itemPrice[0] = block[2].part.data;
        cashless2.itemPrice[1] = block[3].part.data;
        cashless2.itemNumber[0] = block[4].part.data;
        cashless2.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
    if (block[1].part.data == CASHLESS.vend.vendCancel.command) {
        block[0].whole = CASHLESS.vend.vendCancel.response.vendDenied;
        pointer = 1;
        tX(pointer, cashless.address);
    }
    if (block[1].part.data == CASHLESS.vend.vendSuccess.command) {
        cashless2.itemNumber[0] = block[2].part.data;
        cashless2.itemNumber[1] = block[3].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
    if (block[1].part.data == CASHLESS.vend.vendFailure.command) {
        return;
    }
    if (block[1].part.data == CASHLESS.vend.sessionComplete.command) {
        clearBlock();
        block[0].part.data = CASHLESS.vend.sessionComplete.response.endSession;
        pointer = 1;
        tX(pointer, cashless.address);
        cashless2.state = CASHLESS.state.enabled;
    }
    if (block[1].part.data == CASHLESS.vend.cashSale.command) {
        cashless2.itemPrice[0] = block[2].part.data;
        cashless2.itemPrice[1] = block[3].part.data;
        cashless2.itemNumber[0] = block[4].part.data;
        cashless2.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
  }
}
}

void rEADER() {
  if (block[1].part.data == CASHLESS.reader.readerEnable.command) {
    cashless1.state = CASHLESS.state.enabled;
    clearBlock();
    block[0].part.data = ACK;
    pointer = 0;
    tX(pointer, cashless.address);
  }
  if (block[1].part.data == CASHLESS.reader.readerDisable.command) {
    cashless1.state = CASHLESS.state.disabled;
    clearBlock();
    block[0].part.data = ACK;
    pointer = 0;
}

void rEVALUE(int n) {

}

void eXPANSION(int n) {
  if (n == '1') {
    if (block[1].part.data == CASHLESS.expansion.requestID.command) {
        cashless1.vmcManufacturerCode[0] = block[2].part.data;
        cashless1.vmcManufacturerCode[1] = block[3].part.data;
        cashless1.vmcManufacturerCode[2] = block[4].part.data;
        cashless1.vmcSerialNumber[0] = block[5].part.data;
        cashless1.vmcSerialNumber[1] = block[6].part.data;
        cashless1.vmcSerialNumber[2] = block[7].part.data;
        cashless1.vmcSerialNumber[3] = block[8].part.data;
        cashless1.vmcSerialNumber[4] = block[9].part.data;
        cashless1.vmcSerialNumber[5] = block[10].part.data;
        cashless1.vmcSerialNumber[6] = block[11].part.data;
        cashless1.vmcSerialNumber[7] = block[12].part.data;
        cashless1.vmcSerialNumber[8] = block[13].part.data;
        cashless1.vmcSerialNumber[9] = block[14].part.data;
        cashless1.vmcSerialNumber[10] = block[15].part.data;
        cashless1.vmcSerialNumber[11] = block[16].part.data;
        cashless1.vmcModelNumber[0] = block[17].part.data;
        cashless1.vmcModelNumber[1] = block[18].part.data;
        cashless1.vmcModelNumber[2] = block[19].part.data;
        cashless1.vmcModelNumber[3] = block[20].part.data;
        cashless1.vmcModelNumber[4] = block[21].part.data;
        cashless1.vmcModelNumber[5] = block[22].part.data;
        cashless1.vmcModelNumber[6] = block[23].part.data;
        cashless1.vmcModelNumber[7] = block[24].part.data;
        cashless1.vmcModelNumber[8] = block[25].part.data;
        cashless1.vmcModelNumber[9] = block[26].part.data;
        cashless1.vmcModelNumber[10] = block[27].part.data;
        cashless1.vmcModelNumber[11] = block[28].part.data;
        cashless1.vmcSoftwareVersion[0] = block[29].part.data;
        cashless1.vmcSoftwareVersion[1] = block[30].part.data;
        block[2].part.data = cashless1.readerManufacturerCode[0];
        block[3].part.data = cashless1.readerManufacturerCode[1];
        block[4].part.data = cashless1.readerManufacturerCode[2];
        block[5].part.data = cashless1.readerSerialNumber[0];
        block[6].part.data = cashless1.readerSerialNumber[1];
        block[7].part.data = cashless1.readerSerialNumber[2];
        block[8].part.data = cashless1.readerSerialNumber[3];
        block[9].part.data = cashless1.readerSerialNumber[4];
        block[10].part.data = cashless1.readerSerialNumber[5];
        block[11].part.data = cashless1.readerSerialNumber[6];
        block[12].part.data = cashless1.readerSerialNumber[7];
        block[13].part.data = cashless1.readerSerialNumber[8];
        block[14].part.data = cashless1.readerSerialNumber[9];
        block[15].part.data = cashless1.readerSerialNumber[10];
        block[16].part.data = cashless1.readerSerialNumber[11];
        block[17].part.data = cashless1.readerModelNumber[0];
        block[18].part.data = cashless1.readerModelNumber[1];
        block[19].part.data = cashless1.readerModelNumber[2];
        block[20].part.data = cashless1.readerModelNumber[3];
        block[21].part.data = cashless1.readerModelNumber[4];
        block[22].part.data = cashless1.readerModelNumber[5];
        block[23].part.data = cashless1.readerModelNumber[6];
        block[24].part.data = cashless1.readerModelNumber[7];
        block[25].part.data = cashless1.readerModelNumber[8];
        block[26].part.data = cashless1.readerModelNumber[9];
        block[27].part.data = cashless1.readerModelNumber[10];
        block[28].part.data = cashless1.readerModelNumber[11];
        block[29].part.data = cashless1.readerSoftwareVersion[0];
        block[30].part.data = cashless1.readerSoftwareVersion[1];
        pointer = 31;
        if (cashless1.vmcFeatureLevel == 0x03) {
            block[30].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |
                (cashless1.optionalFeatureBitsEnabled. << 3) |
                (cashless1.optionalFeatureBitsEnabled. << 2) |
                (cashless1.optionalFeatureBitsEnabled. << 1) |
                (cashless1.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[31].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |
                (cashless1.optionalFeatureBitsEnabled. << 3) |
                (cashless1.optionalFeatureBitsEnabled. << 2) |
                (cashless1.optionalFeatureBitsEnabled. << 1) |
                (cashless1.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[32].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |
                (cashless1.optionalFeatureBitsEnabled. << 3) |
                (cashless1.optionalFeatureBitsEnabled. << 2) |
                (cashless1.optionalFeatureBitsEnabled. << 1) |
                (cashless1.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[33].whole = (/*
                (cashless1.optionalFeatureBitsEnabled. << 7) |
                (cashless1.optionalFeatureBitsEnabled. << 6) |
                (cashless1.optionalFeatureBitsEnabled. << 5) |
                (cashless1.optionalFeatureBitsEnabled. << 4) |*/
                (cashless1.optionalFeatureBitsEnabled.ftl << 3) |
                (cashless1.optionalFeatureBitsEnabled.controlledManualFillPayoutCommands << 2) |
                (cashless1.optionalFeatureBitsEnabled.extendedDiagnosticCommand << 1) |
                (cashless1.optionalFeatureBitsEnabled.alternativePayoutMethod)
              );
            pointer = 35;
        }
        tX(pointer, cashless1.address);                                   ////I just now remembered loops exist.
    }
    if (block[1].part.data == CASHLESS.expansion.readUserFile.command) {
        clearBlock();
        block[0].part.data = CASHLESS.expansion.readUserFile.response.userFileData;  //Currently unsupported and not forseen to be needed.
        pointer = 1;
        tX(pointer, cashless.address);
    }
    if (block[1].part.data == CASHLESS.expansion.writeUserFile.command) {
        clearBlock();                       //Obsolete command, not seen as necessary to add.
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
    if (block[1].part.data == CASHLESS.expansion.writeTimeDate.command) {
        cashless1.timeDateYears = block[2].part.data;
        cashless1.timeDateMonths = block[3].part.data;
        cashless1.timeDateDays = block[4].part.data;
        cashless1.timeDateHours = block[5].part.data;
        cashless1.timeDateMinutes = block[6].part.data;
        cashless1.timeDateSeconds = block[7].part.data;
        cashless1.timeDateDayOfWeek = block[8].part.data;
        cashless1.timeDateWeekNumber = block[9].part.data;
        cashless1.timeDateSummertime = block[10].part.data;
        cashless1.timeDateHoliday = block[11].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
    }
    if (block[1].part.data == CASHLESS.expansion.optionalFeatureEnabled.command) {
        cashless1.vmcOptionalFeatureBits[3] = block[2].part.data;
        cashless1.vmcOptionalFeatureBits[2] = block[3].part.data;
        cashless1.vmcOptionalFeatureBits[1] = block[4].part.data;
        cashless1.vmcOptionalFeatureBits[0] = block[5].part.data;
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless1.address);
    }
  }
  else if (n == '2') {
    if (block[1].part.data == CASHLESS.expansion.requestID.command) {
        cashless2.vmcManufacturerCode[0] = block[2].part.data;
        cashless2.vmcManufacturerCode[1] = block[3].part.data;
        cashless2.vmcManufacturerCode[2] = block[4].part.data;
        cashless2.vmcSerialNumber[0] = block[5].part.data;
        cashless2.vmcSerialNumber[1] = block[6].part.data;
        cashless2.vmcSerialNumber[2] = block[7].part.data;
        cashless2.vmcSerialNumber[3] = block[8].part.data;
        cashless2.vmcSerialNumber[4] = block[9].part.data;
        cashless2.vmcSerialNumber[5] = block[10].part.data;
        cashless2.vmcSerialNumber[6] = block[11].part.data;
        cashless2.vmcSerialNumber[7] = block[12].part.data;
        cashless2.vmcSerialNumber[8] = block[13].part.data;
        cashless2.vmcSerialNumber[9] = block[14].part.data;
        cashless2.vmcSerialNumber[10] = block[15].part.data;
        cashless2.vmcSerialNumber[11] = block[16].part.data;
        cashless2.vmcModelNumber[0] = block[17].part.data;
        cashless2.vmcModelNumber[1] = block[18].part.data;
        cashless2.vmcModelNumber[2] = block[19].part.data;
        cashless2.vmcModelNumber[3] = block[20].part.data;
        cashless2.vmcModelNumber[4] = block[21].part.data;
        cashless2.vmcModelNumber[5] = block[22].part.data;
        cashless2.vmcModelNumber[6] = block[23].part.data;
        cashless2.vmcModelNumber[7] = block[24].part.data;
        cashless2.vmcModelNumber[8] = block[25].part.data;
        cashless2.vmcModelNumber[9] = block[26].part.data;
        cashless2.vmcModelNumber[10] = block[27].part.data;
        cashless2.vmcModelNumber[11] = block[28].part.data;
        cashless2.vmcSoftwareVersion[0] = block[29].part.data;
        cashless2.vmcSoftwareVersion[1] = block[30].part.data;
        block[2].part.data = cashless2.readerManufacturerCode[0];
        block[3].part.data = cashless2.readerManufacturerCode[1];
        block[4].part.data = cashless2.readerManufacturerCode[2];
        block[5].part.data = cashless2.readerSerialNumber[0];
        block[6].part.data = cashless2.readerSerialNumber[1];
        block[7].part.data = cashless2.readerSerialNumber[2];
        block[8].part.data = cashless2.readerSerialNumber[3];
        block[9].part.data = cashless2.readerSerialNumber[4];
        block[10].part.data = cashless2.readerSerialNumber[5];
        block[11].part.data = cashless2.readerSerialNumber[6];
        block[12].part.data = cashless2.readerSerialNumber[7];
        block[13].part.data = cashless2.readerSerialNumber[8];
        block[14].part.data = cashless2.readerSerialNumber[9];
        block[15].part.data = cashless2.readerSerialNumber[10];
        block[16].part.data = cashless2.readerSerialNumber[11];
        block[17].part.data = cashless2.readerModelNumber[0];
        block[18].part.data = cashless2.readerModelNumber[1];
        block[19].part.data = cashless2.readerModelNumber[2];
        block[20].part.data = cashless2.readerModelNumber[3];
        block[21].part.data = cashless2.readerModelNumber[4];
        block[22].part.data = cashless2.readerModelNumber[5];
        block[23].part.data = cashless2.readerModelNumber[6];
        block[24].part.data = cashless2.readerModelNumber[7];
        block[25].part.data = cashless2.readerModelNumber[8];
        block[26].part.data = cashless2.readerModelNumber[9];
        block[27].part.data = cashless2.readerModelNumber[10];
        block[28].part.data = cashless2.readerModelNumber[11];
        block[29].part.data = cashless2.readerSoftwareVersion[0];
        block[30].part.data = cashless2.readerSoftwareVersion[1];
        pointer = 31;
        if (cashless2.vmcFeatureLevel == 0x03) {
            block[34].part.data = cashless1.vmcOptionalFeatureBits[0];
            block[34].part.data = cashless1.vmcOptionalFeatureBits[1];
            block[34].part.data = cashless1.vmcOptionalFeatureBits[2];
            block[34].part.data = cashless1.vmcOptionalFeatureBits[3];
            pointer = 35;
        }
        tX(pointer, cashless.address);                                   ////I just now remembered loops exist.
    }
    if (block[1].part.data == CASHLESS.expansion.readUserFile.command) {
        clearBlock();
        block[0].part.data = CASHLESS.expansion.readUserFile.response.userFileData;  //Currently unsupported and not forseen to be needed.
        pointer = 1;
        tX(pointer, cashless.address);
    }
    if (block[1].part.data == CASHLESS.expansion.writeUserFile.command) {
        clearBlock();                       //Obsolete command, not seen as necessary to add.
        block[0].part.data = ACK;
        tX(pointer, cashless.address);
    }
    if (block[1].part.data == CASHLESS.expansion.writeTimeDate.command) {
        cashless2.timeDateYears = block[2].part.data;
        cashless2.timeDateMonths = block[3].part.data;
        cashless2.timeDateDays = block[4].part.data;
        cashless2.timeDateHours = block[5].part.data;
        cashless2.timeDateMinutes = block[6].part.data;
        cashless2.timeDateSeconds = block[7].part.data;
        cashless2.timeDateDayOfWeek = block[8].part.data;
        cashless2.timeDateWeekNumber = block[9].part.data;
        cashless2.timeDateSummertime = block[10].part.data;
        cashless2.timeDateHoliday = block[11].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
    }
    if (block[1].part.data == CASHLESS.expansion.optionalFeatureEnabled.command) {
        cashless2.vmcOptionalFeatureBits[4] = block[2].part.data;
        cashless2.vmcOptionalFeatureBits[3] = block[3].part.data;
        cashless2.vmcOptionalFeatureBits[2] = block[4].part.data;
        cashless2.vmcOptionalFeatureBits[1] = block[5].part.data;
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless2.address);
    }
  }
}
