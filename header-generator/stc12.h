/*
 * Copyright (c) 2022 Vincent DEFERT. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright 
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file stc12.h
 * 
 * Register, bit and macro definitions for the STC12
 */

#ifndef _STC12_H
#define _STC12_H

#include <compiler.h>

// SFR P0: Port 0
SFR(P0, 0x80);
SBIT(P0_0, 0x80, 0);
SBIT(P0_1, 0x80, 1);
SBIT(P0_2, 0x80, 2);
SBIT(P0_3, 0x80, 3);
SBIT(P0_4, 0x80, 4);
SBIT(P0_5, 0x80, 5);
SBIT(P0_6, 0x80, 6);
SBIT(P0_7, 0x80, 7);

// SFR SP: Stack Pointer
SFR(SP, 0x81);

// SFR DPL: Data Pointer (DPTR) low
SFR(DPL, 0x82);

// SFR DPH: Data Pointer (DPTR) high
SFR(DPH, 0x83);

// SFR PCON: Power control
SFR(PCON, 0x87);
#define IDL 0x1
#define PD 0x2
#define GF0 0x4
#define GF1 0x8
#define POF 0x10
#define LVDF 0x20
#define SMOD0 0x40
#define SMOD 0x80

// SFR TCON: Timer control
SFR(TCON, 0x88);
SBIT(IT0, 0x88, 0);
SBIT(IE0, 0x88, 1);
SBIT(IT1, 0x88, 2);
SBIT(IE1, 0x88, 3);
SBIT(TR0, 0x88, 4);
SBIT(TF0, 0x88, 5);
SBIT(TR1, 0x88, 6);
SBIT(TF1, 0x88, 7);

// SFR TMOD: Timer mode
SFR(TMOD, 0x89);
#define T0_M0 0x1
#define T0_M1 0x2
#define T0_C_T 0x4
#define T0_GATE 0x8
#define T1_M0 0x10
#define T1_M1 0x20
#define T1_C_T 0x40
#define T1_GATE 0x80

// SFR TL0: Timer 0 low
SFR(TL0, 0x8A);

// SFR TL1: Timer 1 low
SFR(TL1, 0x8B);

// SFR TH0: Timer 0 high
SFR(TH0, 0x8C);

// SFR TH1: Timer 1 high
SFR(TH1, 0x8D);

// SFR AUXR: Auxiliary register
SFR(AUXR, 0x8E);
#define S1BRS 0x1
#define EXTRAM 0x2
#define BRTx12 0x4
#define S2SMOD 0x8
#define BRTR 0x10
#define UART_M0x6 0x20
#define T1x12 0x40
#define T0x12 0x80

// SFR WAIT_CLKO: CLK_Output power-down wake-up control
SFR(WAIT_CLKO, 0x8F);
#define T0CLKO 0x1
#define T1CLKO 0x2
#define BRTCLKO 0x4
#define LVD_WAKE 0x8
#define T0_PIN_IE 0x10
#define T1_PIN_IE 0x20
#define RXD_PIN_IE 0x40
#define PCAWAKEUP 0x80

// SFR P1: Port 1
SFR(P1, 0x90);
SBIT(P1_0, 0x90, 0);
SBIT(P1_1, 0x90, 1);
SBIT(P1_2, 0x90, 2);
SBIT(P1_3, 0x90, 3);
SBIT(P1_4, 0x90, 4);
SBIT(P1_5, 0x90, 5);
SBIT(P1_6, 0x90, 6);
SBIT(P1_7, 0x90, 7);

// SFR P1M1: Port 1 Configuration 1
SFR(P1M1, 0x91);

// SFR P1M0: Port 1 Configuration 0
SFR(P1M0, 0x92);

// SFR P0M1: Port 0 Configuration 1
SFR(P0M1, 0x93);

// SFR P0M0: Port 0 Configuration 0
SFR(P0M0, 0x94);

// SFR P2M1: Port 2 Configuration 1
SFR(P2M1, 0x95);

// SFR P2M0: Port 2 Configuration 0
SFR(P2M0, 0x96);

// SFR CLK_DIV: Clock divider
SFR(CLK_DIV, 0x97);
#define CLKS0 0x1
#define CLKS1 0x2
#define CLKS2 0x4

