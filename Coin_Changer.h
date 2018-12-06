#include "Communication_Format.cpp"

struct {
  union {
    unsigned char Inactive = 0x1;
    unsigned char Disabled = 0x2;
    unsigned char Enabled = 0x03;
    unsigned char SessionIdle = 0x04;
    unsigned char Vend = 0x05;
    unsigned char Revalue = 0x06;
    unsigned char NegativeVend = 0x07;
  } status;                            //Device status labels.
//Command Identification & Bitmasks
  struct {
		unsigned char command = 0x08;
	} reset;                                  //Page
	struct {
		unsigned char command = 0x09;
	} setup;                             //Page 12-14
	struct {
		unsigned char command = 0x0b;
	} poll;                              //Page 15-18
	struct {
    unsigned char command = 0x0a;
  } tubeStatus;                        //Page 14-15
  struct {
    unsigned char command = 0x0c;
  } coinType;                          //Page 17-18
  struct {
    unsigned int command = 0x0d;
  } dispense;                          //Page 19
	struct {
		unsigned char command = 0x0f;
		struct {
			unsigned char command = 0x00;
			struct {
				unsigned char peripheralID = 0x;
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
} changer;                            //Constants


struct CoinHopper{
  String deviceID, readerID, sessionID, sessionID2, money, command;
  unsigned char address = 0x08;                    //Page 9.
  //SETUP VARIABLES
    //Setup.configurationData Page 58-59
    unsigned char vmcFeatureLevel : 2;
    unsigned char columnsOnDisplay;
    unsigned char rowsOnDisplay;
    unsigned char displayType : 3;					  //PWording selected to avoid confusion.
      //Setup.configurationData.Response Page 59-60
      unsigned char readerFeatureLevel : 2;
      unsigned char countryCurrencyCode[1];			//Page 61.
    	unsigned char countryCurrencyCodeLevel3[1];
    	unsigned char scaleFactor;
    	unsigned char decimalPlaces;
    	unsigned char applicationMaximumResponseTime;   //Maximum response time in seconds needed to respond to VMC. Page 12.
    	unsigned char miscellaneousOptions : 4;      	//Page 12.
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
    //Poll.malfunctionError Page 70-71
    struct {
      unsigned char paymentMedia1 : 4 =0x0f;
      unsigned char invalidPaymentMedia1 : 4 =0x1f;
      unsigned char tamper : 4 =0x2f;
      unsigned char manufacturerDefined2 : 4 =0x3f;
      unsigned char communications2 : 4 =0x4f;
      unsigned char readerRequiresService2 : 4 =0x5f;
      unsigned char unassigned2 : 4 =0x6f;
      unsigned char manufacturerDefined2 : 4 =0x7f;
      unsigned char readerFailure3 : 4 =0x8f;
      unsigned char communications3 : 4 =0x9f;
      unsigned char paymentMediaJammed3 : 4 =0xaf;
      unsigned char manufacturerDefined3 : 4 =0xbf;
      unsigned char refundInternalReaderCreditLost : 4 =0xcf;
    }error;
    //Poll.commandOutOfSequence Page 71
    unsigned char status : 3;
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
    unsigned char optionalFeatureBits[3];
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
    unsigned char vendAmount[3];

//FLAGS
  unsigned char displayRequest : 1;                 //Flag for when you have info to display on the vending screen.
	unsigned char displayDataPointer : 5;           //Makes calculating the message length bytes easier.
	unsigned char beginSession : 1;                 //Flag for when you want to begin a session with the VMC.  Page 15.
	unsigned char sessionCancelRequest : 1;         //Flag to set if you want to cancel an active session.
    unsigned char errorCode;
    unsigned char cmdOutOfSequence : 1;             //Self explanatory flag.
    unsigned char justReset : 1;
    unsigned char vendApproved : 1;
    unsigned char vendDenied : 1;
    unsigned char cancelled : 1;
    unsigned char endSession : 1;
    unsigned char peripheralID: 1;
    unsigned char malfunctionError : 1;
    unsigned char revalueDenied : 1;
    unsigned char revalueApproved : 1;
    unsigned char status : 1;
    unsigned char revalueLimitAmount : 1;
    unsigned char timeDateRequest : 1;
    unsigned char dataEntryRequest : 1;
    unsigned char dataEntryCancel : 1;
    unsigned char reqToRcv : 1;
    unsigned char reqToSend : 1;
    unsigned char retryDeny : 1;
    unsigned char sendBlock : 1;
    unsigned char okToSend : 1;
    unsigned char configData : 1;
    unsigned char diagnosticResponse : 1;
  	unsigned char isActive : 1;       //Flag set when device has been addressed, and reset when the VMC is done addressing the peripheral.
  	unsigned char isBusy : 1;         //Flag set when device is busy doing something such as dispensing a coin, or connecting to a web service.
  	unsigned char isOutgoing : 1;     //Flag set when device has information to send in response to the next poll (excluding ACKnowledge).
  	unsigned char isOnline : 1;       //Flag set when device is online, reset when device is offline, meaning ignore all MDB activity.
  	unsigned char isResetting : 1;    //Flag set when device recieves a reset command, and un-set when peripheral's reset completes.
  	unsigned char isReset : 1;        //Flag set when device has been reset, but hasn't transmitted the 'JUST RESET' response yet.
};                                    //Variables
