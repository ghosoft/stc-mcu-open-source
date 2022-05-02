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
 * @file stc8af.h
 * 
 * Register, bit and macro definitions for the STC8AF
 */

#ifndef _STC8AF_H
#define _STC8AF_H

#include <compiler.h>

/**
 * This file can be used with the following parts with some limitations:
 * 
 * +----------------+-----+-----+-----+------+--------+------------+
 * | Part           | ADC | PCA | PWM | UART | Timers | GPIO Ports |
 * +----------------+-----+-----+-----+------+--------+------------+
 * | STC8A8K64S4A12 | yes | yes | yes | 4    | 5      | 8          |
 * | STC8A8K64S2A12 | yes | yes | yes | 2    | 5      | 8          |
 * | STC8F2K64S4    | no  | no  | no  | 4    | 5      | 8          |
 * | STC8F2K64S2    | no  | no  | no  | 2    | 5      | 8          |
 * | STC8F1K08S2    | no  | no  | no  | 2    | 3      | 3 (1/3/5)  |
 * | STC8F1K08      | no  | no  | no  | 1    | 3      | 2 (3/5)    |
 * +----------------+-----+-----+-----+------+--------+------------+
*/

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

// SFR S4CON: 
SFR(S4CON, 0x84);
#define S4RI 0x1
#define S4TI 0x2
#define S4RB8 0x4
#define S4TB8 0x8
#define S4REN 0x10
#define S4SM2 0x20
#define S4ST4 0x40
#define S4SM0 0x80

// SFR S4BUF: 
SFR(S4BUF, 0x85);

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
#define S1ST2 0x1
#define EXTRAM 0x2
#define T2x12 0x4
#define T2_C_T 0x8
#define T2R 0x10
#define UART_M0x6 0x20
#define T1x12 0x40
#define T0x12 0x80

// SFR INTCLKO: CLK_Output and external interrupt enable register
SFR(INTCLKO, 0x8F);
#define T0CLKO 0x1
#define T1CLKO 0x2
#define T2CLKO 0x4
#define EX2 0x10
#define EX3 0x20
#define EX4 0x40

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

// SFR AUXR2: Auxiliary register 2
SFR(AUXR2, 0x97);
#define TXLNRX 0x10

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
#define S2SM0 0x80

// SFR S2BUF: S2 serial buffer
SFR(S2BUF, 0x9B);

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
#define BUS_SPEED0 0x1
#define BUS_SPEED1 0x2
#define RW_S0 0x40
#define RW_S1 0x80

// SFR P_SW1: Auxiliary register 1
SFR(P_SW1, 0xA2);
#define SPI_S0 0x4
#define SPI_S1 0x8
#define CCP_S0 0x10
#define CCP_S1 0x20
#define S1_S0 0x40
#define S1_S1 0x80

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

// SFR WKTCL: Power-down wake-up timer control register low
SFR(WKTCL, 0xAA);

// SFR WKTCH: Power-down wake-up timer control register high
SFR(WKTCH, 0xAB);
#define WKTEN 0x80

// SFR S3CON: S3 serial control
SFR(S3CON, 0xAC);
#define S3RI 0x1
#define S3TI 0x2
#define S3RB8 0x4
#define S3TB8 0x8
#define S3REN 0x10
#define S3SM2 0x20
#define S3ST3 0x40
#define S3SM0 0x80

// SFR S3BUF: S3 serial buffer
SFR(S3BUF, 0xAD);

// SFR TA: DPTR timing control register
SFR(TA, 0xAE);

// SFR IE2: Interrupt enable 2
SFR(IE2, 0xAF);
#define ES2 0x1
#define ESPI 0x2
#define ET2 0x4
#define ES3 0x8
#define ES4 0x10
#define ET3 0x20
#define ET4 0x40

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
#define PS2 0x1
#define PSPI 0x2
#define PPWM 0x4
#define PPWMFD 0x8
#define PX4 0x10
#define PCMP 0x20
#define PI2C 0x40

