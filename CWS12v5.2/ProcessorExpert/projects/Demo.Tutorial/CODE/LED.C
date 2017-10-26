/** ###################################################################
**     Filename  : LED.C
**     Project   : LED
**     Processor : MC9S12DP256BCPV
**     Version   : Driver 01.13
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 29.6.2009, 14:31
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
**     Copyright Freescale Semiconductor, Inc. All Rights Reserved.
** ###################################################################*/
/* MODULE led */

/*Including used modules for compilling procedure*/
#include "Cpu.h"
#include "Events.h"
#include "RedLED.h"
#include "GreenLED.h"
#include "Button.h"

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void main(void)
{
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* loop */

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END led */
/*
** ###################################################################
**
**     This file was created by Processor Expert 02.80 for
**     the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
