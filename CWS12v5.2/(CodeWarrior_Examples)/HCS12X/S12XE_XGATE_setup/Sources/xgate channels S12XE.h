/******************************************************************************
													Copyright (c) Freescale 2008
Current Revision :	$Revision: 1.1 $

PURPOSE: Header file with easy use defines for S12XE XGATE channels..                       
                                                                          
 ***********************************************************************  
 *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  
 *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  
 *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  
 *  AND NO PROMISE OF SUPPORT.                                         *  
 ***********************************************************************  
                                                                          
DESCRIPTION:  .                                             
                                                                          
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
#ifndef __XG_CHANNELS_S12XE_H_
#define __XG_CHANNELS_S12XE_H_

/* XGate channel identifier */
#define XGCHID_ATD1CMP     0x1E  // Channel 1E - ATD1 compare                            
#define XGCHID_ADT0CMP     0x1F  // Channel 1F - ATD0 compare                            
#define XGCHID_TIM_PACIPE  0x20  // Channel 20 - TIM Pulse accumulator input edge     
#define XGCHID_TIM_PACAOF  0x21  // Channel 21 - TIM Pulse accumulator A overflow     
#define XGCHID_TIMOF       0x22  // Channel 22 - TIM overflow  
#define XGCHID_TIMCH7      0x23  // Channel 23 - TIM channel 7                                 
#define XGCHID_TIMCH6      0x24  // Channel 24 - TIM channel 6 
#define XGCHID_TIMCH5      0x25  // Channel 25 - TIM channel 5 
#define XGCHID_TIMCH4      0x26  // Channel 26 - TIM channel 4 
#define XGCHID_TIMCH3      0x27  // Channel 27 - TIM channel 3 
#define XGCHID_TIMCH2      0x28  // Channel 28 - TIM channel 2 
#define XGCHID_TIMCH1      0x29  // Channel 29 - TIM channel 1 
#define XGCHID_TIMCH0      0x2A  // Channel 2A - TIM channel 0 
#define XGCHID_SCI7        0x2B  // Channel 2B - SCI7                     
#define XGCHID_PITCH7      0x2C  // Channel 2C - Periodic Interrupt Timer 7          
#define XGCHID_PITCH6      0x2D  // Channel 2D - Periodic Interrupt Timer 6          
#define XGCHID_PITCH5      0x2E  // Channel 2E - Periodic Interrupt Timer 5          
#define XGCHID_PITCH4      0x2F  // Channel 2F - Periodic Interrupt Timer 4          
//#define XGCHID_            0x30  // Channel 30 - Reserved                         
//#define XGCHID_            0x31  // Channel 31 - Reserved                         
#define XGCHID_SWI7        0x32  // Channel 32 - XGATE Software Trigger 7           
#define XGCHID_SWI6        0x33  // Channel 33 - XGATE Software Trigger 6           
#define XGCHID_SWI5        0x34  // Channel 34 - XGATE Software Trigger 5           
#define XGCHID_SWI4        0x35  // Channel 35 - XGATE Software Trigger 4           
#define XGCHID_SWI3        0x36  // Channel 36 - XGATE Software Trigger 3           
#define XGCHID_SWI2        0x37  // Channel 37 - XGATE Software Trigger 2           
#define XGCHID_SWI1        0x38  // Channel 38 - XGATE Software Trigger 1           
#define XGCHID_SWI0        0x39  // Channel 39 - XGATE Software Trigger 0           
#define XGCHID_PITCH3      0x3A  // Channel 3A - Periodic Interrupt Timer 3          
#define XGCHID_PITCH2      0x3B  // Channel 3B - Periodic Interrupt Timer 2          
#define XGCHID_PITCH1      0x3C  // Channel 3C - Periodic Interrupt Timer 1          
#define XGCHID_PITCH0      0x3D  // Channel 3D - Periodic Interrupt Timer 0          
//#define XGCHID_          0x3E  // Channel 3E - Reserved                         
#define XGCHID_API         0x3F  // Channel 3F - Autonomous Periodical interrupt API
#define XGCHID_LVI         0x40  // Channel 40 - Low Voltage interrupt LVI
#define XGCHID_IIC1        0x41  // Channel 41 - IIC1 Bus                 
#define XGCHID_SCI5        0x42  // Channel 42 - SCI5                     
#define XGCHID_SCI4        0x43  // Channel 43 - SCI4                     
#define XGCHID_SCI3        0x44  // Channel 44 - SCI3                     
#define XGCHID_SCI2        0x45  // Channel 45 - SCI2                     
#define XGCHID_PWMES       0x46  // Channel 46 - PWM Emergency Shutdown   
#define XGCHID_PTP         0x47  // Channel 47 - Port P Interrupt         
#define XGCHID_CAN4TX      0x48  // Channel 48 - CAN4 transmit            
#define XGCHID_CAN4RX      0x49  // Channel 49 - CAN4 receive             
#define XGCHID_CAN4ERR     0x4A  // Channel 4A - CAN4 errors              
#define XGCHID_CAN4WUP     0x4B  // Channel 4B - CAN4 wake-up             
#define XGCHID_CAN3TX      0x4C  // Channel 4C - CAN3 transmit            
#define XGCHID_CAN3RX      0x4D  // Channel 4D - CAN3 receive             
#define XGCHID_CAN3ERR     0x4E  // Channel 4E - CAN3 errors              
#define XGCHID_CAN3WUP     0x4F  // Channel 4F - CAN3 wake-up             
#define XGCHID_CAN2TX      0x50  // Channel 50 - CAN2 transmit
#define XGCHID_CAN2RX      0x51  // Channel 51 - CAN2 receive 
#define XGCHID_CAN2ERR     0x52  // Channel 52 - CAN2 errors  
#define XGCHID_CAN2WUP     0x53  // Channel 53 - CAN2 wake-up 
#define XGCHID_CAN1TX      0x54  // Channel 54 - CAN1 transmit
#define XGCHID_CAN1RX      0x55  // Channel 55 - CAN1 receive 
#define XGCHID_CAN1ERR     0x56  // Channel 56 - CAN1 errors  
#define XGCHID_CAN1WUP     0x57  // Channel 57 - CAN1 wake-up 
#define XGCHID_CAN0TX      0x58  // Channel 58 - CAN0 transmit
#define XGCHID_CAN0RX      0x59  // Channel 59 - CAN0 receive 
#define XGCHID_CAN0ERR     0x5A  // Channel 5A - CAN0 errors  
#define XGCHID_CAN0WUP     0x5B  // Channel 5B - CAN0 wake-up 
#define XGCHID_FLASH       0x5C  // Channel 5C - FLASH 
#define XGCHID_FLASH_FAULT 0x5D  // Channel 5D - FLASH fault detect
#define XGCHID_SPI2        0x5E  // Channel 5E - SPI2  
#define XGCHID_SPI1        0x5F  // Channel 5F - SPI1
#define XGCHID_IIC0        0x60  // Channel 60 - IIC0 Bus                         
#define XGCHID_SCI6        0x61  // Channel 61 - SCI6                         
#define XGCHID_SCM         0x62  // Channel 62 - CRG Self Clock Mode              
#define XGCHID_PLLLOCK     0x63  // Channel 63 - CRG PLL lock                     
#define XGCHID_PACBOF      0x64  // Channel 64 - Pulse Accumulator B Overflow     
#define XGCHID_MODUF       0x65  // Channel 65 - Modulus Down Counter underflow   
#define XGCHID_PTH         0x66  // Channel 66 - Port H                           
#define XGCHID_PTJ         0x67  // Channel 67 - Port J                           
#define XGCHID_ATD1        0x68  // Channel 68 - ATD1                             
#define XGCHID_ADT0        0x69  // Channel 69 - ATD0                             
#define XGCHID_SCI1        0x6A  // Channel 6A - SCI1                             
#define XGCHID_SCI0        0x6B  // Channel 6B - SCI0                             
#define XGCHID_SPI0        0x6C  // Channel 6C - SPI0                             
#define XGCHID_ECT_PACIPE  0x6D  // Channel 6D - Pulse accumulator input edge     
#define XGCHID_ECT_PACAOF  0x6E  // Channel 6E - Pulse accumulator A overflow     
#define XGCHID_ECTOF       0x6F  // Channel 6F - Enhanced Capture Timer overflow  
#define XGCHID_ECTCH7      0x70  // Channel 70 - Enhanced Capture Timer channel 7                                 
#define XGCHID_ECTCH6      0x71  // Channel 71 - Enhanced Capture Timer channel 6 
#define XGCHID_ECTCH5      0x72  // Channel 72 - Enhanced Capture Timer channel 5 
#define XGCHID_ECTCH4      0x73  // Channel 73 - Enhanced Capture Timer channel 4 
#define XGCHID_ECTCH3      0x74  // Channel 74 - Enhanced Capture Timer channel 3 
#define XGCHID_ECTCH2      0x75  // Channel 75 - Enhanced Capture Timer channel 2 
#define XGCHID_ECTCH1      0x76  // Channel 76 - Enhanced Capture Timer channel 1 
#define XGCHID_ECTCH0      0x77  // Channel 77 - Enhanced Capture Timer channel 0 
#define XGCHID_RTI         0x78  // Channel 78 - Real Time Interrupt 

