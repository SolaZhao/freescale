#ifndef OSEKINCLUDES_H
#define OSEKINCLUDES_H
/*
 * Including OSEK header files
 */

/********************** System Include Files ********************************/
#if !defined(OSPROPH)
#include    "osprop.h"                /* OS Properties */
#else   /* !defined(OSPROPH) */
#include    OSPROPH                   /* OS Properties */
#endif  /* !defined(OSPROPH) */

#include <osapi.h>                    /* API calls */

/********************** User's type definition Files ************************/
#if !defined(APPTYPESH)
#include    "usertypes.h"             /* header file for sample typedefs, defines etc. */
#else   /* !defined(APPTYPESH) */
#include    APPTYPESH                 /* header file for sample typedefs, defines etc. */
#endif  /* !defined(APPTYPESH) */

/********************** Application configuration header File ***************/
#if !defined(OSCFGH)
#include    "cfg.h"                   /* Application configuration header file */
#else   /* !defined(OSCFGH) */
#include    OSCFGH                    /* Application configuration header file */
#endif  /* !defined(OSCFGH) */

#endif /* OSEKINCLUDES_H */
