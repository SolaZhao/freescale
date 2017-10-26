# README.TXT

This project is na HC12 ANSI-C++ project.

Folders used:
- Sources: contains your sources. It contains a 'simple.cpp' as a base.
- Debugger Cmd Files: Here you can place your own specific debugger command
  files.
- Startup Code: Contains the startup code of the application. You may adapt it
  to your own needs, but in such a case make sure that you create a local copy.
- Prm: Linker parameter file used for linking. Note that the file used for the linker
  is specified in the Linker Preference Panel itself (<ALT-F7> or Edit->{Current Build Target Name} settings,
  while the project window is opened).
- Libs: contains the ANSI and CPP libraries to be linked with.
- Debugger Project File: This *.ini file is passed to the debugger/simulator
  as configuration file. It contains various target interface setttings, and path
  information as well. This file can be edited from the simulator/debugger e.g. using
  File->Configuration in the simulator/debugger.


Note that this project is set up for a simulator by default.
But you can easily change this to work with a target:
- launch the simulator/debugger using Project->Debug (while
  the current project window is opened)
- Choose in the simulator/debugger Component->Set Target and then choose a
  target interface
- Choose in the simulator/debugger File->Save Project so the new target
  settings are saved

This project includes a burner command file (.bbl) in order to generate a 
SRecord file (.s19). Remove this file from prm folder if no SRecord is needed.

Metrowerks