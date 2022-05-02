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
#include "stc12.h"
#include "console-stc12.h"

/**
 * @file console-stc12.c
 * 
 * Serial console driver: STC12 implementation.
 */

volatile char __console_sending;

#define INPUT_BUFFER_SIZE 16
unsigned char __console_inputBuffer[INPUT_BUFFER_SIZE];
volatile unsigned char __console_bufferFirst;
volatile unsigned char __console_bufferNext;

// TxD2 is on P1.3 (pin 4 on DIP40) and RxD2 on P1.2 (pin 3 on DIP40)
// (the alternative location is TxD2 on P4.3 and RxD2 on P4.2, 
// but these pins are not available on DIP40 packages.)
void console_initialise(unsigned long baudRate) {
	// Set baud rate timer reload value
	BRT =  (unsigned char) (256UL - (F_CPU / baudRate / 32UL));
	// If bit S2SMOD (double baud rate) was set in AUXR,
	// baudRate would be divided by 16 instead of 32.
	
	// Set clock source of baud rate timer to SYSclk/1
	AUXR |= BRTx12;
	
	// Start baud rate timer
	AUXR |= BRTR;
	
	// Set UART2 in mode 1 and clear interrupt flags
	S2CON = 0x50;
	
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