// SFR IP2H: Interrupt priority register 2 high
SFR(IP2H, 0xB6);
#define PS2H 0x1
#define PSPIH 0x2
#define PPWMH 0x4
#define PPWMFDH 0x8
#define PX4H 0x10
#define PCMPH 0x20
#define PI2CH 0x40

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
SBIT(PX0, 0xB8, 0);
SBIT(PT0, 0xB8, 1);
SBIT(PX1, 0xB8, 2);
SBIT(PT1, 0xB8, 3);
SBIT(PS, 0xB8, 4);
SBIT(PADC, 0xB8, 5);
SBIT(PLVD, 0xB8, 6);
SBIT(PPCA, 0xB8, 7);

// SFR SADEN: Slave address mask
SFR(SADEN, 0xB9);

// SFR P_SW2: Peripheral function switch register 2
SFR(P_SW2, 0xBA);
#define S2_S 0x1
#define S3_S 0x2
#define S4_S 0x4
#define CMPO_S 0x8
#define I2C_S0 0x10
#define I2C_S1 0x20
#define EAXSFR 0x80

// SFR VOCTRL: Voltage control register
SFR(VOCTRL, 0xBB);
#define SCC 0x80

// SFR ADC_CONTR: ADC control
SFR(ADC_CONTR, 0xBC);
#define ADC_CHS0 0x1
#define ADC_CHS1 0x2
#define ADC_CHS2 0x4
#define ADC_CHS3 0x8
#define ADC_FLAG 0x20
#define ADC_START 0x40
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

// SFR WDT_CONTR: Watchdog timer control
SFR(WDT_CONTR, 0xC1);
#define WDT_PS0 0x1
#define WDT_PS1 0x2
#define WDT_PS2 0x4
#define IDL_WDT 0x8
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
#define CMD0 0x1
#define CMD1 0x2

// SFR IAP_TRIG: ISP/IAP flash trigger register
SFR(IAP_TRIG, 0xC6);

// SFR IAP_CONTR: ISP/IAP flash control register
SFR(IAP_CONTR, 0xC7);
#define IAP_WT0 0x1
#define IAP_WT1 0x2
#define IAP_WT2 0x4
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

// SFR P5M1: Port 5 configuration 1
SFR(P5M1, 0xC9);

// SFR P5M0: Port 5 configuration 0
SFR(P5M0, 0xCA);

// SFR P6M1: Port 6 configuration 1
SFR(P6M1, 0xCB);

// SFR P6M0: Port 6 configuration 0
SFR(P6M0, 0xCC);

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

// SFR T4T3M: T4 and T3 mode register
SFR(T4T3M, 0xD1);
#define T3CLKO 0x1
#define T3x12 0x2
#define T3_C_T 0x4
#define T3R 0x8
#define T4CLKO 0x10
#define T4x12 0x20
#define T4_C_T 0x40
#define T4R 0x80

// SFR T4H: Timer 4 high
SFR(T4H, 0xD2);

// SFR T4L: Timer 4 low
SFR(T4L, 0xD3);

// SFR T3H: Timer 3 high
SFR(T3H, 0xD4);

// SFR T3L: Timer 3 low
SFR(T3L, 0xD5);

// SFR T2H: Timer 2 high
SFR(T2H, 0xD6);

// SFR T2L: Timer 2 low
SFR(T2L, 0xD7);

// SFR CCON: PCA control register
SFR(CCON, 0xD8);
SBIT(CCF0, 0xD8, 0);
SBIT(CCF1, 0xD8, 1);
SBIT(CCF2, 0xD8, 2);
SBIT(CCF3, 0xD8, 3);
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

// SFR CCAPM2: PCA module 2 mode register
SFR(CCAPM2, 0xDC);
#define EECF2 0x1
#define PWM2 0x2
#define TOG2 0x4
#define MAT2 0x8
#define CAPN2 0x10
#define CAPP2 0x20
#define ECOM2 0x40

// SFR CCAPM3: PCA module 3 mode register
SFR(CCAPM3, 0xDD);
#define EECF3 0x1
#define PWM3 0x2
#define TOG3 0x4
#define MAT3 0x8
#define CAPN3 0x10
#define CAPP3 0x20
#define ECOM3 0x40

