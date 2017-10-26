/*****************************************************
  Demo files: Calculation of Fibonnacci numbers
 ----------------------------------------------------
   Copyright (c) HIWARE AG, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#include <hidef.h>

#if defined(__HC11__)
  #pragma DATA_SEG SHORT zpage /* place following variables into zeropage */
#endif

unsigned int fiboCount;
unsigned int counter;

unsigned int Fibonacci(unsigned int n) {
  unsigned fib1, fib2, fibo;
  int i;

  fib1 = 0;
  fib2 = 1;
  fibo = n;
  i = 2;  
  while (i <= n) { 
    fibo = fib1 + fib2;       
    fib1 = fib2;
    fib2 = fibo;
    i++;       
  }             
  return(fibo);
}

void main(void) { 
   int i;

   EnableInterrupts;
   #pragma MESSAGE DISABLE C4000 /* Condition Always True */
   while (TRUE) {
      counter = 0;
      for (i = 0; i <= 25; i++) {
         counter++;
         fiboCount = Fibonacci(counter);
      }      
   }
}
