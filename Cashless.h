#include "Communication_Format.cpp"

extern int tX(unsigned int pointer, unsigned char address);

//7.2.1

typedef struct cashlessType {
  unsigned char address;  //Just so it compiles, fix/remove this later.
  union state {
    unsigned char inactive : 1;
    unsigned char disabled : 2;
    unsigned char enabled : 2;
    unsigned char sessionIdle :3 ;
    unsigned char vend : 3;
    unsigned char revalue : 3;
    unsigned char negativeVend : 3;
  } state;                            //Device state labels.
//Command Identification & Bitmasks
  struct reset {
    unsigned char command : 1;
  } reset;                                  //Page57
  struct setup {
    unsigned char command : 1;
    struct configData {
      unsigned char command : 1;
      struct response {
        unsigned char readerConfigData : 1;
      } response;
    } configData;     //Config Data subcommand & response. Page 10-12.
    struct {        //Maintains consistent formatting.
      unsigned char command : 1;    //Min/Max Prices subcommand. Page 12.
    } maxMinPrices;
  } setup;                             //Page 58-61
  struct {
    unsigned char command : 2;
    struct {
      unsigned char justReset : 1;
      unsigned char readerConfigInfo : 1;
      unsigned char displayRequest : 2;
      unsigned char beginSession : 2;
      unsigned char sessionCancelRequest : 3;
      unsigned char vendApproved : 3;
      unsigned char vendDenied : 3;
      unsigned char endSession : 3;
      unsigned char cancelled : 4;
      unsigned char peripheralID : 4;
      unsigned char malfunctionError : 4;
      unsigned char commandOutOfSequence : 4;
      unsigned char diagnosticResponse : 4;
      unsigned char revalueApproved : 4;
      unsigned char revalueDenied : 4;
      unsigned char revalueLimitAmount : 4;
      unsigned char userFileData : 5;
      unsigned char timeDateRequest : 5;
      unsigned char dataEntryRequest : 5;
      unsigned char dataEntryCancel : 5;
      unsigned char oneAH : 5;
      unsigned char reqToRcv : 5;
      unsigned char retryDeny : 5;
      unsigned char sendBlock : 5;
      unsigned char okToSend : 5;
      unsigned char reqToSend : 5;
      unsigned char feh : 6;
    } response;                             //Page 62
  } poll;                              //Page 63-77
  struct {
    unsigned char command : 2;
    struct {
      unsigned char command : 1;
      struct {
        unsigned char vendApproved : 3;
        unsigned char vendDenied : 3;
      } response;
    } vendRequest;
    struct {
      unsigned char command : 1;
      struct {
        unsigned char vendDenied : 3;
      } response;
    } vendCancel;
    struct {
      unsigned char command : 2;
    } vendSuccess;
    struct {
      unsigned char command : 2;
    } vendFailure;
      struct {
      unsigned char command : 3;
      struct {
        unsigned char endSession : 3;
      } response;
    } sessionComplete;
    struct {
      unsigned char command : 3;
    } cashSale;
    struct {
        unsigned char command : 3;
        struct {
          unsigned char vendApproved : 3;
          unsigned char vendDenied : 3;
        } response;
      } negativeVendRequest;
  } vend;                              //Page 77-81
  struct {
    unsigned char command : 3;
    struct {
      unsigned char command : 1;
    } readerDisable;
    struct {
      unsigned char command : 1;
    } readerEnable;
    struct {
      unsigned char  command : 2;
      struct {
        unsigned char cancelled : 4;
      } response;
    } readerCancel;
    struct {
        unsigned char command : 2;
      } dataEntryResponse;
  } reader;                            //Page 81-90
  struct {
    unsigned char command : 3;
    struct {
      unsigned char command : 1;
      struct {
        unsigned char revalueApproved : 4;
        unsigned char revalueDenied : 4;
      } response;
    } revalueRequest;
    struct {
      unsigned char command : 1;
      struct {
        unsigned char revalueLimitAmount : 4;
        unsigned char revalueDenied : 4;
      } response;
    } revalueLimitRequest;
  } revalue;                           //Page 91-93
  struct {
    unsigned char command = 0x07;
    struct {
      unsigned char command = 0x00;
      struct {
        unsigned char peripheralID = 0x09;
      } response;
    } requestID;
    struct {
      unsigned char command = 0xff;
      struct {
        unsigned char diagnosticResponse = 0xff;
      } response;
    } diagnostics;
    struct {
      unsigned char command = 0x01;
      struct {
        unsigned char userFileData = 0x10;
      } response;
    } readUserFile;
    struct {
      unsigned char command = 0x02;
    } writeUserFile;
    struct {
      unsigned char command = 0x03;
    } writeTimeDate;
    struct {
      unsigned char command = 0x04;
    } optionalFeatureEnabled;
    struct  {
      struct {
        unsigned char command = 0xfa;
        struct {
          unsigned char sendBlock = 0x1d;
          unsigned char retryDeny = 0x1c;
        } response;
      } reqToRcv;
      struct {
      unsigned char command = 0xfb;
      } retryDeny;
      struct {
        unsigned char command = 0xfc;
      } sendBlock;
      struct {
        unsigned char command = 0xfd;
        struct {
          unsigned char sendBlock = 0x1d;
        } response;
      } okToSend;
      struct {
        unsigned char command = 0xfe;
        struct {
          unsigned char okToSend = 0x1e;
          unsigned char retryDeny = 0x1c;
        } response;
      } reqToSend;
    } ftl;
  } expansion;                         //Page 93-100
  struct {                             //Poll.malfunctionError Page 70-71
    unsigned char paymentMedia1 : 4;
    unsigned char invalidPaymentMedia1 : 4;
    unsigned char tamper : 4;
    unsigned char manufacturerDefined1 : 4;
    unsigned char communications2 : 4;
    unsigned char readerRequiresService2 : 4;
    unsigned char unassigned2 : 4;
    unsigned char manufacturerDefined2 : 4;
    unsigned char readerFailure3 : 4;
    unsigned char communications3 : 4;
    unsigned char paymentMediaJammed3 : 4;
    unsigned char manufacturerDefined3 : 4;
    unsigned char refundInternalReaderCreditLost : 4;
  } error;
} cashlessType;                            //Constants

  cashlessType cashless;

  void cashlessSetup() {
  cashless.state.inactive = 0x1;
  cashless.state.disabled = 0x2;
  cashless.state.enabled = 0x03;
  cashless.state.sessionIdle = 0x04;
  cashless.state.vend = 0x05;
  cashless.state.revalue = 0x06;
  cashless.state.negativeVend = 0x07;
  cashless.reset.command = 0x0;
  cashless.setup.command = 0x1;
    cashless.setup.configData.command = 0x00;
    cashless.setup.configData.response.readerConfigData = 0x01;
  cashless.setup.maxMinPrices.command = 0x01;
  cashless.poll.command = 0x2;
    cashless.poll.response.justReset = 0x00;
    cashless.poll.response.readerConfigInfo = 0x01;
    cashless.poll.response.displayRequest = 0x02;
    cashless.poll.response.beginSession = 0x03;
    cashless.poll.response.sessionCancelRequest = 0x04;
    cashless.poll.response.vendApproved = 0x05;
    cashless.poll.response.vendDenied = 0x06;
    cashless.poll.response.endSession = 0x07;
    cashless.poll.response.cancelled = 0x08;
    cashless.poll.response.peripheralID = 0x09;
    cashless.poll.response.malfunctionError = 0x0a;
    cashless.poll.response.commandOutOfSequence = 0x0b;
    cashless.poll.response.diagnosticResponse = 0xff;
    cashless.poll.response.revalueApproved = 0x0d;
    cashless.poll.response.revalueDenied = 0x0e;
    cashless.poll.response.revalueLimitAmount = 0x0f;
    cashless.poll.response.userFileData = 0x10;
    cashless.poll.response.timeDateRequest = 0x11;
    cashless.poll.response.dataEntryRequest = 0x12;
    cashless.poll.response.dataEntryCancel = 0x13;
    cashless.poll.response.oneAH = 0x14;
    cashless.poll.response.reqToRcv = 0x1b;
    cashless.poll.response.retryDeny = 0x1c;
    cashless.poll.response.sendBlock = 0x1d;
    cashless.poll.response.okToSend = 0x1e;
    cashless.poll.response.reqToSend = 0x1f;
    cashless.poll.response.feh = 0x20;
  cashless.vend.command = 0x3;
    cashless.vend.vendRequest.command  = 0x00;
      cashless.vend.vendRequest.response.vendApproved = 0x05;
      cashless.vend.vendRequest.response.vendDenied = 0x06;
    cashless.vend.vendCancel.command = 0x01;
      cashless.vend.vendCancel.response.vendDenied = 0x06;
    cashless.vend.vendSuccess.command = 0x02;
    cashless.vend.vendFailure.command = 0x03;
    cashless.vend.sessionComplete.command = 0x04;
      cashless.vend.sessionComplete.response.endSession = 0x07;
    cashless.vend.cashSale.command = 0x05;
    cashless.vend.negativeVendRequest.command = 0x06;
      cashless.vend.negativeVendRequest.response.vendApproved = 0x05;
      cashless.vend.negativeVendRequest.response.vendDenied = 0x06;
  cashless.reader.command = 0x04;
    cashless.reader.readerDisable.command = 0x00;
    cashless.reader.readerDisable.command = 0x01;
    cashless.reader.readerCancel.command = 0x02;
      cashless.reader.readerCancel.response.cancelled = 0x08;
    cashless.reader.dataEntryResponse.command = 0x03;
  cashless.revalue.command = 0x05;
  cashless.revalue.revalueRequest.command = 0x00;
    cashless.revalue.revalueRequest.response.revalueApproved = 0x0d;
    cashless.revalue.revalueRequest.response.revalueDenied = 0x0e;
  cashless.revalue.revalueLimitRequest.command = 0x01;
    cashless.revalue.revalueLimitRequest.response.revalueLimitAmount = 0x0f;
    cashless.revalue.revalueLimitRequest.response.revalueDenied = 0x0e;
  cashless.expansion.command = 0x07;
    cashless.expansion.requestID.command = 0x00;
    cashless.expansion.requestID.response.peripheralID = 0x09;
  cashless.expansion.diagnostics.command = 0xff;
    cashless.expansion.diagnostics.response.diagnosticResponse = 0xff;
  cashless.expansion.readUserFile.command = 0x01;
  cashless.expansion.readUserFile.response.userFileData = 0x10;
  cashless.expansion.writeUserFile.command = 0x02;
  cashless.expansion.writeTimeDate.command = 0x03;
  cashless.expansion.optionalFeatureEnabled.command = 0x04;
  /*cashless.expansion.ftl.reqToRcv.command = 0xfa;
  cashless.expansion.ftl.reqToRcv.response.sendBlock = 0x1d;
  cashless.expansion.ftl.reqToRcv.response.retryDeny = 0x1c;
  cashless.expansion.ftl.retryDeny.command = 0xfb;
  cashless.expansion.ftl.sendBlock.command = 0xfc;
  cashless.expansion.ftl.okToSend.command = 0xfd;
  cashless.expansion.ftl.okToSend.response.sendBlock = 0x1d;
  cashless.expansion.ftl.reqToSend.command = 0xfe;
  cashless.expansion.ftl.reqToSend.response.okToSend = 0x1e;
  cashless.expansion.ftl.reqToSend.response.retryDeny = 0x1c;*/
  cashless.error.paymentMedia1 = 0x0f;
  cashless.error.invalidPaymentMedia1 = 0x1f;
  cashless.error.tamper = 0x2f;
  cashless.error.manufacturerDefined1 = 0x3f;
  cashless.error.communications2 = 0x4f;
  cashless.error.readerRequiresService2 = 0x5f;
  cashless.error.unassigned2 = 0x6f;
  cashless.error.manufacturerDefined2 = 0x7f;
  cashless.error.readerFailure3 = 0x8f;
  cashless.error.communications3 = 0x9f;
  cashless.error.paymentMediaJammed3 = 0xaf;
  cashless.error.manufacturerDefined3 = 0xbf;
  cashless.error.refundInternalReaderCreditLost = 0xcf;
}