// SFR ADCCFG: ADC configuration register
SFR(ADCCFG, 0xDE);
#define ADC_SPEED0 0x1
#define ADC_SPEED1 0x2
#define ADC_SPEED2 0x4
#define ADC_SPEED3 0x8
#define RESFMT 0x20

// SFR ACC: Accumulator
SFR(ACC, 0xE0);

// SFR P7M1: Port 7 configuration 1
SFR(P7M1, 0xE1);

// SFR P7M0: Port 7 configuration 0
SFR(P7M0, 0xE2);

// SFR DPS: Data Pointer selector
SFR(DPS, 0xE3);
#define DPSEL 0x1
#define AU0 0x8
#define AU1 0x10
#define TSL 0x20
#define ID0 0x40
#define ID1 0x80

// SFR DPL1: Second data pointer low
SFR(DPL1, 0xE4);

// SFR DPH1: Second data pointer high
SFR(DPH1, 0xE5);

// SFR CMPCR1: Comparator control register 1
SFR(CMPCR1, 0xE6);
#define CMPRES 0x1
#define CMPOE 0x2
#define NIS 0x4
#define PIS 0x8
#define NIE 0x10
#define PIE 0x20
#define CMPIF 0x40
#define CMPEN 0x80

// SFR CMPCR2: Comparator control register 2
SFR(CMPCR2, 0xE7);
#define LCDTY0 0x1
#define LCDTY1 0x2
#define LCDTY2 0x4
#define LCDTY3 0x8
#define LCDTY4 0x10
#define LCDTY5 0x20
#define DISFLT 0x40
#define INVCMPO 0x80

// SFR P6: Port 6
SFR(P6, 0xE8);

// SFR CL: PCA base timer low
SFR(CL, 0xE9);

// SFR CCAP0L: PCA module 0 capture register low
SFR(CCAP0L, 0xEA);

// SFR CCAP1L: PCA module 1 capture register low
SFR(CCAP1L, 0xEB);

// SFR CCAP2L: PCA module 2 capture register low
SFR(CCAP2L, 0xEC);

// SFR CCAP3L: PCA module 3 capture register low
SFR(CCAP3L, 0xED);

// SFR AUXINTIF: Extended external interrupt flag register
SFR(AUXINTIF, 0xEF);
#define T2IF 0x1
#define T3IF 0x2
#define T4IF 0x4
#define INT2IF 0x10
#define INT3IF 0x20
#define INT4IF 0x40

// SFR B: B register
SFR(B, 0xF0);

// SFR PWMCFG: PWM configuration register
SFR(PWMCFG, 0xF1);
#define ETADC 0x40
#define CBIF 0x80

// SFR PCA_PWM0: PCA PWM mode auxiliary register 0
SFR(PCA_PWM0, 0xF2);
#define EPC0L 0x1
#define EPC0H 0x2
#define XCCAP0L0 0x4
#define XCCAP0L1 0x8
#define XCCAP0H0 0x10
#define XCCAP0H1 0x20
#define EBS00 0x40
#define EBS01 0x80

// SFR PCA_PWM1: PCA PWM mode auxiliary register 1
SFR(PCA_PWM1, 0xF3);
#define EPC1L 0x1
#define EPC1H 0x2
#define XCCAP1L0 0x4
#define XCCAP1L1 0x8
#define XCCAP1H0 0x10
#define XCCAP1H1 0x20
#define EBS10 0x40
#define EBS11 0x80

// SFR PCA_PWM2: PCA PWM mode auxiliary register 2
SFR(PCA_PWM2, 0xF4);
#define EPC2L 0x1
#define EPC2H 0x2
#define XCCAP2L0 0x4
#define XCCAP2L1 0x8
#define XCCAP2H0 0x10
#define XCCAP2H1 0x20
#define EBS20 0x40
#define EBS21 0x80

// SFR PCA_PWM3: PCA PWM mode auxiliary register 3
SFR(PCA_PWM3, 0xF5);
#define EPC3L 0x1
#define EPC3H 0x2
#define XCCAP3L0 0x4
#define XCCAP3L1 0x8
#define XCCAP3H0 0x10
#define XCCAP3H1 0x20
#define EBS30 0x40
#define EBS31 0x80

