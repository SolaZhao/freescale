#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
/*$OSEKDecl$*//*$AsmDecl$*/
$$IF $$XGATE_CORE2$$
/*$XGATEDecl$*/
$$ENDIF
$$IF $$XGATE_CORE3$$
/*$XGATEDeclCore3$*/
$$ENDIF

$$IF $$CALL_DEVICE_INIT$$
void MCU_init(void); /* Device initialization function declaration */
$$ENDIF

void main(void) {
$$IF $$CALL_DEVICE_INIT$$
  MCU_init(); /* call Device Initialization */
$$ENDIF
  /* put your own code here */
  /*$XGATECall$*/
$$IF !$$CALL_DEVICE_INIT$$
	EnableInterrupts;
$$ENDIF
/*$AsmCall$*//*$OSEKCall$*/

  for(;;) {
$$IF $$CALL_DEVICE_INIT$$
    /* _FEED_COP(); by default, COP is disabled with device init. When enabling, also reset the watchdog. */
$$ELSE
    _FEED_COP(); /* feeds the dog */
$$ENDIF
  } /* loop forever */
  /* please make sure that you never leave main */
}
/*$OSEKTasks$*/