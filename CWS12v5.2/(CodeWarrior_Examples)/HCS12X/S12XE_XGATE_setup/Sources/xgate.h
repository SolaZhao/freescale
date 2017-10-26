/******************************************************************************
													Copyright (c) Freescale 2008
Current Revision :	$Revision: 1.1 $

PURPOSE: header file for XGATE service routines.                       
                                                                          
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

#ifndef __XGATE_H_
#define __XGATE_H_

/**** XGATE Stack Initialisation ****/
   
   #define XGATE_LO_STACK_SIZE 0x40		/* words */
   #define XGATE_HI_STACK_SIZE 0x40		/* words */

#pragma push
#pragma DATA_SEG XGATE_DATA
   extern volatile unsigned int XgateHiStack[XGATE_HI_STACK_SIZE];
   extern volatile unsigned int XgateLoStack[XGATE_LO_STACK_SIZE];
#pragma pop


/**** XGATE vector table entry ****/
typedef void (*_NEAR XGATE_Function)(int);
typedef struct {
  XGATE_Function pc;        /* pointer to the handler */
  int dataptr;              /* pointer to the data of the handler */
} XGATE_TableEntry;


#define XVEC_TABLE_OFFSET (0x1E * 4U)		 /* for S12XE100 first vector in xgate table is 1E */
                                           /* and each vector takes up 4 bytes */

#pragma push								
#pragma CONST_SEG __GPAGE_SEG XGATE_VECTORS  /* for the HCS12X/XGATE shared setup, HCS12X needs 
                                                global addressing to access the vector table. */
   extern const XGATE_TableEntry XGATE_VectorTable[];
#pragma pop									/* restore previous segment definitions */

/* Suggestions for XGATE data :
- Generally, data used by an XGATE service routine should be declared along with the XGATE diver 
code and also specified as extern where it is neccessary for the CPU to access it. It should be 
placed in a shared data segment.
- Private data to the XSR that is required to be persistent between execution of an XGATE thread 
should be declared within the XSR (local) using the static specifier.
- XGATE private data that is required to be persistent between execution of an XGATE thread 
but needs to referenced as a parameter in the XGATE vector table should be declared outside of
the XSR using the static specifier.*/


/**** XGATE data custom type definitions ****/ 
typedef struct {
  int counter;
} tDescriptor1;


typedef struct {
  int counter;
  unsigned char channel;
  unsigned char general;  /* space holder to ensure aligned boundary spacing */
} tDescriptor2;

/**** shared data ****/
   /* declare any data here as extern that needs to be shared with the core CPU */
   /* this will be global in scope */
#pragma push								/* save current segment definitions */
#pragma DATA_SEG SHARED_DATA /* allocate the following variables in the segment SHARED_DATA */
// placeholder
#pragma pop									/* restore previous segment definitions */



#endif /* __XGATE_H_ */
