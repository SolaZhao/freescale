/************************************************
*	CPU12 Interrupt-Programm-Beispiel			*
*	Beispiel 4									*
************************************************/

#include "MC9S12DP256.h"

#pragma MESSAGE DISABLE C4000	// WARNING C4000: Condition always is TRUE


/* Funktionsprototypen	*/
void Dummy_ISR( void );			// Dummy Interrupt-Service-Routine
void PWM_Shutdown_ISR( void );	// PWM Emergency Shutdown
void Port_P_ISR( void );		// Port P
void CAN4_Tx_ISR( void );		// CAN 4 senden
void CAN4_Rx_ISR( void );		// CAN 4 empfangen
void CAN4_Error_ISR( void );	// CAN 4 Fehlerbehandlung
void CAN4_Wakeup_ISR( void );	// CAN 4 wakeup
void CAN3_Tx_ISR( void );		// CAN 3 senden
void CAN3_Rx_ISR( void );		// CAN 3 empfangen
void CAN3_Error_ISR( void );	// CAN 3 Fehlerbehandlung
void CAN3_Wakeup_ISR( void );	// CAN 3 wakeup
void CAN2_Tx_ISR( void );		// CAN 2 senden
void CAN2_Rx_ISR( void );		// CAN 2 empfangen
void CAN2_Error_ISR( void );	// CAN 2 Fehlerbehandlung
void CAN2_Wakeup_ISR( void );	// CAN 2 wakeup
void CAN1_Tx_ISR( void );		// CAN 1 senden
void CAN1_Rx_ISR( void );		// CAN 1 empfangen
void CAN1_Error_ISR( void );	// CAN 1 Fehlerbehandlung
void CAN1_Wakeup_ISR( void );	// CAN 1 wakeup
void CAN0_Tx_ISR( void );		// CAN 0 senden
void CAN0_Rx_ISR( void );		// CAN 0 empfangen
void CAN0_Error_ISR( void );	// CAN 0 Fehlerbehandlung
void CAN0_Wakeup_ISR( void );	// CAN 0 wakeup
void Flash_ISR( void );			// Flash
void EEPROM_ISR( void );		// EEPROM
void SPI2_ISR( void );			// SPI2
void SPI1_ISR( void );			// SPI1
void IIC_ISR( void );			// IIC
void Dummy_ISR( void );			// BDLC wird hier nicht verwendet
void SCME_ISR( void );			// SCME
void CRG_Lock_ISR( void );		// CRG Lock
void PA_B_Ovfl_ISR_ISR( void );	// Pulsakkumulator B Overflow
void Counter_ISR( void );		// Down Counter Underflow
void Port_H_ISR( void );		// Port H
void Port_J_ISR( void );		// Port J
void ATD1_ISR( void );			// ATD1
void ATD2_ISR( void );			// ATD2
void SCI1_ISR( void );			// SCI1
void SCI0_ISR( void );			// SCI2
void SPI0_ISR( void );			// SPI0
void PA_Edge_ISR( void );		// Pulsakkumulator Eingangsflanke
void PA_Overflow_ISR( void );	// Pulsakkumulator Überlauf
void Tim_Ovfl_ISR( void );		// Timer Überlauf
void Tim_Ch7_ISR( void );		// Timer Kanal 7
void Tim_Ch6_ISR( void );		// Timer Kanal 6
void Tim_Ch5_ISR( void );		// Timer Kanal 5
void Tim_Ch4_ISR( void );		// Timer Kanal 4
void Tim_Ch3_ISR( void );		// Timer Kanal 3
void Tim_Ch2_ISR( void );		// Timer Kanal 2
void Tim_Ch1_ISR( void );		// Timer Kanal 1
void Tim_Ch0_ISR( void );		// Timer Kanal 0
void RTI__ISR( void );			// Real Time Interrupt
void IRQ_ISR( void );			// IRQ
void XIRQ_ISR( void );			// XIRQ
void SWI_ISR( void );			// Software Interrupt
void TRAP_ISR( void );			// TRAP Illegal Opcode
void COP_Reset_ISR( void );		// COP Watchdog
void Clock_Mon_ISR( void );		// Clock Monitor

/* Extern definierte Funktionen	*/
extern void _Startup( void );			// Programmeingang, Hauptprogramm

