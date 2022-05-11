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
#ifndef _PCA_H
#define _PCA_H

/**
 * @file pca.h
 * 
 * PCA abstraction definitions.
 * 
 * Supported MCU families: STC12, STC15, STC8A, STC8F, STC8G.
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 */

#ifdef _STC8AF_H
#define PCA_CHANNEL_COUNT 4
#define __PCA_HAS_CHANNEL2
#define __PCA_HAS_CHANNEL3
#define __PCA_HAS_10BIT_PWM
#define __PCA_HAS_6_7_BIT_PWM
#endif // _STC8AF_H

#ifdef _STC8G_H
#define PCA_CHANNEL_COUNT 3
#define __PCA_HAS_CHANNEL2
#define __PCA_HAS_10BIT_PWM
#define __PCA_HAS_6_7_BIT_PWM
#endif // _STC8G_H

#ifdef _STC15_H
#define PCA_CHANNEL_COUNT 3
#define __PCA_HAS_CHANNEL2
#define __PCA_HAS_6_7_BIT_PWM
#endif // _STC15_H

#ifdef _STC12_H
#define PCA_CHANNEL_COUNT 2
#endif // _STC12_H

typedef enum {
	PCA_SYSCLK_DIV12 = 0,
	PCA_SYSCLK_DIV2 = 1,
	PCA_TIMER0 = 2,
	PCA_ECI = 3,
	PCA_SYSCLK = 4,
	PCA_SYSCLK_DIV4 = 5,
	PCA_SYSCLK_DIV6 = 6,
	PCA_SYSCLK_DIV8 = 7,
} PCA_ClockSource;

typedef enum {
	PCA_FREE_RUNNING = 0,
	PCA_ECI_ENABLED = 1,
} PCA_CounterMode;

typedef enum {
	PCA_CONTINUOUS = 0,
	PCA_ONE_SHOT = 1,
} PCA_CaptureMode;

typedef enum {
	PCA_INTERRUPT_DISABLE = 0,
	PCA_INTERRUPT_ENABLE = 1,
} PCA_Interrupt;

typedef enum {
	PCA_OUTPUT_DISABLE = 0,
	PCA_OUTPUT_ENABLE = 1,
} PCA_PulseOutput;

typedef enum {
	PCA_EDGE_RISING = 2,
	PCA_EDGE_FALLING = 1,
	PCA_EDGE_BOTH = 3,
	PCA_EDGE_NONE = 0,
} PCA_EdgeTrigger;

typedef enum {
	PCA_CHANNEL0 = 0,
	PCA_CHANNEL1 = 1,
#ifdef __PCA_HAS_CHANNEL2
	PCA_CHANNEL2 = 2,
#endif // __PCA_HAS_CHANNEL2
#ifdef __PCA_HAS_CHANNEL3
	PCA_CHANNEL3 = 3,
#endif // __PCA_HAS_CHANNEL3
} PCA_Channel;

typedef enum {
	PCA_P1 = 0,
#ifdef _STC8AF_H
	// Pin assignments:
	//
	// PCA_P1 => P1.2 = ECI, P1.7 = CCP0, P1.6 = CCP1, P1.5 = CCP2, P1.4 = CCP3
	// PCA_P2 => P2.2 = ECI, P2.3 = CCP0, P2.4 = CCP1, P2.5 = CCP2, P2.6 = CCP3
	// PCA_P3 => P3.5 = ECI, P3.3 = CCP0, P3.2 = CCP1, P3.1 = CCP2, P3.0 = CCP3
	// PCA_P7 => P7.4 = ECI, P7.0 = CCP0, P7.1 = CCP1, P7.2 = CCP2, P7.3 = CCP3
	PCA_P2 = 1,
	PCA_P7 = 2,
	PCA_P3 = 3,
#endif // _STC8AF_H
#ifdef _STC8G_H
	// For all STC8G except STC8G1K08A and STC8G1K08T, pin assignments 
	// are as follows:
	//
	// PCA_P1 => P1.2 = ECI, P1.1 = CCP0, P1.0 = CCP1, P3.7 = CCP2
	// PCA_P2 => P2.4 = ECI, P2.5 = CCP0, P2.6 = CCP1, P2.7 = CCP2
	// PCA_P3 => P3.4 = ECI, P3.5 = CCP0, P3.6 = CCP1, P3.7 = CCP2
	//
	// The STC8G1K08A uses an 8-pin package, so pin assignments 
	// somewhat differ:
	//
	// PCA_P1 => P5.5 = ECI, P3.2 = CCP0, P3.3 = CCP1, P5.4 = CCP2
	// PCA_P2 => P3.1 = ECI, P3.2 = CCP0, P3.3 = CCP1, P5.5 = CCP2
	// PCA_P3 => P5.5 = ECI, P3.1 = CCP0, P3.3 = CCP1, P5.4 = CCP2
	PCA_P2 = 2,
	PCA_P3 = 1,
#endif // _STC8G_H
#ifdef _STC15_H
	// Note: PCA_P2 is NOT available on STC15W4xxAS.
	
	// Pin assignments:
	//
	// PCA_P1 => P1.2 = ECI, P1.1 = CCP0, P1.0 = CCP1, P3.7 = CCP2
	// PCA_P2 => P2.4 = ECI, P2.5 = CCP0, P2.6 = CCP1, P2.7 = CCP2
	// PCA_P3 => P3.4 = ECI, P3.5 = CCP0, P3.6 = CCP1, P3.7 = CCP2
	PCA_P2 = 2,
	PCA_P3 = 1,
#endif // _STC15_H
#ifdef _STC12_H
	// Pin assignments:
	//
	// PCA_P1 => P1.2 = ECI, P1.3 = CCP0, P1.4 = CCP1
	// PCA_P4 => P4.1 = ECI, P4.2 = CCP0, P4.3 = CCP1
	PCA_P4 = 1,
#endif // _STC12_H
} PCA_Port;

