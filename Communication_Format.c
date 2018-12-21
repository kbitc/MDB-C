#include "Communication_Format.h"
#include "Bus_Timing.cpp"

int rX() {                                          //1=ACK, 2=NAK, 3=RET, 4=NO-RESPONSE, 5=Ignored, 6=OK!
    clearBlock();
    while (!Serial1.available()) {                  //Wait for first byte.
        chronoLogic(1);                             //Update timing flags.
        if (transmission.isUnresponsive)            //Chec if time is up.
            return 4;                               //Return status that time is up if so.
    }
    block[counter].whole = Serial1.read();          //Get first byte.
    command = block[0].part.data;
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
    command = 0x0;
    checksum = 0x00;
}

int tX(unsigned int pointer) {
    counter = 0;
    checksum = 0x00;
    while (pointer != counter) {
    Serial1.write(block[counter].whole);
    checksum += block[counter].part.data;     //Add on to the checksum byte.
    counter++;
    Serial1.flush();                        //Wait for information to finish sending, placed here so previous commands execute prior to any waiting time.
    }
    //block[counter].part.data +- checksum;   //Add to the checksum, doesn't affect ACK or NAK, but requires a block with no extra data other than what's sent, prior to calling tX().
    //block[counter].part.mode = 0x01;        //Add a mode bit to the checksum.
    txBypass = block[counter].part.data + checksum;  //Replacing the above two uncommented parts.
    txBypass << 8;                            //Replacing the above two uncommented parts.
    txBypass++;                               //Replacing the above two uncommented parts.
    Serial1.write(txBypass);
    chronoLogic(0);                         //Set non-response timer.
    result = rX();
    if ((result == 1) || (result == 2) || (result == 4))
        clearBlock();
    return result;
}
