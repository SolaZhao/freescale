# README.TXT

This project is a demo application showing various features of the checksum generation.

Folders used:
- Sources: contains a 'main.c' as with all the test/example code.
- Startup Code: Contains the startup code of the application. You may adapt it
  to your own needs, but in such a case make sure that you create a local copy.
- Prm: Linker parameter file used for linking. Note that the file used for the linker
  is specified in the Linker Preference Panel itself (<ALT-F7> or Edit->{Current Build Target Name} settings,
  while the project window is opened).
- Libs: contains the ANSI library to be linked with.
- Debugger Project File: This *.ini file is passed to the debugger/simulator
  as configuration file. It contains various target interface settings, and path
  information as well. This file can be edited from the simulator/debugger e.g. using
  File->Configuration in the simulator/debugger.

Note that this project is set up for a simulator only.
But you can  change this to work with a target:
- launch the simulator/debugger using Project->Debug (while
  the current project window is opened)
- Choose in the simulator/debugger Component->Set Target and then choose a
  target interface
- Choose in the simulator/debugger File->Save Project so the new target
  settings are saved
- adapt the prm file checksum.prm to fit your target.
- do adapt the main.c module, which contains some global addresses as well.

Please read the text at the top of main.c for details.


Metrowerks