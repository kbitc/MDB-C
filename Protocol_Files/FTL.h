#ifndef FTL_HEADER
#define FTL_HEADER

typedef struct ftlType {
	unsigned char destinationAddress;
	unsigned char sourceAddress;
	unsigned char fileId;
	unsigned char maximumLength;
	unsigned char control;
	unsigned char blockNumber;
	unsigned char dataBlock[30];
	unsigned char finalBlockLength;//Length of the final data block;
	unsigned char retryDelay;
	unsigned char okToSend;
	unsigned char initiate : 1;//Flag set if function is initiating said command, rather than responding to it.
	struct {
		struct {
			unsigned char command : 5 = 0x1f;
			} reqToSend;
		struct {
			unsigned char command : 5= 0x1e;
		} okToSend;
		struct {
			unsigned char command : 5 = 0x1d;
		} sendBlock;
		struct {
			unsigned char command : 5 = 0x1c;
		} retryDeny;
		struct{
			unsigned char command : 5 = 0x1b;
		} reqToRcv;
	} peripheral;
	struct {
		struct {
			unsigned char command = 0x07;
		} ftlResponse;
		struct {
			unsigned char command = 0xfe;
		} reqToSend;
		struct {
			unsigned char command = 0xfd;
		} okToSend;
		struct {
			unsigned char command = 0xfc;
		} sendBlock;
		struct {
			unsigned char command = 0xfb;
		} retryDeny;
		struct{
			unsigned char command = 0xfa;
		} reqToRcv;
	} vmc;
} ftl;

int requestToSend(uint8_t callingAddress, unsigned char input) {
clearBlock();
if (callingAddress == '0x00') {
block[0].part.data = (ftl.destinationAddress | ftl.vmc.ftlResponse);
block[1].part.data = ftl.vmc.requestToSend;
block[2].part.data = ftl.destinationAddress;
block[3].part.data = ftl.sourceAddress;
block[4].part.data = ftl.fileID;
block[5].part.data = ftl.maximumLength;
block[6].part.data = ftl.control;
result = tX(7);
return result;
}
else {
block[0].part.data = ftl.peripheral.requestToSend;
block[1].part.data = ftl.destinationAddress;
block[2].part.data = ftl.sourceAddress;
block[3].part.data = ftl.fileID;
block[4].part.data = ftl.maximumLength;
block[5].part.data = ftl.control;
result = tX(6);
return result;
}
}

int okToSend() {
if (callingAddress == '0x00') {
block[0].part.data = (ftl.destinationAddress | 0x07);
block[1].part.data = ftl.vmc.okToSend;
tx(2);
}
else {

}
}

int sendBlock() {
if (callingAddress == '0x00') {
do {
block[0].part.data = (ftl.destinationAddress | ftl.vmc.ftlResponse);
block[1].part.data = ftl.vmc.sendBlock;
block[2].part.data = ftl.destinationAddress;
block[3].part.data = ftl.blockCounter;
do {
block[ftl.blockCounter].part.data = ftl.dataBlock[ftl.blockCounter];
ftl.blockCounter++;
} while (ftl.dataBlockCounter != ftl.dataBlockLength)
} while (ftl.blockCounter != ftl.maximumLength)
if (tX(ftl.blockCounter = '0x00')
}


else {
clearBlock();
block[0].part.data = ftl.peripheral.sendBlock;
block[1].part.data = ftl.destinationAddress;
block[2].part.data = ftl.blockNumber;
counter = 0;
while ((counter != 31) && (ftl.maximumLength != ftl.blockNumber || ftl.finalBlockLength != counter) {
block[counter + 3].part.data = ftl.dataBlock[counter];
counter++;
}
return tX(counter + 4);
}
}
}

int retryDeny() {
if (callingAddress == '0x00') {

}
else {

}
}

int reqToRcv(unsigned char callingAddress, unsigned char input) {
if (callingAddress == '0x00') {
	/*#FIXDIS*/
}
else {
/*if (ftl.initiate) {
ftl.initiate = 0x0;
}*/
else {

	block[0].whole = CASHLESS_POLL_RESPONSE_REQTORCV;
	block[1].whole = cashless.ftlDestinationAddress;
	block[2].whole = cashless.address;
	block[3].whole = cashless.ftlFileID;
	block[4].whole = cashless.ftlMaximumLength;
	block[5].whole = cashless.ftlControl;
	tX(6, cashless.address);
if (block[2].part.data != callingAddress)
	return 1; //If the command is not intended for this device (within FTL Scope).
b = callingAddress; //Set the source address (for the reply).
ftl.destinationAddress = block[3].part.data;//The source of this command becomes the destination.
ftl.fileID = block[4].part.data;
ftl.maximumLength = block[5].part.data;
ftl.control = block[6].part.data;
ftl.blockNumber = 0x00; //Set to zero for the File Loader method.
while (ftl.maximumLength >= ftl.blockNumber) {
fileLoader();
sendBlock();
ftl.blockNumber++;
}
}
}
}

int fileLoader() {
//File management stuffs.Take the file ID and block number.Fill the block with the matching info.
}

#endif /* FTL_HEADER */
