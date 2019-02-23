# MDB-C
The goal of this project is to create an easy to use and abstract interface for the MDB/ICP (Version 4.2) communication protocol.  The target hardware is any Arduino compatible device (defaulting on the ESP32), but the end goal is to complete this code and have it run on a linux system.  So, the language used should stick to C if it is not hardware/arduino specific code, to make the transition to linux (C only) easy.

This code started out as a cashless payment device only, and has been repurposed into a full configurable genera MDB project.  So the cashless payment device is currently in transition from the old code that worked, to the new format.  The first priority for getting working code, is the Coin changer, and then the VMC supporting the coin changer.  At this point, the code can be tested against itself.  Next will be the Bill Acceptor, and then the Cashless Payment Device, then the rest.  FTL support can be added in any time after the coin changer file, it is used to send files between MDB devices.  EVA-DTS support should be added directly after the Coin Changer file, it is used both to define how data is saved as a file, and how to transmit it out of an MDB system, to something like an auditing device.

The code is essentially a transcription of the manual, and so, it is both organized like the manual, and tokens are named as closely as possible to names used in the manual.

Variables with "_f" appended mark that the variable is a flag.
Variables with "_C" appended mark that the variable is a configuration variable, set once prior to uploading code (i.e. Serial Number).
Variables with "_s" appended mark that the variable is a setting, set and reset as the device runs (i.e. enable/disable a feature).
Variables without anything appended, imply that the variable contains a value (i.e. The value of the last coin inserted).
Contants are taken care of by the pre-processor, and in all caps.

Each section of the MDB manual that is relevant to software, has its own file named after that section.
 Each subsection of each section, has its own code to go with it (in most cases).
 In doing this, it is easy to follow along in the manual with the code.
