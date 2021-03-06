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
#include "gpio.h"

/**
 * @file gpio.c
 * 
 * GPIO abstraction layer implementation.
 */

#if defined(__GPIO_EVOLUTION1) || defined(__GPIO_EVOLUTION2) ||  defined(__GPIO_EVOLUTION3)
#define __USE_EXTENDED_SFR
#endif

inline unsigned char __gpio_setBits(unsigned char portValue, unsigned char cfgValue, GpioConfig *gpioConfig) {
	return cfgValue ? (portValue | gpioConfig->__setMask) : (portValue & gpioConfig->__clearMask);
}

inline unsigned char __isOutput(GpioConfig *gpioConfig) {
	return gpioConfig->portMode == GPIO_BIDIRECTIONAL || gpioConfig->portMode == GPIO_PUSH_PULL || gpioConfig->portMode == GPIO_OPEN_DRAIN;
}

inline unsigned char __isInput(GpioConfig *gpioConfig) {
	return gpioConfig->portMode == GPIO_BIDIRECTIONAL || gpioConfig->portMode == GPIO_HIGH_IMPEDANCE;
}

void gpio_configure(GpioConfig *gpioConfig) {
	// Pre-generate bit masks for read/write operations
	unsigned char mask = 0;
	
	for (unsigned char n = gpioConfig->count; n > 0; n--) {
		mask = mask << 1;
		mask |= 1;
	}
	
	gpioConfig->__setMask = mask << gpioConfig->pin;
	gpioConfig->__clearMask = ~gpioConfig->__setMask;
	
	switch (gpioConfig->port) {
	case GPIO_PORT0:
		P0M1 = __gpio_setBits(P0M1, gpioConfig->portMode & 2, gpioConfig);
		P0M0 = __gpio_setBits(P0M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P0NCS = __gpio_setBits(P0NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P0PU = __gpio_setBits(P0PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P0DR = __gpio_setBits(P0DR, gpioConfig->currentDrive, gpioConfig);
			P0SR = __gpio_setBits(P0SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P0IE = __gpio_setBits(P0IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P0IM1 = __gpio_setBits(P0IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P0IM0 = __gpio_setBits(P0IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P0INTF &= gpioConfig->__clearMask;
		P0INTE = __gpio_setBits(P0INTE, gpioConfig->interrupts, gpioConfig);
		P0WKUE = __gpio_setBits(P0WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;
	
	case GPIO_PORT1:
		P1M1 = __gpio_setBits(P1M1, gpioConfig->portMode & 2, gpioConfig);
		P1M0 = __gpio_setBits(P1M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P1NCS = __gpio_setBits(P1NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P1PU = __gpio_setBits(P1PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P1DR = __gpio_setBits(P1DR, gpioConfig->currentDrive, gpioConfig);
			P1SR = __gpio_setBits(P1SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P1IE = __gpio_setBits(P1IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P1IM1 = __gpio_setBits(P1IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P1IM0 = __gpio_setBits(P1IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P1INTF &= gpioConfig->__clearMask;
		P1INTE = __gpio_setBits(P1INTE, gpioConfig->interrupts, gpioConfig);
		P1WKUE = __gpio_setBits(P1WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;
	
	case GPIO_PORT2:
		P2M1 = __gpio_setBits(P2M1, gpioConfig->portMode & 2, gpioConfig);
		P2M0 = __gpio_setBits(P2M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P2NCS = __gpio_setBits(P2NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P2PU = __gpio_setBits(P2PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P2DR = __gpio_setBits(P2DR, gpioConfig->currentDrive, gpioConfig);
			P2SR = __gpio_setBits(P2SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P2IE = __gpio_setBits(P2IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P2IM1 = __gpio_setBits(P2IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P2IM0 = __gpio_setBits(P2IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P2INTF &= gpioConfig->__clearMask;
		P2INTE = __gpio_setBits(P2INTE, gpioConfig->interrupts, gpioConfig);
		P2WKUE = __gpio_setBits(P2WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;
	
	case GPIO_PORT3:
		P3M1 = __gpio_setBits(P3M1, gpioConfig->portMode & 2, gpioConfig);
		P3M0 = __gpio_setBits(P3M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P3NCS = __gpio_setBits(P3NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P3PU = __gpio_setBits(P3PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P3DR = __gpio_setBits(P3DR, gpioConfig->currentDrive, gpioConfig);
			P3SR = __gpio_setBits(P3SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P3IE = __gpio_setBits(P3IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P3IM1 = __gpio_setBits(P3IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P3IM0 = __gpio_setBits(P3IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P3INTF &= gpioConfig->__clearMask;
		P3INTE = __gpio_setBits(P3INTE, gpioConfig->interrupts, gpioConfig);
		P3WKUE = __gpio_setBits(P3WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;
	
	case GPIO_PORT4:
		P4M1 = __gpio_setBits(P4M1, gpioConfig->portMode & 2, gpioConfig);
		P4M0 = __gpio_setBits(P4M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P4NCS = __gpio_setBits(P4NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P4PU = __gpio_setBits(P4PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P4DR = __gpio_setBits(P4DR, gpioConfig->currentDrive, gpioConfig);
			P4SR = __gpio_setBits(P4SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P4IE = __gpio_setBits(P4IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P4IM1 = __gpio_setBits(P4IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P4IM0 = __gpio_setBits(P4IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P4INTF &= gpioConfig->__clearMask;
		P4INTE = __gpio_setBits(P4INTE, gpioConfig->interrupts, gpioConfig);
		P04WKUE = __gpio_setBits(P4WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;
	
	case GPIO_PORT5:
		P5M1 = __gpio_setBits(P5M1, gpioConfig->portMode & 2, gpioConfig);
		P5M0 = __gpio_setBits(P5M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P5NCS = __gpio_setBits(P5NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P5PU = __gpio_setBits(P5PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P5DR = __gpio_setBits(P5DR, gpioConfig->currentDrive, gpioConfig);
			P5SR = __gpio_setBits(P5SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P5IE = __gpio_setBits(P5IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P5IM1 = __gpio_setBits(P5IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P5IM0 = __gpio_setBits(P5IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P5INTF &= gpioConfig->__clearMask;
		P5INTE = __gpio_setBits(P5INTE, gpioConfig->interrupts, gpioConfig);
		P5WKUE = __gpio_setBits(P5WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;

#ifdef __GPIO_HAS_PORTS67
	case GPIO_PORT6:
		P6M1 = __gpio_setBits(P6M1, gpioConfig->portMode & 2, gpioConfig);
		P6M0 = __gpio_setBits(P6M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P6NCS = __gpio_setBits(P6NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P6PU = __gpio_setBits(P6PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P6DR = __gpio_setBits(P6DR, gpioConfig->currentDrive, gpioConfig);
			P6SR = __gpio_setBits(P6SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P6IE = __gpio_setBits(P6IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P6IM1 = __gpio_setBits(P6IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P6IM0 = __gpio_setBits(P6IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P6INTF &= gpioConfig->__clearMask;
		P6INTE = __gpio_setBits(P6INTE, gpioConfig->interrupts, gpioConfig);
		P6WKUE = __gpio_setBits(P6WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;
	
	case GPIO_PORT7:
		P7M1 = __gpio_setBits(P7M1, gpioConfig->portMode & 2, gpioConfig);
		P7M0 = __gpio_setBits(P7M0, gpioConfig->portMode & 1, gpioConfig);
#ifdef __USE_EXTENDED_SFR
		enableExtendedSFR();
		
#ifdef __GPIO_EVOLUTION1
		P7NCS = __gpio_setBits(P7NCS, gpioConfig->schmidtTrigger, gpioConfig);
		P7PU = __gpio_setBits(P7PU, gpioConfig->internalPullUp, gpioConfig);
#endif // __GPIO_EVOLUTION1
		
#ifdef __GPIO_EVOLUTION2
		if (__isOutput(gpioConfig)) {
			P7DR = __gpio_setBits(P7DR, gpioConfig->currentDrive, gpioConfig);
			P7SR = __gpio_setBits(P7SR, gpioConfig->slewRate, gpioConfig);
		}
		
		if (__isInput(gpioConfig)) {
			P7IE = __gpio_setBits(P7IE, gpioConfig->digitalInput, gpioConfig);
		}
#endif // __GPIO_EVOLUTION2
		
#ifdef __GPIO_EVOLUTION3
		P7IM1 = __gpio_setBits(P7IM1, gpioConfig->interruptMode & 2, gpioConfig);
		P7IM0 = __gpio_setBits(P7IM0, gpioConfig->interruptMode & 1, gpioConfig);
		P7INTF &= gpioConfig->__clearMask;
		P7INTE = __gpio_setBits(P7INTE, gpioConfig->interrupts, gpioConfig);
		P7WKUE = __gpio_setBits(P7WKUE, gpioConfig->wakeUp, gpioConfig);
#endif // __GPIO_EVOLUTION3
		
		disableExtendedSFR();
#endif // __USE_EXTENDED_SFR
		break;
#endif // __GPIO_HAS_PORTS67
	}
}

unsigned char gpio_read(GpioConfig *gpioConfig) {
	unsigned char value = 0;
	
	switch (gpioConfig->port) {
	case GPIO_PORT0:
		value = P0;
		break;
	
	case GPIO_PORT1:
		value = P1;
		break;
	
	case GPIO_PORT2:
		value = P2;
		break;
	
	case GPIO_PORT3:
		value = P3;
		break;
	
	case GPIO_PORT4:
		value = P4;
		break;
	
	case GPIO_PORT5:
		value = P5;
		break;

#ifdef __GPIO_HAS_PORTS67
	case GPIO_PORT6:
		value = P6;
		break;
	
	case GPIO_PORT7:
		value = P7;
		break;
#endif // __GPIO_HAS_PORTS67
	}
	
	return (value & gpioConfig->__setMask) >> gpioConfig->pin;
}

void gpio_write(GpioConfig *gpioConfig, unsigned char value) {
	if (gpioConfig->count == 1) {
		// In case the caller wants to set a single bit and expects
		// any non-zero value will be treated as a logical one (which
		// makes sense in C), let's make sure we do.
		value = value ? 1 : 0;
	}
	
	value = (value << gpioConfig->pin) & gpioConfig->__setMask;
	
	switch (gpioConfig->port) {
	case GPIO_PORT0:
		P0 = (P0 & gpioConfig->__clearMask) | value;
		break;
	
	case GPIO_PORT1:
		P1 = (P1 & gpioConfig->__clearMask) | value;
		break;
	
	case GPIO_PORT2:
		P2 = (P2 & gpioConfig->__clearMask) | value;
		break;
	
	case GPIO_PORT3:
		P3 = (P3 & gpioConfig->__clearMask) | value;
		break;
	
	case GPIO_PORT4:
		P4 = (P4 & gpioConfig->__clearMask) | value;
		break;
	
	case GPIO_PORT5:
		P5 = (P5 & gpioConfig->__clearMask) | value;
		break;

#ifdef __GPIO_HAS_PORTS67
	case GPIO_PORT6:
		P6 = (P6 & gpioConfig->__clearMask) | value;
		break;
	
	case GPIO_PORT7:
		P7 = (P7 & gpioConfig->__clearMask) | value;
		break;
#endif // __GPIO_HAS_PORTS67
	}
}
