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
#ifndef _CONSOLE_STC90_H
#define _CONSOLE_STC90_H

/**
 * @file console-stc90.h
 * 
 * Serial console driver: definitions.
 * 
 * Pin assignments:
 * 
 * RxD = P3.0 (pin 10 on DIP40)
 * TxD = P3.1 (pin 11 on DIP40)
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 */

/**
 * Initialises the driver.
 * 
 * Configures the UART and initialises the driver's internal state.
 * 
 * Note the console uses the one and only UART of the poor STC90...
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

void __uart1_isr() __interrupt UART1_INTERRUPT __using 1;

#endif // _CONSOLE_STC90_H
