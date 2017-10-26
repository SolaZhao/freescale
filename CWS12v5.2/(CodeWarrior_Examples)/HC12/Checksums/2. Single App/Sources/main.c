/******************************************************************************
  FILE        : main.c
  PURPOSE     : checksum demo/test file
  LANGUAGE    : ANSI-C
  -----------------------------------------------------------------------------
  HISTORY
    19 sep 2002       Created.
 ******************************************************************************/

/* this module demonstrates and checks various features of the checksum computation capabilities of the linker */


#include "hidef.h"
#include "checksum.h"

#ifdef __HC08__
#include "start08.h" /* for automatic startup data structure based checksums */
#elif defined(__HC12__)
#include "start12.h" /* for automatic startup data structure based checksums */
#else
#error "Not adapted for this target"
#endif

#if 0

How the checksum feature works.

This file does demonstrate two different ways of how the linker can compute checksums. The "PRM file Method" and the "Automatic linker controlled Method".

PRM file Method:
The linker can be instructed by some new commands in the prm file to compute the checksum over some areas.
All necessary information for this is specified in this structure:
For example (in the prm file):
CHECKSUM
    CHECKSUM_ENTRY
        METHOD_CRC_CCITT
        OF      READ_ONLY   0xE020 TO 0xFEFF
        INTO    READ_ONLY   0xE010 SIZE 2
        UNDEFINED 0xff
    END
END
This entry causes the computation of a checksum from 0xE020 up to 0xFEFF (including this address).
The checksum is calculated according to the CRC CCITT.
The EBNF of the CHECKSUM entry:
CHECKSUM=        "CHECKSUM" { CHECKSUM_ENTRY } "END".
CHECKSUM_ENTRY=  "CHECKSUM_ENTRY" CHECKSUM_METHOD [INIT_VAL] [POLYNOM] OF_AREA INTO_AREA [UNDEF_VAL] "END".
CHECKSUM_METHOD= "METHOD_CRC_CCITT"|"METHOD_CRC8"|"METHOD_CRC16"|"METHOD_CRC32"|"METHOD_ADD"|"METHOD_XOR".
INIT_VAL=        "INIT" number.
POLYNOM=         "POLY" number.
OF_AREA=        "OF" MEMORY_AREA.
INTO_AREA=       "INTO" MEMORY_AREA.
MEMORY_AREA=     CHECKSUM_SPACE number (("TO" number)|("SIZE" number)).
UNDEF_VAL=       "UNDEFINED" number.
CHECKSUM_SPACE=  "READ_ONLY" | "CODE".

CHECKSUM: contains a list of checksums descriptions to be computed.
CHECKSUM_ENTRY: one single checksum computation description.
CHECKSUM_METHOD: How to compute the checksum.
- METHOD_XOR. The elements of the memory area are xored together.
  The element size is defined by the size of the INTO_AREA.
- METHOD_ADD. The elements of the memory area are added together.
  The element size is defined by the size of the INTO_AREA.
- METHOD_CRC_CCITT. A 16-bit CRC (cyclic redundancy check) checksum according
  to CRC CCITT is computed over all bytes in the area. The INTO_AREA size must be 2 bytes.
- METHOD_CRC16. A 16-bit CRC checksum according to the commonly used CRC 16 is computed
  over all bytes in the area. The INTO_AREA size must be 2 bytes.
- METHOD_CRC32. A 32-bit CRC checksum according to the commonly used CRC 32 is computed
  over all bytes in the area. The INTO_AREA size must be 4 bytes.
INIT_VAL: The value to start the checksum computation. This value is provided to compute any kind of CRC checksum.
  However, specifing it does not increase the robustness of the checksum and therefore the default values of -1 for CRC
  checksums and 0 for addition and XOR is usually sufficient.
POLYNOM: The polynom specifies how a set bit in the code should affect the checksum. For certain polynoms especially efficient
  checksums exists. 0 is not a valid choice.
