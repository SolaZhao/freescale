;*****************************************************************
;* This stationery serves as the framework for a                 *
;* user application (single file, absolute assembly application) *
;* For a more comprehensive program that                         *
;* demonstrates the more advanced functionality of this          *
;* processor, please see the demonstration applications          *
;* located in the examples subdirectory of the                   *
;* Freescale CodeWarrior for the HC12 Program directory          *
;*****************************************************************

; export symbols
            XDEF Entry, _Startup            ; export 'Entry' symbol
            ABSENTRY Entry        ; for absolute assembly: mark this as application entry point



; Include derivative-specific definitions 
		INCLUDE 'derivative.inc' 

$$MCU_ASM_RAMROMDEF$$
; variable/data section

$$IF $$SERIAL_MONITOR_SETUP$$
 ifdef _HCS12_SERIALMON
            ORG $3FFF - (RAMEnd - RAMStart)
 else
            ORG RAMStart
 endif
$$ELSE
            ORG RAMStart
$$ENDIF
 ; Insert here your data definition.
Counter     DS.W 1
FiboRes     DS.W 1


; code section
            ORG   ROMStart

$$IF $$CALL_DEVICE_INIT$$
; Include device initialization code
            INCLUDE 'MCUInit.inc'
$$ENDIF

Entry:
_Startup:
$$IF $$SERIAL_MONITOR_SETUP$$
            ; remap the RAM &amp; EEPROM here. See EB386.pdf
 ifdef _HCS12_SERIALMON
            ; set registers at $0000
            CLR   $11                  ; INITRG= $0
            ; set ram to end at $3FFF
            LDAB  #$39
            STAB  $10                  ; INITRM= $39

            ; set eeprom to end at $0FFF
            LDAA  #$9
            STAA  $12                  ; INITEE= $9


            LDS   #$3FFF+1        ; See EB386.pdf, initialize the stack pointer
 else
            LDS   #RAMEnd+1       ; initialize the stack pointer
 endif
$$ELSE
            LDS   #RAMEnd+1       ; initialize the stack pointer
$$ENDIF

$$IF $$CALL_DEVICE_INIT$$
            ; Call generated Device Initialization function
            CALL   MCU_init
$$ELSE
            CLI                     ; enable interrupts
$$ENDIF
mainLoop:
            LDX   #1              ; X contains counter
couterLoop:
            STX   Counter         ; update global.
            BSR   CalcFibo
            STD   FiboRes         ; store result
            LDX   Counter
            INX
            CPX   #24             ; larger values cause overflow.
            BNE   couterLoop
            BRA   mainLoop        ; restart.

CalcFibo:  ; Function to calculate fibonacci numbers. Argument is in X.
            LDY   #$00            ; second last
            LDD   #$01            ; last
            DBEQ  X,FiboDone      ; loop once more (if X was 1, were done already)
FiboLoop:
            LEAY  D,Y             ; overwrite second last with new value
            EXG   D,Y             ; exchange them -> order is correct again
            DBNE  X,FiboLoop
FiboDone:
            RTS                   ; result in D

$$IF $$CALL_DEVICE_INIT$$
$$ELSE
;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
$$ENDIF
