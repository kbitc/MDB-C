# MDB-C
A transcription of the Multi Drop Bus protocol into C.

Initially (now if reading this) this is the raw format of my transcribing efforts to put the MDB protocol onto a microcontroller in C++.  Originally I was aiming for a cashless payment device as that was a short term project, but a long term project requires the entire protocol and full configurability as a VMC, which requires the entire protocol.  So, I am posting it here, tidying it up as this was my first programming project where I was googling how to program as I wrote it, and once it is prettied up, I will be expanding it until the code is finished.

Includes all options, version 1, 2, and 3.  I think there was a 2.5 too if I remember right.
Naming of variables and stuff tries to stay consistent with that used in the book.
Upper and lower case is used to differentiate between commands and categories, something like that.
More info later, I doubt anyone's reading yet.

Plans to transcribe into VHDL after this.

Each file is named after each section in the MDB protocol.


The VMC will send out Commands, these are high tier commands addressed to specific devices, what follows is either a subcommand or data if no subcommand is necessary (such as a reset command).  In header files, each device has nested structures where there is a main structure for the peripheral, a second tier of commands, a third tier containing the binary format of the command, as well as a third tier response structure which contains all of the allowed responses in binary format.  This organizes all binary values of commands, and by keeping names of commands consistent with the manual, each value is predictable.  This minimizes the amount of times the names of variables need to be looked up, makes code easy to read/understand.  There is also a rule where every command is named 'command' so no matter where you stop in the heirarhcy, you always end on 'command', this is not true for responses as there aren't heirarchial response options

'Cashless1.Setup.command' is references the binary value of an incoming setup command for Cashless1.
'Cashless1.Setup.configData.command' is references the binary value of an incoming configDatat subcommand for Cashless1.
'Cashless1.setup.configData.response.readerConfigData' is references the binary value of the response command.
 
 Addresses and commands for cashless devices are bitmasks for efficiency.  Will update this explanation later.
 
 