// SFR PWMIF: PWM interrupt flag
SFR(PWMIF, 0xF6);
#define C0IF 0x1
#define C1IF 0x2
#define C2IF 0x4
#define C3IF 0x8
#define C4IF 0x10
#define C5IF 0x20
#define C6IF 0x40
#define C7IF 0x80

// SFR PWMFDCR: PWM exception detection control register
SFR(PWMFDCR, 0xF7);
#define FDIF 0x1
#define FDIO 0x2
#define FDCMP 0x4
#define EFDI 0x8
#define FLTFLIO 0x10
#define ENFD 0x20
#define INVIO 0x40
#define INVCMP 0x80

// SFR P7: Port 7
SFR(P7, 0xF8);

// SFR CH: PCA base timer high
SFR(CH, 0xF9);

// SFR CCAP0H: PCA module 0 capture register high
SFR(CCAP0H, 0xFA);

// SFR CCAP1H: PCA module 1 capture register high
SFR(CCAP1H, 0xFB);

// SFR CCAP2H: PCA module 2 capture register high
SFR(CCAP2H, 0xFC);

// SFR CCAP3H: PCA module 3 capture register high
SFR(CCAP3H, 0xFD);

// SFR PWMCR: PWM control register
SFR(PWMCR, 0xFE);
#define ECBI 0x40
#define ENPWM 0x80

// SFR RSTCFG: Reset configuration register
SFR(RSTCFG, 0xFF);
#define LVDS0 0x1
#define LVDS1 0x2
#define P54RST 0x10
#define ENLVR 0x40

// SFR CKSEL: Clock selection register
SFRX(CKSEL, 0xFE00);
#define MCKSEL0 0x1
#define MCKSEL1 0x2
#define MCLKO_S 0x8
#define MCLKODIV0 0x10
#define MCLKODIV1 0x20
#define MCLKODIV2 0x40
#define MCLKODIV3 0x80

// SFR CLKDIV: Clock frequency division register
SFRX(CLKDIV, 0xFE01);

// SFR IRC24MCR: Internal 24MHz RC oscillator control register
SFRX(IRC24MCR, 0xFE02);
#define IRC24MST 0x1
#define ENIRC24M 0x80

// SFR XOSCCR: External oscillator control register
SFRX(XOSCCR, 0xFE03);
#define XOSCST 0x1
#define XITYPE 0x40
#define ENXOSC 0x80

// SFR IRC32KCR: Internal 32kHz oscillator control register
SFRX(IRC32KCR, 0xFE04);
#define IRC32KST 0x1
#define ENIRC32K 0x80

// SFR P0PU: Port 0 pull-up resistor control register
SFRX(P0PU, 0xFE10);

// SFR P1PU: Port 1 pull-up resistor control register
SFRX(P1PU, 0xFE11);

// SFR P2PU: Port 2 pull-up resistor control register
SFRX(P2PU, 0xFE12);

// SFR P3PU: Port 3 pull-up resistor control register
SFRX(P3PU, 0xFE13);

// SFR P4PU: Port 4 pull-up resistor control register
SFRX(P4PU, 0xFE14);

// SFR P5PU: Port 5 pull-up resistor control register
SFRX(P5PU, 0xFE15);

// SFR P6PU: Port 6 pull-up resistor control register
SFRX(P6PU, 0xFE16);

// SFR P7PU: Port 7 pull-up resistor control register
SFRX(P7PU, 0xFE17);

// SFR P0NCS: Port 0 Schmidt trigger control register
SFRX(P0NCS, 0xFE18);

// SFR P1NCS: Port 1 Schmidt trigger control register
SFRX(P1NCS, 0xFE19);

// SFR P2NCS: Port 2 Schmidt trigger control register
SFRX(P2NCS, 0xFE1A);

// SFR P3NCS: Port 3 Schmidt trigger control register
SFRX(P3NCS, 0xFE1B);

// SFR P4NCS: Port 4 Schmidt trigger control register
SFRX(P4NCS, 0xFE1C);

// SFR P5NCS: Port 5 Schmidt trigger control register
SFRX(P5NCS, 0xFE1D);

// SFR P6NCS: Port 6 Schmidt trigger control register
SFRX(P6NCS, 0xFE1E);

