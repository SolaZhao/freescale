/******************************************************************************
  FILE        : main.c 
  PURPOSE     : checksum demo/test file
  LANGUAGE    : ANSI-C
  -----------------------------------------------------------------------------
  HISTORY 
    19 sep 2002       Created.
 ******************************************************************************/

/* this module demonstrates a simple usage of the linker checksum computation feature */


#include "hidef.h"
#include "checksum.h"

#ifdef __HC08__
#include "start08.h" /* for automatic startup data structure based checksums */
#elif defined(__HC12__)
#include "start12.h" /* for automatic startup data structure based checksums */
#else
#error "Not adapted for this target"
#endif

#define CHECKSUM_FIRST_ADDR 0xE001
#define CHECKSUM_LAST_ADDR  0xFEFF
#define CHECKSUM_STORAGE_CRC8     (*(unsigned char*)0xE000)

static int IsSimplePrmCRCCheckSumOK(void) {
#if __OPTION_ACTIVE__("-ot") /* optimize for time */
  return _Checksum_CheckAreaCRC8_PreCalc((const void*)CHECKSUM_FIRST_ADDR, CHECKSUM_LAST_ADDR+1-CHECKSUM_FIRST_ADDR) == CHECKSUM_STORAGE_CRC8;
#else
  return _Checksum_CheckAreaCRC8((const void*)CHECKSUM_FIRST_ADDR, CHECKSUM_LAST_ADDR+1-CHECKSUM_FIRST_ADDR, DEFAULT_CRC8_CHECKSUM, 0xFF) == CHECKSUM_STORAGE_CRC8;
#endif
}

void main(void) {
  int okCNT= 0;  /* select and drag this assignment from the source to the memory window */
                  /* then change the code and see if the checksum fails */
  int failedCNT= 0; 
  for (;;) { /* for-ever */
    if (IsSimplePrmCRCCheckSumOK()) {
      okCNT++;      /* Checksum OK! */
    } else {
      failedCNT++; /* Checksum Failed! */
    }
  }
}
