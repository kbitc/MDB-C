#include "Communication_Format.cpp"

//7.2.1

extern typedef struct cashlessType {
  union {
    unsigned char inactive = 0x1;
    unsigned char disabled = 0x2;
    unsigned char enabled = 0x03;
    unsigned char sessionIdle = 0x04;
    unsigned char vend = 0x05;
    unsigned char revalue = 0x06;
    unsigned char negativeVend = 0x07;
  } state;                            //Device state labels.
//Command Identification & Bitmasks
  struct {
		unsigned char command = 0x0;
	} reset;                                  //Page57
	struct {
		unsigned char command = 0x1;
		struct {
			unsigned char command = 0x00;
			struct {
				unsigned char readerConfigData = 0x01;
			} response;
		} configData;			//Config Data subcommand & response. Page 10-12.
		struct {				//Maintains consistent formatting.
			unsigned char command = 0x01;    //Min/Max Prices subcommand. Page 12.
		} maxMinPrices;
	} setup;                             //Page 58-61
	struct {
		unsigned char command = 0x2;
		struct {
			unsigned char justReset = 0x00;
			unsigned char readerConfigInfo = 0x01;
			unsigned char displayRequest = 0x02;
			unsigned char beginSession = 0x03;
			unsigned char sessionCancelRequest = 0x04;
			unsigned char vendApproved = 0x05;
			unsigned char vendDenied = 0x06;
			unsigned char endSession = 0x07;
			unsigned char cancelled = 0x08;
			unsigned char peripheralID = 0x09;
			unsigned char malfunctionError = 0x0a;
			unsigned char commandOutOfSequence = 0x0b;
			unsigned char diagnosticResponse = 0xff;
			unsigned char revalueApproved = 0x0d;
			unsigned char revalueDenied = 0x0e;
			unsigned char revalueLimitAmount = 0x0f;
			unsigned char userFileData = 0x10;
			unsigned char timeDateRequest = 0x11;
			unsigned char dataEntryRequest = 0x12;
			unsigned char dataEntryCancel = 0x13;
			unsigned char oneAH = 0x14;
			unsigned char reqToRcv = 0x1b;
			unsigned char retryDeny = 0x1c;
			unsigned char sendBlock = 0x1d;
			unsigned char okToSend = 0x1e;
			unsigned char reqToSend = 0x1f;
			unsigned char feh = 0x20;
		} response;                             //Page 62
	} poll;                              //Page 63-77
	struct {
		unsigned char command = 0x3;
		struct {
			unsigned char command  = 0x00;
			struct {
				unsigned char vendApproved = 0x05;
				unsigned char vendDenied = 0x06;
			} response;
		} vendRequest;
		struct {
			unsigned char command = 0x01;
			struct {
				unsigned char vendDenied = 0x06;
			} response;
		} vendCancel;
		struct {
			unsigned char command = 0x02;
		} vendSuccess;
		struct {
			unsigned char command = 0x03;
		} vendFailure;
	    struct {
			unsigned char command = 0x04;
			struct {
				unsigned char endSession = 0x07;
			} response;
		} sessionComplete;
		struct {
			unsigned char command = 0x05;
		} cashSale;
		struct {
				unsigned char command = 0x06;
				struct {
					unsigned char vendApproved = 0x05;
					unsigned char vendDenied = 0x06;
				} response;
			} negativeVendRequest;
	} vend;                              //Page 77-81
	struct {
		unsigned char command = 0x04;
		struct {
			unsigned char command = 0x00;
		} readerDisable;
		struct {
			unsigned char command = 0x01;
		} readerEnable;
		struct {
			unsigned char  command = 0x02;
			struct {
				unsigned char cancelled = 0x08;
			} responese;
		} readerCancel;
		struct {
				unsigned char command = 0x03;
			} dataEntryResponse;
	} reader;                            //Page 81-90
	struct {
		unsigned char command = 0x05;
		struct {
			unsigned char command = 0x00;
			struct {
				unsigned char revalueApproved = 0x0d;
				unsigned char revalueDenied = 0x0e;
			} response;
		} revalueRequest;
		struct {
			unsigned char command = 0x01;
			struct {
				unsigned char revalueLimitAmount = 0x0f;
				unsigned char revalueDenied = 0x0e;
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
} cashless;                            //Constants


struct CashlessPaymentDevice{
  String deviceID, readerID, sessionID, sessionID2, money, command;
  unsigned char address;                    //Page 49, this is a bitmask to identify between cashless1 and cashless2.
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

//FLAGS.  If MDB were a kernel, these would be the shell commands.  Setting a flag will get the action done at the appropriate time.
  unsigned char displayRequest : 1;               //Flag for when you have info to display on the vending screen.
	unsigned char displayDataPointer : 5;           //Makes calculating the message length bytes easier.
	unsigned char beginSession : 1;                 //Flag for when you want to begin a session with the VMC.  Page 15.
	unsigned char sessionCancelRequest : 1;         //Flag to set if you want to cancel an active session.
  unsigned char errorCode;                        //Flag for when there is an error code to report.
  unsigned char commandOutOfSequence : 1;
  unsigned char justReset : 1;
  unsigned char vendApproved : 1;
  unsigned char vendDenied : 1;
  unsigned char cancelled : 1;
  unsigned char endSession : 1;
  unsigned char peripheralID: 1;
  unsigned char malfunctionError : 1;
  unsigned char revalueDenied : 1;
  unsigned char revalueApproved : 1;
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

char startCashless(int n){
  if (n == '1') {
  CashlessPaymentDevice cashless1;
  cashless1.address = 0x10;
  cashless1.state = cashless.state.inactive;
  }
  if (n == '2') {
  CashlessPaymentDevice cashless2;
  cashless2.address = 0x60;
  cashless2.state = cashless.state.inactive;
  }
  return 0;
};        //Input number of cashless device you wish to start.


void main() {
  if (cashless1.state == cashless.state.inactive) {
        if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))   //Result 6 means incoming command is addressed to a cashless device.
            RESET(1);
        if ((block[0].command == cashless.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
            SETUP(1);
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            POLL(1);
        if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
    }
  if (cashless1.state == cashless.state.disabled) {
        if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
            READER(1);
        if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
            RESET()1;
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            POLL(1);
        if ((block[0].command == cashless.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
            SETUP(1);
        if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
    }
  if (cashless1.state == cashless.state.enabled) {
        if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
            VEND(1);
        if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
            REVALUE(1);
        if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
            EXPANSION(1);
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            POLL(1);
        if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
            RESET(1);
        if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
        if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
            cashless1.commandOutOfSequence = 0x0;
    }
  if (cashless1.state == cashless.state.sessionIdle) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          VEND(1);
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          REVALUE(1);
      if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
          POLL(1);
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          NEGATIVEVEND(1);
      if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
          RESET(1);
      if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
    }
  if (cashless1.state == cashless.state.vend) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
    }
  if (cashless1.state == cashless.state.revalue) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
    }
  if (cashless1.state == cashless.state.negativeVend) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless1.commandOutOfSequence = 0x0;
    }
  if (cashless2.state == cashless.state.inactive) {
        if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))   //No byte will reach here with result 6 if not for you.  Check the command.
            RESET(2);
        if ((block[0].command == cashless.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
            SETUP(2);
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            POLL(2);
    }
  if (cashless2.state == cashless.state.disabled) {
        if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
            READER(2);
        if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
            RESET(2);
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            POLL(2);
        if ((block[0].command == cashless.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
            SETUP(2);
    }
  if (cashless2.state == cashless.state.enabled) {
        if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
            VEND(2);
        if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
            REVALUE(2);
        if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
            EXPANSION(2);
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            POLL(2);
    }
  if (cashless2.state == cashless.state.sessionIdle) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          VEND(2);
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          REVALUE(2);
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          NEGATIVEVEND(2);
    }
  if (cashless2.state == cashless.state.vend) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
    }
  if (cashless2.state == cashless.state.revalue) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
    }
  if (cashless2.state == cashless.state.negativeVend) {
      if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.negativeVend.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
      if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
          cashless2.commandOutOfSequence = 0x0;
  }
}                                                  //Page 49-50, Section 7.2

void resetPeripheral(int n) {                      //Reset flags and other nonessential values.
  if (n == '1') {
    cashless1.displayRequest = 0x1;                //Flag for when you have info to display on the vending screen.
  	cashless1.beginSession = 0x1;                  //Flag for when you want to begin a session with the VMC.  Page 15.
  	cashless1.sessionCancelRequest = 0x1;          //Flag to set if you want to cancel an active session.
    cashless1.commandOutOfSequence = 0x1;          //Self explanatory flag.
    cashless1.state = cashless.state.inactive;
  };
  if (n == '2') {
    cashless2.displayRequest = 0x1;                //Flag for when you have info to display on the vending screen.
  	cashless2.beginSession = 0x1;                  //Flag for when you want to begin a session with the VMC.  Page 15.
  	cashless2.sessionCancelRequest = 0x1;          //Flag to set if you want to cancel an active session.
    cashless2.commandOutOfSequence = 0x1;          //Self explanatory flag.
    cashless2.state = cashless.state.inactive;
  };
}

int beginSession(String data) {
    clearBlock();
    block[0].part.data = 0xaa;
    block[1].part.data = 0xc0;
    block[2].part.data = 0x55;
    tX(2);
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
    cashless.beginSession = 0x01;
    return 1;
}

int sessionCancelRequest(String data) {
    cashless.sessionCancelRequest = 0x01;
    return 1;
}

int vendApproved(String data) {
    cashless.vendAmount[0] = data.charAt(0);
    cashless.vendAmount[1] = data.charAt(1);
    if (cashless.vmcFeatureLevel == 0x03) {
        cashless.vendAmount[2] = data.charAt(2);
        cashless.vendAmount[3] = data.charAt(3);
    }
    cashless.vendApproved = 0x01;
    return 1;
}

int vendDenied(String data) {
    cashless.vendDenied = 0x01;
    return 1;
}

int displayRequest(String data) {
    return 1;
}

int displayCancel(String data) {
    //cashless.displayCancel = 0x01;
    return 1;
}


void RESET(int n) {
    if (n == '1') {
      cashless1.state = cashless.state.inactive;
    }
    else if (n = '2') {
      cashless2.state = cashless.state.inactive;
    }
    block[0].part.data = ack;           //No response comes from VMC so sending ACK this way is the most efficient.
    tX(0);
    chronoLogic(0);                 //Resettimer for the 200ms or so allowed for resetting.  Chronologic may need to be adjusted to time two devices.
    resetPeripheral(n);
    peripheral1.isActive = 0x1;
    peripheral1.isBusy = 0x1;
    peripheral1.isOnline = 0x1;        //Indicates that the MDB device is accepting commands.
    peripheral1.isResetting = 0x1;     //Indicates that the peripheral is resetting.
    peripheral1.isReset = 0x1;         //Indicates peripheral is done resetting but the VMC doesn't know yet.
    transmission.isUnresponsive = 0x1;
    transmission.isDone = 0x1;
    transmission.isActive = 0x1;      //No current BUS RESET is occuring.
	  cashless1.displayRequest = 0x1;               //Flag for when you have info to display on the vending screen.
	  cashless1.beginSession = 0x1;                 //Flag for when you want to begin a session with the VMC.  Page 15.
	  cashless1.sessionCancelRequest = 0x1;         //Flag to set if you want to cancel an active session.
    cashless.cmdOutOfSequence = 0x1;             //Self explanatory flag.
    cashless.justReset = 0x0;
    counter = 0;
    result = 0;
    pointer = 0;
    clearBlock();                   //Empty/reset the data block.
    while (transmission.isResetting) {
        chronoLogic(1);
    }
}                        //Page 57

void POLL(int n) {
    if (n == '1') {
      if (cashless1.justReset) {            //If the peripheral has finished resetting.
          clearBlock();
          block[0].part.data = cashless.poll.response.justReset;
          tX(1);
          clearBlock();
          cashless1.justReset = 0x1;
      }
      else if (cashless1.displayRequest) {  //If cashless device requests to display on the Vending Machine's screen.
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
          tX(pointer);
          cashless1.displayRequest = 0;
          clearBlock();
          return;
      }          //Requests to display data.
      else if (cashless1.beginSession) {
          cashless1.state = cashless.state.sessionIdle
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
          tX(pointer);
          cashless1.beginSession = 0x1;
      }            //Begins a Vend session.
      else if (cashless1.sessionCancelRequest) {
          clearBlock();
          block[0].part.data = cashless.poll.response.sessionCancelRequest;
          result = tX(1);
          if (block[0].part.data == ack) {
              cashless1.sessionCancelRequest = 0x00;
          }
      }    //Cancels a Vend session.
      else if (cashless1.vendApproved) {
          block[0].whole = cashless.poll.response.vendApproved;
          block[1].whole = cashless1.vendAmount[0];
          block[2].whole = cashless1.vendAmount[1];
          pointer = 3;
          if (cashless1.vmcFeatureLevel == 0x03) {
              block[3].whole = cashless1.vendAmount[2];
              block[4].whole = cashless1.vendAmount[3];
              pointer = 5;
          }
          tX(pointer);
          cashless1.vendApproved = 0x00;
      }            //Approves a vend.
      else if (cashless1.vendDenied) {
          block[0].whole = cashless.poll.response.vendDenied;
          tX(1);
          cashless1.vendDenied = 0;
      }              //Denies a vend.
      else if (cashless1.endSession) {
          block[0].whole = cashless.poll.response.endSession;
          tX(1);
      }              //Indicates the reader has returned to the enabled state, follows Session Cancel.
      else if (cashless1.cancelled) {
          block[0].whole = cashless.poll.response.cancelled;
          tX(1);
          cashless1.cancelled = 0;
      }               //Aborts READER activities which occur in the enabled state.
      else if (cashless1.peripheralID) {
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
              block[30].whole = cashless1.optionalFeatureBits[0];
              block[31].whole = cashless1.optionalFeatureBits[1];
              block[32].whole = cashless1.optionalFeatureBits[2];
              block[33].whole = cashless1.optionalFeatureBits[3];
              pointer = 34;
          }
          tX(pointer);
      }            //Response to cashless.expansion.peripheralID.command
      else if (cashless1.malfunctionError) {
          block[0].whole = cashless.poll.response.malfunctionError;
          block[1].whole = cashless1.errorCode;
          tX(2);
      }        //Reports an error or malfunction to the VMC.
      else if (cashless1.cmdOutOfSequence) {
          block[0].whole = cashless.poll.response.cmdOutOfSequence;
          pointer = 1;
          if ((cashless1.vmcFeatureLevel >= 2) && (cashless1.readerFeatureLevel >= 2)) {
              block[1].whole = cashless1.state;
              pointer = 2;
          }
          tX(pointer);
      }        //Tells the VMC that a command was sent out of sequence.
      else if (cashless1.revalueApproved) {

      }         //     revalue involves putting money back onto a cashless payment source.
      else if (cashless1.revalueDenied) {

      }           //
      else if (cashless1.revalueLimitAmount) {

      }      //
      /*else if (cashless1.userFileData) {
          Do not use, obsolete.
      }          //Obsolete command.*/
      else if (cashless1.timeDateRequest) {
          block[0].whole = cashless.poll.response.timeDateRequest;
          tX(1);
      }         //Request time/date from VMC.
      else if (cashless1.dataEntryRequest) {  //Request input from machine Keypad.
          block[0].whole = cashless.poll.response.dataEntryRequest;
          block[1].whole = cashless1.dataEntryLengthAndRepeatBit;
          tX(2);
      }        //Request input from VMC Keypad.
      else if (cashless1.dataEntryCancel) {
          block[0].whole = cashless.poll.response.dataEntryCancel;
          tX(1);
      }         //Cancel input session.
      else if (cashless1.reqToRcv) {
          block[0].whole = cashless.poll.response.reqToRcv;
          block[1].whole = cashless1.ftlDestinationAddress;
          block[2].whole = cashless1.address;
          block[3].whole = cashless1.ftlFileID;
          block[4].whole = cashless1.ftlMaximumLength;
          block[5].whole = cashless1.ftlControl;
          tX(6);
      }                //File Transport Layer
      else if (cashless1.retryDeny) {
          block[0].whole = cashless.poll.response.retryDeny;
          block[1].whole = cashless1.ftlDestinationAddress;
          block[2].whole = cashless1.address;
          block[3].whole = cashless1.ftlRetryDeny;
          tX(4);
      }               //File Transport Layer
      else if (cashless1.sendBlock) {
          block[0].whole = cashless.poll.response.sendBlock;
          block[1].whole = cashless1.destinationAddress;
          block[2].whole = cashless1.blockNumber;
          block[3].whole = cashless1.ftlData;
          tX(4);
      }               //File Transport Layer
      else if (cashless1.okToSend) {
          block[0].whole = cashless.poll.response.okToSend;
          block[1].whole = cashless1.destinationAddress;
          block[2].whole = cashless1.address;
          tX(3);
      }                //File transport Layer
      else if (cashless1.reqToSend) {
          block[0].whole = cashless.poll.response.reqToSend;
          block[1].whole = cashless1.destinationAddress;
          block[2].whole = cashless1.address;
          block[3].whole = cashless1.fileID;
          block[4].whole = cashless1.maximumLength;
          block[5].whole = cashless1.control;
          tX(6);
      }               //File Transport Layer
      else if (cashless1.diagnosticResponse) {

      }      //
      else if (cashless1.configData) { //CONFIG DATA... I assume this is for compatibility, we don't use this.  Page 14.
          block[0].part.data = cashless.poll.response.readerConfigData;   //Lets the VMC know you are replying to CONFIG-DATA.
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
      tX(9);  //Transmit Setup response block.
      }              //Sends config data.
      else
          Serial1.write(0x100);
      clearBlock();
    };
    else if (n == '2') {
      if (cashless2.justReset) {            //If the peripheral has finished resetting.
          clearBlock();
          block[0].part.data = cashless.poll.response.justReset;
          tX(1);
          clearBlock();
          cashless2.justReset = 0x1;
      }
      else if (cashless2.displayRequest) {  //If cashless device requests to display on the Vending Machine's screen.
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
          tX(pointer);
          cashless2.displayRequest = 0;
          clearBlock();
          return;
      }          //Requests to display data.
      else if (cashless2.beginSession) {
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
          tX(pointer);
          cashless2.beginSession = 0x1;
      }            //Begins a Vend session.
      else if (cashless2.sessionCancelRequest) {
          clearBlock();
          block[0].part.data = cashless.poll.response.sessionCancelRequest;
          result = tX(1);
          if (block[0].part.data == ack) {
              cashless2.sessionCancelRequest = 0x00;
          }
      }    //Cancels a Vend session.
      else if (cashless2.vendApproved) {
          block[0].whole = cashless.poll.response.vendApproved;
          block[1].whole = cashless2.vendAmount[0];
          block[2].whole = cashless2.vendAmount[1];
          pointer = 3;
          if (cashless2.vmcFeatureLevel == 0x03) {
              block[3].whole = cashless2.vendAmount[2];
              block[4].whole = cashless2.vendAmount[3];
              pointer = 5;
          }
          tX(pointer);
          cashless2.vendApproved = 0x00;
      }            //Approves a vend.
      else if (cashless2.vendDenied) {
          block[0].whole = cashless.poll.response.vendDenied;
          tX(1);
          cashless2.vendDenied = 0;
      }              //Denies a vend.
      else if (cashless2.endSession) {
          block[0].whole = cashless.poll.response.endSession;
          tX(1);
      }              //Indicates the reader has returned to the enabled state, follows Session Cancel.
      else if (cashless2.cancelled) {
          block[0].whole = cashless.poll.response.cancelled;
          tX(1);
          cashless2.cancelled = 0;
      }               //Aborts READER activities which occur in the enabled state.
      else if (cashless2.peripheralID) {
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
              block[30].whole = cashless2.optionalFeatureBits[0];
              block[31].whole = cashless2.optionalFeatureBits[1];
              block[32].whole = cashless2.optionalFeatureBits[2];
              block[33].whole = cashless2.optionalFeatureBits[3];
              pointer = 34;
          }
          tX(pointer);
      }            //Response to cashless.expansion.peripheralID.command
      else if (cashless2.malfunctionError) {
          block[0].whole = cashless.poll.response.malfunctionError;
          block[1].whole = cashless2.errorCode;
          tX(2);
      }        //Reports an error or malfunction to the VMC.
      else if (cashless2.cmdOutOfSequence) {
          block[0].whole = cashless.poll.response.cmdOutOfSequence;
          pointer = 1;
          if ((cashless2.vmcFeatureLevel >= 2) && (cashless2.readerFeatureLevel >= 2)) {
              block[1].whole = cashless2.state;
              pointer = 2;
          }
          tX(pointer);
      }        //Tells the VMC that a command was sent out of sequence.
      else if (cashless2.revalueApproved) {

      }         //     revalue involves putting money back onto a cashless payment source.
      else if (cashless2.revalueDenied) {

      }           //
      else if (cashless2.revalueLimitAmount) {

      }      //
      /*else if (cashless2.userFileData) {
          Do not use, obsolete.
      }          //Obsolete command.*/
      else if (cashless2.timeDateRequest) {
          block[0].whole = cashless.poll.response.timeDateRequest;
          tX(1);
      }         //Request time/date from VMC.
      else if (cashless2.dataEntryRequest) {  //Request input from machine Keypad.
          block[0].whole = cashless.poll.response.dataEntryRequest;
          block[1].whole = cashless2.dataEntryLengthAndRepeatBit;
          tX(2);
      }        //Request input from VMC Keypad.
      else if (cashless2.dataEntryCancel) {
          block[0].whole = cashless.poll.response.dataEntryCancel;
          tX(1);
      }         //Cancel input session.
      else if (cashless2.reqToRcv) {
          block[0].whole = cashless.poll.response.reqToRcv;
          block[1].whole = cashless2.ftlDestinationAddress;
          block[2].whole = cashless2.address;
          block[3].whole = cashless2.ftlFileID;
          block[4].whole = cashless2.ftlMaximumLength;
          block[5].whole = cashless2.ftlControl;
          tX(6);
      }                //File Transport Layer
      else if (cashless2.retryDeny) {
          block[0].whole = cashless.poll.response.retryDeny;
          block[1].whole = cashless2.ftlDestinationAddress;
          block[2].whole = cashless2.address;
          block[3].whole = cashless2.ftlRetryDeny;
          tX(4);
      }               //File Transport Layer
      else if (cashless2.sendBlock) {
          block[0].whole = cashless.poll.response.sendBlock;
          block[1].whole = cashless2.destinationAddress;
          block[2].whole = cashless2.blockNumber;
          block[3].whole = cashless2.ftlData;
          tX(4);
      }               //File Transport Layer
      else if (cashless2.okToSend) {
          block[0].whole = cashless.poll.response.okToSend;
          block[1].whole = cashless2.destinationAddress;
          block[2].whole = cashless2.address;
          tX(3);
      }                //File transport Layer
      else if (cashless2.reqToSend) {
          block[0].whole = cashless.poll.response.reqToSend;
          block[1].whole = cashless2.destinationAddress;
          block[2].whole = cashless2.address;
          block[3].whole = cashless2.fileID;
          block[4].whole = cashless2.maximumLength;
          block[5].whole = cashless2.control;
          tX(6);
      }               //File Transport Layer
      else if (cashless2.diagnosticResponse) {

      }      //
      else if (cashless2.configData) { //CONFIG DATA... I assume this is for compatibility, we don't use this.  Page 14.
          block[0].part.data = cashless.poll.response.readerConfigData;   //Lets the VMC know you are replying to CONFIG-DATA.
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
      tX(9);  //Transmit Setup response block.
      }              //Sends config data.
      else
          block[0].part.data = ack;
          tX(0);
      clearBlock();
    };
}

