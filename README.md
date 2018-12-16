# MDB-C
The end goal of this project is to create an easy to use and abstract interface for the MDB/ICP 3.0 communication protocol.

The code:
Each MDB file is named after each section in the MDB manual.
Each variable and function tries to stick as closely to the wording used in the manual.
 Each variable uses lowercase for the first character, then capitalized first letter of all words thereafter. i.e. 'helloWorld'
  Each variable is contained in a hierarchical structure, named (& numbered) after the peripherial/device the data relates to.
  Each constant is contained in a hierarchical structure named after the peripherial/device the data relates to.
   When accessing a COMMAND from a constants structure, the VALUE is always named 'command'.  i.e. 'cashless.poll.command'
    When accessing a RESPONSE to a COMMAND, the order is command.response.option.  i.e. 'cashless.poll.response.justReset'
     When accessing device addresses, the value given is a bitmask.
High level commands from the VMC are all uppercase functions.

Each peripherial has a management function that checks the block data.  If the data is addressed to the peripherial, it is identified and the corresponding function (named after the command) is called.
For interacting with the MDB bus, flag bits are available to be set within the users' code, and they will be acted upon at the next earliest convenience.  For example, if running a CashlessPaymentDevice, and you want to display a message on the screen, you would first load your message into the appropriate place, then set the 'cashless1.displayRequest = 0x0;' flag.  The appropriate function (in this case, the POLL function) will react at the next appropriate time.
