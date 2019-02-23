#include "Cashless.h"

/*Completed Secions: 7.4.22 - 7.4.28 */
/*Needs work: 7.5-7.6


/*Setup Notes(for users):
 *Name this file Cashless#, with the # set to the desired cashless device.
 *readerFeatureLevel, countryCurrencyCode, DiagnosticCommand, appmaxresponse,
 *
 */
/*
 *Abstract usage notes (for me):
 *cashless.columnsOnDisplay, cashless.rowsOnDisplay, cashless.displayType 0=7seg,1ascii
 *
 *
 * Possibly obsolete flags/values
 * isActiveFlag
 * isBusyFlag
 * isOnlineFlag
 */

extern uint8_t mainz();

struct cashlessVariables {
uint8_t address;
/* SETUP VARIABLES */
/* 7.4.2 */
uint8_t vmcFeatureLevel : 2;
uint8_t columnsOnDisplay;
uint8_t rowsOnDisplay;
uint8_t displayType : 3; /* Wording selected to avoid confusion */
	uint8_t readerFeatureLevel : 2;
	uint8_t countryCurrencyCode[1];
	uint8_t countryCurrencyCodeLevel3[1];
	uint8_t scaleFactor;
	uint8_t decimalPlaces;
	uint8_t applicationMaximumResponseTime;
	uint8_t miscellaneousOptions : 4;
/* 7.4.3 */
	uint8_t maximumPrice[3];
	uint8_t minimumPrice[3];
	uint8_t vmcCurrencyCode[1];
/* POLL VARIABLES */
/* Poll.readerConfigInfo is made up from vallues previously mentioned */
/* 7.4.4 */
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
//Poll.revalueDenied or Approved or limitAmount.Page 71-73
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

//FLAGS.If MDB were a kernel, these would be the shell commands.Setting a flag will get the action done at the appropriate time.
uint8_t displayRequest_f : 1; //Flag for when you have info to display on the vending screen.
uint8_t displayDataPointer : 5; //Makes calculating the message length bytes easier.
uint8_t beginSession_f : 1; //Flag for when you want to begin a session with the VMC.Page 15.
uint8_t beginSessionReady_f : 1;//After setting the begin session flag, a function loads up the necessary data, and sets this once done.The pOLL function checks for this flag.
uint8_t sessionCancelRequest_f : 1; //Flag to set if you want to cancel an active session.
uint8_t errorCode_f : 1;//Flag for when there is an error code to report.
uint8_t commandOutOfSequence_f : 1;
uint8_t justReset_f : 1;
uint8_t vendApproved_f : 1;
uint8_t vendDenied_f : 1;
uint8_t cancelled_f : 1;
uint8_t endSession_f : 1;
uint8_t peripheralID_f : 1;
uint8_t malfunctionError_f : 1;
uint8_t revalueDenied_f : 1;
uint8_t revalueApproved_f : 1;
uint8_t revalueLimitAmount_f : 1;
uint8_t timeDateRequest_f : 1;
uint8_t dataEntryRequest_f : 1;
uint8_t dataEntryCancel_f : 1;
uint8_t reqToRcv_f : 1;
uint8_t reqToSend_f : 1;
uint8_t retryDeny_f : 1;
uint8_t sendBlock_f : 1;
uint8_t okToSend_f : 1;
uint8_t configData_f : 1;
uint8_t diagnosticResponse_f : 1;
uint8_t isActive_f : 1; //Flag set when device has been addressed, and reset when the VMC is done addressing the peripheral.
uint8_t isBusy_f : 1; //Flag set when device is busy doing something such as dispensing a coin, or connecting to a web service.
uint8_t isOutgoing_f : 1; //Flag set when device has information to send in response to the next poll (excluding ACKnowledge).
uint8_t isOnline_f : 1; //Flag set when device is online, reset when device is offline, meaning ignore all MDB activity.
uint8_t isResetting_f : 1;//Flag set when device recieves a reset command, and un-set when peripheral's reset completes.
uint8_t isReset_f : 1;//Flag set when device has been reset, but hasn't transmitted the 'JUST RESET' response yet.
uint8_t coinReturnPushed : 1; /*Coin Mech Escrow/Return button pushed.*/
} cashless; //Variables

