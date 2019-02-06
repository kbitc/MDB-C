#include "Cashless.h"

/*  Setup Notes  (for users):
 *  Name this file Cashless#, with the # set to the desired cashless device.
 *  readerFeatureLevel, countryCurrencyCode
 *
 */
/*
 *  Abstract usage notes (for me):
 *  cashless.columnsOnDisplay, cashless.rowsOnDisplay, cashless.displayType 0=7seg,1ascii
 *
 *
 * Possibly obsolete flags/values
 * isActiveFlag
 * isBusyFlag
 * isOnlineFlag
 *
 */

static uint8_t rxResult;

extern uint8_t mainz();                        //Page 49-50, Section 7.2

struct cashlessVariables {
  String deviceID, readerID, sessionID, sessionID2, money, command;
  uint8_t address;                    //Page 49, this is a bitmask to identify between cashless1 and cashless2.
  //SETUP VARIABLES
    //Setup.configurationData Page 58-59
    uint8_t vmcFeatureLevel : 2;
    uint8_t columnsOnDisplay;
    uint8_t rowsOnDisplay;
    uint8_t displayType : 3;            //PWording selected to avoid confusion.
      //Setup.configurationData.Response Page 59-60
      uint8_t readerFeatureLevel : 2;
      uint8_t countryCurrencyCode[1];     //Page 61.
      uint8_t countryCurrencyCodeLevel3[1];
      uint8_t scaleFactor;
      uint8_t decimalPlaces;
      uint8_t applicationMaximumResponseTime;   //Maximum response time in seconds needed to respond to VMC. Page 12.
      uint8_t miscellaneousOptions : 4;       //Page 12.
    //Setup.maxMinPrices Page 61
    uint8_t maximumPrice[3];
    uint8_t minimumPrice[3];
    uint8_t vmcCurrencyCode[1];         //Page 61
  //POLL VARIABLES
    //Poll.readerConfigInfo is made up from vallues previously mentioned.
    //Poll.displayRequest Page 63
    uint8_t displayTime;
    char displayData[29];
    //Poll.beginSession Page64-67
    uint8_t fundsAvailable[3];
    uint8_t paymentMediaID[3];
    uint8_t paymentType;
    uint8_t paymentData[1];
    uint8_t userLanguage[1];
    uint8_t userCurrencyCode[1];
    uint8_t cardOptions;
    //Poll.sessionCancelRequest Page 67
    //Poll.vendApproved or denied, or endSession or cancelled. Page 67-68
    //Poll.peripheralID Page 68-69
    uint8_t readerManufacturerCode[2];
    uint8_t readerSerialNumber[11];
    uint8_t vmcSerialNumber[11];
    uint8_t readerModelNumber[11];
    //Poll.commandOutOfSequence Page 71
    uint8_t state : 3;
    //Poll.revalueDenied or Approved or limitAmount.  Page 71-73
    uint8_t revalueLimitAmount[3];
    //Poll.userFileData Page 73 OBSOLETE
    uint8_t numberOfUserFile;
    uint8_t lengthOfUserFile;
    //Poll.timeDateRequest Page 73
    //Poll.dataEntryRequest Page 74
    uint8_t dataEntryLengthAndRepeatBit;
    //Poll.FTLStuff or diagnostic response Page 75-77
  //VEND VALUES
    //Vend.vendRequest Page 77, vendRequest 78-79
    uint8_t itemPrice[1];
    uint8_t itemNumber[1];
    //Vend.vendApproved Page 78-79
    uint8_t vendAmount[3];
    //Vend.vendDenied Page 78
    //Vend.cashSale Page 82-83
    uint8_t itemCurrency[1];
    //Vend.negativeVendRequest Page 83
    uint8_t itemValu[1];
  //READER VALUES
    //Reader.dataEntryResponse Page 89-90
    uint8_t dataEntryData[7];
  //EXPANSION VALUES
    //Expansion.requestID Page93 and so on;
    uint8_t readerSoftwareVersion[1];
    uint8_t vmcManufacturerCode[2];
    uint8_t vmcModelNumber[11];
    uint8_t vmcSoftwareVersion[1];
    uint8_t vmcOptionalFeatureBits[3];
    struct optionalFeatureBits {
      uint8_t alternativePayoutMethod : 1;
      uint8_t extendedDiagnosticCommand : 1;
      uint8_t controlledManualFillPayoutCommands : 1;
      uint8_t ftl : 1;
      //28 more options reserved for future use
    } optionalFeatureBitsEnabled;
    //Expansion.writeTimeDateFile
    uint8_t timeDateYears;
    uint8_t timeDateMonths;
    uint8_t timeDateDays;
    uint8_t timeDateHours;
    uint8_t timeDateMinutes;
    uint8_t timeDateSeconds;
    uint8_t timeDateDayOfWeek;
    uint8_t timeDateWeekNumber;
    uint8_t timeDateSummertime;
    uint8_t timeDateHoliday;

//?
    uint8_t ftlDestinationAddress;
    uint8_t ftlFileID;
    uint8_t ftlMaximumLength;
    uint8_t ftlControl;
    uint8_t ftlRetryDeny;
    uint8_t destinationAddress;
    uint8_t blockNumber;
    uint8_t ftlData;
    uint8_t fileID;
    uint8_t control;
    uint8_t maximumLength;

//FLAGS.  If MDB were a kernel, these would be the shell commands.  Setting a flag will get the action done at the appropriate time.
  uint8_t displayRequestFlag : 1;               //Flag for when you have info to display on the vending screen.
    uint8_t displayDataPointer : 5;           //Makes calculating the message length bytes easier.
  uint8_t beginSessionFlag : 1;                 //Flag for when you want to begin a session with the VMC.  Page 15.
    uint8_t beginSessionReadyFlag : 1;            //After setting the begin session flag, a function loads up the necessary data, and sets this once done.  The pOLL function checks for this flag.
  uint8_t sessionCancelRequestFlag : 1;         //Flag to set if you want to cancel an active session.
  uint8_t errorCodeFlag;                        //Flag for when there is an error code to report.
  uint8_t commandOutOfSequenceFlag : 1;
  uint8_t justResetFlag : 1;
  uint8_t vendApprovedFlag : 1;
  uint8_t vendDeniedFlag : 1;
  uint8_t cancelledFlag : 1;
  uint8_t endSessionFlag : 1;
  uint8_t peripheralIDFlag: 1;
  uint8_t malfunctionErrorFlag : 1;
  uint8_t revalueDeniedFlag : 1;
  uint8_t revalueApprovedFlag : 1;
  uint8_t revalueLimitAmountFlag : 1;
  uint8_t timeDateRequestFlag : 1;
  uint8_t dataEntryRequestFlag : 1;
  uint8_t dataEntryCancelFlag : 1;
  uint8_t reqToRcvFlag : 1;
  uint8_t reqToSendFlag : 1;
  uint8_t retryDenyFlag : 1;
  uint8_t sendBlockFlag : 1;
  uint8_t okToSendFlag : 1;
  uint8_t configDataFlag : 1;
  uint8_t diagnosticResponseFlag : 1;
  uint8_t isActiveFlag : 1;       //Flag set when device has been addressed, and reset when the VMC is done addressing the peripheral.
  uint8_t isBusyFlag : 1;         //Flag set when device is busy doing something such as dispensing a coin, or connecting to a web service.
  uint8_t isOutgoingFlag : 1;     //Flag set when device has information to send in response to the next poll (excluding ACKnowledge).
  uint8_t isOnlineFlag : 1;       //Flag set when device is online, reset when device is offline, meaning ignore all MDB activity.
  uint8_t isResettingFlag : 1;    //Flag set when device recieves a reset command, and un-set when peripheral's reset completes.
  uint8_t isResetFlag : 1;        //Flag set when device has been reset, but hasn't transmitted the 'JUST RESET' response yet.
  uint8_t coinReturnPushed : 1;         /*Coin Mech Escrow/Return button pushed.*/
} cashless;                                   //Variables

