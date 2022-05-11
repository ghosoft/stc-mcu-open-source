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
#include "project-defs.h"
#include "pca.h"

/**
 * @file pca.c
 * 
 * PCA abstraction implementation.
 */

typedef enum {
	PCA_UNUSED = 0x00,
	// Pulse width capture
	PCA_CAPTURE = 0x40,
	// PWM output
	PCA_PWM = 0x42,
	// 16-bit software timer
	PCA_TIMER = 0x49,
	// 16-bit high-speed pulse output
	PCA_PULSE = 0x4d,
} PCA_ChannelMode;

typedef union {
	struct {
		uint8_t ccapl;
		uint8_t ccaph;
		uint8_t cnt;
		uint8_t zero;
	} fields;
	uint32_t count;
} PCA_CaptureCount;

PCA_CaptureCount __pca_captureStartCount[PCA_CHANNEL_COUNT];
PCA_CaptureCount __pca_captureEndCount[PCA_CHANNEL_COUNT];
uint16_t __pca_timerPeriod[PCA_CHANNEL_COUNT];
uint16_t __pca_timerValue[PCA_CHANNEL_COUNT];
uint8_t __pca_captureOverflowCounter[PCA_CHANNEL_COUNT];
uint8_t __pca_captureShiftBits[PCA_CHANNEL_COUNT];
PCA_CaptureMode __pca_captureMode[PCA_CHANNEL_COUNT];
PCA_ChannelMode __pca_channelMode[PCA_CHANNEL_COUNT];

void __pca_isr() ISR_PARAM(PCA_INTERRUPT, 1) __critical {
	uint8_t ccapl = 0;
	uint8_t ccaph = 0;
	uint8_t channel = PCA_CHANNEL_COUNT;
	PCA_CaptureCount width;
	uint16_t duration = 0;
	
	if (CF) {
		CF = 0;
		__pca_captureOverflowCounter[PCA_CHANNEL0]++;
		__pca_captureOverflowCounter[PCA_CHANNEL1]++;
#ifdef __PCA_HAS_CHANNEL2
		__pca_captureOverflowCounter[PCA_CHANNEL2]++;
#endif // __PCA_HAS_CHANNEL2
#ifdef __PCA_HAS_CHANNEL3
		__pca_captureOverflowCounter[PCA_CHANNEL3]++;
#endif // __PCA_HAS_CHANNEL3
	}
	
	if (CCF0) {
		CCF0 = 0;
		channel = PCA_CHANNEL0;
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP0L;
			ccaph = CCAP0H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM0 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP0L = __pca_timerValue[channel] & 0xff;
			CCAP0H = __pca_timerValue[channel] >> 8;
			break;
		}
	}
	
	if (CCF1) {
		CCF1 = 0;
		channel = PCA_CHANNEL1;
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP1L;
			ccaph = CCAP1H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM1 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP1L = __pca_timerValue[channel] & 0xff;
			CCAP1H = __pca_timerValue[channel] >> 8;
			break;
		}
	}
	
#ifdef __PCA_HAS_CHANNEL2
	if (CCF2) {
		CCF2 = 0;
		channel = PCA_CHANNEL2;
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP2L;
			ccaph = CCAP2H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM2 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP2L = __pca_timerValue[channel] & 0xff;
			CCAP2H = __pca_timerValue[channel] >> 8;
			break;
		}
	}
#endif // __PCA_HAS_CHANNEL2
	
#ifdef __PCA_HAS_CHANNEL3
	if (CCF3) {
		CCF3 = 0;
		channel = PCA_CHANNEL3;
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP3L;
			ccaph = CCAP3H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM3 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP3L = __pca_timerValue[channel] & 0xff;
			CCAP3H = __pca_timerValue[channel] >> 8;
			break;
		}
	}
