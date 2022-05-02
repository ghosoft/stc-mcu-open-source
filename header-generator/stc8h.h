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
 * @file stc8h.h
 * 
 * Register, bit and macro definitions for the STC8H
 */

#ifndef _STC8H_H
#define _STC8H_H

#include <compiler.h>

/**
 * This file can be used with the following parts with some limitations:
 * 
 * +-------------+-----+-----+------+--------+-------------------+
 * | Part        | MDU | USB | UART | Timers | GPIO Ports & Int. |
 * +-------------+-----+-----+------+--------+-------------------+
 * | STC8H8K64U  | yes | yes | 4    | 5      | 8             no  |
 * | STC8H3K64S4 | yes | no  | 4    | 5      | 8             yes |
 * | STC8H3K64S2 | yes | no  | 2    | 5      | 8             yes |
 * | STC8H1K28   | no  | no  | 2    | 5      | 5 (0/1/2/3/5) no  |
 * | STC8H1K08   | no  | no  | 2    | 3      | 3 (1/3/5)     no  |
 * +-------------+-----+-----+------+--------+-------------------+
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

// SFR USBCLK: USB clock control register
SFR(USBCLK, 0xDC);
#define PHYTST0 0x1
#define PHYTST1 0x2
#define TST_PHY 0x4
#define TST_USB 0x8
#define CRE 0x10
#define PCKI0 0x20
#define PCKI1 0x40
#define ENCKM 0x80

// SFR ADCCFG: ADC configuration register
SFR(ADCCFG, 0xDE);
#define ADC_SPEED0 0x1
#define ADC_SPEED1 0x2
#define ADC_SPEED2 0x4
#define ADC_SPEED3 0x8
#define RESFMT 0x20

// SFR IP3: 
SFR(IP3, 0xDF);

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

// SFR USBDAT: USB data register
SFR(USBDAT, 0xEC);

// SFR IP3H: 
SFR(IP3H, 0xEE);

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

// SFR USBCON: USB control register
SFR(USBCON, 0xF4);
#define DM 0x1
#define DP 0x2
#define DFREC 0x4
#define PDEN 0x8
#define PUEN 0x10
#define PS2M 0x20
#define USBRST 0x40
#define ENUSB 0x80

// SFR IAP_TPS: 
SFR(IAP_TPS, 0xF5);

// SFR P7: Port 7
SFR(P7, 0xF8);

// SFR USBADR: USB address register
SFR(USBADR, 0xFC);
#define UADR0 0x1
#define UADR1 0x2
#define UADR2 0x4
#define UADR3 0x8
#define UADR4 0x10
#define UADR5 0x20
#define AUTORD 0x40
#define BUSY 0x80

// SFR RSTCFG: Reset configuration register
SFR(RSTCFG, 0xFF);
#define LVDS0 0x1
#define LVDS1 0x2
#define P54RST 0x10
#define ENLVR 0x40

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

// SFR P0INTE: Port 0 interrupt enable register
SFRX(P0INTE, 0xFD00);

// SFR P1INTE: Port 1 interrupt enable register
SFRX(P1INTE, 0xFD01);

// SFR P2INTE: Port 2 interrupt enable register
SFRX(P2INTE, 0xFD02);

// SFR P3INTE: Port 3 interrupt enable register
SFRX(P3INTE, 0xFD03);

// SFR P4INTE: Port 4 interrupt enable register
SFRX(P4INTE, 0xFD04);

// SFR P5INTE: Port 5 interrupt enable register
SFRX(P5INTE, 0xFD05);

// SFR P6INTE: Port 6 interrupt enable register
SFRX(P6INTE, 0xFD06);

// SFR P7INTE: Port 7 interrupt enable register
SFRX(P7INTE, 0xFD07);

// SFR P0INTF: Port 0 interrupt flag register
SFRX(P0INTF, 0xFD10);

// SFR P1INTF: Port 1 interrupt flag register
SFRX(P1INTF, 0xFD11);

// SFR P2INTF: Port 2 interrupt flag register
SFRX(P2INTF, 0xFD12);

// SFR P3INTF: Port 3 interrupt flag register
SFRX(P3INTF, 0xFD13);

// SFR P4INTF: Port 4 interrupt flag register
SFRX(P4INTF, 0xFD14);

// SFR P5INTF: Port 5 interrupt flag register
SFRX(P5INTF, 0xFD15);

// SFR P6INTF: Port 6 interrupt flag register
SFRX(P6INTF, 0xFD16);

// SFR P7INTF: Port 7 interrupt flag register
SFRX(P7INTF, 0xFD17);

// SFR P0IM0: Port 0 interrupt mode register 0
SFRX(P0IM0, 0xFD20);

// SFR P1IM0: Port 1 interrupt mode register 0
SFRX(P1IM0, 0xFD21);

// SFR P2IM0: Port 2 interrupt mode register 0
SFRX(P2IM0, 0xFD22);

// SFR P3IM0: Port 3 interrupt mode register 0
SFRX(P3IM0, 0xFD23);

// SFR P4IM0: Port 4 interrupt mode register 0
SFRX(P4IM0, 0xFD24);

// SFR P5IM0: Port 5 interrupt mode register 0
SFRX(P5IM0, 0xFD25);

// SFR P6IM0: Port 6 interrupt mode register 0
SFRX(P6IM0, 0xFD26);

// SFR P7IM0: Port 7 interrupt mode register 0
SFRX(P7IM0, 0xFD27);

// SFR P0IM1: Port 0 interrupt mode register 1
SFRX(P0IM1, 0xFD30);

// SFR P1IM1: Port 1 interrupt mode register 1
SFRX(P1IM1, 0xFD31);

// SFR P2IM1: Port 2 interrupt mode register 1
SFRX(P2IM1, 0xFD32);

// SFR P3IM1: Port 3 interrupt mode register 1
SFRX(P3IM1, 0xFD33);

// SFR P4IM1: Port 4 interrupt mode register 1
SFRX(P4IM1, 0xFD34);

// SFR P5IM1: Port 5 interrupt mode register 1
SFRX(P5IM1, 0xFD35);

// SFR P6IM1: Port 6 interrupt mode register 1
SFRX(P6IM1, 0xFD36);

// SFR P7IM1: Port 7 interrupt mode register 1
SFRX(P7IM1, 0xFD37);

// SFR P0WKUE: Port 0 interrupt wake-up enable register
SFRX(P0WKUE, 0xFD40);

// SFR P1WKUE: Port 1 interrupt wake-up enable register
SFRX(P1WKUE, 0xFD41);

// SFR P2WKUE: Port 2 interrupt wake-up enable register
SFRX(P2WKUE, 0xFD42);

// SFR P3WKUE: Port 3 interrupt wake-up enable register
SFRX(P3WKUE, 0xFD43);

// SFR P4WKUE: Port 4 interrupt wake-up enable register
SFRX(P4WKUE, 0xFD44);

// SFR P5WKUE: Port 5 interrupt wake-up enable register
SFRX(P5WKUE, 0xFD45);

// SFR P6WKUE: Port 6 interrupt wake-up enable register
SFRX(P6WKUE, 0xFD46);

// SFR P7WKUE: Port 7 interrupt wake-up enable register
SFRX(P7WKUE, 0xFD47);

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

// SFR IRC48MCR: Internal 48MHz RC oscillator control register
SFRX(IRC48MCR, 0xFE07);
#define IRC48MST 0x1
#define ENIRC48M 0x80

// SFR SPFUNC: Special function fontrol register
SFRX(SPFUNC, 0xFE08);
#define BKSWR 0x1

// SFR RSTFLAG: Reset flag register
SFRX(RSTFLAG, 0xFE09);
#define EXRST 0x1
#define ROMOV 0x2
#define SWR 0x4

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

// SFR P6SR: Port 6 level transition rate register
SFRX(P6SR, 0xFE26);

// SFR P7SR: Port 7 level transition rate register
SFRX(P7SR, 0xFE27);

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

// SFR P6DR: Port 6 drive current control register
SFRX(P6DR, 0xFE2E);

// SFR P7DR: Port 7 drive current control register
SFRX(P7DR, 0xFE2F);

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

// SFR T3T4PIN: T3/T4 selection register
SFRX(T3T4PIN, 0xFEAC);
#define T3T4SEL 0x1

// SFR PWMA_ETRPS: PWMA ETR select register
SFRX(PWMA_ETRPS, 0xFEB0);
#define ETRAPS0 0x1
#define ETRAPS1 0x2
#define BRKAPS 0x4

// SFR PWMA_ENO: PWMA output enable control
SFRX(PWMA_ENO, 0xFEB1);
#define ENO1P 0x1
#define ENO1N 0x2
#define ENO2P 0x4
#define ENO2N 0x8
#define ENO3P 0x10
#define ENO3N 0x20
#define ENO4P 0x40
#define ENO4N 0x80

// SFR PWMA_PS: PWMA output pin selection register
SFRX(PWMA_PS, 0xFEB2);
#define C1PS0 0x1
#define C1PS1 0x2
#define C2PS0 0x4
#define C2PS1 0x8
#define C3PS0 0x10
#define C3PS1 0x20
#define C4PS0 0x40
#define C4PS1 0x80

// SFR PWMA_IOAUX: PWMA auxiliary register
SFRX(PWMA_IOAUX, 0xFEB3);
#define AUX1P 0x1
#define AUX1N 0x2
#define AUX2P 0x4
#define AUX2N 0x8
#define AUX3P 0x10
#define AUX3N 0x20
#define AUX4P 0x40
#define AUX4N 0x80

// SFR PWMB_ETRPS: PWMB ETR select register
SFRX(PWMB_ETRPS, 0xFEB4);
#define ETRBPS0 0x1
#define ETRBPS1 0x2
#define BRKBPS 0x4

// SFR PWMB_ENO: PWMB output enable control
SFRX(PWMB_ENO, 0xFEB5);
#define ENO5P 0x1
#define ENO6P 0x4
#define ENO7P 0x10
#define ENO8P 0x40

// SFR PWMB_PS: PWMB output pin selection register
SFRX(PWMB_PS, 0xFEB6);
#define C5PS0 0x1
#define C5PS1 0x2
#define C6PS0 0x4
#define C6PS1 0x8
#define C7PS0 0x10
#define C7PS1 0x20
#define C8PS0 0x40
#define C8PS1 0x80

// SFR PWMB_IOAUX: PWMB auxiliary register
SFRX(PWMB_IOAUX, 0xFEB7);
#define AUX5P 0x1
#define AUX6P 0x4
#define AUX7P 0x10
#define AUX8P 0x40

// SFR PWMA_CR1: PWMA control register 1
SFRX(PWMA_CR1, 0xFEC0);
#define CEN 0x1
#define UDIS 0x2
#define URS 0x4
#define OPM 0x8
#define DIR 0x10
#define CMS0 0x20
#define CMS1 0x40
#define ARPE 0x80

// SFR PWMA_CR2: PWMA control register 2
SFRX(PWMA_CR2, 0xFEC1);
#define CCPC 0x1
#define COMS 0x4
#define MMS0 0x10
#define MMS1 0x20
#define MMS2 0x40

// SFR PWMA_SMCR: PWMA slave mode control register
SFRX(PWMA_SMCR, 0xFEC2);
#define SMS0 0x1
#define SMS1 0x2
#define SMS2 0x4
#define TS0 0x10
#define TS1 0x20
#define TS2 0x40
#define MSM 0x80

// SFR PWMA_ETR: PWMA external trigger register
SFRX(PWMA_ETR, 0xFEC3);
#define ETF0 0x1
#define ETF1 0x2
#define ETF2 0x4
#define ETF3 0x8
#define ETPS0 0x10
#define ETPS1 0x20
#define ECE 0x40
#define ETP 0x80

// SFR PWMA_IER: PWMA interrupt enable register
SFRX(PWMA_IER, 0xFEC4);
#define UIE 0x1
#define CC1IE 0x2
#define CC2IE 0x4
#define CC3IE 0x8
#define CC4IE 0x10
#define COMIE 0x20
#define TIE 0x40
#define BIE 0x80

// SFR PWMA_SR1: PWMA status register 1
SFRX(PWMA_SR1, 0xFEC5);
#define UIF 0x1
#define CC1IF 0x2
#define CC2IF 0x4
#define CC3IF 0x8
#define CC4IF 0x10
#define COMIF 0x20
#define TIF 0x40
#define BIF 0x80

// SFR PWMA_SR2: PWMA status register 2
SFRX(PWMA_SR2, 0xFEC6);
#define CC1OF 0x2
#define CC2OF 0x4
#define CC3OF 0x8
#define CC4OF 0x10

// SFR PWMA_EGR: PWMA event register
SFRX(PWMA_EGR, 0xFEC7);
#define UG 0x1
#define CC1G 0x2
#define CC2G 0x4
#define CC3G 0x8
#define CC4G 0x10
#define COMG 0x20
#define TG 0x40
#define BG 0x80

// SFR PWMA_CCMR1: PWMA capture mode register 1
SFRX(PWMA_CCMR1, 0xFEC8);
#define CC1S0 0x1
#define CC1S1 0x2
#define OC1FE 0x4
#define OC1PE 0x8
#define OC1M0 0x10
#define OC1M1 0x20
#define OC1M2 0x40
#define OC1CE 0x80

// SFR PWMA_CCMR1: PWMA compare mode register 1
#define IC1PSC0 0x4
#define IC1PSC1 0x8
#define IC1F0 0x10
#define IC1F1 0x20
#define IC1F2 0x40
#define IC1F3 0x80

// SFR PWMA_CCMR2: PWMA capture mode register 2
SFRX(PWMA_CCMR2, 0xFEC9);
#define CC2S0 0x1
#define CC2S1 0x2
#define OC2FE 0x4
#define OC2PE 0x8
#define OC2M0 0x10
#define OC2M1 0x20
#define OC2M2 0x40
#define OC2CE 0x80

// SFR PWMA_CCMR2: PWMA compare mode register 2
#define IC2PSC0 0x4
#define IC2PSC1 0x8
#define IC2F0 0x10
#define IC2F1 0x20
#define IC2F2 0x40
#define IC2F3 0x80

// SFR PWMA_CCMR3: PWMA capture mode register 3
SFRX(PWMA_CCMR3, 0xFECA);
#define CC3S0 0x1
#define CC3S1 0x2
#define OC3FE 0x4
#define OC3PE 0x8
#define OC3M0 0x10
#define OC3M1 0x20
#define OC3M2 0x40
#define OC3CE 0x80

// SFR PWMA_CCMR3: PWMA compare mode register 3
#define IC3PSC0 0x4
#define IC3PSC1 0x8
#define IC3F0 0x10
#define IC3F1 0x20
#define IC3F2 0x40
#define IC3F3 0x80

// SFR PWMA_CCMR4: PWMA capture mode register 4
SFRX(PWMA_CCMR4, 0xFECB);
#define CC4S0 0x1
#define CC4S1 0x2
#define OC4FE 0x4
#define OC4PE 0x8
#define OC4M0 0x10
#define OC4M1 0x20
#define OC4M2 0x40
#define OC4CE 0x80

// SFR PWMA_CCMR4: PWMA compare mode register 4
#define IC4PSC0 0x4
#define IC4PSC1 0x8
#define IC4F0 0x10
#define IC4F1 0x20
#define IC4F2 0x40
#define IC4F3 0x80

// SFR PWMA_CCER1: PWMA capture compare enable register 1
SFRX(PWMA_CCER1, 0xFECC);
#define CC1E 0x1
#define CC1P 0x2
#define CC1NE 0x4
#define CC1NP 0x8
#define CC2E 0x10
#define CC2P 0x20
#define CC2NE 0x40
#define CC2NP 0x80

// SFR PWMA_CCER2: PWMA capture compare enable register 2
SFRX(PWMA_CCER2, 0xFECD);
#define CC3E 0x1
#define CC3P 0x2
#define CC3NE 0x4
#define CC3NP 0x8
#define CC4E 0x10
#define CC4P 0x20
#define CC4NE 0x40
#define CC4NP 0x80

// SFR PWMA_CNTRH: PWMA counter high byte
SFRX(PWMA_CNTRH, 0xFECE);

// SFR PWMA_CNTRL: PWMA counter low byte
SFRX(PWMA_CNTRL, 0xFECF);

// SFR PWMA_PSCRH: PWMA prescale high byte
SFRX(PWMA_PSCRH, 0xFED0);

// SFR PWMA_PSCRL: PWMA prescale low byte
SFRX(PWMA_PSCRL, 0xFED1);

// SFR PWMA_ARRH: PWMA auto-reload register high byte
SFRX(PWMA_ARRH, 0xFED2);

// SFR PWMA_ARRL: PWMA auto-reload register low byte
SFRX(PWMA_ARRL, 0xFED3);

// SFR PWMA_RCR: PWMA repeat counter register
SFRX(PWMA_RCR, 0xFED4);

// SFR PWMA_CCR1H: PWMA compare capture register 1 high byte
SFRX(PWMA_CCR1H, 0xFED5);

// SFR PWMA_CCR1L: PWMA compare capture register 1 low byte
SFRX(PWMA_CCR1L, 0xFED6);

// SFR PWMA_CCR2H: PWMA compare capture register 2 high byte
SFRX(PWMA_CCR2H, 0xFED7);

// SFR PWMA_CCR2L: PWMA compare capture register 2 low byte
SFRX(PWMA_CCR2L, 0xFED8);

// SFR PWMA_CCR3H: PWMA compare capture register 3 high byte
SFRX(PWMA_CCR3H, 0xFED9);

// SFR PWMA_CCR3L: PWMA compare capture register 3 low byte
SFRX(PWMA_CCR3L, 0xFEDA);

// SFR PWMA_CCR4H: PWMA compare capture register 4 high byte
SFRX(PWMA_CCR4H, 0xFEDB);

// SFR PWMA_CCR4L: PWMA compare capture register 4 low byte
SFRX(PWMA_CCR4L, 0xFEDC);

// SFR PWMA_BKR: PWMA brake register
SFRX(PWMA_BKR, 0xFEDD);
#define LOCK0 0x1
#define LOCK1 0x2
#define OSSI 0x4
#define OSSR 0x8
#define BKE 0x10
#define BKP 0x20
#define AOE 0x40
#define MOE 0x80

// SFR PWMA_DTR: PWMA dead time control register
SFRX(PWMA_DTR, 0xFEDE);

// SFR PWMA_OISR: PWMA output idle status register
SFRX(PWMA_OISR, 0xFEDF);
#define OIS1 0x1
#define OIS1N 0x2
#define OIS2 0x4
#define OIS2N 0x8
#define OIS3 0x10
#define OIS3N 0x20
#define OIS4 0x40
#define OIS4N 0x80

// SFR PWMB_CR1: PWMB control register 1
SFRX(PWMB_CR1, 0xFEE0);

// SFR PWMB_CR2: PWMB control register 2
SFRX(PWMB_CR2, 0xFEE1);

// SFR PWMB_SMCR: PWMB slave mode control register
SFRX(PWMB_SMCR, 0xFEE2);

// SFR PWMB_ETR: PWMB external trigger register
SFRX(PWMB_ETR, 0xFEE3);

// SFR PWMB_IER: PWMB interrupt enable register
SFRX(PWMB_IER, 0xFEE4);
#define CC5IE 0x2
#define CC6IE 0x4
#define CC7IE 0x8
#define CC8IE 0x10

// SFR PWMB_SR1: PWMB status register 1
SFRX(PWMB_SR1, 0xFEE5);
#define CC5IF 0x2
#define CC6IF 0x4
#define CC7IF 0x8
#define CC8IF 0x10

// SFR PWMB_SR2: PWMB status register 2
SFRX(PWMB_SR2, 0xFEE6);
#define CC5OF 0x2
#define CC6OF 0x4
#define CC7OF 0x8
#define CC8OF 0x10

// SFR PWMB_EGR: PWMB event register
SFRX(PWMB_EGR, 0xFEE7);
#define CC5G 0x2
#define CC6G 0x4
#define CC7G 0x8
#define CC8G 0x10

// SFR PWMB_CCMR1: PWMB capture mode register 1
SFRX(PWMB_CCMR1, 0xFEE8);
#define CC5S0 0x1
#define CC5S1 0x2
#define OC5FE 0x4
#define OC5PE 0x8
#define OC5M0 0x10
#define OC5M1 0x20
#define OC5M2 0x40
#define OC5CE 0x80

// SFR PWMB_CCMR1: PWMB compare mode register 1
#define IC5PSC0 0x4
#define IC5PSC1 0x8
#define IC5F0 0x10
#define IC5F1 0x20
#define IC5F2 0x40
#define IC5F3 0x80

// SFR PWMB_CCMR2: PWMB capture mode register 2
SFRX(PWMB_CCMR2, 0xFEE9);
#define CC6S0 0x1
#define CC6S1 0x2
#define OC6FE 0x4
#define OC6PE 0x8
#define OC6M0 0x10
#define OC6M1 0x20
#define OC6M2 0x40
#define OC6CE 0x80

// SFR PWMB_CCMR2: PWMB compare mode register 2
#define IC6PSC0 0x4
#define IC6PSC1 0x8
#define IC6F0 0x10
#define IC6F1 0x20
#define IC6F2 0x40
#define IC6F3 0x80

// SFR PWMB_CCMR3: PWMB capture mode register 3
SFRX(PWMB_CCMR3, 0xFEEA);
#define CC7S0 0x1
#define CC7S1 0x2
#define OC7FE 0x4
#define OC7PE 0x8
#define OC7M0 0x10
#define OC7M1 0x20
#define OC7M2 0x40
#define OC7CE 0x80

// SFR PWMB_CCMR3: PWMB compare mode register 3
#define IC7PSC0 0x4
#define IC7PSC1 0x8
#define IC7F0 0x10
#define IC7F1 0x20
#define IC7F2 0x40
#define IC7F3 0x80

// SFR PWMB_CCMR4: PWMB capture mode register 4
SFRX(PWMB_CCMR4, 0xFEEB);
#define CC8S0 0x1
#define CC8S1 0x2
#define OC8FE 0x4
#define OC8PE 0x8
#define OC8M0 0x10
#define OC8M1 0x20
#define OC8M2 0x40
#define OC8CE 0x80

// SFR PWMB_CCMR4: PWMB compare mode register 4
#define IC8PSC0 0x4
#define IC8PSC1 0x8
#define IC8F0 0x10
#define IC8F1 0x20
#define IC8F2 0x40
#define IC8F3 0x80

// SFR PWMB_CCER1: PWMB capture compare enable register 1
SFRX(PWMB_CCER1, 0xFEEC);
#define CC5E 0x1
#define CC5P 0x2
#define CC5NE 0x4
#define CC5NP 0x8
#define CC6E 0x10
#define CC6P 0x20
#define CC6NE 0x40
#define CC6NP 0x80

// SFR PWMB_CCER2: PWMB capture compare enable register 2
SFRX(PWMB_CCER2, 0xFEED);
#define CC7E 0x1
#define CC7P 0x2
#define CC7NE 0x4
#define CC7NP 0x8
#define CC8E 0x10
#define CC8P 0x20
#define CC8NE 0x40
#define CC8NP 0x80

// SFR PWMB_CNTRH: PWMB counter high byte
SFRX(PWMB_CNTRH, 0xFEEE);

// SFR PWMB_CNTRL: PWMB counter low byte
SFRX(PWMB_CNTRL, 0xFEEF);

// SFR PWMB_PSCRH: PWMB prescale high byte
SFRX(PWMB_PSCRH, 0xFEF0);

// SFR PWMB_PSCRL: PWMB prescale low byte
SFRX(PWMB_PSCRL, 0xFEF1);

// SFR PWMB_ARRH: PWMB auto-reload register high byte
SFRX(PWMB_ARRH, 0xFEF2);

// SFR PWMB_ARRL: PWMB auto-reload register low byte
SFRX(PWMB_ARRL, 0xFEF3);

// SFR PWMB_RCR: PWMB repeat counter register
SFRX(PWMB_RCR, 0xFEF4);

// SFR PWMB_CCR1H: PWMB compare capture register 1 high byte
SFRX(PWMB_CCR1H, 0xFEF5);

// SFR PWMB_CCR1L: PWMB compare capture register 1 low byte
SFRX(PWMB_CCR1L, 0xFEF6);

// SFR PWMB_CCR2H: PWMB compare capture register 2 high byte
SFRX(PWMB_CCR2H, 0xFEF7);

// SFR PWMB_CCR2L: PWMB compare capture register 2 low byte
SFRX(PWMB_CCR2L, 0xFEF8);

// SFR PWMB_CCR3H: PWMB compare capture register 3 high byte
SFRX(PWMB_CCR3H, 0xFEF9);

// SFR PWMB_CCR3L: PWMB compare capture register 3 low byte
SFRX(PWMB_CCR3L, 0xFEFA);

// SFR PWMB_CCR4H: PWMB compare capture register 4 high byte
SFRX(PWMB_CCR4H, 0xFEFB);

// SFR PWMB_CCR4L: PWMB compare capture register 4 low byte
SFRX(PWMB_CCR4L, 0xFEFC);

// SFR PWMB_BKR: PWMB brake register
SFRX(PWMB_BKR, 0xFEFD);

// SFR PWMB_DTR: PWMB dead time control register
SFRX(PWMB_DTR, 0xFEFE);

// SFR PWMB_OISR: PWMB output idle status register
SFRX(PWMB_OISR, 0xFEFF);
#define OIS5 0x1
#define OIS6 0x4
#define OIS7 0x10
#define OIS8 0x40
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
// I2C interrupt
#define I2C_INTERRUPT 24
#define I2C_VECTOR_ADDR 0xC3
// USB interrupt
#define USB_INTERRUPT 25
#define USB_VECTOR_ADDR 0xCB
// PWM A interrupt
#define PWMA_INTERRUPT 26
#define PWMA_VECTOR_ADDR 0xD3
// PWM B interrupt
#define PWMB_INTERRUPT 27
#define PWMB_VECTOR_ADDR 0xDB
// Touch key interrupt (usage in C => see STC8H TRM appendix R)
#define TKSU_INTERRUPT 35_SEE_APPENDIX_R
#define TKSU_VECTOR_ADDR 0x11B
// RTC interrupt (usage in C => see STC8H TRM appendix R)
#define RTC_INTERRUPT 36_SEE_APPENDIX_R
#define RTC_VECTOR_ADDR 0x123
// GPIO port 0 interrupt (usage in C => see STC8H TRM appendix R)
#define P0_INTERRUPT 37_SEE_APPENDIX_R
#define P0_VECTOR_ADDR 0x12B
// GPIO port 1 interrupt (usage in C => see STC8H TRM appendix R)
#define P1_INTERRUPT 38_SEE_APPENDIX_R
#define P1_VECTOR_ADDR 0x133
// GPIO port 2 interrupt (usage in C => see STC8H TRM appendix R)
#define P2_INTERRUPT 39_SEE_APPENDIX_R
#define P2_VECTOR_ADDR 0x13B
// GPIO port 3 interrupt (usage in C => see STC8H TRM appendix R)
#define P3_INTERRUPT 40_SEE_APPENDIX_R
#define P3_VECTOR_ADDR 0x143
// GPIO port 4 interrupt (usage in C => see STC8H TRM appendix R)
#define P4_INTERRUPT 41_SEE_APPENDIX_R
#define P4_VECTOR_ADDR 0x14B
// GPIO port 5 interrupt (usage in C => see STC8H TRM appendix R)
#define P5_INTERRUPT 42_SEE_APPENDIX_R
#define P5_VECTOR_ADDR 0x153
// GPIO port 6 interrupt (usage in C => see STC8H TRM appendix R)
#define P6_INTERRUPT 43_SEE_APPENDIX_R
#define P6_VECTOR_ADDR 0x15B
// GPIO port 7 interrupt (usage in C => see STC8H TRM appendix R)
#define P7_INTERRUPT 44_SEE_APPENDIX_R
#define P7_VECTOR_ADDR 0x163
// DMA M2M interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_M2M_INTERRUPT 47_SEE_APPENDIX_R
#define DMA_M2M_VECTOR_ADDR 0x17B
// DMA ADC interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_ADC_INTERRUPT 48_SEE_APPENDIX_R
#define DMA_ADC_VECTOR_ADDR 0x183
// DMA SPI interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_SPI_INTERRUPT 49_SEE_APPENDIX_R
#define DMA_SPI_VECTOR_ADDR 0x18B
// DMA UART1 transmit interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR1T_INTERRUPT 50_SEE_APPENDIX_R
#define DMA_UR1T_VECTOR_ADDR 0x193
// DMA UART1 receive interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR1R_INTERRUPT 51_SEE_APPENDIX_R
#define DMA_UR1R_VECTOR_ADDR 0x19B
// DMA UART2 transmit interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR2T_INTERRUPT 52_SEE_APPENDIX_R
#define DMA_UR2T_VECTOR_ADDR 0x1A3
// DMA UART2 receive interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR2R_INTERRUPT 53_SEE_APPENDIX_R
#define DMA_UR2R_VECTOR_ADDR 0x1AB
// DMA UART3 transmit interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR3T_INTERRUPT 54_SEE_APPENDIX_R
#define DMA_UR3T_VECTOR_ADDR 0x1B3
// DMA UART3 receive interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR3R_INTERRUPT 55_SEE_APPENDIX_R
#define DMA_UR3R_VECTOR_ADDR 0x1BB
// DMA UART4 transmit interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR4T_INTERRUPT 56_SEE_APPENDIX_R
#define DMA_UR4T_VECTOR_ADDR 0x1C3
// DMA UART4 receive interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_UR4R_INTERRUPT 57_SEE_APPENDIX_R
#define DMA_UR4R_VECTOR_ADDR 0x1CB
// DMA LCM interrupt (usage in C => see STC8H TRM appendix R)
#define DMA_LCM_INTERRUPT 58_SEE_APPENDIX_R
#define DMA_LCM_VECTOR_ADDR 0x1D3
// LCD module interface interrupt (usage in C => see STC8H TRM appendix R)
#define LCM_INTERRUPT 59_SEE_APPENDIX_R
#define LCM_VECTOR_ADDR 0x1DB

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

#endif // _STC8H_H
