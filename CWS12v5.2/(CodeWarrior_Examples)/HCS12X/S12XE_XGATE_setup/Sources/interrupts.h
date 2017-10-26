/******************************************************************************
													Copyright (c) Freescale 2008
Current Revision :	$Revision: 1.1 $

PURPOSE: header file for CPU12 interrupt settings.                       
                                                                          
 ***********************************************************************  
 *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  
 *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  
 *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  
 *  AND NO PROMISE OF SUPPORT.                                         *  
 ***********************************************************************  
                                                                          
DESCRIPTION:                                               
                                                                          
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

#ifndef __INTERRUPTS_H_
#define __INTERRUPTS_H_

/************************* #defines ******************************************/
#define PRIORITY0 0U
#define PRIORITY1 1U 
#define PRIORITY2 2U 
#define PRIORITY3 3U 
#define PRIORITY4 4U 
#define PRIORITY5 5U 
#define PRIORITY6 6U 
#define PRIORITY7 7U 
#define RQST INT_CFDATA2_RQST_MASK
#define XGATE_RQST RQST

#define BIT0     1U    
#define BIT1    (1U << 1)
#define BIT2    (1U << 2)
#define BIT3    (1U << 3)
#define BIT4    (1U << 4)
#define BIT5    (1U << 5)
#define BIT6    (1U << 6)
#define BIT7    (1U << 7)
#define BIT8    (1U << 8)
#define BIT9    (1U << 9)
#define BIT10   (1U << 10)
#define BIT11   (1U << 11)
#define BIT12   (1U << 12)
#define BIT13   (1U << 13)
#define BIT14   (1U << 14)
#define BIT15   (1U << 15)

/******************************************************************************
Macro Name     : ROUTE_INTERRUPT
Engineer       : 	
Date           : 14/05/2008
Parameters     : XGATE channel id, interrupt cfdata for the channel
Returns        : NONE
Notes          : writes the interrupt routing and priority configuration to the
                 appropriate banked configuration register location. 
******************************************************************************/
#define ROUTE_INTERRUPT(channel_id, cfdata)                \
  INT_CFADDR= (channel_id * 2) & 0xF0;                     \
  INT_CFDATA_ARR[((channel_id * 2) & 0x0F) >> 1] = (cfdata)

/* declaration of the vector table - included to allow initialisation of the 
vector base register */
#pragma CONST_SEG __NEAR_SEG S12_VEC_TABLE
const void (*const near _vectab[])(void); 

#endif /* __INTERRUPTS_H_ */
