struct {
    String deviceID, readerID, sessionID, sessionID2, money, command;
	unsigned char card1 = 0x10;                     //Address for card based devices, cashless device #1.
	unsigned char mobile2 = 0x60;                   //Address for mobile phone based devices, cashless device #2.
	unsigned char state : 3;						//Page 1 lists 7 device states.  Device state will be stored by numbers corresponding to that list.
	    unsigned char stateInactive = 0x1;
	    unsigned char stateDisabled = 0x2;
	    unsigned char stateEnabled = 0x03;
	    unsigned char stateSessionIdle = 0x04;
	    unsigned char stateVend = 0x05;
	    unsigned char stateRevalue = 0x06;
	    unsigned char stateNegativeVend = 0x07;
	unsigned char rowsOnDisplay;					//Used to store the amount of rows available for text to display on.
	unsigned char columnsOnDisplay;					//Used to store the amount of columns available for text to display on.
	unsigned char displayType : 3;					//Used to store the format used on the machine's display.
	unsigned char minimumPrice[3];						//Minimum price of product in the machine.
	unsigned char maximumPrice[3];						//Maximum price of product in the machine.
	unsigned char vmcFeatureLevel : 2;				//Feature level of the VMC.
	unsigned char readerFeatureLevel : 2;			//Feature level of Cashless device (should be 3).
	unsigned char countryCurrencyCode[1];				//Page 11.
	unsigned char countryCurrencyCodeLevel3[1];
	unsigned char scaleFactor;						//All currency values accepted are a multiple of this number (5 in the usa). Page 11.
	unsigned char decimalPlaces;					//Digits to the right of a decimal place. Page 11.
	unsigned char applicationMaximumResponseTime;   //Maximum response time in seconds needed to respond to VMC. Page 12.
	unsigned char miscellaneousOptions : 4;      	//Page 12.
	unsigned char readerManufacturerCode[2];              //ASCII
	unsigned char vmcManufacturerCode[2];
	unsigned char readerSerialNumber[11];
	unsigned char vmcSerialNumber[11];
	unsigned char readerModelNumber[11];
	unsigned char vmcModelNumber[11];
	unsigned char readerSoftwareVersion[1];
	unsigned char optionalFeatureBits[3];
	unsigned char vmcSoftwareVersion[1];
	unsigned char displayRequest : 1;               //Flag for when you have info to display on the vending screen.
	unsigned char displayTime;                      //Number of tenths of a second desired for message to be displayed.
	char displayData[29];                           //ASCII message to be displayed.  Up to 30 characters.
	unsigned char displayDataPointer : 5;           //Makes calculating the message length bytes easier.
	unsigned char beginSession : 1;                 //Flag for when you want to begin a session with the VMC.  Page 15.
	unsigned char fundsAvailable[3];                //Currency Available for spending. Page 15.
	unsigned char paymentMediaID[3];                //Page 15.
	unsigned char paymentType;                      //Page 15.
	unsigned char paymentData[1];                   //Page 15-16.
	unsigned char userLanguage[1];                  //Page 17.
	unsigned char userCurrencyCode[1];              //Page 17.
	unsigned char cardOptions;                      //Page 17.
	unsigned char sessionCancelRequest : 1;         //Flag to set if you want to cancel an active session.
    unsigned char errorCode;
    unsigned char cmdOutOfSequence : 1;             //Self explanatory flag.
    unsigned char justReset : 1;
    unsigned char vendApproved : 1;
    unsigned char vendAmount[3];
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
    unsigned char dataEntryLengthAndRepeatBit;
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
    unsigned char itemNumber[1];
    unsigned char itemPrice[1];
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
    union {
        struct {
        //Bit descriptions (n/a) (n/a) (Always Idle) (Data Entry) (Negative Vend) (Multi-Currency/Lingual Support) (16 or 32 bit Monetary Format) (FTL Supported)
        unsigned char ftlSupport;       //Support of FTL
        unsigned char expandedCurrency;    //Support for expanded currency mode, which uses 32 bit currency format.
        unsigned char multiCurrencyLingual;   //Support for multiple currencies and languages.
        unsigned char negativeVend;         //Support for negative vend mode.
        unsigned char dataEntry;        //Support for data entry.
        unsigned char alwaysIdle;       //Support for the always idle option.
        } option;
        unsigned int whole;
    } optionalFeatureBitsEnabled;

