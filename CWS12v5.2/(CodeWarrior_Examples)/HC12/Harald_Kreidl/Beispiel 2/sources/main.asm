;************************************************
;*  CPU12 Interrupt-Programm-Beispiel			*
;*	Beispiel 2									*
;************************************************

            XDEF	main
            XDEF	Dummy_ISR
            XDEF	PWM_Shutdown_ISR,Counter_ISR
            XDEF	CAN4_Tx_ISR,CAN3_Tx_ISR,CAN2_Tx_ISR,CAN1_Tx_ISR,CAN0_Tx_ISR
            XDEF	CAN4_Rx_ISR,CAN3_Rx_ISR,CAN2_Rx_ISR,CAN1_Rx_ISR,CAN0_Rx_ISR
            XDEF	CAN4_Error_ISR,CAN3_Error_ISR,CAN2_Error_ISR,CAN1_Error_ISR,CAN0_Error_ISR
            XDEF	CAN4_Wakeup_ISR,CAN3_Wakeup_ISR,CAN2_Wakeup_ISR,CAN1_Wakeup_ISR,CAN0_Wakeup_ISR
            XDEF	Flash_ISR,EEPROM_ISR
            XDEF	SPI0_ISR,SPI1_ISR,SPI2_ISR,IIC_ISR,SCI0_ISR,SCI1_ISR
;           XDEF	BDLC_ISR ist nicht implementiert
            XDEF	SCME_ISR,CRG_Lock_ISR
            XDEF	PA_B_Ovfl_ISR_ISR,PA_Edge_ISR,PA_Overflow_ISR
            XDEF	Port_H_ISR,Port_J_ISR,Port_P_ISR
            XDEF	ATD1_ISR,ATD2_ISR
            XDEF	Tim_Ovfl_ISR,Tim_Ch7_ISR,Tim_Ch6_ISR,Tim_Ch5_ISR,Tim_Ch4_ISR
            XDEF	Tim_Ch3_ISR,Tim_Ch2_ISR,Tim_Ch1_ISR,Tim_Ch0_ISR
            XDEF	RTI__ISR
            XDEF	IRQ_ISR,XIRQ_ISR
            XDEF	SWI_ISR,TRAP_ISR
            XDEF	COP_Reset_ISR,Clock_Mon_ISR

initStk:	EQU		$3FFF+1

DataSection:     SECTION
;
; Hier können die Datendefinitionen stehen
;

CodeSection:	SECTION
;
; Hier folgen die Anwenderprogramme
;

main:		LDS		#initStk			; Stackpointer laden
			CLI							; Interrupts freigeben
			; Hier kann der Anwender-Code
			; des Hauptprogramms stehen
			BRA     main

Dummy_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI

RTI_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
PWM_Shutdown_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI

Counter_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI

CAN4_Tx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN3_Tx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN2_Tx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN1_Tx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN0_Tx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN4_Rx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN3_Rx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN2_Rx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN1_Rx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN0_Rx_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN4_Error_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN3_Error_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN2_Error_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN1_Error_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN0_Error_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN4_Wakeup_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN3_Wakeup_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN2_Wakeup_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN1_Wakeup_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CAN0_Wakeup_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Flash_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
EEPROM_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
SPI0_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
SPI1_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI

SPI2_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
IIC_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
SCI0_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
SCI1_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
				
; BDLC_ISR:	ist nicht implementiert
			; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
;			RTI

SCME_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
CRG_Lock_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
PA_B_Ovfl_ISR_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
PA_Edge_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
PA_Overflow_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Port_H_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Port_J_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Port_P_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
ATD1_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
ATD2_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ovfl_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch7_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch6_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch5_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch4_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch3_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch2_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch1_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Tim_Ch0_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
RTI__ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
IRQ_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
XIRQ_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
SWI_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
TRAP_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
COP_Reset_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			
Clock_Mon_ISR:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI
			

;
; Definition der Vektortabelle
;

VectorTable:	SECTION

