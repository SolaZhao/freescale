/** ###################################################################
**     Filename  : Events.C
**     Project   : LED
**     Processor : MC9S12DP256BCPV
**     Componenttype  : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 29.6.2009, 14:34
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         ButtonOnInterrupt - void ButtonOnInterrupt(void);
**
**     Copyright Freescale Semiconductor, Inc. All Rights Reserved.
** ###################################################################*/
/* MODULE Events */

#pragma MESSAGE DISABLE C1420 /* WARNING C1420: Result of function-call is ignored */


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

/*
** ===================================================================
**     Event       :  ButtonOnInterrupt (module Events)
**
**     From component   :  Button [ExtInt]
**     Description :
**         This event is called when the active signal edge/level
**         occurs.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ButtonOnInterrupt(void)
{
  RedLED_NegVal();
  GreenLED_NegVal();
}


/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 02.80 for
**     the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
