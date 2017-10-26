/******************************************************************************
													Copyright (c) Freescale 2008
Current Revision :	$Revision: 1.2 $

PURPOSE: main program entry and CPU12 interrupt vector table                       
                                                                          
 ***********************************************************************  
 *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  
 *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  
 *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  
 *  AND NO PROMISE OF SUPPORT.                                         *  
 ***********************************************************************  
                                                                          
DESCRIPTION:  function main() providing initial program entry.                                             
                                                                          
UPDATE HISTORY                                                            
REV  AUTHOR    DATE        DESCRIPTION OF CHANGE                          
---  ------    --------    ---------------------                          
1.0  r32151    01/03/08    - initial coding              
                                                                          

*******************************************************************************
Freescale reserves the right to make changes without further notice to any
product herein to improve reliability, function or design. Freescale does
not assume any liability arising out ot the application or use of any
product, circuit, or software described herein; neither does it convey any
license under its patent rights nor the rights of others. Freescale products
are not designed, intended, or authorized for use as components in systems
intended for surgical implant into the body, or other applications intended
to support life, or for any other application in which the failure of the
Freescale product could create a situation where personal injury or death may
occur. Should Buyer purchase or use Freescale products for any such unintended
or unauthorized application, Buyer shall idemnify and hold Freescale and its
officers, employees, subsidiaries, affiliates, and distributors harmless
against all claims costs, damages, and expenses, and reasonable attorney fees
arising out of, dirTimerly or indirTimerly, any claim of personal injury or death
associated with such unintended or unathorized use, even if such claim alleges
that Freescale was negligent regarding the design or manufacture of the part.
Freescale and the Freescale logo* are registered trademarks of Freescale Ltd.
******************************************************************************/

#include <hidef.h>            /* common defines and macros */
#include <start12.h>          /* provides the reset vector */
#include "derivative.h"

#include "interrupts.h"
#include "xgate channels S12XE.h"
#include "xgate.h"

/************************* #defines ******************************************/
/* can edit these values as appropriate for the application */
#define XGATE_PRIORITY PRIORITY1

/* the following flash configuration field values will be included in the 
   vector table entry */

#define KEY0     0xFFFF
#define KEY1     0xFFFF
#define KEY2     0xFFFF
#define KEY3     0xFFFF
#define FOPT_NV  0xFF
#define FPROT_NV 0xFF
#define EPROT_NV 0xFF
#define FSEC_NV  0xFE    /* don't change unless you want to secure!!!!! */

/************************ function prototypes ********************************/
void main(void);
void ConfigureXGATE(void);
void ConfigureXGATE(void);
void ConfigureInterrupts(void);
void ConfigurePIT(void);
void ConfigurePLL(void);

/******************************************************************************
Function Name  : main
Engineer       : 	
Date           : 14/05/2008
Parameters     : NONE
Returns        : NONE
Notes          : main routine entered from Startup.c.
                 Initialises interrupts and the PIT timer and then loops to 
                 re-trigger one of the XGATE software triggers whenever it is
                 cleared by the XGATE service routine. 
******************************************************************************/
void main(void) {
//  ConfigurePLL();
//  ConfigurePorts();
  ConfigureXGATE();
  ConfigureInterrupts();
  ConfigurePIT();
  EnableInterrupts;
  for(;;) { /* repeat forever */
            /* if the software int ch0 flag is not set (i.e. has been cleared by XGATE) */
     if(!(XGSWT&BIT0)) {
            /* then set it to force execution of software trigger 0 handler */
         XGSWT= BIT0|(BIT0<<8);
     }
  }
  /* make sure that you never leave this function */
}

/******************************************************************************
Function Name  : ConfigureXGATE
Date           : 14/05/2008
Parameters     : NONE
Returns        : NONE
Notes          : intialises the XGATE V3 module  
******************************************************************************/
void ConfigureXGATE(void) {
  /* initialize the XGATE vector block and
     set the XGVBR register to its start address */
     /* set XGATE priority level */
   XGCHPL = XGATE_PRIORITY;    
     /* index to vector base register */
   XGISPSEL = 0;
     /* configure XGate Vector base register to point at the vector table */
   XGVBR= (unsigned int)(void*__far)XGATE_VectorTable - XVEC_TABLE_OFFSET; /* initialise Xgate vector base */
     /* index to low priority stack base register */
   XGISPSEL = 1;
     /* set the low priority stack start address */
   XGVBR =  (unsigned int)(char *__far)XgateLoStack + sizeof(XgateLoStack);
     /* index to high priority stack base register */
   XGISPSEL = 2;
     /* set the high priority stack start address */
   XGVBR =  (unsigned int)(char *__far)XgateHiStack + sizeof(XgateHiStack);
     /* enable XGATE mode and interrupts XGE | XGFRZ | XGIE set, XGSWEF cleared*/
   XGMCTL = XGMCTL_XGE_MASK|XGMCTL_XGFRZ_MASK|XGMCTL_XGSWEF_MASK|XGMCTL_XGIE_MASK|0xFB00;
}

