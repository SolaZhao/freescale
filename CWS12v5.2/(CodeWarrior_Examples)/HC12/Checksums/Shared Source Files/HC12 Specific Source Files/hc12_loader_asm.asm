;******************************************************************************
;  FILE        : loader_asm.asm
;  PURPOSE     : checksum demo/test file
;  LANGUAGE    : HC12 Assembler
;  -----------------------------------------------------------------------------
;  HISTORY
;    19 sep 2002       Created.
; ******************************************************************************

; the purpose of this module is to redirect the vectors from 0xFFE0..0xFFFF to 0xEFE0..0xEFFF
; the reset vector is especially handled. After reset, the stack is init and CheckApp is called 
; actually do the checksum tests
;
; if the main app is valid.
         XREF.B isValid ; 0: main app is about to be checked.
                        ; 1: main app is valid. Call it.
                        ; 2: main app is invalid.
         XREF CheckApp  ; code which sets isValid. Called once after reset.


         XDEF  L_FFFE; for the debugger only, start here as for a reset.
psVect:  EQU $EFFE ; pseudo reset vector
cpuVect: EQU $FFFE ; real reset vector


         ORG $FF80
handleResetInts:
         LDS #$01FF+1
         JSR  CheckApp
         LDD #L_FFFE+2 ; simulate "L_FFFE: BSR handleInts"
         PSHD
handleInts: ; the top of stack contains now L_FFE0+2+vecnum*2
         LDAA isValid
         DECA
         BNE error
callIt:  ; TOS (top of stack) contains currently our FFE0 addresses.
         PULX ; HX contains now our L_FFE0 addresses.
         JMP  [(psVect-(L_FFFE+2)),X]  ; simulate vector execution
                                       ; calculation: HX contains L_FFFE+2 for the reset vector:
                                       ; address:    psVect-(L_FFFE+2),X
                                       ;          == psVect-(L_FFFE+2)+HX
                                       ;          == psVect-(L_FFFE+2)+(L_FFFE+2)
                                       ;          == psVect
                                       ;          == $EFFE


error:
         BRA  *   ; error. 
                  ; if (isValid == 0) then an interrupt happened before we could check the main app. What should we do?
                  ; if (isValue == 2): app is invalid. Did you load the main application? 
                  ;                    If not, enter srec bin\app.abs.s19 to load it.
                  
                


L_FFE0:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFE2:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFE4:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFE6:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFE8:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFEA:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFEC:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFEE:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFF0:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFF2:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFF4:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFF6:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFF8:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFFA:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFFC:  BSR handleInts; note: we use here that BSR handleInts is 2 bytes!
L_FFFE:  BRA handleResetInts; note: We don't use a BSR here because the stack might not be ok.


         ORG $FFE0
         DC.W L_FFE0
         DC.W L_FFE2
         DC.W L_FFE4
         DC.W L_FFE6
         DC.W L_FFE8
         DC.W L_FFEA
         DC.W L_FFEC
         DC.W L_FFEE
         DC.W L_FFF0
         DC.W L_FFF2
         DC.W L_FFF4
         DC.W L_FFF6
         DC.W L_FFF8
         DC.W L_FFFA
         DC.W L_FFFC
         DC.W L_FFFE
