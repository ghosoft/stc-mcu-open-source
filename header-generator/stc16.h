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
 * @file stc16.h
 * 
 * Register, bit and macro definitions for the STC16
 */

#ifndef _STC16_H
#define _STC16_H

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

// SFR DPXL: Data pointer (highest byte)
SFR(DPXL, 0x84);

// SFR USBCLK: USB clock control register
SFR(USBCLK, 0x85);
#define PHYTST0 0x1
#define PHYTST1 0x2
#define TST_PHY 0x4
#define TST_USB 0x8
#define CRE 0x10
#define PCKI0 0x20
#define PCKI1 0x40
#define ENCKM 0x80

// SFR DPS: DPTR pointer selector
SFR(DPS, 0x86);
#define DPSEL 0x1
#define AU0 0x8
#define AU1 0x10
#define TSL 0x20
#define ID0 0x40
#define ID1 0x80

// SFR PCON: Power control register
SFR(PCON, 0x87);
#define IDL 0x1
#define PD 0x2
#define GF0 0x4
#define GF1 0x8
#define POF 0x10
#define LVDF 0x20
#define SMOD0 0x40
#define SMOD 0x80

// SFR TCON: Timer control register
SFR(TCON, 0x88);
SBIT(IT0, 0x88, 0);
SBIT(IE0, 0x88, 1);
SBIT(IT1, 0x88, 2);
SBIT(IE1, 0x88, 3);
SBIT(TR0, 0x88, 4);
SBIT(TF0, 0x88, 5);
SBIT(TR1, 0x88, 6);
SBIT(TF1, 0x88, 7);

// SFR TMOD: Timer mode register
SFR(TMOD, 0x89);
#define T0_M0 0x1
#define T0_M1 0x2
#define T0_C_T 0x4
#define T0_GATE 0x8
#define T1_M0 0x10
#define T1_M1 0x20
#define T1_C_T 0x40
#define T1_GATE 0x80

// SFR TL0: Timer 0 low byte
SFR(TL0, 0x8A);

// SFR TL1: Timer 1 low byte
SFR(TL1, 0x8B);

// SFR TH0: Timer 0 high byte
SFR(TH0, 0x8C);

// SFR TH1: Timer 1 high byte
SFR(TH1, 0x8D);

// SFR CKCON: XRAM control register
SFR(CKCON, 0x8E);
#define CKCON0 0x1
#define CKCON1 0x2
#define CKCON2 0x4
#define T0M 0x8
#define T1M 0x10

// SFR DMAIR: FMU DMA instruction register
SFR(DMAIR, 0x8F);

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

// SFR USBCON: USB control register
SFR(USBCON, 0x91);
#define DM 0x1
#define DP 0x2
#define DFREC 0x4
#define PDEN 0x8
#define PUEN 0x10
#define PS2M 0x20
#define USBRST 0x40
#define ENUSB 0x80

// SFR WTST: Program read control register
SFR(WTST, 0x92);

// SFR AUXR1: Auxiliary register 1
SFR(AUXR1, 0x93);
#define SIST2 0x1
#define EXTRAM 0x2
#define T2x12 0x4
#define T2_C_T 0x8
#define T2R 0x10
#define UART_M0x6 0x20
#define T1x12 0x40
#define T0x12 0x80

// SFR AUXR2: Auxiliary register 2
SFR(AUXR2, 0x94);
#define LINEN 0x1
#define CANEN 0x2
#define TXLNRX 0x10
#define ADIBF 0x20
#define P40ADR 0x40

// SFR INTCLKO: 
SFR(INTCLKO, 0x95);
#define T0CLKO 0x1
#define T1CLKO 0x2
#define T2CLKO 0x4
#define EX2 0x10
#define EX3 0x20
#define EX4 0x40

// SFR USBADR: USB address register
SFR(USBADR, 0x96);
#define UADR0 0x1
#define UADR1 0x2
#define UADR2 0x4
#define UADR3 0x8
#define UADR4 0x10
#define UADR5 0x20
#define AUTORD 0x40
#define BUSY 0x80

// SFR USBDAT: USB data register
SFR(USBDAT, 0x97);

// SFR SCON: Serial port 1 control register
SFR(SCON, 0x98);
SBIT(RI, 0x98, 0);
SBIT(TI, 0x98, 1);
SBIT(RB8, 0x98, 2);
SBIT(TB8, 0x98, 3);
SBIT(REN, 0x98, 4);
SBIT(SM2, 0x98, 5);
SBIT(SM1, 0x98, 6);
SBIT(SM0_FE, 0x98, 7);

// SFR SBUF: Serial port 1 buffer register
SFR(SBUF, 0x99);

// SFR P_SW1: Peripheral port switching register 1
SFR(P_SW1, 0x9A);
#define LIN_S0 0x1
#define LIN_S1 0x2
#define SPI_S0 0x4
#define SPI_S1 0x8
#define CAN_S0 0x10
#define CAN_S1 0x20
#define S1_S0 0x40
#define S1_S1 0x80

// SFR P_SW2: Peripheral port switching register 2
SFR(P_SW2, 0x9B);
#define S2_S 0x1
#define S3_S 0x2
#define S4_S 0x4
#define CMPO_S 0x8
#define I2C_S0 0x10
#define I2C_S1 0x20
#define EAXFR 0x80

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

// SFR CANICR: CANBUS interrupt control register
SFR(CANICR, 0xA1);
#define PCANL 0x1
#define ECAN 0x2
#define CANIF 0x4
#define PCANH 0x8

// SFR CANAR: CANBUS address register
SFR(CANAR, 0xA2);

// SFR CANDR: CANBUS data register
SFR(CANDR, 0xA3);

