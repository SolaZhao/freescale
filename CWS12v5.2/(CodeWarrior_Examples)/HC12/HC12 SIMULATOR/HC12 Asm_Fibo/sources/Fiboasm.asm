; File: fibo.o
;------------------------------------------------------------------------
; The present file tests the global possibilities for the ASSEMBLER /
;------------------------------------------------------------------------
       
         XDEF fiboCount, counter, Fibonacci, main

myData: section
fiboCount:    ds.w  1
counter:      ds.w  1

locData: section
fib1:         ds.w  1
fib2:         ds.w  1
fibo:         ds.w  1
i:            ds.w  1

myCode: section
Fibonacci:
     PSHD  
     CLRB  
     CLRA  
     STD   fib1
     INCB  
     STD   fib2
     LDX   0,SP
     STX   fibo
     LDAB  #2
     STD   i
     BRA   cond   
   loop:
     LDD   fib1
     ADDD  fib2
     STD   fibo
     
     LDX   fib2
     STX   fib1
     
     STD   fib2
     
     LDX   i
     INX
     STX   i
     
   cond:  
     LDD   i
     CPD   0, SP
     BLS   loop
     
     LDD   fibo
     LEAS  2, SP
     RTS
     

main:
     LDS   #$3FF0 ; initialize Stack 
     CLR   fiboCount
   mainLoop:
     CLRB  
     CLRA  
     STD   counter
     STD   +0,SP
     BRA   testEnd   
   incCnt:
     LDD   counter
     ADDD  #1
     STD   counter
     BSR   Fibonacci   
     STD   fiboCount
     LDX   +0,SP
     INX   
     STX   +0,SP
   testEnd:
     LDD   +0,SP
     CPD   #48
     BLE   incCnt   
     BRA  mainLoop  
     PULD  
     RTS   
