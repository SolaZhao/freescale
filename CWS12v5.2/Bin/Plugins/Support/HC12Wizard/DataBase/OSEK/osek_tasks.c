#include "OSEKIncludes.h"

/* OSEK Tasks */
TASK (InitTask) {
   (void)SetRelAlarm(CyclicAlarm, 3, 20);
   (void)TerminateTask();
}

TASK (CyclicTask) {
   (void)TerminateTask();
}