// SFR IE: Interrupt enable register
SFR(IE, 0xA8);
SBIT(EX0, 0xA8, 0);
SBIT(ET0, 0xA8, 1);
SBIT(EX1, 0xA8, 2);
SBIT(ET1, 0xA8, 3);
SBIT(ES, 0xA8, 4);
SBIT(EADC, 0xA8, 5);
SBIT(ELVD, 0xA8, 6);
SBIT(EA, 0xA8, 7);

// SFR IRCBAND: IRC band selection detection
SFR(IRCBAND, 0xA9);
#define BANDSEL 0x1

// SFR WKTCL: Power-down wake-up timer low byte
SFR(WKTCL, 0xAA);

// SFR WKTCH: Power-down wake-up timer high byte
SFR(WKTCH, 0xAB);
#define WKTEN 0x80

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

// SFR LINICR: LINBUS interrupt control register
SFR(LINICR, 0xB1);
#define PLINL 0x1
#define ELIN 0x2
#define LINIF 0x4
#define PLINH 0x8

// SFR LINAR: LINBUS address register
SFR(LINAR, 0xB2);

// SFR LINDR: LINBUS data register
SFR(LINDR, 0xB3);

// SFR CMPCR1: Comparator control register 1
SFR(CMPCR1, 0xB4);
#define CMPRES 0x1
#define CMPOE 0x2
#define NIS 0x4
#define PIS 0x8
#define NIE 0x10
#define PIE 0x20
#define CMPIF 0x40
#define CMPEN 0x80

// SFR CMPCR2: Comparator control register 2
SFR(CMPCR2, 0xB5);
#define LCDTY0 0x1
#define LCDTY1 0x2
#define LCDTY2 0x4
#define LCDTY3 0x8
#define LCDTY4 0x10
#define LCDTY5 0x20
#define DISFLT 0x40
#define INVCMPO 0x80

// SFR IP2H: Interrupt priority control register 2 high
SFR(IP2H, 0xB6);
#define PS2H 0x1
#define PSPIH 0x2
#define PUSBH 0x4
#define PPWMB 0x8
#define PX4H 0x10
#define PCMPH 0x20
#define PI2CH 0x40

// SFR IPH: Interrupt priority control register high
SFR(IPH, 0xB7);
#define PX0H 0x1
#define PT0H 0x2
#define PX1H 0x4
#define PT1H 0x8
#define PSH 0x10
#define PADCH 0x20
#define PLVDH 0x40
#define PPWMAH 0x80

// SFR IP: Interrupt priority control register low
SFR(IP, 0xB8);
SBIT(PX0, 0xB8, 0);
SBIT(PT0, 0xB8, 1);
SBIT(PX1, 0xB8, 2);
SBIT(PT1, 0xB8, 3);
SBIT(PS, 0xB8, 4);
SBIT(PADC, 0xB8, 5);
SBIT(PLVD, 0xB8, 6);
SBIT(PPWMA, 0xB8, 7);

// SFR SPSTAT: SPI status register
SFR(SPSTAT, 0xB9);
#define WCOL 0x40
#define SPIF 0x80

// SFR SPCTL: SPI control register
SFR(SPCTL, 0xBA);
#define SPR0 0x1
#define SPR1 0x2
#define CPHA 0x4
#define CPOL 0x8
#define MSTR 0x10
#define DORD 0x20
#define SPEN 0x40
#define SSIG 0x80

// SFR SPDAT: SPI data register
SFR(SPDAT, 0xBB);

// SFR S4CON: Serial port 4 control register
SFR(S4CON, 0xBC);
#define S4RI 0x1
#define S4TI 0x2
#define S4RB8 0x4
#define S4TB8 0x8
#define S4REN 0x10
#define S4SM2 0x20
#define S4ST4 0x40
#define S4SM0 0x80

// SFR S4BUF: Serial port 4 buffer register
SFR(S4BUF, 0xBD);

// SFR SPH: Stack pointer high byte
SFR(SPH, 0xBE);

// SFR BUS_SPEED: Bus speed control register
SFR(BUS_SPEED, 0xBF);
#define SPEED0 0x1
#define SPEED1 0x2
#define SPEED2 0x4
#define RW_S0 0x40
#define RW_S1 0x80

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

// SFR : 
SFR(, 0xC1);

// SFR IAP_DATA: IAP data register
SFR(IAP_DATA, 0xC2);

// SFR IAP_ADDRH: IAP address register high
SFR(IAP_ADDRH, 0xC3);

// SFR IAP_ADDRL: IAP address register low
SFR(IAP_ADDRL, 0xC4);

// SFR IAP_CMD: IAP command register
SFR(IAP_CMD, 0xC5);
#define CMD0 0x1
#define CMD1 0x2

// SFR IAP_TRIG: IAP trigger register
SFR(IAP_TRIG, 0xC6);

// SFR IAP_CONTR: IAP control register
SFR(IAP_CONTR, 0xC7);
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

// SFR T4H: Timer 4 high byte
SFR(T4H, 0xC9);

// SFR T4L: Timer 4 low byte
SFR(T4L, 0xCA);

// SFR T3H: Timer 3 high byte
SFR(T3H, 0xCB);

// SFR T3L: Timer 3 low byte
SFR(T3L, 0xCC);

// SFR T2H: Timer 2 high byte
SFR(T2H, 0xCD);

// SFR T2L: Timer 2 low byte
SFR(T2L, 0xCE);

