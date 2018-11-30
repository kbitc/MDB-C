PRODUCT_ID(1559);
PRODUCT_VERSION(1);

union nineBit {             		  //Union allows accessing all 9 bits as a 'short' data type.  (Two bytes long)
	struct {                    	  //Structurs allows accessing 8 data bits and 1 mode bit separately, as well as reducing boolean values to one bit in size.
		unsigned char data : 8;       //8 data bits dddddddd
		unsigned char mode : 1; 	  //1 mode bit  _______m  
    } part;                 		  //Type this to access as two separate bytes rather than one single short data type.  Example: 'Block[3].part.mode;'  'Block[3].part.data;'
    unsigned short whole;     		  //Type this to access both bytes as a single 'short'.                                Example: 'Block[3].whole;'  (same as the above two examples' results concatenated)
    unsigned char command : 3;        //The three bits containing a command in an address byte.  mdddddccc. 
} block[35];                		  //Array of 9 bit data, 36 is the maximum amount of 'bytes' MDB allows per transmission.

struct peripheral {                   //Structure for status flags related to the peripheral.
	unsigned char address : 8;        //Address of the peripheral.
	unsigned char isActive : 1;       //Flag set when device has been addressed, and reset when the VMC is done addressing the peripheral (for now).
	unsigned char isBusy : 1;         //Flag set when device is busy doing something such as dispensing a coin, or connecting to a web service.
	unsigned char isOutgoing : 1;     //Flag set when device has information to send in response to the next poll (excluding ACKnowledge).
	unsigned char isOnline : 1;       //Flag set when device is online, reset when device is offline, meaning ignore all MDB activity.
	unsigned char isResetting : 1;    //Flag set when device recieves a reset command, and un-set when peripheral's reset completes.
	unsigned char isReset : 1;        //Flag set when device has been reset, but hasn't transmitted the 'JUST RESET' response yet.
} peripheral;                         //Creates an instance of the structure called peripheral.  Example usage, an if condition to check if the device is online   'if(peripheral.isOnline)'.
	
struct {                              //Structure for status/timing flags related to the MDB transmission.
    unsigned char isUnresponsive : 1; //Flag set when transmission completes and non-response time is reached before a response.
    unsigned char isDone : 1;         //Flag set when recieved transmission completes and inter-byte time-out is reached before the next byte, or know end of conversation (poll required before peripheral transmits again).
    unsigned char isResetting : 1;    //Flag set when a 'BUS RESET' is taking place.
	unsigned char isActive : 1;       //Flag set when VMC's TX line goes active, and unset the instant the line goes inactive (used to detect 'BUS RESET').
} transmission;

String stringData;
int counter, result, pointer, microseconds, thirdPin;                 
unsigned char checksum, ack, ret, nak;     
 //counter = A tracker for loops to define an endpoint with.
 //result = A non-volatile temporary storage variable for results of operations to be stored.  When calling a method and using the returned value from it, this makes checking the value more than once possible.
 //pointer = Points to the last byte in a data block to indicate when to stop transmitting or when the last recieved byte occurs within the block.
 //microseconds = Used by the timing method with 'micros()' in order to measure how many microseconds have gone by since the method was last called, rather than how many have gone by since the system started up.
 //thirdPin = The pin name of the GPIO that senses the bus reset.
 //checksum = Calculated checksum for comparison with recieved checksum.
 //ack, ret, nak = Values of described command/value.
 
void serialEvent1();    //9 bit UART data recieved.
void thirdEvent1();     //GPIO detects voltage fall.
void thirdEvent2();     //GPIO detects voltage rise.
int rX();               //Recieves a byte, judges if it needs to recieve the rest of the data, and ends at appropriate time.  Returns status codes.
void clearBlock();      //Clear all communications related variables.
int tX();               //Send the data in the block, calculate and insert check byte into location of pointer, uness pointer is zero.  ALways sets mode bit on last byte.
void chronoLogic(unsigned char command);    //Stopwatch that updates all timing flags.