// SFR SCON: Serial control
SFR(SCON, 0x98);
SBIT(RI, 0x98, 0);
SBIT(TI, 0x98, 1);
SBIT(RB8, 0x98, 2);
SBIT(TB8, 0x98, 3);
SBIT(REN, 0x98, 4);
SBIT(SM2, 0x98, 5);
SBIT(SM1, 0x98, 6);
SBIT(SM0_FE, 0x98, 7);

// SFR SBUF: Serial buffer
SFR(SBUF, 0x99);

// SFR S2CON: S2 serial control
SFR(S2CON, 0x9A);
#define S2RI 0x1
#define S2TI 0x2
#define S2RB8 0x4
#define S2TB8 0x8
#define S2REN 0x10
#define S2SM2 0x20
#define S2SM1 0x40
#define S2SM0 0x80

// SFR S2BUF: S2 serial buffer
SFR(S2BUF, 0x9B);

// SFR BRT: Dedicated baud rate timer
SFR(BRT, 0x9C);

// SFR P1ASF: P1 analog special function
SFR(P1ASF, 0x9D);
#define P10ASF 0x1
#define P11ASF 0x2
#define P12ASF 0x4
#define P13ASF 0x8
#define P14ASF 0x10
#define P15ASF 0x20
#define P16ASF 0x40
#define P17ASF 0x80

// SFR P2: Port 2
SFR(P2, 0xA0);
SBIT(P2_0, 0xA0, 0);
SBIT(P2_1, 0xA0, 1);
SBIT(P2_2, 0xA0, 2);
SBIT(P2_3, 0xA0, 3);
SBIT(P2_4, 0xA0, 4);
SBIT(P2_5, 0xA0, 5);
SBIT(P2_6, 0xA0, 6);
SBIT(P2_7, 0xA0, 7);

// SFR BUS_SPEED: Bus speed control
SFR(BUS_SPEED, 0xA1);
#define RWS0 0x1
#define RWS1 0x2
#define RWS2 0x4
#define ALES0 0x10
#define ALES1 0x20

// SFR AUXR1: Auxiliary register 1
SFR(AUXR1, 0xA2);
#define DPSEL 0x1
#define ADRJ 0x4
#define GF2 0x8
#define S2_P4 0x10
#define SPI_P4 0x20
#define PCA_P4 0x40

// SFR DPS: Alias of AUXR1 used by SDCC
SFR(DPS, 0xA2);

// SFR IE: Interrupt enable
SFR(IE, 0xA8);
SBIT(EX0, 0xA8, 0);
SBIT(ET0, 0xA8, 1);
SBIT(EX1, 0xA8, 2);
SBIT(ET1, 0xA8, 3);
SBIT(ES, 0xA8, 4);
SBIT(EADC, 0xA8, 5);
SBIT(ELVD, 0xA8, 6);
SBIT(EA, 0xA8, 7);

// SFR SADDR: Slave address
SFR(SADDR, 0xA9);

// SFR IE2: Interrupt enable 2
SFR(IE2, 0xAF);
#define ES2 0x1
#define ESPI 0x2

// SFR P3: Port 3
SFR(P3, 0xB0);
SBIT(P3_0, 0xB0, 0);
SBIT(P3_1, 0xB0, 1);
SBIT(P3_2, 0xB0, 2);
SBIT(P3_3, 0xB0, 3);
SBIT(P3_4, 0xB0, 4);
SBIT(P3_5, 0xB0, 5);
SBIT(P3_6, 0xB0, 6);
SBIT(P3_7, 0xB0, 7);

// SFR P3M1: Port 3 configuration 1
SFR(P3M1, 0xB1);

// SFR P3M0: Port 3 configuration 0
SFR(P3M0, 0xB2);

// SFR P4M1: Port 4 configuration 1
SFR(P4M1, 0xB3);

// SFR P4M0: Port 4 configuration 0
SFR(P4M0, 0xB4);

// SFR IP2: Interrupt priority register 2 low
SFR(IP2, 0xB5);
#define PS2L 0x1
#define PSPIL 0x2

// SFR IP2H: Interrupt priority register 2 high
SFR(IP2H, 0xB6);
#define PS2H 0x1
#define PSPIH 0x2

