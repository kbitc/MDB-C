# MDB-C
The end goal of this project is to create an easy to use and abstract interface for the MDB/ICP (Version 4.2) communication protocol.  The target hardware is any Arduino compatible device (defaulting on the ESP32), but the end goal is to complete this code and have it run on a linux system.  So, the language used should stick to C if it is not hardware/arduino specific code, to make the transition to linux (C only) easy.

Currently working devices:
*Cashless Payment Device

To use the software, take the source & header files for: "MDB_ESP32", "Bus_Timing", "Communication_Format", and "Cashless".  Also grab the "PreProcessors.h" file.  Slap em all into your Arduino IDE in different tabs named accordingly.  The "MDB_ESP32.c" file will get a .ino extension instead when used with arduino as the main function.  I don't yet have an abstract guide on interacting with the software, so you'll have to take a look at it.  In general, you interact by reading and writing to global status flags.  Flags are set in order to initiate an action or signal a condition to the other "side" (your side, and the MDB device's side).  If data needs to be passed along, data will be stored in the appropriate location prior to setting the flags.


The code is essentially a transcription of the manual, and so, it is both organized like the manual, and tokens are named as closely as possible to names used in the manual.

Each section of the MDB manual that is relevant to software, has its own file named after that section.
 In doing this, it is easy to follow along in the manual with the code.
 Each variable uses lowercase for the first character, then capitalized first letter of all words thereafter. i.e. 'helloWorld'
  Each variable is contained in a hierarchical structure, named (& numbered) after the peripherial/device the data relates to.
  Each constant is contained in a hierarchical structure named after the peripherial/device the data relates to.
   When accessing a COMMAND from a constants structure, the VALUE is always named 'command'.  i.e. 'cashless.poll.command'
    When accessing a RESPONSE to a COMMAND, the order is command.response.option.  i.e. 'cashless.poll.response.justReset'
     When accessing device addresses, the value given is a bitmask.
  Each variable associated with a peripheral is contained in a hierarchial structure named after the peripheral with a number appended to the end of it, which both differentiates it from the constants structure, as well as separates devices where there can be multiple instances of that kind of device (such as cashless payment devices, allowing up to 3 devices).
High level commands from the VMC are all their own functions/methods called when the VMC sends that command.
All interaction with the code (from your point of view) happens by setting and un-setting flags.  The code will check if flags are set and react to them at the next appropriate time.
 If data needs to be sent, data is loaded into the appropriate locations prior to setting the flag that indicates this data needs to be sent.

Each peripherial has a main() function that checks the block data.  If the data is addressed to the peripherial, it is identified and the corresponding function (named after the command) is called.  The main() function also loops through things checking flags and conditions, directing the flow of things.

There is a set of hardware functions/methods that begin with the word "hardware".  These will be loaded with a user's custom code that monitors their specific hardware's inputs/outputs and translates that into the flags used to interact with the MDB code, as well as translates flags into the mechanical device actuations that produce the desired result (with feedback).  In general, hardware functions are hardware specific, and I will write a better guide for that later on.
