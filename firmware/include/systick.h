/* SPDX-License-Identifier: GPL-3.0-only */
/* Copyright © 2020 Staudt Technologies GmbH / Yannic Staudt */

#ifndef H_SYSTICK
#define H_SYSTICK

#include <stdbool.h>

// enable TIM4 etc
void systick_enable( void );

// Delay by n milliseconds (timer based)
void delayms(uint16_t delay);

// Delay by n instructions
void delay(uint32_t n);

// get the current sys millis
uint32_t millis( void );
#endif