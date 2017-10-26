/******************************************************************************
  FILE        : main.c 
  PURPOSE     : checksum demo/test file
  LANGUAGE    : ANSI-C
  -----------------------------------------------------------------------------
  HISTORY 
    19 sep 2002       Created.
 ******************************************************************************/

/******************************************************************************
 This module demonstrates and checks various features of the checksum
 computation capabilities of the linker.
 It's intended as for demonstration purposes only. 
 It runs fine in the simulator, but to run it on real hardware,
 the used memory areas and the peripherals handling (especially the COP) 
 would need to be adapted.

Please read the readme.txt to see how to run this example.

We do (artificially) assume the following memory configuration:
    RAM         0x0080 up to 0x01FF
    FLASH/ROM   0xE000 up to 0xFFFF

 This memory area is further separated into two applications.
 1. The loader. It gets control after reset, checks if the main application
    is around and its checksums are correct. If so, it is started.
    The name loader is misleading as we don't actually load anything here. 
    This would be an additional step left to the reader.

 2. The actual application. In our case, it does just about nothing other than providing some code over which 
    we can compute and verify a checksum. 

Here how these two applications are allocated in memory:

    LOADER_RAM             = NO_INIT             0x0080 TO 0x0081;              // loader private RAM storage
    ZERP_PAGE_RAM          = READ_WRITE          0x0082 TO 0x00FF;              // zero page RAM. Not used by loader
    EXTENDED_RAM           = READ_WRITE          0x0100 TO 0x017F;              // extended RAM. Not used by loader
    STACK_RAM              = NO_INIT             0x0180 TO 0x01FF;              // stack area. Also used by loader

    APP_FIX_IDENT_ROM      = READ_ONLY           0xE000 TO 0xE001;              // some magic number $cafe. Just some additional validity check.
    APP_AUTO_CHECKSUM_ROM  = READ_ONLY           0xE002 TO 0xE03F FILL 0x00;    // automatic generated checksums.
    APP_PRM_CHECKSUM_ROM   = READ_ONLY           0xE040 TO 0xE041;              // prm file based CRC checksum.
    APP_STARTUP_STRUCT_ROM = READ_ONLY           0xE042 TO 0xE0FF FILL 0xFF;    // startup structure of application.
    APP_ROM                = READ_ONLY           0xE100 TO 0xEFDF FILL 0xFF;    // our application code. Note: at the end are vector copies.
    APP_ROM_VECTORS        = READ_ONLY           0xEFE0 TO 0xEFFF;              // our application code. Note: at the end are vector copies.
    LOADER_ROM             = READ_ONLY           0xF000 TO 0xFFFF;              // our loader code. Note: this area does include the vectors.

    APP_FIX_IDENT_ROM: just some ordinary magic number as additional not checksum based test
    APP_AUTO_CHECKSUM_ROM: here we place the automatically computed checksums.
    APP_PRM_CHECKSUM_ROM: place of a CRC checksum over the whole remaining application space.
    APP_STARTUP_STRUCT_ROM: the startupData structure of the application.
    APP_ROM: the code of our application. The main function.
    APP_ROM_VECTORS: vector copies of our main function.
    LOADER_ROM: memory area for the loader. Contains the checksum computation code and also the vector redirection code.
                
The loader:

Usually, the job of a loader is to load something, check it, and if it is OK, run it.
As this example is intended to show the linker checksum feature only, we skip the loading part here. 
(So it more a checker than a loader, but we will ignore this and continue to call it loader anyway.)
The loader catches all vectors, as we wants to be sure that the application is OK before giving control to it.
For every reset (say, whenever the code pointed by the reset vector is executed), 
the code in the loader checks the checksum of the eventually loaded application.
If this code is OK, then the application reset vector is fetched and executed.
All other interrupts are forwarded to the app, if (and only if) the checksums of the application has been verified before.
The loader expects a shadow vector area at 0xEFE0 to 0xEFFF the same way as the CPU expects the vector at 0xFFE0 to 0xFFFF.
The loader does also expect the checksums to be at specific places, basically the loader is aware of the prm file of the application.
The loader is computing both the prm file defined checksum and the automatically generated checksum.
Production loaders would probably just check one of them, but as this is a demonstration example, 
we just want to show as much as possible.
Also for fast loading times, we are using a table driven CRC8 calculation method.

The application:

There are only few things special about this application. Its vectors are just below 0xF000, 0x1000 lower than usual.
And it does have checksums are at special places, so that the loader can verify them before actually calling the application.


 ******************************************************************************/
#pragma CONST_SEG APP_FIX_IDENT_ROM
const unsigned short MagicNumber=0xCAFE;

#pragma CONST_SEG DEFAULT

void main(void) {
  for (;;) {}
}

__interrupt void UnusedVector(void) {
  for (;;) {}
}