void main( void )
{	while( 1 )			// Endloshauptschleife
	{	DDRE = 0;
		asm SEI;			// I-Bit setzen und Interrupts sperren
		WRTINT	= 1;			// Testen von SCI 0 Interrupt
		ADR		= 0x0D;
		ITEST	= 0x08;
		asm CLI;			// I-Bit löschen und Interrupts freigeben
		asm WAI;			// Warten auf Interrupts
	}
}

#pragma TRAP_PROC
void Dummy_ISR( void )
{}

#pragma TRAP_PROC
void PWM_Shutdown_ISR( void )
{}

#pragma TRAP_PROC
void Port_P_ISR( void )
{}

#pragma TRAP_PROC
void CAN4_Tx_ISR( void )
{}

#pragma TRAP_PROC
void CAN4_Rx_ISR( void )
{}

#pragma TRAP_PROC
void CAN4_Error_ISR( void )
{}

#pragma TRAP_PROC
void CAN4_Wakeup_ISR( void )
{}

#pragma TRAP_PROC
void CAN3_Tx_ISR( void )
{}

#pragma TRAP_PROC
void CAN3_Rx_ISR( void )
{}

#pragma TRAP_PROC
void CAN3_Error_ISR( void )
{}

#pragma TRAP_PROC
void CAN3_Wakeup_ISR( void )
{}

#pragma TRAP_PROC
void CAN2_Tx_ISR( void )
{}

#pragma TRAP_PROC
void CAN2_Rx_ISR( void )
{}

#pragma TRAP_PROC
void CAN2_Error_ISR( void )
{}

#pragma TRAP_PROC
void CAN2_Wakeup_ISR( void )
{}

#pragma TRAP_PROC
void CAN1_Tx_ISR( void )
{}

#pragma TRAP_PROC
void CAN1_Rx_ISR( void )
{}

#pragma TRAP_PROC
void CAN1_Error_ISR( void )
{}

#pragma TRAP_PROC
void CAN1_Wakeup_ISR( void )
{}

#pragma TRAP_PROC
void CAN0_Tx_ISR( void )
{}

#pragma TRAP_PROC
void CAN0_Rx_ISR( void )
{}

#pragma TRAP_PROC
void CAN0_Error_ISR( void )
{}

#pragma TRAP_PROC
void CAN0_Wakeup_ISR( void )
{}

#pragma TRAP_PROC
void Flash_ISR( void )
{}

#pragma TRAP_PROC
void EEPROM_ISR( void )
{}

#pragma TRAP_PROC
void SPI2_ISR( void )
{}

#pragma TRAP_PROC
void SPI1_ISR( void )
{}

#pragma TRAP_PROC
void IIC_ISR( void )
{}

/* #pragma TRAP_PROC
void BDLC_ISR( void )
{} wird hier nicht verwendet*/

#pragma TRAP_PROC
void SCME_ISR( void )
{}

#pragma TRAP_PROC
void CRG_Lock_ISR( void )
{}

#pragma TRAP_PROC
void PA_B_Ovfl_ISR_ISR( void )
{}

#pragma TRAP_PROC
void Counter_ISR( void )
{}

#pragma TRAP_PROC
void Port_H_ISR( void )
{}

#pragma TRAP_PROC
void Port_J_ISR( void )
{}

#pragma TRAP_PROC
void ATD1_ISR( void )
{}

#pragma TRAP_PROC
void ATD2_ISR( void )
{}

#pragma TRAP_PROC
void SCI1_ISR( void )
{}

#pragma TRAP_PROC
void SCI0_ISR( void )
{}

#pragma TRAP_PROC
void SPI0_ISR( void )
{}

#pragma TRAP_PROC
void PA_Edge_ISR( void )
{}

#pragma TRAP_PROC
void PA_Overflow_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ovfl_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch7_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch6_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch5_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch4_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch3_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch2_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch1_ISR( void )
{}

#pragma TRAP_PROC
void Tim_Ch0_ISR( void )
{}

#pragma TRAP_PROC
void RTI__ISR( void )
{}

#pragma TRAP_PROC
void IRQ_ISR( void )
{}