// SFR P7NCS: Port 7 Schmidt trigger control register
SFRX(P7NCS, 0xFE1F);

// SFR I2CCFG: I2C configuration register
SFRX(I2CCFG, 0xFE80);
#define MSSPEED0 0x1
#define MSSPEED1 0x2
#define MSSPEED2 0x4
#define MSSPEED3 0x8
#define MSSPEED4 0x10
#define MSSPEED5 0x20
#define MSSL 0x40
#define ENI2C 0x80

// SFR I2CMSCR: I2C host control register
SFRX(I2CMSCR, 0xFE81);
#define MSCMD0 0x1
#define MSCMD1 0x2
#define MSCMD2 0x4
#define MSCMD3 0x8
#define EMSI 0x80

// SFR I2CMSST: I2C host state register
SFRX(I2CMSST, 0xFE82);
#define MSACK0 0x1
#define MSACK1 0x2
#define MSIF 0x40
#define MSBUSY 0x80

// SFR I2CSLCR: I2C slave control register
SFRX(I2CSLCR, 0xFE83);
#define SLRST 0x1
#define ESTOI 0x8
#define ETXI 0x10
#define ERXI 0x20
#define ESTAI 0x40

// SFR I2CSLST: I2C slave state register
SFRX(I2CSLST, 0xFE84);
#define SLACK0 0x1
#define SLACK1 0x2
#define TXING 0x4
#define STOIF 0x8
#define TXIF 0x10
#define RXIF 0x20
#define STAIF 0x40
#define SLBUSY 0x80

// SFR I2CSLADR: I2C slave address register
SFRX(I2CSLADR, 0xFE85);
#define MA 0x1
#define SLADR0 0x2
#define SLADR1 0x4
#define SLADR2 0x8
#define SLADR3 0x10
#define SLADR4 0x20
#define SLADR5 0x40
#define SLADR6 0x80

// SFR I2CTXD: I2C data transmission register
SFRX(I2CTXD, 0xFE86);

// SFR I2CRXD: I2C data receiving register
SFRX(I2CRXD, 0xFE87);

// SFR I2CMSAUX: I2C host auxiliary control register
SFRX(I2CMSAUX, 0xFE88);
#define WDTA 0x1

// SFR PWM0T1H: PWM0 Timer 1 high
SFRX(PWM0T1H, 0xFF00);

// SFR PWM0T1L: PWM0 Timer 1 low
SFRX(PWM0T1L, 0xFF01);

// SFR PWM0T2H: PWM0 Timer 2 high
SFRX(PWM0T2H, 0xFF02);

// SFR PWM0T2L: PWM0 Timer 2 low
SFRX(PWM0T2L, 0xFF03);

// SFR PWM0CR: PWM0 control register
SFRX(PWM0CR, 0xFF04);
#define EC0T1SI 0x1
#define EC0T2SI 0x2
#define EC0I 0x4
#define C0_S0 0x8
#define C0_S1 0x10
#define C0INI 0x40
#define ENC0O 0x80

// SFR PWM0HLD: PWM0 level hold control register
SFRX(PWM0HLD, 0xFF05);
#define HC0L 0x1
#define HC0H 0x2

// SFR PWM1T1H: PWM1 Timer 1 high
SFRX(PWM1T1H, 0xFF10);

// SFR PWM1T1L: PWM1 Timer 1 low
SFRX(PWM1T1L, 0xFF11);

// SFR PWM1T2H: PWM1 Timer 2 high
SFRX(PWM1T2H, 0xFF12);

// SFR PWM1T2L: PWM1 Timer 2 low
SFRX(PWM1T2L, 0xFF13);

// SFR PWM1CR: PWM1 control register
SFRX(PWM1CR, 0xFF14);
#define EC1T1SI 0x1
#define EC1T2SI 0x2
#define EC1I 0x4
#define C1_S0 0x8
#define C1_S1 0x10
#define C1INI 0x40
#define ENC1O 0x80

// SFR PWM1HLD: PWM1 level hold control register
SFRX(PWM1HLD, 0xFF15);
#define HC1L 0x1
#define HC1H 0x2