struct CashlessPaymentDevice{
  String deviceID, readerID, sessionID, sessionID2, money, command;
  unsigned char address;                    //Page 49, this is a bitmask to identify between cashless1 and cashless2.
  //SETUP VARIABLES
    //Setup.configurationData Page 58-59
    unsigned char vmcFeatureLevel : 2;
    unsigned char columnsOnDisplay;
    unsigned char rowsOnDisplay;
    unsigned char displayType : 3;            //PWording selected to avoid confusion.
      //Setup.configurationData.Response Page 59-60
      unsigned char readerFeatureLevel : 2;
      unsigned char countryCurrencyCode[1];     //Page 61.
      unsigned char countryCurrencyCodeLevel3[1];
      unsigned char scaleFactor;
      unsigned char decimalPlaces;
      unsigned char applicationMaximumResponseTime;   //Maximum response time in seconds needed to respond to VMC. Page 12.
      unsigned char miscellaneousOptions : 4;       //Page 12.
    //Setup.maxMinPrices Page 61
    unsigned char maximumPrice[3];
    unsigned char minimumPrice[3];
    unsigned char vmcCurrencyCode[1];         //Page 61
  //POLL VARIABLES
    //Poll.readerConfigInfo is made up from vallues previously mentioned.
    //Poll.displayRequest Page 63
    unsigned char displayTime;
    char displayData[29];
    //Poll.beginSession Page64-67
    unsigned char fundsAvailable[3];
    unsigned char paymentMediaID[3];
    unsigned char paymentType;
    unsigned char paymentData[1];
    unsigned char userLanguage[1];
    unsigned char userCurrencyCode[1];
    unsigned char cardOptions;
    //Poll.sessionCancelRequest Page 67
    //Poll.vendApproved or denied, or endSession or cancelled. Page 67-68
    //Poll.peripheralID Page 68-69
    unsigned char readerManufacturerCode[2];
    unsigned char readerSerialNumber[11];
    unsigned char vmcSerialNumber[11];
    unsigned char readerModelNumber[11];
    //Poll.commandOutOfSequence Page 71
    unsigned char state : 3;
    //Poll.revalueDenied or Approved or limitAmount.  Page 71-73
    unsigned char revalueLimitAmount[3];
    //Poll.userFileData Page 73 OBSOLETE
    unsigned char numberOfUserFile;
    unsigned char lengthOfUserFile;
    //Poll.timeDateRequest Page 73
    //Poll.dataEntryRequest Page 74
    unsigned char dataEntryLengthAndRepeatBit;
    //Poll.FTLStuff or diagnostic response Page 75-77
  //VEND VALUES
    //Vend.vendRequest Page 77, vendRequest 78-79
    unsigned char itemPrice[1];
    unsigned char itemNumber[1];
    //Vend.vendApproved Page 78-79
    unsigned char vendAmount[3];
    //Vend.vendDenied Page 78
    //Vend.cashSale Page 82-83
    unsigned char itemCurrency[1];
    //Vend.negativeVendRequest Page 83
    unsigned char itemValu[1];
  //READER VALUES
    //Reader.dataEntryResponse Page 89-90
    unsigned char dataEntryData[7];
  //EXPANSION VALUES
    //Expansion.requestID Page93 and so on;
    unsigned char readerSoftwareVersion[1];
    unsigned char vmcManufacturerCode[2];
    unsigned char vmcModelNumber[11];
    unsigned char vmcSoftwareVersion[1];
    unsigned char vmcOptionalFeatureBits[3];
    struct optionalFeatureBits {
      unsigned char alternativePayoutMethod : 1;
      unsigned char extendedDiagnosticCommand : 1;
      unsigned char controlledManualFillPayoutCommands : 1;
      unsigned char ftl : 1;
      //28 more options reserved for future use
    } optionalFeatureBitsEnabled;
    //Expansion.writeTimeDateFile
    unsigned char timeDateYears;
    unsigned char timeDateMonths;
    unsigned char timeDateDays;
    unsigned char timeDateHours;
    unsigned char timeDateMinutes;
    unsigned char timeDateSeconds;
    unsigned char timeDateDayOfWeek;
    unsigned char timeDateWeekNumber;
    unsigned char timeDateSummertime;
    unsigned char timeDateHoliday;

//?
    unsigned char ftlDestinationAddress;
    unsigned char ftlFileID;
    unsigned char ftlMaximumLength;
    unsigned char ftlControl;
    unsigned char ftlRetryDeny;
    unsigned char destinationAddress;
    unsigned char blockNumber;
    unsigned char ftlData;
    unsigned char fileID;
    unsigned char control;
    unsigned char maximumLength;

//FLAGS.  If MDB were a kernel, these would be the shell commands.  Setting a flag will get the action done at the appropriate time.
  unsigned char displayRequestFlag : 1;               //Flag for when you have info to display on the vending screen.
    unsigned char displayDataPointer : 5;           //Makes calculating the message length bytes easier.
  unsigned char beginSessionFlag : 1;                 //Flag for when you want to begin a session with the VMC.  Page 15.
    unsigned char beginSessionReadyFlag : 1;            //After setting the begin session flag, a function loads up the necessary data, and sets this once done.  The pOLL function checks for this flag.
  unsigned char sessionCancelRequestFlag : 1;         //Flag to set if you want to cancel an active session.
  unsigned char errorCodeFlag;                        //Flag for when there is an error code to report.
  unsigned char commandOutOfSequenceFlag : 1;
  unsigned char justResetFlag : 1;
  unsigned char vendApprovedFlag : 1;
  unsigned char vendDeniedFlag : 1;
  unsigned char cancelledFlag : 1;
  unsigned char endSessionFlag : 1;
  unsigned char peripheralIDFlag: 1;
  unsigned char malfunctionErrorFlag : 1;
  unsigned char revalueDeniedFlag : 1;
  unsigned char revalueApprovedFlag : 1;
  unsigned char revalueLimitAmountFlag : 1;
  unsigned char timeDateRequestFlag : 1;
  unsigned char dataEntryRequestFlag : 1;
  unsigned char dataEntryCancelFlag : 1;
  unsigned char reqToRcvFlag : 1;
  unsigned char reqToSendFlag : 1;
  unsigned char retryDenyFlag : 1;
  unsigned char sendBlockFlag : 1;
  unsigned char okToSendFlag : 1;
  unsigned char configDataFlag : 1;
  unsigned char diagnosticResponseFlag : 1;
  unsigned char isActiveFlag : 1;       //Flag set when device has been addressed, and reset when the VMC is done addressing the peripheral.
  unsigned char isBusyFlag : 1;         //Flag set when device is busy doing something such as dispensing a coin, or connecting to a web service.
  unsigned char isOutgoingFlag : 1;     //Flag set when device has information to send in response to the next poll (excluding ACKnowledge).
  unsigned char isOnlineFlag : 1;       //Flag set when device is online, reset when device is offline, meaning ignore all MDB activity.
  unsigned char isResettingFlag : 1;    //Flag set when device recieves a reset command, and un-set when peripheral's reset completes.
  unsigned char isResetFlag : 1;        //Flag set when device has been reset, but hasn't transmitted the 'JUST RESET' response yet.
};                                    //Variables

