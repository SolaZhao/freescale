# README.TXT

This project is a advanced demo application showing how to have one "loader" application checking the checksum of another.

The "How to run this example:" description below explains how to run this example and it 
should be read carefully as running this example is not trivial.
Please also read the text at the top of main.c for a checksum feature description. 

Folders used:
- Sources: contains all C source files
- Startup Code: Contains the startup code of the application. You may adapt it
  to your own needs, but in such a case make sure that you create a local copy.
- Prm: Linker parameter files used for linking. Note that the file used for the linker
  is specified in the Linker Preference Panel itself (<ALT-F7> or Edit->{Current Build Target Name} settings,
  while the project window is opened).
- Libs: contains the ANSI library to be linked with.
- Debugger Project File: This *.ini file is passed to the debugger/simulator
  as configuration file. It contains various target interface settings, and path
  information as well. This file can be edited from the simulator/debugger e.g. using
  File->Configuration in the simulator/debugger.

Note that this project is set up for the simulator only.

How to run this example:

1. Build and debug the loader:

  In the target selection combo box, the first entry of the toolbar of the "Checksum Loader Example.mcp"
  project window, select the "Loader" component. Then build and run the debugger using the little triangle button
  with the small bug. This will start the HIWAVE debugger.
  Press the reset button.
  Step through the code. In CheckApp (loader.c) the code will detect that no application is loaded at the following check:

  "if (APP_FIX_IDENT == 0xCAFE)"

  When any one of the tests in CheckApp fails, it sets the global isValid to 2 to indicate the checksum failure.
  The assembly code will then loop forever.
  Do not close the HIWAVE debugger right now.

  Note: The generated code and its execution speed depends on the compiler options. 
        "-ot" generates a speed optimized version, "-DENABLE_PRECOMPUTE=0" a size optimized one.

2. Build and use the Application.

  In the target selection combo box select "Application". Then press the make button, not the debug button.
  Using the debug button would launch a separate HIWAVE without the loader.
  Switch to the HIWAVE started from the loader application 
  (if you did close it: switch the target selection combo back to "Loader" and press the Debug button).
  Now open a command window (if none is already open).
     Select the Component->Open menu entry of HIWAVE. In the opened dialog, select "Command" and press OK.

  In the command window enter 

  srec "bin\app.abs.s19"

  Note:    We can load the app.abs also with the load menu of HIWAVE. 
           But this has the disadvantages that the debug info of the loader.abs is replaced with the debug info of the app.abs.
           So we could afterwards debug in the app, but no longer (at least on a C source level) in the loader. 
  Note(2): The simulator has to be configured in its "Auto on Access" mode and not in the default "Auto on Load" mode. 
           This mode can be configured with the Simulator->Configure menu entry.

  Now, press the reset button and start stepping through the code again. This time all the checks in CheckApp should work and isValid should be set to 1.
  After returning from CheckApp, the code calls the application. As we do not have debug info loaded for the application, only the assembly code is shown.

  Experiment with invalidation the application code (0xe000 to 0xefff) and see if the checksum fails.

3. Load the Symbol info for the Application

  Use the File->Load menu command in HIWAVE. In the "Load Executable File" dialog, select "app.abs" and also check the "Load Symbols only" check box.
  If you do not see the debug info, then you did probably not step far enough in the previous step 2. If so, set a breakpoint at _Startup, press Reset and then Start/Continue.



Metrowerks