void serialEvent1() {   								//Possible replacement to RX, hardware calls this when UART recieves data.  Called after current method is finished.
    chronoLogic(0);
    noInterrupts();  									//Disable interrupts from third wire, otherwise it'd interrupt every single bit.
    transmission.isActive = 1;  						//Line might be marked active, since this is a uart frame, it's not a busReset, so make the line inactive.
	result = rX();										//Fetch the rest & pass up the result.
	if (block[counter].part.data != checksum) {
	    result = 0;                                     //0 for failure, checksum doesn't match.
        clearBlock();                                   //Clear the block so corrupt data isn't read.
	}
	if (result == 6) 
    interrupts();   									//Turn interrupts back on, and return to the loop.
}

void thirdEvent1() {     								//Called when voltage rises on RX while not listening for UART.
    detachInterrupt(thirdPin);
    attachInterrupt(thirdPin, thirdEvent2, FALLING);    //Look for voltage drop, call 'thirdEvent2()' when one is detected.
    transmission.isActive = 1;                          //Line active.
    chronoLogic(0);                                     //Reset timer.
}

void thirdEvent2() {    								//Called when voltage drops on RX while not listening for UART.
    detachInterrupt(thirdPin);
    attachInterrupt(thirdPin, thirdEvent1, RISING);     //Look for voltage rise, call 'thirdEvent1()' when one is detected.
    transmission.isActive = 0;                          //Line is inactive.
}

int rX() {                                          //1=ACK, 2=NAK, 3=RET, 4=NO-RESPONSE, 5=Ignored, 6=OK!
    clearBlock();
    while (!Serial1.available()) {                  //Wait for first byte.
        chronoLogic(1);                             //Update timing flags.
        if (transmission.isUnresponsive)            //Chec if time is up.
            return 4;                               //Return status that time is up if so.
    }
    block[counter].whole = Serial1.read();          //Get first byte.
	if (block[0].part.data == ack)              	//If Acknowledged...
		return 1;                  		   			//Return with one, meaning Acknowledge response recieved.
	if (block[0].part.data == ret)              	//If VMC requests a retransmit...
		return 3;       	                    	//Return to API in order to reload the block w/ data.
	if (block[0].part.data == nak)              	//If Negatively Acknowledged...
		return 2;
	if (!block[0].part.mode) {                       
	    if (!peripheral.isActive)
	        return 5;                               //Return if it's not an address byte and the device isn't active.
	}
	else if ((block[0].part.data & 0xf8) != peripheral.address)
	       return 5;                                //Return if it's not addressed to you.
    while (counter != 36)  {                   		//While the counter does not exceed the maximum block size...
        while (!Serial1.available()) {               ////Wait for data to be recieved.
            chronoLogic(1);                         //Update timing flags.
            if (transmission.isDone)                //Check for inter-byte timeout.
                return 6;                           //Transmission ended.
        }
        chronoLogic(0);
        checksum += block[counter].part.data;       //Add last byte to checksum.
        counter++;                                  
        block[counter].whole = Serial1.read();      //Recieve data byte.
    }
}

void clearBlock() {                            //Clears data out of the block.
    counter = 0;
    while (counter != 36) {
        block[counter].whole = (0x0000);
        counter++;
    }
    counter = 0;
    checksum = 0x00;
}

int tX() {
    counter = 0;
    checksum = 0x00;
    while (pointer != counter) {
    Serial1.write(block[counter].whole);
    checksum += block[counter].part.data;     //Add on to the checksum byte.
    counter++;
    Serial1.flush();                        //Wait for information to finish sending, placed here so previous commands execute prior to any waiting time.
    }
    block[counter].part.data += checksum;   //Add to the checksum, doesn't affect ACK or NAK, but requires a block with no extra data other than what's sent, prior to calling tX().
    block[counter].part.mode = 0x01;        //Add a mode bit to the checksum.
    Serial1.write(block[counter].whole);
    chronoLogic(0);                         //Set non-response timer.
    result = rX();
    if ((result == 1) || (result == 2) || (result == 4))
        clearBlock();
    return result;
}

