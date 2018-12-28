extern ftlType ftl;  //Declare the FTL file here.
extern requestToSend();
extern okToSend();
extern sendBlock();
extern retryDeny();
extern reqToRcv();

extern typedef struct changerType {
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
      unsigned char sdePolledResponse FFFFFFFTTTTTTLLLLLLL STUFFFFFFF;
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
    } identification;
    struct {
      unsigned char command : 1 = 0x0f;
    } featureEnable;
    struct {
      unsigned char command : 1 = 0x02;
    } payout;
    struct {
      unsigned char command : 2 = 0x03;
    } payoutStatus;
    struct {
      unsigned char command : 3 = 0x04;
    } payoutValuePoll;
    struct {
      unsigned char command : 3 = 0x05;
      struct {
        unsigned char poweringUp[1] = {0x01, 0x00};
        unsigned char poweringDown[1] = {0x02, 0x00};
        unsigned char ok[1] = {0x03, 0x00};
        unsigned char keypadShifted[1] = {0x04, 0x00};
        unsigned char manualFillPayoutActive[1] = {0x05, 0x10};
        unsigned char newInventoryInformationAvailable[1] = {0x05, 0x20};
        unsigned char inhibitedByVMC[1] = {0x06, 0x00};
        struct {
          unsigned char command : 5 = 0x10;
          unsigned char nonSpecific : 1 = 0x00;
          unsigned char checksumErrorOne : 1 = 0x01;
          unsigned char checksumErrorTwo : 2 = 0x02;
          unsigned char lowLineVoltage : 2 = 0x03;
        } generalChangerError;
        struct {
          unsigned char command : 5 = 0x11;
          unsigned char nonSpecific : 1 = 0x00;
          unsigned char flightDeckOpen : 5 = 0x10;
          unsigned char escrowReturnStuckOpen : 5 = 0x11;
          unsigned char coinJamInSensor : 6 = 0x30;
          unsigned char discriminationBelowSpecifiedStandard : 7 = 0x41;
          unsigned char validationSensorAOutOfRange : 7 = 0x50;
          unsigned char validationSensorBOutOfRange : 7 = 0x51;
          unsigned char validationSensorCOutOfRange : 7 = 0x52;
          unsigned char operatingTemperatureExceeded : 7 = 0x53;
          unsigned char sizingOpticsFailure : 7 = 0x54;
        } discriminatorModuleError;
        struct {
          unsigned char command : 5 = 0x12;
          unsigned char nonSpecific : 1 = 0x00;
          unsigned char coinsStuck : 6 = 0x30;
          unsigned char acceptGateAlarmActive : 6 = 0x31;
          unsigned char acceptGateOpenButNoCoin : 7 = 0x40;
          unsigned char postGateSensedBeforeGateOpened : 7 = 0x50;
        } acceptGateModuleError;
        struct {
          unsigned char command : 5 = 0x13;
          unsigned char nonSpecific : 1 = 0x00;
          unsigned char sortSensor : 5 = 0x10;
        } separatorModuleError;
        struct {
          unsigned char command : 5 = 0x14;
          unsigned char nonSpecific : 1 = 0x00;
        } dispenserModuleError;
        struct {
          unsigned char command : 5 = 0x15;
          unsigned char nonSpecific : 1 = 0x00;
          unsigned char cassetteRemoved : 2 = 0x02;
          unsigned char cashBoxSensor : 2 = 0x03;
          unsigned char sunLightOnTubeSensors : 3 = 0x04;
        } coinCassetteTubeModuleError;
      } response;
    } sendDiagnosticStatus;
    struct {
      unsigned char command : 3 = 0x06;
    } sendControlledManualFillReport;
    struct {
      unsigned char command : 3 = 0x07;
    } sendControlledManualPayoutReport;
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
