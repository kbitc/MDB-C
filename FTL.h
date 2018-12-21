struct {
  unsigned char destinationAddress;
  unsigned char sourceAddress;
  unsigned char fileId;
  unsigned char maximumLength;
  unsigned char control;
  unsigned char blockNumber;
  unsigned char dataBlock[30];
  unsigned char dataBlockLength;
  unsigned char dataBlockCounter;
  unsigned char retryDelay;
  unsigned char okToSend;
  unsigned char blockCounter;
  struct {
    unsigned char reqToSend : 5 = 0x1f;
    unsigned char okToSend : 5= 0x1e;
    unsigned char sendBlock : 5 = 0x1d;
    unsigned char retryDeny : 5 = 0x1c;
    unsigned char reqToRcv : 5 = 0x1b;
  } peripheral;
  struct {
    unsigned char ftlResponse : 3 = 0x07;
    unsigned char reqToSend = 0xfe;
    unsigned char okToSend = 0xfd;
    unsigned char sendBlock = 0xfc;
    unsigned char retryDeny = 0xfb;
    unsigned char reqToRcv = 0xfa;
  } vmc;
} ftl;

static int requestToSend(unsigned int callingAddress) {
  clearBlock();
  if (callingAddress == '0x00') {
    block[0].part.data = (ftl.destinationAddress || ftl.vmc.ftlResponse);
    block[1].part.data = ftl.vmc.requestToSend;
    block[2].part.data = ftl.destinationAddress;
    block[3].part.data = ftl.sourceAddress;
    block[4].part.data = ftl.fileID;
    block[5].part.data = ftl.maximumLength;
    block[6].part.data = ftl.control;
    tX(7);
  }
  else {
    block[0].part.data = ftl.peripheral.requestToSend;
    block[1].part.data = ftl.destinationAddress;
    block[2].part.data = ftl.sourceAddress;
    block[3].part.data = ftl.fileID;
    block[4].part.data = ftl.maximumLength;
    block[5].part.data = ftl.control;
  }
}

static int okToSend() {
  if (callingAddress == '0x00') {
    block[0].part.data = (ftl.destinationAddress || 0x07);
    block[1].part.data = ftl.vmc.okToSend;
    tx(2);
  }
  else {
    clearBlock();
    block[0].part.data = ftl.vmcokToSend;
    tX(1);
  }
}

static int sendBlock() {
  ftl.blockCounter = 0x00;      //For the Blocks of data, 0-255
  ftl.dataBlockCounter = 0x00;  //For the Bytes of data within each block, 0-30
  if (callingAddress == '0x00') {
    do {
      block[0].part.data = (ftl.destinationAddress || ftl.vmc.ftlResponse);
      block[1].part.data = ftl.vmc.sendBlock;
      block[2].part.data = ftl.destinationAddress;
      block[3].part.data = ftl.blockCounter;
      do {
        block[ftl.blockCounter].part.data = ftl.dataBlock[ftl.blockCounter];
        ftl.blockCounter++;
      } while (ftl.dataBlockCounter != ftl.dataBlockLength);
    } while (ftl.blockCounter != ftl.maximumLength);
    if (tX(ftl.blockCounter = '0x00')
  }
  else {

  }
}

static int retryDeny() {
  if (callingAddress == '0x00') {

  }
  else {

  }
}

static int reqToRcv() {
  if (callingAddress == '0x00') {

  }
  else {

  }
}
