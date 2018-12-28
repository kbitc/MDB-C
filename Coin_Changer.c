#include "Coin_Changer.h"
#include "Communication_Format.c"

struct {
  String ;
  unsigned char address = 0x08;                    //5.1
  //SETUP VARIABLES
    //Setup 5.4
    unsigned char vmcFeatureLevel : 2;
    unsigned char changerFeatureLevel : 2;
    unsigned char countryCurrencyCode[1];			//Page 61.
    unsigned char scaleFactor;
    unsigned char decimalPlaces;
    unsigned char coinTypeRouting[1];         //Read-Only routing.
    unsigned char coinTypeCredit[15];         //Read-Only credit values.
    unsigned char coin[15];                   //Enable a coin by loading its value.  Set to zero if disabled.
    unsigned char coinsFilled[15];            //Stores the number of undisclosed controlled-manually-filled coins.
    unsigned char coinsPaid[15];               //Stores the number of undisclosed dispensed coins for each type.
    unsigned char payoutValue;                //Stores the net scaled value of undisclosed dispensed coins;
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
    unsigned char isBusy : 1;
    unsigned char wasReset : 1;
    unsigned char coinJam : 1;
    unsigned char possibleCreditedCoinRemoval :1;

    unsigned char manufacturerCode[2];
    unsigned char serialNumber[11];
    unsigned char modelNumber[11];
    unsigned char softwareVersion[1];
    unsigned char optionalFeatureBits;

    //5.11-5.12
    unsigned char alternativePayoutMethodSupported : 1;
    unsigned char extendedDiagnosticCommandSupported : 1;
    unsigned char controlledManualFillPayoutSupported : 1;
    unsigned char ftlSupported : 1;



    //Poll.revalueDenied or Approved or limitAmount.  Page 71-73
    //Poll.userFileData Page 73 OBSOLETE
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

//FLAGS
    unsigned char errors : 1;         //Set if ANY other error flag is set, so we only need to check this one when none are set.
    unsigned char cmdOutOfSequence : 1;
    unsigned char justReset : 1;
    unsigned char reqToRcv : 1;
    unsigned char reqToSend : 1;
    unsigned char retryDeny : 1;
    unsigned char sendBlock : 1;
    unsigned char okToSend : 1;
    unsigned char configData : 1;
    unsigned char diagnosticResponse : 1;
  	unsigned char isResetting : 1;
    unsigned char powerOn : 1 = 0x1;    //Always set when powered on initially.
} changer1;                                    //Variables