// SFR IPH: Interrupt priority register high
SFR(IPH, 0xB7);
#define PX0H 0x1
#define PT0H 0x2
#define PX1H 0x4
#define PT1H 0x8
#define PSH 0x10
#define PADCH 0x20
#define PLVDH 0x40
#define PPCAH 0x80

// SFR IP: Interrupt priority register low
SFR(IP, 0xB8);
SBIT(PX0L, 0xB8, 0);
SBIT(PT0L, 0xB8, 1);
SBIT(PX1L, 0xB8, 2);
SBIT(PT1L, 0xB8, 3);
SBIT(PSL, 0xB8, 4);
SBIT(PADCL, 0xB8, 5);
SBIT(PLVDL, 0xB8, 6);
SBIT(PPCAL, 0xB8, 7);

// SFR SADEN: Slave address mask
SFR(SADEN, 0xB9);

// SFR P4SW: Port 4 switch
SFR(P4SW, 0xBB);
#define NA_P4_4 0x10
#define ALE_P4_5 0x20
#define LVD_P4_6 0x40

// SFR ADC_CONTR: ADC control
SFR(ADC_CONTR, 0xBC);
#define CHS0 0x1
#define CHS1 0x2
#define CHS2 0x4
#define ADC_START 0x8
#define ADC_FLAG 0x10
#define SPEED0 0x20
#define SPEED1 0x40
#define ADC_POWER 0x80

// SFR ADC_RES: ADC result
SFR(ADC_RES, 0xBD);

// SFR ADC_RESL: ADC result low
SFR(ADC_RESL, 0xBE);

// SFR P4: Port 4
SFR(P4, 0xC0);
SBIT(P4_0, 0xC0, 0);
SBIT(P4_1, 0xC0, 1);
SBIT(P4_2, 0xC0, 2);
SBIT(P4_3, 0xC0, 3);
SBIT(P4_4, 0xC0, 4);
SBIT(P4_5, 0xC0, 5);
SBIT(P4_6, 0xC0, 6);
SBIT(P4_7, 0xC0, 7);

// SFR WDT_CONTR: Watchdog timer control
SFR(WDT_CONTR, 0xC1);
#define PS0 0x1
#define PS1 0x2
#define PS2 0x4
#define IDLE_WDT 0x8
#define CLR_WDT 0x10
#define EN_WDT 0x20
#define WDT_FLAG 0x80

// SFR IAP_DATA: ISP/IAP flash data register
SFR(IAP_DATA, 0xC2);

// SFR IAP_ADDRH: ISP/IAP flash address high
SFR(IAP_ADDRH, 0xC3);

// SFR IAP_ADDRL: ISP/IAP flash address low
SFR(IAP_ADDRL, 0xC4);

// SFR IAP_CMD: ISP/IAP flash command register
SFR(IAP_CMD, 0xC5);
#define MS0 0x1
#define MS1 0x2

// SFR IAP_TRIG: ISP/IAP flash trigger register
SFR(IAP_TRIG, 0xC6);

// SFR IAP_CONTR: ISP/IAP flash control register
SFR(IAP_CONTR, 0xC7);
#define WT0 0x1
#define WT1 0x2
#define WT2 0x4
#define CMD_FAIL 0x10
#define SWRST 0x20
#define SWBS 0x40
#define IAPEN 0x80

// SFR P5: Port 5
SFR(P5, 0xC8);
SBIT(P5_0, 0xC8, 0);
SBIT(P5_1, 0xC8, 1);
SBIT(P5_2, 0xC8, 2);
SBIT(P5_3, 0xC8, 3);
SBIT(P5_4, 0xC8, 4);
SBIT(P5_5, 0xC8, 5);
SBIT(P5_6, 0xC8, 6);
SBIT(P5_7, 0xC8, 7);

// SFR P5M1: Port 5 configuration 1
SFR(P5M1, 0xC9);

// SFR P5M0: Port 5 configuration 0
SFR(P5M0, 0xCA);

// SFR SPSTAT: SPI status register
SFR(SPSTAT, 0xCD);
#define WCOL 0x40
#define SPIF 0x80

// SFR SPCTL: SPI control register
SFR(SPCTL, 0xCE);
#define SPR0 0x1
#define SPR1 0x2
#define CPHA 0x4
#define CPOL 0x8
#define MSTR 0x10
#define DORD 0x20
#define SPEN 0x40
#define SSIG 0x80

