unsigned int counter, result, pointer;
unsigned char checksum, ack, ret, nak;
unsigned short txBypass; //Fixes tx() using nineBit datatype's read-only as a write method.
 //counter = A tracker for loops to define an endpoint with.
 //result = A non-volatile temporary storage variable for results of operations to be stored.  When calling a method and using the returned value from it, this makes checking the value more than once possible.
 //pointer = Points to the last byte in a data block to indicate when to stop transmitting or when the last recieved byte occurs within the block.
 //checksum = Calculated checksum for comparison with recieved checksum.
 //ack, ret, nak = Values of described command/value.
void serialEvent1();    //9 bit UART data recieved.
int rX();               //Recieves a byte, judges if it needs to recieve the rest of the data, and ends at appropriate time.  Returns status codes.
void clearBlock();      //Clear all communications related variables.
int tX();               //Send the data in the block, calculate and insert check byte into location of pointer, uness pointer is zero.  ALways sets mode bit on last byte.

union nineBit {             		  //Union allows writing mode and data bits simultaneously as a short, therefore not overwriting one another.  Bit format: dddddddd_______m
	struct {                    	  //Structure allows accessing 8 data bits and 1 mode bit separately, as well as setting the parent union's size.
		unsigned char data : 8;       //8 data bits dddddddd most significant byte when written to as a short..
		unsigned char mode : 1;       //1 mode bit  _______m least significant byte when written to as a short.
    } part;                 		  //Named for readability & organization of code.
    unsigned short whole;         //Allows writing the 'data' and 'mode' all at once, otherwise the second write would erase the first.
} block[35];                		  //Array of 9 bit data, 36 is the maximum amount of 'bytes' MDB allows per transmission.
unsigned char command : 3;        //Would be part of the 'block' union but must be a separate variable.
