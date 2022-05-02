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
 * @file delay-stc15.c
 * 
 * Calibrated delay loops: STC15 implementation.
 * 
 * Tested on an STC15W4K32S4 clocked by its internal 24 MHz RC oscillator.
 */

#define DELAY_1ms ((unsigned int) (((F_CPU / 1000UL) - 30UL) / 18UL))

// total_cycles = ms (18 n + 2 (n div 256) + 25) + 2 (ms div 256) + 14
// total_cycles = delay (= 1e-3 s) * oscillator_frequency (= 2.4e7 Hz)
// In order to round the result of the division to the closest integer,
// we add 18/2 = 9 to the numerator, giving - 30UL instead of - 39UL.
// n = 1331 => error = -0.0125 %
void delay1ms(unsigned int ms) {
	for (unsigned int i = ms; i; i--) {
		for (unsigned int n = DELAY_1ms; n; n--) {
			__asm nop __endasm;
			__asm nop __endasm;
			__asm nop __endasm;
		}
	}
}

#define DELAY_10us ((unsigned char) (((F_CPU / 100000UL) - 23UL) / 10UL))

// total_cycles = us (10 n + 17) + 11
// total_cycles = delay (= 1e-5 s) * oscillator_frequency (= 2.4e7 Hz)
// In order to round the result of the division to the closest integer,
// we add 10/2 = 5 to the numerator, giving - 23UL instead of - 28UL.
// n = 21 => error = -0.9434 %
void delay10us(unsigned char us) {
	for (unsigned char i = us; i; i--) {
		for (unsigned char n = DELAY_10us; n; n--) {
		}
	}
}
