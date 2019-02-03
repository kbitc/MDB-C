# MDB-C
The end goal of this project is to create an easy to use and abstract interface for the MDB/ICP (Version 4.2) communication protocol.  The target hardware is any Arduino compatible device (defaulting on the ESP32), but the end goal is to complete this code and have it run on a linux system.  So, the language used should stick to C if it is not hardware/arduino specific code, to make the transition to linux (C only) easy.

Currently working devices:
*Cashless Payment Device

To use the software, take the source & header files for: "MDB_ESP32", "Bus_Timing", "Communication_Format", and "Cashless".  Also grab the "PreProcessors.h" file.  Rename the 'Cashless.cpp' file to "Cashless2.cpp".  Slap em all into your Arduino IDE in different tabs named accordingly.  The "MDB_ESP32.c" file will get a .ino extension instead when used with arduino as the main function.  I don't yet have an abstract guide on interacting with the software, so you'll have to take a look at it for now.








The code is essentially a transcription of the manual, and so, it is both organized like the manual, and tokens are named as closely as possible to names used in the manual.

Each section of the MDB manual that is relevant to software, has its own file named after that section.
 Each subsection of each section, has its own code to go with it (in most cases).
 In doing this, it is easy to follow along in the manual with the code.
 
Each variable uses lowercase for the first character, then capitalized first letter of all words thereafter. i.e. 'helloWorld'
  Each variable is contained in a local hierarchical structure, named after the peripherial/device the data relates to.
   The one exception to this is the "block" structure, which is the "data block" for ALL MDB data on the MDB bus.
  Each constant is contained in the "PreProcessors.h" file, named like variables but all uppercase & underscores instead of dots/periods.
   When accessing a COMMAND from 'PreProcessors.h', the text "_COMMAND" is appended.  i.e. 'CASHLESS_POLL_COMMAND'
    When accessing a RESPONSE to a COMMAND, the order is COMMAND_RESPONSE_OPTION.  i.e. 'CASHLESS_POLL_RESPONSE_JUSTRESET'
     When accessing device addresses, "_ADDRESS" is appended.  i.e. 'CASHLESS_ADDRESS'
       The address is used as a bitmask within code.  The first/address byte from the VMC to any peripheral contains a command.
High level commands from the VMC are all their own functions/methods called when the VMC sends that command.  These are the commands that are send within an address byte to any peripheral.  These functions are all uppercase except for their first letter.  i.e. 'pOLL()'
 If data needs to be sent, data is loaded into the appropriate locations prior to setting the flag that indicates this data needs to be sent.  The command most likely to cause this data to be sent is the pOLL() command, which is called the next time the device receives a poll command from the VMC.

Each peripherial has a global main function (named and numbered after the device) that checks the local 'rxResult' value if incoming data is addressed to it.  If addressed, it calls the appropriate function, and the function(s) called take care of all communications necessary until the next break in the conversation between the VMC and Peripheral.  The main function also checks necessary flags, such as a reset flag, and checks for the appropriate functions to call (if any) before resetting the device.
