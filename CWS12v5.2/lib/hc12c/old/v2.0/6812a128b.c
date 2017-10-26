/*
** ###################################################################
**
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**
**     Filename  : 6812a128b.c
** 
**     Processor : MC9S12A128BCPV
**
**     Version   : Driver 01.00
**
**     Compiler  : Metrowerks HC12 C Compiler
**
**     Date/Time : 03.12.2002, 07:29
**
**     Abstract  :
**
**         This header implements the mapping of IO devices.
**
**     Settings  :
**
**
**
**     Contents  :
**
**         No public methods
**
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2002
**
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
**
** ###################################################################
*/
/* Based on CPU DB MC9S12A128_112, version 2.87.227 */
#include <6812a128b.h>

volatile ARMCOPSTR _ARMCOP;    /* CRG COP Timer Arm/Reset Register */
volatile ATD0CTL2STR _ATD0CTL2; /* ATD Control Register 2 */
volatile ATD0CTL3STR _ATD0CTL3; /* ATD Control Register 3 */
volatile ATD0CTL4STR _ATD0CTL4; /* ATD Control Register 4 */
volatile ATD0CTL5STR _ATD0CTL5; /* ATD Control Register 5 */
volatile ATD0DIENSTR _ATD0DIEN; /* ATD Input Enable Mask Register */
volatile ATD0DR0HSTR _ATD0DR0H; /* A/D Conversion Result Register 0 High */
volatile ATD0DR0LSTR _ATD0DR0L; /* A/D Conversion Result Register 0 Low */
volatile ATD0DR1HSTR _ATD0DR1H; /* A/D Conversion Result Register 1 High */
volatile ATD0DR1LSTR _ATD0DR1L; /* A/D Conversion Result Register 1 Low */
volatile ATD0DR2HSTR _ATD0DR2H; /* A/D Conversion Result Register 2 High */
volatile ATD0DR2LSTR _ATD0DR2L; /* A/D Conversion Result Register 2 Low */
volatile ATD0DR3HSTR _ATD0DR3H; /* A/D Conversion Result Register 3 High */
volatile ATD0DR3LSTR _ATD0DR3L; /* A/D Conversion Result Register 3 Low */
volatile ATD0DR4HSTR _ATD0DR4H; /* A/D Conversion Result Register 4 High */
volatile ATD0DR4LSTR _ATD0DR4L; /* A/D Conversion Result Register 4 Low */
volatile ATD0DR5HSTR _ATD0DR5H; /* A/D Conversion Result Register 5 High */
volatile ATD0DR5LSTR _ATD0DR5L; /* A/D Conversion Result Register 5 Low */
volatile ATD0DR6HSTR _ATD0DR6H; /* A/D Conversion Result Register 6 High */
volatile ATD0DR6LSTR _ATD0DR6L; /* A/D Conversion Result Register 6 Low */
volatile ATD0DR7HSTR _ATD0DR7H; /* A/D Conversion Result Register 7 High */
volatile ATD0DR7LSTR _ATD0DR7L; /* A/D Conversion Result Register 7 Low */
volatile ATD0STAT0STR _ATD0STAT0; /* A/D Status Register 0 */
volatile ATD0STAT1STR _ATD0STAT1; /* A/D Status Register 1 */
volatile ATD1CTL2STR _ATD1CTL2; /* ATD Control Register 2 */
volatile ATD1CTL3STR _ATD1CTL3; /* ATD Control Register 3 */
volatile ATD1CTL4STR _ATD1CTL4; /* ATD Control Register 4 */
volatile ATD1CTL5STR _ATD1CTL5; /* ATD Control Register 5 */
volatile ATD1DIENSTR _ATD1DIEN; /* ATD Input Enable Mask Register */
volatile ATD1DR0HSTR _ATD1DR0H; /* A/D Conversion Result Register 0 High */
volatile ATD1DR0LSTR _ATD1DR0L; /* A/D Conversion Result Register 0 Low */
volatile ATD1DR1HSTR _ATD1DR1H; /* A/D Conversion Result Register 1 High */
volatile ATD1DR1LSTR _ATD1DR1L; /* A/D Conversion Result Register 1 Low */
volatile ATD1DR2HSTR _ATD1DR2H; /* A/D Conversion Result Register 2 High */
volatile ATD1DR2LSTR _ATD1DR2L; /* A/D Conversion Result Register 2 Low */
volatile ATD1DR3HSTR _ATD1DR3H; /* A/D Conversion Result Register 3 High */
volatile ATD1DR3LSTR _ATD1DR3L; /* A/D Conversion Result Register 3 Low */
volatile ATD1DR4HSTR _ATD1DR4H; /* A/D Conversion Result Register 4 High */
volatile ATD1DR4LSTR _ATD1DR4L; /* A/D Conversion Result Register 4 Low */
volatile ATD1DR5HSTR _ATD1DR5H; /* A/D Conversion Result Register 5 High */
volatile ATD1DR5LSTR _ATD1DR5L; /* A/D Conversion Result Register 5 Low */
volatile ATD1DR6HSTR _ATD1DR6H; /* A/D Conversion Result Register 6 High */
volatile ATD1DR6LSTR _ATD1DR6L; /* A/D Conversion Result Register 6 Low */
volatile ATD1DR7HSTR _ATD1DR7H; /* A/D Conversion Result Register 7 High */
volatile ATD1DR7LSTR _ATD1DR7L; /* A/D Conversion Result Register 7 Low */
volatile ATD1STAT0STR _ATD1STAT0; /* A/D Status Register 0 */
volatile ATD1STAT1STR _ATD1STAT1; /* A/D Status Register 1 */
volatile BDMCCRSTR _BDMCCR;    /* BDM CCR Holding Register */
volatile BDMINRSTR _BDMINR;    /* BDM Internal Register Position Register */
volatile BDMSTSSTR _BDMSTS;    /* BDM Status Register */
volatile BKP0HSTR _BKP0H;      /* First Address High Byte Breakpoint Register */
volatile BKP0LSTR _BKP0L;      /* First Address Low Byte Breakpoint Register */
volatile BKP0XSTR _BKP0X;      /* First Address Memory Expansion Breakpoint Register */
volatile BKP1HSTR _BKP1H;      /* Data (Second Address) High Byte Breakpoint Register */
volatile BKP1LSTR _BKP1L;      /* Data (Second Address) Low Byte Breakpoint Register */
volatile BKP1XSTR _BKP1X;      /* Second Address Memory Expansion Breakpoint Register */
volatile BKPCT0STR _BKPCT0;    /* Breakpoint Control Register 0 */
volatile BKPCT1STR _BKPCT1;    /* Breakpoint Control Register 1 */
volatile CFORCSTR _CFORC;      /* Timer Compare Force Register */
volatile CLKSELSTR _CLKSEL;    /* CRG Clock Select Register */
volatile COPCTLSTR _COPCTL;    /* CRG COP Control Register */
volatile CRGFLGSTR _CRGFLG;    /* CRG Flags Register */
volatile CRGINTSTR _CRGINT;    /* CRG Interrupt Enable Register */
volatile CTCTLSTR _CTCTL;      /* CRG Test Control Register */
volatile CTFLGSTR _CTFLG;      /* CRG Test Flags Register */
volatile DDRASTR _DDRA;        /* Port A Data Direction Register */
volatile DDRBSTR _DDRB;        /* Port B Data Direction Register */
volatile DDRESTR _DDRE;        /* Port E Data Direction Register */
volatile DDRHSTR _DDRH;        /* Port H Data Direction Register */
volatile DDRJSTR _DDRJ;        /* Port J Data Direction Register */
volatile DDRKSTR _DDRK;        /* Port K Data Direction Register */
volatile DDRMSTR _DDRM;        /* Port M Data Direction Register */
volatile DDRPSTR _DDRP;        /* Port P Data Direction Register */
volatile DDRSSTR _DDRS;        /* Port S Data Direction Register */
volatile DDRTSTR _DDRT;        /* Port S Data Direction Register */
volatile DLYCTSTR _DLYCT;      /* Delay Counter Control Register */
volatile EBICTLSTR _EBICTL;    /* External Bus Interface Control */
volatile ECLKDIVSTR _ECLKDIV;  /* EEPROM Clock Divider Register */
volatile ECMDSTR _ECMD;        /* EEPROM Command Buffer and Register */
volatile ECNFGSTR _ECNFG;      /* EEPROM Configuration Register */
volatile EPROTSTR _EPROT;      /* EEPROM Protection Register */
volatile ESTATSTR _ESTAT;      /* EEPROM Status Register */
volatile FCLKDIVSTR _FCLKDIV;  /* Flash Clock Divider Register */
volatile FCMDSTR _FCMD;        /* Flash Command Buffer and Register */
volatile FCNFGSTR _FCNFG;      /* Flash Configuration Register */
volatile FPROTSTR _FPROT;      /* Flash Protection Register */
volatile FSECSTR _FSEC;        /* Flash Security Register */
volatile FSTATSTR _FSTAT;      /* Flash Status Register */
volatile HPRIOSTR _HPRIO;      /* Highest Priority I Interrupt */
volatile IBADSTR _IBAD;        /* IIC Address Register */
volatile IBCRSTR _IBCR;        /* IIC Control Register */
volatile IBDRSTR _IBDR;        /* IIC Data I/O Register */
volatile IBFDSTR _IBFD;        /* IIC Frequency Divider Register */
volatile IBSRSTR _IBSR;        /* IIC Status Register */
volatile ICOVWSTR _ICOVW;      /* Input Control Overwrite Register */
volatile ICPARSTR _ICPAR;      /* Input Control Pulse Accumulator Register */
volatile ICSYSSTR _ICSYS;      /* Input Control System Control Register */
volatile INITEESTR _INITEE;    /* Initialization of Internal EEPROM Position Register */
volatile INITRGSTR _INITRG;    /* Initialization of Internal Register Position Register */
volatile INITRMSTR _INITRM;    /* Initialization of Internal RAM Position Register */
volatile INTCRSTR _INTCR;      /* Interrupt Control Register */
volatile ITCRSTR _ITCR;        /* Interrupt Test Control Register */
volatile ITESTSTR _ITEST;      /* Interrupt Test Register */
volatile MCCNThiSTR _MCCNThi;  /* Modulus Down-Counter Count Register High */
volatile MCCNTloSTR _MCCNTlo;  /* Modulus Down-Counter Count Register Low */
volatile MCCTLSTR _MCCTL;      /* Modulus Down Counter underflow */
volatile MCFLGSTR _MCFLG;      /* 16-Bit Modulus Down Counter Flag Register */
volatile MEMSIZ0STR _MEMSIZ0;  /* Memory Size Register Zero */
volatile MEMSIZ1STR _MEMSIZ1;  /* Memory Size Register One */
volatile MISCSTR _MISC;        /* Miscellaneous Mapping Control Register */
volatile MODESTR _MODE;        /* Mode Register */
volatile MODRRSTR _MODRR;      /* Module Routing Register */
volatile MTST0STR _MTST0;      /* MTST0 */
volatile MTST1STR _MTST1;      /* MTST1 */
volatile OC7DSTR _OC7D;        /* Output Compare 7 Data Register */
volatile OC7MSTR _OC7M;        /* Output Compare 7 Mask Register */
volatile PA0HSTR _PA0H;        /* 8-Bit Pulse Accumulators Holding Register */
volatile PA1HSTR _PA1H;        /* 8-Bit Pulse Accumulators Holding Register */
volatile PA2HSTR _PA2H;        /* 8-Bit Pulse Accumulators Holding Register */
volatile PA3HSTR _PA3H;        /* 8-Bit Pulse Accumulators Holding Register */
volatile PACN0STR _PACN0;      /* Pulse Accumulators Count Register 0 */
volatile PACN1STR _PACN1;      /* Pulse Accumulators Count Register 1 */
volatile PACN2STR _PACN2;      /* Pulse Accumulators Count Register 2 */
volatile PACN3STR _PACN3;      /* Pulse Accumulators Count Register 3 */
volatile PACTLSTR _PACTL;      /* 16-Bit Pulse Accumulator A Control Register */
volatile PAFLGSTR _PAFLG;      /* Pulse Accumulator A Flag Register */
volatile PARTIDHSTR _PARTIDH;  /* Part ID Register High */
volatile PARTIDLSTR _PARTIDL;  /* Part ID Register Low */
volatile PBCTLSTR _PBCTL;      /* 16-Bit Pulse Accumulator B Control Register */
volatile PBFLGSTR _PBFLG;      /* Pulse Accumulator B Flag Register */
volatile PEARSTR _PEAR;        /* Port E Assignment Register */
volatile PERHSTR _PERH;        /* Port H Pull Device Enable Register */
volatile PERJSTR _PERJ;        /* Port J Pull Device Enable Register */
volatile PERMSTR _PERM;        /* Port M Pull Device Enable Register */
volatile PERPSTR _PERP;        /* Port P Pull Device Enable Register */
volatile PERSSTR _PERS;        /* Port S Pull Device Enable Register */
volatile PERTSTR _PERT;        /* Port H Pull Device Enable Register */
volatile PIEHSTR _PIEH;        /* Port H Interrupt Enable Register */
volatile PIEJSTR _PIEJ;        /* Port J Interrupt Enable Register */
volatile PIEPSTR _PIEP;        /* Port P Interrupt Enable Register */
volatile PIFHSTR _PIFH;        /* Port H Interrupt Flag Register */
volatile PIFJSTR _PIFJ;        /* Port J Interrupt Flag Register */
volatile PIFPSTR _PIFP;        /* Port P Interrupt Flag Register */
volatile PLLCTLSTR _PLLCTL;    /* CRG PLL Control Register */
volatile PORTASTR _PORTA;      /* Port A Register */
volatile PORTAD0STR _PORTAD0;  /* Port AD0 Register */
volatile PORTAD1STR _PORTAD1;  /* Port AD1 Register */
volatile PORTBSTR _PORTB;      /* Port B Register */
volatile PORTESTR _PORTE;      /* Port E Register */
volatile PORTKSTR _PORTK;      /* Port K Data Register */
volatile PPAGESTR _PPAGE;      /* Page Index Register */
volatile PPSHSTR _PPSH;        /* Port H Polarity Select Register */
volatile PPSJSTR _PPSJ;        /* PortJP Polarity Select Register */
volatile PPSMSTR _PPSM;        /* Port M Polarity Select Register */
volatile PPSPSTR _PPSP;        /* Port P Polarity Select Register */
volatile PPSSSTR _PPSS;        /* Port S Polarity Select Register */
volatile PPSTSTR _PPST;        /* Port T Polarity Select Register */
volatile PTHSTR _PTH;          /* Port H I/O Register */
volatile PTIHSTR _PTIH;        /* Port H Input Register */
volatile PTIJSTR _PTIJ;        /* Port J Input Register */
volatile PTIMSTR _PTIM;        /* Port M Input */
volatile PTIPSTR _PTIP;        /* Port P Input */
volatile PTISSTR _PTIS;        /* Port S Input */
volatile PTITSTR _PTIT;        /* Port S Input */
volatile PTJSTR _PTJ;          /* Port J I/O Register */
volatile PTMSTR _PTM;          /* Port M I/O Register */
volatile PTPSTR _PTP;          /* Port P I/O Register */
volatile PTSSTR _PTS;          /* Port S Polarity Select Register */
volatile PTTSTR _PTT;          /* Port T I/O Register */
volatile PUCRSTR _PUCR;        /* Pull-Up Control Register */
volatile PWMCAESTR _PWMCAE;    /* PWM Center Align Enable Register */
volatile PWMCLKSTR _PWMCLK;    /* PWM Clock Select Register */
volatile PWMCNT0STR _PWMCNT0;  /* PWM Channel Counter Register */
volatile PWMCNT1STR _PWMCNT1;  /* PWM Channel Counter Register */
volatile PWMCNT2STR _PWMCNT2;  /* PWM Channel Counter Register */
volatile PWMCNT3STR _PWMCNT3;  /* PWM Channel Counter Register */
volatile PWMCNT4STR _PWMCNT4;  /* PWM Channel Counter Register */
volatile PWMCNT5STR _PWMCNT5;  /* PWM Channel Counter Register */
volatile PWMCNT6STR _PWMCNT6;  /* PWM Channel Counter Register */
volatile PWMCNT7STR _PWMCNT7;  /* PWM Channel Counter Register */
volatile PWMCTLSTR _PWMCTL;    /* PWM Control Register */
volatile PWMDTY0STR _PWMDTY0;  /* PWM Channel Duty Register */
volatile PWMDTY1STR _PWMDTY1;  /* PWM Channel Duty Register */
volatile PWMDTY2STR _PWMDTY2;  /* PWM Channel Duty Register */
volatile PWMDTY3STR _PWMDTY3;  /* PWM Channel Duty Register */
volatile PWMDTY4STR _PWMDTY4;  /* PWM Channel Duty Register */
volatile PWMDTY5STR _PWMDTY5;  /* PWM Channel Duty Register */
volatile PWMDTY6STR _PWMDTY6;  /* PWM Channel Duty Register */
volatile PWMDTY7STR _PWMDTY7;  /* PWM Channel Duty Register */
volatile PWMESTR _PWME;        /* PWM Enable Register */
volatile PWMPER0STR _PWMPER0;  /* PWM Channel Period Register */
volatile PWMPER1STR _PWMPER1;  /* PWM Channel Period Register */
volatile PWMPER2STR _PWMPER2;  /* PWM Channel Period Register */
volatile PWMPER3STR _PWMPER3;  /* PWM Channel Period Register */
volatile PWMPER4STR _PWMPER4;  /* PWM Channel Period Register */
volatile PWMPER5STR _PWMPER5;  /* PWM Channel Period Register */
volatile PWMPER6STR _PWMPER6;  /* PWM Channel Period Register */
volatile PWMPER7STR _PWMPER7;  /* PWM Channel Period Register */
volatile PWMPOLSTR _PWMPOL;    /* PWM Polarity Register */
volatile PWMPRCLKSTR _PWMPRCLK; /* PWM Prescale Clock Select Register */
volatile PWMSCLASTR _PWMSCLA;  /* PWM Scale A Register */
volatile PWMSCLBSTR _PWMSCLB;  /* PWM Scale B Register */
volatile PWMSDNSTR _PWMSDN;    /* PWM Shutdown Register */
volatile RDRHSTR _RDRH;        /* Port H Reduced Drive Register */
volatile RDRIVSTR _RDRIV;      /* Reduced Drive of I/O Lines */
volatile RDRJSTR _RDRJ;        /* Port J Reduced Drive Register */
volatile RDRMSTR _RDRM;        /* Port M Reduced Drive Register */
volatile RDRPSTR _RDRP;        /* Port P Reduced Drive Register */
volatile RDRSSTR _RDRS;        /* Port S Reduced Drive Register */
volatile RDRTSTR _RDRT;        /* Port S Reduced Drive Register */
volatile REFDVSTR _REFDV;      /* CRG Reference Divider Register */
volatile RTICTLSTR _RTICTL;    /* CRG RTI Control Register */
volatile SCI0BDHSTR _SCI0BDH;  /* SCI Baud Rate Register High */
volatile SCI0BDLSTR _SCI0BDL;  /* SCI Baud Rate Register Low */
volatile SCI0CR1STR _SCI0CR1;  /* SCI Control Register 1 */
volatile SCI0CR2STR _SCI0CR2;  /* SCI Control Register 2 */
volatile SCI0DRHSTR _SCI0DRH;  /* SCI Data Register High */
volatile SCI0DRLSTR _SCI0DRL;  /* SCI Data Register Low */
volatile SCI0SR1STR _SCI0SR1;  /* SCI Status Register 1 */
volatile SCI0SR2STR _SCI0SR2;  /* SCI Status Register 2 */
volatile SCI1BDHSTR _SCI1BDH;  /* SCI Baud Rate Register High */
volatile SCI1BDLSTR _SCI1BDL;  /* SCI Baud Rate Register Low */
volatile SCI1CR1STR _SCI1CR1;  /* SCI Control Register 1 */
volatile SCI1CR2STR _SCI1CR2;  /* SCI Control Register 2 */
volatile SCI1DRHSTR _SCI1DRH;  /* SCI Data Register High */
volatile SCI1DRLSTR _SCI1DRL;  /* SCI Data Register Low */
volatile SCI1SR1STR _SCI1SR1;  /* SCI Status Register 1 */
volatile SCI1SR2STR _SCI1SR2;  /* SCI Status Register 2 */
volatile SPI0BRSTR _SPI0BR;    /* SPI Baud Rate Register */
volatile SPI0CR1STR _SPI0CR1;  /* SPI Control Register */
volatile SPI0CR2STR _SPI0CR2;  /* SPI Control Register 2 */
volatile SPI0DRSTR _SPI0DR;    /* SPI Data Register */
volatile SPI0SRSTR _SPI0SR;    /* SPI Baud Rate Register */
volatile SPI1BRSTR _SPI1BR;    /* SPI Baud Rate Register */
volatile SPI1CR1STR _SPI1CR1;  /* SPI Control Register */
volatile SPI1CR2STR _SPI1CR2;  /* SPI Control Register 2 */
volatile SPI1DRSTR _SPI1DR;    /* SPI Data Register */
volatile SPI1SRSTR _SPI1SR;    /* SPI Baud Rate Register */
volatile SYNRSTR _SYNR;        /* CRG Synthesizer Register */
volatile TC0HhiSTR _TC0Hhi;    /* Timer Input Capture Holding Registers 0 High */
volatile TC0HiSTR _TC0Hi;      /* Timer Input Capture/Output Compare Register 0 High */
volatile TC0HloSTR _TC0Hlo;    /* Timer Input Capture Holding Registers 0 Low */
volatile TC0LoSTR _TC0Lo;      /* Timer Input Capture/Output Compare Register 0 Low */
volatile TC1HhiSTR _TC1Hhi;    /* Timer Input Capture Holding Registers 1 High */
volatile TC1HiSTR _TC1Hi;      /* Timer Input Capture/Output Compare Register 1 High */
volatile TC1HloSTR _TC1Hlo;    /* Timer Input Capture Holding Registers 1 Low */
volatile TC1LoSTR _TC1Lo;      /* Timer Input Capture/Output Compare Register 1 Low */
volatile TC2HhiSTR _TC2Hhi;    /* Timer Input Capture Holding Registers 2 High */
volatile TC2HiSTR _TC2Hi;      /* Timer Input Capture/Output Compare Register 2 High */
volatile TC2HloSTR _TC2Hlo;    /* Timer Input Capture Holding Registers 2 Low */
volatile TC2LoSTR _TC2Lo;      /* Timer Input Capture/Output Compare Register 2 Low */
volatile TC3HhiSTR _TC3Hhi;    /* Timer Input Capture Holding Registers 3 High */
volatile TC3HiSTR _TC3Hi;      /* Timer Input Capture/Output Compare Register 3 High */
volatile TC3HloSTR _TC3Hlo;    /* Timer Input Capture Holding Registers 3 Low */
volatile TC3LoSTR _TC3Lo;      /* Timer Input Capture/Output Compare Register 3 Low */
volatile TC4HiSTR _TC4Hi;      /* Timer Input Capture/Output Compare Register 4 High */
volatile TC4LoSTR _TC4Lo;      /* Timer Input Capture/Output Compare Register 4 Low */
volatile TC5HiSTR _TC5Hi;      /* Timer Input Capture/Output Compare Register 5 High */
volatile TC5LoSTR _TC5Lo;      /* Timer Input Capture/Output Compare Register 5 Low */
volatile TC6HiSTR _TC6Hi;      /* Timer Input Capture/Output Compare Register 6 High */
volatile TC6LoSTR _TC6Lo;      /* Timer Input Capture/Output Compare Register 6 Low */
volatile TC7HiSTR _TC7Hi;      /* Timer Input Capture/Output Compare Register 7 High */
volatile TC7LoSTR _TC7Lo;      /* Timer Input Capture/Output Compare Register 7 Low */
volatile TCNTHiSTR _TCNTHi;    /* Timer Count Register High */
volatile TCNTLoSTR _TCNTLo;    /* Timer Count Register Low */
volatile TCTL1STR _TCTL1;      /* Timer Control Registers 1 */
volatile TCTL2STR _TCTL2;      /* Timer Control Registers 1 */
volatile TCTL3STR _TCTL3;      /* Timer Control Register 3 */
volatile TCTL4STR _TCTL4;      /* Timer Control Register 4 */
volatile TFLG1STR _TFLG1;      /* Main Timer Interrupt Flag 1 */
volatile TFLG2STR _TFLG2;      /* Main Timer Interrupt Flag 2 */
volatile TIESTR _TIE;          /* Timer Interrupt Enable Register */
volatile TIMTSTSTR _TIMTST;    /* Timer Test Register */
volatile TIOSSTR _TIOS;        /* Timer Input Capture/Output Compare Select */
volatile TSCR1STR _TSCR1;      /* Timer System Control Register1 */
volatile TSCR2STR _TSCR2;      /* Timer System Control Register 2 */
volatile TTOVSTR _TTOV;        /* Timer Toggle On Overflow Register */
volatile WOMMSTR _WOMM;        /* Port M Wired-Or Mode Register */
volatile WOMSSTR _WOMS;        /* Port S Wired-Or Mode Register */
volatile ATD0CTL23STR _ATD0CTL23; /* ATD Control Register 23 */
volatile ATD0CTL45STR _ATD0CTL45; /* ATD Control Register 45 */
volatile ATD0DR0STR _ATD0DR0;  /* A/D Conversion Result Register 0 */
volatile ATD0DR1STR _ATD0DR1;  /* A/D Conversion Result Register 1 */
volatile ATD0DR2STR _ATD0DR2;  /* A/D Conversion Result Register 2 */
volatile ATD0DR3STR _ATD0DR3;  /* A/D Conversion Result Register 3 */
volatile ATD0DR4STR _ATD0DR4;  /* A/D Conversion Result Register 4 */
volatile ATD0DR5STR _ATD0DR5;  /* A/D Conversion Result Register 5 */
volatile ATD0DR6STR _ATD0DR6;  /* A/D Conversion Result Register 6 */
volatile ATD0DR7STR _ATD0DR7;  /* A/D Conversion Result Register 7 */
volatile ATD1CTL23STR _ATD1CTL23; /* ATD Control Register 23 */
volatile ATD1CTL45STR _ATD1CTL45; /* ATD Control Register 45 */
volatile ATD1DR0STR _ATD1DR0;  /* A/D Conversion Result Register 0 */
volatile ATD1DR1STR _ATD1DR1;  /* A/D Conversion Result Register 1 */
volatile ATD1DR2STR _ATD1DR2;  /* A/D Conversion Result Register 2 */
volatile ATD1DR3STR _ATD1DR3;  /* A/D Conversion Result Register 3 */
volatile ATD1DR4STR _ATD1DR4;  /* A/D Conversion Result Register 4 */
volatile ATD1DR5STR _ATD1DR5;  /* A/D Conversion Result Register 5 */
volatile ATD1DR6STR _ATD1DR6;  /* A/D Conversion Result Register 6 */
volatile ATD1DR7STR _ATD1DR7;  /* A/D Conversion Result Register 7 */
volatile DDRABSTR _DDRAB;      /* Port AB Data Direction Register */
volatile MCCNTSTR _MCCNT;      /* Modulus Down-Counter Count Register */
volatile PA10HSTR _PA10H;      /* 8-Bit Pulse Accumulators Holding */
volatile PA32HSTR _PA32H;      /* 8-Bit Pulse Accumulators Holding */
volatile PACN10STR _PACN10;    /* Pulse Accumulators Count Register */
volatile PACN32STR _PACN32;    /* Pulse Accumulators Count Register */
volatile PORTABSTR _PORTAB;    /* Port AB Register */
volatile PWMCNT01STR _PWMCNT01; /* PWM Channel Counter */
volatile PWMCNT23STR _PWMCNT23; /* PWM Channel Counter */
volatile PWMCNT45STR _PWMCNT45; /* PWM Channel Counter */
volatile PWMCNT67STR _PWMCNT67; /* PWM Channel Counter */
volatile PWMDTY01STR _PWMDTY01; /* PWM Channel Duty */
volatile PWMDTY23STR _PWMDTY23; /* PWM Channel Duty */
volatile PWMDTY45STR _PWMDTY45; /* PWM Channel Duty */
volatile PWMDTY67STR _PWMDTY67; /* PWM Channel Duty */
volatile PWMPER01STR _PWMPER01; /* PWM Channel Period */
volatile PWMPER23STR _PWMPER23; /* PWM Channel Period */
volatile PWMPER45STR _PWMPER45; /* PWM Channel Period */
volatile PWMPER67STR _PWMPER67; /* PWM Channel Period */
volatile SCI0BDSTR _SCI0BD;    /* SCI Baud Rate Register */
volatile SCI1BDSTR _SCI1BD;    /* SCI Baud Rate Register */
volatile TC0STR _TC0;          /* Timer Input Capture/Output Compare Register 0 */
volatile TC0HSTR _TC0H;        /* Timer Input Capture Holding Registers 0 */
volatile TC1STR _TC1;          /* Timer Input Capture/Output Compare Register 1 */
volatile TC1HSTR _TC1H;        /* Timer Input Capture Holding Registers 1 */
volatile TC2STR _TC2;          /* Timer Input Capture/Output Compare Register 2 */
volatile TC2HSTR _TC2H;        /* Timer Input Capture Holding Registers 2 */
volatile TC3STR _TC3;          /* Timer Input Capture/Output Compare Register 3 */
volatile TC3HSTR _TC3H;        /* Timer Input Capture Holding Registers 3 */
volatile TC4STR _TC4;          /* Timer Input Capture/Output Compare Register 4 */
volatile TC5STR _TC5;          /* Timer Input Capture/Output Compare Register 5 */
volatile TC6STR _TC6;          /* Timer Input Capture/Output Compare Register 6 */
volatile TC7STR _TC7;          /* Timer Input Capture/Output Compare Register 7 */
volatile TCNTSTR _TCNT;        /* Timer Count Register */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.05 for 
**     the Motorola HCS12 series of microcontrollers.
**
** ###################################################################
*/