// SFR PWM2T1H: PWM2 Timer 1 high
SFRX(PWM2T1H, 0xFF20);

// SFR PWM2T1L: PWM2 Timer 1 low
SFRX(PWM2T1L, 0xFF21);

// SFR PWM2T2H: PWM2 Timer 2 high
SFRX(PWM2T2H, 0xFF22);

// SFR PWM2T2L: PWM2 Timer 2 low
SFRX(PWM2T2L, 0xFF23);

// SFR PWM2CR: PWM2 control register
SFRX(PWM2CR, 0xFF24);
#define EC2T1SI 0x1
#define EC2T2SI 0x2
#define EC2I 0x4
#define C2_S0 0x8
#define C2_S1 0x10
#define C2INI 0x40
#define ENC2O 0x80

// SFR PWM2HLD: PWM2 level hold control register
SFRX(PWM2HLD, 0xFF25);
#define HC2L 0x1
#define HC2H 0x2

// SFR PWM3T1H: PWM3 Timer 1 high
SFRX(PWM3T1H, 0xFF30);

// SFR PWM3T1L: PWM3 Timer 1 low
SFRX(PWM3T1L, 0xFF31);

// SFR PWM3T2H: PWM3 Timer 2 high
SFRX(PWM3T2H, 0xFF32);

// SFR PWM3T2L: PWM3 Timer 2 low
SFRX(PWM3T2L, 0xFF33);

// SFR PWM3CR: PWM3 control register
SFRX(PWM3CR, 0xFF34);
#define EC3T1SI 0x1
#define EC3T2SI 0x2
#define EC3I 0x4
#define C3_S0 0x8
#define C3_S1 0x10
#define C3INI 0x40
#define ENC3O 0x80

// SFR PWM3HLD: PWM3 level hold control register
SFRX(PWM3HLD, 0xFF35);
#define HC3L 0x1
#define HC3H 0x2

// SFR PWM4T1H: PWM4 Timer 1 high
SFRX(PWM4T1H, 0xFF40);

// SFR PWM4T1L: PWM4 Timer 1 low
SFRX(PWM4T1L, 0xFF41);

// SFR PWM4T2H: PWM4 Timer 2 high
SFRX(PWM4T2H, 0xFF42);

// SFR PWM4T2L: PWM4 Timer 2 low
SFRX(PWM4T2L, 0xFF43);

// SFR PWM4CR: PWM4 control register
SFRX(PWM4CR, 0xFF44);
#define EC4T1SI 0x1
#define EC4T2SI 0x2
#define EC4I 0x4
#define C4_S0 0x8
#define C4_S1 0x10
#define C4INI 0x40
#define ENC4O 0x80

// SFR PWM4HLD: PWM4 level hold control register
SFRX(PWM4HLD, 0xFF45);
#define HC4L 0x1
#define HC4H 0x2

// SFR PWM5T1H: PWM5 Timer 1 high
SFRX(PWM5T1H, 0xFF50);

// SFR PWM5T1L: PWM5 Timer 1 low
SFRX(PWM5T1L, 0xFF51);

// SFR PWM5T2H: PWM5 Timer 2 high
SFRX(PWM5T2H, 0xFF52);

// SFR PWM5T2L: PWM5 Timer 2 low
SFRX(PWM5T2L, 0xFF53);

// SFR PWM5CR: PWM5 control register
SFRX(PWM5CR, 0xFF54);
#define EC5T1SI 0x1
#define EC5T2SI 0x2
#define EC5I 0x4
#define C5_S0 0x8
#define C5_S1 0x10
#define C5INI 0x40
#define ENC5O 0x80

// SFR PWM5HLD: PWM5 level hold control register
SFRX(PWM5HLD, 0xFF55);
#define HC5L 0x1
#define HC5H 0x2

// SFR PWM6T1H: PWM6 Timer 1 high
SFRX(PWM6T1H, 0xFF60);

// SFR PWM6T1L: PWM6 Timer 1 low
SFRX(PWM6T1L, 0xFF61);

// SFR PWM6T2H: PWM6 Timer 2 high
SFRX(PWM6T2H, 0xFF62);

// SFR PWM6T2L: PWM6 Timer 2 low
SFRX(PWM6T2L, 0xFF63);

