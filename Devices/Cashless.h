#ifndef CASHLESS_HEADER
#define CASHLESS_HEADER

#include <Arduino.h>
#include "PreProcessors.h"
#include "Communication_Format.h"

extern uint8_t result;

//extern int tX(unsigned int pointer, uint8_t address);

//7.2.1

struct cashlessConstants {
  uint8_t address;  //Just so it compiles, fix/remove this later.
  union state {
    uint8_t inactive : 1;
    uint8_t disabled : 2;
    uint8_t enabled : 2;
    uint8_t sessionIdle :3 ;
    uint8_t vend : 3;
    uint8_t revalue : 3;
    uint8_t negativeVend : 3;
  } state;                            //Device state labels.
//Command Identification & Bitmasks
  struct reset {
    uint8_t command : 1;
  } reset;                                  //Page57
  struct setup {
    uint8_t command : 1;
    struct configData {
      uint8_t command : 1;
      struct response {
        uint8_t readerConfigData : 1;
      } response;
    } configData;     //Config Data subcommand & response. Page 10-12.
    struct {        //Maintains consistent formatting.
      uint8_t command : 1;    //Min/Max Prices subcommand. Page 12.
    } maxMinPrices;
  } setup;                             //Page 58-61
  struct {
    uint8_t command : 2;
    struct {
      uint8_t justReset : 1;
      uint8_t readerConfigInfo : 1;
      uint8_t displayRequest : 2;
      uint8_t beginSession : 2;
      uint8_t sessionCancelRequest : 3;
      uint8_t vendApproved : 3;
      uint8_t vendDenied : 3;
      uint8_t endSession : 3;
      uint8_t cancelled : 4;
      uint8_t peripheralID : 4;
      uint8_t malfunctionError : 4;
      uint8_t commandOutOfSequence : 4;
      uint8_t diagnosticResponse : 4;
      uint8_t revalueApproved : 4;
      uint8_t revalueDenied : 4;
      uint8_t revalueLimitAmount : 4;
      uint8_t userFileData : 5;
      uint8_t timeDateRequest : 5;
      uint8_t dataEntryRequest : 5;
      uint8_t dataEntryCancel : 5;
      uint8_t oneAH : 5;
      uint8_t reqToRcv : 5;
      uint8_t retryDeny : 5;
      uint8_t sendBlock : 5;
      uint8_t okToSend : 5;
      uint8_t reqToSend : 5;
      uint8_t feh : 6;
    } response;                             //Page 62
  } poll;                              //Page 63-77
  struct {
    uint8_t command : 2;
    struct {
      uint8_t command : 1;
      struct {
        uint8_t vendApproved : 3;
        uint8_t vendDenied : 3;
      } response;
    } vendRequest;
    struct {
      uint8_t command : 1;
      struct {
        uint8_t vendDenied : 3;
      } response;
    } vendCancel;
    struct {
      uint8_t command : 2;
    } vendSuccess;
    struct {
      uint8_t command : 2;
    } vendFailure;
      struct {
      uint8_t command : 3;
      struct {
        uint8_t endSession : 3;
      } response;
    } sessionComplete;
    struct {
      uint8_t command : 3;
    } cashSale;
    struct {
        uint8_t command : 3;
        struct {
          uint8_t vendApproved : 3;
          uint8_t vendDenied : 3;
        } response;
      } negativeVendRequest;
  } vend;                              //Page 77-81
  struct {
    uint8_t command : 3;
    struct {
      uint8_t command : 1;
    } readerDisable;
    struct {
      uint8_t command : 1;
    } readerEnable;
    struct {
      uint8_t  command : 2;
      struct {
        uint8_t cancelled : 4;
      } response;
    } readerCancel;
    struct {
        uint8_t command : 2;
      } dataEntryResponse;
  } reader;                            //Page 81-90
  struct {
    uint8_t command : 3;
    struct {
      uint8_t command : 1;
      struct {
        uint8_t revalueApproved : 4;
        uint8_t revalueDenied : 4;
      } response;
    } revalueRequest;
    struct {
      uint8_t command : 1;
      struct {
        uint8_t revalueLimitAmount : 4;
        uint8_t revalueDenied : 4;
      } response;
    } revalueLimitRequest;
  } revalue;                           //Page 91-93
  struct {
    uint8_t command : 3;
    struct {
      uint8_t command : 1;
      struct {
        uint8_t peripheralID : 5;
      } response;
    } requestID;
    struct {
      uint8_t command : 8;
      struct {
        uint8_t diagnosticResponse : 8;
      } response;
    } diagnostics;
    struct {
      uint8_t command : 1;
      struct {
        uint8_t userFileData : 5;
      } response;
    } readUserFile;
    struct {
      uint8_t command : 2;
    } writeUserFile;
    struct {
      uint8_t command : 2;
    } writeTimeDate;
    struct {
      uint8_t command : 3;
    } optionalFeatureEnabled;
    struct  {
      struct {
        uint8_t command : 8;
        struct {
          uint8_t sendBlock : 5;
          uint8_t retryDeny : 5;
        } response;
      } reqToRcv;
      struct {
      uint8_t command : 8;
      } retryDeny;
      struct {
        uint8_t command : 8;
      } sendBlock;
      struct {
        uint8_t command : 8;
        struct {
          uint8_t sendBlock : 5;
        } response;
      } okToSend;
      struct {
        uint8_t command : 8;
        struct {
          uint8_t okToSend : 5;
          uint8_t retryDeny : 5;
        } response;
      } reqToSend;
    } ftl;
  } expansion;                         //Page 93-100
  struct {                             //Poll.malfunctionError Page 70-71
    uint8_t paymentMedia1 : 4;
    uint8_t invalidPaymentMedia1 : 4;
    uint8_t tamper : 4;
    uint8_t manufacturerDefined1 : 4;
    uint8_t communications2 : 4;
    uint8_t readerRequiresService2 : 4;
    uint8_t unassigned2 : 4;
    uint8_t manufacturerDefined2 : 4;
    uint8_t readerFailure3 : 4;
    uint8_t communications3 : 4;
    uint8_t paymentMediaJammed3 : 4;
    uint8_t manufacturerDefined3 : 4;
    uint8_t refundInternalReaderCreditLost : 4;
  } error;
};                            //Constants

extern struct cashlessConstants cashless;

extern void cashlessSetup();

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
};                                   //Variables

extern struct cashlessVariables cashless1, cashless2;

extern int startCashless (int n);        //Input number of cashless device you wish to start.

extern void resetPeripheral(int n);

extern int beginSession(String data);

extern int sessionCancelRequest(String data);

extern int vendApproved(String data);

extern int vendDenied(String data);

extern int displayRequest(String data);

extern int displayCancel(String data);


extern void rESET(int n);

extern void pOLL(int n);

extern void sETUP(int n);

extern void VEND(int n);

extern void rEADER(int n);

extern void rEVALUE(int n);

extern void nEGATIVEVEND(int n);

extern void eXPANSION(int n);
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

extern int cashlessMain(int n);                        //Page 49-50, Section 7.2

#endif