INT80:			DC.W	Dummy_ISR			; reserviert
INT82:			DC.W	Dummy_ISR			; reserviert
INT84:			DC.W	Dummy_ISR			; reserviert
INT86:			DC.W	Dummy_ISR			; reserviert
INT88:			DC.W	Dummy_ISR			; reserviert
INT8A:			DC.W	Dummy_ISR			; reserviert
PWM_Shutdown:	DC.W	PWM_Shutdown_ISR	; PWM Emergency Shutdown
Port_P:			DC.W	Port_P_ISR			; Port P
CAN4_Tx:		DC.W	CAN4_Tx_ISR			; CAN 4 senden
CAN4_Rx:		DC.W	CAN4_Rx_ISR			; CAN 4 empfangen
CAN4_Error:		DC.W	CAN4_Error_ISR		; CAN 4 Fehlerbehandlung
CAN4_Wakeup:	DC.W	CAN4_Wakeup_ISR		; CAN 4 wakeup
CAN3_Tx:		DC.W	CAN3_Tx_ISR			; CAN 3 senden
CAN3_Rx:		DC.W	CAN3_Rx_ISR			; CAN 3 empfangen
CAN3_Error:		DC.W	CAN3_Error_ISR		; CAN 3 Fehlerbehandlung
CAN3_Wakeup:	DC.W	CAN3_Wakeup_ISR		; CAN 3 wakeup
CAN2_Tx:		DC.W	CAN2_Tx_ISR			; CAN 2 senden
CAN2_Rx:		DC.W	CAN2_Rx_ISR			; CAN 2 empfangen
CAN2_Error:		DC.W	CAN2_Error_ISR		; CAN 2 Fehlerbehandlung
CAN2_wakeup:	DC.W	CAN2_Wakeup_ISR		; CAN 2 wakeup
CAN1_Tx:		DC.W	CAN1_Tx_ISR			; CAN 1 senden
CAN1_Rx:		DC.W	CAN1_Rx_ISR			; CAN 1 empfangen
CAN1_Error:		DC.W	CAN1_Error_ISR		; CAN 1 Fehlerbehandlung
CAN1_wakeup:	DC.W	CAN1_Wakeup_ISR		; CAN 1 wakeup
CAN0_Tx:		DC.W	CAN0_Tx_ISR			; CAN 0 senden
CAN0_Rx:		DC.W	CAN0_Rx_ISR			; CAN 0 empfangen
CAN0_Error:		DC.W	CAN0_Error_ISR		; CAN 0 Fehlerbehandlung
CAN0_wakeup:	DC.W	CAN0_Wakeup_ISR		; CAN 0 wakeup
Flash:			DC.W	Flash_ISR			; Flash
EEPROM:			DC.W	EEPROM_ISR			; EEPROM
SPI2:			DC.W	SPI2_ISR			; SPI2
SPI1:			DC.W	SPI1_ISR			; SPI1
IIC:			DC.W	IIC_ISR				; IIC
BDLC:			DC.W	Dummy_ISR			; BDLC wird hier nicht verwendet
SCME:			DC.W	SCME_ISR			; SCME
CRG_Lock:		DC.W	CRG_Lock_ISR		; CRG Lock
PA_B_Ovfl:		DC.W	PA_B_Ovfl_ISR_ISR	; Pulsakkumulator B Overflow
Counter:		DC.W	Counter_ISR			; Down Counter Underflow
Port_H:			DC.W	Port_H_ISR			; Port H
Port_J:			DC.W	Port_J_ISR			; Port J
ATD1:			DC.W	ATD1_ISR			; ATD1
ATD0:			DC.W	ATD2_ISR			; ATD2
SCI1:			DC.W	SCI1_ISR			; SCI1
SCI0:			DC.W	SCI0_ISR			; SCI2
SPI0:			DC.W	SPI0_ISR			; SPI0
PA_Edge:		DC.W	PA_Edge_ISR			; Pulsakkumulator Eingangsflanke
PA_A_Overflow:	DC.W	PA_Overflow_ISR		; Pulsakkumulator Überlauf
Timer_Overflow:	DC.W	Tim_Ovfl_ISR		; Timer Überlauf
Tim_Ch7:		DC.W	Tim_Ch7_ISR			; Timer Kanal 7
Tim_Ch6:		DC.W	Tim_Ch6_ISR			; Timer Kanal 6
Tim_Ch5:		DC.W	Tim_Ch5_ISR			; Timer Kanal 5
Tim_Ch4:		DC.W	Tim_Ch4_ISR			; Timer Kanal 4
Tim_Ch3:		DC.W	Tim_Ch3_ISR			; Timer Kanal 3
Tim_Ch2:		DC.W	Tim_Ch2_ISR			; Timer Kanal 2
Tim_Ch1:		DC.W	Tim_Ch1_ISR			; Timer Kanal 1
Tim_Ch0:		DC.W	Tim_Ch0_ISR			; Timer Kanal 0
RTI_Interrupt:	DC.W	RTI__ISR			; Real Time Interrupt
IRQ_Interrupt:	DC.W	IRQ_ISR				; IRQ
XIRQ_Interrupt:	DC.W	XIRQ_ISR			; XIRQ
SWI_Interrupt:	DC.W	SWI_ISR				; Software Interrupt
TRAP_Interrupt:	DC.W	TRAP_ISR			; TRAP Illegal Opcode
COP_Reset		DC.W	COP_Reset_ISR		; COP Watchdog
Clock_Mon_Reset:DC.W	Clock_Mon_ISR		; Clock Monitor
main__:			DC.W	main				; Programmeingang, Hauptprogramm
