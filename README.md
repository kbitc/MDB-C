# MDB-C
The end goal of this project is to create an easy to use and abstract interface for the MDB/ICP 3.0 communication protocol.

A better explanation/guide will be made once finished. Also, a goal once done is to make an interactive Q&A webpage where it will adjust the settings in all of the files you need, in a user friendly way.


The code:
Each MDB file is named after each section in the MDB manual.
Each variable and function tries to stick as closely to the wording used in the manual.
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