OF_AREA: The area of which the checksum should be computed.
INTO_AREA: The area into which the computed checksum should be stored. Should be distinct from the OF_AREA and from any other placement in the prm file.
MEMORY_AREA: Describes a memory area. The same syntax as in the placement is used.
UNDEF_VAL: The value to be used in the checksum computation for areas not covered by the application.
  It is recommended to use the FILL directive to avoid undefined areas.
    E.g.:
    SEGMENTS
      MY_ROM = READ_ONLY   0xE020 TO 0xFEFF FILL 0xFF;
CHECKSUM_SPACE: The address space. Use "READ_ONLY" unless your target uses a harward architecture and you are refering to the "CODE" address space.

Example:
Assume the following memory content:
0x1000 02 02 03 04
Then the XOR 1 byte checksum from 0x1000 to 0x1003 is 0x06 (=0x02^0x02^0x03^0x04).
Notes:
- METHOD_XOR is the fastest method to compute together with METHOD_ADD.
- However, for METHOD_XOR and METHOD_ADD, regular multiple one bit changes can cancel each other out. The CRC methods avoid this weakness.
  As example, assume that both 0x1000 and 0x1001 are getting cleared, then, the XOR checksum does not change. There are similar cases for the addition as well.
- METHOD_XOR/METHOD_ADD do also support to compute the checksum with larger element sizes.
  The element size is taken as the size of the INTO_AREA part.
  With a element size of 2, the checksum of the example would be 0x0506 (= 0x2020 ^ 0x0304).
  Larger element sizes do allow a faster computation of the checksums on 16 or 32 bit machines.
  The size and the address of the OF_AREA part have to be a multiple of the element size.
  CRC checksums do only compute the values byte wise (or more precisely they are even defined bitwise).
- Often, the actual size of the area to be checked is not known in advance.
  Depending on how much code the compiler is generating for C source code, the placements do fill up more or less.
  This method however does not support varying sizes. Instead, the unused areas in the placement
  have to be filled with the FILL directive to a known value.
  This causes a certain overhead as the checksum is computed over these fill areas as well.

Automatic linker controlled Method:
The linker itself is the one who knows all the memory areas used by an application.
Therefore this method is using this knowledge to generate a data structure,
which then can be used at runtime to validate the complete code.
The linker is providing this information similar to the way it provides copy down and zero out information.
The startup data structure has to have additional fields:

