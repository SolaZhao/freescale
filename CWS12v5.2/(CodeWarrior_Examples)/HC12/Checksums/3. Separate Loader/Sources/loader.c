/******************************************************************************
  FILE        : loader_asm.c 
  PURPOSE     : checksum demo/test file
  LANGUAGE    : ANSI-C
  -----------------------------------------------------------------------------
  HISTORY 
    19 sep 2002       Created.
 ******************************************************************************/

#include "hidef.h"
#include "checksum.h"

#ifdef __HC08__
#include "start08.h" /* for automatic startup data structure based checksums */
#elif defined(__HC12__)
#include "start12.h" /* for automatic startup data structure based checksums */
#else
#error "Not adapted for this target"
#endif

/*

    This modules shows how to actually check the main app before starting it.
    The idea is that this is the loader application which loads the main application somehow.
    We don't show this loading phase here. 
    Instead we do only check if something valid is already loaded. 
    If so we start it.

    Please read the readme.txt to see how to run this example.
 */

#pragma DATA_SEG LOADER_RAM
volatile unsigned char isValid;
#pragma DATA_SEG DEFAULT

// 0: main app is about to be checked.
// 1: main app is valid. Call it.
// 2: main app is invalid.

#define APP_CHECKSUM_AREA_START ((const char*)0xE042)
#define APP_CHECKSUM_AREA_END   ((const char*)(0xEFFF+1))
#define APP_CHECKSUM_AREA_LEN   (APP_CHECKSUM_AREA_END-APP_CHECKSUM_AREA_START)
#define APP_CHECKSUM_VALUE      (*(unsigned char*)0xE040)
#define APP_FIX_IDENT           (*(unsigned short*)0xE000)
#define APP_FIX_CHECKSUM_AREA   (void*)0xE002

#define APP_STARTUP_STRUCT_PTR ((struct _tagStartup*)(0xE042))

void CheckApp(void) { // Called by asm code to actually check the checksums
  unsigned char crc8;
  isValid=0;
  if (APP_FIX_IDENT == 0xCAFE) {
      /* check prm file based checksum */
#if __OPTION_ACTIVE__("-ot")  /* faster: use lookup table */
      crc8= _Checksum_CheckAreaCRC8_PreCalc(APP_CHECKSUM_AREA_START, APP_CHECKSUM_AREA_LEN);
#else
      crc8= _Checksum_CheckAreaCRC8(APP_CHECKSUM_AREA_START, APP_CHECKSUM_AREA_LEN, DEFAULT_CRC8_CHECKSUM, 0xFF);
#endif
      if (crc8 == APP_CHECKSUM_VALUE) {
#if 1 /* here we do check the automatic checksums also. Usually only one checksum would be calculated. */      
          /* check automatic checksum */
          if ( APP_STARTUP_STRUCT_PTR->checkSum == APP_FIX_CHECKSUM_AREA /* just some additional sanity checks */
             && APP_STARTUP_STRUCT_PTR->nofCheckSums > 0
             && APP_STARTUP_STRUCT_PTR->nofCheckSums < 100
             && _Checksum_Check(APP_STARTUP_STRUCT_PTR->checkSum, APP_STARTUP_STRUCT_PTR->nofCheckSums)) {
            /* everything is OK! */
            isValid= 1;
            return;
          }  
#else
          isValid =1;
          return;          
#endif
      }
  }      

  /* app is not OK */
  isValid= 2;
  return;
}
