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
#include "stc8f.h"
#include "console-stc8.h"

/**
 * @file console-stc8.c
 * 
 * Serial console driver: STC8 implementation.
 */

volatile char __console_sending;

#define INPUT_BUFFER_SIZE 16
unsigned char __console_inputBuffer[INPUT_BUFFER_SIZE];
volatile unsigned char __console_bufferFirst;
volatile unsigned char __console_bufferNext;

void console_initialise(unsigned long baudRate) {
	// Set Timer 2 reload value
	unsigned int reloadValue =  (unsigned int) (65536UL - (F_CPU / baudRate / 4UL));
	T2L = reloadValue & 0xFF;
	T2H = reloadValue >> 8;
	
	// Set clock source of Timer 2 to SYSclk/1
	AUXR |= T2x12;
	
	// Start Timer 2
	AUXR |= T2R;
	
	// Assign UART2 lines to P4 (P4.0 = RxD2, P4.2 = TxD2)
	// These pins are not available on DIP40 packages, 
	// but DIP40 STC8A are no longer manufactured.
	P_SW2 |= 1;
	
	// Set UART2 in mode 0 and clear interrupt flags
	S2CON = 0x10;
	
	// Enable Serial port 2 interrupt
	IE2 |= ES2;
	
	__console_bufferFirst = 0;
	__console_bufferNext = 0;
	__console_sending = 0;
}

void __uart2_isr() __interrupt UART2_INTERRUPT __using 1 __critical {
	if (S2CON & S2TI) {
		S2CON &= ~S2TI;
		__console_sending = 0;
	}

	if (S2CON & S2RI) {
		S2CON &= ~S2RI;
		int ptrDiff = __console_bufferNext - __console_bufferFirst;
		// ptrDiff == 0 => Buffer is empty.
		// Buffer is considered full if, when incremented, bufferNext 
		// would become equal to bufferFirst.
		
		if (ptrDiff != -1 && ptrDiff != (INPUT_BUFFER_SIZE - 1)) {
			__console_inputBuffer[__console_bufferNext++] = S2BUF;
			
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
    S2BUF = c;
}
