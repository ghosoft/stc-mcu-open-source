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
 * @file stc8g.h
 * 
 * Register, bit and macro definitions for the STC8G
 */

#ifndef _STC8G_H
#define _STC8G_H

#include <compiler.h>

/**
 * This file can be used with the following parts with some limitations:
 * 
 * +-------------------+-----+------+-----+-----+-------+------+--------+------------+
 * | Part              | ADC | Comp | PCA | PWM | MDU16 | UART | Timers | GPIO Ports |
 * +-------------------+-----+------+-----+-----+-------+------+--------+------------+
 * | STC8G2K64S4       | yes | yes  | yes | 6x8 | yes   | 4    | 5      | 6          |
 * | STC8G2K64S2       | yes | yes  | yes | 1x8 | yes   | 2    | 5      | 6          |
 * | STC8G1K08   8-pin | no  | no   | no  | no  | yes   | 1    | 2      | 2 (3/5)    |
 * | STC8G1K08A        | yes | no   | yes | no  | yes   | 1    | 2      | 2 (3/5)    |
 * | STC8G1K08 > 8-pin | yes | yes  | yes | no  | no    | 2    | 3      | 3 (1/3/5)  |
 * +-------------------+-----+------+-----+-----+-------+------+--------+------------+
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

// SFR IRCBAND: IRC band selection detection
SFR(IRCBAND, 0x9D);
#define BANDSEL 0x1

// SFR LIRTRIM: IRC frequency trim register
SFR(LIRTRIM, 0x9E);
#define LIRTRIM0 0x1
#define LIRTRIM1 0x2

// SFR IRTRIM: IRC frequency adjustment register
SFR(IRTRIM, 0x9F);

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
#define PPWM0 0x4
#define PPWM0FD 0x8
#define PX4 0x10
#define PCMP 0x20
#define PI2C 0x40
#define PPWM2FD 0x80

// SFR IP2H: Interrupt priority register 2 high
SFR(IP2H, 0xB6);
#define PS2H 0x1
#define PSPIH 0x2
#define PPWM0H 0x4
#define PPWM0FDH 0x8
#define PX4H 0x10
#define PCMPH 0x20
#define PI2CH 0x40
#define PPWM2FDH 0x80

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

// SFR ADC_CONTR: ADC control
SFR(ADC_CONTR, 0xBC);
#define ADC_CHS0 0x1
#define ADC_CHS1 0x2
#define ADC_CHS2 0x4
#define ADC_CHS3 0x8
#define ADC_EPWMT 0x10
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

// SFR ADCCFG: ADC configuration register
SFR(ADCCFG, 0xDE);
#define ADC_SPEED0 0x1
#define ADC_SPEED1 0x2
#define ADC_SPEED2 0x4
#define ADC_SPEED3 0x8
#define RESFMT 0x20

// SFR IP3: Interrupt priority register 3 low
SFR(IP3, 0xDF);
#define PS3 0x1
#define PS4 0x2
#define PPWM1 0x4
#define PPWM2 0x8
#define PPWM3 0x10
#define PPWM4 0x20
#define PPWM5 0x40
#define PPWM4FD 0x80

// SFR ACC: Accumulator
SFR(ACC, 0xE0);

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

// SFR CL: PCA base timer low
SFR(CL, 0xE9);

// SFR CCAP0L: PCA module 0 capture register low
SFR(CCAP0L, 0xEA);

// SFR CCAP1L: PCA module 1 capture register low
SFR(CCAP1L, 0xEB);

// SFR CCAP2L: PCA module 2 capture register low
SFR(CCAP2L, 0xEC);

// SFR IP3H: Interrupt priority register 3 high
SFR(IP3H, 0xEE);
#define PS3H 0x1
#define PS4H 0x2
#define PPWM1H 0x4
#define PPWM2H 0x8
#define PPWM3H 0x10
#define PPWM4H 0x20
#define PPWM5H 0x40
#define PPWM4FDH 0x80

// SFR AUXINTIF: Extended external interrupt flag register
SFR(AUXINTIF, 0xEF);
#define T2IF 0x1
#define INT2IF 0x10
#define INT3IF 0x20
#define INT4IF 0x40

// SFR B: B register
SFR(B, 0xF0);

// SFR PWMSET: PWM set register
SFR(PWMSET, 0xF1);
#define ENPWM0 0x1
#define ENPWM1 0x2
#define ENPWM2 0x4
#define ENPWM3 0x8
#define ENPWM4 0x10
#define ENPWM5 0x20
#define PWMRST 0x40
#define ENGLBSET 0x80

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

// SFR IAP_TPS: IAP waiting time control register
SFR(IAP_TPS, 0xF5);

// SFR PWMCFG01: PWM 0 & 1 configuration register
SFR(PWMCFG01, 0xF6);
#define PWM0CEN 0x1
#define ENPWM0TA 0x2
#define EPWM0CBI 0x4
#define PWM0CBIF 0x8
#define PWM1CEN 0x10
#define FLTPS0 0x20
#define EPWM1CBI 0x40
#define PWM1CBIF 0x80

// SFR PWMCFG23: PWM 2 & 3 configuration register
SFR(PWMCFG23, 0xF7);
#define PWM2CEN 0x1
#define ENPWM2TA 0x2
#define EPWM2CBI 0x4
#define PWM2CBIF 0x8
#define PWM3CEN 0x10
#define FLTPS1 0x20
#define EPWM3CBI 0x40
#define PWM3CBIF 0x80

// SFR CH: PCA base timer high
SFR(CH, 0xF9);

// SFR CCAP0H: PCA module 0 capture register high
SFR(CCAP0H, 0xFA);

// SFR CCAP1H: PCA module 1 capture register high
SFR(CCAP1H, 0xFB);

// SFR CCAP2H: PCA module 2 capture register high
SFR(CCAP2H, 0xFC);

// SFR PWMCFG45: PWM 4 & 5 configuration register
SFR(PWMCFG45, 0xFE);
#define PWM4CEN 0x1
#define ENPWM4TA 0x2
#define EPWM4CBI 0x4
#define PWM4CBIF 0x8
#define PWM5CEN 0x10
#define FLTPS2 0x20
#define EPWM5CBI 0x40
#define PWM5CBIF 0x80

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

// SFR CLKDIV: Clock frequency division register
SFRX(CLKDIV, 0xFE01);

// SFR HIRCCR: Internal high-speed RC oscillator control register
SFRX(HIRCCR, 0xFE02);
#define HIRCST 0x1
#define ENHIRC 0x80

// SFR XOSCCR: External oscillator control register
SFRX(XOSCCR, 0xFE03);
#define XOSCST 0x1
#define XITYPE 0x40
#define ENXOSC 0x80

// SFR IRC32KCR: Internal 32kHz oscillator control register
SFRX(IRC32KCR, 0xFE04);
#define IRC32KST 0x1
#define ENIRC32K 0x80

// SFR MCLKOCR: Main clock output control register
SFRX(MCLKOCR, 0xFE05);
#define MCLKODIV0 0x1
#define MCLKODIV1 0x2
#define MCLKODIV2 0x4
#define MCLKODIV3 0x8
#define MCLKODIV4 0x10
#define MCLKODIV5 0x20
#define MCLKODIV6 0x40
#define MCLKO_S 0x80

// SFR IRCDB: Internal high-speed oscillator debounce control
SFRX(IRCDB, 0xFE06);

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

// SFR P0SR: Port 0 level transition rate register
SFRX(P0SR, 0xFE20);

// SFR P1SR: Port 1 level transition rate register
SFRX(P1SR, 0xFE21);

// SFR P2SR: Port 2 level transition rate register
SFRX(P2SR, 0xFE22);

// SFR P3SR: Port 3 level transition rate register
SFRX(P3SR, 0xFE23);

// SFR P4SR: Port 4 level transition rate register
SFRX(P4SR, 0xFE24);

// SFR P5SR: Port 5 level transition rate register
SFRX(P5SR, 0xFE25);

// SFR P0DR: Port 0 drive current control register
SFRX(P0DR, 0xFE28);

// SFR P1DR: Port 1 drive current control register
SFRX(P1DR, 0xFE29);

// SFR P2DR: Port 2 drive current control register
SFRX(P2DR, 0xFE2A);

// SFR P3DR: Port 3 drive current control register
SFRX(P3DR, 0xFE2B);

// SFR P4DR: Port 4 drive current control register
SFRX(P4DR, 0xFE2C);

// SFR P5DR: Port 5 drive current control register
SFRX(P5DR, 0xFE2D);

// SFR P0IE: Port 0 input enable control register
SFRX(P0IE, 0xFE30);

// SFR P1IE: Port 1 input enable control register
SFRX(P1IE, 0xFE31);

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

// SFR TM2PS: Timer 2 clock prescaler register
SFRX(TM2PS, 0xFEA2);

// SFR TM3PS: Timer 3 clock prescaler register
SFRX(TM3PS, 0xFEA3);

// SFR TM4PS: Timer 4 clock prescaler register
SFRX(TM4PS, 0xFEA4);

// SFR ADCTIM: ADC timing control register
SFRX(ADCTIM, 0xFEA8);
#define SMPDUTY0 0x1
#define SMPDUTY1 0x2
#define SMPDUTY2 0x4
#define SMPDUTY3 0x8
#define SMPDUTY4 0x10
#define CSHOLD0 0x20
#define CSHOLD1 0x40
#define CSSETUP 0x80

// SFR PWM0CH: PWM0 counter high
SFRX(PWM0CH, 0xFF00);

// SFR PWM0CL: PWM0 counter low
SFRX(PWM0CL, 0xFF01);

// SFR PWM0CKS: PWM0 clock select register
SFRX(PWM0CKS, 0xFF02);
#define PWM_PS0 0x1
#define PWM_PS1 0x2
#define PWM_PS2 0x4
#define PWM_PS3 0x8
#define SELT2 0x10

// SFR PWM0TADCH: PWM0 PWM0 trigger ADC counter high
SFRX(PWM0TADCH, 0xFF03);

// SFR PWM0TADCL: PWM0 PWM0 trigger ADC counter low
SFRX(PWM0TADCL, 0xFF04);

// SFR PWM0IF: PWM0 interrupt flag register
SFRX(PWM0IF, 0xFF05);
#define C0IF 0x1
#define C1IF 0x2
#define C2IF 0x4
#define C3IF 0x8
#define C4IF 0x10
#define C5IF 0x20
#define C6IF 0x40
#define C7IF 0x80

// SFR PWM0FDCR: PWM0 fault detection control register
SFRX(PWM0FDCR, 0xFF06);
#define FDIF 0x1
#define FDIO 0x2
#define FDCMP 0x4
#define EFDI 0x8
#define FLTFLIO 0x10
#define ENFD 0x20
#define INVIO 0x40
#define INVCMP 0x80

// SFR PWM00T1H: PWM00 Timer 1 high
SFRX(PWM00T1H, 0xFF10);

// SFR PWM00T1L: PWM00 Timer 1 low
SFRX(PWM00T1L, 0xFF11);

// SFR PWM00T2H: PWM00 Timer 2 high
SFRX(PWM00T2H, 0xFF12);

// SFR PWM00T2L: PWM00 Timer 2 low
SFRX(PWM00T2L, 0xFF13);

// SFR PWM00CR: PWM00 control register
SFRX(PWM00CR, 0xFF14);
#define ENT1I 0x1
#define ENT2I 0x2
#define ENI 0x4
#define INI 0x40
#define ENO 0x80

// SFR PWM00HLD: PWM00 level hold control register
SFRX(PWM00HLD, 0xFF15);
#define HLDL 0x1
#define HLDH 0x2

// SFR PWM01T1H: PWM01 Timer 1 high
SFRX(PWM01T1H, 0xFF18);

// SFR PWM01T1L: PWM01 Timer 1 low
SFRX(PWM01T1L, 0xFF19);

// SFR PWM01T2H: PWM01 Timer 2 high
SFRX(PWM01T2H, 0xFF1A);

// SFR PWM01T2L: PWM01 Timer 2 low
SFRX(PWM01T2L, 0xFF1B);

// SFR PWM01CR: PWM01 control register
SFRX(PWM01CR, 0xFF1C);

// SFR PWM01HLD: PWM01 level hold control register
SFRX(PWM01HLD, 0xFF1D);

// SFR PWM02T1H: PWM02 Timer 1 high
SFRX(PWM02T1H, 0xFF20);

// SFR PWM02T1L: PWM02 Timer 1 low
SFRX(PWM02T1L, 0xFF21);

// SFR PWM02T2H: PWM02 Timer 2 high
SFRX(PWM02T2H, 0xFF22);

// SFR PWM02T2L: PWM02 Timer 2 low
SFRX(PWM02T2L, 0xFF23);

// SFR PWM02CR: PWM02 control register
SFRX(PWM02CR, 0xFF24);

// SFR PWM02HLD: PWM02 level hold control register
SFRX(PWM02HLD, 0xFF25);

// SFR PWM03T1H: PWM03 Timer 1 high
SFRX(PWM03T1H, 0xFF28);

// SFR PWM03T1L: PWM03 Timer 1 low
SFRX(PWM03T1L, 0xFF29);

// SFR PWM03T2H: PWM03 Timer 2 high
SFRX(PWM03T2H, 0xFF2A);

// SFR PWM03T2L: PWM03 Timer 2 low
SFRX(PWM03T2L, 0xFF2B);

// SFR PWM03CR: PWM03 control register
SFRX(PWM03CR, 0xFF2C);

// SFR PWM03HLD: PWM03 level hold control register
SFRX(PWM03HLD, 0xFF2D);

// SFR PWM04T1H: PWM04 Timer 1 high
SFRX(PWM04T1H, 0xFF30);

// SFR PWM04T1L: PWM04 Timer 1 low
SFRX(PWM04T1L, 0xFF31);

// SFR PWM04T2H: PWM04 Timer 2 high
SFRX(PWM04T2H, 0xFF32);

// SFR PWM04T2L: PWM04 Timer 2 low
SFRX(PWM04T2L, 0xFF33);

// SFR PWM04CR: PWM04 control register
SFRX(PWM04CR, 0xFF34);

// SFR PWM04HLD: PWM04 level hold control register
SFRX(PWM04HLD, 0xFF35);

// SFR PWM05T1H: PWM05 Timer 1 high
SFRX(PWM05T1H, 0xFF38);

// SFR PWM05T1L: PWM05 Timer 1 low
SFRX(PWM05T1L, 0xFF39);

// SFR PWM05T2H: PWM05 Timer 2 high
SFRX(PWM05T2H, 0xFF3A);

// SFR PWM05T2L: PWM05 Timer 2 low
SFRX(PWM05T2L, 0xFF3B);

// SFR PWM05CR: PWM05 control register
SFRX(PWM05CR, 0xFF3C);

// SFR PWM05HLD: PWM05 level hold control register
SFRX(PWM05HLD, 0xFF3D);

// SFR PWM06T1H: PWM06 Timer 1 high
SFRX(PWM06T1H, 0xFF40);

// SFR PWM06T1L: PWM06 Timer 1 low
SFRX(PWM06T1L, 0xFF41);

// SFR PWM06T2H: PWM06 Timer 2 high
SFRX(PWM06T2H, 0xFF42);

// SFR PWM06T2L: PWM06 Timer 2 low
SFRX(PWM06T2L, 0xFF43);

// SFR PWM06CR: PWM06 control register
SFRX(PWM06CR, 0xFF44);

// SFR PWM06HLD: PWM06 level hold control register
SFRX(PWM06HLD, 0xFF45);

// SFR PWM07T1H: PWM07 Timer 1 high
SFRX(PWM07T1H, 0xFF48);

// SFR PWM07T1L: PWM07 Timer 1 low
SFRX(PWM07T1L, 0xFF49);

// SFR PWM07T2H: PWM07 Timer 2 high
SFRX(PWM07T2H, 0xFF4A);

// SFR PWM07T2L: PWM07 Timer 2 low
SFRX(PWM07T2L, 0xFF4B);

// SFR PWM07CR: PWM07 control register
SFRX(PWM07CR, 0xFF4C);

// SFR PWM07HLD: PWM07 level hold control register
SFRX(PWM07HLD, 0xFF4D);

// SFR PWM1CH: PWM1 counter high
SFRX(PWM1CH, 0xFF50);

// SFR PWM1CL: PWM1 counter low
SFRX(PWM1CL, 0xFF51);

// SFR PWM1CKS: PWM1 clock select register
SFRX(PWM1CKS, 0xFF52);

// SFR PWM1TADCH: PWM1 PWM1 trigger ADC counter high
SFRX(PWM1TADCH, 0xFF53);

// SFR PWM1TADCL: PWM1 PWM1 trigger ADC counter low
SFRX(PWM1TADCL, 0xFF54);

// SFR PWM1IF: PWM1 interrupt flag register
SFRX(PWM1IF, 0xFF55);

// SFR PWM1FDCR: PWM1 fault detection control register
SFRX(PWM1FDCR, 0xFF56);

// SFR PWM10T1H: PWM10 Timer 1 high
SFRX(PWM10T1H, 0xFF60);

// SFR PWM10T1L: PWM10 Timer 1 low
SFRX(PWM10T1L, 0xFF61);

// SFR PWM10T2H: PWM10 Timer 2 high
SFRX(PWM10T2H, 0xFF62);

// SFR PWM10T2L: PWM10 Timer 2 low
SFRX(PWM10T2L, 0xFF63);

// SFR PWM10CR: PWM10 control register
SFRX(PWM10CR, 0xFF64);

// SFR PWM10HLD: PWM10 level hold control register
SFRX(PWM10HLD, 0xFF65);

// SFR PWM11T1H: PWM11 Timer 1 high
SFRX(PWM11T1H, 0xFF68);

// SFR PWM11T1L: PWM11 Timer 1 low
SFRX(PWM11T1L, 0xFF69);

// SFR PWM11T2H: PWM11 Timer 2 high
SFRX(PWM11T2H, 0xFF6A);

// SFR PWM11T2L: PWM11 Timer 2 low
SFRX(PWM11T2L, 0xFF6B);

// SFR PWM11CR: PWM11 control register
SFRX(PWM11CR, 0xFF6C);

// SFR PWM11HLD: PWM11 level hold control register
SFRX(PWM11HLD, 0xFF6D);

// SFR PWM12T1H: PWM12 Timer 1 high
SFRX(PWM12T1H, 0xFF70);

// SFR PWM12T1L: PWM12 Timer 1 low
SFRX(PWM12T1L, 0xFF71);

// SFR PWM12T2H: PWM12 Timer 2 high
SFRX(PWM12T2H, 0xFF72);

// SFR PWM12T2L: PWM12 Timer 2 low
SFRX(PWM12T2L, 0xFF73);

// SFR PWM12CR: PWM12 control register
SFRX(PWM12CR, 0xFF74);

// SFR PWM12HLD: PWM12 level hold control register
SFRX(PWM12HLD, 0xFF75);

// SFR PWM13T1H: PWM13 Timer 1 high
SFRX(PWM13T1H, 0xFF78);

// SFR PWM13T1L: PWM13 Timer 1 low
SFRX(PWM13T1L, 0xFF79);

// SFR PWM13T2H: PWM13 Timer 2 high
SFRX(PWM13T2H, 0xFF7A);

// SFR PWM13T2L: PWM13 Timer 2 low
SFRX(PWM13T2L, 0xFF7B);

// SFR PWM13CR: PWM13 control register
SFRX(PWM13CR, 0xFF7C);

// SFR PWM13HLD: PWM13 level hold control register
SFRX(PWM13HLD, 0xFF7D);

// SFR PWM14T1H: PWM14 Timer 1 high
SFRX(PWM14T1H, 0xFF80);

// SFR PWM14T1L: PWM14 Timer 1 low
SFRX(PWM14T1L, 0xFF81);

// SFR PWM14T2H: PWM14 Timer 2 high
SFRX(PWM14T2H, 0xFF82);

// SFR PWM14T2L: PWM14 Timer 2 low
SFRX(PWM14T2L, 0xFF83);

// SFR PWM14CR: PWM14 control register
SFRX(PWM14CR, 0xFF84);

// SFR PWM14HLD: PWM14 level hold control register
SFRX(PWM14HLD, 0xFF85);

// SFR PWM15T1H: PWM15 Timer 1 high
SFRX(PWM15T1H, 0xFF88);

// SFR PWM15T1L: PWM15 Timer 1 low
SFRX(PWM15T1L, 0xFF89);

// SFR PWM15T2H: PWM15 Timer 2 high
SFRX(PWM15T2H, 0xFF8A);

// SFR PWM15T2L: PWM15 Timer 2 low
SFRX(PWM15T2L, 0xFF8B);

// SFR PWM15CR: PWM15 control register
SFRX(PWM15CR, 0xFF8C);

// SFR PWM15HLD: PWM15 level hold control register
SFRX(PWM15HLD, 0xFF8D);

// SFR PWM16T1H: PWM16 Timer 1 high
SFRX(PWM16T1H, 0xFF90);

// SFR PWM16T1L: PWM16 Timer 1 low
SFRX(PWM16T1L, 0xFF91);

// SFR PWM16T2H: PWM16 Timer 2 high
SFRX(PWM16T2H, 0xFF92);

// SFR PWM16T2L: PWM16 Timer 2 low
SFRX(PWM16T2L, 0xFF93);

// SFR PWM16CR: PWM16 control register
SFRX(PWM16CR, 0xFF94);

// SFR PWM16HLD: PWM16 level hold control register
SFRX(PWM16HLD, 0xFF95);

// SFR PWM17T1H: PWM17 Timer 1 high
SFRX(PWM17T1H, 0xFF98);

// SFR PWM17T1L: PWM17 Timer 1 low
SFRX(PWM17T1L, 0xFF99);

// SFR PWM17T2H: PWM17 Timer 2 high
SFRX(PWM17T2H, 0xFF9A);

// SFR PWM17T2L: PWM17 Timer 2 low
SFRX(PWM17T2L, 0xFF9B);

// SFR PWM17CR: PWM17 control register
SFRX(PWM17CR, 0xFF9C);

// SFR PWM17HLD: PWM17 level hold control register
SFRX(PWM17HLD, 0xFF9D);

// SFR PWM2CH: PWM2 counter high
SFRX(PWM2CH, 0xFFA0);

// SFR PWM2CL: PWM2 counter low
SFRX(PWM2CL, 0xFFA1);

// SFR PWM2CKS: PWM2 clock select register
SFRX(PWM2CKS, 0xFFA2);

// SFR PWM2TADCH: PWM2 PWM2 trigger ADC counter high
SFRX(PWM2TADCH, 0xFFA3);

// SFR PWM2TADCL: PWM2 PWM2 trigger ADC counter low
SFRX(PWM2TADCL, 0xFFA4);

// SFR PWM2IF: PWM2 interrupt flag register
SFRX(PWM2IF, 0xFFA5);

// SFR PWM2FDCR: PWM2 fault detection control register
SFRX(PWM2FDCR, 0xFFA6);

// SFR PWM20T1H: PWM20 Timer 1 high
SFRX(PWM20T1H, 0xFFB0);

// SFR PWM20T1L: PWM20 Timer 1 low
SFRX(PWM20T1L, 0xFFB1);

// SFR PWM20T2H: PWM20 Timer 2 high
SFRX(PWM20T2H, 0xFFB2);

// SFR PWM20T2L: PWM20 Timer 2 low
SFRX(PWM20T2L, 0xFFB3);

// SFR PWM20CR: PWM20 control register
SFRX(PWM20CR, 0xFFB4);

// SFR PWM20HLD: PWM20 level hold control register
SFRX(PWM20HLD, 0xFFB5);

// SFR PWM21T1H: PWM21 Timer 1 high
SFRX(PWM21T1H, 0xFFB8);

// SFR PWM21T1L: PWM21 Timer 1 low
SFRX(PWM21T1L, 0xFFB9);

// SFR PWM21T2H: PWM21 Timer 2 high
SFRX(PWM21T2H, 0xFFBA);

// SFR PWM21T2L: PWM21 Timer 2 low
SFRX(PWM21T2L, 0xFFBB);

// SFR PWM21CR: PWM21 control register
SFRX(PWM21CR, 0xFFBC);

// SFR PWM21HLD: PWM21 level hold control register
SFRX(PWM21HLD, 0xFFBD);

// SFR PWM22T1H: PWM22 Timer 1 high
SFRX(PWM22T1H, 0xFFC0);

// SFR PWM22T1L: PWM22 Timer 1 low
SFRX(PWM22T1L, 0xFFC1);

// SFR PWM22T2H: PWM22 Timer 2 high
SFRX(PWM22T2H, 0xFFC2);

// SFR PWM22T2L: PWM22 Timer 2 low
SFRX(PWM22T2L, 0xFFC3);

// SFR PWM22CR: PWM22 control register
SFRX(PWM22CR, 0xFFC4);

// SFR PWM22HLD: PWM22 level hold control register
SFRX(PWM22HLD, 0xFFC5);

// SFR PWM23T1H: PWM23 Timer 1 high
SFRX(PWM23T1H, 0xFFC8);

// SFR PWM23T1L: PWM23 Timer 1 low
SFRX(PWM23T1L, 0xFFC9);

// SFR PWM23T2H: PWM23 Timer 2 high
SFRX(PWM23T2H, 0xFFCA);

// SFR PWM23T2L: PWM23 Timer 2 low
SFRX(PWM23T2L, 0xFFCB);

// SFR PWM23CR: PWM23 control register
SFRX(PWM23CR, 0xFFCC);

// SFR PWM23HLD: PWM23 level hold control register
SFRX(PWM23HLD, 0xFFCD);

// SFR PWM24T1H: PWM24 Timer 1 high
SFRX(PWM24T1H, 0xFFD0);

// SFR PWM24T1L: PWM24 Timer 1 low
SFRX(PWM24T1L, 0xFFD1);

// SFR PWM24T2H: PWM24 Timer 2 high
SFRX(PWM24T2H, 0xFFD2);

// SFR PWM24T2L: PWM24 Timer 2 low
SFRX(PWM24T2L, 0xFFD3);

// SFR PWM24CR: PWM24 control register
SFRX(PWM24CR, 0xFFD4);

// SFR PWM24HLD: PWM24 level hold control register
SFRX(PWM24HLD, 0xFFD5);

// SFR PWM25T1H: PWM25 Timer 1 high
SFRX(PWM25T1H, 0xFFD8);

// SFR PWM25T1L: PWM25 Timer 1 low
SFRX(PWM25T1L, 0xFFD9);

// SFR PWM25T2H: PWM25 Timer 2 high
SFRX(PWM25T2H, 0xFFDA);

// SFR PWM25T2L: PWM25 Timer 2 low
SFRX(PWM25T2L, 0xFFDB);

// SFR PWM25CR: PWM25 control register
SFRX(PWM25CR, 0xFFDC);

// SFR PWM25HLD: PWM25 level hold control register
SFRX(PWM25HLD, 0xFFDD);

// SFR PWM26T1H: PWM26 Timer 1 high
SFRX(PWM26T1H, 0xFFE0);

// SFR PWM26T1L: PWM26 Timer 1 low
SFRX(PWM26T1L, 0xFFE1);

// SFR PWM26T2H: PWM26 Timer 2 high
SFRX(PWM26T2H, 0xFFE2);

// SFR PWM26T2L: PWM26 Timer 2 low
SFRX(PWM26T2L, 0xFFE3);

// SFR PWM26CR: PWM26 control register
SFRX(PWM26CR, 0xFFE4);

// SFR PWM26HLD: PWM26 level hold control register
SFRX(PWM26HLD, 0xFFE5);

// SFR PWM27T1H: PWM27 Timer 1 high
SFRX(PWM27T1H, 0xFFE8);

// SFR PWM27T1L: PWM27 Timer 1 low
SFRX(PWM27T1L, 0xFFE9);

// SFR PWM27T2H: PWM27 Timer 2 high
SFRX(PWM27T2H, 0xFFEA);

// SFR PWM27T2L: PWM27 Timer 2 low
SFRX(PWM27T2L, 0xFFEB);

// SFR PWM27CR: PWM27 control register
SFRX(PWM27CR, 0xFFEC);

// SFR PWM27HLD: PWM27 level hold control register
SFRX(PWM27HLD, 0xFFED);

// SFR PWM3CH: PWM3 counter high
SFRX(PWM3CH, 0xFC00);

// SFR PWM3CL: PWM3 counter low
SFRX(PWM3CL, 0xFC01);

// SFR PWM3CKS: PWM3 clock select register
SFRX(PWM3CKS, 0xFC02);

// SFR PWM3TADCH: PWM3 PWM3 trigger ADC counter high
SFRX(PWM3TADCH, 0xFC03);

// SFR PWM3TADCL: PWM3 PWM3 trigger ADC counter low
SFRX(PWM3TADCL, 0xFC04);

// SFR PWM3IF: PWM3 interrupt flag register
SFRX(PWM3IF, 0xFC05);

// SFR PWM3FDCR: PWM3 fault detection control register
SFRX(PWM3FDCR, 0xFC06);

// SFR PWM30T1H: PWM30 Timer 1 high
SFRX(PWM30T1H, 0xFC10);

// SFR PWM30T1L: PWM30 Timer 1 low
SFRX(PWM30T1L, 0xFC11);

// SFR PWM30T2H: PWM30 Timer 2 high
SFRX(PWM30T2H, 0xFC12);

// SFR PWM30T2L: PWM30 Timer 2 low
SFRX(PWM30T2L, 0xFC13);

// SFR PWM30CR: PWM30 control register
SFRX(PWM30CR, 0xFC14);

// SFR PWM30HLD: PWM30 level hold control register
SFRX(PWM30HLD, 0xFC15);

// SFR PWM31T1H: PWM31 Timer 1 high
SFRX(PWM31T1H, 0xFC18);

// SFR PWM31T1L: PWM31 Timer 1 low
SFRX(PWM31T1L, 0xFC19);

// SFR PWM31T2H: PWM31 Timer 2 high
SFRX(PWM31T2H, 0xFC1A);

// SFR PWM31T2L: PWM31 Timer 2 low
SFRX(PWM31T2L, 0xFC1B);

// SFR PWM31CR: PWM31 control register
SFRX(PWM31CR, 0xFC1C);

// SFR PWM31HLD: PWM31 level hold control register
SFRX(PWM31HLD, 0xFC1D);

// SFR PWM32T1H: PWM32 Timer 1 high
SFRX(PWM32T1H, 0xFC20);

// SFR PWM32T1L: PWM32 Timer 1 low
SFRX(PWM32T1L, 0xFC21);

// SFR PWM32T2H: PWM32 Timer 2 high
SFRX(PWM32T2H, 0xFC22);

// SFR PWM32T2L: PWM32 Timer 2 low
SFRX(PWM32T2L, 0xFC23);

// SFR PWM32CR: PWM32 control register
SFRX(PWM32CR, 0xFC24);

// SFR PWM32HLD: PWM32 level hold control register
SFRX(PWM32HLD, 0xFC25);

// SFR PWM33T1H: PWM33 Timer 1 high
SFRX(PWM33T1H, 0xFC28);

// SFR PWM33T1L: PWM33 Timer 1 low
SFRX(PWM33T1L, 0xFC29);

// SFR PWM33T2H: PWM33 Timer 2 high
SFRX(PWM33T2H, 0xFC2A);

// SFR PWM33T2L: PWM33 Timer 2 low
SFRX(PWM33T2L, 0xFC2B);

// SFR PWM33CR: PWM33 control register
SFRX(PWM33CR, 0xFC2C);

// SFR PWM33HLD: PWM33 level hold control register
SFRX(PWM33HLD, 0xFC2D);

// SFR PWM34T1H: PWM34 Timer 1 high
SFRX(PWM34T1H, 0xFC30);

// SFR PWM34T1L: PWM34 Timer 1 low
SFRX(PWM34T1L, 0xFC31);

// SFR PWM34T2H: PWM34 Timer 2 high
SFRX(PWM34T2H, 0xFC32);

// SFR PWM34T2L: PWM34 Timer 2 low
SFRX(PWM34T2L, 0xFC33);

// SFR PWM34CR: PWM34 control register
SFRX(PWM34CR, 0xFC34);

// SFR PWM34HLD: PWM34 level hold control register
SFRX(PWM34HLD, 0xFC35);

// SFR PWM35T1H: PWM35 Timer 1 high
SFRX(PWM35T1H, 0xFC38);

// SFR PWM35T1L: PWM35 Timer 1 low
SFRX(PWM35T1L, 0xFC39);

// SFR PWM35T2H: PWM35 Timer 2 high
SFRX(PWM35T2H, 0xFC3A);

// SFR PWM35T2L: PWM35 Timer 2 low
SFRX(PWM35T2L, 0xFC3B);

// SFR PWM35CR: PWM35 control register
SFRX(PWM35CR, 0xFC3C);

// SFR PWM35HLD: PWM35 level hold control register
SFRX(PWM35HLD, 0xFC3D);

// SFR PWM36T1H: PWM36 Timer 1 high
SFRX(PWM36T1H, 0xFC40);

// SFR PWM36T1L: PWM36 Timer 1 low
SFRX(PWM36T1L, 0xFC41);

// SFR PWM36T2H: PWM36 Timer 2 high
SFRX(PWM36T2H, 0xFC42);

// SFR PWM36T2L: PWM36 Timer 2 low
SFRX(PWM36T2L, 0xFC43);

// SFR PWM36CR: PWM36 control register
SFRX(PWM36CR, 0xFC44);

// SFR PWM36HLD: PWM36 level hold control register
SFRX(PWM36HLD, 0xFC45);

// SFR PWM37T1H: PWM37 Timer 1 high
SFRX(PWM37T1H, 0xFC48);

// SFR PWM37T1L: PWM37 Timer 1 low
SFRX(PWM37T1L, 0xFC49);

// SFR PWM37T2H: PWM37 Timer 2 high
SFRX(PWM37T2H, 0xFC4A);

// SFR PWM37T2L: PWM37 Timer 2 low
SFRX(PWM37T2L, 0xFC4B);

// SFR PWM37CR: PWM37 control register
SFRX(PWM37CR, 0xFC4C);

// SFR PWM37HLD: PWM37 level hold control register
SFRX(PWM37HLD, 0xFC4D);

// SFR PWM4CH: PWM4 counter high
SFRX(PWM4CH, 0xFC50);

// SFR PWM4CL: PWM4 counter low
SFRX(PWM4CL, 0xFC51);

// SFR PWM4CKS: PWM4 clock select register
SFRX(PWM4CKS, 0xFC52);

// SFR PWM4TADCH: PWM4 PWM4 trigger ADC counter high
SFRX(PWM4TADCH, 0xFC53);

// SFR PWM4TADCL: PWM4 PWM4 trigger ADC counter low
SFRX(PWM4TADCL, 0xFC54);

// SFR PWM4IF: PWM4 interrupt flag register
SFRX(PWM4IF, 0xFC55);

// SFR PWM4FDCR: PWM4 fault detection control register
SFRX(PWM4FDCR, 0xFC56);

// SFR PWM40T1H: PWM40 Timer 1 high
SFRX(PWM40T1H, 0xFC60);

// SFR PWM40T1L: PWM40 Timer 1 low
SFRX(PWM40T1L, 0xFC61);

// SFR PWM40T2H: PWM40 Timer 2 high
SFRX(PWM40T2H, 0xFC62);

// SFR PWM40T2L: PWM40 Timer 2 low
SFRX(PWM40T2L, 0xFC63);

// SFR PWM40CR: PWM40 control register
SFRX(PWM40CR, 0xFC64);

// SFR PWM40HLD: PWM40 level hold control register
SFRX(PWM40HLD, 0xFC65);

// SFR PWM41T1H: PWM41 Timer 1 high
SFRX(PWM41T1H, 0xFC68);

// SFR PWM41T1L: PWM41 Timer 1 low
SFRX(PWM41T1L, 0xFC69);

// SFR PWM41T2H: PWM41 Timer 2 high
SFRX(PWM41T2H, 0xFC6A);

// SFR PWM41T2L: PWM41 Timer 2 low
SFRX(PWM41T2L, 0xFC6B);

// SFR PWM41CR: PWM41 control register
SFRX(PWM41CR, 0xFC6C);

// SFR PWM41HLD: PWM41 level hold control register
SFRX(PWM41HLD, 0xFC6D);

// SFR PWM42T1H: PWM42 Timer 1 high
SFRX(PWM42T1H, 0xFC70);

// SFR PWM42T1L: PWM42 Timer 1 low
SFRX(PWM42T1L, 0xFC71);

// SFR PWM42T2H: PWM42 Timer 2 high
SFRX(PWM42T2H, 0xFC72);

// SFR PWM42T2L: PWM42 Timer 2 low
SFRX(PWM42T2L, 0xFC73);

// SFR PWM42CR: PWM42 control register
SFRX(PWM42CR, 0xFC74);

// SFR PWM42HLD: PWM42 level hold control register
SFRX(PWM42HLD, 0xFC75);

// SFR PWM43T1H: PWM43 Timer 1 high
SFRX(PWM43T1H, 0xFC78);

// SFR PWM43T1L: PWM43 Timer 1 low
SFRX(PWM43T1L, 0xFC79);

// SFR PWM43T2H: PWM43 Timer 2 high
SFRX(PWM43T2H, 0xFC7A);

// SFR PWM43T2L: PWM43 Timer 2 low
SFRX(PWM43T2L, 0xFC7B);

// SFR PWM43CR: PWM43 control register
SFRX(PWM43CR, 0xFC7C);

// SFR PWM43HLD: PWM43 level hold control register
SFRX(PWM43HLD, 0xFC7D);

// SFR PWM44T1H: PWM44 Timer 1 high
SFRX(PWM44T1H, 0xFC80);

// SFR PWM44T1L: PWM44 Timer 1 low
SFRX(PWM44T1L, 0xFC81);

// SFR PWM44T2H: PWM44 Timer 2 high
SFRX(PWM44T2H, 0xFC82);

// SFR PWM44T2L: PWM44 Timer 2 low
SFRX(PWM44T2L, 0xFC83);

// SFR PWM44CR: PWM44 control register
SFRX(PWM44CR, 0xFC84);

// SFR PWM44HLD: PWM44 level hold control register
SFRX(PWM44HLD, 0xFC85);

// SFR PWM45T1H: PWM45 Timer 1 high
SFRX(PWM45T1H, 0xFC88);

// SFR PWM45T1L: PWM45 Timer 1 low
SFRX(PWM45T1L, 0xFC89);

// SFR PWM45T2H: PWM45 Timer 2 high
SFRX(PWM45T2H, 0xFC8A);

// SFR PWM45T2L: PWM45 Timer 2 low
SFRX(PWM45T2L, 0xFC8B);

// SFR PWM45CR: PWM45 control register
SFRX(PWM45CR, 0xFC8C);

// SFR PWM45HLD: PWM45 level hold control register
SFRX(PWM45HLD, 0xFC8D);

// SFR PWM46T1H: PWM46 Timer 1 high
SFRX(PWM46T1H, 0xFC90);

// SFR PWM46T1L: PWM46 Timer 1 low
SFRX(PWM46T1L, 0xFC91);

// SFR PWM46T2H: PWM46 Timer 2 high
SFRX(PWM46T2H, 0xFC92);

// SFR PWM46T2L: PWM46 Timer 2 low
SFRX(PWM46T2L, 0xFC93);

// SFR PWM46CR: PWM46 control register
SFRX(PWM46CR, 0xFC94);

// SFR PWM46HLD: PWM46 level hold control register
SFRX(PWM46HLD, 0xFC95);

// SFR PWM47T1H: PWM47 Timer 1 high
SFRX(PWM47T1H, 0xFC98);

// SFR PWM47T1L: PWM47 Timer 1 low
SFRX(PWM47T1L, 0xFC99);

// SFR PWM47T2H: PWM47 Timer 2 high
SFRX(PWM47T2H, 0xFC9A);

// SFR PWM47T2L: PWM47 Timer 2 low
SFRX(PWM47T2L, 0xFC9B);

// SFR PWM47CR: PWM47 control register
SFRX(PWM47CR, 0xFC9C);

// SFR PWM47HLD: PWM47 level hold control register
SFRX(PWM47HLD, 0xFC9D);

// SFR PWM5CH: PWM5 counter high
SFRX(PWM5CH, 0xFCA0);

// SFR PWM5CL: PWM5 counter low
SFRX(PWM5CL, 0xFCA1);

// SFR PWM5CKS: PWM5 clock select register
SFRX(PWM5CKS, 0xFCA2);

// SFR PWM5TADCH: PWM5 PWM5 trigger ADC counter high
SFRX(PWM5TADCH, 0xFCA3);

// SFR PWM5TADCL: PWM5 PWM5 trigger ADC counter low
SFRX(PWM5TADCL, 0xFCA4);

// SFR PWM5IF: PWM5 interrupt flag register
SFRX(PWM5IF, 0xFCA5);

// SFR PWM5FDCR: PWM5 fault detection control register
SFRX(PWM5FDCR, 0xFCA6);

// SFR PWM50T1H: PWM50 Timer 1 high
SFRX(PWM50T1H, 0xFCB0);

// SFR PWM50T1L: PWM50 Timer 1 low
SFRX(PWM50T1L, 0xFCB1);

// SFR PWM50T2H: PWM50 Timer 2 high
SFRX(PWM50T2H, 0xFCB2);

// SFR PWM50T2L: PWM50 Timer 2 low
SFRX(PWM50T2L, 0xFCB3);

// SFR PWM50CR: PWM50 control register
SFRX(PWM50CR, 0xFCB4);

// SFR PWM50HLD: PWM50 level hold control register
SFRX(PWM50HLD, 0xFCB5);

// SFR PWM51T1H: PWM51 Timer 1 high
SFRX(PWM51T1H, 0xFCB8);

// SFR PWM51T1L: PWM51 Timer 1 low
SFRX(PWM51T1L, 0xFCB9);

// SFR PWM51T2H: PWM51 Timer 2 high
SFRX(PWM51T2H, 0xFCBA);

// SFR PWM51T2L: PWM51 Timer 2 low
SFRX(PWM51T2L, 0xFCBB);

// SFR PWM51CR: PWM51 control register
SFRX(PWM51CR, 0xFCBC);

// SFR PWM51HLD: PWM51 level hold control register
SFRX(PWM51HLD, 0xFCBD);

// SFR PWM52T1H: PWM52 Timer 1 high
SFRX(PWM52T1H, 0xFCC0);

// SFR PWM52T1L: PWM52 Timer 1 low
SFRX(PWM52T1L, 0xFCC1);

// SFR PWM52T2H: PWM52 Timer 2 high
SFRX(PWM52T2H, 0xFCC2);

// SFR PWM52T2L: PWM52 Timer 2 low
SFRX(PWM52T2L, 0xFCC3);

// SFR PWM52CR: PWM52 control register
SFRX(PWM52CR, 0xFCC4);

// SFR PWM52HLD: PWM52 level hold control register
SFRX(PWM52HLD, 0xFCC5);

// SFR PWM53T1H: PWM53 Timer 1 high
SFRX(PWM53T1H, 0xFCC8);

// SFR PWM53T1L: PWM53 Timer 1 low
SFRX(PWM53T1L, 0xFCC9);

// SFR PWM53T2H: PWM53 Timer 2 high
SFRX(PWM53T2H, 0xFCCA);

// SFR PWM53T2L: PWM53 Timer 2 low
SFRX(PWM53T2L, 0xFCCB);

// SFR PWM53CR: PWM53 control register
SFRX(PWM53CR, 0xFCCC);

// SFR PWM53HLD: PWM53 level hold control register
SFRX(PWM53HLD, 0xFCCD);

// SFR PWM54T1H: PWM54 Timer 1 high
SFRX(PWM54T1H, 0xFCD0);

// SFR PWM54T1L: PWM54 Timer 1 low
SFRX(PWM54T1L, 0xFCD1);

// SFR PWM54T2H: PWM54 Timer 2 high
SFRX(PWM54T2H, 0xFCD2);

// SFR PWM54T2L: PWM54 Timer 2 low
SFRX(PWM54T2L, 0xFCD3);

// SFR PWM54CR: PWM54 control register
SFRX(PWM54CR, 0xFCD4);

// SFR PWM54HLD: PWM54 level hold control register
SFRX(PWM54HLD, 0xFCD5);

// SFR PWM55T1H: PWM55 Timer 1 high
SFRX(PWM55T1H, 0xFCD8);

// SFR PWM55T1L: PWM55 Timer 1 low
SFRX(PWM55T1L, 0xFCD9);

// SFR PWM55T2H: PWM55 Timer 2 high
SFRX(PWM55T2H, 0xFCDA);

// SFR PWM55T2L: PWM55 Timer 2 low
SFRX(PWM55T2L, 0xFCDB);

// SFR PWM55CR: PWM55 control register
SFRX(PWM55CR, 0xFCDC);

// SFR PWM55HLD: PWM55 level hold control register
SFRX(PWM55HLD, 0xFCDD);

// SFR PWM56T1H: PWM56 Timer 1 high
SFRX(PWM56T1H, 0xFCE0);

// SFR PWM56T1L: PWM56 Timer 1 low
SFRX(PWM56T1L, 0xFCE1);

// SFR PWM56T2H: PWM56 Timer 2 high
SFRX(PWM56T2H, 0xFCE2);

// SFR PWM56T2L: PWM56 Timer 2 low
SFRX(PWM56T2L, 0xFCE3);

// SFR PWM56CR: PWM56 control register
SFRX(PWM56CR, 0xFCE4);

// SFR PWM56HLD: PWM56 level hold control register
SFRX(PWM56HLD, 0xFCE5);

// SFR PWM57T1H: PWM57 Timer 1 high
SFRX(PWM57T1H, 0xFCE8);

// SFR PWM57T1L: PWM57 Timer 1 low
SFRX(PWM57T1L, 0xFCE9);

// SFR PWM57T2H: PWM57 Timer 2 high
SFRX(PWM57T2H, 0xFCEA);

// SFR PWM57T2L: PWM57 Timer 2 low
SFRX(PWM57T2L, 0xFCEB);

// SFR PWM57CR: PWM57 control register
SFRX(PWM57CR, 0xFCEC);

// SFR PWM57HLD: PWM57 level hold control register
SFRX(PWM57HLD, 0xFCED);

// SFR MD3: MDU data register
SFRX(MD3, 0xFCF0);

// SFR MD2: MDU data register
SFRX(MD2, 0xFCF1);

// SFR MD1: MDU data register
SFRX(MD1, 0xFCF2);

// SFR MD0: MDU data register
SFRX(MD0, 0xFCF3);

// SFR MD5: MDU data register
SFRX(MD5, 0xFCF4);

// SFR MD4: MDU data register
SFRX(MD4, 0xFCF5);

// SFR ARCON: MDU mode control register
SFRX(ARCON, 0xFCF6);
#define SC0 0x1
#define SC1 0x2
#define SC2 0x4
#define SC3 0x8
#define SC4 0x10
#define MODE0 0x20
#define MODE1 0x40
#define MODE2 0x80

// SFR OPCON: MDU operation control register
SFRX(OPCON, 0xFCF7);
#define ENOP 0x1
#define RST 0x2
#define MDOV 0x40
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
// PWM group 0 interrupt
#define PWM0_INTERRUPT 22
#define PWM0_VECTOR_ADDR 0xB3
// PWM group 0 fault detection interrupt
#define PWM0FD_INTERRUPT 23
#define PWM0FD_VECTOR_ADDR 0xBB
// I2C interrupt
#define I2C_INTERRUPT 24
#define I2C_VECTOR_ADDR 0xC3
// PWM group 1 interrupt
#define PWM1_INTERRUPT 28
#define PWM1_VECTOR_ADDR 0xE3
// PWM group 2 interrupt
#define PWM2_INTERRUPT 29
#define PWM2_VECTOR_ADDR 0xEB
// PWM group 3 interrupt
#define PWM3_INTERRUPT 30
#define PWM3_VECTOR_ADDR 0xF3
// PWM group 4 interrupt
#define PWM4_INTERRUPT 31
#define PWM4_VECTOR_ADDR 0xFB
// PWM group 5 interrupt (usage in C => see STC8G TRM appendix N)
#define PWM5_INTERRUPT 32_SEE_APPENDIX_N
#define PWM5_VECTOR_ADDR 0x103
// PWM group 2 fault detection interrupt (usage in C => see STC8G TRM appendix N)
#define PWM2FD_INTERRUPT 33_SEE_APPENDIX_N
#define PWM2FD_VECTOR_ADDR 0x10B
// PWM group 4 fault detection interrupt (usage in C => see STC8G TRM appendix N)
#define PWM4FD_INTERRUPT 34_SEE_APPENDIX_N
#define PWM4FD_VECTOR_ADDR 0x113
// Touch key interrupt (usage in C => see STC8G TRM appendix N)
#define TKSU_INTERRUPT 35_SEE_APPENDIX_N
#define TKSU_VECTOR_ADDR 0x11B

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

#endif // _STC8G_H