typedef enum {
	PCA_8BIT_PWM = 0,
#ifdef __PCA_HAS_6_7_BIT_PWM
	PCA_7BIT_PWM = 1,
	PCA_6BIT_PWM = 2,
#endif // __PCA_HAS_6_7_BIT_PWM
#ifdef __PCA_HAS_10BIT_PWM
	PCA_10BIT_PWM = 3,
#endif // __PCA_HAS_10BIT_PWM
} PCA_PWM_Bits;

// For use by MAKE_PCA_PWM_BITS(b) only.
#define __MAKE_PCA_PWM_BITS(b) PCA_##b##BIT_PWM

/**
 * builds the name of the constant corresponding to the number of bits 
 * given as argument. Mind it HAS to be valid, as no check is made.
 * Supported values are [ 6, 7, 8, 10 ], but depend on the MCU family.
 */
#define MAKE_PCA_PWM_BITS(b) __MAKE_PCA_PWM_BITS(b)


void __pca_isr() ISR_PARAM(PCA_INTERRUPT, 1);

/**
 * Initialises the master counter of the counter array.
 * 
 * For source code clarity, should be called before any other PCA_* function.
 * 
 * PCA = Programmable Counter Array
 * 
 * CCP = Compare / Capture / PWM
 */
void pca_initialise(PCA_ClockSource clockSource, PCA_CounterMode counterMode, PCA_Interrupt overflowInterrupt, PCA_Port port);

/**
 * Helper function to configure and start Timer0 to achieve a given frequency.
 * 
 * Must be used when clockSource == PCA_TIMER0.
 * @returns -1 if the requested frequency is too HIGH to be obtained,
 * -2 if the requested frequency is too LOW to be obtained,
 * or 0 if the timer was successfully configured and started.
 */
int pca_startTimer0(uint32_t frequency);

/**
 * Configures a PCA channel to measure the width of a pulse.
 * 
 * The calculated 32-bit duration will be shifted right 'shiftBits' 
 * bits to get an uint16_t to pass to pca_onInterrupt().
 * 
 * shiftBits > 23 makes no sense, but be aware no check is made.
 */
void pca_startCapture(PCA_Channel channel, PCA_EdgeTrigger trigger, PCA_CaptureMode captureMode, uint8_t shiftBits);

/**
 * Configures a PCA channel in PWM mode.
 * 
 * The duty cycle is defined by the number of clockSource pulses during 
 * which the PWM output must be high.
 */
void pca_startPwm(PCA_Channel channel, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh);

/**
 * Changes the duty cycle of a PWM channel.
 * 
 * All other configuration parameters remain unchanged.
 */
void pca_setPwmDutyCycle(PCA_Channel channel, uint16_t clocksHigh);

/**
 * Configures a PCA channel in 16-bit software timer / pulse output mode.
 * 
 * timerPeriod is expressed as a number of clockSource pulses.
 */
void pca_startTimer(PCA_Channel channel, PCA_PulseOutput pulseOutput, uint16_t timerPeriod);

/**
 * MUST be implemented by the application, even when not used.
 * 
 * **IMPORTANT** We're inside an ISR, so just keep track of the values 
 * but DON'T do any processing there!
 */
void pca_onInterrupt(PCA_Channel channel, uint16_t pulseLength) USE_BANK(1);

#endif // _PCA_H