void chronoLogic(unsigned char command) {     //Command 0 to reset.  Command 1 to update timing variables.  Think of it like a stopwatch, but it updates flags rather than reporting a time.
	if (!command) {
	    microseconds = micros();              //Save time of this command's execution.
	    transmission.isDone = 0;              //Reset the inter-byte timing flag.
	    transmission.isUnresponsive = 0;      //Reset the non-response timing flag.
	    transmission.isResetting = 0;         //Reset the 'BUS RESET' timing flag.
	    return;
	}
	result = micros() - microseconds;
	if (result > 2144) transmission.isDone = 1;
	if (result > 6144) transmission.isUnresponsive = 1;
	if (result > 101144) transmission.isResetting = 1;
	if (result > 201144) transmission.isResetting = 0;
	return;
}

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

void setup() {
    Serial1.begin(9600, SERIAL_9N1);                 //Set up the UART for MDB appropriate settings.
	settings();
	Particle.function("Reset", reSET);
    Particle.function("Begin", beginSession);
    Particle.function("Cancel", sessionCancelRequest);
    Particle.function("Approve", vendApproved);
    Particle.function("Deny", vendDenied);
    Particle.function("Display", displayRequest);
    //Particle.function("Entry", dataEntryRequest);
}

int reSET(String data) {
    rESET();
    return 1;
}

