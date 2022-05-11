/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
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
#ifndef _CONSOLE_H
#define _CONSOLE_H

/**
 * @file console.h
 * 
 * Serial console driver: definitions.
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 * 
 * Pin assignments:
 * 
 * STC12 (only the STC12C5AxxS2 has an UART2)
 * 
 * RxD = P1.2 (alternative is P4.2, but not available on all packages)
 * TxD = P1.3 (alternative is P4.3, but not available on all packages)
 * 
 * STC15 (only the STC15W4KxxS4 and STC15F2KxxS2 have an UART2)
 * 
 * RxD = P1.0 (alternative is P4.6, but not available on all packages)
 * TxD = P1.1 (alternative is P4.7, but not available on all packages)
 * 
 * STC8A/F (we assume we're using an MCU in LQFP44/48/64 package)
 * 
 * RxD = P4.0 (normally P1.0, but often used for I/O)
 * TxD = P4.2 (normally P1.1, but often used for I/O)
 * 
 * STC8G/H (only STC8G1Kxx-38I in 16- or 20-pin package
 *          and STC8G2KxxSy have an UART2. All STC8H do)
 * 
 * RxD = P1.0 (alternative is P4.6, but not available on all packages)
 * TxD = P1.1 (alternative is P4.7, but not available on all packages)
 * 
 */

/**
 * Initialises the driver.
 * 
 * Configures the UART and initialises the driver's internal state.
 * 
 * Note: the console uses UART2, leaving UART1 for flash programming.
 */
void console_initialise(unsigned long baudRate);

/**
 * Initiates the transmission of a character.
 * 
 * The character is placed in the output buffer, and transmission is 
 * (re-)started if needed.
 */
void console_sendCharacter(unsigned char c);

/**
 * @returns the next character available in the input buffer, 
 * or 0 if the buffer was empty.
 */
unsigned char console_readCharacter();

void __uart2_isr() __interrupt UART2_INTERRUPT __using 1;

#endif // _CONSOLE_H