// SFR PSW: Program status word register
SFR(PSW, 0xD0);
SBIT(P, 0xD0, 0);
SBIT(OV, 0xD0, 2);
SBIT(RS0, 0xD0, 3);
SBIT(RS1, 0xD0, 4);
SBIT(F0, 0xD0, 5);
SBIT(AC, 0xD0, 6);
SBIT(CY, 0xD0, 7);

// SFR PSW1: Program status word 1 register
SFR(PSW1, 0xD1);
#define Z 0x2
#define OV 0x4
#define RS0 0x8
#define RS1 0x10
#define N 0x20
#define AC 0x40
#define CY 0x80

// SFR P7M1: P7 port configuration register 1
SFR(P7M1, 0xD2);

// SFR P7M0: P7 port configuration register 0
SFR(P7M0, 0xD3);

// SFR AUXINTF: Extended external interrupt flag register
SFR(AUXINTF, 0xDA);
#define T2IF 0x1
#define T3IF 0x2
#define T4IF 0x4
#define INT2IF 0x10
#define INT3IF 0x20
#define INT4IF 0x40

// SFR T4T3M: Timer 4/3 control register
SFR(T4T3M, 0xDB);
#define T3CLKO 0x1
#define T3x12 0x2
#define T3_C_T 0x4
#define T3R 0x8
#define T4CLKO 0x10
#define T4x12 0x20
#define T4_C_T 0x40
#define T4R 0x80

// SFR ADC_CONTR: ADC control register
SFR(ADC_CONTR, 0xDC);
#define ADC_CHS0 0x1
#define ADC_CHS1 0x2
#define ADC_CHS2 0x4
#define ADC_CHS3 0x8
#define ADC_FLAG 0x20
#define ADC_START 0x40
#define ADC_POWER 0x80

// SFR ADC_RES: ADC conversion result register high
SFR(ADC_RES, 0xDD);

// SFR ADC_RESL: ADC conversion result register low
SFR(ADC_RESL, 0xDE);

// SFR ADCCFG: ADC configuration register
SFR(ADCCFG, 0xDF);
#define ADC_SPEED0 0x1
#define ADC_SPEED1 0x2
#define ADC_SPEED2 0x4
#define ADC_SPEED3 0x8
#define RESFMT 0x20

// SFR ACC: Accumulator
SFR(ACC, 0xE0);

// SFR SADDR: Serial port 1 slave address register
SFR(SADDR, 0xE1);

// SFR SADEN: Serial port 1 slave address mask register
SFR(SADEN, 0xE2);

// SFR S2CON: Serial port 2 control register
SFR(S2CON, 0xE3);
#define S2RI 0x1
#define S2TI 0x2
#define S2RB8 0x4
#define S2TB8 0x8
#define S2REN 0x10
#define S2SM2 0x20
#define S2SM0 0x80

// SFR S2BUF: Serial port 2 buffer register
SFR(S2BUF, 0xE4);

// SFR S3CON: Serial port 3 control register
SFR(S3CON, 0xE5);
#define S3RI 0x1
#define S3TI 0x2
#define S3RB8 0x4
#define S3TB8 0x8
#define S3REN 0x10
#define S3SM2 0x20
#define S3ST4 0x40
#define S3SM0 0x80

// SFR S3BUF: Serial port 3 buffer register
SFR(S3BUF, 0xE6);

// SFR IE2: Interrupt enable register 2
SFR(IE2, 0xE7);
#define ES2 0x1
#define ESPI 0x2
#define ET2 0x4
#define ES3 0x8
#define ES4 0x10
#define ET3 0x20
#define ET4 0x40

// SFR P6: Port 6
SFR(P6, 0xE8);

// SFR MXAX: MOVX extended address register
SFR(MXAX, 0xEA);

// SFR TA: DPTR timing control register
SFR(TA, 0xEB);

// SFR P5M1: P5 port configuration register 1
SFR(P5M1, 0xEC);

// SFR P5M0: P5 port configuration register 0
SFR(P5M0, 0xED);

// SFR P6M1: P6 port configuration register 1
SFR(P6M1, 0xEE);

// SFR P6M0: P6 port configuration register 0
SFR(P6M0, 0xEF);

// SFR B: B register
SFR(B, 0xF0);

// SFR P0M1: P0 port configuration register 1
SFR(P0M1, 0xF1);

// SFR P0M0: P0 port configuration register 0
SFR(P0M0, 0xF2);

// SFR P1M1: P1 port configuration register 1
SFR(P1M1, 0xF3);

// SFR P1M0: P1 port configuration register 0
SFR(P1M0, 0xF4);

// SFR P2M1: P2 port configuration register 1
SFR(P2M1, 0xF5);

// SFR P2M0: P2 port configuration register 0
SFR(P2M0, 0xF6);

// SFR IAP_TPS: IAP latency control register
SFR(IAP_TPS, 0xF7);
#define IAPTPS0 0x1
#define IAPTPS1 0x2
#define IAPTPS2 0x4
#define IAPTPS3 0x8
#define IAPTPS4 0x10
#define IAPTPS5 0x20

// SFR P7: Port 7
SFR(P7, 0xF8);

// SFR P3M1: P3 port configuration register 1
SFR(P3M1, 0xF9);

// SFR P3M0: P3 port configuration register 0
SFR(P3M0, 0xFA);

// SFR P4M1: P4 port configuration register 1
SFR(P4M1, 0xFB);

// SFR P4M0: P4 port configuration register 0
SFR(P4M0, 0xFC);

// SFR WDT_CONTR: Watchdog control register
SFR(WDT_CONTR, 0xFD);
#define WDT_PS0 0x1
#define WDT_PS1 0x2
#define WDT_PS2 0x4
#define IDL_WDT 0x8
#define CLR_WDT 0x10
#define EN_WDT 0x20
#define WDT_FLAG 0x80