/* XGate Interrupt Flag word identifier */
#define XGIF_WORD_ATD1CMP     XGIF_1F_10 // Channel 1E - ATD1 compare                            
#define XGIF_WORD_ADT0CMP     XGIF_1F_10 // Channel 1F - ATD0 compare                            
#define XGIF_WORD_TIM_PACIPE  XGIF_2F_20 // Channel 20 - TIM Pulse accumulator input edge     
#define XGIF_WORD_TIM_PACAOF  XGIF_2F_20 // Channel 21 - TIM Pulse accumulator A overflow     
#define XGIF_WORD_TIMOF       XGIF_2F_20 // Channel 22 - TIM overflow  
#define XGIF_WORD_TIMCH7      XGIF_2F_20 // Channel 23 - TIM channel 7                                 
#define XGIF_WORD_TIMCH6      XGIF_2F_20 // Channel 24 - TIM channel 6 
#define XGIF_WORD_TIMCH5      XGIF_2F_20 // Channel 25 - TIM channel 5 
#define XGIF_WORD_TIMCH4      XGIF_2F_20 // Channel 26 - TIM channel 4 
#define XGIF_WORD_TIMCH3      XGIF_2F_20 // Channel 27 - TIM channel 3 
#define XGIF_WORD_TIMCH2      XGIF_2F_20 // Channel 28 - TIM channel 2 
#define XGIF_WORD_TIMCH1      XGIF_2F_20 // Channel 29 - TIM channel 1 
#define XGIF_WORD_TIMCH0      XGIF_2F_20 // Channel 2A - TIM channel 0 
#define XGIF_WORD_SCI7        XGIF_2F_20 // Channel 2B - SCI7                     
#define XGIF_WORD_PITCH7      XGIF_2F_20 // Channel 2C - Periodic Interrupt Timer 7          
#define XGIF_WORD_PITCH6      XGIF_2F_20 // Channel 2D - Periodic Interrupt Timer 6          
#define XGIF_WORD_PITCH5      XGIF_2F_20 // Channel 2E - Periodic Interrupt Timer 5          
#define XGIF_WORD_PITCH4      XGIF_2F_20 // Channel 2F - Periodic Interrupt Timer 4          
//#define XGIF_WORD_          XGIF_3F_30  // Channel 30 - Reserved                         
//#define XGIF_WORD_          XGIF_3F_30  // Channel 31 - Reserved                         
#define XGIF_WORD_SWI7        XGIF_3F_30  // Channel 32 - XGATE Software Trigger 7           
#define XGIF_WORD_SWI6        XGIF_3F_30  // Channel 33 - XGATE Software Trigger 6           
#define XGIF_WORD_SWI5        XGIF_3F_30  // Channel 34 - XGATE Software Trigger 5           
#define XGIF_WORD_SWI4        XGIF_3F_30  // Channel 35 - XGATE Software Trigger 4           
#define XGIF_WORD_SWI3        XGIF_3F_30  // Channel 36 - XGATE Software Trigger 3           
#define XGIF_WORD_SWI2        XGIF_3F_30  // Channel 37 - XGATE Software Trigger 2           
#define XGIF_WORD_SWI1        XGIF_3F_30  // Channel 38 - XGATE Software Trigger 1           
#define XGIF_WORD_SWI0        XGIF_3F_30  // Channel 39 - XGATE Software Trigger 0           
#define XGIF_WORD_PITCH3      XGIF_3F_30  // Channel 3A - Periodic Interrupt Timer 3          
#define XGIF_WORD_PITCH2      XGIF_3F_30  // Channel 3B - Periodic Interrupt Timer 2          
#define XGIF_WORD_PITCH1      XGIF_3F_30  // Channel 3C - Periodic Interrupt Timer 1          
#define XGIF_WORD_PITCH0      XGIF_3F_30  // Channel 3D - Periodic Interrupt Timer 0          
//#define XGIF_WORD_          XGIF_3F_30  // Channel 3E - Reserved                         
#define XGIF_WORD_API         XGIF_3F_30  // Channel 3F - Autonomous Periodical interrupt API
#define XGIF_WORD_LVI         XGIF_4F_40  // Channel 40 - Low Voltage interrupt LVI
#define XGIF_WORD_IIC1        XGIF_4F_40  // Channel 41 - IIC1 Bus                 
#define XGIF_WORD_SCI5        XGIF_4F_40  // Channel 42 - SCI5                     
#define XGIF_WORD_SCI4        XGIF_4F_40  // Channel 43 - SCI4                     
#define XGIF_WORD_SCI3        XGIF_4F_40  // Channel 44 - SCI3                     
#define XGIF_WORD_SCI2        XGIF_4F_40  // Channel 45 - SCI2                     
#define XGIF_WORD_PWMES       XGIF_4F_40  // Channel 46 - PWM Emergency Shutdown   
#define XGIF_WORD_PTP         XGIF_4F_40  // Channel 47 - Port P Interrupt         
#define XGIF_WORD_CAN4TX      XGIF_4F_40  // Channel 48 - CAN4 transmit            
#define XGIF_WORD_CAN4RX      XGIF_4F_40  // Channel 49 - CAN4 receive             
#define XGIF_WORD_CAN4ERR     XGIF_4F_40  // Channel 4A - CAN4 errors              
#define XGIF_WORD_CAN4WUP     XGIF_4F_40  // Channel 4B - CAN4 wake-up             
#define XGIF_WORD_CAN3TX      XGIF_4F_40  // Channel 4C - CAN3 transmit            
#define XGIF_WORD_CAN3RX      XGIF_4F_40  // Channel 4D - CAN3 receive             
#define XGIF_WORD_CAN3ERR     XGIF_4F_40  // Channel 4E - CAN3 errors              
#define XGIF_WORD_CAN3WUP     XGIF_4F_40  // Channel 4F - CAN3 wake-up             
#define XGIF_WORD_CAN2TX      XGIF_5F_50  // Channel 50 - CAN2 transmit
#define XGIF_WORD_CAN2RX      XGIF_5F_50  // Channel 51 - CAN2 receive 
#define XGIF_WORD_CAN2ERR     XGIF_5F_50  // Channel 52 - CAN2 errors  
#define XGIF_WORD_CAN2WUP     XGIF_5F_50  // Channel 53 - CAN2 wake-up 
#define XGIF_WORD_CAN1TX      XGIF_5F_50  // Channel 54 - CAN1 transmit
#define XGIF_WORD_CAN1RX      XGIF_5F_50  // Channel 55 - CAN1 receive 
#define XGIF_WORD_CAN1ERR     XGIF_5F_50  // Channel 56 - CAN1 errors  
#define XGIF_WORD_CAN1WUP     XGIF_5F_50  // Channel 57 - CAN1 wake-up 
#define XGIF_WORD_CAN0TX      XGIF_5F_50  // Channel 58 - CAN0 transmit
#define XGIF_WORD_CAN0RX      XGIF_5F_50  // Channel 59 - CAN0 receive 
#define XGIF_WORD_CAN0ERR     XGIF_5F_50  // Channel 5A - CAN0 errors  
#define XGIF_WORD_CAN0WUP     XGIF_5F_50  // Channel 5B - CAN0 wake-up 
#define XGIF_WORD_FLASH       XGIF_5F_50  // Channel 5C - FLASH 
#define XGIF_WORD_FLASH_FAULT XGIF_5F_50  // Channel 5D - FLASH fault detect
#define XGIF_WORD_SPI2        XGIF_5F_50  // Channel 5E - SPI2  
#define XGIF_WORD_SPI1        XGIF_5F_50  // Channel 5F - SPI1
#define XGIF_WORD_IIC0        XGIF_6F_60  // Channel 60 - IIC0 Bus                         
#define XGIF_WORD_SCI6        XGIF_6F_60  // Channel 61 - SCI6                         
#define XGIF_WORD_SCM         XGIF_6F_60  // Channel 62 - CRG Self Clock Mode              
#define XGIF_WORD_PLLLOCK     XGIF_6F_60  // Channel 63 - CRG PLL lock                     
#define XGIF_WORD_PACBOF      XGIF_6F_60  // Channel 64 - Pulse Accumulator B Overflow     
#define XGIF_WORD_MODUF       XGIF_6F_60  // Channel 65 - Modulus Down Counter underflow   
#define XGIF_WORD_PTH         XGIF_6F_60  // Channel 66 - Port H                           
#define XGIF_WORD_PTJ         XGIF_6F_60  // Channel 67 - Port J                           
#define XGIF_WORD_ATD1        XGIF_6F_60  // Channel 68 - ATD1                             
#define XGIF_WORD_ADT0        XGIF_6F_60  // Channel 69 - ATD0                             
#define XGIF_WORD_SCI1        XGIF_6F_60  // Channel 6A - SCI1                             
#define XGIF_WORD_SCI0        XGIF_6F_60  // Channel 6B - SCI0                             
#define XGIF_WORD_SPI0        XGIF_6F_60  // Channel 6C - SPI0                             
#define XGIF_WORD_ECT_PACIPE  XGIF_6F_60  // Channel 6D - Pulse accumulator input edge     
#define XGIF_WORD_ECT_PACAOF  XGIF_6F_60  // Channel 6E - Pulse accumulator A overflow     
#define XGIF_WORD_ECTOF       XGIF_6F_60  // Channel 6F - Enhanced Capture Timer overflow  
#define XGIF_WORD_ECTCH7      XGIF_7F_70  // Channel 70 - Enhanced Capture Timer channel 7                                 
#define XGIF_WORD_ECTCH6      XGIF_7F_70  // Channel 71 - Enhanced Capture Timer channel 6 
#define XGIF_WORD_ECTCH5      XGIF_7F_70  // Channel 72 - Enhanced Capture Timer channel 5 
#define XGIF_WORD_ECTCH4      XGIF_7F_70  // Channel 73 - Enhanced Capture Timer channel 4 
#define XGIF_WORD_ECTCH3      XGIF_7F_70  // Channel 74 - Enhanced Capture Timer channel 3 
#define XGIF_WORD_ECTCH2      XGIF_7F_70  // Channel 75 - Enhanced Capture Timer channel 2 
#define XGIF_WORD_ECTCH1      XGIF_7F_70  // Channel 76 - Enhanced Capture Timer channel 1 
#define XGIF_WORD_ECTCH0      XGIF_7F_70  // Channel 77 - Enhanced Capture Timer channel 0 
#define XGIF_WORD_RTI         XGIF_7F_70  // Channel 78 - Real Time Interrupt 
                                   