int beginSession(String data) {
    Particle.publish("SessionBegin Recieved!!!");
    clearBlock();
    block[0].part.data = 0xaa;
    block[1].part.data = 0xc0;
    block[2].part.data = 0x55;
    pointer = 2;
    tX();
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

void loop() {
    if (cashless.state == cashless.stateInactive) {
        Particle.publish("Cashless inactive");
        if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))   //No byte will reach here with result 6 if not for you.  Check the command.
            rESET();
        if ((block[0].command == cashless.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
            sETUP();
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            pOLL();
    }
    if (cashless.state == cashless.stateDisabled) {
        if ((block[0].command == cashless.reader.command) && (block[0].part.mode == 0x01) && (result == 6))
            rEADER();
        if ((block[0].command == cashless.reset.command) && (block[0].part.mode == 0x01) && (result == 6))
            rESET();
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            pOLL();
        if ((block[0].command == cashless.setup.command) && (block[0].part.mode == 0x01) && (result == 6))
            sETUP();
    }
    if (cashless.state == cashless.stateEnabled) {
        if ((block[0].command == cashless.vend.command) && (block[0].part.mode == 0x01) && (result == 6))
            vEND();
        if ((block[0].command == cashless.revalue.command) && (block[0].part.mode == 0x01) && (result == 6))
            rEVALUE();
        if ((block[0].command == cashless.expansion.command) && (block[0].part.mode == 0x01) && (result == 6))
            eXPANSION();
        if ((block[0].command == cashless.poll.command) && (block[0].part.mode == 0x01) && (result == 6))
            pOLL();
    }
    if (cashless.state == cashless.stateSessionIdle);
    if (cashless.state == cashless.stateVend);
    if (cashless.state == cashless.stateRevalue);    
    if (cashless.state == cashless.stateNegativeVend);    
}

void resetPeripheral() {                       //Reset flags and other nonessential values.
	cashless.displayRequest = 0x0;               //Flag for when you have info to display on the vending screen.
	cashless.beginSession = 0x00;                 //Flag for when you want to begin a session with the VMC.  Page 15.
	cashless.sessionCancelRequest = 0x00;         //Flag to set if you want to cancel an active session.
    cashless.cmdOutOfSequence = 0x00;             //Self explanatory flag.
    cashless.state = cashless.stateInactive;
}

/*****Functions/commands*****/
void rESET() {                      //Puts the state inactive and loads the sequence.  Page-9
    cashless.state = cashless.stateInactive;
    Serial1.write(0x100);           //No response comes from VMC so sending ACK this way is the most efficient.
    chronoLogic(0);                 //Resettimer for the 200ms or so allowed for resetting.
    resetPeripheral();
    peripheral.isActive = 0x01;
    peripheral.isBusy = 0x01;
    peripheral.isOnline = 0x01;        //Indicates that the MDB device is accepting commands.
    peripheral.isResetting = 0x01;     //Indicates that the peripheral is resetting.
    peripheral.isReset = 0x01;         //Indicates peripheral is done resetting but the VMC doesn't know yet.
    transmission.isUnresponsive = 0x01;
    transmission.isDone = 0x00;
    transmission.isActive = 0x01;      //No current BUS RESET is occuring.
    cashless.state = cashless.stateInactive;
	cashless.displayRequest = 0x0;               //Flag for when you have info to display on the vending screen.
	cashless.beginSession = 0x00;                 //Flag for when you want to begin a session with the VMC.  Page 15.
	cashless.sessionCancelRequest = 0x00;         //Flag to set if you want to cancel an active session.
    cashless.cmdOutOfSequence = 0x00;             //Self explanatory flag.
    cashless.justReset = 0x01;
    counter = 0;
    result = 0;
    pointer = 0;
    clearBlock();                   //Empty/reset the data block.
    while (transmission.isResetting)
        chronoLogic(1);
}

void pOLL() {
    if (cashless.justReset) {       //If the peripheral has finished resetting. 
        clearBlock();
        block[0].part.data = cashless.poll.response.justReset;
        pointer = 1;
        tX();
        clearBlock();
        cashless.justReset = 0x00;
        Serial.printf("     Just RESET");
    }
    else if (cashless.displayRequest) {  //If cashless device requests to display on the Vending Machine's screen.
        block[0].whole = cashless.poll.response.displayRequest;
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
        tX();
        cashless.displayRequest = 0;
        clearBlock();
        return;
    }          //Requests to display data. 
    else if (cashless.beginSession) {
        block[0].whole = cashless.poll.response.beginSession;
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
        tX();
        cashless.beginSession = 0x00;
        Particle.publish("Vend", "Session Began");
    }            //Begins a Vend session.
    else if (cashless.sessionCancelRequest) {
        clearBlock();
        block[0].part.data = cashless.poll.response.sessionCancelRequest;
        pointer = 1;
        result = tX();
        if (block[0].part.data == ack) {
            cashless.sessionCancelRequest = 0x00;
        }
    }    //Cancels a Vend session.
    else if (cashless.vendApproved) {
        block[0].whole = cashless.poll.response.vendApproved;
        block[1].whole = cashless.vendAmount[0];
        block[2].whole = cashless.vendAmount[1];
        pointer = 3;
        if (cashless.vmcFeatureLevel == 0x03) {
            block[3].whole = cashless.vendAmount[2];
            block[4].whole = cashless.vendAmount[3];
            pointer = 5;
        }
        tX();
        cashless.vendApproved = 0x00;
    }            //Approves a vend.
    else if (cashless.vendDenied) {
        block[0].whole = cashless.poll.response.vendDenied;
        pointer = 1;
        tX();
        cashless.vendDenied = 0;
    }              //Denies a vend.
    else if (cashless.endSession) {
        block[0].whole = cashless.poll.response.endSession;
        pointer = 1;
        tX();
    }              //Indicates the reader has returned to the enabled state, follows Session Cancel.
    else if (cashless.cancelled) {
        block[0].whole = cashless.poll.response.cancelled;
        pointer = 1;
        tX();
        cashless.cancelled = 0;
    }               //Aborts READER activities which occur in the enabled state.
    else if (cashless.peripheralID) {
        block[0].whole = cashless.poll.response.peripheralID;
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
        if ((cashless.vmcFeatureLevel == 0x3) && (cashless.vmcFeatureLevel == 0x3) && (/*optional Feature bits enabled by VMC*/0x01)) { /////////////////////////////////
            block[30].whole = cashless.optionalFeatureBits[0]; 
            block[31].whole = cashless.optionalFeatureBits[1];
            block[32].whole = cashless.optionalFeatureBits[2];
            block[33].whole = cashless.optionalFeatureBits[3];
            pointer = 34;
        }
        tX();
    }            //Response to cashless.expansion.peripheralID.command
    else if (cashless.malfunctionError) {
        block[0].whole = cashless.poll.response.malfunctionError;
        block[1].whole = cashless.errorCode;
        pointer = 2;
        tX();
    }        //Reports an error or malfunction to the VMC.
    else if (cashless.cmdOutOfSequence) {
        block[0].whole = cashless.poll.response.cmdOutOfSequence;
        pointer = 1;
        if ((cashless.vmcFeatureLevel >= 2) && (cashless.readerFeatureLevel >= 2)) {
            block[1].whole = cashless.status;
            pointer = 2;
        }
        tX();
    }        //Tells the VMC that a command was sent out of sequence.
    else if (cashless.revalueApproved) {
        
    }         //     revalue involves putting money back onto a cashless payment source.
    else if (cashless.revalueDenied) {
        
    }           //
    else if (cashless.revalueLimitAmount) {
        
    }      //
    /*else if (cashless.userFileData) {
        Do not use, obsolete.
    }          //Obsolete command.*/
    else if (cashless.timeDateRequest) {
        block[0].whole = cashless.poll.response.timeDateRequest;
        pointer = 1;
        tX();
    }         //Request time/date from VMC.
    else if (cashless.dataEntryRequest) {  //Request input from machine Keypad.
        block[0].whole = cashless.poll.response.dataEntryRequest;
        block[1].whole = cashless.dataEntryLengthAndRepeatBit;
        pointer = 2;
        tX();
    }        //Request input from VMC Keypad.
    else if (cashless.dataEntryCancel) {
        block[0].whole = cashless.poll.response.dataEntryCancel;
        pointer = 1;
        tX();
    }         //Cancel input session.
    else if (cashless.reqToRcv) {
        block[0].whole = cashless.poll.response.reqToRcv;
        block[1].whole = cashless.ftlDestinationAddress;
        block[2].whole = peripheral.address;
        block[3].whole = cashless.ftlFileID;
        block[4].whole = cashless.ftlMaximumLength;
        block[5].whole = cashless.ftlControl;
        pointer = 6;
        tX();
    }                //File Transport Layer
    else if (cashless.retryDeny) {
        block[0].whole = cashless.poll.response.retryDeny;
        block[1].whole = cashless.ftlDestinationAddress;
        block[2].whole = peripheral.address;
        block[3].whole = cashless.ftlRetryDeny;
        pointer = 4;
        tX();
    }               //File Transport Layer
    else if (cashless.sendBlock) {
        block[0].whole = cashless.poll.response.sendBlock;
        block[1].whole = cashless.destinationAddress;
        block[2].whole = cashless.blockNumber;
        block[3].whole = cashless.ftlData;
        pointer = 4;
        tX();
    }               //File Transport Layer
    else if (cashless.okToSend) {
        block[0].whole = cashless.poll.response.okToSend;
        block[1].whole = cashless.destinationAddress;
        block[2].whole = peripheral.address;
        pointer = 3;
        tX();
    }                //File transport Layer
    else if (cashless.reqToSend) {
        block[0].whole = cashless.poll.response.reqToSend;
        block[1].whole = cashless.destinationAddress;
        block[2].whole = peripheral.address;
        block[3].whole = cashless.fileID;
        block[4].whole = cashless.maximumLength;
        block[5].whole = cashless.control;
        pointer = 6;
        tX();
    }               //File Transport Layer
    else if (cashless.diagnosticResponse) {
        
    }      //
    else if (cashless.configData) { //CONFIG DATA... I assume this is for compatibility, we don't use this.  Page 14.
        block[0].part.data = cashless.poll.response.readerConfigData;   //Lets the VMC know you are replying to CONFIG-DATA.
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
    pointer = 9;
    tX();  //Transmit Setup response block.  
    }              //Sends config data.
    else
        Serial1.write(0x100);
    clearBlock();
}

void sETUP() {                          //Pages 10-13.
    peripheral.isActive = 1;
    if (block[1].part.data == cashless.setup.configData.command) {
    cashless.vmcFeatureLevel = block[2].part.data;  //Retrieve VMC's supported MDB Level.  Page-10
    cashless.columnsOnDisplay = block[3].part.data;  //Retrieve display dimensions.   Page-10
    cashless.rowsOnDisplay = block[4].part.data;  //Retrieve display dimensions.      Page-10
    cashless.displayType = block[5].part.data;  //0=Seven Segment, 1=ASCII.       Page-10
    clearBlock();
    block[0].part.data = cashless.setup.configData.response.readerConfigData;   //Lets the VMC know you are replying to CONFIG-DATA.
    block[1].part.data = cashless.readerFeatureLevel;  //Tells VMC device supports Level 3.    Page-10
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
    tX();  //Transmit Setup response block.    
    peripheral.isActive = 0;
    return;
    }
    if (block[1].part.data == cashless.setup.maxMinPrices.command) {
        if ((cashless.state == cashless.stateDisabled) && (cashless.vmcFeatureLevel == 0x03)) {
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
        cashless.state = cashless.stateDisabled;  //Device is now in the Disabled state, awaiting DEVICE-ENABLE.
        return;
    }
}

void vEND() {
    if (block[1].part.data == cashless.vend.vendRequest.command) {
        cashless.itemPrice[0] = block[2].part.data;
        cashless.itemPrice[1] = block[3].part.data;
        cashless.itemNumber[0] = block[4].part.data;
        cashless.itemNumber[1] = block[5].part.data;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
        stringData = "Request, Price:";
        stringData += cashless.itemPrice[0];
        stringData += cashless.itemPrice[1];
        stringData += ", Item Number:";
        stringData += cashless.itemNumber[0];
        stringData += cashless.itemNumber[1];
        Particle.publish("Vend", stringData, PRIVATE);
        //if (cashless.)
          //  cashless.state = cashless.stateVend;
    }
    if (block[1].part.data == cashless.vend.vendCancel.command) {
        block[0].whole = cashless.vend.vendCancel.response.vendDenied;
        pointer = 1;
        tX();
    }
    if (block[1].part.data == cashless.vend.vendSuccess.command) {
        cashless.itemNumber[0] = block[2].part.data;
        cashless.itemNumber[1] = block[3].part.data;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
        stringData = "Success, item Number:";
        stringData += cashless.itemNumber[0];
        stringData += cashless.itemNumber[1];
        Particle.publish("Vend", stringData, PRIVATE);
    }
    if (block[1].part.data == cashless.vend.vendFailure.command) {
        return;
    }
    if (block[1].part.data == cashless.vend.sessionComplete.command) {
        clearBlock();
        block[0].part.data = cashless.vend.sessionComplete.response.endSession;
        pointer = 1;
        tX();
        cashless.state = cashless.stateEnabled;
        Particle.publish("Vend", "Complete", PRIVATE);
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
        stringData = "Cash Sale, $";
        stringData += ((cashless.itemPrice[0] * cashless.scaleFactor) << (cashless.decimalPlaces + 0x01)) ;
    }
}

void rEADER() {
    if (block[1].part.data == cashless.reader.readerEnable.command) {
        cashless.state = cashless.stateEnabled;
        clearBlock();
        block[0].part.data = ack;
        pointer = 0;
        tX();
            stringData = "Enabled: Level=";
			stringData += cashless.vmcFeatureLevel;
			stringData += ", Display(";
			stringData += cashless.rowsOnDisplay;
			stringData += ",";
			stringData += cashless.columnsOnDisplay;
			stringData += ")";
			if (cashless.displayType == 0x01)
			    stringData += "FULL-ASCII";
			else if (cashless.displayType == 0x00)
			    stringData += "BASIC-ASCII";
			stringData += ", Max/Min-Prices:";
			stringData += cashless.maximumPrice[0];
			stringData += cashless.maximumPrice[1];
			stringData += cashless.maximumPrice[3];
			stringData += "/";
			stringData += cashless.minimumPrice[0];
			stringData += cashless.minimumPrice[1];
			stringData += ".";
			stringData += cashless.minimumPrice[2];
        Particle.publish("State", stringData, PRIVATE);
    }
    if (block[1].part.data == cashless.reader.readerDisable.command) {
        return;
    }
}

void rEVALUE() {
    
}

void eXPANSION() {
    if (block[1].part.data == cashless.expansion.requestID.command) {
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