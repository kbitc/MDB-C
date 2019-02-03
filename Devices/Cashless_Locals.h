#ifndef CASHLESS_LOCALS
#define CASHLESS_LOCALS

#include <Arduino.h>
#include "PreProcessors.h"

static uint8_t rxResult;

extern int main();                        //Page 49-50, Section 7.2

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
  uint8_t coinReturn : 1;         /*Coin Mech Escrow/Return button pushed.*/
};                                   //Variables

#endif