uint8_t Cashless() {//Change global name
  /*if (begin)
    startCashless();
  if (reset)
    resetCashless();
  if ()*/
}

/*7.1*/
uint8_t startCashless () {
  struct cashlessVariables cashless;
  if ((__FILE__ == "Cashless1.cpp") || (__FILE__ == "Cashless1.c"))
    cashless.address = CASHLESS1_ADDRESS;
  else if ((__FILE__ == "Cashless2.cpp") || (__FILE__ == "Cashless2.c"))
    cashless.address = CASHLESS2_ADDRESS;
  else {
    //debug.println("Rename the Cashless.cpp to Cashless1.cpp, Cashless2.cpp, or Cashless3.cpp");
    //debug.println("The difference is:         Credit Cards,  Mobile Phones,    A battery powered device");
    return 0x01;;
  }
  rESET();
  cashless.justResetFlag = 0x00;  /*The only difference between setup and reset*/
  return 0x00;
}

uint8_t configCashless () {
  //For Setup - Config Data.
    cashless.readerFeatureLevel = 0x03;
    cashless.countryCurrencyCode[0] = 0x00;
    cashless.countryCurrencyCode[1] = 0x01;         //Telephone code for usa.
    cashless.countryCurrencyCodeLevel3[0] = 0x18;
    cashless.countryCurrencyCodeLevel3[1] = 0x40;   //Level 3 code for USA
    cashless.scaleFactor = 0x01;  //Pennies
    cashless.decimalPlaces = 0x02;  //Murica.
    cashless.applicationMaximumResponseTime = 0x00; //Default.
    cashless.miscellaneousOptions = (
      0x00
      | 0x01       /*Comment out this line if refunds are unsupported*/
      | 0x02       /*Comment out this line if multivend is unsupported*/
      | 0x04       /*Comment out this line if cashless device has no display*/
      | 0x08       /*Comment out this line if uninterested in CashSale reporting*/
    );             /*Bit descriptions (n/a) (n/a) (n/a) (n/a) (refunds) (multivend-capability) (hasDisplay) (Vend/Cash tracking)*/
    //For Expansion - PeripheralID.
   // cashless.optionalFeatureBits[0] = 0x00;  //Not used
   // cashless.optionalFeatureBits[1] = 0x00;  //Not used   OLD CODE, CHECK AND UPDATE TO DE NEW WEY
   // cashless.optionalFeatureBits[2] = 0x00;  //Not used
   // cashless.optionalFeatureBits[3] = 0x04;  //Bit descriptions (n/a) (n/a) (Always Idle) (Data Entry) (Negative Vend) (Multi-Currency/Lingual Support) (16 or 32 bit Monetary Format) (FTL Supported)
    cashless.readerSerialNumber[0] = 0x00;
    cashless.readerSerialNumber[1] = 0x00;
    cashless.readerSerialNumber[2] = 0x00;
    cashless.readerSerialNumber[3] = 0x00;
    cashless.readerSerialNumber[4] = 0x00;
    cashless.readerSerialNumber[5] = 0x00;
    cashless.readerSerialNumber[6] = 0x00;
    cashless.readerSerialNumber[7] = 0x00;
    cashless.readerSerialNumber[8] = 0x00;
    cashless.readerSerialNumber[9] = 0x00;
    cashless.readerSerialNumber[10] = 0x00;
    cashless.readerSerialNumber[11] = 0x00;  //Your very own serial number.
    cashless.readerModelNumber[0] = 0x00;
    cashless.readerModelNumber[1] = 0x00;
    cashless.readerModelNumber[2] = 0x00;
    cashless.readerModelNumber[3] = 0x00;
    cashless.readerModelNumber[4] = 0x00;
    cashless.readerModelNumber[5] = 0x00;
    cashless.readerModelNumber[6] = 0x00;
    cashless.readerModelNumber[7] = 0x00;
    cashless.readerModelNumber[8] = 0x00;
    cashless.readerModelNumber[9] = 0x00;
    cashless.readerModelNumber[10] = 0x00;
    cashless.readerModelNumber[11] = 0x00;  //Your very own model number.
    //For display request
    cashless.displayTime = 0xaa;            //Time unit is 0.1 seconds.
    cashless.displayData[0] = 0x01;         //The product of these two must equal the lenght of the message.
    cashless.displayData[1] = 0x0a;         //The product of these two must equal the length of the message.
    cashless.displayData[2] = 0x4b;
    cashless.displayData[3] = 0x49;         //ASCII characters. 4b 49 4c 4c 48 55 4d 41 4e 53
    cashless.displayData[4] = 0x4c;         //                  K  I  L  L  H  U  M  A  N  S
    cashless.displayData[5] = 0x4c;
    cashless.displayData[6] = 0x48;
    cashless.displayData[7] = 0x55;
    cashless.displayData[8] = 0x4d;
    cashless.displayData[9] = 0x41;
    cashless.displayData[10] = 0x4e;
    cashless.displayData[11] = 0x53;
    cashless.displayData[31] = 0xff;
    //For Begin Session
    cashless.fundsAvailable[0] = 0xff;          //Scaled, set to 0xffff if unknown.
    cashless.fundsAvailable[1] = 0xfe;
        cashless.paymentMediaID[0] = 0xff;      //Set to 0xffffffff if unknown.
        cashless.paymentMediaID[1] = 0xff;
        cashless.paymentMediaID[2] = 0xff;
        cashless.paymentMediaID[3] = 0xff;
        cashless.paymentType = 0x40;            //Test Vend.
        cashless.paymentData[0] = 0x00;
        cashless.paymentData[1] = 0x00;
            cashless.userLanguage[0] = 0x00;
            cashless.userLanguage[1] = 0x00;
            cashless.userCurrencyCode[0] = 0x00;
            cashless.userCurrencyCode[1] = 0x00;
            cashless.cardOptions = 0x00;
}