// SFR IP2: Interrupt priority control register 2 low
SFR(IP2, 0xFE);
#define PS2 0x1
#define PSPI 0x2
#define PPWMA 0x4
#define PX4 0x10
#define PI2C 0x40

// SFR RSTCFG: Reset configuration register
SFR(RSTCFG, 0xFF);
#define LVDS0 0x1
#define LVDS1 0x2
#define P54RST 0x10
#define ENLVR 0x40

// SFR MD3: MDU data register
SFRX(MD3, 0x7EFCF0);

// SFR MD2: MDU data register
SFRX(MD2, 0x7EFCF1);

// SFR MD1: MDU data register
SFRX(MD1, 0x7EFCF2);

// SFR MD0: MDU data register
SFRX(MD0, 0x7EFCF3);

// SFR MD5: MDU data register
SFRX(MD5, 0x7EFCF4);

// SFR MD4: MDU data register
SFRX(MD4, 0x7EFCF5);

// SFR ARCON: MDU mode control register
SFRX(ARCON, 0x7EFCF6);
#define SC0 0x1
#define SC1 0x2
#define SC2 0x4
#define SC3 0x8
#define SC4 0x10
#define MODE0 0x20
#define MODE1 0x40
#define MODE2 0x80

// SFR OPCON: MDU operation control register
SFRX(OPCON, 0x7EFCF7);
#define ENOP 0x1
#define RST 0x2
#define MDOV 0x40

// SFR CKSEL: Clock selection register
SFRX(CKSEL, 0x7EFE00);
#define MCKSEL0 0x1
#define MCKSEL1 0x2

// SFR CLKDIV: Clock divider register
SFRX(CLKDIV, 0x7EFE01);

// SFR IRC24MCR: Internal 24MHz RC oscillator control register
SFRX(IRC24MCR, 0x7EFE02);
#define IRC24MST 0x1
#define ENIRC24M 0x80

// SFR XOSCCR: External crystal oscillator control register
SFRX(XOSCCR, 0x7EFE03);
#define XOSCST 0x1
#define XITYPE 0x40
#define ENXOSC 0x80

// SFR IRC32KCR: Internal 32kHz RC oscillator control register
SFRX(IRC32KCR, 0x7EFE04);
#define IRC32KST 0x1
#define ENIRC32K 0x80

// SFR PLLCR: PLL control register
SFRX(PLLCR, 0x7EFE05);
#define PLLST 0x1
#define PLLTOMSEL0 0x2
#define PLLTOMSEL1 0x4
#define PLLINCTL0 0x8
#define PLLINCTL1 0x10
#define PLLSSEL0 0x20
#define PLLSSEL1 0x40
#define ENPLL 0x80

// SFR USBCON1: USB control register 1
SFRX(USBCON1, 0x7EFE06);
#define TRIMLDO330 0x2
#define TRIMLDO331 0x4
#define TRIMLDO332 0x8
#define TRIMLDO333 0x10
#define TRIMPLL0 0x20
#define TRIMPLL1 0x40
#define ENLDO33 0x80

// SFR MCLKOCR: Master clock output control register
SFRX(MCLKOCR, 0x7EFE07);
#define MCLKODIV0 0x1
#define MCLKODIV1 0x2
#define MCLKODIV2 0x4
#define MCLKODIV3 0x8
#define MCLKODIV4 0x10
#define MCLKODIV5 0x20
#define MCLKODIV6 0x40
#define MCLKO_S 0x80

// SFR IRC48MCR: Internal 48MHz RC oscillator control register
SFRX(IRC48MCR, 0x7EFE08);
#define IRC48MST 0x1
#define ENIRC48M 0x80

// SFR IRC48ATRIM: Internal 48MHz RC oscillator TRIM register A
SFRX(IRC48ATRIM, 0x7EFE09);
#define ATRIM0 0x1
#define ATRIM1 0x2
#define ATRIM2 0x4
#define ATRIM3 0x8
#define ATRIM4 0x10

// SFR IRC48BTRIM: Internal 48MHz RC oscillator TRIM register B
SFRX(IRC48BTRIM, 0x7EFE0A);

// SFR IRCDB: Internal high-speed oscillator debounce control
SFRX(IRCDB, 0x7EFE0B);

// SFR P0PU: Port 0 pull-up resistor control register
SFRX(P0PU, 0x7EFE10);

// SFR P1PU: Port 1 pull-up resistor control register
SFRX(P1PU, 0x7EFE11);

// SFR P2PU: Port 2 pull-up resistor control register
SFRX(P2PU, 0x7EFE12);

// SFR P3PU: Port 3 pull-up resistor control register
SFRX(P3PU, 0x7EFE13);

// SFR P4PU: Port 4 pull-up resistor control register
SFRX(P4PU, 0x7EFE14);

// SFR P5PU: Port 5 pull-up resistor control register
SFRX(P5PU, 0x7EFE15);

// SFR P6PU: Port 6 pull-up resistor control register
SFRX(P6PU, 0x7EFE16);

// SFR P7PU: Port 7 pull-up resistor control register
SFRX(P7PU, 0x7EFE17);

// SFR P0NCS: Port 0 Schmidt trigger control register
SFRX(P0NCS, 0x7EFE18);

// SFR P1NCS: Port 1 Schmidt trigger control register
SFRX(P1NCS, 0x7EFE19);

// SFR P2NCS: Port 2 Schmidt trigger control register
SFRX(P2NCS, 0x7EFE1A);

// SFR P3NCS: Port 3 Schmidt trigger control register
SFRX(P3NCS, 0x7EFE1B);