/******************************************************************************
Function Name  : ConfigureInterrupts
Date           : 14/05/2008
Parameters     : NONE
Returns        : NONE
Notes          : intialises the interrupt vector routing and priorities
******************************************************************************/
void ConfigureInterrupts(void){   
     /* write the interrupt vector base register */
  IVBR = (unsigned char)(((unsigned int)_vectab)>>8);
      /* switch software trigger 0 interrupt to XGATE */
  ROUTE_INTERRUPT(XGCHID_SWI0, (XGATE_RQST|PRIORITY1)); 
      /* switch PIT channel 0 interrupt to XGATE */
  ROUTE_INTERRUPT(XGCHID_PITCH0, (XGATE_RQST|PRIORITY4));
}

/******************************************************************************
Function Name  : ConfigurePIT
Date           : 14/05/2008
Parameters     : NONE
Returns        : NONE
Notes          : Configures PIT channel 0 to generate a periodic interrupt  
******************************************************************************/
void ConfigurePIT(void){
       /* load micro-timer0 for 1 us tick @ 50MHz bus */
   PITMTLD0 = 49;              
       /* select MT0 for channel 0 */
   PITMUX_PMUX0 = 0;
       /* enable PIT channel 0 */
   PITCE_PCE0 = 1;              
       /* enable channel 0 interrupt */
   PITINTE_PINTE0 = 1;
       /* load modulus-timer for 100us */
   PITLD0 = 99;              
       /* ensure the PIT flags are clear */
   PITTF = 0xFF;
       /* enable the PIT module */
   PITCFLMT = PITCFLMT_PITE_MASK | PITCFLMT_PITFRZ_MASK;;
}

/******************************************************************************
Function Name  : ConfigurePLL
Engineer       : 	
Date           : 14/05/2008
Parameters     : NONE
Returns        : NONE
Notes          : configures the IPLL for a 50MHz bus from a 4MHz crystal.
                 calls to error hook and  
******************************************************************************/
#define PLL_LOCK_INT_STATUS 0  /* disabled */

void ConfigurePLL(void){
   unsigned int timeout = 0xFFFF;

       /* 50MHz from 4MHz XTAL */     
   SYNR = 0xD8;
   REFDV = 0x01;
   POSTDIV = 0;
   while((!CRGFLG_LOCK) && (timeout-- != 0))	/* wait for PLL to lock */
   {
   }
   if (timeout == 0){
      asm BGND; 
/*      ErrorHook(0); */                     /* PLL didn't lock for some reason so halt */
   }
   CRGFLG = CRGFLG_LOCKIF_MASK;              /* ensure the lock interrupt flag is cleared 
                                             - pll should be locked */
   CRGINT_LOCKIE = PLL_LOCK_INT_STATUS;      /* configure the PLL lock interrupt - the PLL clock 
                                             is a critical timing reference so we want to 
                                             know if it loses lock at all during trimming */
   CLKSEL_PLLSEL = 1;                        /* select the PLL as the clock source */
   if(CLKSEL_PLLSEL != 1) {                  /* will only have set if the PLL was still locked */
      asm BGND; 
/*      ErrorHook(1); */
   }
}

/*****************************************************************************/
/********* INTERRUPT SERVICE ROUTINES - Non-Maskable vectors shown ***********/
/*****************************************************************************/
#pragma push 
#pragma CODE_SEG __NEAR_SEG NON_BANKED 

/*Note: any vectors to be triggered by the XGATE sif instruction must be routed 
to the XGATE.  */


/******************************************************************************  
Function Name  : SoftwareTrigger0_ISR		  ===== non maskable
Engineer       : 	
Date           : 14/05/2008
Parameters     : NONE
Returns        : NONE
Notes          : Interrupt service routine for XGATE s'ware interrupt 0. 
                 Routed to XGATE.
******************************************************************************/
interrupt void SoftwareTrigger0_ISR(void) {
   XGIF_WORD_SWI0 = XGIF_MASK_SWI0;     /* clear the xgate sif flag */
}