/* XGate Interrupt Flag word bit masks */
#define XGIF_MASK_ATD1CMP     (0x0001<<0x0E)  // Channel 1E - ATD1 compare                            
#define XGIF_MASK_ADT0CMP     (0x0001<<0x0F)  // Channel 1F - ATD0 compare                            
#define XGIF_MASK_TIM_PACIPE   0x0001         // Channel 20 - TIM Pulse accumulator input edge     
#define XGIF_MASK_TIM_PACAOF  (0x0001<<0x01)  // Channel 21 - TIM Pulse accumulator A overflow     
#define XGIF_MASK_TIMOF       (0x0001<<0x02)  // Channel 22 - TIM overflow  
#define XGIF_MASK_TIMCH7      (0x0001<<0x03)  // Channel 23 - TIM channel 7                                 
#define XGIF_MASK_TIMCH6      (0x0001<<0x04)  // Channel 24 - TIM channel 6 
#define XGIF_MASK_TIMCH5      (0x0001<<0x05)  // Channel 25 - TIM channel 5 
#define XGIF_MASK_TIMCH4      (0x0001<<0x06)  // Channel 26 - TIM channel 4 
#define XGIF_MASK_TIMCH3      (0x0001<<0x07)  // Channel 27 - TIM channel 3 
#define XGIF_MASK_TIMCH2      (0x0001<<0x08)  // Channel 28 - TIM channel 2 
#define XGIF_MASK_TIMCH1      (0x0001<<0x09)  // Channel 29 - TIM channel 1 
#define XGIF_MASK_TIMCH0      (0x0001<<0x0A)  // Channel 2A - TIM channel 0 
#define XGIF_MASK_SCI7        (0x0001<<0x0B)  // Channel 2B - SCI7                     
#define XGIF_MASK_PITCH7      (0x0001<<0x0C)  // Channel 2C - Periodic Interrupt Timer 7          
#define XGIF_MASK_PITCH6      (0x0001<<0x0D)  // Channel 2D - Periodic Interrupt Timer 6          
#define XGIF_MASK_PITCH5      (0x0001<<0x0E)  // Channel 2E - Periodic Interrupt Timer 5          
#define XGIF_MASK_PITCH4      (0x0001<<0x0F)  // Channel 2F - Periodic Interrupt Timer 4          
//#define XGIF_MASK_           0x0001         // Channel 30 - Reserved                         
//#define XGIF_MASK_          (0x0001<<0x01)  // Channel 31 - Reserved                         
#define XGIF_MASK_SWI7        (0x0001<<0x02)  // Channel 32 - XGATE Software Trigger 7           
#define XGIF_MASK_SWI6        (0x0001<<0x03)  // Channel 33 - XGATE Software Trigger 6           
#define XGIF_MASK_SWI5        (0x0001<<0x04)  // Channel 34 - XGATE Software Trigger 5           
#define XGIF_MASK_SWI4        (0x0001<<0x05)  // Channel 35 - XGATE Software Trigger 4           
#define XGIF_MASK_SWI3        (0x0001<<0x06)  // Channel 36 - XGATE Software Trigger 3           
#define XGIF_MASK_SWI2        (0x0001<<0x07)  // Channel 37 - XGATE Software Trigger 2           
#define XGIF_MASK_SWI1        (0x0001<<0x08)  // Channel 38 - XGATE Software Trigger 1           
#define XGIF_MASK_SWI0        (0x0001<<0x09)  // Channel 39 - XGATE Software Trigger 0           
#define XGIF_MASK_PITCH3      (0x0001<<0x0A)  // Channel 3A - Periodic Interrupt Timer 3          
#define XGIF_MASK_PITCH2      (0x0001<<0x0B)  // Channel 3B - Periodic Interrupt Timer 2          
#define XGIF_MASK_PITCH1      (0x0001<<0x0C)  // Channel 3C - Periodic Interrupt Timer 1          
#define XGIF_MASK_PITCH0      (0x0001<<0x0D)  // Channel 3D - Periodic Interrupt Timer 0          
//#define XGIF_MASK_          (0x0001<<0x0E)  // Channel 3E - Reserved                         
#define XGIF_MASK_API         (0x0001<<0x0F)  // Channel 3F - Autonomous Periodical interrupt API
#define XGIF_MASK_LVI          0x0001         // Channel 40 - Low Voltage interrupt LVI
#define XGIF_MASK_IIC1        (0x0001<<0x01)  // Channel 41 - IIC1 Bus                 
#define XGIF_MASK_SCI5        (0x0001<<0x02)  // Channel 42 - SCI5                     
#define XGIF_MASK_SCI4        (0x0001<<0x03)  // Channel 43 - SCI4                     
#define XGIF_MASK_SCI3        (0x0001<<0x04)  // Channel 44 - SCI3                     
#define XGIF_MASK_SCI2        (0x0001<<0x05)  // Channel 45 - SCI2                     
#define XGIF_MASK_PWMES       (0x0001<<0x06)  // Channel 46 - PWM Emergency Shutdown   
#define XGIF_MASK_PTP         (0x0001<<0x07)  // Channel 47 - Port P Interrupt         
#define XGIF_MASK_CAN4TX      (0x0001<<0x08)  // Channel 48 - CAN4 transmit            
#define XGIF_MASK_CAN4RX      (0x0001<<0x09)  // Channel 49 - CAN4 receive             
#define XGIF_MASK_CAN4ERR     (0x0001<<0x0A)  // Channel 4A - CAN4 errors              
#define XGIF_MASK_CAN4WUP     (0x0001<<0x0B)  // Channel 4B - CAN4 wake-up             
#define XGIF_MASK_CAN3TX      (0x0001<<0x0C)  // Channel 4C - CAN3 transmit            
#define XGIF_MASK_CAN3RX      (0x0001<<0x0D)  // Channel 4D - CAN3 receive             
#define XGIF_MASK_CAN3ERR     (0x0001<<0x0E)  // Channel 4E - CAN3 errors              
#define XGIF_MASK_CAN3WUP     (0x0001<<0x0F)  // Channel 4F - CAN3 wake-up             
#define XGIF_MASK_CAN2TX       0x0001         // Channel 50 - CAN2 transmit
#define XGIF_MASK_CAN2RX      (0x0001<<0x01)  // Channel 51 - CAN2 receive 
#define XGIF_MASK_CAN2ERR     (0x0001<<0x02)  // Channel 52 - CAN2 errors  
#define XGIF_MASK_CAN2WUP     (0x0001<<0x03)  // Channel 53 - CAN2 wake-up 
#define XGIF_MASK_CAN1TX      (0x0001<<0x04)  // Channel 54 - CAN1 transmit
#define XGIF_MASK_CAN1RX      (0x0001<<0x05)  // Channel 55 - CAN1 receive 
#define XGIF_MASK_CAN1ERR     (0x0001<<0x06)  // Channel 56 - CAN1 errors  
#define XGIF_MASK_CAN1WUP     (0x0001<<0x07)  // Channel 57 - CAN1 wake-up 
#define XGIF_MASK_CAN0TX      (0x0001<<0x08)  // Channel 58 - CAN0 transmit
#define XGIF_MASK_CAN0RX      (0x0001<<0x09)  // Channel 59 - CAN0 receive 
#define XGIF_MASK_CAN0ERR     (0x0001<<0x0A)  // Channel 5A - CAN0 errors  
#define XGIF_MASK_CAN0WUP     (0x0001<<0x0B)  // Channel 5B - CAN0 wake-up 
#define XGIF_MASK_FLASH       (0x0001<<0x0C)  // Channel 5C - FLASH 
#define XGIF_MASK_FLASH_FAULT (0x0001<<0x0D)  // Channel 5D - FLASH fault detect
#define XGIF_MASK_SPI2        (0x0001<<0x0E)  // Channel 5E - SPI2  
#define XGIF_MASK_SPI1        (0x0001<<0x0F)  // Channel 5F - SPI1
#define XGIF_MASK_IIC0         0x0001         // Channel 60 - IIC0 Bus                         
#define XGIF_MASK_SCI6        (0x0001<<0x01)  // Channel 61 - SCI6                         
#define XGIF_MASK_SCM         (0x0001<<0x02)  // Channel 62 - CRG Self Clock Mode              
#define XGIF_MASK_PLLLOCK     (0x0001<<0x03)  // Channel 63 - CRG PLL lock                     
#define XGIF_MASK_PACBOF      (0x0001<<0x04)  // Channel 64 - Pulse Accumulator B Overflow     
#define XGIF_MASK_MODUF       (0x0001<<0x05)  // Channel 65 - Modulus Down Counter underflow   
#define XGIF_MASK_PTH         (0x0001<<0x06)  // Channel 66 - Port H                           
#define XGIF_MASK_PTJ         (0x0001<<0x07)  // Channel 67 - Port J                           
#define XGIF_MASK_ATD1        (0x0001<<0x08)  // Channel 68 - ATD1                             
#define XGIF_MASK_ADT0        (0x0001<<0x09)  // Channel 69 - ATD0                             
#define XGIF_MASK_SCI1        (0x0001<<0x0A)  // Channel 6A - SCI1                             
#define XGIF_MASK_SCI0        (0x0001<<0x0B)  // Channel 6B - SCI0                             
#define XGIF_MASK_SPI0        (0x0001<<0x0C)  // Channel 6C - SPI0                             
#define XGIF_MASK_ECT_PACIPE  (0x0001<<0x0D)  // Channel 6D - Pulse accumulator input edge     
#define XGIF_MASK_ECT_PACAOF  (0x0001<<0x0E)  // Channel 6E - Pulse accumulator A overflow     
#define XGIF_MASK_ECTOF       (0x0001<<0x0F)  // Channel 6F - Enhanced Capture Timer overflow  
#define XGIF_MASK_ECTCH7       0x0001         // Channel 70 - Enhanced Capture Timer channel 7                                 
#define XGIF_MASK_ECTCH6      (0x0001<<0x01)  // Channel 71 - Enhanced Capture Timer channel 6 
#define XGIF_MASK_ECTCH5      (0x0001<<0x02)  // Channel 72 - Enhanced Capture Timer channel 5 
#define XGIF_MASK_ECTCH4      (0x0001<<0x03)  // Channel 73 - Enhanced Capture Timer channel 4 
#define XGIF_MASK_ECTCH3      (0x0001<<0x04)  // Channel 74 - Enhanced Capture Timer channel 3 
#define XGIF_MASK_ECTCH2      (0x0001<<0x05)  // Channel 75 - Enhanced Capture Timer channel 2 
#define XGIF_MASK_ECTCH1      (0x0001<<0x06)  // Channel 76 - Enhanced Capture Timer channel 1 
#define XGIF_MASK_ECTCH0      (0x0001<<0x07)  // Channel 77 - Enhanced Capture Timer channel 0 
#define XGIF_MASK_RTI         (0x0001<<0x08)  // Channel 78 - Real Time Interrupt 

#endif /* __XG_CHANNELS_S12XE_H_ */