// SFR SPDAT: SPI data register
SFR(SPDAT, 0xCF);

// SFR PSW: Program status word
SFR(PSW, 0xD0);
SBIT(P, 0xD0, 0);
SBIT(F1, 0xD0, 1);
SBIT(OV, 0xD0, 2);
SBIT(RS0, 0xD0, 3);
SBIT(RS1, 0xD0, 4);
SBIT(F0, 0xD0, 5);
SBIT(AC, 0xD0, 6);
SBIT(CY, 0xD0, 7);

// SFR CCON: PCA control register
SFR(CCON, 0xD8);
SBIT(CCF0, 0xD8, 0);
SBIT(CCF1, 0xD8, 1);
SBIT(CR, 0xD8, 6);
SBIT(CF, 0xD8, 7);

// SFR CMOD: PCA mode register
SFR(CMOD, 0xD9);
#define ECF 0x1
#define CPS0 0x2
#define CPS1 0x4
#define CPS2 0x8
#define CIDL 0x80

// SFR CCAPM0: PCA module 0 mode register
SFR(CCAPM0, 0xDA);
#define EECF0 0x1
#define PWM0 0x2
#define TOG0 0x4
#define MAT0 0x8
#define CAPN0 0x10
#define CAPP0 0x20
#define ECOM0 0x40

// SFR CCAPM1: PCA module 1 mode register
SFR(CCAPM1, 0xDB);
#define EECF1 0x1
#define PWM1 0x2
#define TOG1 0x4
#define MAT1 0x8
#define CAPN1 0x10
#define CAPP1 0x20
#define ECOM1 0x40

// SFR ACC: Accumulator
SFR(ACC, 0xE0);

// SFR CL: PCA base timer low
SFR(CL, 0xE9);

// SFR CCAP0L: PCA module 0 capture register low
SFR(CCAP0L, 0xEA);

// SFR CCAP1L: PCA module 1 capture register low
SFR(CCAP1L, 0xEB);

// SFR B: B register
SFR(B, 0xF0);

// SFR PCA_PWM0: PCA PWM mode auxiliary register 0
SFR(PCA_PWM0, 0xF2);
#define EPC0L 0x1
#define EPC0H 0x2

// SFR PCA_PWM1: PCA PWM mode auxiliary register 1
SFR(PCA_PWM1, 0xF3);
#define EPC1L 0x1
#define EPC1H 0x2

// SFR CH: PCA base timer high
SFR(CH, 0xF9);

// SFR CCAP0H: PCA module 0 capture register high
SFR(CCAP0H, 0xFA);

// SFR CCAP1H: PCA module 1 capture register high
SFR(CCAP1H, 0xFB);
// External interrupt 0
#define EXTINT0_INTERRUPT 0
#define EXTINT0_VECTOR_ADDR 0x03
// Timer 0 interrupt
#define TIMER0_INTERRUPT 1
#define TIMER0_VECTOR_ADDR 0x0B
// External interrupt 1
#define EXTINT1_INTERRUPT 2
#define EXTINT1_VECTOR_ADDR 0x13
// Timer 1 interrupt
#define TIMER1_INTERRUPT 3
#define TIMER1_VECTOR_ADDR 0x1B
// UART 1 interrupt
#define UART1_INTERRUPT 4
#define UART1_VECTOR_ADDR 0x23
// ADC interrupt
#define ADC_INTERRUPT 5
#define ADC_VECTOR_ADDR 0x2B
// Low-voltage detector interrupt
#define LVD_INTERRUPT 6
#define LVD_VECTOR_ADDR 0x33
// PCA interrupt
#define PCA_INTERRUPT 7
#define PCA_VECTOR_ADDR 0x3B
// UART 2 interrupt
#define UART2_INTERRUPT 8
#define UART2_VECTOR_ADDR 0x43
// SPI interrupt
#define SPI_INTERRUPT 9
#define SPI_VECTOR_ADDR 0x4B

// Default value for macro F_CPU
#ifndef F_CPU
#error "The F_CPU macro *MUST* be defined (e.g. -DF_CPU=11095200UL)"
#endif

// Default value for macro T_CPU
#ifndef T_CPU
#define T_CPU 1
#endif

#endif // _STC12_H