void SETUP(int n) {
  if (n == '1') {
    cashless1.isActive = 0x0;
    if (block[1].part.data == cashless.setup.configData.command) {
    cashless1.vmcFeatureLevel = block[2].part.data;  //Retrieve VMC's supported MDB Level.  Page-10
    cashless1.columnsOnDisplay = block[3].part.data;  //Retrieve display dimensions.   Page-10
    cashless1.rowsOnDisplay = block[4].part.data;  //Retrieve display dimensions.      Page-10
    cashless1.displayType = block[5].part.data;  //0=Seven Segment, 1=ASCII.       Page-10
    clearBlock();
    block[0].part.data = cashless.setup.configData.response.readerConfigData;   //Lets the VMC know you are replying to CONFIG-DATA.
    block[1].part.data = cashless1.readerFeatureLevel;  //Tells VMC device supports Level 3.    Page-10
    block[2].part.data = cashless1.countryCurrencyCode[0];  //First half of US country code.        Page-11
    block[3].part.data = cashless1.countryCurrencyCode[1];  //Second half of US country code.       Page-11
    if ((cashless.vmcFeatureLevel == 0x03) && (cashless.readerFeatureLevel == 0x03)) {  //IF VMC supports Level 3 MDB.       Page-11
        block[2].part.data = cashless1.countryCurrencyCodeLevel3[0];  //THEN use ISO4217 country code.    Page-11
        block[3].part.data = cashless1.countryCurrencyCodeLevel3[1];  //Second half of ISO4217 code.      Page-11
    }
    block[4].part.data = cashless1.scaleFactor;  //Sets the scale factor for the currency.     Page-11
    block[5].part.data = cashless1.decimalPlaces;  //Sets decimal places up for cents.     Page-11
    block[6].part.data = cashless1.applicationMaximumResponseTime;  //Sets maximum response time.      Page-12
    block[7].part.data = cashless1.miscellaneousOptions;  //Sets refunds, multivend, display, and sales reporting.  Page-12
    pointer = 8;
    tX();  //Transmit Setup response block.
    cashless1.isActive = 0;
    return;
    }
    if (block[1].part.data == cashless.setup.maxMinPrices.command) {
        if ((cashless1.state == cashless.state.disabled) && (cashless1.vmcFeatureLevel == 0x03)) {
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
        cashless1.state = cashless.state.disabled;  //Device is now in the Disabled state, awaiting DEVICE-ENABLE.
        return;
    }
  }
  else if (n == '2') {
    cashless2.isActive = 0x0;
    if (block[1].part.data == cashless.setup.configData.command) {
    cashless2.vmcFeatureLevel = block[2].part.data;  //Retrieve VMC's supported MDB Level.  Page-10
    cashless2.columnsOnDisplay = block[3].part.data;  //Retrieve display dimensions.   Page-10
    cashless2.rowsOnDisplay = block[4].part.data;  //Retrieve display dimensions.      Page-10
    cashless2.displayType = block[5].part.data;  //0=Seven Segment, 1=ASCII.       Page-10
    clearBlock();
    block[0].part.data = cashless.setup.configData.response.readerConfigData;   //Lets the VMC know you are replying to CONFIG-DATA.
    block[1].part.data = cashless2.readerFeatureLevel;  //Tells VMC device supports Level 3.    Page-10
    block[2].part.data = cashless2.countryCurrencyCode[0];  //First half of US country code.        Page-11
    block[3].part.data = cashless2.countryCurrencyCode[1];  //Second half of US country code.       Page-11
    if ((cashless.vmcFeatureLevel == 0x03) && (cashless.readerFeatureLevel == 0x03)) {  //IF VMC supports Level 3 MDB.       Page-11
        block[2].part.data = cashless2.countryCurrencyCodeLevel3[0];  //THEN use ISO4217 country code.    Page-11
        block[3].part.data = cashless2.countryCurrencyCodeLevel3[1];  //Second half of ISO4217 code.      Page-11
    }
    block[4].part.data = cashless2.scaleFactor;  //Sets the scale factor for the currency.     Page-11
    block[5].part.data = cashless2.decimalPlaces;  //Sets decimal places up for cents.     Page-11
    block[6].part.data = cashless2.applicationMaximumResponseTime;  //Sets maximum response time.      Page-12
    block[7].part.data = cashless2.miscellaneousOptions;  //Sets refunds, multivend, display, and sales reporting.  Page-12
    pointer = 8;
    tX();  //Transmit Setup response block.
    cashless2.isActive = 0;
    return;
    }
    if (block[1].part.data == cashless.setup.maxMinPrices.command) {
        if ((cashless2.state == cashless.state.disabled) && (cashless2.vmcFeatureLevel == 0x03)) {
        cashless2.maximumPrice[0] = block[2].part.data;  //Scaled maximum price.                Page-12
        cashless2.maximumPrice[1] = block[3].part.data;  //Second half of max price.            Page-12
        cashless2.maximumPrice[2] = block[4].part.data;  //Scaled minimum price.                Page-12
        cashless2.maximumPrice[3] = block[5].part.data;  //Second half of min price.            Page-12
        cashless2.minimumPrice[0] = block[6].part.data;  //Scaled maximum price.                Page-12
        cashless2.minimumPrice[1] = block[7].part.data;  //Second half of max price.            Page-12
        cashless2.minimumPrice[2] = block[8].part.data;  //Scaled minimum price.                Page-12
        cashless2.minimumPrice[3] = block[9].part.data;  //Second half of min price.            Page-12
        cashless2.countryCurrencyCode[0] = block[10].part.data;
        cashless2.countryCurrencyCode[1] = block[11].part.data;
        }
        else {
        cashless2.maximumPrice[0] = block[2].part.data;  //Scaled maximum price.                Page-12
        cashless2.maximumPrice[1] = block[3].part.data;  //Second half of max price.            Page-12
        cashless2.minimumPrice[0] = block[4].part.data;  //Scaled minimum price.                Page-12
        cashless2.minimumPrice[1] = block[5].part.data;  //Second half of min price.            Page-12
        }
        clearBlock();
        Serial1.write(0x100);
        cashless2.state = cashless.state.disabled;  //Device is now in the Disabled state, awaiting DEVICE-ENABLE.
        return;
    }
  }
}                                           //Pages 10-13

void VEND(int n) {
  if (n == '1') {
    cashless
    if (block[1].part.data == cashless.vend.vendRequest.command) {
        cashless1.itemPrice[0] = block[2].part.data;
        cashless1.itemPrice[1] = block[3].part.data;
        cashless1.itemNumber[0] = block[4].part.data;
        cashless1.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ack;
        tX(0);
    }
    if (block[1].part.data == cashless.vend.vendCancel.command) {
        block[0].whole = cashless.vend.vendCancel.response.vendDenied;
        tX(1);
    }
    if (block[1].part.data == cashless.vend.vendSuccess.command) {
        cashless1.itemNumber[0] = block[2].part.data;
        cashless1.itemNumber[1] = block[3].part.data;
        clearBlock();
        block[0].part.data = ack;
        tX(0);
    }
    if (block[1].part.data == cashless.vend.vendFailure.command) {
        return;
    }
    if (block[1].part.data == cashless.vend.sessionComplete.command) {
        clearBlock();
        block[0].part.data = cashless.vend.sessionComplete.response.endSession;
        pointer = 1;
        tX();
        cashless1.state = cashless.state.enabled;
    }
    if (block[1].part.data == cashless.vend.cashSale.command) {
        cashless.itemPrice[0] = block[2].part.data;
        cashless.itemPrice[1] = block[3].part.data;
        cashless.itemNumber[0] = block[4].part.data;
        cashless.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ack;
        tX(0);
    }
  }
  else if (n == '2') {
    if (block[1].part.data == cashless.vend.vendRequest.command) {
        cashless2.itemPrice[0] = block[2].part.data;
        cashless2.itemPrice[1] = block[3].part.data;
        cashless2.itemNumber[0] = block[4].part.data;
        cashless2.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
    }
    if (block[1].part.data == cashless.vend.vendCancel.command) {
        block[0].whole = cashless.vend.vendCancel.response.vendDenied;
        pointer = 1;
        tX();
    }
    if (block[1].part.data == cashless.vend.vendSuccess.command) {
        cashless2.itemNumber[0] = block[2].part.data;
        cashless2.itemNumber[1] = block[3].part.data;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
    }
    if (block[1].part.data == cashless.vend.vendFailure.command) {
        return;
    }
    if (block[1].part.data == cashless.vend.sessionComplete.command) {
        clearBlock();
        block[0].part.data = cashless.vend.sessionComplete.response.endSession;
        pointer = 1;
        tX();
        cashless2.state = cashless.state.enabled;
    }
    if (block[1].part.data == cashless.vend.cashSale.command) {
        cashless.itemPrice[0] = block[2].part.data;
        cashless.itemPrice[1] = block[3].part.data;
        cashless.itemNumber[0] = block[4].part.data;
        cashless.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
    }
  }
}

void READER(int n) {
  if (n == '1') {
    if (block[1].part.data == cashless.reader.readerEnable.command) {
        cashless1.state = cashless.state.enabled;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
    }
    if (block[1].part.data == cashless.reader.readerDisable.command) {
        cashless1.state = cashless.state.disabled;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
    }
  }
  else if (n == '2') {
    if (block[1].part.data == cashless.reader.readerEnable.command) {
        cashless2.state = cashless.state.enabled;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
  }
    if (block[1].part.data == cashless.reader.readerDisable.command) {
      cashless2.state = cashless.state.disabled;
      clearBlock();
      block[0].part.data = ack;
      pointer = 0;
  }
}
}

void REVALUE(int n) {

}

void NEGATIVEVEND(int n) {

}

void EXPANSION(int n) {
  if (n == '1') {
    if (block[1].part.data == cashless.expansion.requestID.command) {
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
        if (cashless.vmcFeatureLevel == 0x03) {
            block[34].part.data = cashless.optionalFeatureBits[0];
            block[34].part.data = cashless.optionalFeatureBits[1];
            block[34].part.data = cashless.optionalFeatureBits[2];
            block[34].part.data = cashless.optionalFeatureBits[3];
            pointer = 35;
        }
        tX();                                   ////I just now remembered loops exist.
    }
    if (block[1].part.data == cashless.expansion.readUserFile.command) {
        clearBlock();
        block[0].part.data = cashless.expansion.readUserFile.response.userFileData;  //Currently unsupported and not forseen to be needed.
        pointer = 1;
        tX();
    }
    if (block[1].part.data == cashless.expansion.writeUserFile.command) {
        clearBlock();                       //Obsolete command, not seen as necessary to add.
        block[0].part.data = ack;
        tX();
    }
    if (block[1].part.data == cashless.expansion.writeTimeDate.command) {
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
        block[0].part.data = ack;
        pointer = 0;
    }
    if (block[1].part.data == cashless.expansion.optionalFeatureEnabled.command) {
        cashless.optionalFeatureBitsEnabled.whole = block[5].part.data;
        block[0].part.data = ack;
        pointer = 0;
        tX();
    }
  }
  else if (n == '2') {
    if (block[1].part.data == cashless.expansion.requestID.command) {
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
        if (cashless.vmcFeatureLevel == 0x03) {
            block[34].part.data = cashless.optionalFeatureBits[0];
            block[34].part.data = cashless.optionalFeatureBits[1];
            block[34].part.data = cashless.optionalFeatureBits[2];
            block[34].part.data = cashless.optionalFeatureBits[3];
            pointer = 35;
        }
        tX();                                   ////I just now remembered loops exist.
    }
    if (block[1].part.data == cashless.expansion.readUserFile.command) {
        clearBlock();
        block[0].part.data = cashless.expansion.readUserFile.response.userFileData;  //Currently unsupported and not forseen to be needed.
        pointer = 1;
        tX();
    }
    if (block[1].part.data == cashless.expansion.writeUserFile.command) {
        clearBlock();                       //Obsolete command, not seen as necessary to add.
        block[0].part.data = ack;
        tX();
    }
    if (block[1].part.data == cashless.expansion.writeTimeDate.command) {
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
        block[0].part.data = ack;
        pointer = 0;
    }
    if (block[1].part.data == cashless.expansion.optionalFeatureEnabled.command) {
        cashless.optionalFeatureBitsEnabled.whole = block[5].part.data;
        block[0].part.data = ack;
        pointer = 0;
        tX();
    }
  }
}








































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