#endif // __PCA_HAS_CHANNEL3
	
	if (channel < PCA_CHANNEL_COUNT) {
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			__pca_captureStartCount[channel].count = __pca_captureEndCount[channel].count;
			__pca_captureEndCount[channel].fields.ccapl = ccapl;
			__pca_captureEndCount[channel].fields.ccaph = ccaph;
			__pca_captureEndCount[channel].fields.cnt = __pca_captureOverflowCounter[channel];
			__pca_captureEndCount[channel].fields.zero = 0;
			
			width.count = (__pca_captureEndCount[channel].count - __pca_captureStartCount[channel].count) >> __pca_captureShiftBits[channel];
			// 0xffff means "maximum value and above".
			duration = width.fields.cnt ? 0xffff : ((uint16_t) width.count);
			
			pca_onInterrupt(channel, duration);
			break;
		
		case PCA_PWM:
		case PCA_TIMER:
			pca_onInterrupt(channel, duration);
			break;
		}
	}
}

inline uint8_t __pca_ccapm(PCA_ChannelMode channelMode, PCA_EdgeTrigger interruptTrigger) {
	return channelMode | (interruptTrigger << 4) | ((interruptTrigger != PCA_EDGE_NONE) ? PCA_INTERRUPT_ENABLE : PCA_INTERRUPT_DISABLE);
}

void pca_initialise(PCA_ClockSource clockSource, PCA_CounterMode counterMode, PCA_Interrupt overflowInterrupt, PCA_Port port) {
	/*
	 * All CCP channels are assigned to the same port (default is P1).
	 * 
	 * STC12 pin choices:
	 * 
	 * PCA_P1 => P1.2 = ECI, P1.3 = CCP0, P1.4 = CCP1
	 * PCA_P4 => P4.1 = ECI, P4.2 = CCP0, P4.3 = CCP1
	 * 
	 * STC15 pin choices:
	 * 
	 * PCA_P1 => P1.2 = ECI, P1.1 = CCP0, P1.0 = CCP1, P3.7 = CCP2
	 * PCA_P2 => P2.4 = ECI, P2.5 = CCP0, P2.6 = CCP1, P2.7 = CCP2
	 * PCA_P3 => P3.4 = ECI, P3.5 = CCP0, P3.6 = CCP1, P3.7 = CCP2
	 * 
	 * Note: PCA_P2 is NOT available on STC15W4xxAS.
	 * 
	 * STC8 pin choices:
	 * 
	 * PCA_P1 => ECI = P1.2 - CCP0 = P1.7 - CCP1 = P1.6 - CCP2 = P1.5 - CCP3 = P1.4
	 * PCA_P2 => ECI = P2.2 - CCP0 = P2.3 - CCP1 = P2.4 - CCP2 = P2.5 - CCP3 = P2.6
	 * PCA_P7 => ECI = P7.4 - CCP0 = P7.0 - CCP1 = P7.1 - CCP2 = P7.2 - CCP3 = P7.3
	 * PCA_P3 => ECI = P3.5 - CCP0 = P3.3 - CCP1 = P3.2 - CCP2 = P3.1 - CCP3 = P3.0
	 */
#ifdef __PCA_HAS_P4
	AUXR1 = (AUXR1 & 0xdf) | (port << 6);
#else // !__PCA_HAS_P4
	P_SW1 = (P_SW1 & 0xcf) | (port << 4);
#endif // __PCA_HAS_P4
	
	for (uint8_t channel = 0; channel < PCA_CHANNEL_COUNT; channel++) {
		__pca_channelMode[channel] = PCA_UNUSED;
	}
	
	CMOD = (counterMode << 7) | (clockSource << 1) | overflowInterrupt;
	CCON = 0;
	CL = 0x00;
	CH = 0x00;
	CR = 1;
}

