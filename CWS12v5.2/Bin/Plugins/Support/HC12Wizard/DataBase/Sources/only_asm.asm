;**************************************************************
;* This stationery serves as the framework for a              *
;* user application. For a more comprehensive program that    *
;* demonstrates the more advanced functionality of this       *
;* processor, please see the demonstration applications       *
;* located in the examples subdirectory of the                *
;* Freescale CodeWarrior for the HC12 Program directory       *
;**************************************************************
; Include derivative-specific definitions
            INCLUDE 'derivative.inc'
$$IF $$CALL_DEVICE_INIT$$
$$// we should include here MCUInit.inc. Unfortunately, the one that Unis generates does not assemble -> fix this when the fixed it.
$$//; Include device initialization code
$$//            INCLUDE 'MCUInit.inc'
            XREF MCU_init
$$ENDIF

; export symbols
            XDEF Entry, _Startup, main
            ; we use export 'Entry' as symbol. This allows us to
            ; reference 'Entry' either in the linker .prm file
            ; or from C/C++ later on

            XREF __SEG_END_SSTACK      ; symbol defined by the linker for the end of the stack

$$XGATE_INCLUDE$$

$$IF $$XGATE_CORE3$$
$$XGATE_INCLUDE_STACKS$$
$$ENDIF

; variable/data section
MY_EXTENDED_RAM: SECTION
; Insert here your data definition.
Counter     ds.w 1
FiboRes     ds.w 1


; code section
MyCode:     SECTION
main:
_Startup:
Entry:
            LDS  #__SEG_END_SSTACK     ; initialize the stack pointer
$$IF $$CALL_DEVICE_INIT$$
            ; Call generated Device Initialization function
            CALL    MCU_init
$$ELSE
            CLI                     ; enable interrupts
$$ENDIF

$$IF $$SERIAL_MONITOR_SETUP$$
            ; remap the RAM &amp; EEPROM here. See EB386.pdf
 ifdef _HCS12_SERIALMON
            ; set registers at $0000
            CLR   $11                  ; INITRG= $0
            ; set ram to end at $3fff
            LDAB  #$39
            STAB  $10                  ; INITRM= $39

            ; set eeprom to end at $0fff
            LDAA  #$9
            STAA  $12                  ; INITEE= $9
 endif
$$ENDIF

$$XGATE_SETUP$$
$$XGATE_SETUP_RAM$$
$$IF $$XGATE_CORE2$$
$$XGATE_SETUP_CORE2$$
$$ENDIF
$$IF $$XGATE_CORE3$$
$$XGATE_SETUP_CORE3$$
$$ENDIF

EndlessLoop:
            LDX   #1                   ; X contains counter
CouterLoop:                            
            STX   Counter              ; update global.
            BSR   CalcFibo             
            STD   FiboRes              ; store result
            LDX   Counter              
            INX                        
            CPX   #24                  ; larger values cause overflow.
            BNE   CouterLoop           
            BRA   EndlessLoop          ; restart.


; Function to calculate fibonacci numbers. Argument is in X.
CalcFibo:
            LDY   #$00                 ; second last
            LDD   #$01                 ; last
            DBEQ  X,FiboDone           ; loop once more (if X was 1, were done already)
FiboLoop:                              
            LEAY  D,Y                  ; overwrite second last with new value
            EXG   D,Y                  ; exchange them -> order is correct again
            DBNE  X,FiboLoop           
FiboDone:                              
            RTS                        ; result in D