/******************************************************************************  
Function Name  : PITCH0_ISR		  ===== non maskable
Engineer       : 	
Date           : 14/05/2008
Parameters     : NONE
Returns        : NONE
Notes          : Interrupt service routine for unresolved interrupt source. 
                 Routed to XGATE.
******************************************************************************/
interrupt void PITCH0_ISR(void) {
   XGIF_WORD_PITCH0 = XGIF_MASK_PITCH0;     /* clear the xgate sif flag */
}

/******************************************************************************  
Function Name  : Spurious_ISR		  ===== non maskable
Engineer       : 	
Date           : 06/05/2003
Parameters     : NONE
Returns        : NONE
Notes          : Interrupt service routine for unresolved interrupt source. 
******************************************************************************/
interrupt void Spurious_ISR(void) {
   asm NOP;		 /* to avoid unintentional single stepping of BGND instruction */
   asm BGND;
   for(;;);    /* stall */
}

/******************************************************************************  
Function Name  : XGATE_Error_ISR	  ===== non maskable										
Engineer       : 	
Date           : 06/05/2003
Parameters     : NONE
Returns        : NONE
Notes          : Interrupt service routine for XGATE error. 
******************************************************************************/
interrupt void XGATE_Error_ISR(void) {
   asm NOP;		 /* to avoid unintentional single stepping of BGND instruction */
   asm BGND;
            /* clear the error flag */
   XGMCTL = XGMCTL_XGSWEF_MASK | XGMCTL_XGSWEIFM_MASK;	
   for(;;);    /* stall */
}

/******************************************************************************
Function Name  : Default_ISR
Engineer       : 	
Date           : 06/05/2003
Parameters     : NONE
Returns        : NONE
Notes          : Interrupt service routine for unused interrupt vectors. 
******************************************************************************/
#pragma TRAP_PROC [SAVE_NO_REGS]
void 
Default_ISR(void)
{
   asm BGND;
   for(;;);
}

/******************************************************************************
Function Name  : Reserved_ISR
Engineer       : 	
Date           : 06/05/2003
Parameters     : NONE
Returns        : NONE
Notes          : Interrupt service routine for unused interrupt vectors. 
******************************************************************************/
#pragma TRAP_PROC [SAVE_NO_REGS]
void 
Reserved_ISR(void)
{
   asm BGND;
   for(;;);
}

#pragma pop