main() {
  if (changer1.error) {
    hardwareError();
  }
  if (changer1.payout) {
    counter = 15;
    do {
        if (payoutValue > changer1.coin[counter])
          payoutValue -= hardwareDispense(changer1.coin[counter];
        counter--;
    } while (payoutValue | counter)
  }
  if (changer1.isOutgoing) {
    poll();
  }
}

static int hardwareOutput(unsigned char coinType) {
  //Insert hardware control code to dispense coin.
  //Also add code to monitor sensors and update info as needed.
  //return 0 for success, or a status/error.
}

static int hardwareInput() {

}

static int hardwareError(unsigned char error) {
  //Hardware error handler.  Sets flags when errors are found, and this will be called.
  }

static int hardwareReset() {
  changer1.isResetting = 0x1;
  changer1.commandOutOfSequence = 0x0;

  changer1.status = 0x1;          //Sets the flag for the Just Reset response.
  changer1.changerWasReset = 0x1;
  changer1.isResetting = 0x0;
}

static int hardwareConfigure() {
  //Settings & Configuration
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
  result = tX(23);
  return result;
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
  result = tX(18);
  return result;
}

static int poll() {
  if (changer1.coinsDispensedManually) {
    clearBlock();
    counter = 0;
    do {
      block[counter].part.data = changer1.coinsDispensedManuallyData[counter];
      counter++;
      block[counter].part.data = changer1.coinsDispensedManuallyData[counter];
      counter++;
    } while (block[].part.data = changer1.coinsDepositedData[];)
    counter++;
    result = tx(counter);
    return result;
  }
  else if (changer1.coinsDeposited) {
    clearBlock();
    counter = 0;
    do {
      block[counter].part.data = changer1.coinsDepositedData[counter];
      counter++;
      block[counter].part.data = changer1.coinsDepositedData[counter];
      counter++;
    } while (block[].part.data = changer1.coinsDepositedData[];)
    counter++;
    result = tx(counter);
    return result;
  }
  else if (changer1.status) {
    clearBlock();
    counter = 0;
    if (changer1.escrowRequest) {
      block[counter].part.data = changer.status.escrowRequest;
      counter++;
    }
    if (changer1.noCredit) {
      block[counter].part.data = changer.status.noCredit;
      counter++;
    }
    if (changer1.defectiveTubeSensor) {
      block[counter].part.data = changer.status.defectiveTubeSensor;
      counter++;
    }
    if (changer1.doubleArrival) {
      block[counter].part.data = changer.status.doubleArrival;
      counter++;
    }
    if (changer1.tubeJam) {
      block[counter].part.data = changer.status.tubeJam;
      counter++;
    }
    if (changer1.romChecksumError) {
      block[counter].part.data = changer.status.romChecksumError;
      counter++;
    }
    if (changer1.coinRoutingError) {
      block[counter].part.data = changer.status.coinRoutingError;
      counter++;
    }
    if (changer1.changerWasReset) {
      block[counter].part.data = changer.status.changerWasReset;
      counter++;
    }
    if (changer1.coinJam) {
      block[counter].part.data = changer.status.coinJam;
      counter++;
    }
    changer1.status = 0x0;
    if (changer1.possibleCreditedCoinRemoval) {
      block[counter].part.data = changer.status.possibleCreditedCoinRemoval;
      counter++;
      changer1.status = 0x1;
    }
    if (changer1.changerPayoutBusy) {
      block[counter].part.data = changer.status.changerPayoutBusy;
      counter++;
      changer1.status = 0x1;
    }
    if (changer1.acceptorUnplugged) {
      block[counter].part.data = changer.status.acceptorUnplugged;
      counter++;
      chanager1.status = 0x1;
    }
    if (changer1.changerBusy) {
      block[counter].part.data = changer.status.changerBusy;
      counter++;
      changer1.status = 0x1;
    }
    result = tX(counter);
    if (result) {
      changer1.noCredit = 0x0;
      changer1.defectiveTubeSensor = 0x0;
      changer1.doubleArrival = 0x0;
      changer1.tubeJam = 0x0;
      changer1.romChecksumError = 0x0;
      changer1.coinRoutingError = 0x0;
      changer1.changerWasReset = 0x0;
      changer1.coinJam = 0x0;
    }
    return result;
  }
  else if (changer1.slug) {
    clearBlock();
    block[0].part.data = (changer1.numberOfSlugs | 0x20);
    result = tX(1);
    return result;
  }
  else if (changer1.ftlPolledResponse) {
    if (changer1.reqToRcv) {
      result = reqToRcv(changer1.address);
      if (result == 0x1)
        changer1.reqToRcv = 0x0;
      return result;
    }
    else if (changer1.retryDeny) {
      result = retryDeny(changer1.address);
      if (result == 0x1)
        changer1.retryDeny = 0x0;
      return result;
    }
    else if (changer1.sendBlock) {
      result = sendBlock(changer1.address);
      if (result == 0x1)
        changer1.sendBlock = 0x0;
      return result;
    }
    else if (changer1.okToSend) {
      result = okToSend(changer1.address);
      if (result == 0x1)
        changer1.okToSend = 0x0;
      return result;
    }
    else if (changer1.reqToSend) {
      result = reqToSend(changer1.address);
      if (result == 0x1)
        changer1.reqToSend = 0x0;
      return result;
    }
  }
  else
    block[0].part.data = ack;
    result = tX(0);
    return result;
}

static void coinType() {
changer1.coinEnable[0] = block[1].part.data;
changer1.coinEnable[2] = block[2].part.data;
changer1.manualDispenseEnable[0] = block[3].part.data;
changer1.manualDispenseEnable[1] = block[4].part.data;
clearBlock();
if (changer1.coinEnable[2] & 0x80)
  coin[15] = changer1.coinTypeCredit[15];
if (changer1.coinEnable[2] & 0x40)
  coin[14] = changer1.coinTypeCredit[14];
if (changer1.coinEnable[2] & 0x20)
  coin[13] = changer1.coinTypeCredit[13];
if (changer1.coinEnable[2] & 0x10)
  coin[12] = changer1.coinTypeCredit[12];
if (changer1.coinEnable[2] & 0x08)
  coin[11] = changer1.coinTypeCredit[11];
if (changer1.coinEnable[2] & 0x04)
  coin[10] = changer1.coinTypeCredit[10];
if (changer1.coinEnable[2] & 0x02)
  coin[9] = changer1.coinTypeCredit[9];
if (changer1.coinEnable[2] & 0x01)
  coin[8] = changer1.coinTypeCredit[8];
if (changer1.coinEnable[2] & 0x80)
  coin[7] = changer1.coinTypeCredit[7];
if (changer1.coinEnable[2] & 0x40)
  coin[6] = changer1.coinTypeCredit[6];
if (changer1.coinEnable[2] & 0x20)
  coin[5] = changer1.coinTypeCredit[5];
if (changer1.coinEnable[2] & 0x10)
  coin[4] = changer1.coinTypeCredit[4];
if (changer1.coinEnable[2] & 0x08)
  coin[3] = changer1.coinTypeCredit[3];
if (changer1.coinEnable[2] & 0x04)
  coin[2] = changer1.coinTypeCredit[2];
if (changer1.coinEnable[2] & 0x02)
  coin[1] = changer1.coinTypeCredit[1];
if (changer1.coinEnable[2] & 0x01)
  coin[0] = changer1.coinTypeCredit[0];
return changer1.coinEnable;  //Returns 0 if changer is to be disabled.
}

static int dispense() {
result = hardwareDispense(block[1].part.data);  //Call function to dispense coin.
if (result = changer.status.defectiveTubeSensor)
  changer1.defectiveTubeSensor = 0x1;
else if (result = changer.status.tubeJam)
  changer1.tubeJam = 0x1;
clearBlock();
block[0].part.data = ack;
result = tx(0);
return result;
}

static int expansion() {
  clearBlock();
  if (block[1].part.data == changer.expansion.identification.command) {
  block[0].part.data = changer1.manufacturerCode[0];
  block[1].part.data = changer1.manufacturerCode[1];
  block[2].part.data = changer1.manufacturerCode[2];
  block[3].part.data = changer1.serialNumber[0];
  block[4].part.data = changer1.serialNumber[1];
  block[5].part.data = changer1.serialNumber[2];
  block[6].part.data = changer1.serialNumber[3];
  block[7].part.data = changer1.serialNumber[4];
  block[8].part.data = changer1.serialNumber[5];
  block[9].part.data = changer1.serialNumber[6];
  block[10].part.data = changer1.serialNumber[7];
  block[11].part.data = changer1.serialNumber[8];
  block[12].part.data = changer1.serialNumber[9];
  block[13].part.data = changer1.serialNumber[10];
  block[14].part.data = changer1.serialNumber[11];
  block[15].part.data = changer1.modelNumber[0];
  block[16].part.data = changer1.modelNumber[1];
  block[17].part.data = changer1.modelNumber[2];
  block[18].part.data = changer1.modelNumber[3];
  block[19].part.data = changer1.modelNumber[4];
  block[20].part.data = changer1.modelNumber[5];
  block[21].part.data = changer1.modelNumber[6];
  block[22].part.data = changer1.modelNumber[7];
  block[23].part.data = changer1.modelNumber[8];
  block[24].part.data = changer1.modelNumber[9];
  block[25].part.data = changer1.modelNumber[10];
  block[26].part.data = changer1.modelNumber[11];
  block[27].part.data = changer1.softwareVersion[0];
  block[28].part.data = changer1.softwareVersion[1];
  block[29].part.data = changer1.optionalFeatureBits[0];
  block[30].part.data = changer1.optionalFeatureBits[1];
  block[31].part.data = changer1.optionalFeatureBits[2];
  block[32].part.data = changer1.optionalFeatureBits[3];
  result = tX(33);
  return result;
  }
  else if (block[1].part.data == changer.expansion.featureEnable.command) {
    changer1.optionalFeatureEnabled[0] = block[3].part.data;
    changer1.optionalFeatureEnabled[1] = block[4].part.data;
    changer1.optionalFeatureEnabled[2] = block[5].part.data;
    changer1.optionalFeatureEnabled[3] = block[6].part.data;
    clearBlock();
    if (changer1.optionalFeatureEnabled[3] & 0x01)
      changer1.alternativePayoutMethodSupported = 0x1;
    if (changer1.optionalFeatureEnabled[3] & 0x02)
      changer1.extendedDiagnosticCommandSupported = 0x1;
    if (changer1.optionalFeatureEnabled[3] & 0x04)
      changer1.controlledManualFillPayoutSupported = 0x1;
    if (changer1.optionalFeatureEnabled[3] & 0x08)
      changer1.ftlSupported = 0x01;
    return 0;
  }
  else if (block[1].part.data == changer.expansion.payout.command) {
    unsigned char payoutValue;
    payoutValue = block[2].part.data;
    changer1.payout = 0x1;            //Set the flag for payout rather than hang up the processor waiting on payout confirmation.
  }
  else if (block[1].part.data == changer.expansion.payoutStatus.command) {
    counter = 0;
    while (counter != 16) {
      block[counter].part.data = changer1.coinsPaid[counter];
      counter++;
    }
    if (tX(counter) == 1) {
      counter = 0;
      while (counter != 16) {
        changer1.coinsPaid[counter] = 0;
        counter++;
      }
      return 0;
    }
    return 1;
  }
  else if (block[1].part.data == changer.expansion.payoutValuePoll.command) {
    block[0].part.data = changer1.payoutValue;
    if (tX(1))
      return 0;
    else return 1;
  }
  else if (block[1].part.data == changer.expansion.sendDiagnosticStatus.command) {
    block[0].part.data = changer1.diagnosticStatus[0];
    block[1].part.data = changer1.diagnosticStatus[1];
    if (tX(2))
      return 0;
    else return 1;
  }
  else if (block[1].part.data == changer.expansion.sendControlledManualFillReport.command) {
    counter = 0;
    while (counter != 16) {
      block[counter].part.data = changer1.coinsFilled[counter];
      counter++;
    }
    if (tX(counter))
      return 0;
    else return 1;
  }
  else if (block[1].part.data == changer.expansion.sendControlledManualPayoutReport.command) {
    counter = 0;
    while (counter != 16) {
      block[counter].part.data = changer1.coinsPaid[counter];
      counter++;
    }
    if (tX(counter))
      return 0;
    else return 1;
  }
  else if (block[1].part.data == changer.expansion.diagnostics.command) {
    //No Use of Diagnostic Command.  5.23
    return 0;
  }
  else if (block[1].part.data == ftl.reqToRcv.command) {
    extern ftl.initiating = 0x0;
    reqToRcv(changer1.address);
  }
  else if (block[1].part.data == ftl.retryDeny.command) {
    extern ftl.initiating = 0x0;
    retryDeny(changer1.address);
  }
  else if (block[1].part.data == ftl.sendBlock.command) {
    extern ftl.initiating = 0x0;
    sendBlock(changer1.address);
  }
  else if (block[1].part.data == ftl.okToSend.command) {
    extern ftl.initiating = 0x0;
    okToSend(changer1.address);
  }
  else if (block[1].part.data == ftl.reqToSend.command) {
    extern ftl.initiating = 0x0;
    reqToSend(changer1.address);
  }
}