extern struct _tagStartup {
....
     struct __Checksum* checkSum;
     int nofCheckSums;
....

The structure __Checksum is defined in the header file checksum.h:
struct __Checksum {
    void* start;
    unsigned int len;
#if _CHECKSUM_CRC_CCITT
    _CheckSum2ByteType checkSumCRC_CCITT;
#endif
#if _CHECKSUM_CRC_16
    _CheckSum2ByteType checkSumCRC16;
#endif
#if _CHECKSUM_CRC_32
    _CheckSum4ByteType checkSumCRC32;
#endif
#if _CHECKSUM_ADD_BYTE
    _CheckSum1ByteType checkSumByteAdd;
#endif
#if _CHECKSUM_XOR_BYTE
    _CheckSum1ByteType checkSumByteXor;
#endif
};

The __checksum structure is allocated by the linker in a ".checksum" section after all the other code.
The areas do cover all the used segments in the prm file. FILL areas are not checked.
The checksum types to be computed is derived by the linker by using the field names of the __Checksum structure.
Usually only one of the alternatives should be present, but the linker does support to compute any combination checksum methods together.
Automatic struct detection:
The linker does read the debug information of the module containing _tagStartup
to detect which checksums it should actually generate and how the structure is built.
Because of this, the structure used by the compiler does always match the structure generated by the linker.
The linker does know the structure field names and the name __Checksum of the checksum structure itself. These names cannot be changed.
The types of the structure fields can be adapted to the actual needs.

.checksum section:
The ".checksum" section must be the last section in a placement. It is allowed to be after the .copy section.
If it is not mentioned in the prm file, its automatically allocated when needed.
The checksum areas do not cover .checksum itself.
Notes:
The __Checksum structure can also contain checkSumWordAdd, checkSumLongAdd, checkSumWordXor and checkSumLongXor fields
to have checksums computed with larger element sizes. However, as the FILL areas are not considered,
the len field might be not a multiple of the element size. When this happens, 0 has to be assumed for the missing bytes.
Because this is not handled in the provided example code, automatic generated word or long size add or xor checksums are not officially supported.

Runtime support
The file checksum.h does contain functions and utilities to compute the various checksums.
The corresponding source file is checksum.c. Check it to find out how to compute the various checksums.

The automatic generated checksum feature does not need any customer code.
A simple call "_Checksum_Check(_startupData.checkSum, _startupData.nofCheckSums);" does state if the checksums are OK.

Comparison:   Automatic method                                       Prm Method
Complexity    Really easy to use.                                    More Complicated to use.
              Just call _Checksum_Check and the return value         The prm file has to be setup, with different things in mind.
              states whether the checksum is correct.                All the addresses of all memory areas have to be duplicated in the C source and
                                                                     int the prm file at 2 places.
Robustness    Good. Nothing (or few things) to configure.            Maybe values have to match.
              Automatic adaptation of the linker for C source file
              changes.
Control       Poor. Only if a segment should be checked and the      Everything is in full user control.
              method can be controlled.
Memory Usage  Needs few more memory because of the control           Needs not one unnecessary byte. As optimal as possible.
              structures.
Exec. Time    For execution time only innermost loop is significant. For execution time only innermost loop is significant.
              Both methods are using the same.                       Both methods are using the same.

#endif /* description */

/* PRM file method test routines */

enum CheckType {
  CheckSumAdd=         '+', /* Add */
  CheckSumXor=         '^', /* XOR */
  CheckSumCRC_CCITT=   'c', /* CRC CCITT */
  CheckSumCRC_8=       '8', /* CRC8 with default poly */
  CheckSumCRC_16=      '6', /* CRC16 with default poly */
  CheckSumCRC_32=      '2', /* CRC32 with default poly */
  CheckSumCRC_CCITT_P= 'C', /* precomputed CRC CCITT */
  CheckSumCRC_8_P=     '9', /* precomputed CRC8 with default poly */
  CheckSumCRC_16_P=    '7', /* precomputed CRC16 with default poly */
  CheckSumCRC_32_P=    '3', /* precomputed CRC32 with default poly */
  CheckSumCRC_8_spec=  's', /* CRC8 with non default poly and special init value */
};

struct CheckSums {
  unsigned char size;
  enum CheckType type;
  void* start;
  void* end;
  void* cmp;
} checkSums[]= {
 /*  0 */  {4, CheckSumAdd,         (void*)0xE020, (void*)0xFF00, (void*)0xE000},
 /*  1 */  {2, CheckSumAdd,         (void*)0xE020, (void*)0xFF00, (void*)0xE004},
 /*  2 */  {1, CheckSumAdd,         (void*)0xE020, (void*)0xFF00, (void*)0xE006},
 /*  3 */  {4, CheckSumXor,         (void*)0xE020, (void*)0xFF00, (void*)0xE008},
 /*  4 */  {2, CheckSumXor,         (void*)0xE020, (void*)0xFF00, (void*)0xE00C},
 /*  5 */  {1, CheckSumXor,         (void*)0xE020, (void*)0xFF00, (void*)0xE00E},
 /*  6 */  {2, CheckSumCRC_CCITT,   (void*)0xE020, (void*)0xFF00, (void*)0xE010},
 /*  7 */  {2, CheckSumCRC_CCITT_P, (void*)0xE020, (void*)0xFF00, (void*)0xE010},
 /*  8 */  {1, CheckSumCRC_8,       (void*)0xE020, (void*)0xFF00, (void*)0xE018},
 /*  9 */  {1, CheckSumCRC_8_P,     (void*)0xE020, (void*)0xFF00, (void*)0xE018},
 /* 10 */  {2, CheckSumCRC_16,      (void*)0xE020, (void*)0xFF00, (void*)0xE012},
 /* 11 */  {2, CheckSumCRC_16_P,    (void*)0xE020, (void*)0xFF00, (void*)0xE012},
 /* 12 */  {4, CheckSumCRC_32,      (void*)0xE020, (void*)0xFF00, (void*)0xE014},
 /* 13 */  {4, CheckSumCRC_32_P,    (void*)0xE020, (void*)0xFF00, (void*)0xE014},
 /* 14 */  {1, CheckSumCRC_8_spec,  (void*)0xE020, (void*)0xFF00, (void*)0xE019},
};

/* here we store some timings to compare the algorithms */
unsigned long simplePrmAddTime;
unsigned long simplePrmCRCTime;
unsigned long prmTimes[sizeof(checkSums)/sizeof(checkSums[0])];
unsigned long allAutoTime;

/* Timings do only work with the optional Timer component loaded in the simulator. */
/* Timer component: Every write to its address range at 0x210 does update the read values with the current time (in cycles) */
/* If the Timer component is not available, all the measured times will be 0. */

volatile unsigned long currentTime@0x210; /* Do not move: memory actually implemented by Timer component */

unsigned long GetTime(unsigned long* pLastTime) {
   unsigned long time;
   currentTime=0; /* Timer component: set currentTime to the current time */
   time= currentTime-*pLastTime;
   *pLastTime= currentTime;
   return time;
}

#define CHECKSUM_FIRST_ADDR 0xE020
#define CHECKSUM_LAST_ADDR  0xFEFF
#define CHECKSUM_STORAGE_BYTE_ADD (*(unsigned char*)0xE006)
#define CHECKSUM_STORAGE_CRC_CCITT (*(unsigned short*)0xE010)

static int IsSimplePrmCheckSumOK(void) {
  unsigned char* ptr= (unsigned char*)CHECKSUM_FIRST_ADDR;
  unsigned char checkSum=0;
  while (ptr != (unsigned char*)CHECKSUM_LAST_ADDR+1) {
    checkSum += *ptr;
    ptr++;
  }
  return (checkSum & 0xff) == CHECKSUM_STORAGE_BYTE_ADD;
}

static int IsSimplePrmCRCCheckSumOK(void) {
  return _Checksum_CheckAreaCRC_CCITT((const void*)CHECKSUM_FIRST_ADDR, CHECKSUM_LAST_ADDR+1-CHECKSUM_FIRST_ADDR) == CHECKSUM_STORAGE_CRC_CCITT;
}


static int AreAllPrmChecksSumsOK(void) {
  int i;
  for (i=0; i < sizeof(checkSums)/sizeof(checkSums[0]); i++) {
    unsigned long checkSumVal;
    unsigned long expectedChecksum;
    const void* start= (const void*)checkSums[i].start;
    unsigned int len= (const unsigned char*)checkSums[i].end - (const unsigned char*)start;
    enum CheckType checkSumType= checkSums[i].type;
    unsigned char checkSize  = checkSums[i].size;
    unsigned long time=0;
    /* read the expected checksum */
    if (checkSize == 1) {
      expectedChecksum= *(unsigned char*)checkSums[i].cmp;
    } else if (checkSize == 2) {
      expectedChecksum= *(unsigned short*)checkSums[i].cmp;
    } else {
      /* (checkSize == 4) */
      expectedChecksum= *(unsigned long*)checkSums[i].cmp;
    }
    (void)GetTime(&time);  /* init timer */

    /* calculate the actual checksum */
    switch (checkSumType) {
      case CheckSumCRC_CCITT:   checkSumVal= _Checksum_CheckAreaCRC_CCITT(start, len);                         break;
      case CheckSumCRC_CCITT_P: checkSumVal= _Checksum_CheckAreaCRC_CCITT_PreCalc(start, len);                 break;
      case CheckSumCRC_8:       checkSumVal= _Checksum_CheckAreaCRC8(start, len, DEFAULT_CRC8_CHECKSUM, -1);   break;
      case CheckSumCRC_8_P:     checkSumVal= _Checksum_CheckAreaCRC8_PreCalc(start, len);                      break;
      case CheckSumCRC_16:      checkSumVal= _Checksum_CheckAreaCRC16(start, len, DEFAULT_CRC16_CHECKSUM, -1); break;
      case CheckSumCRC_16_P:    checkSumVal= _Checksum_CheckAreaCRC16_PreCalc(start, len);                     break;
      case CheckSumCRC_32:      checkSumVal= _Checksum_CheckAreaCRC32(start, len, DEFAULT_CRC32_CHECKSUM, -1); break;
      case CheckSumCRC_32_P:    checkSumVal= _Checksum_CheckAreaCRC32_PreCalc(start, len);                     break;
      case CheckSumCRC_8_spec:  checkSumVal= _Checksum_CheckAreaCRC8(start, len, 0x81, 0x01);                  break;
      case CheckSumAdd:
        if (checkSize == 1) {
          checkSumVal= _Checksum_CheckAreaByteAdd(start, len);
        } else if (checkSize == 2) {
          checkSumVal= _Checksum_CheckAreaWordAdd(start, len);
        } else {
          /* (checkSize == 4) */
          checkSumVal= _Checksum_CheckAreaLongAdd(start, len);
        }
        break;
      case CheckSumXor:
        if (checkSize == 1) {
          checkSumVal= _Checksum_CheckAreaByteXor(start, len);
        } else if (checkSize == 2) {
          checkSumVal= _Checksum_CheckAreaWordXor(start, len);
        } else {
          /* (checkSize == 4) */
          checkSumVal= _Checksum_CheckAreaLongXor(start, len);
        }
        break;
    }
    prmTimes[i]= GetTime(&time);  /* get time */
    if (checkSumVal != expectedChecksum) {
      return FALSE;
    }
  }
  return TRUE;
}

/* main test application  */

int isSimpleAddChecksumOK; /* simple checksum computed by added the values in some memory area */
int isSimpleCRCChecksumOK; /* simple checksum computed by computing a CRC in a memory area */
int areAllPrmChecksumsOK;  /* are all the checksums computed because of the prm entry ok. Uses the array checkSums above to find them all */
int areAutomaticChecksumsOK; /* are all the checksums automatically generated by the linker togehter with position/size info correct? */
int areAutomaticChecksumsOkAfterModi; /* test if checksums do fail (test only works when the simulator is configured accordinly) */

int cnt; /* counts the loops */

#define ADDITIONAL_CONST_AREA 0x0220 /* actually its RAM */
const char Data[] @ ADDITIONAL_CONST_AREA ="Hallo World. This is to test the checksum stuff a little bit more";
const char Data1[] @ (ADDITIONAL_CONST_AREA+101) ="OddSized";
const char Data2[] @ (ADDITIONAL_CONST_AREA+130) ="OddSized";

void main(void) {
  for (;;) {
    unsigned long time=0;
    (void)GetTime(&time);  /* init timer */
    isSimpleAddChecksumOK= IsSimplePrmCheckSumOK();
    simplePrmAddTime= GetTime(&time);
    isSimpleCRCChecksumOK= IsSimplePrmCRCCheckSumOK();
    simplePrmCRCTime= GetTime(&time);
    areAllPrmChecksumsOK= AreAllPrmChecksSumsOK();
    (void)GetTime(&time);  /* init timer */
    areAutomaticChecksumsOK= _Checksum_Check(_startupData.checkSum, _startupData.nofCheckSums);
    allAutoTime= GetTime(&time);
    *((char*)&Data[0])= 'B'; /* can we write here? */
    /* if the debugger stops here, we probably cannot write. In the simulator, you the user, could help? */
    areAutomaticChecksumsOkAfterModi = _Checksum_Check(_startupData.checkSum, _startupData.nofCheckSums);
    areAutomaticChecksumsOkAfterModi ^= (Data[0] != 'H'); /* depending on the memory configuration, we can or cannot write into RAM. If we can, a failure is actually OK. Otherwise not */
    *((char*)&Data[0])= 'H'; /* undo the change for the next round */

    cnt++;
  }
}