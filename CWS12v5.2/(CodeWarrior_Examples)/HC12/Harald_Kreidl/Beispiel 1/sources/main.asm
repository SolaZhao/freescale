;************************************************
;*         CPU12 Interrupt-Programm-Beispiel	*
;************************************************

            XDEF main,RTI_isr

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

RTI_isr:	; Hier kann der Anwender-Code
			; der Interrupt Service Routine
			; stehen
			RTI


