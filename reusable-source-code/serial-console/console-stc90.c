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
#include "stc90.h"
#include "console-stc90.h"

/**
 * @file console-stc90.c
 * 
 * Serial console driver: STC90 implementation.
 */

#if T_CPU == 6
#define PRESCALING 16UL
#else
#define PRESCALING 32UL
#endif

volatile char __console_sending;

#define INPUT_BUFFER_SIZE 16
unsigned char __console_inputBuffer[INPUT_BUFFER_SIZE];
volatile unsigned char __console_bufferFirst;
volatile unsigned char __console_bufferNext;

// TxD is on P3.1 (pin 11 on DIP40) and RxD on P3.0 (pin 10 on DIP40)
void console_initialise(unsigned long baudRate) {
	// Set Timer 2 reload value
	// If PCON |= SMOD; then PRESCALING must be divided by 2.
	unsigned int reloadValue =  (unsigned int) (65536UL - (F_CPU / baudRate / PRESCALING));
	T2L = RCAP2L = reloadValue & 0xFF;
	T2H = RCAP2H = reloadValue >> 8;
	
	// Define Timer 2 as baud rate generator for UART, and start it.
	T2CON = 0x34;
	
	// Set UART in mode 1 and clear interrupt flags
	SCON = 0x50;
	
	// Enable serial port interrupt
	ES = 1;
	
	__console_bufferFirst = 0;
	__console_bufferNext = 0;
	__console_sending = 0;
}

void __uart1_isr() __interrupt UART1_INTERRUPT __using 1 __critical {
	if (TI) {
		TI = 0;
		__console_sending = 0;
	}

	if (RI) {
		RI = 0;
		
		int ptrDiff = __console_bufferNext - __console_bufferFirst;
		// ptrDiff == 0 => Buffer is empty.
		// Buffer is considered full if, when incremented, bufferNext 
		// would become equal to bufferFirst.
		
		if (ptrDiff != -1 && ptrDiff != (INPUT_BUFFER_SIZE - 1)) {
			__console_inputBuffer[__console_bufferNext++] = SBUF;
			
			if (__console_bufferNext == INPUT_BUFFER_SIZE) {
				__console_bufferNext = 0;
			}
		}
	}
}

unsigned char console_readCharacter() {
	unsigned char result = 0;
	
	if (__console_bufferFirst != __console_bufferNext) {
		result = __console_inputBuffer[__console_bufferFirst++];
		
		if (__console_bufferFirst == INPUT_BUFFER_SIZE) {
			__console_bufferFirst = 0;
		}
	}
	
	return result;
}

void console_sendCharacter(unsigned char c) {
	while (__console_sending) {
		__asm nop __endasm;
	}
	
	__console_sending = 1;
    SBUF = c;
}