// SFR P4NCS: Port 4 Schmidt trigger control register
SFRX(P4NCS, 0x7EFE1C);

// SFR P5NCS: Port 5 Schmidt trigger control register
SFRX(P5NCS, 0x7EFE1D);

// SFR P6NCS: Port 6 Schmidt trigger control register
SFRX(P6NCS, 0x7EFE1E);

// SFR P7NCS: Port 7 Schmidt trigger control register
SFRX(P7NCS, 0x7EFE1F);

// SFR P0SR: Port 0 level transition rate register
SFRX(P0SR, 0x7EFE20);

// SFR P1SR: Port 1 level transition rate register
SFRX(P1SR, 0x7EFE21);

// SFR P2SR: Port 2 level transition rate register
SFRX(P2SR, 0x7EFE22);

// SFR P3SR: Port 3 level transition rate register
SFRX(P3SR, 0x7EFE23);

// SFR P4SR: Port 4 level transition rate register
SFRX(P4SR, 0x7EFE24);

// SFR P5SR: Port 5 level transition rate register
SFRX(P5SR, 0x7EFE25);

// SFR P6SR: Port 6 level transition rate register
SFRX(P6SR, 0x7EFE26);

// SFR P7SR: Port 7 level transition rate register
SFRX(P7SR, 0x7EFE27);

// SFR P0DR: Port 0 drive current control register
SFRX(P0DR, 0x7EFE28);

// SFR P1DR: Port 1 drive current control register
SFRX(P1DR, 0x7EFE29);

// SFR P2DR: Port 2 drive current control register
SFRX(P2DR, 0x7EFE2A);

// SFR P3DR: Port 3 drive current control register
SFRX(P3DR, 0x7EFE2B);

// SFR P4DR: Port 4 drive current control register
SFRX(P4DR, 0x7EFE2C);

// SFR P5DR: Port 5 drive current control register
SFRX(P5DR, 0x7EFE2D);

// SFR P6DR: Port 6 drive current control register
SFRX(P6DR, 0x7EFE2E);

// SFR P7DR: Port 7 drive current control register
SFRX(P7DR, 0x7EFE2F);

// SFR P0IE: Port 0 input enable control register
SFRX(P0IE, 0x7EFE30);

// SFR P1IE: Port 1 input enable control register
SFRX(P1IE, 0x7EFE31);

// SFR P3IE: Port 3 input enable control register
SFRX(P3IE, 0x7EFE33);

// SFR I2CCFG: I2C configuration register
SFRX(I2CCFG, 0x7EFE80);
#define MSSPEED0 0x1
#define MSSPEED1 0x2
#define MSSPEED2 0x4
#define MSSPEED3 0x8
#define MSSPEED4 0x10
#define MSSPEED5 0x20
#define MSSL 0x40
#define ENI2C 0x80

// SFR I2CMSCR: I2C host control register
SFRX(I2CMSCR, 0x7EFE81);
#define MSCMD0 0x1
#define MSCMD1 0x2
#define MSCMD2 0x4
#define MSCMD3 0x8
#define EMSI 0x80

// SFR I2CMSST: I2C host status register
SFRX(I2CMSST, 0x7EFE82);
#define MSACKO 0x1
#define MSACKI 0x2
#define MSIF 0x40
#define MSBUSY 0x80

// SFR I2CSLCR: I2C slave control register
SFRX(I2CSLCR, 0x7EFE83);
#define SLRST 0x1
#define ESTOI 0x8
#define ETXI 0x10
#define ERXI 0x20
#define ESTAI 0x40

// SFR I2CSLST: I2C slave status register
SFRX(I2CSLST, 0x7EFE84);
#define SLACKO 0x1
#define SLACKI 0x2
#define TXING 0x4
#define STOIF 0x8
#define TXIF 0x10
#define RXIF 0x20
#define STAIF 0x40
#define SLBUSY 0x80

// SFR I2CSLADR: I2C slave address register
SFRX(I2CSLADR, 0x7EFE85);
#define MA 0x1
#define SLADR0 0x2
#define SLADR1 0x4
#define SLADR2 0x8
#define SLADR3 0x10
#define SLADR4 0x20
#define SLADR5 0x40
#define SLADR6 0x80

// SFR I2CTXD: I2C data transmission register
SFRX(I2CTXD, 0x7EFE86);

// SFR I2CRXD: I2C data receive register
SFRX(I2CRXD, 0x7EFE87);

// SFR I2CMSAUX: I2C host auxiliary control register
SFRX(I2CMSAUX, 0x7EFE88);
#define WDTA 0x1

// SFR TM2PS: Timer 2 clock prescaler register
SFRX(TM2PS, 0x7EFEA2);

// SFR TM3PS: Timer 3 clock prescaler register
SFRX(TM3PS, 0x7EFEA3);

// SFR TM4PS: Timer 4 clock prescaler register
SFRX(TM4PS, 0x7EFEA4);

// SFR ADCTIM: ADC timing control register
SFRX(ADCTIM, 0x7EFEAB);
#define SMPDUTY0 0x1
#define SMPDUTY1 0x2
#define SMPDUTY2 0x4
#define SMPDUTY3 0x8
#define SMPDUTY4 0x10
#define CSHOLD0 0x20
#define CSHOLD1 0x40
#define CSSETUP 0x80

// SFR T3T4PIN: T3/T4 selection register
SFRX(T3T4PIN, 0x7EFEAC);
#define T3T4SEL 0x1

// SFR PWMA_ETRPS: PWMA ETR select register
SFRX(PWMA_ETRPS, 0x7EFEB0);
#define ETRAPS0 0x1
#define ETRAPS1 0x2
#define BRKAPS 0x4