/*7.2  Incomplete*/
uint8_t mainz() {
  if (rX9BitsAvailable() == 0x01)
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

uint8_t terminateSession() {
}

/*7.3 Describes the flow of all functions
 *7.3.1
 *7.3.2 Check this over, implemented in main function.
/*7.3.0-7.3. is applied to all mdb side communications, and is more relevant to the VMC source file*/

/*7.4   INCOMPLETE*/

/*7.4.1*/
uint8_t rESET() {
  if (block[0].part.data == CASHLESS_RESET_COMMAND) { /*rESET() is called for a BUS RESET too, which you don't ACK.*/
    block[0].part.data = ACK;
    pointer = 0;
    tX(pointer, cashless.address);
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

  cashless.state = CASHLESS_STATE_INACTIVE;
}

/*7.4.2 - 7.4.3*/
uint8_t  sETUP() {
/*7.4.2*/
    if (block[1].part.data == CASHLESS_SETUP_CONFIGDATA_COMMAND) {
      cashless.vmcFeatureLevel = block[2].part.data;
      cashless.columnsOnDisplay = block[3].part.data;
      cashless.rowsOnDisplay = block[4].part.data;
      cashless.displayType = block[5].part.data;
      clearBlock(); /*Necessary for clearing old mode bits*/
      block[0].part.data = CASHLESS_SETUP_CONFIGDATA_RESPONSE_READERCONFIGDATA;
      block[1].part.data = cashless.readerFeatureLevel;
      block[2].part.data = cashless.countryCurrencyCode[0];  //First half of US country code.        Page-11
      block[3].part.data = cashless.countryCurrencyCode[1];  //Second half of US country code.       Page-11
      if ((cashless.vmcFeatureLevel == 0x03) && (cashless.readerFeatureLevel == 0x03)) {  //IF VMC supports Level 3 MDB.       Page-11
        block[2].part.data = cashless.countryCurrencyCodeLevel3[0];  //THEN use ISO4217 country code.    Page-11
        block[3].part.data = cashless.countryCurrencyCodeLevel3[1];  //Second half of ISO4217 code.      Page-11
    }
    block[4].part.data = cashless.scaleFactor;  //Sets the scale factor for the currency.     Page-11
    block[5].part.data = cashless.decimalPlaces;  //Sets decimal places up for cents.     Page-11
    block[6].part.data = cashless.applicationMaximumResponseTime;  //Sets maximum response time.      Page-12
    block[7].part.data = cashless.miscellaneousOptions;  //Sets refunds, multivend, display, and sales reporting.  Page-12
    pointer = 8;
    tX(pointer, cashless.address);  //Transmit Setup response block.
    cashless.isActiveFlag = 0x01;
    return 0;
    }
/*7.4.3*/
    if (block[1].part.data == CASHLESS_SETUP_MAXMINPRICES_COMMAND) {
        if ((cashless.state == CASHLESS_STATE_DISABLED) && (cashless.vmcFeatureLevel == 0x03)) {
        cashless.maximumPrice[0] = block[2].part.data;  //Scaled maximum price.                Page-12
        cashless.maximumPrice[1] = block[3].part.data;  //Second half of max price.            Page-12
        cashless.maximumPrice[2] = block[4].part.data;  //Scaled minimum price.                Page-12
        cashless.maximumPrice[3] = block[5].part.data;  //Second half of min price.            Page-12
        cashless.minimumPrice[0] = block[6].part.data;  //Scaled maximum price.                Page-12
        cashless.minimumPrice[1] = block[7].part.data;  //Second half of max price.            Page-12
        cashless.minimumPrice[2] = block[8].part.data;  //Scaled minimum price.                Page-12
        cashless.minimumPrice[3] = block[9].part.data;  //Second half of min price.            Page-12
        cashless.countryCurrencyCode[0] = block[10].part.data;
        cashless.countryCurrencyCode[1] = block[11].part.data;
        }
        else {
        cashless.maximumPrice[0] = block[2].part.data;  //Scaled maximum price.                Page-12
        cashless.maximumPrice[1] = block[3].part.data;  //Second half of max price.            Page-12
        cashless.minimumPrice[0] = block[4].part.data;  //Scaled minimum price.                Page-12
        cashless.minimumPrice[1] = block[5].part.data;  //Second half of min price.            Page-12
        }
        clearBlock();
        Serial1.write(0x100);
        cashless.state = CASHLESS_STATE_DISABLED;  //Device is now in the Disabled state, awaiting DEVICE-ENABLE.
        return 0;
    }
  }

/*7.4.4*/
uint8_t  pOLL() {
  if (cashless.justResetFlag == 0x01) {            //If the peripheral has finished resetting.
    clearBlock();
    block[0].part.data = CASHLESS_POLL_RESPONSE_JUSTRESET;
    tX(1, cashless.address);
    clearBlock();
    cashless.justResetFlag = 0x00;
  }
  else if (cashless.displayRequestFlag) {  //If cashless device requests to display on the Vending Machine's screen.
    block[0].whole = CASHLESS_POLL_RESPONSE_DISPLAYREQUEST;
    block[1].whole = cashless.displayTime;
    block[2].whole = cashless.displayData[0];
    block[3].whole = cashless.displayData[1];
    block[4].whole = cashless.displayData[2];
    block[5].whole = cashless.displayData[3];
    block[6].whole = cashless.displayData[4];
    block[7].whole = cashless.displayData[5];
    block[8].whole = cashless.displayData[6];
    block[9].whole = cashless.displayData[7];
    block[10].whole = cashless.displayData[8];
    block[11].whole = cashless.displayData[9];
    block[12].whole = cashless.displayData[10];
    block[13].whole = cashless.displayData[11];
    block[14].whole = cashless.displayData[12];
    block[15].whole = cashless.displayData[13];
    block[16].whole = cashless.displayData[14];
    block[17].whole = cashless.displayData[15];
    block[18].whole = cashless.displayData[16];
    block[19].whole = cashless.displayData[17];
    block[20].whole = cashless.displayData[18];
    block[21].whole = cashless.displayData[19];
    block[22].whole = cashless.displayData[20];
    block[23].whole = cashless.displayData[21];
    block[24].whole = cashless.displayData[22];
    block[25].whole = cashless.displayData[23];
    block[26].whole = cashless.displayData[24];
    block[27].whole = cashless.displayData[25];
    block[28].whole = cashless.displayData[26];
    block[29].whole = cashless.displayData[27];
    block[30].whole = cashless.displayData[28];
    block[31].whole = cashless.displayData[29];
    block[32].whole = cashless.displayData[30];
    block[33].whole = cashless.displayData[31];
    pointer = (cashless.columnsOnDisplay * cashless.rowsOnDisplay);
    tX(pointer, cashless.address);
    cashless.displayRequestFlag = 0;
    clearBlock();
    return 0;
  }          //Requests to display data.
  else if (cashless.beginSessionFlag) {
    cashless.state = CASHLESS_STATE_SESSIONIDLE;
    block[0].whole = CASHLESS_POLL_RESPONSE_BEGINSESSION;
    block[1].whole = cashless.fundsAvailable[0];    //Scaled Currency.
    block[2].whole = cashless.fundsAvailable[1];
    pointer = 3;
      if (cashless.vmcFeatureLevel >= (0x02)) {
        block[3].whole = cashless.paymentMediaID[0];
        block[4].whole = cashless.paymentMediaID[1];
        block[5].whole = cashless.paymentMediaID[2];
        block[6].whole = cashless.paymentMediaID[3];
        block[7].whole = cashless.paymentType;
        block[8].whole = cashless.paymentData[0];
        block[9].whole = cashless.paymentData[1];
        pointer = 10;
          if (cashless.vmcFeatureLevel == (0x03)) {
            block[10].whole = cashless.userLanguage[0];
            block[11].whole = cashless.userLanguage[1];
            block[12].whole = cashless.userCurrencyCode[0];
            block[13].whole = cashless.userCurrencyCode[1];
            block[14].whole = cashless.cardOptions;
            pointer = 15;
          }
      }
      tX(pointer, cashless.address);
      cashless.beginSessionFlag = 0x1;
    }            //Begins a Vend session.
    else if (cashless.sessionCancelRequestFlag == 0x01) {
      clearBlock();
      block[0].part.data = CASHLESS_POLL_RESPONSE_SESSIONCANCELREQUEST;
      rxResult = tX(1, cashless.address);
      if (block[0].part.data == ACK) {
        cashless.sessionCancelRequestFlag = 0x00;
      }
    }    //Cancels a Vend session.
    else if (cashless.vendApprovedFlag) {
      block[0].whole = CASHLESS_POLL_RESPONSE_VENDAPPROVED;
      block[1].whole = cashless.vendAmount[0];
      block[2].whole = cashless.vendAmount[1];
          pointer = 3;
          if (cashless.vmcFeatureLevel == 0x03) {
              block[3].whole = cashless.vendAmount[2];
              block[4].whole = cashless.vendAmount[3];
              pointer = 5;
          }
          tX(pointer, cashless.address);
          cashless.vendApprovedFlag = 0x00;
      }            //Approves a vend.
      else if (cashless.vendDeniedFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_VENDDENIED;
          tX(1, cashless.address);
          cashless.vendDeniedFlag = 0x00;
      }              //Denies a vend.
      else if (cashless.endSessionFlag = 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_ENDSESSION;
          tX(1, cashless.address);
      }              //Indicates the reader has returned to the enabled state, follows Session Cancel.
      else if (cashless.cancelledFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_CANCELLED;
          tX(1, cashless.address);
          cashless.cancelledFlag = 0x00;
      }               //Aborts rEADER activities which occur in the enabled state.
      else if (cashless.peripheralIDFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_PERIPHERALID;
          block[1].whole = cashless.readerManufacturerCode[0];
          block[2].whole = cashless.readerManufacturerCode[1];
          block[3].whole = cashless.readerManufacturerCode[3];
          counter = 0;
          while (counter != 11) {
            block[counter + 4].whole = cashless.readerSerialNumber[counter];
            block[counter + 16].whole = cashless.readerModelNumber[counter];
            counter++;
          }
          block[28].whole = cashless.readerSoftwareVersion[0];
          block[29].whole = cashless.readerSoftwareVersion[1];
          pointer = 30;
          if ((cashless.vmcFeatureLevel == 0x3) && (cashless.readerFeatureLevel == 0x3) && (/*optional Feature bits enabled by VMC*/0x01)) { /////////////////////////////////
              block[30].whole = (/*
                (cashless.optionalFeatureBitsEnabled. << 7) |
                (cashless.optionalFeatureBitsEnabled. << 6) |
                (cashless.optionalFeatureBitsEnabled. << 5) |
                (cashless.optionalFeatureBitsEnabled. << 4) |
                (cashless.optionalFeatureBitsEnabled. << 3) |
                (cashless.optionalFeatureBitsEnabled. << 2) |
                (cashless.optionalFeatureBitsEnabled. << 1) |
                (cashless.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[31].whole = (/*
                (cashless.optionalFeatureBitsEnabled. << 7) |
                (cashless.optionalFeatureBitsEnabled. << 6) |
                (cashless.optionalFeatureBitsEnabled. << 5) |
                (cashless.optionalFeatureBitsEnabled. << 4) |
                (cashless.optionalFeatureBitsEnabled. << 3) |
                (cashless.optionalFeatureBitsEnabled. << 2) |
                (cashless.optionalFeatureBitsEnabled. << 1) |
                (cashless.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[32].whole = (/*
                (cashless.optionalFeatureBitsEnabled. << 7) |
                (cashless.optionalFeatureBitsEnabled. << 6) |
                (cashless.optionalFeatureBitsEnabled. << 5) |
                (cashless.optionalFeatureBitsEnabled. << 4) |
                (cashless.optionalFeatureBitsEnabled. << 3) |
                (cashless.optionalFeatureBitsEnabled. << 2) |
                (cashless.optionalFeatureBitsEnabled. << 1) |
                (cashless.optionalFeatureBitsEnabled.     )*/
                0x000
              );
              block[33].whole = (/*
                (cashless.optionalFeatureBitsEnabled. << 7) |
                (cashless.optionalFeatureBitsEnabled. << 6) |
                (cashless.optionalFeatureBitsEnabled. << 5) |
                (cashless.optionalFeatureBitsEnabled. << 4) |*/
                (cashless.optionalFeatureBitsEnabled.ftl << 3) |
                (cashless.optionalFeatureBitsEnabled.controlledManualFillPayoutCommands << 2) |
                (cashless.optionalFeatureBitsEnabled.extendedDiagnosticCommand << 1) |
                (cashless.optionalFeatureBitsEnabled.alternativePayoutMethod)
              );
              pointer = 34;
          }
          tX(pointer, cashless.address);
          cashless.peripheralIDFlag = 0x00;
      }            //Response to cashless.expansion.peripheralID.command
      else if (cashless.malfunctionErrorFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_MALFUNCTIONERROR;
          block[1].whole = cashless.errorCodeFlag;
          tX(2, cashless.address);
      }        //Reports an error or malfunction to the VMC.
      else if (cashless.commandOutOfSequenceFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_COMMANDOUTOFSEQUENCE;
          pointer = 1;
          if ((cashless.vmcFeatureLevel >= 2) && (cashless.readerFeatureLevel >= 2)) {
              block[1].whole = cashless.state;
              pointer = 2;
          }
          tX(pointer, cashless.address);
      }        //Tells the VMC that a command was sent out of sequence.
      else if (cashless.revalueApprovedFlag) {

      }         //     revalue involves putting money back onto a cashless payment source.
      else if (cashless.revalueDeniedFlag == 0x01) {

      }           //
      else if (cashless.revalueLimitAmount) {

      }      //
      /*else if (cashless.userFileData) {
          Do not use, obsolete.
      }          //Obsolete command.*/
      else if (cashless.timeDateRequestFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_TIMEDATEREQUEST;
          tX(1, cashless.address);
      }         //Request time/date from VMC.
      else if (cashless.dataEntryRequestFlag == 0x01) {  //Request input from machine Keypad.
          block[0].whole = CASHLESS_POLL_RESPONSE_DATAENTRYREQUEST;
          block[1].whole = cashless.dataEntryLengthAndRepeatBit;
          tX(2, cashless.address);
      }        //Request input from VMC Keypad.
      else if (cashless.dataEntryCancelFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_DATAENTRYCANCEL;
          tX(1, cashless.address);
      }         //Cancel input session.
      else if (cashless.reqToRcvFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_REQTORCV;
          block[1].whole = cashless.ftlDestinationAddress;
          block[2].whole = cashless.address;
          block[3].whole = cashless.ftlFileID;
          block[4].whole = cashless.ftlMaximumLength;
          block[5].whole = cashless.ftlControl;
          tX(6, cashless.address);
      }                //File Transport Layer
      else if (cashless.retryDenyFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_RETRYDENY;
          block[1].whole = cashless.ftlDestinationAddress;
          block[2].whole = cashless.address;
          block[3].whole = cashless.ftlRetryDeny;
          tX(4, cashless.address);
      }               //File Transport Layer
      else if (cashless.sendBlockFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_SENDBLOCK;
          block[1].whole = cashless.destinationAddress;
          block[2].whole = cashless.blockNumber;
          block[3].whole = cashless.ftlData;
          tX(4, cashless.address);
      }               //File Transport Layer
      else if (cashless.okToSendFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_OKTOSEND;
          block[1].whole = cashless.destinationAddress;
          block[2].whole = cashless.address;
          tX(3, cashless.address);
      }                //File transport Layer
      else if (cashless.reqToSendFlag == 0x01) {
          block[0].whole = CASHLESS_POLL_RESPONSE_REQTOSEND;
          block[1].whole = cashless.destinationAddress;
          block[2].whole = cashless.address;
          block[3].whole = cashless.fileID;
          block[4].whole = cashless.maximumLength;
          block[5].whole = cashless.control;
          tX(6, cashless.address);
      }               //File Transport Layer
      else if (cashless.diagnosticResponseFlag == 0x01) {

      }      //
      else if (cashless.configDataFlag == 0x01) { //CONFIG DATA... I assume this is for compatibility, we don't use this.  Page 14.
          block[0].part.data = CASHLESS_POLL_RESPONSE_READERCONFIGINFO;   //Lets the VMC know you are replying to CONFIG-DATA, from a previous SETUP command.
      block[1].part.data = cashless.readerFeatureLevel;  //Tells VMC device supports Level 3.    Page-10
      block[2].part.data = cashless.countryCurrencyCode[0];  //First half of US country code.        Page-11
      block[3].part.data = cashless.countryCurrencyCode[1];  //Second half of US country code.       Page-11
      if ((cashless.vmcFeatureLevel == 0x03) && (cashless.readerFeatureLevel == 0x03)) {  //IF VMC supports Level 3 MDB.       Page-11
          block[2].part.data = (0x18);  //THEN use ISO4217 country code.    Page-11
          block[3].part.data = (0x40);  //Second half of ISO4217 code.      Page-11
      }
      block[4].part.data = (0x01);  //Sets coin scale to 1 for pennies.     Page-11
      block[5].part.data = (0x02);  //Sets decimal places up for cents.     Page-11
      block[6].part.data = cashless.applicationMaximumResponseTime;  //Sets maximum response time.      Page-12
      block[7].part.data = cashless.miscellaneousOptions;  //Sets refunds, multivend, display, and sales reporting.  Page-12
      block[8].part.mode = (0x01);  //Set data length.
      tX(9, cashless.address);  //Transmit Setup response block.
      }              //Sends config data.
      else
          Serial1.write(0x100);
      clearBlock();
}

/*7.4.5 - 7.4.11*/
uint8_t  vEND() {
/*7.4.5*/
    if (block[1].part.data == CASHLESS_VEND_VENDREQUEST_COMMAND) {
        cashless.itemPrice[0] = block[2].part.data;
        cashless.itemPrice[1] = block[3].part.data;
        cashless.itemNumber[0] = block[4].part.data;
        cashless.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ACK;
        tX(0, cashless.address);
    }
/*7.4.6*/
    if (block[1].part.data == CASHLESS_VEND_VENDCANCEL_COMMAND) {
        block[0].whole = CASHLESS_VEND_VENDCANCEL_RESPONSE_VENDDENIED;
        tX(1, cashless.address);
    }
/*7.4.7*/
    if (block[1].part.data == CASHLESS_VEND_VENDSUCCESS_COMMAND) {
        cashless.itemNumber[0] = block[2].part.data;
        cashless.itemNumber[1] = block[3].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
/*7.4.8*/
    if (block[1].part.data == CASHLESS_VEND_VENDFAILURE_COMMAND) {
        return 0;
    }
/*7.4.9*/
    if (block[1].part.data == CASHLESS_VEND_SESSIONCOMPLETE_COMMAND) {
        clearBlock();
        block[0].part.data = CASHLESS_VEND_SESSIONCOMPLETE_RESPONSE_ENDSESSION;
        pointer = 1;
        tX(pointer, cashless.address);
        cashless.state = CASHLESS_STATE_ENABLED;
    }
/*7.4.10*/
    if (block[1].part.data == CASHLESS_VEND_CASHSALE_COMMAND) {
        cashless.itemPrice[0] = block[2].part.data;
        cashless.itemPrice[1] = block[3].part.data;
        cashless.itemNumber[0] = block[4].part.data;
        cashless.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
  }
/*7.4.11*/
}

/*7.4.12 - 7.4.15*/
uint8_t  rEADER() {
/*7.4.12*/
  if (block[1].part.data == CASHLESS_READER_READERDISABLE_COMMAND) {
    cashless.state = CASHLESS_STATE_DISABLED;
    clearBlock();
    block[0].part.data = ACK;
    pointer = 0;
    tX(pointer, cashless.address);
  }
/*7.4.13*/
  if (block[1].part.data == CASHLESS_READER_READERENABLE_COMMAND) {
    cashless.state = CASHLESS_STATE_ENABLED;
    clearBlock();
    block[0].part.data = ACK;
    pointer = 0;
    tX(pointer, cashless.address);
  }
/*7.4.14*/
/*7.4.15*/
}

/*7.4.16 - 7.4.17*/
uint8_t  rEVALUE() {
/*7.4.16*/
/*7.4.17*/
}

/*7.4.18*/
uint8_t eXPANSION() {
/*7.4.18*/
  if (block[1].part.data == CASHLESS_EXPANSION_REQUESTID_COMMAND) {
    cashless.vmcManufacturerCode[0] = block[2].part.data;
    cashless.vmcManufacturerCode[1] = block[3].part.data;
    cashless.vmcManufacturerCode[2] = block[4].part.data;
    cashless.vmcSerialNumber[0] = block[5].part.data;
    cashless.vmcSerialNumber[1] = block[6].part.data;
    cashless.vmcSerialNumber[2] = block[7].part.data;
    cashless.vmcSerialNumber[3] = block[8].part.data;
    cashless.vmcSerialNumber[4] = block[9].part.data;
    cashless.vmcSerialNumber[5] = block[10].part.data;
    cashless.vmcSerialNumber[6] = block[11].part.data;
    cashless.vmcSerialNumber[7] = block[12].part.data;
    cashless.vmcSerialNumber[8] = block[13].part.data;
    cashless.vmcSerialNumber[9] = block[14].part.data;
    cashless.vmcSerialNumber[10] = block[15].part.data;
    cashless.vmcSerialNumber[11] = block[16].part.data;
    cashless.vmcModelNumber[0] = block[17].part.data;
    cashless.vmcModelNumber[1] = block[18].part.data;
    cashless.vmcModelNumber[2] = block[19].part.data;
    cashless.vmcModelNumber[3] = block[20].part.data;
    cashless.vmcModelNumber[4] = block[21].part.data;
    cashless.vmcModelNumber[5] = block[22].part.data;
    cashless.vmcModelNumber[6] = block[23].part.data;
    cashless.vmcModelNumber[7] = block[24].part.data;
    cashless.vmcModelNumber[8] = block[25].part.data;
    cashless.vmcModelNumber[9] = block[26].part.data;
    cashless.vmcModelNumber[10] = block[27].part.data;
    cashless.vmcModelNumber[11] = block[28].part.data;
    cashless.vmcSoftwareVersion[0] = block[29].part.data;
    cashless.vmcSoftwareVersion[1] = block[30].part.data;
    block[2].part.data = cashless.readerManufacturerCode[0];
    block[3].part.data = cashless.readerManufacturerCode[1];
    block[4].part.data = cashless.readerManufacturerCode[2];
    block[5].part.data = cashless.readerSerialNumber[0];
    block[6].part.data = cashless.readerSerialNumber[1];
    block[7].part.data = cashless.readerSerialNumber[2];
    block[8].part.data = cashless.readerSerialNumber[3];
    block[9].part.data = cashless.readerSerialNumber[4];
    block[10].part.data = cashless.readerSerialNumber[5];
    block[11].part.data = cashless.readerSerialNumber[6];
    block[12].part.data = cashless.readerSerialNumber[7];
    block[13].part.data = cashless.readerSerialNumber[8];
    block[14].part.data = cashless.readerSerialNumber[9];
    block[15].part.data = cashless.readerSerialNumber[10];
    block[16].part.data = cashless.readerSerialNumber[11];
    block[17].part.data = cashless.readerModelNumber[0];
    block[18].part.data = cashless.readerModelNumber[1];
    block[19].part.data = cashless.readerModelNumber[2];
    block[20].part.data = cashless.readerModelNumber[3];
    block[21].part.data = cashless.readerModelNumber[4];
    block[22].part.data = cashless.readerModelNumber[5];
    block[23].part.data = cashless.readerModelNumber[6];
    block[24].part.data = cashless.readerModelNumber[7];
    block[25].part.data = cashless.readerModelNumber[8];
    block[26].part.data = cashless.readerModelNumber[9];
    block[27].part.data = cashless.readerModelNumber[10];
    block[28].part.data = cashless.readerModelNumber[11];
    block[29].part.data = cashless.readerSoftwareVersion[0];
    block[30].part.data = cashless.readerSoftwareVersion[1];
    pointer = 31;
    if (cashless.vmcFeatureLevel == 0x03) {
      block[30].whole = (/*
        (cashless.optionalFeatureBitsEnabled. << 7) |
        (cashless.optionalFeatureBitsEnabled. << 6) |
        (cashless.optionalFeatureBitsEnabled. << 5) |
        (cashless.optionalFeatureBitsEnabled. << 4) |
        (cashless.optionalFeatureBitsEnabled. << 3) |
        (cashless.optionalFeatureBitsEnabled. << 2) |
        (cashless.optionalFeatureBitsEnabled. << 1) |
        (cashless.optionalFeatureBitsEnabled.     )*/
        0x000
      );
      block[31].whole = (/*
        (cashless.optionalFeatureBitsEnabled. << 7) |
        (cashless.optionalFeatureBitsEnabled. << 6) |
        (cashless.optionalFeatureBitsEnabled. << 5) |
        (cashless.optionalFeatureBitsEnabled. << 4) |
        (cashless.optionalFeatureBitsEnabled. << 3) |
        (cashless.optionalFeatureBitsEnabled. << 2) |
        (cashless.optionalFeatureBitsEnabled. << 1) |
        (cashless.optionalFeatureBitsEnabled.     )*/
        0x000
      );
      block[32].whole = (/*
        (cashless.optionalFeatureBitsEnabled. << 7) |
        (cashless.optionalFeatureBitsEnabled. << 6) |
        (cashless.optionalFeatureBitsEnabled. << 5) |
        (cashless.optionalFeatureBitsEnabled. << 4) |
        (cashless.optionalFeatureBitsEnabled. << 3) |
        (cashless.optionalFeatureBitsEnabled. << 2) |
        (cashless.optionalFeatureBitsEnabled. << 1) |
        (cashless.optionalFeatureBitsEnabled.     )*/
        0x000
      );
      block[33].whole = (/*
        (cashless.optionalFeatureBitsEnabled. << 7) |
        (cashless.optionalFeatureBitsEnabled. << 6) |
        (cashless.optionalFeatureBitsEnabled. << 5) |
        (cashless.optionalFeatureBitsEnabled. << 4) |*/
        (cashless.optionalFeatureBitsEnabled.ftl << 3) |
        (cashless.optionalFeatureBitsEnabled.controlledManualFillPayoutCommands << 2) |
        (cashless.optionalFeatureBitsEnabled.extendedDiagnosticCommand << 1) |
        (cashless.optionalFeatureBitsEnabled.alternativePayoutMethod)
      );
      pointer = 35;
    }
    tX(pointer, cashless.address);                                   ////I just now remembered loops exist.
}
/*7.4.19*/
  if (block[1].part.data == CASHLESS_EXPANSION_READUSERFILE_COMMAND) {
      clearBlock();
      block[0].part.data = CASHLESS_EXPANSION_READUSERFILE_RESPONSE_USERFILEDATA;  //Currently unsupported and not forseen to be needed.
      pointer = 1;
      tX(pointer, cashless.address);
    }
/*7.4.20*/
  if (block[1].part.data == CASHLESS_EXPANSION_WRITEUSERFILE_COMMAND) {
        clearBlock();                       //Obsolete command, not seen as necessary to add.
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
/*7.4.21*/
  if (block[1].part.data == CASHLESS_EXPANSION_WRITETIMEDATE_COMMAND) {
        cashless.timeDateYears = block[2].part.data;
        cashless.timeDateMonths = block[3].part.data;
        cashless.timeDateDays = block[4].part.data;
        cashless.timeDateHours = block[5].part.data;
        cashless.timeDateMinutes = block[6].part.data;
        cashless.timeDateSeconds = block[7].part.data;
        cashless.timeDateDayOfWeek = block[8].part.data;
        cashless.timeDateWeekNumber = block[9].part.data;
        cashless.timeDateSummertime = block[10].part.data;
        cashless.timeDateHoliday = block[11].part.data;
        clearBlock();
        block[0].part.data = ACK;
        pointer = 0;
    }
/*7.4.22*/
  if (block[1].part.data == CASHLESS_EXPANSION_OPTIONALFEATUREENABLED_COMMAND) {
        cashless.vmcOptionalFeatureBits[3] = block[2].part.data;
        cashless.vmcOptionalFeatureBits[2] = block[3].part.data;
        cashless.vmcOptionalFeatureBits[1] = block[4].part.data;
        cashless.vmcOptionalFeatureBits[0] = block[5].part.data;
        block[0].part.data = ACK;
        pointer = 0;
        tX(pointer, cashless.address);
    }
/*7.4.23*/
/*7.4.24*/
/*7.4.25*/
/*7.4.26*/
/*7.4.27*/
/*7.4.28*/
}


uint8_t beginSession(String data) {  //I don't remember this, it's old code so might be obsolete?
  clearBlock();
  //block[0].part.data = 0xaa;
  //block[1].part.data = 0xc0;
  //block[2].part.data = 0x55;
  //tX(3, cashless.address);
  cashless.fundsAvailable[0] = data.charAt(0);
  cashless.fundsAvailable[1] = data.charAt(1);     //Load minimum known currency.
  if (cashless.vmcFeatureLevel == 0x02) {
    cashless.paymentMediaID[0] = data.charAt(2);
    cashless.paymentMediaID[1] = data.charAt(3);
    cashless.paymentMediaID[2] = data.charAt(4);
    cashless.paymentMediaID[3] = data.charAt(5);
    cashless.paymentType = data.charAt(6);
    cashless.paymentData[0] = data.charAt(7);
    cashless.paymentData[1] = data.charAt(8);
  }
  if (cashless.vmcFeatureLevel == 0x03) {
    cashless.fundsAvailable[2] = data.charAt(2);
    cashless.fundsAvailable[3] = data.charAt(3);
    cashless.paymentMediaID[0] = data.charAt(4);
    cashless.paymentMediaID[1] = data.charAt(5);
    cashless.paymentMediaID[2] = data.charAt(6);
    cashless.paymentMediaID[3] = data.charAt(7);
    cashless.paymentType = data.charAt(8);
    cashless.paymentData[0] = data.charAt(9);
    cashless.paymentData[1] = data.charAt(10);
    cashless.userLanguage[0] = data.charAt(11);
    cashless.userLanguage[1] = data.charAt(12);
    cashless.userCurrencyCode[0] = data.charAt(13);
    cashless.userCurrencyCode[1] = data.charAt(14);
    cashless.cardOptions = data.charAt(15);
  }
  cashless.beginSessionFlag = 0x00;
  cashless.beginSessionReadyFlag = 0x01;
  return 1;
}

uint8_t sessionCancelRequest(String data) {
  cashless.sessionCancelRequestFlag = 0x01;
  return 0;
}

uint8_t vendApproved(String data) {
  /*I believe the data.charAt stuff was old Particle Photon Web IDE stuff*/
  cashless.vendAmount[0] = data.charAt(0);
  cashless.vendAmount[1] = data.charAt(1);
  if (cashless.vmcFeatureLevel == 0x03) {
    cashless.vendAmount[2] = data.charAt(2);
    cashless.vendAmount[3] = data.charAt(3);
  }
  cashless.vendApprovedFlag = 0x01;
  return 0;
}

uint8_t vendDenied(String data) {
  cashless.vendDeniedFlag = 0x00;
  return 0;
}

uint8_t displayRequest(String data) {
  /*Yet to be tackled?*/
    return 1;
}

uint8_t displayCancel(String data) {
    //cashless.displayCancel = 0x01;
    return 1;
}
