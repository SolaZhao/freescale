# README.TXT


This project is a generic base for an HC12 Assembly project.

Folders used:
- Sources: contains your sources. It contains a 'main.asm' as a base.
- Debugger Cmd Files: Here you can place your own specific debugger command
  files.
- Prm: Linker parameter file used for linking. Note that this file is specified in 
  the Linker Preference Panel itself (<ALT-F7> or Edit->{Current Build Target Name} 
  settings, while the project window is opened).
- Debugger Project File: This *.ini file is passed to the debugger/simulator
  as configuration file. It contains various target interface settings, and path
  information as well. This file can be edited from the simulator/debugger e.g. using
  File->Configuration in the simulator/debugger.


Note that this project is set up for a simulator by default.
But you can easily change this to work with a target:
- launch the simulator/debugger using Project->Debug (while the current project window
  is opened)
- Choose in the simulator/debugger Component->Set Target and then choose a
  target interface
- Choose in the simulator/debugger File->Save Project so the new target
  settings are saved
  
This project is set for a simulator with a default parameter file (.prm).
Before building your project:
- you must choose the correct prm file in Target Settings Panel/Linker/Use template prm list
  to match your derivative.
- or modify the given project.prm file to match your derivative.

This project includes a burner command file (.bbl) in order to generate a 
SRecord file (.s19). Remove this file from prm folder if no SRecord is needed.

Metrowerks