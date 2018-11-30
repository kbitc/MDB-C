# MDB-C
A transcription of the Multi Drop Bus protocol into C.

Initially (now if reading this) this is the raw format of my transcribing efforts to put the MDB protocol onto a microcontroller in C++.  Originally I was aiming for a cashless payment device as that was a short term project, but a long term project requires the entire protocol and full configurability as a VMC, which requires the entire protocol.  So, I am posting it here, tidying it up as this was my first programming project where I was googling how to program as I wrote it, and once it is prettied up, I will be expanding it until the code is finished.

Includes all options, version 1, 2, and 3.  I think there was a 2.5 too if I remember right.
Naming of variables and stuff tries to stay consistent with that used in the book.
Upper and lower case is used to differentiate between commands and categories, something like that.
More info later, I doubt anyone's reading yet.

Plans to transcribe into VHDL after this.

Each file is named after each section in the MDB protocol.
