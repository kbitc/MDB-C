#include "Cashless.h"
#include "Communication_Format.cpp"

/*
void main() {  //Place in your code on a loop to run the cashless device.
    if (cashless.state == cashless.stateInactive) {
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
*/

void resetPeripheral() {                       //Reset flags and other nonessential values.
	cashless.displayRequest = 0x0;               //Flag for when you have info to display on the vending screen.
	cashless.beginSession = 0x00;                 //Flag for when you want to begin a session with the VMC.  Page 15.
	cashless.sessionCancelRequest = 0x00;         //Flag to set if you want to cancel an active session.
    cashless.cmdOutOfSequence = 0x00;             //Self explanatory flag.
    cashless.state = cashless.stateInactive;
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