// SFR PWMA_ENO: PWMA output enable control
SFRX(PWMA_ENO, 0x7EFEB1);
#define ENO1P 0x1
#define ENO1N 0x2
#define ENO2P 0x4
#define ENO2N 0x8
#define ENO3P 0x10
#define ENO3N 0x20
#define ENO4P 0x40
#define ENO4N 0x80

// SFR PWMA_PS: PWMA output pin selection register
SFRX(PWMA_PS, 0x7EFEB2);
#define C1PS0 0x1
#define C1PS1 0x2
#define C2PS0 0x4
#define C2PS1 0x8
#define C3PS0 0x10
#define C3PS1 0x20
#define C4PS0 0x40
#define C4PS1 0x80

// SFR PWMA_IOAUX: PWMA auxiliary register
SFRX(PWMA_IOAUX, 0x7EFEB3);
#define AUX1P 0x1
#define AUX1N 0x2
#define AUX2P 0x4
#define AUX2N 0x8
#define AUX3P 0x10
#define AUX3N 0x20
#define AUX4P 0x40
#define AUX4N 0x80

// SFR PWMB_ETRPS: PWMB ETR select register
SFRX(PWMB_ETRPS, 0x7EFEB4);
#define ETRBPS0 0x1
#define ETRBPS1 0x2
#define BRKBPS 0x4

// SFR PWMB_ENO: PWMB output enable control
SFRX(PWMB_ENO, 0x7EFEB5);
#define ENO5P 0x1
#define ENO6P 0x4
#define ENO7P 0x10
#define ENO8P 0x40

// SFR PWMB_PS: PWMB output pin selection register
SFRX(PWMB_PS, 0x7EFEB6);
#define C5PS0 0x1
#define C5PS1 0x2
#define C6PS0 0x4
#define C6PS1 0x8
#define C7PS0 0x10
#define C7PS1 0x20
#define C8PS0 0x40
#define C8PS1 0x80

// SFR PWMB_IOAUX: PWMB auxiliary register
SFRX(PWMB_IOAUX, 0x7EFEB7);
#define AUX5P 0x1
#define AUX6P 0x4
#define AUX7P 0x10
#define AUX8P 0x40

// SFR PWMA_CR1: PWMA control register 1
SFRX(PWMA_CR1, 0x7EFEC0);
#define CEN 0x1
#define UDIS 0x2
#define URS 0x4
#define OPM 0x8
#define DIR 0x10
#define CMS0 0x20
#define CMS1 0x40
#define ARPE 0x80

// SFR PWMA_CR2: PWMA control register 2
SFRX(PWMA_CR2, 0x7EFEC1);
#define CCPC 0x1
#define COMS 0x4
#define MMS0 0x10
#define MMS1 0x20
#define MMS2 0x40

// SFR PWMA_SMCR: PWMA slave mode control register
SFRX(PWMA_SMCR, 0x7EFEC2);
#define SMS0 0x1
#define SMS1 0x2
#define SMS2 0x4
#define TS0 0x10
#define TS1 0x20
#define TS2 0x40
#define MSM 0x80

// SFR PWMA_ETR: PWMA external trigger register
SFRX(PWMA_ETR, 0x7EFEC3);
#define ETF0 0x1
#define ETF1 0x2
#define ETF2 0x4
#define ETF3 0x8
#define ETPS0 0x10
#define ETPS1 0x20
#define ECE 0x40
#define ETP 0x80

// SFR PWMA_IER: PWMA interrupt enable register
SFRX(PWMA_IER, 0x7EFEC4);
#define UIE 0x1
#define CC1IE 0x2
#define CC2IE 0x4
#define CC3IE 0x8
#define CC4IE 0x10
#define COMIE 0x20
#define TIE 0x40
#define BIE 0x80

// SFR PWMA_SR1: PWMA status register 1
SFRX(PWMA_SR1, 0x7EFEC5);
#define UIF 0x1
#define CC1IF 0x2
#define CC2IF 0x4
#define CC3IF 0x8
#define CC4IF 0x10
#define COMIF 0x20
#define TIF 0x40
#define BIF 0x80

// SFR PWMA_SR2: PWMA status register 2
SFRX(PWMA_SR2, 0x7EFEC6);
#define CC1OF 0x2
#define CC2OF 0x4
#define CC3OF 0x8
#define CC4OF 0x10

// SFR PWMA_EGR: PWMA event register
SFRX(PWMA_EGR, 0x7EFEC7);
#define UG 0x1
#define CC1G 0x2
#define CC2G 0x4
#define CC3G 0x8
#define CC4G 0x10
#define COMG 0x20
#define TG 0x40
#define BG 0x80

// SFR PWMA_CCMR1: PWMA capture mode register 1
SFRX(PWMA_CCMR1, 0x7EFEC8);
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
SFRX(PWMA_CCMR2, 0x7EFEC9);
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
SFRX(PWMA_CCMR3, 0x7EFECA);
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
SFRX(PWMA_CCMR4, 0x7EFECB);
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
SFRX(PWMA_CCER1, 0x7EFECC);
#define CC1E 0x1
#define CC1P 0x2
#define CC1NE 0x4
#define CC1NP 0x8
#define CC2E 0x10
#define CC2P 0x20
#define CC2NE 0x40
#define CC2NP 0x80

// SFR PWMA_CCER2: PWMA capture compare enable register 2
SFRX(PWMA_CCER2, 0x7EFECD);
#define CC3E 0x1
#define CC3P 0x2
#define CC3NE 0x4
#define CC3NP 0x8
#define CC4E 0x10
#define CC4P 0x20
#define CC4NE 0x40
#define CC4NP 0x80