#pragma CONST_SEG __NEAR_SEG S12_VEC_TABLE
/*****************************************************************************
ResetVectorTable
Interrupt vector table for S12XEP100 (a superset for the S12XE family)
This is the default CPU interrupt vector table at reset: IVBR = $FF
Other vector tables can be created and used by changing IVBR - note that the 
reset vectors and the flash configuration field entries (the first 8) are only 
valid for configuring the device when the table is placed at the default 
location (0xFF00). 
*****************************************************************************/
/* vector table default location is at address 0xFF00 */
const void (*const near _vectab[])(void) = 
{                             
	(void (*near const)(void))KEY0,		   /* 0xFF00 backdoor key 0 */
	(void (*near const)(void))KEY1,		   /* 0xFF02 backdoor key 1 */
	(void (*near const)(void))KEY2,		   /* 0xFF04 backdoor key 2 */
	(void (*near const)(void))KEY3,		   /* 0xFF06 backdoor key 3 */
	(void (*near const)(void))0xFFFF,		/* 0xFF08 reserved */
	(void (*near const)(void))0xFFFF,		/* 0xFF0A reserved */ 
	(void (*near const)(void))((FPROT_NV<<8)|EPROT_NV),	/* 0xFF0C protection */ 
	(void (*near const)(void))((FOPT_NV<<8) |FSEC_NV ),   /* 0xFF0E security */
    Spurious_ISR,                /* 0xFF10 Spurious Interrupt */
    Default_ISR,                 /* 0xFF12 SYS - System interrupt */
    Default_ISR,                 /* 0xFF14 MPU Access error */
    XGATE_Error_ISR,             /* 0xFF16 XGATE error */
    Reserved_ISR,                /* 0xFF18 Reserved */
    Reserved_ISR,                /* 0xFF1A Reserved */
    Reserved_ISR,                /* 0xFF1C Reserved */
    Reserved_ISR,                /* 0xFF1E Reserved */
    Reserved_ISR,                /* 0xFF20 Reserved */
    Reserved_ISR,                /* 0xFF22 Reserved */
    Reserved_ISR,                /* 0xFF24 Reserved */
    Reserved_ISR,                /* 0xFF26 Reserved */
    Reserved_ISR,                /* 0xFF28 Reserved */
    Reserved_ISR,                /* 0xFF2A Reserved */
    Reserved_ISR,                /* 0xFF2C Reserved */
    Reserved_ISR,                /* 0xFF2E Reserved */
    Reserved_ISR,                /* 0xFF30 Reserved */
    Reserved_ISR,                /* 0xFF32 Reserved */
    Reserved_ISR,                /* 0xFF34 Reserved */
    Reserved_ISR,                /* 0xFF36 Reserved */
    Reserved_ISR,                /* 0xFF38 Reserved */
    Reserved_ISR,                /* 0xFF3A Reserved */
    Default_ISR,                 /* 0xFF3C ATD1 compare */                            
    Default_ISR,                 /* 0xFF3E ATD0 compare */                            
    Default_ISR,                 /* 0xFF40 TIM Pulse accumulator input edge */     
    Default_ISR,                 /* 0xFF42 TIM Pulse accumulator A overflow */     
    Default_ISR,                 /* 0xFF44 TIM overflow */  
    Default_ISR,                 /* 0xFF46 TIM channel 7 */                                 
    Default_ISR,                 /* 0xFF48 TIM channel 6 */ 
    Default_ISR,                 /* 0xFF4A TIM channel 5 */ 
    Default_ISR,                 /* 0xFF4C TIM channel 4 */ 
    Default_ISR,                 /* 0xFF4E TIM channel 3 */ 
    Default_ISR,                 /* 0xFF50 TIM channel 2 */ 
    Default_ISR,                 /* 0xFF52 TIM channel 1 */ 
    Default_ISR,                 /* 0xFF54 TIM channel 0 */ 
    Default_ISR,                 /* 0xFF56 SCI7 */                     
    Default_ISR,                 /* 0xFF58 Periodic Interrupt Timer 7 */          
    Default_ISR,                 /* 0xFF5A Periodic Interrupt Timer 6 */          
    Default_ISR,                 /* 0xFF5C Periodic Interrupt Timer 5 */          
    Default_ISR,                 /* 0xFF5E Periodic Interrupt Timer 4 */          
    Reserved_ISR,                /* 0xFF60 Reserved */
    Reserved_ISR,                /* 0xFF62 Reserved */
    Default_ISR,                 /* 0xFF64 XGATE Software Trigger 7 */
    Default_ISR,                 /* 0xFF66 XGATE Software Trigger 6 */
    Default_ISR,                 /* 0xFF68 XGATE Software Trigger 5 */
    Default_ISR,                 /* 0xFF6A XGATE Software Trigger 4 */
    Default_ISR,                 /* 0xFF6C XGATE Software Trigger 3 */
    Default_ISR,                 /* 0xFF6E XGATE Software Trigger 2 */
    Default_ISR,                 /* 0xFF70 XGATE Software Trigger 1 */
    SoftwareTrigger0_ISR,        /* 0xFF72 XGATE Software Trigger 0 */
    Default_ISR,                 /* 0xFF74 Periodic Interrupt Timer 3 */
    Default_ISR,                 /* 0xFF76 Periodic Interrupt Timer 2 */
    Default_ISR,                 /* 0xFF78 Periodic Interrupt Timer 1 */
    PITCH0_ISR,                  /* 0xFF7A Periodic Interrupt Timer 0 */
    Default_ISR,                 /* 0xFF7C Reserved */
    Default_ISR,                 /* 0xFF7E API Autonomous Periodical Interrupt */
    Default_ISR,                 /* 0xFF80 LVI Low Voltage Interrupt */
    Default_ISR,                 /* 0xFF82 IIC1 */
    Default_ISR,                 /* 0xFF84 SCI5 */
    Default_ISR,                 /* 0xFF86 SCI4 */
    Default_ISR,                 /* 0xFF88 SCI3 */
    Default_ISR,                 /* 0xFF8A SCI2 */
    Default_ISR,                 /* 0xFF8C PWM Emergency Shutdown */
    Default_ISR,                 /* 0xFF8E Port P Interrupt */
    Default_ISR,                 /* 0xFF90 MSCAN 4 transmit */
    Default_ISR,                 /* 0xFF92 MSCAN 4 receive */
    Default_ISR,                 /* 0xFF94 MSCAN 4 errors */
    Default_ISR,                 /* 0xFF96 MSCAN 4 wake-up */
    Default_ISR,                 /* 0xFF98 MSCAN 3 transmit */
    Default_ISR,                 /* 0xFF9A MSCAN 3 receive */
    Default_ISR,                 /* 0xFF9C MSCAN 3 errors */
    Default_ISR,                 /* 0xFF9E MSCAN 3 wake-up */
    Default_ISR,                 /* 0xFFA0 MSCAN 2 transmit */
    Default_ISR,                 /* 0xFFA2 MSCAN 2 receive */
    Default_ISR,                 /* 0xFFA4 MSCAN 2 errors */
    Default_ISR,                 /* 0xFFA6 MSCAN 2 wake-up */
    Default_ISR,                 /* 0xFFA8 MSCAN 1 transmit */
    Default_ISR,                 /* 0xFFAA MSCAN 1 receive */
    Default_ISR,                 /* 0xFFAC MSCAN 1 errors */
    Default_ISR,                 /* 0xFFAE MSCAN 1 wake-up */
    Default_ISR,                 /* 0xFFB0 MSCAN 0 transmit */
    Default_ISR,                 /* 0xFFB2 MSCAN 0 receive */
    Default_ISR,                 /* 0xFFB4 MSCAN 0 errors */
    Default_ISR,                 /* 0xFFB6 MSCAN 0 wake-up */
    Default_ISR,                 /* 0xFFB8 Flash */
    Default_ISR,                 /* 0xFFBA Flash error detect */
    Default_ISR,                 /* 0xFFBC SPI2 */
    Default_ISR,                 /* 0xFFBE SPI1 */
    Default_ISR,                 /* 0xFFC0 IIC0 */
    Default_ISR,                 /* 0xFFC2 SCI6 */
    Default_ISR,                 /* 0xFFC4 CRG Self Clock Mode */
    Default_ISR,                 /* 0xFFC6 CRG PLL lock */
    Default_ISR,                 /* 0xFFC8 Pulse accumulator B overflow */
    Default_ISR,                 /* 0xFFCA Modulus Down Counter Underflow */
    Default_ISR,                 /* 0xFFCC Port H */
    Default_ISR,                 /* 0xFFCE Port J */
    Default_ISR,                 /* 0xFFD0 ATD1 */
    Default_ISR,                 /* 0xFFD2 ATD0 */
    Default_ISR,                 /* 0xFFD4 SCI1 */
    Default_ISR,                 /* 0xFFD6 SCI0 */
    Default_ISR,                 /* 0xFFD8 SPI0 */
    Default_ISR,                 /* 0xFFDA Pulse accumulator input edge */
    Default_ISR,                 /* 0xFFDC Pulse accumulator A overflow */
    Default_ISR,                 /* 0xFFDE Enhanced Capture Timer overflow */
    Default_ISR,                 /* 0xFFE0 Enhanced Capture Timer channel 7 */
    Default_ISR,                 /* 0xFFE2 Enhanced Capture Timer channel 6 */
    Default_ISR,                 /* 0xFFE4 Enhanced Capture Timer channel 5 */
    Default_ISR,                 /* 0xFFE6 Enhanced Capture Timer channel 4 */
    Default_ISR,                 /* 0xFFE8 Enhanced Capture Timer channel 3 */
    Default_ISR,                 /* 0xFFEA Enhanced Capture Timer channel 2 */
    Default_ISR,                 /* 0xFFEC Enhanced Capture Timer channel 1 */
    Default_ISR,                 /* 0xFFEE Enhanced Capture Timer channel 0 */
    Default_ISR,                 /* 0xFFF0 Real Time Interrupt (Channel 78) */
    Default_ISR,                 /* 0xFFF2 IRQ */
    Default_ISR,                 /* 0xFFF4 XIRQ */
    Default_ISR,                 /* 0xFFF6 SWI */
    Default_ISR,                 /* 0xFFF8 Unallocated instruction trap */
    Default_ISR,                 /* 0xFFFA COP failure reset */
    Default_ISR,                 /* 0xFFFC Clock monitor fail reset */
    _Startup                     /* 0xFFFE Reset vector */
};

