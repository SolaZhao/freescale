/** ###################################################################
**     Filename  : Events.H
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


#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "RedLED.h"
#include "GreenLED.h"
#include "Button.h"

void ButtonOnInterrupt(void);
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

/* END Events */
#endif /* __Events_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 03.29 for
**     the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
