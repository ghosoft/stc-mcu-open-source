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
#include "delay.h"

/**
 * @file delay-stc12.c
 * 
 * Calibrated delay loops: STC12 implementation.
 * 
 * Tested on an STC12C5A60S2 clocked by an 11.0952 MHz crystal.
 */

#define DELAY_1ms ((unsigned int) (((F_CPU / 1000UL) - 30UL) / 19UL))

// total_cycles = ms (19 n + 3 (n div 256) + 26) + 3 (ms div 256) + 14
// total_cycles = delay (= 1e-3 s) * oscillator_frequency (in Hz)
// In order to round the result of the division to the closest integer,
// we add 19/2 = 9 to the numerator, giving - 30UL instead of - 39UL.
void delay1ms(unsigned int ms) {
	for (unsigned int i = ms; i; i--) {
		for (unsigned int n = DELAY_1ms; n; n--) {
			__asm nop __endasm;
			__asm nop __endasm;
			__asm nop __endasm;
		}
	}
}

#define DELAY_10us ((unsigned char) (((F_CPU / 100000UL) - 21UL) / 10UL))

// total_cycles = us (10 n + 16) + 10
// total_cycles = delay (= 1e-5 s) * oscillator_frequency (in Hz)
// In order to round the result of the division to the closest integer,
// we add 10/2 = 5 to the numerator, giving - 21UL instead of - 26UL.
void delay10us(unsigned char us) {
	for (unsigned char i = us; i; i--) {
		for (unsigned char n = DELAY_10us; n; n--) {
		}
	}
}
