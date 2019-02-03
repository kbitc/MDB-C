#ifndef CASHLESS_HEADER
#define CASHLESS_HEADER

#include <Arduino.h>
#include "PreProcessors.h"
#include "Communication_Format.h"

extern void resetCashless(int n);

extern int beginSession(String data);

extern int sessionCancelRequest(String data);

extern int vendApproved(String data);

extern int vendDenied(String data);

extern int displayRequest(String data);

extern int displayCancel(String data);


extern void rESET(int n);

extern void pOLL(int n);

extern void sETUP(int n);

extern void vEND(int n);

extern void rEADER(int n);

extern void rEVALUE(int n);

extern void nEGATIVEVEND(int n);

extern void eXPANSION(int n);
/*
//Cashless1 is meant for card based deives. I.E. a credit card.
void startCashless(char n) {
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
    cashless.displayTime = 0xaa;            //Time unit is 0.1 seconds.
    cashless.displayData[0] = 0x01;         //The product of these two must equal the lenght of the message.
    cashless.displayData[1] = 0x0a;         //The product of these two must equal the length of the message.
    cashless.displayData[2] = 0x4b;
    cashless.displayData[3] = 0x49;         //ASCII characters. 4b 49 4c 4c 48 55 4d 41 4e 53
    cashless.displayData[4] = 0x4c;         //                  K  I  L  L  H  U  M  A  N  S
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
//Cashless2 is meant for mobile phone based devices.
void cashless2Settings() {
    cashless2.address = cashless.card2;
    //For Setup - Config Data.
    cashless2.readerFeatureLevel = 0x03;
    cashless2.countryCurrencyCode[0] = 0x00;
    cashless2.countryCurrencyCode[1] = 0x01;         //Telephone code for usa.
    cashless2.countryCurrencyCodeLevel3[0] = 0x18;
    cashless2.countryCurrencyCodeLevel3[1] = 0x40;   //Level 3 code for USA
    cashless2.scaleFactor = 0x01;  //Pennies
    cashless2.decimalPlaces = 0x02;  //Murica.
    cashless2.applicationMaximumResponseTime = 0x00; //Default.
    cashless2.miscellaneousOptions = 0x01;  //Bit descriptions (n/a) (n/a) (n/a) (n/a) (refunds) (multivend-capability) (hasDisplay) (Vend/Cash tracking)
    //For Expansion - PeripheralID.
    cashless2.optionalFeatureBits[0] = 0x00;  //Not used
    cashless2.optionalFeatureBits[1] = 0x00;  //Not used
    cashless2.optionalFeatureBits[2] = 0x00;  //Not used
    cashless2.optionalFeatureBits[3] = 0x04;  //Bit descriptions (n/a) (n/a) (Always Idle) (Data Entry) (Negative Vend) (Multi-Currency/Lingual Support) (16 or 32 bit Monetary Format) (FTL Supported)
    cashless2.readerSerialNumber[0] = 0x00;
    cashless2.readerSerialNumber[1] = 0x00;
    cashless2.readerSerialNumber[2] = 0x00;
    cashless2.readerSerialNumber[3] = 0x00;
    cashless2.readerSerialNumber[4] = 0x00;
    cashless2.readerSerialNumber[5] = 0x00;
    cashless2.readerSerialNumber[6] = 0x00;
    cashless2.readerSerialNumber[7] = 0x00;
    cashless2.readerSerialNumber[8] = 0x00;
    cashless2.readerSerialNumber[9] = 0x00;
    cashless2.readerSerialNumber[10] = 0x00;
    cashless2.readerSerialNumber[11] = 0x00;  //Your very own serial number.
    cashless2.readerModelNumber[0] = 0x00;
    cashless2.readerModelNumber[1] = 0x00;
    cashless2.readerModelNumber[2] = 0x00;
    cashless2.readerModelNumber[3] = 0x00;
    cashless2.readerModelNumber[4] = 0x00;
    cashless2.readerModelNumber[5] = 0x00;
    cashless2.readerModelNumber[6] = 0x00;
    cashless2.readerModelNumber[7] = 0x00;
    cashless2.readerModelNumber[8] = 0x00;
    cashless2.readerModelNumber[9] = 0x00;
    cashless2.readerModelNumber[10] = 0x00;
    cashless2.readerModelNumber[11] = 0x00;  //Your very own model number.
    //For display request
    cashless2.displayTime = 0xaa;            //Time unit is 0.1 seconds.
    cashless2.displayData[0] = 0x01;         //The product of these two must equal the lenght of the message.
    cashless2.displayData[1] = 0x0a;         //The product of these two must equal the length of the message.
    cashless2.displayData[2] = 0x4b;
    cashless2.displayData[3] = 0x49;         //ASCII characters. 4b 49 4c 4c 48 55 4d 41 4e 53
    cashless2.displayData[4] = 0x4c;         //                  K  I  L  L  H  U  M  A  N  S
    cashless2.displayData[5] = 0x4c;
    cashless2.displayData[6] = 0x48;
    cashless2.displayData[7] = 0x55;
    cashless2.displayData[8] = 0x4d;
    cashless2.displayData[9] = 0x41;
    cashless2.displayData[10] = 0x4e;
    cashless2.displayData[11] = 0x53;
    cashless2.displayData[31] = 0xff;
    //For Begin Session
    cashless2.fundsAvailable[0] = 0xff;          //Scaled, set to 0xffff if unknown.
    cashless2.fundsAvailable[1] = 0xfe;
        cashless2.paymentMediaID[0] = 0xff;      //Set to 0xffffffff if unknown.
        cashless2.paymentMediaID[1] = 0xff;
        cashless2.paymentMediaID[2] = 0xff;
        cashless2.paymentMediaID[3] = 0xff;
        cashless2.paymentType = 0x40;            //Test Vend.
        cashless2.paymentData[0] = 0x00;
        cashless2.paymentData[1] = 0x00;
            cashless2.userLanguage[0] = 0x00;
            cashless2.userLanguage[1] = 0x00;
            cashless2.userCurrencyCode[0] = 0x00;
            cashless2.userCurrencyCode[1] = 0x00;
            cashless2.cardOptions = 0x00;
}


/*
Options
Devices used
cashless1.readerFeatureLevel = 0x03;          //Set to 1, 2, or 3.  Page59.
cashless1.countryCurrencyCode[0] = 0x00;
cashless1.countryCurrencyCode[1] = 0x01;      //Telephone Code.  Page59
cashless1.countryCurrencyCodeLevel3[0] = 0x18;
cashless1.countryCurrencyCodeLevel3[1] = 0x40;       //ISO4217 codes.  Page59-60, Appendix-A1 on Page
cashless1.scaleFactor = 0x05;
cashless1.decimalPlaces = 0x02;
cashless1.applicationMaximumResponseTime = 0x01;    //Page 60, in seconds.
cashless1.miscellaneousOptions = (
0x00
|| 0x01       //Comment out this line if refunds are unsupported.
|| 0x02       //Comment out this line if multivend is unsupported.
|| 0x04       //Comment out this line if cashless device has no display.
|| 0x08       //Comment out this line if uninterested in CashSale reporting.
);              //Page 60.  XXXXABCD
*/

/*
Power
Change money/time/feature-level/response-time/Options
Request to display message
Get selection, approve/deny vend, negative vend,
Data Entry

*/

#endif
