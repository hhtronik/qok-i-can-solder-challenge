/**
 * I.CAN.SOLDER SMD Challenge firmware
 */
/* SPDX-License-Identifier: GPL-3.0-only */
/* Copyright © 2020 Staudt Technologies GmbH / Yannic Staudt */

#include <stdint.h>
#include <stddef.h>
#include "stm8s003.h"
#include "systick.h"

#define FLASH_DURATION 50
#define GLITTER_DELAY_ON 30
#define GLITTER_DELAY_OFF 70

//--------------------------------------------------------------
// fn/method prototypes
void init_sysclock(void);
void init_AWU(void);
void init_low_power(void);
void init_gpio(void);

typedef void (*SetLedMethod)( uint8_t );

// invert the set value as the LEDs are in a low side switch configuration
void set_led_powergood(uint8_t value) { PA_ODR_bit.ODR3 = (value == 1) ? LOW : HIGH; }
void set_led_1206(uint8_t value)      { PC_ODR_bit.ODR3 = (value == 1) ? LOW : HIGH; }
void set_led_0805(uint8_t value)      { PC_ODR_bit.ODR4 = (value == 1) ? LOW : HIGH; }
void set_led_0603(uint8_t value)      { PC_ODR_bit.ODR5 = (value == 1) ? LOW : HIGH; }
void set_led_0402(uint8_t value)      { PC_ODR_bit.ODR6 = (value == 1) ? LOW : HIGH; }
void set_led_0201(uint8_t value)      { PC_ODR_bit.ODR7 = (value == 1) ? LOW : HIGH; }
void set_led_01005(uint8_t value)     { PD_ODR_bit.ODR2 = (value == 1) ? LOW : HIGH; }

void flash_led(SetLedMethod ledMethod)
{
  ledMethod(HIGH);
  delayms(FLASH_DURATION);
  ledMethod(LOW);
}

void glitter_led(SetLedMethod ledOn, SetLedMethod ledOff)
{
  ledOn(HIGH);
  delayms(GLITTER_DELAY_ON);
  ledOff(LOW);
  delayms(GLITTER_DELAY_OFF);
}

//--------------------------------------------------------------
// main method
void main()
{
  __disable_interrupts(); // we have to disable interrupts prior to configuring some peripherals
  init_sysclock();
  systick_enable();
  init_AWU();
  init_low_power(); 
  __enable_interrupts();

  init_gpio();

  // intro
  set_led_powergood(HIGH);  // show power is there
  delayms(200);

  for(int i = 0; i < 10; i++)
  {
    glitter_led(set_led_1206, set_led_01005);
    glitter_led(set_led_0805, set_led_1206);
    glitter_led(set_led_0603, set_led_0805);
    glitter_led(set_led_0402, set_led_0603);
    glitter_led(set_led_0201, set_led_0402);
    glitter_led(set_led_01005, set_led_0201);
  }
  
  // switch off again
  set_led_powergood(LOW); 

  uint8_t step = 0;

  // main loop
  while (1)
  {
    switch (step++)
    {
    case 0:
      flash_led(set_led_1206);
      break;

    case 1:
       flash_led(set_led_0805);
      break;

    case 2:
      flash_led(set_led_0603);
      break;    
      
    case 3:
      flash_led(set_led_0402);
      break;   
      
    case 4:
      flash_led(set_led_0201);
      break;
  
    case 5:
      flash_led(set_led_01005);
      break;
    
    default:
      step = 0;
      continue;
      break;
    }


    // go to sleep / active halt until the AWU pokes us awake
    __halt();
  }
}

void init_gpio(void)
{
  // reset the GPIO just to be source
  PA_DDR = 0;
  PB_DDR = 0;
  PC_DDR = 0;
  PD_DDR = 0;

  // PA3 power good LED
  PA_ODR_bit.ODR3 = 1;  // drive high == led OFF
  PA_DDR_bit.DDR3 = 1;  // output  
  PA_CR1_bit.C13 = 1;   // push-pull mode  

  // PC3 => 1206
  PC_ODR_bit.ODR3 = 1;  // drive high == led OFF
  PC_DDR_bit.DDR3 = 1;  // output  
  PC_CR1_bit.C13 = 1;   // push-pull mode

  // PC4 => 0805
  PC_ODR_bit.ODR4 = 1;  // drive high == led OFF
  PC_DDR_bit.DDR4 = 1;  // output  
  PC_CR1_bit.C14 = 1;   // push-pull mode

  // PC5 => 0603
  PC_ODR_bit.ODR5 = 1;  // drive high == led OFF
  PC_DDR_bit.DDR5 = 1;  // output  
  PC_CR1_bit.C15 = 1;   // push-pull mode

  // PC6 => 0402
  PC_ODR_bit.ODR6 = 1;  // drive high == led OFF
  PC_DDR_bit.DDR6 = 1;  // output  
  PC_CR1_bit.C16 = 1;   // push-pull mode

  // PC7 => 0201
  PC_ODR_bit.ODR7 = 1;  // drive high == led OFF
  PC_DDR_bit.DDR7 = 1;  // output  
  PC_CR1_bit.C17 = 1;   // push-pull mode

  // PD2 => 01005
  PD_ODR_bit.ODR2 = 1;  // drive high == led OFF
  PD_DDR_bit.DDR2 = 1;  // output  
  PD_CR1_bit.C12 = 1;   // push-pull mode
}

