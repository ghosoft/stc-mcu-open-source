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
#ifndef _GPIO_H
#define _GPIO_H

/**
 * @file gpio.h
 * 
 * GPIO abstraction layer definitions.
 * 
 * Supported MCU families: STC12, STC15, STC8A, STC8F, STC8G, STC8H.
 */

#ifdef _STC8AF_H
#define __GPIO_HAS_PORTS67
// Schmidt-trigger inputs and internal 4.1k pull-up resistors
#define __GPIO_EVOLUTION1
#endif

#ifdef _STC8G_H
// Schmidt-trigger inputs and internal 4.1k pull-up resistors
#define __GPIO_EVOLUTION1
// Slew rate control, current drive control, digital input enable
#define __GPIO_EVOLUTION2
#endif

#ifdef _STC8H_H
#define __GPIO_HAS_PORTS67
// Schmidt-trigger inputs and internal 4.1k pull-up resistors
#define __GPIO_EVOLUTION1
// Slew rate control, current drive control, digital input enable
#define __GPIO_EVOLUTION2
// Interrupt & wake-up support
#define __GPIO_EVOLUTION3
#endif

typedef enum {
	GPIO_BIDIRECTIONAL = 0,
	GPIO_PUSH_PULL = 1,
	GPIO_HIGH_IMPEDANCE = 2,
	GPIO_OPEN_DRAIN = 3,
} GpioPortMode;

typedef enum {
	GPIO_DISABLED = 0,
	GPIO_ENABLED = 1,
} GpioBoolean;

#ifdef __GPIO_EVOLUTION2
typedef enum {
	GPIO_FAST_TRANSITIONS = 0,
	GPIO_SLOW_TRANSITIONS = 1,
} GpioSlewRate;

typedef enum {
	GPIO_ENHANCED_DRIVE = 0,
	GPIO_STANDARD_DRIVE = 1,
} GpioCurrentDrive;
#endif // __GPIO_EVOLUTION2

#ifdef __GPIO_EVOLUTION3
typedef enum {
	GPIO_FALLING_EDGE = 0,
	GPIO_RISING_EDGE = 1,
	GPIO_LOW_LEVEL = 2,
	GPIO_HIGH_LEVEL = 3,
} GpioInterruptMode;
#endif // __GPIO_EVOLUTION3

typedef enum {
	GPIO_PORT0 = 0,
	GPIO_PORT1,
	GPIO_PORT2,
	GPIO_PORT3,
	GPIO_PORT4,
	GPIO_PORT5,
#ifdef __GPIO_HAS_PORTS67
	GPIO_PORT6,
	GPIO_PORT7,
#endif // __GPIO_HAS_PORTS67
} GpioPort;

typedef enum {
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
} GpioPin;

/**
 * Configuration details of a GPIO pin, or series of consecutive pins.
 * 
 * **IMPORTANT:** symbols whose names beginning with 2 underscores are 
 * used internally by the driver.
 */
typedef struct {
	GpioPort port;			/*!< GPIO port number. */
	GpioPin pin;			/*!< Index of the first pin used on the port. */
	unsigned char count;	/*!< Number of consecutive pins used on the port, 
							starting with .pin and counting up. */
	GpioPortMode portMode;			/*!< GPIO pins mode of operation. */
#ifdef __GPIO_EVOLUTION1
	GpioBoolean schmidtTrigger;	/*!< Enable Schmidt trigger. */
	GpioBoolean internalPullUp;	/*!< Enable internal 4.1k pull-up resistor. */
#endif // __GPIO_EVOLUTION1

#ifdef __GPIO_EVOLUTION2
	GpioCurrentDrive currentDrive;	/*!< Control output drive capacity. */
	GpioSlewRate slewRate;	/*!< Control output slew rate. */
	GpioBoolean digitalInput;	/*!< Enable line(s) as digital inputs. */
#endif // __GPIO_EVOLUTION2

#ifdef __GPIO_EVOLUTION3
	GpioBoolean interrupts;	/*!< Enable interrupts. */
	GpioInterruptMode interruptMode;	/*!< Type of event triggering an interrupt. */
	GpioBoolean wakeUp;	/*!< Enable wake-up interrupt. */
#endif // __GPIO_EVOLUTION3
	
	unsigned char __setMask;
	unsigned char __clearMask;
} GpioConfig;

/**
 * Convenience macros to configure an entire port and a single GPIO pin.
 */
#ifdef __GPIO_EVOLUTION1
#define DEFAULTS_EVOLUTION1 \
	.schmidtTrigger = GPIO_DISABLED, \
	.internalPullUp = GPIO_DISABLED,
#else
#define DEFAULTS_EVOLUTION1 /**/
#endif

#ifdef __GPIO_EVOLUTION2
#define DEFAULTS_EVOLUTION2 \
	.currentDrive = GPIO_STANDARD_DRIVE, \
	.slewRate = GPIO_SLOW_TRANSITIONS, \
	.digitalInput = GPIO_ENABLED,
#else
#define DEFAULTS_EVOLUTION2 /**/
#endif

#ifdef __GPIO_EVOLUTION3
#define DEFAULTS_EVOLUTION3 \
	.interrupts = GPIO_DISABLED, \
	.interruptMode = GPIO_FALLING_EDGE, \
	.wakeUp = GPIO_DISABLED,
#else
#define DEFAULTS_EVOLUTION3 /**/
#endif

#define GPIO_PORT_CONFIG(gpioPort, gpioMode) { .port = gpioPort, .pin = 0, .count = 8, .portMode = gpioMode, \
	DEFAULTS_EVOLUTION1 DEFAULTS_EVOLUTION2 DEFAULTS_EVOLUTION3 }

#define GPIO_PIN_CONFIG(gpioPort, gpioPin, gpioMode) { .port = gpioPort, .pin = gpioPin, .count = 1, .portMode = gpioMode, \
	DEFAULTS_EVOLUTION1 DEFAULTS_EVOLUTION2 DEFAULTS_EVOLUTION3 }

/**
 * Configures a GPIO pin, or series of consecutive pins.
 */
void gpio_configure(GpioConfig *config);

/**
 * Reads a GPIO pin, or series of consecutive pins.
 * 
 * When reading a series of pins, the resulting value will be shifted
 * so that bit 0 of the result corresponds to .pin in GpioConfig.
 * Bits outside of the scope defined by GpioConfig are masked off.
 */
unsigned char gpio_read(GpioConfig *config);

/**
 * Sets a GPIO pin, or series of consecutive pins.
 * 
 * When setting a series of pins, 'value' will be shifted so that its 
 * bit 0 corresponds to .pin in GpioConfig.
 * Bits outside of the scope defined by GpioConfig are masked off.
 */
void gpio_write(GpioConfig *config, unsigned char value);

#endif // _GPIO_H
