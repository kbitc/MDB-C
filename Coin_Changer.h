//5.1

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
	} reset;                                  //5.3
	struct {
		unsigned char command = 0x09;
	} setup;                             //5.4
	struct {
		unsigned char command = 0x0b;
    struct {
      unsigned char coinsDispensedManually = 0x80;
      unsigned char coinsDeposited = 0x40;
      unsigned char status = 0x00;  //For VMC use.
      unsigned char slug = 0x20;    //For VMC use.
      unsigned char ftlPolledResponse FFFFFFFTTTTTTLLLLLLL STUFFFFFFF;
    } response;       //Bitmasks
	} poll;                              //5.6
	struct {
    unsigned char command = 0x0a;
  } tubeStatus;                        //5.5
  struct {
    unsigned char command = 0x0c;
  } coinType;                          //5.9
  struct {
    unsigned int command = 0x0d;
  } dispense;                          //5.10
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
	} expansion;                         //5.11
  struct {
    unsigned char escrowRequest : 1 = 0x01;
    unsigned char changerPayoutBusy : 2 = 0x02;
    unsigned char noCredit : 2 = 0x03;
    unsigned char defectiveTubeSensor : 3 = 0x04;
    unsigned char doubleArrival : 3 = 0x05;
    unsigned char acceptorUnplugged : 3 = 0x06;
    unsigned char tubeJam : 3 = 0x07;
    unsigned char romChecksumError : 4 = 0x08;
    unsigned char coinRoutingError : 4 = 0x09;
    unsigned char changerBusy : 4 = 0x0a;
    unsigned char changerWasReset : 4 = 0x0b;
    unsigned char coinJam : 4 = 0x0c;
    unsigned char possibleCreditedCoinRemoval : 4 = 0x0d;
  } status;
} changer;                            //Constants


struct CoinHopper{
  String ;
  unsigned char address = 0x08;                    //5.1
  //SETUP VARIABLES
    //Setup 5.4
    unsigned char vmcFeatureLevel : 2;
    unsigned char changerFeatureLevel : 2;
    unsigned char countryCurrencyCode[1];			//Page 61.
    unsigned char scaleFactor;
    unsigned char decimalPlaces;
    unsigned char coinTypeRouting[1];
    unsigned char coinTypeCredit[15];
    //5.5
    unsigned char tubeFullStatus[1];
    unsigned char tubeStatus[15];
    //5.6
    unsigned char coinsDispensedManually : 1;
    unsigned char coinsDispensedManuallyData[15];
    unsigned char coinsDeposited : 1;
    unsigned char coinsDepositedData[15];
    unsigned char status : 1;
    unsigned char slug : 1;
    unsigned char slugs;
    unsigned char escrowRequest : 1;
    unsigned char changerPayoutBusy : 1;
    unsigned char noCredit : 1;
    unsigned char defectiveTubeSensor : 1;
    unsigned char doubleArrival : 1;
    unsigned char acceptorUnplugged : 1;
    unsigned char tubeJam : 1;
    unsigned char romChecksumError : 1;
    unsigned char coinRoutingError : 1;
    unsigned char changerBusy : 1;
    unsigned char changerWasReset : 1;
    unsigned char coinJam : 1;
    unsigned char possibleCreditedCoinRemoval :1;
    //Poll.revalueDenied or Approved or limitAmount.  Page 71-73
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
} changer1;                                    //Variables


static int resetPeripheral() {
  changer1.commandOutOfSequence = 0x0;          //Self explanatory flag.

}

static int reset() {

}