#pragma TRAP_PROC
void XIRQ_ISR( void )
{}

#pragma TRAP_PROC
void SWI_ISR( void )
{}

#pragma TRAP_PROC
void TRAP_ISR( void )
{}

#pragma TRAP_PROC
void COP_Reset_ISR( void )
{}

#pragma TRAP_PROC
void Clock_Mon_ISR( void )
{}

#pragma CONST_SEG VECTORS
void (*	const VectorTable[])() = 
{	Dummy_ISR,			// reserviert
	Dummy_ISR,			// reserviert
	Dummy_ISR,			// reserviert
	Dummy_ISR,			// reserviert
	Dummy_ISR,			// reserviert
	Dummy_ISR,			// reserviert
	PWM_Shutdown_ISR,	// PWM Emergency Shutdown
	Port_P_ISR,			// Port P
	CAN4_Tx_ISR,		// CAN 4 senden
	CAN4_Rx_ISR,		// CAN 4 empfangen
	CAN4_Error_ISR,		// CAN 4 Fehlerbehandlung
	CAN4_Wakeup_ISR,	// CAN 4 wakeup
	CAN3_Tx_ISR,		// CAN 3 senden
	CAN3_Rx_ISR,		// CAN 3 empfangen
	CAN3_Error_ISR,		// CAN 3 Fehlerbehandlung
	CAN3_Wakeup_ISR,	// CAN 3 wakeup
	CAN2_Tx_ISR,		// CAN 2 senden
	CAN2_Rx_ISR,		// CAN 2 empfangen
	CAN2_Error_ISR,		// CAN 2 Fehlerbehandlung
	CAN2_Wakeup_ISR,	// CAN 2 wakeup
	CAN1_Tx_ISR,		// CAN 1 senden
	CAN1_Rx_ISR,		// CAN 1 empfangen
	CAN1_Error_ISR,		// CAN 1 Fehlerbehandlung
	CAN1_Wakeup_ISR,	// CAN 1 wakeup
	CAN0_Tx_ISR,		// CAN 0 senden
	CAN0_Rx_ISR,		// CAN 0 empfangen
	CAN0_Error_ISR,		// CAN 0 Fehlerbehandlung
	CAN0_Wakeup_ISR,	// CAN 0 wakeup
	Flash_ISR,			// Flash
	EEPROM_ISR,			// EEPROM
	SPI2_ISR,			// SPI2
	SPI1_ISR,			// SPI1
	IIC_ISR,			// IIC
	Dummy_ISR,			// BDLC wird hier nicht verwendet
	SCME_ISR,			// SCME
	CRG_Lock_ISR,		// CRG Lock
	PA_B_Ovfl_ISR_ISR,	// Pulsakkumulator B Overflow
	Counter_ISR,		// Down Counter Underflow
	Port_H_ISR,			// Port H
	Port_J_ISR,			// Port J
	ATD1_ISR,			// ATD1
	ATD2_ISR,			// ATD2
	SCI1_ISR,			// SCI1
	SCI0_ISR,			// SCI2
	SPI0_ISR,			// SPI0
	PA_Edge_ISR,		// Pulsakkumulator Eingangsflanke
	PA_Overflow_ISR,	// Pulsakkumulator Überlauf
	Tim_Ovfl_ISR,		// Timer Überlauf
	Tim_Ch7_ISR,		// Timer Kanal 7
	Tim_Ch6_ISR,		// Timer Kanal 6
	Tim_Ch5_ISR,		// Timer Kanal 5
	Tim_Ch4_ISR,		// Timer Kanal 4
	Tim_Ch3_ISR,		// Timer Kanal 3
	Tim_Ch2_ISR,		// Timer Kanal 2
	Tim_Ch1_ISR,		// Timer Kanal 1
	Tim_Ch0_ISR,		// Timer Kanal 0
	RTI__ISR,			// Real Time Interrupt
	IRQ_ISR,			// IRQ
	XIRQ_ISR,			// XIRQ
	SWI_ISR,			// Software Interrupt
	TRAP_ISR,			// TRAP Illegal Opcode
	COP_Reset_ISR,		// COP Watchdog
	Clock_Mon_ISR,		// Clock Monitor
	_Startup			// Programmeingang, Hauptprogramm
};