int pca_startTimer0(uint32_t frequency) {
	int rc = 0;
	uint32_t divisor = F_CPU / frequency;
	uint8_t timerMode = 0;
	uint8_t sysclkDiv1 = 1;
	
	if (divisor == 0) {
		// frequency too high
		rc = -1;
	} else if (divisor > 786432UL) {
		// frequency too low (786432 = 65536 * 12)
		rc = -2;
	} else {
		if (divisor > 65536UL || (divisor > 256UL && divisor <= 3072UL && (divisor % 12) == 0)) {
			// sysclkDiv1 = 0 => pre-divide sysclk by 12
			sysclkDiv1 = 0;
			divisor /= 12UL;
		}
		
		uint16_t reloadValue;
		
		if (divisor <= 256UL) {
			timerMode = 2;
			reloadValue = (uint16_t) (256UL - divisor);
		} else {
			reloadValue = (uint16_t) (65536UL - divisor);
		}
		
		// Set prescaler
		AUXR = (AUXR & 0x7f) | (sysclkDiv1 << 7);
		// Set timer mode
		TMOD = (TMOD & 0xf0) | timerMode;
		
		if (timerMode == 0) {
			// Mode 0 = 16-bit auto-reload
			TL0 = reloadValue & 0xff;
			TH0 = reloadValue >> 8;
		} else {
			// Mode 2 = 8-bit auto-reload
			TH0 = TL0 = reloadValue;
		}
		
		// Clear flags and start timer
		TCON = (TCON & 0xcc) | 0x10;
	}
	
	return rc;
}

void pca_startCapture(PCA_Channel channel, PCA_EdgeTrigger trigger, PCA_CaptureMode captureMode, uint8_t shiftBits) {
	CR = 0;
	CL = 0;
	CH = 0;
	
	__pca_captureOverflowCounter[channel] = 0;
	__pca_captureStartCount[channel].count = 0;
	__pca_captureEndCount[channel].count = 0;
	__pca_captureShiftBits[channel] = shiftBits;
	__pca_captureMode[channel] = captureMode;
	__pca_channelMode[channel] = PCA_CAPTURE;
	
	uint8_t ccapm = __pca_ccapm(PCA_CAPTURE, trigger);
	
	switch (channel) {
	case PCA_CHANNEL0:
		CCAPM0 = ccapm;
		CCAP0L = 0;
		CCAP0H = 0;
		break;
		
	case PCA_CHANNEL1:
		CCAPM1 = ccapm;
		CCAP1L = 0;
		CCAP1H = 0;
		break;
		
#ifdef __PCA_HAS_CHANNEL2
	case PCA_CHANNEL2:
		CCAPM2 = ccapm;
		CCAP2L = 0;
		CCAP2H = 0;
		break;
#endif // __PCA_HAS_CHANNEL2
		
#ifdef __PCA_HAS_CHANNEL3
	case PCA_CHANNEL3:
		CCAPM3 = ccapm;
		CCAP3L = 0;
		CCAP3H = 0;
		break;
#endif // __PCA_HAS_CHANNEL3
	}
	
	CR = 1;
}