	struct {
		unsigned char command = 0x0;
	} reset;				//VMC reset command, later defined based on if you are cashless 1 or 2.  Page 9.
	struct {						//VMC setup command, later defined based on if you are cashless 1 or 2.  Page 10.
		unsigned char command = 0x1;
		struct {
			unsigned char command = 0x00;
			struct {
				unsigned char readerConfigData = 0x01;
			} response;
		} configData;			//Config Data subcommand & response. Page 10-12.
		struct {				//Maintains consistent formatting.
			unsigned char command = 0x01;			//Min/Max Prices subcommand. Page 12.
		} maxMinPrices;
	} setup;
	struct {
		unsigned char command = 0x2;
		struct {
			unsigned char justReset = 0x00;
			unsigned char readerConfigData = 0x01;
			unsigned char displayRequest = 0x02;
			unsigned char beginSession = 0x03;
			unsigned char sessionCancelRequest = 0x04;
			unsigned char vendApproved = 0x05;
			unsigned char vendDenied = 0x06;
			unsigned char endSession = 0x07;
			unsigned char cancelled = 0x08;
			unsigned char peripheralID = 0x09;
			unsigned char malfunctionError = 0x0a;
			unsigned char cmdOutOfSequence = 0x0b;
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
		} response;
	} poll;
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
	} vend;
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
	} reader;
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
	} revalue;
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
	} expansion;
} cashless;

void settings() {
    peripheral.address = cashless.card1;
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
    cashless.displayTime = 0xaa;  //Time unit is 0.1 seconds.
    cashless.displayData[0] = 0x01;  //The product of these two must equal the lenght of the message.
    cashless.displayData[1] = 0x0a;  //The product of these two must equal the length of the message.
    cashless.displayData[2] = 0x4b;
    cashless.displayData[3] = 0x49;  //ASCII characters. 4b 49 4c 4c 48 55 4d 41 4e 53
    cashless.displayData[4] = 0x4c;  //                  K  I  L  L  H  U  M  A  N  S
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



/*    *****Commands values*****
    unsigned char cashless1Address = (0x10);  //Cashless Address for credit card based cashless devices.  Page-1
    unsigned char cashless2Address = (0x60);  //Cashless Address for mobile phone based cashless devices. Page-1
cashless.reset.command = (0x0);      ///////////Page 7-8 for values & mdb level.
cashless.setup.command = (0x1);
	cashless.setup.configData.command = (0x00);
		cashless.setup.configData.response.readerConfigData = (0x01);
	cashless.setup.maxMinPrices.command = (0x01);
cashless.poll.command = (0x2);
		cashless.poll.response.justReset = (0x00);
		cashless.poll.response.readerConfigData = (0x01);
		cashless.poll.response.displayRequest = (0x02);
		cashless.poll.response.beginSession = (0x03);
		cashless.poll.response.sessionCancelRequest = (0x04);
		cashless.poll.response.vendApproved = (0x05);
		cashless.poll.response.vendDenied = (0x06);
		cashless.poll.response.endSession = (0x07);
		cashless.poll.response.cancelled = (0x08);
		cashless.poll.response.peripheralID = (0x09);
		cashless.poll.response.malfunctionError = (0x0A);
		cashless.poll.response.cmdOutOfSequence = (0x0B);
		cashless.poll.response.revalueApproved = (0x0D);
		cashless.poll.response.revalueDenied = (0x0E);
		cashless.poll.response.revalueLimitAmount = (0x0F);
		cashless.poll.response.userFileData = (0x10);
		cashless.poll.response.timeDateRequest = (0x11);
		cashless.poll.response.dataEntryRequest = (0x12);
		cashless.poll.response.dataEntryCancel = (0x13);
		cashless.poll.response.oneAH = (0x14);
		cashless.poll.response.ftl.reqToRcv = (0x1B);
		cashless.poll.response.ftl.retryDeny = (0x1C);
		cashless.poll.response.ftl.sendBlock = (0x1D);
		cashless.poll.response.ftl.okToSend = (0x1E);
		cashless.poll.response.ftl.reqToSend = (0x1F);
		cashless.poll.response.feh = (0x20);
		cashless.poll.response.diagnosticResponse = (0xFF);
cashless.vend.command = (0x3);
	cashless.vendRequest.command = (0x00);
		cashless.vendRequest.response.vendApproved = (0x05);
		cashless.vendRequest.response.vendDenied = (0x06);
	cashless.vendCancel.command = (0x01);
		cashless.vendCancel.response.vendDenied = (0x06);
	cashless.vendSuccess.command = (0x02);
	cashless.vendFailure.command = (0x03);
	cashless.sessionComplete.command = (0x04);
		cashless.sessionComplete.response.endSession = (0x07);
	cashless.cashSale.command = (0x05);
	cashless.negativeVendRequest.command = (0x06);
		cashless.negativeVendRequest.response.vendApproved = (0x05);
		cashless.negativeVendRequest.response.vendDenied = (0x06);
cashless.expansion.command = (0x7); */
