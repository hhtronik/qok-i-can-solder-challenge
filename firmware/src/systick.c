/* SPDX-License-Identifier: GPL-3.0-only */
/* Copyright © 2020 Staudt Technologies GmbH / Yannic Staudt */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "stm8s003.h"
#include "systick.h"


// enable TIM4 etc
void systick_enable( void )
{
  // TIM4 configuration:
  // 
  // TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM4 counter
  // clock used is 16 MHz / 128 = 125000 Hz
  //
  // With 125000 Hz we can generate time base:
  //  max time base is 2.048 ms if TIM4_PERIOD = 255 --> (255 + 1) / 125000 = 2.048 ms
  //  min time base is 0.016 ms if TIM4_PERIOD = 1   --> (  1 + 1) / 125000 = 0.016 ms
  //
  // For 1 ms interrupts
  // => TIM4_PERIOD = (0.001 * 125000 - 1) = 124    
  
  // configure TIM4 for 1ms interrupt
  TIM4_PSCR = 0x07;           // Prescaler = 128
  TIM4_ARR = 124;             // TIM4 overflow in 1.0008ms
  TIM4_IER_bit.UIE = 1;       // Update interrupt enable
  TIM4_EGR_bit.UG = 1;        // Generate UEV (update event) to reload TIM4 and set the prescaler
  TIM4_CR1_bit.CEN = 1;       // start the counter
}
 
volatile uint32_t systemMillis = 0;

void TIM4_UIF_IRQHandler() __interrupt(ISRV_TIM4)
{
  systemMillis++;   
  TIM4_SR1 &= ~(1 << 0); // Clear TIM4 update interrupt flag
} 

//
// just some dumb "active wait" down-counting at CPU execution speed...
void delay(uint32_t n)
{
  while(n-- > 0) 
    __no_operation();
}

//
// wait until the system clock reached a barrier
void delayms(uint16_t delay)
{
  uint32_t start = systemMillis;  
  while(systemMillis - start < delay)
  {
    __wait_for_interrupt();
  }
}

//
// return the current system millis runtime
uint32_t millis( void )
{
  return systemMillis;
}