uint8_t Cashless1(uint8_t command)
{
/* All the top level abstract commands go here  #FIXDIS numbering of cashless*/
/*if (CREATE)
	startCashless();
if (RESET)
	rESET();
if ()*/
}

/*7.1*/
uint8_t startCashless ()
{
struct cashlessVariables cashless;
if ((__FILE__ == "Cashless1.cpp") || (__FILE__ == "Cashless1.c"))
	cashless.address = CASHLESS1_ADDRESS;
else if ((__FILE__ == "Cashless2.cpp") || (__FILE__ == "Cashless2.c"))
	cashless.address = CASHLESS2_ADDRESS;
else {
	fprintf(stderr, "Rename the Cashless.cpp to Cashless1.cpp, Cashless2.cpp, or Cashless3.cpp\n");
	fprintf(stderr, "The difference is:         Credit Cards,  Mobile Phones,    Battery powered\n");
return 0x01;
}
rESET();
cashless.justReset_f = 0x00; /*The only difference between setup and reset*/
return 0x00;
}

uint8_t configCashless ()
{
//For Setup - Config Data.
cashless.readerFeatureLevel = 0x03;
cashless.countryCurrencyCode[0] = 0x00;
cashless.countryCurrencyCode[1] = 0x01; /*Telephone code*/
cashless.countryCurrencyCodeLevel3[0] = 0x18;
cashless.countryCurrencyCodeLevel3[1] = 0x40; /*Level 3 code #FIXDIS*/
cashless.scaleFactor = 0x01;//Pennies
cashless.decimalPlaces = 0x02;//Murica.
cashless.applicationMaximumResponseTime = 0x00; //Default.
cashless.miscellaneousOptions = (
0x00
| 0x01 /*Comment out this line if refunds are unsupported*/
| 0x02 /*Comment out this line if multivend is unsupported*/
| 0x04 /*Comment out this line if cashless device has no display*/
| 0x08 /*Comment out this line if uninterested in CashSale reporting*/
); /*Bit descriptions (n/a) (n/a) (n/a) (n/a) (refunds) (multivend-capability) (hasDisplay) (Vend/Cash tracking)*/
//For Expansion - PeripheralID.
 // cashless.optionalFeatureBits[0] = 0x00;//Not used
 // cashless.optionalFeatureBits[1] = 0x00;//Not used OLD CODE, CHECK AND UPDATE TO DE NEW WEY
 // cashless.optionalFeatureBits[2] = 0x00;//Not used
 // cashless.optionalFeatureBits[3] = 0x04;//Bit descriptions (n/a) (n/a) (Always Idle) (Data Entry) (Negative Vend) (Multi-Currency/Lingual Support) (16 or 32 bit Monetary Format) (FTL Supported)
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
cashless.readerSerialNumber[11] = 0x00;//Your very own serial number.
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
cashless.readerModelNumber[11] = 0x00;//Your very own model number.
//For display request
cashless.displayTime = 0xaa;//Time unit is 0.1 seconds.
cashless.displayData[0] = 0x01; //The product of these two must equal the lenght of the message.
cashless.displayData[1] = 0x0a; //The product of these two must equal the length of the message.
cashless.displayData[2] = 0x4b;
cashless.displayData[3] = 0x49; //ASCII characters. 4b 49 4c 4c 48 55 4d 41 4e 53
cashless.displayData[4] = 0x4c; //KILLHUMANS
cashless.displayData[5] = 0x4c;
cashless.displayData[6] = 0x48;
cashless.displayData[7] = 0x55;
cashless.displayData[8] = 0x4d;
cashless.displayData[9] = 0x41;
cashless.displayData[10] = 0x4e;
cashless.displayData[11] = 0x53;
cashless.displayData[31] = 0xff;
//For Begin Session
cashless.fundsAvailable[0] = 0xff;//Scaled, set to 0xffff if unknown.
cashless.fundsAvailable[1] = 0xfe;
cashless.paymentMediaID[0] = 0xff;//Set to 0xffffffff if unknown.
cashless.paymentMediaID[1] = 0xff;
cashless.paymentMediaID[2] = 0xff;
cashless.paymentMediaID[3] = 0xff;
cashless.paymentType = 0x40;//Test Vend.
cashless.paymentData[0] = 0x00;
cashless.paymentData[1] = 0x00;
cashless.userLanguage[0] = 0x00;
cashless.userLanguage[1] = 0x00;
cashless.userCurrencyCode[0] = 0x00;
cashless.userCurrencyCode[1] = 0x00;
cashless.cardOptions = 0x00;
}