// SFR PWMA_CNTRH: PWMA counter high byte
SFRX(PWMA_CNTRH, 0x7EFECE);

// SFR PWMA_CNTRL: PWMA counter low byte
SFRX(PWMA_CNTRL, 0x7EFECF);

// SFR PWMA_PSCRH: PWMA prescale high byte
SFRX(PWMA_PSCRH, 0x7EFED0);

// SFR PWMA_PSCRL: PWMA prescale low byte
SFRX(PWMA_PSCRL, 0x7EFED1);

// SFR PWMA_ARRH: PWMA auto-reload register high byte
SFRX(PWMA_ARRH, 0x7EFED2);

// SFR PWMA_ARRL: PWMA auto-reload register low byte
SFRX(PWMA_ARRL, 0x7EFED3);

// SFR PWMA_RCR: PWMA repeat counter register
SFRX(PWMA_RCR, 0x7EFED4);

// SFR PWMA_CCR1H: PWMA compare capture register 1 high byte
SFRX(PWMA_CCR1H, 0x7EFED5);

// SFR PWMA_CCR1L: PWMA compare capture register 1 low byte
SFRX(PWMA_CCR1L, 0x7EFED6);

// SFR PWMA_CCR2H: PWMA compare capture register 2 high byte
SFRX(PWMA_CCR2H, 0x7EFED7);

// SFR PWMA_CCR2L: PWMA compare capture register 2 low byte
SFRX(PWMA_CCR2L, 0x7EFED8);

// SFR PWMA_CCR3H: PWMA compare capture register 3 high byte
SFRX(PWMA_CCR3H, 0x7EFED9);

// SFR PWMA_CCR3L: PWMA compare capture register 3 low byte
SFRX(PWMA_CCR3L, 0x7EFEDA);

// SFR PWMA_CCR4H: PWMA compare capture register 4 high byte
SFRX(PWMA_CCR4H, 0x7EFEDB);

// SFR PWMA_CCR4L: PWMA compare capture register 4 low byte
SFRX(PWMA_CCR4L, 0x7EFEDC);

// SFR PWMA_BKR: PWMA brake register
SFRX(PWMA_BKR, 0x7EFEDD);
#define LOCK0 0x1
#define LOCK1 0x2
#define OSSI 0x4
#define OSSR 0x8
#define BKE 0x10
#define BKP 0x20
#define AOE 0x40
#define MOE 0x80

// SFR PWMA_DTR: PWMA dead time control register
SFRX(PWMA_DTR, 0x7EFEDE);

// SFR PWMA_OISR: PWMA output idle status register
SFRX(PWMA_OISR, 0x7EFEDF);
#define OIS1 0x1
#define OIS1N 0x2
#define OIS2 0x4
#define OIS2N 0x8
#define OIS3 0x10
#define OIS3N 0x20
#define OIS4 0x40
#define OIS4N 0x80

// SFR PWMB_CR1: PWMB control register 1
SFRX(PWMB_CR1, 0x7EFEE0);

// SFR PWMB_CR2: PWMB control register 2
SFRX(PWMB_CR2, 0x7EFEE1);

// SFR PWMB_SMCR: PWMB slave mode control register
SFRX(PWMB_SMCR, 0x7EFEE2);

// SFR PWMB_ETR: PWMB external trigger register
SFRX(PWMB_ETR, 0x7EFEE3);

// SFR PWMB_IER: PWMB interrupt enable register
SFRX(PWMB_IER, 0x7EFEE4);
#define CC5IE 0x2
#define CC6IE 0x4
#define CC7IE 0x8
#define CC8IE 0x10

// SFR PWMB_SR1: PWMB status register 1
SFRX(PWMB_SR1, 0x7EFEE5);
#define CC5IF 0x2
#define CC6IF 0x4
#define CC7IF 0x8
#define CC8IF 0x10

// SFR PWMB_SR2: PWMB status register 2
SFRX(PWMB_SR2, 0x7EFEE6);
#define CC5OF 0x2
#define CC6OF 0x4
#define CC7OF 0x8
#define CC8OF 0x10

// SFR PWMB_EGR: PWMB event register
SFRX(PWMB_EGR, 0x7EFEE7);
#define CC5G 0x2
#define CC6G 0x4
#define CC7G 0x8
#define CC8G 0x10

// SFR PWMB_CCMR1: PWMB capture mode register 1
SFRX(PWMB_CCMR1, 0x7EFEE8);
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
SFRX(PWMB_CCMR2, 0x7EFEE9);
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
SFRX(PWMB_CCMR3, 0x7EFEEA);
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
SFRX(PWMB_CCMR4, 0x7EFEEB);
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
SFRX(PWMB_CCER1, 0x7EFEEC);
#define CC5E 0x1
#define CC5P 0x2
#define CC5NE 0x4
#define CC5NP 0x8
#define CC6E 0x10
#define CC6P 0x20
#define CC6NE 0x40
#define CC6NP 0x80

// SFR PWMB_CCER2: PWMB capture compare enable register 2
SFRX(PWMB_CCER2, 0x7EFEED);
#define CC7E 0x1
#define CC7P 0x2
#define CC7NE 0x4
#define CC7NP 0x8
#define CC8E 0x10
#define CC8P 0x20
#define CC8NE 0x40
#define CC8NP 0x80

// SFR PWMB_CNTRH: PWMB counter high byte
SFRX(PWMB_CNTRH, 0x7EFEEE);

// SFR PWMB_CNTRL: PWMB counter low byte
SFRX(PWMB_CNTRL, 0x7EFEEF);

// SFR PWMB_PSCRH: PWMB prescale high byte
SFRX(PWMB_PSCRH, 0x7EFEF0);