void __pca_configurePWM(uint8_t initialise, PCA_Channel channel, PCA_PWM_Bits pwmBits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
	__pca_channelMode[channel] = PCA_PWM;
	PCA_PWM_Bits bits = pwmBits;
	
	if (!initialise) {
		switch (channel) {
		case PCA_CHANNEL0:
			bits = (PCA_PWM_Bits) ((PCA_PWM0 >> 6) & 3);
			break;
		
		case PCA_CHANNEL1:
			bits = (PCA_PWM_Bits) ((PCA_PWM1 >> 6) & 3);
			break;
		
#ifdef __PCA_HAS_CHANNEL2
		case PCA_CHANNEL2:
			bits = (PCA_PWM_Bits) ((PCA_PWM2 >> 6) & 3);
			break;
#endif // __PCA_HAS_CHANNEL2
		
#ifdef __PCA_HAS_CHANNEL3
		case PCA_CHANNEL3:
			bits = (PCA_PWM_Bits) ((PCA_PWM3 >> 6) & 3);
			break;
#endif // __PCA_HAS_CHANNEL3
		}
	}
	
	uint16_t maxValue = 0;
	
	switch (bits) {
	case PCA_8BIT_PWM:
		maxValue = 256;
		break;
	
#ifdef __PCA_HAS_6_7_BIT_PWM
	case PCA_7BIT_PWM:
		maxValue = 128;
		break;
	
	case PCA_6BIT_PWM:
		maxValue = 64;
		break;
#endif // __PCA_HAS_6_7_BIT_PWM
	
#ifdef __PCA_HAS_10BIT_PWM
	case PCA_10BIT_PWM:
		maxValue = 1024;
		break;
#endif // __PCA_HAS_10BIT_PWM
	}
	
	uint16_t reloadValue = maxValue - clocksHigh;
	uint8_t xccap = (reloadValue >> 8) & 3;
	uint8_t ccap = reloadValue & 0xff;
	// When using 10-bit PWM:
	// (xccap << 4) defines bits 9 and 8 of the reload value (XCCAPnH)
	// (xccap << 2) defines bits 9 and 8 of the comparison value (XCCAPnL)
	uint8_t pcaPwm = (bits << 6) | (xccap << 4) | (xccap << 2);
	uint8_t ccapm = __pca_ccapm(PCA_PWM, interruptTrigger);
	
	switch (channel) {
	case PCA_CHANNEL0:
		PCA_PWM0 = pcaPwm;
		
		if (initialise) {
			CCAPM0 = ccapm;
			CCAP0L = ccap;
		}
		
		CCAP0H = ccap;
		break;
		
	case PCA_CHANNEL1:
		PCA_PWM1 = pcaPwm;
		
		if (initialise) {
			CCAPM1 = ccapm;
			CCAP1L = ccap;
		}
		
		CCAP1H = ccap;
		break;
	
#ifdef __PCA_HAS_CHANNEL2
	case PCA_CHANNEL2:
		PCA_PWM2 = pcaPwm;
		
		if (initialise) {
			CCAPM2 = ccapm;
			CCAP2L = ccap;
		}
		
		CCAP2H = ccap;
		break;
#endif // __PCA_HAS_CHANNEL2
	
#ifdef __PCA_HAS_CHANNEL3
	case PCA_CHANNEL3:
		PCA_PWM3 = pcaPwm;
		
		if (initialise) {
			CCAPM3 = ccapm;
			CCAP3L = ccap;
		}
		
		CCAP3H = ccap;
		break;
#endif // __PCA_HAS_CHANNEL3
	}
}

void pca_startPwm(PCA_Channel channel, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
	__pca_configurePWM(1, channel, bits, interruptTrigger, clocksHigh);
}

void pca_setPwmDutyCycle(PCA_Channel channel, uint16_t clocksHigh) {
	__pca_configurePWM(0, channel, 0, PCA_EDGE_NONE, clocksHigh);
}

void pca_startTimer(PCA_Channel channel, PCA_PulseOutput pulseOutput, uint16_t timerPeriod) {
	__pca_timerPeriod[channel] = timerPeriod;
	__pca_timerValue[channel] = __pca_timerPeriod[channel];
	uint8_t ccapm = (pulseOutput == PCA_OUTPUT_ENABLE) ? PCA_PULSE : PCA_TIMER;
	__pca_channelMode[channel] = ccapm;
	
	switch (channel) {
	case PCA_CHANNEL0:
		CCAPM0 = ccapm;
		CCAP0L = __pca_timerValue[channel] & 0xff;
		CCAP0H = __pca_timerValue[channel] >> 8;
		break;
		
	case PCA_CHANNEL1:
		CCAPM1 = ccapm;
		CCAP1L = __pca_timerValue[channel] & 0xff;
		CCAP1H = __pca_timerValue[channel] >> 8;
		break;
		
#ifdef __PCA_HAS_CHANNEL2
	case PCA_CHANNEL2:
		CCAPM2 = ccapm;
		CCAP2L = __pca_timerValue[channel] & 0xff;
		CCAP2H = __pca_timerValue[channel] >> 8;
		break;
#endif // __PCA_HAS_CHANNEL2
		
#ifdef __PCA_HAS_CHANNEL3
	case PCA_CHANNEL3:
		CCAPM3 = ccapm;
		CCAP3L = __pca_timerValue[channel] & 0xff;
		CCAP3H = __pca_timerValue[channel] >> 8;
		break;
#endif // __PCA_HAS_CHANNEL3
	}
}
