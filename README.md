# MDB-C
The goal of this project is to create an easy to use and abstract interface for the MDB/ICP (Version 4.2) communication protocol that is 'universal', in that it can be configured to be used to operate any MDB device.

Being an implementation of MDB (and DTS), tokens are named as closely as possible to those names used in the manuals, and the files are organized like the manuals.

Variables with "_f" appended mark that the variable is a flag.
Variables with "_C" appended mark that the variable is a configuration variable, set once prior to uploading code (i.e. Serial Number).
Variables with "_s" appended mark that the variable is a setting, set and reset as the device runs (i.e. enable/disable a feature).
Variables without anything appended, imply that the variable contains a value (i.e. The value of the last coin inserted).
Contants are taken care of by the pre-processor, and in all caps.


Work in progress.  No support for those trying to use (unless willing to help work out bugs & issues) until finished.
