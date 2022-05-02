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
 * @file delay-stc90.c
 * 
 * Calibrated delay loops: STC90 implementation.
 * 
 * Tested on an STC90C58RD+ clocked by an 11.0952 MHz crystal.
 */

#if T_CPU == 6
#define DELAY_1ms ((unsigned int) (((F_CPU / 1000UL) - 114UL) / 72UL))
#else
#define DELAY_1ms ((unsigned int) (((F_CPU / 1000UL) - 228UL) / 144UL))
#endif

// 12T mode: total_cycles = ms (144 n + 12 (n div 256) + 180) + 12 (ms div 256) + 120
// 6T mode: total_cycles = ms (72 n + 6 (n div 256) + 90) + 6 (ms div 256) + 60
// total_cycles = delay (= 1e-3 s) * oscillator_frequency (in Hz)
void delay1ms(unsigned int ms) {
	for (unsigned int i = ms; i; i--) {
		for (unsigned int n = DELAY_1ms; n; n--) {
			__asm nop __endasm;
			__asm nop __endasm;
			__asm nop __endasm;
		}
	}
}

#if T_CPU == 6
#define DELAY_10us ((unsigned char) (((F_CPU / 100000UL) - 84UL) / 36UL))
#else
#define DELAY_10us ((unsigned char) (((F_CPU / 100000UL) - 168UL) / 72UL))
#endif

// 12T mode: total_cycles = us (72 n + 120) + 84
// 6T mode: total_cycles = us (36 n + 60) + 42
// total_cycles = delay (= 1e-5 s) * oscillator_frequency (in Hz)
void delay10us(unsigned char us) {
	for (unsigned char i = us; i; i--) {
		for (unsigned char n = DELAY_10us; n; n--) {
		}
	}
}