// SFR PWM6CR: PWM6 control register
SFRX(PWM6CR, 0xFF64);
#define EC6T1SI 0x1
#define EC6T2SI 0x2
#define EC6I 0x4
#define C6_S0 0x8
#define C6_S1 0x10
#define C6INI 0x40
#define ENC6O 0x80

// SFR PWM6HLD: PWM6 level hold control register
SFRX(PWM6HLD, 0xFF65);
#define HC6L 0x1
#define HC6H 0x2

// SFR PWM7T1H: PWM7 Timer 1 high
SFRX(PWM7T1H, 0xFF70);

// SFR PWM7T1L: PWM7 Timer 1 low
SFRX(PWM7T1L, 0xFF71);

// SFR PWM7T2H: PWM7 Timer 2 high
SFRX(PWM7T2H, 0xFF72);

// SFR PWM7T2L: PWM7 Timer 2 low
SFRX(PWM7T2L, 0xFF73);

// SFR PWM7CR: PWM7 control register
SFRX(PWM7CR, 0xFF74);
#define EC7T1SI 0x1
#define EC7T2SI 0x2
#define EC7I 0x4
#define C7_S0 0x8
#define C7_S1 0x10
#define C7INI 0x40
#define ENC7O 0x80

// SFR PWM7HLD: PWM7 level hold control register
SFRX(PWM7HLD, 0xFF75);
#define HC7L 0x1
#define HC7H 0x2

// SFR PWMCH: PWM counter high
SFRX(PWMCH, 0xFFF0);

// SFR PWMCL: PWM counter low
SFRX(PWMCL, 0xFFF1);

// SFR PWMCKS: PWM clock selection register
SFRX(PWMCKS, 0xFFF2);
#define PWM_PS0 0x1
#define PWM_PS1 0x2
#define PWM_PS2 0x4
#define PWM_PS3 0x8
#define SELT2 0x10

// SFR TADCPH: ADC counter value high
SFRX(TADCPH, 0xFFF3);

// SFR TADCPL: ADC counter value low
SFRX(TADCPL, 0xFFF4);
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
// External interrupt 2 (falling edge only)
#define EXTINT2_INTERRUPT 10
#define EXTINT2_VECTOR_ADDR 0x53
// External interrupt 3 (falling edge only)
#define EXTINT3_INTERRUPT 11
#define EXTINT3_VECTOR_ADDR 0x5B
// Timer 2 interrupt
#define TIMER2_INTERRUPT 12
#define TIMER2_VECTOR_ADDR 0x63
// External interrupt 4 (falling edge only)
#define EXTINT4_INTERRUPT 16
#define EXTINT4_VECTOR_ADDR 0x83
// UART 3 interrupt
#define UART3_INTERRUPT 17
#define UART3_VECTOR_ADDR 0x8B
// UART 4 interrupt
#define UART4_INTERRUPT 18
#define UART4_VECTOR_ADDR 0x93
// Timer 3 interrupt
#define TIMER3_INTERRUPT 19
#define TIMER3_VECTOR_ADDR 0x9B
// Timer 4 interrupt
#define TIMER4_INTERRUPT 20
#define TIMER4_VECTOR_ADDR 0xA3
// Comparator interrupt
#define CMP_INTERRUPT 21
#define CMP_VECTOR_ADDR 0xAB
// Enhanced PWM interrupt
#define PWM_INTERRUPT 22
#define PWM_VECTOR_ADDR 0xB3
// Enhanced PWM fault detection interrupt
#define PWMFD_INTERRUPT 23
#define PWMFD_VECTOR_ADDR 0xBB
// I2C interrupt
#define I2C_INTERRUPT 24
#define I2C_VECTOR_ADDR 0xC3

// Default value for macro F_CPU
#ifndef F_CPU
#define F_CPU 24000000UL
#endif

// Default value for macro T_CPU
#ifndef T_CPU
#define T_CPU 1
#endif

inline void enableExtendedSFR() { P_SW2 |= EAXSFR; }
inline void disableExtendedSFR() { P_SW2 &= ~EAXSFR; }

#endif // _STC8AF_H
