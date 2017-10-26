/*****************************************************
   Demo files:  Simple C++ demo program
 ----------------------------------------------------
   Copyright (c) HIWARE AG, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
#include "hidef.h"

#ifdef __cplusplus
/* NOTE: for simplicity reason, we are not using a dynamic heap to allocate objects */

class ListElem {  /* generic list class */
  protected:
    ListElem *next, *prev;
  public:
    void ListElem(const ListElem&);   /* default copy constructor */
    void ListElem(void) { next = NULL; prev = NULL; }  /* constructor */
    void ~ListElem(void) {} /* destructor */
};

class IntListElem: ListElem {  /* list containing an int elem */
  private:
    int elem;
  public:
    void IntListElem(const IntListElem&);/* default copy constructor */
    void IntListElem(void) { elem = 0; } /* constructor */
    void IntListElem(int initValue) { elem = initValue; } /* constructor */
    int operator + (IntListElem &second) {
      return this->elem + second.elem;
    }
};
#endif

void main(void) {
#ifdef __cplusplus
  IntListElem L1 = 3, L2 = 5;
  volatile int i;
  
  i = L1 + L2;
#endif
}