// SFR PWMB_PSCRL: PWMB prescale low byte
SFRX(PWMB_PSCRL, 0x7EFEF1);

// SFR PWMB_ARRH: PWMB auto-reload register high byte
SFRX(PWMB_ARRH, 0x7EFEF2);

// SFR PWMB_ARRL: PWMB auto-reload register low byte
SFRX(PWMB_ARRL, 0x7EFEF3);

// SFR PWMB_RCR: PWMB repeat counter register
SFRX(PWMB_RCR, 0x7EFEF4);

// SFR PWMB_CCR1H: PWMB compare capture register 1 high byte
SFRX(PWMB_CCR1H, 0x7EFEF5);

// SFR PWMB_CCR1L: PWMB compare capture register 1 low byte
SFRX(PWMB_CCR1L, 0x7EFEF6);

// SFR PWMB_CCR2H: PWMB compare capture register 2 high byte
SFRX(PWMB_CCR2H, 0x7EFEF7);

// SFR PWMB_CCR2L: PWMB compare capture register 2 low byte
SFRX(PWMB_CCR2L, 0x7EFEF8);

// SFR PWMB_CCR3H: PWMB compare capture register 3 high byte
SFRX(PWMB_CCR3H, 0x7EFEF9);

// SFR PWMB_CCR3L: PWMB compare capture register 3 low byte
SFRX(PWMB_CCR3L, 0x7EFEFA);

// SFR PWMB_CCR4H: PWMB compare capture register 4 high byte
SFRX(PWMB_CCR4H, 0x7EFEFB);

// SFR PWMB_CCR4L: PWMB compare capture register 4 low byte
SFRX(PWMB_CCR4L, 0x7EFEFC);

// SFR PWMB_BKR: PWMB brake register
SFRX(PWMB_BKR, 0x7EFEFD);

// SFR PWMB_DTR: PWMB dead time control register
SFRX(PWMB_DTR, 0x7EFEFE);

// SFR PWMB_OISR: PWMB output idle status register
SFRX(PWMB_OISR, 0x7EFEFF);
#define OIS5 0x1
#define OIS6 0x4
#define OIS7 0x10
#define OIS8 0x40
// External interrupt 0
#define EXTINT0_INTERRUPT 0
#define EXTINT0_VECTOR_ADDR 0xFF0003
// Timer 0 interrupt
#define TIMER0_INTERRUPT 1
#define TIMER0_VECTOR_ADDR 0xFF000B
// External interrupt 1
#define EXTINT1_INTERRUPT 2
#define EXTINT1_VECTOR_ADDR 0xFF0013
// Timer 1 interrupt
#define TIMER1_INTERRUPT 3
#define TIMER1_VECTOR_ADDR 0xFF001B
// UART 1 interrupt
#define UART1_INTERRUPT 4
#define UART1_VECTOR_ADDR 0xFF0023
// ADC interrupt
#define ADC_INTERRUPT 5
#define ADC_VECTOR_ADDR 0xFF002B
// Low-voltage detector interrupt
#define LVD_INTERRUPT 6
#define LVD_VECTOR_ADDR 0xFF0033
// PWM A interrupt
#define PWMA_INTERRUPT 7
#define PWMA_VECTOR_ADDR 0x3B
// UART 2 interrupt
#define UART2_INTERRUPT 8
#define UART2_VECTOR_ADDR 0xFF0043
// SPI interrupt
#define SPI_INTERRUPT 9
#define SPI_VECTOR_ADDR 0xFF004B
// External interrupt 2 (falling edge only)
#define EXTINT2_INTERRUPT 10
#define EXTINT2_VECTOR_ADDR 0xFF0053
// External interrupt 3 (falling edge only)
#define EXTINT3_INTERRUPT 11
#define EXTINT3_VECTOR_ADDR 0xFF005B
// Timer 2 interrupt
#define TIMER2_INTERRUPT 12
#define TIMER2_VECTOR_ADDR 0xFF0063
// External interrupt 4 (falling edge only)
#define EXTINT4_INTERRUPT 16
#define EXTINT4_VECTOR_ADDR 0xFF0083
// UART 3 interrupt
#define UART3_INTERRUPT 17
#define UART3_VECTOR_ADDR 0xFF008B
// UART 4 interrupt
#define UART4_INTERRUPT 18
#define UART4_VECTOR_ADDR 0xFF0093
// Timer 3 interrupt
#define TIMER3_INTERRUPT 19
#define TIMER3_VECTOR_ADDR 0xFF009B
// Timer 4 interrupt
#define TIMER4_INTERRUPT 20
#define TIMER4_VECTOR_ADDR 0xFF00A3
// Comparator interrupt
#define CMP_INTERRUPT 21
#define CMP_VECTOR_ADDR 0xFF00AB
// USB interrupt
#define USB_INTERRUPT 22
#define USB_VECTOR_ADDR 0xFF00B3
// PWM B interrupt
#define PWMB_INTERRUPT 23
#define PWMB_VECTOR_ADDR 0xFF00BB
// I2C interrupt
#define I2C_INTERRUPT 24
#define I2C_VECTOR_ADDR 0xFF00C3
// CAN interrupt
#define CANBUS_INTERRUPT 28
#define CANBUS_VECTOR_ADDR 0xFF00E3
// LIN interrupt
#define LINBUS_INTERRUPT 29
#define LINBUS_VECTOR_ADDR 0xFF00EB

// Default value for macro F_CPU
#ifndef F_CPU
#define F_CPU 24000000UL
#endif

// Default value for macro T_CPU
#ifndef T_CPU
#define T_CPU 1
#endif

#endif // _STC16_H