int startCashless (int n);        //Input number of cashless device you wish to start.

//To get the code to compile I have to declare them manually
CashlessPaymentDevice cashless1, cashless2;


void resetPeripheral(int n);

int beginSession(String data);

int sessionCancelRequest(String data);

int vendApproved(String data);

int vendDenied(String data);

int displayRequest(String data);

int displayCancel(String data);


void rESET(int n);

void pOLL(int n);

void sETUP(int n);

void VEND(int n);

void rEADER(int n);

void rEVALUE(int n);

void nEGATIVEVEND(int n);

void eXPANSION(int n);
/*
//Cashless1 is meant for card based deives. I.E. a credit card.
void startCashless(char n) {
    //For Setup - Config Data.
    cashless.readerFeatureLevel = 0x03;
    cashless.countryCurrencyCode[0] = 0x00;
    cashless.countryCurrencyCode[1] = 0x01;         //Telephone code for usa.
    cashless.countryCurrencyCodeLevel3[0] = 0x18;
    cashless.countryCurrencyCodeLevel3[1] = 0x40;   //Level 3 code for USA
    cashless.scaleFactor = 0x01;  //Pennies
    cashless.decimalPlaces = 0x02;  //Murica.
    cashless.applicationMaximumResponseTime = 0x00; //Default.
    cashless.miscellaneousOptions = 0x01;  //Bit descriptions (n/a) (n/a) (n/a) (n/a) (refunds) (multivend-capability) (hasDisplay) (Vend/Cash tracking)
    //For Expansion - PeripheralID.
    cashless.optionalFeatureBits[0] = 0x00;  //Not used
    cashless.optionalFeatureBits[1] = 0x00;  //Not used
    cashless.optionalFeatureBits[2] = 0x00;  //Not used
    cashless.optionalFeatureBits[3] = 0x04;  //Bit descriptions (n/a) (n/a) (Always Idle) (Data Entry) (Negative Vend) (Multi-Currency/Lingual Support) (16 or 32 bit Monetary Format) (FTL Supported)
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
//Cashless2 is meant for mobile phone based devices.
void cashless2Settings() {
    cashless2.address = cashless.card2;
    //For Setup - Config Data.
    cashless2.readerFeatureLevel = 0x03;
    cashless2.countryCurrencyCode[0] = 0x00;
    cashless2.countryCurrencyCode[1] = 0x01;         //Telephone code for usa.
    cashless2.countryCurrencyCodeLevel3[0] = 0x18;
    cashless2.countryCurrencyCodeLevel3[1] = 0x40;   //Level 3 code for USA
    cashless2.scaleFactor = 0x01;  //Pennies
    cashless2.decimalPlaces = 0x02;  //Murica.
    cashless2.applicationMaximumResponseTime = 0x00; //Default.
    cashless2.miscellaneousOptions = 0x01;  //Bit descriptions (n/a) (n/a) (n/a) (n/a) (refunds) (multivend-capability) (hasDisplay) (Vend/Cash tracking)
    //For Expansion - PeripheralID.
    cashless2.optionalFeatureBits[0] = 0x00;  //Not used
    cashless2.optionalFeatureBits[1] = 0x00;  //Not used
    cashless2.optionalFeatureBits[2] = 0x00;  //Not used
    cashless2.optionalFeatureBits[3] = 0x04;  //Bit descriptions (n/a) (n/a) (Always Idle) (Data Entry) (Negative Vend) (Multi-Currency/Lingual Support) (16 or 32 bit Monetary Format) (FTL Supported)
    cashless2.readerSerialNumber[0] = 0x00;
    cashless2.readerSerialNumber[1] = 0x00;
    cashless2.readerSerialNumber[2] = 0x00;
    cashless2.readerSerialNumber[3] = 0x00;
    cashless2.readerSerialNumber[4] = 0x00;
    cashless2.readerSerialNumber[5] = 0x00;
    cashless2.readerSerialNumber[6] = 0x00;
    cashless2.readerSerialNumber[7] = 0x00;
    cashless2.readerSerialNumber[8] = 0x00;
    cashless2.readerSerialNumber[9] = 0x00;
    cashless2.readerSerialNumber[10] = 0x00;
    cashless2.readerSerialNumber[11] = 0x00;  //Your very own serial number.
    cashless2.readerModelNumber[0] = 0x00;
    cashless2.readerModelNumber[1] = 0x00;
    cashless2.readerModelNumber[2] = 0x00;
    cashless2.readerModelNumber[3] = 0x00;
    cashless2.readerModelNumber[4] = 0x00;
    cashless2.readerModelNumber[5] = 0x00;
    cashless2.readerModelNumber[6] = 0x00;
    cashless2.readerModelNumber[7] = 0x00;
    cashless2.readerModelNumber[8] = 0x00;
    cashless2.readerModelNumber[9] = 0x00;
    cashless2.readerModelNumber[10] = 0x00;
    cashless2.readerModelNumber[11] = 0x00;  //Your very own model number.
    //For display request
    cashless2.displayTime = 0xaa;            //Time unit is 0.1 seconds.
    cashless2.displayData[0] = 0x01;         //The product of these two must equal the lenght of the message.
    cashless2.displayData[1] = 0x0a;         //The product of these two must equal the length of the message.
    cashless2.displayData[2] = 0x4b;
    cashless2.displayData[3] = 0x49;         //ASCII characters. 4b 49 4c 4c 48 55 4d 41 4e 53
    cashless2.displayData[4] = 0x4c;         //                  K  I  L  L  H  U  M  A  N  S
    cashless2.displayData[5] = 0x4c;
    cashless2.displayData[6] = 0x48;
    cashless2.displayData[7] = 0x55;
    cashless2.displayData[8] = 0x4d;
    cashless2.displayData[9] = 0x41;
    cashless2.displayData[10] = 0x4e;
    cashless2.displayData[11] = 0x53;
    cashless2.displayData[31] = 0xff;
    //For Begin Session
    cashless2.fundsAvailable[0] = 0xff;          //Scaled, set to 0xffff if unknown.
    cashless2.fundsAvailable[1] = 0xfe;
        cashless2.paymentMediaID[0] = 0xff;      //Set to 0xffffffff if unknown.
        cashless2.paymentMediaID[1] = 0xff;
        cashless2.paymentMediaID[2] = 0xff;
        cashless2.paymentMediaID[3] = 0xff;
        cashless2.paymentType = 0x40;            //Test Vend.
        cashless2.paymentData[0] = 0x00;
        cashless2.paymentData[1] = 0x00;
            cashless2.userLanguage[0] = 0x00;
            cashless2.userLanguage[1] = 0x00;
            cashless2.userCurrencyCode[0] = 0x00;
            cashless2.userCurrencyCode[1] = 0x00;
            cashless2.cardOptions = 0x00;
}


/*
Options
Devices used
cashless1.readerFeatureLevel = 0x03;          //Set to 1, 2, or 3.  Page59.
cashless1.countryCurrencyCode[0] = 0x00;
cashless1.countryCurrencyCode[1] = 0x01;      //Telephone Code.  Page59
cashless1.countryCurrencyCodeLevel3[0] = 0x18;
cashless1.countryCurrencyCodeLevel3[1] = 0x40;       //ISO4217 codes.  Page59-60, Appendix-A1 on Page
cashless1.scaleFactor = 0x05;
cashless1.decimalPlaces = 0x02;
cashless1.applicationMaximumResponseTime = 0x01;    //Page 60, in seconds.
cashless1.miscellaneousOptions = (
0x00
|| 0x01       //Comment out this line if refunds are unsupported.
|| 0x02       //Comment out this line if multivend is unsupported.
|| 0x04       //Comment out this line if cashless device has no display.
|| 0x08       //Comment out this line if uninterested in CashSale reporting.
);              //Page 60.  XXXXABCD
*/

/*
Power
Change money/time/feature-level/response-time/Options
Request to display message
Get selection, approve/deny vend, negative vend,
Data Entry

*/

int cashlessMain(int n);                        //Page 49-50, Section 7.2