void init_low_power(void)
{
  CLK_ICKR_bit.REGAH = 1;  // disable MVR regulator (active)-halt mode
  CLK_ICKR_bit.FHWU = 0;   // disable fast wake-up from halt
  FLASH_CR1_bit.HALT = 0;  // Switch the Flash to power down in halt state, increses wakeup by few us but saves power
  FLASH_CR1_bit.AHALT = 1; // Switch the Flash to power down in active halt state, increse wakeup by few us
}

void init_AWU(void)
{
  // this sets the timeout to ~14s +-12% (precision of the LSI _/\Ö/\_)
  AWU_APR_bit.APR = 22;
  AWU_TB_bit.AWUTB = 15;

  // enable the wake-up unit
  AWU_CSR1_bit.AWUEN = 1; 
}

void init_sysclock(void)
{
  CLK_ICKR = 0;           // Reset the Internal Clock Register.
  CLK_ICKR_bit.HSIEN = 1; // Enable the HSI (high speed internal osc.)
  CLK_ICKR_bit.LSIEN = 1; // Enable the LSI (low speed internal osc.) to allow for low power active halt
  CLK_ECKR = 0;           // Disable the external clock.

  // clock speed divider
  // 0 = System clock source /1 (16MHz from HSI)
  // 1 = System clock source /2 (8MHz from HSI)
  // 5 = System clock source /32 (0.5MHz from HSI)
  // 7 = System clock source /128 (125kHz from HSI)
  CLK_CKDIVR = 0; //  Ensure the clocks are running at full speed.

  CLK_CCOR = 0;     //  Turn off Configurable Clock Ouput.
  CLK_HSITRIMR = 0; //  Turn off any HSIU trimming.
  CLK_SWIMCCR = 0;  //  Set SWIM to run at clock / 2.
  CLK_SWR = 0xe1;   //  Use HSI as the clock source.
  CLK_SWCR = 0;     //  Reset the clock switch control register.

  CLK_SWCR_bit.SWEN = 1; //  Enable switching.
  while (CLK_SWCR_bit.SWBSY)
    ; // wait for clock switch to complete

  // setup / distribute the clock to selected peripherals
  CLK_PCKENR1 = 0;
  CLK_PCKENR1_bit.PCKEN17 = 0; // TIM1 (used as PWM driver)
  CLK_PCKENR1_bit.PCKEN16 = 0; // TIM3
  CLK_PCKENR1_bit.PCKEN15 = 0; // TIM2
  CLK_PCKENR1_bit.PCKEN14 = 1; // TIM4 (used for systick)
  CLK_PCKENR1_bit.PCKEN13 = 0; // UART1
  CLK_PCKENR1_bit.PCKEN12 = 0; // UART2
  CLK_PCKENR1_bit.PCKEN11 = 0; // SPI
  CLK_PCKENR1_bit.PCKEN10 = 0; // I2C1

  CLK_PCKENR2 = 0;
  CLK_PCKENR2_bit.PCKEN27 = 0; // Reserved
  CLK_PCKENR2_bit.PCKEN25 = 0; // Reserved
  CLK_PCKENR2_bit.PCKEN24 = 0; // Reserved
  CLK_PCKENR2_bit.PCKEN23 = 0; // ADC
  CLK_PCKENR2_bit.PCKEN22 = 1; // AWU
  CLK_PCKENR2_bit.PCKEN21 = 0; // Reserved
  CLK_PCKENR2_bit.PCKEN20 = 0; // Reserved
}

//--------------------------------------------------------------
// IRQ prototypes
//  /!\ SDCC required they are defined in the same file as main()
// /_!_\ Actual implementation can be spread over the application then.

//
// the auto-wakeup happens only when the device is actually in
// __halt() (actually active halt state which is chosen automatically)
// by the hardware when the auto-wakeup unit is enabled
void AWU_IRQHandler() __interrupt(ISRV_AWU)
{    
    volatile uint8_t reg;
    reg = AWU_CSR1; // reading the register to clear the interrupt flag
}