static int setup() {
  clearBlock();
  block[0].part.data = changer1.changerFeatureLevel;
  block[1].part.data = changer1.countryCurrencyCode[0];
  block[2].part.data = changer1.countryCurrencyCode[1];
  block[3].part.data = changer1.scaleFactor;
  block[4].part.data = changer1.decimalPlaces;
  block[5].part.data = changer1.coinTypeRouting[0];
  block[6].part.data = changer1.coinTypeRouting[1];
  block[7].part.data = changer1.coinTypeCredit[0];
  block[8].part.data = changer1.coinTypeCredit[1];
  block[9].part.data = changer1.coinTypeCredit[2];
  block[10].part.data = changer1.coinTypeCredit[3];
  block[11].part.data = changer1.coinTypeCredit[4];
  block[12].part.data = changer1.coinTypeCredit[5];
  block[13].part.data = changer1.coinTypeCredit[6];
  block[14].part.data = changer1.coinTypeCredit[7];
  block[15].part.data = changer1.coinTypeCredit[8];
  block[16].part.data = changer1.coinTypeCredit[9];
  block[17].part.data = changer1.coinTypeCredit[10];
  block[18].part.data = changer1.coinTypeCredit[11];
  block[19].part.data = changer1.coinTypeCredit[12];
  block[20].part.data = changer1.coinTypeCredit[13];
  block[21].part.data = changer1.coinTypeCredit[14];
  block[22].part.data = changer1.coinTypeCredit[15];
  pointer = 23;
  tX();
}

static int tubeStatus() {
  clearBlock();
  block[0].part.data = changer1.tubeFullStatus[0];
  block[1].part.data = changer1.tubeFullStatus[1];
  block[2].part.data = changer1.tubeStatus[0];
  block[3].part.data = changer1.tubeStatus[1];
  block[4].part.data = changer1.tubeStatus[2];
  block[5].part.data = changer1.tubeStatus[3];
  block[6].part.data = changer1.tubeStatus[4];
  block[7].part.data = changer1.tubeStatus[5];
  block[8].part.data = changer1.tubeStatus[6];
  block[9].part.data = changer1.tubeStatus[7];
  block[10].part.data = changer1.tubeStatus[8];
  block[11].part.data = changer1.tubeStatus[9];
  block[12].part.data = changer1.tubeStatus[10];
  block[13].part.data = changer1.tubeStatus[11];
  block[14].part.data = changer1.tubeStatus[12];
  block[15].part.data = changer1.tubeStatus[13];
  block[16].part.data = changer1.tubeStatus[14];
  block[17].part.data = changer1.tubeStatus[15];
  pointer = 18;
  tX();
}

static int poll() {
  if (changer1.coinsDispensedManually == '0x0') {
    clearBlock();
    counter = 0;
    do {
      block[counter].part.data = changer1.coinsDispensedManuallyData[counter];
      counter++;
      block[counter].part.data = changer1.coinsDispensedManuallyData[counter];
      counter++;
    } while (block[].part.data = changer1.coinsDepositedData[];)
    counter++;
    pointer = counter;
    tx();
    return 0;
  }
  else if (changer1.coinsDeposited == '0x0') {
    clearBlock();
    counter = 0;
    do {
      block[counter].part.data = changer1.coinsDepositedData[counter];
      counter++;
      block[counter].part.data = changer1.coinsDepositedData[counter];
      counter++;
    } while (block[].part.data = changer1.coinsDepositedData[];)
    counter++;
    pointer = counter;
    tx();
    return 0;
  }
  else if (changer1.status == '0x0') {
    clearBlock();
    counter = 0;
    if (changer1.escrowRequest = '0x0') {
      block[counter].part.data = changer.status.escrowRequest;
      counter++
    }
    if (changer1.changerPayoutBusy = '0x0') {
      block[counter].part.data = changer.status.changerPayoutBusy;
    }
    tX(counter);
    return 0;
  }
  else if (changer1.slug == '0x0') {
    clearBlock();
    block[0].part.data = changer1.slugs;
    pointer = 1;
    tX();
    return 0;
  }
  else if (changer1.ftlPolledResponse == '0x0') {

  }
  else
    block[0].part.data = ack;
    tX(1);
}

static int coinType() {

}

static int dispense() {
block[0].part.data = ack;
tx(1);
changer1.status = changer.status.payoutBusy;
}

static int expansion() {

}