/*7.2Incomplete*/
uint8_t mainz()
{
if (rX9BitsAvailable() == 0x01)
	rxResult = rX(cashless.address);
if (rxResult == RECEIVED) {
	rxResult = EMPTY;
	switch (cashless.state) {
/*7.2.1*/
		case CASHLESS_STATE_INACTIVE :
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					return rESET();
				case CASHLESS_SETUP_COMMAND :
					return sETUP();
				case CASHLESS_POLL_COMMAND :
					return pOLL();
				case CASHLESS_VEND_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_REVALUE_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_EXPANSION_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;
/*7.2.2*/
		case CASHLESS_STATE_DISABLED :
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					return rESET();
				case CASHLESS_SETUP_COMMAND :
					return sETUP();
				case CASHLESS_POLL_COMMAND :
					return pOLL();
				case CASHLESS_VEND_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_REVALUE_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_EXPANSION_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_READER_COMMAND :
					return rEADER();
			}
			return RUNTIME_ERROR;
/*7.2.3*/
		case CASHLESS_STATE_INACTIVE :
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					return rESET();
				case CASHLESS_SETUP_COMMAND :
					return sETUP();
				case CASHLESS_POLL_COMMAND :
					return pOLL();
				case CASHLESS_VEND_COMMAND :
					return vEND();
				case CASHLESS_REVALUE_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_EXPANSION_COMMAND :
					return eXPANSION();
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;

		case CASHLESS_STATE_ENABLED :
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					return rESET();
				case CASHLESS_SETUP_COMMAND :
					return sETUP();
				case CASHLESS_POLL_COMMAND :
					return pOLL();
				case CASHLESS_VEND_COMMAND :
					return vEND();
				case CASHLESS_REVALUE_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_EXPANSION_COMMAND :
					return eXPANSION();
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;

		case CASHLESS_STATE_SESSIONIDLE :
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					return rESET();
				case CASHLESS_SETUP_COMMAND :
					return sETUP();
				case CASHLESS_POLL_COMMAND :
					return pOLL();
				case CASHLESS_VEND_COMMAND :
					return vEND(();
				case CASHLESS_REVALUE_COMMAND :
					return rEVALUE();
				case CASHLESS_EXPANSION_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;
/*7.2.4*/
/*7.2.5Check the vend state.Vend is non interruptable, but should respond to a reset or vend command.?*/
		case CASHLESS_STATE_ALWAYSIDLE :
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					return rESET();
				case CASHLESS_SETUP_COMMAND :
					return sETUP();
				case CASHLESS_POLL_COMMAND :
					return pOLL();
				case CASHLESS_VEND_COMMAND :
					return vEND(();
				case CASHLESS_REVALUE_COMMAND :
					return rEVALUE();
				case CASHLESS_EXPANSION_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;

		case CASHLESS_STATE_VEND :
			if (cashless.isResetting_f == 0x1) {
				return terminateSession();
			}
			if (cashless.coinReturnPushed_f == 0x01) {
				cashless.endSession_f = 0x1;
				cashless.coinReturnPushed = 0x0;
				return EMPTY;
			}
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_SETUP_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_POLL_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_VEND_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_REVALUE_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_EXPANSION_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;

		case CASHLESS_STATE_REVALUE :
			if (cashless.isResetting_f == 0x1)
				return terminateSession();
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_SETUP_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_POLL_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_VEND_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_REVALUE_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_EXPANSION_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;
/*7.2.6*/
		case CASHLESS_STATE_NEGATIVEVEND :
			if (cashless.isResetting_f == 0x1)
				return terminateSession();
			switch (block[0].part.data) {
				case CASHLESS_RESET_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_SETUP_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_POLL_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_VEND_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_REVALUE_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_EXPANSION_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
				case CASHLESS_READER_COMMAND :
					cashless.commandOutOfSequence_f = 0x1;
					return DISORDERED;
			}
			return RUNTIME_ERROR;

/*7.2.7*/
	}
	return RUNTIME_ERROR;
}
}

uint8_t terminateSession() {
	/*return credits, cancel vend, etc.  Prepare to reset*/
}

/*7.3 Describes the flow of all functions
 *7.3.1
 *7.3.2 Check this over, implemented in main function.
/*7.3.0-7.3. is applied to all mdb side communications, and is more relevant to the VMC source file*/

/*7.4 INCOMPLETE*/

/*7.4.1*/
uint8_t rESET() {
	if (block[0].part.data == CASHLESS_RESET_COMMAND) { /*rESET() is called for a BUS RESET too, which you don't ACK.*/
	block[0].part.data = ACK;
	pointer = 0;
	tX(pointer, cashless.address);
}
cashless.isResetting_f = 0x01;
if (cashless.state = CASHLESS_STATE_VEND)
	return 0;
if (cashless.state = CASHLESS_STATE_NEGATIVEVEND)
	return 0;
if (cashless.state = CASHLESS_STATE_REVALUE)
	return 0;

cashless.displayRequest_f = 0x00;
cashless.beginSession_f = 0x00;
cashless.sessionCancelRequest_f = 0x00;
cashless.commandOutOfSequence_f = 0x00;
cashless.justReset_f = 0x1;

cashless.state = CASHLESS_STATE_INACTIVE;
}

/*7.4.2 - 7.4.3*/
uint8_t sETUP() {
/*7.4.2*/
if (block[1].part.data == CASHLESS_SETUP_CONFIGDATA_COMMAND) {
	cashless.vmcFeatureLevel = block[2].part.data;
	cashless.columnsOnDisplay = block[3].part.data;
	cashless.rowsOnDisplay = block[4].part.data;
	cashless.displayType = block[5].part.data;
	clearBlock(); /*Necessary for clearing old mode bits*/
	block[0].part.data = CASHLESS_SETUP_CONFIGDATA_RESPONSE_READERCONFIGDATA;
	block[1].part.data = cashless.readerFeatureLevel;
	block[2].part.data = cashless.countryCurrencyCode[0]; /*Telephone Country Code*/
	block[3].part.data = cashless.countryCurrencyCode[1];
	if ((cashless.vmcFeatureLevel == 0x03) && (cashless.readerFeatureLevel == 0x03)) {
		block[2].part.data = cashless.countryCurrencyCodeLevel3[0]; /*ISO4217 country code*/
		block[3].part.data = cashless.countryCurrencyCodeLevel3[1];
	}
	block[4].part.data = cashless.scaleFactor;//Sets the scale factor for the currency. Page-11
	block[5].part.data = cashless.decimalPlaces;//Sets decimal places up for cents. Page-11
	block[6].part.data = cashless.applicationMaximumResponseTime;//Sets maximum response time.Page-12
	block[7].part.data = cashless.miscellaneousOptions;//Sets refunds, multivend, display, and sales reporting.Page-12
	pointer = 8;
	tX(pointer, cashless.address);//Transmit Setup response block.
	cashless.isActive_f = 0x01;
	return 0;
}
/*7.4.3*/
if (block[1].part.data == CASHLESS_SETUP_MAXMINPRICES_COMMAND) {
	if ((cashless.state == CASHLESS_STATE_DISABLED) && (cashless.vmcFeatureLevel == 0x03)) {
		cashless.maximumPrice[0] = block[2].part.data;
		cashless.maximumPrice[1] = block[3].part.data;
		cashless.maximumPrice[2] = block[4].part.data;
		cashless.maximumPrice[3] = block[5].part.data;
		cashless.minimumPrice[0] = block[6].part.data;
		cashless.minimumPrice[1] = block[7].part.data;
		cashless.minimumPrice[2] = block[8].part.data;
		cashless.minimumPrice[3] = block[9].part.data;
		cashless.countryCurrencyCode[0] = block[10].part.data;
		cashless.countryCurrencyCode[1] = block[11].part.data;
	}
	else {
		cashless.maximumPrice[0] = block[2].part.data;
		cashless.maximumPrice[1] = block[3].part.data;
		cashless.minimumPrice[0] = block[4].part.data;
		cashless.minimumPrice[1] = block[5].part.data;
	}
	clearBlock();
	Serial1.write(0x100);
	cashless.state = CASHLESS_STATE_DISABLED;
	return 0x0;
}
}

/*7.4.4*/
uint8_t pOLL() {
if (cashless.justReset_f == 0x01) {
	block[0].part.data = CASHLESS_POLL_RESPONSE_JUSTRESET;
	tX(1, cashless.address);
	clearBlock();
	cashless.justReset_f = 0x0;
}
else if (cashless.displayRequest_f) {
	block[0].whole = CASHLESS_POLL_RESPONSE_DISPLAYREQUEST;
	block[1].whole = cashless.displayTime;
	for (int displayDataCounter = 0; displayDataCounter != 32; displayDataCounter++) {
		block[(displayDataCounter + 2)].whole = cashless.displayData[displayDataCounter];
	}
	//pointer = ((cashless.columnsOnDisplay * cashless.rowsOnDisplay) + 2);	?????????????????
	pointer = 33; /*Check this w/ the manual*/
	tX(pointer, cashless.address);
	cashless.displayRequest_f = 0;
	clearBlock();
	return 0;
}
else if (cashless.beginSession_f) {
	cashless.state = CASHLESS_STATE_SESSIONIDLE;
	block[0].whole = CASHLESS_POLL_RESPONSE_BEGINSESSION;
	block[1].whole = cashless.fundsAvailable[0];
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
	cashless.beginSession_f = 0x1;
}
else if (cashless.sessionCancelRequest_f == 0x01) {
	clearBlock();
	block[0].part.data = CASHLESS_POLL_RESPONSE_SESSIONCANCELREQUEST;
	rxResult = tX(1, cashless.address);
	if (block[0].part.data == ACK)
		cashless.sessionCancelRequest_f = 0x00;
}
else if (cashless.vendApproved_f) {
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
	cashless.vendApproved_f = 0x00;
}
else if (cashless.vendDenied_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_VENDDENIED;
	tX(1, cashless.address);
	cashless.vendDenied_f = 0x00;
}
else if (cashless.endSession_f = 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_ENDSESSION;
	tX(1, cashless.address);
}
else if (cashless.cancelled_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_CANCELLED;
	tX(1, cashless.address);
	cashless.cancelled_f = 0x00;
}
else if (cashless.peripheralID_f == 0x01) {
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
	if ((cashless.vmcFeatureLevel == 0x3) && (cashless.readerFeatureLevel == 0x3) && (/*optional Feature bits enabled by VMC #FIXDIS*/0x01)) {
		block[30].whole = (
/*
			(cashless.optionalFeatureBitsEnabled. << 7) |
			(cashless.optionalFeatureBitsEnabled. << 6) |
			(cashless.optionalFeatureBitsEnabled. << 5) |
			(cashless.optionalFeatureBitsEnabled. << 4) |
			(cashless.optionalFeatureBitsEnabled. << 3) |
			(cashless.optionalFeatureBitsEnabled. << 2) |
			(cashless.optionalFeatureBitsEnabled. << 1) |
			(cashless.optionalFeatureBitsEnabled. )*/
			0x000
		);
		block[31].whole = (
/*
			(cashless.optionalFeatureBitsEnabled. << 7) |
			(cashless.optionalFeatureBitsEnabled. << 6) |
			(cashless.optionalFeatureBitsEnabled. << 5) |
			(cashless.optionalFeatureBitsEnabled. << 4) |
			(cashless.optionalFeatureBitsEnabled. << 3) |
			(cashless.optionalFeatureBitsEnabled. << 2) |
			(cashless.optionalFeatureBitsEnabled. << 1) |
			(cashless.optionalFeatureBitsEnabled. )*/
			0x000
		);
		block[32].whole = (
/*
			(cashless.optionalFeatureBitsEnabled. << 7) |
			(cashless.optionalFeatureBitsEnabled. << 6) |
			(cashless.optionalFeatureBitsEnabled. << 5) |
			(cashless.optionalFeatureBitsEnabled. << 4) |
			(cashless.optionalFeatureBitsEnabled. << 3) |
			(cashless.optionalFeatureBitsEnabled. << 2) |
			(cashless.optionalFeatureBitsEnabled. << 1) |
			(cashless.optionalFeatureBitsEnabled. )*/
			0x000
		);
		block[33].whole = (
/*
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
	cashless.peripheralID_f = 0x00;
}
else if (cashless.malfunctionError_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_MALFUNCTIONERROR;
	block[1].whole = cashless.errorCode_f; /*#FIXDIS*/
	tX(2, cashless.address);
}
else if (cashless.commandOutOfSequence_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_COMMANDOUTOFSEQUENCE;
	pointer = 1;
	if ((cashless.vmcFeatureLevel >= 2) && (cashless.readerFeatureLevel >= 2)) {
		block[1].whole = cashless.state;
		pointer = 2;
	}
	tX(pointer, cashless.address);
}
else if (cashless.revalueApproved_f == 0x1) {
	/*#FIXDIS*/
}
else if (cashless.revalueDenied_f == 0x1) {
	/*#FIXDIS*/
}
else if (cashless.revalueLimitAmount) {
	/*#FIXDIS*/
}
else if (cashless.userFileData) {
	/*Obsolete Command kept for compatibility.  #FIXDIS*/
}
else if (cashless.timeDateRequest_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_TIMEDATEREQUEST;
	tX(1, cashless.address);
}
else if (cashless.dataEntryRequest_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_DATAENTRYREQUEST;
	block[1].whole = cashless.dataEntryLengthAndRepeatBit;
	tX(2, cashless.address);
}
else if (cashless.dataEntryCancel_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_DATAENTRYCANCEL;
	tX(1, cashless.address);
}
/*#FIXDIS  VVV FTL STUFF BELOW VVV*/
else if (cashless.reqToRcv_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_REQTORCV;
	block[1].whole = cashless.ftlDestinationAddress;
	block[2].whole = cashless.address;
	block[3].whole = cashless.ftlFileID;
	block[4].whole = cashless.ftlMaximumLength;
	block[5].whole = cashless.ftlControl;
	tX(6, cashless.address);
}
else if (cashless.retryDeny_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_RETRYDENY;
	block[1].whole = cashless.ftlDestinationAddress;
	block[2].whole = cashless.address;
	block[3].whole = cashless.ftlRetryDeny;
	tX(4, cashless.address);
}
else if (cashless.sendBlock_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_SENDBLOCK;
	block[1].whole = cashless.destinationAddress;
	block[2].whole = cashless.blockNumber;
	block[3].whole = cashless.ftlData;
	tX(4, cashless.address);
}
else if (cashless.okToSend_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_OKTOSEND;
	block[1].whole = cashless.destinationAddress;
	block[2].whole = cashless.address;
	tX(3, cashless.address);
}
else if (cashless.reqToSend_f == 0x01) {
	block[0].whole = CASHLESS_POLL_RESPONSE_REQTOSEND;
	block[1].whole = cashless.destinationAddress;
	block[2].whole = cashless.address;
	block[3].whole = cashless.fileID;
	block[4].whole = cashless.maximumLength;
	block[5].whole = cashless.control;
	tX(6, cashless.address);
}
else if (cashless.diagnosticResponse_f == 0x01) {
	/*#FIXDIS*/
}
else if (cashless.configData_f == 0x01) {
	/*FIXDIS*/
	//CONFIG DATA... I assume this is for compatibility, we don't use this.Page 14.
	block[0].part.data = CASHLESS_POLL_RESPONSE_READERCONFIGINFO; //Lets the VMC know you are replying to CONFIG-DATA, from a previous SETUP command.
	block[1].part.data = cashless.readerFeatureLevel;//Tells VMC device supports Level 3.Page-10
	block[2].part.data = cashless.countryCurrencyCode[0];//First half of US country code.Page-11
	block[3].part.data = cashless.countryCurrencyCode[1];//Second half of US country code. Page-11
	if ((cashless.vmcFeatureLevel == 0x03) && (cashless.readerFeatureLevel == 0x03)) {//IF VMC supports Level 3 MDB. Page-11
		block[2].part.data = (0x18);//THEN use ISO4217 country code.Page-11
		block[3].part.data = (0x40);//Second half of ISO4217 code.Page-11
	}
	block[4].part.data = (0x01);//Sets coin scale to 1 for pennies. Page-11
	block[5].part.data = (0x02);//Sets decimal places up for cents. Page-11
	block[6].part.data = cashless.applicationMaximumResponseTime;//Sets maximum response time.Page-12
	block[7].part.data = cashless.miscellaneousOptions;//Sets refunds, multivend, display, and sales reporting.Page-12
	block[8].part.mode = (0x01);//Set data length.
	tX(9, cashless.address);//Transmit Setup response block.
}
else {
	clearBlock();
	block[0].whole = ACK;
	pointer = 0;
	tx(pointer, cashless.address);
}
return 0x0;
}

/*7.4.5 - 7.4.11*/
uint8_ tvEND() {
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
uint8_t rEADER() {
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
uint8_ trEVALUE() {
/*7.4.16*/
/*7.4.17*/
}

/*7.4.18*/
uint8_t eXPANSION() {
switch (block[1].part.data) {
/*7.4.18*/
if (block[1].part.data == CASHLESS_EXPANSION_REQUESTID_COMMAND) {
	for (int counter = 2; counter < 31; counter++) {
		if (counter < 5)
			cashless.vmcManufacturerCode[counter - 2] = block[counter].part.data;
		else if (counter < 17)
			cashless.vmcSerialNumber[counter - 5] = block[counter].part.data;
		else if (counter < 29)
			cashless.vmcModelNumber[counter - 17] = block[counter].part.data;
		else if (counter < 28)
			cashless.vmcSoftwareVersion[counter - 29] = block[counter].part.data;
	}
	clearBlock();
	block[0].part.data = cashless.address;
	for (int counter = 1; counter < 30; counter++) {
		if (counter < 4)
			block[counter].part.data = cashless.readerManufacturerCode[counter - 1];
		if (counter < 16)
			block[counter].part.data = cashless.readerSerialNumber[counter - 4];
		if (counter < 28)
			block[counter].part.data = cashless.readerModelNumber[counter - 16];
		if (counter < 30)
			block[counter.part.data = cashless.readerSoftwareVersion[counter - 28];
	}
	pointer = 30;
	if (cashless.vmcFeatureLevel == 0x03) {
		block[30].whole = (
	/*
		(cashless.optionalFeatureBitsEnabled. << 7) |
		(cashless.optionalFeatureBitsEnabled. << 6) |
		(cashless.optionalFeatureBitsEnabled. << 5) |
		(cashless.optionalFeatureBitsEnabled. << 4) |
		(cashless.optionalFeatureBitsEnabled. << 3) |
		(cashless.optionalFeatureBitsEnabled. << 2) |
		(cashless.optionalFeatureBitsEnabled. << 1) |
		(cashless.optionalFeatureBitsEnabled. )*/
		0x000
		);
		block[31].whole = (
	/*
		(cashless.optionalFeatureBitsEnabled. << 7) |
		(cashless.optionalFeatureBitsEnabled. << 6) |
		(cashless.optionalFeatureBitsEnabled. << 5) |
		(cashless.optionalFeatureBitsEnabled. << 4) |
		(cashless.optionalFeatureBitsEnabled. << 3) |
		(cashless.optionalFeatureBitsEnabled. << 2) |
		(cashless.optionalFeatureBitsEnabled. << 1) |
		(cashless.optionalFeatureBitsEnabled. )*/
		0x000
		);
		block[32].whole = (
	/*
		(cashless.optionalFeatureBitsEnabled. << 7) |
		(cashless.optionalFeatureBitsEnabled. << 6) |
		(cashless.optionalFeatureBitsEnabled. << 5) |
		(cashless.optionalFeatureBitsEnabled. << 4) |
		(cashless.optionalFeatureBitsEnabled. << 3) |
		(cashless.optionalFeatureBitsEnabled. << 2) |
		(cashless.optionalFeatureBitsEnabled. << 1) |
		(cashless.optionalFeatureBitsEnabled. )*/
		0x000
		);
		block[33].whole = (
	/*
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
	tX(pointer, cashless.address);
}
/*7.4.19*/
if (block[1].part.data == CASHLESS_EXPANSION_READUSERFILE_COMMAND) {
	clearBlock();
	block[0].part.data = CASHLESS_EXPANSION_READUSERFILE_RESPONSE_USERFILEDATA;//Currently unsupported and not forseen to be needed.
	pointer = 1;
	tX(pointer, cashless.address);
}
/*7.4.20*/
if (block[1].part.data == CASHLESS_EXPANSION_WRITEUSERFILE_COMMAND) {
	/* Obsolete Command */
	clearBlock();
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
	/* #REVISIT*/
	cashless.vmcOptionalFeatureBits[3] = block[2].part.data;
	cashless.vmcOptionalFeatureBits[2] = block[3].part.data;
	cashless.vmcOptionalFeatureBits[1] = block[4].part.data;
	cashless.vmcOptionalFeatureBits[0] = block[5].part.data;
	block[0].part.data = ACK;
	pointer = 0;
	tX(pointer, cashless.address);
}
/*7.4.23*/
	case CASHLESS_EXPANSION_FTL_REQTORCV_COMMAND :
		ftl(cashless.address);
		break;
/*7.4.24*/
	case CASHLESS_EXPANSION_FTL_RETRYDENY_COMMAND :
		ftl(cashless.address);
		break;
/*7.4.25*/
	case CASHLESS_EXPANSION_FTL_SENDBLOCK_COMMAND :
		ftl(cashless.address);
		break;
/*7.4.26*/
	case CASHLESS_EXPANSION_FTL_OKTOSEND_COMMAND :
		ftl(cashless.address);
		break;
/*7.4.27*/
	case CASHLESS_EXPANSION_FTL_REQTOSEND :
		/* #REVISIT */
		ftl(cashless.address);
		break;
/*7.4.28*/
	case CASHLESS_EXPANSION_DIAGNOSTICS_COMMAND :
		/* Manufacturer Defined Instructions, #REVISIT */
		clearBlock();
		block[0].part.data = CASHLESS_EXPANSION_DIAGNOSTICS_RESPONSE_DIAGNOSTICSRESPONSE;
		/* Manufacturer Defined Data*/
		break;
}
}


uint8_t beginSession(String data) {//I don't remember this, it's old code so might be obsolete?
clearBlock();
//block[0].part.data = 0xaa;
//block[1].part.data = 0xc0;
//block[2].part.data = 0x55;
//tX(3, cashless.address);
cashless.fundsAvailable[0] = data.charAt(0);
cashless.fundsAvailable[1] = data.charAt(1); //Load minimum known currency.
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
cashless.beginSession_f = 0x00;
cashless.beginSessionReady_f = 0x01;
return 1;
}

uint8_t sessionCancelRequest(String data) {
cashless.sessionCancelRequest_f = 0x01;
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
cashless.vendApproved_f = 0x01;
return 0;
}

uint8_t vendDenied(String data) {
cashless.vendDenied_f = 0x00;
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
