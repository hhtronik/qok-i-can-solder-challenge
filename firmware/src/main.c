/**
 * I.CAN.SOLDER SMD Challenge firmware
 */
/* SPDX-License-Identifier: GPL-3.0-only */
/* Copyright © 2020 Staudt Technologies GmbH / Yannic Staudt */

#include <stdint.h>
#include <stddef.h>
#include "stm8s003.h"
#include "systick.h"

//--------------------------------------------------------------
// type definitions and configuration
typedef void (*setledmethod_t)( uint8_t );

// (in ms)
#define FLASH_DURATION 2

#define GLITTER_DELAY_ON_FACTOR 7
#define GLITTER_DELAY_OFF_FACTOR 3

// settings for the auto-wakeup-unit:
// (APR = 22; AWUTB = 15) ~= 14 seconds interval
#define POWER_SAVE_AWU_APR 22
#define POWER_SAVE_AWU_AWUTB 15

// morse stuff

#define MORSE_TIME_UNIT ((uint32_t)(250 * 125))
#define MORSE_DOT MORSE_TIME_UNIT
#define MORSE_DASH (3 * MORSE_TIME_UNIT)
#define MORSE_SYMBOL_SPACE MORSE_TIME_UNIT
#define MORSE_LETTER_SPACE (3 * MORSE_TIME_UNIT - MORSE_SYMBOL_SPACE)
#define MORSE_WORD_SPACE (7 * MORSE_TIME_UNIT - MORSE_LETTER_SPACE)

// ... --- .-.. -.. . .-. .. -. --. / .-. --- -.-. -.- ... / -....- / .... .... - .-. --- -. .. -.- / ... -- -.. / -.-. .... .- .-.. .-.. . -. --. .
const uint8_t message[] = {
  0, 0, 0,  2,
  1, 1, 1,  2,
  0, 1, 0, 0,  2,
  1, 0, 0,  2,
  0,  2,
  0, 1, 0,  2,
  0, 0,  2,
  1, 0,  2,
  1, 1, 0,  2,
  3,
  0, 1, 0,  2,
  1, 1, 1,  2,
  1, 0, 1, 0,  2,
  1, 0, 1,  2,
  0, 0, 0,  2,
  3,
  1, 0, 0, 0, 0, 1,  2,
  3,
  0, 0, 0, 0,  2,
  0, 0, 0, 0,  2,
  1,  2,
  0, 1, 0,  2,
  1, 1, 1,  2,
  1, 0,  2,
  0, 0,  2,
  1, 0, 1,  2,
  3,
  0, 0, 0,  2,
  1, 1,  2,
  1, 0, 0,  2,
  3,
  1, 0, 1, 0,  2,
  0, 0, 0, 0,  2,
  0, 1,  2,
  0, 1, 0, 0,  2,
  0, 1, 0, 0,  2,
  0,  2,
  1, 0,  2,
  1, 1, 0,  2,
  0,  2
};

//--------------------------------------------------------------
// fn/method prototypes
void init_sysclock(void);
void init_AWU(void);
void init_low_power(void);
void init_gpio(void);
void flash_led(setledmethod_t ledMethod);
void glitter_led(setledmethod_t ledOnMethod, uint16_t onDelay, setledmethod_t ledOffMethod, uint16_t offDelay);

//--------------------------------------------------------------
// helper methods to set the LED outputs
// inverts the set value as the LEDs are in a low side switch configuration
void set_led_powergood(uint8_t value) { PA_ODR_bit.ODR3 = (value == 1) ? LOW : HIGH; }
void set_led_1206(uint8_t value)      { PC_ODR_bit.ODR3 = (value == 1) ? LOW : HIGH; }
void set_led_0805(uint8_t value)      { PC_ODR_bit.ODR4 = (value == 1) ? LOW : HIGH; }
void set_led_0603(uint8_t value)      { PC_ODR_bit.ODR5 = (value == 1) ? LOW : HIGH; }
void set_led_0402(uint8_t value)      { PC_ODR_bit.ODR6 = (value == 1) ? LOW : HIGH; }
void set_led_0201(uint8_t value)      { PC_ODR_bit.ODR7 = (value == 1) ? LOW : HIGH; }
void set_led_01005(uint8_t value)     { PD_ODR_bit.ODR2 = (value == 1) ? LOW : HIGH; }

void set_leds_all(uint8_t value)
{  
  set_led_1206(value);
  set_led_0805(value);
  set_led_0603(value);
  set_led_0402(value);
  set_led_0201(value);
  set_led_01005(value);
}

void animation_break_flash_all()
{
  for(uint8_t step = 0; step < 6; step++)
  {
    set_leds_all(HIGH);
    delay(20000);
    set_leds_all(LOW);
    delay(60000);
  }
}

// maybe use a random seed later?
volatile uint16_t _rnd_cnt16 = 91;

// simple 16bit PRNG
static uint16_t prng_lfsr16(void)
{

  return (_rnd_cnt16 = (_rnd_cnt16 >> 1) ^ (-(_rnd_cnt16 & 1) & 0xB400));
}

static void random_set_led(setledmethod_t ledSetMethod)
{
  uint8_t value = (uint8_t)prng_lfsr16();

  ledSetMethod(value & 1);
}

static void  random_set_all_led()
{
  random_set_led(set_led_1206);
  random_set_led(set_led_0805);
  random_set_led(set_led_0603);
  random_set_led(set_led_0402);
  random_set_led(set_led_0201);
  random_set_led(set_led_01005);
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

  uint8_t step = 0;

  init_gpio();

  // intro  
  set_led_powergood(HIGH);  // show power is there

  // switch on all leds slowly
  set_led_01005(HIGH);
  delay(60000);
  set_led_0201(HIGH);
  delay(60000);
  set_led_0402(HIGH);
  delay(60000);
  set_led_0603(HIGH);
  delay(60000);
  set_led_0805(HIGH);
  delay(60000);
  set_led_1206(HIGH);
  delay(60000);

  animation_break_flash_all();

  // binary counter
  for(step = 0; step <= 64; step++)
  {
    set_led_01005((step & 32) >> 5);
    set_led_0201((step & 16) >> 4);
    set_led_0402((step & 8) >> 3);
    set_led_0603((step & 4) >> 2);
    set_led_0805((step & 2) >> 1);
    set_led_1206((step & 1) >> 0);
    delay(20000);
  }

  animation_break_flash_all();

  uint8_t stepEven = 0;

  for(uint8_t mod = 1; mod <= 6; mod++)
  {
    for(step = 0; step < 10; step++)
    {
      stepEven = (step % 2);
      set_led_01005((6 % mod) == stepEven);
      set_led_0201((5 % mod) == stepEven);
      set_led_0402((4 % mod) == stepEven);
      set_led_0603((3 % mod) == stepEven);
      set_led_0805((2 % mod) == stepEven);
      set_led_1206((1 % mod) == stepEven);
      delay(60000);      
    }
  }

  animation_break_flash_all();

  /*or(step = 0; step < 6; step++)
  {
    set_led_01005(HIGH);
    set_led_0201(LOW);
    set_led_0402(HIGH);
    set_led_0603(LOW);
    set_led_0805(HIGH);
    set_led_1206(LOW);
    delay(60000);
    set_led_01005(LOW);
    set_led_0201(HIGH);
    set_led_0402(LOW);
    set_led_0603(HIGH);
    set_led_0805(LOW);
    set_led_1206(HIGH);
    delay(60000);
  }

  for(step = 0; step < 6; step++)
  {
    set_leds_all(HIGH);
    delay(20000);
    set_leds_all(LOW);
    delay(60000);
  }*/



  // send morse codes
  for(step = 0; step < sizeof(message) / sizeof(uint8_t); step++)
  {
    
    switch (message[step])
    {
    // DOT
    case 0:
      set_led_0805(HIGH);
      delay(MORSE_DOT);
      set_led_0805(LOW);
      delay(MORSE_SYMBOL_SPACE);
      break;

    // DASH
    case 1:
      set_led_0805(HIGH);
      delay(MORSE_DASH);
      set_led_0805(LOW);
      delay(MORSE_SYMBOL_SPACE);
      break;
    
    // character break
    case 2:
      delay(MORSE_LETTER_SPACE);
      break;
    
    // word break
    case 3:

      delay(MORSE_WORD_SPACE);
      break;
    
    // skip over other erroneous entries...
    default:
      break;
    }
  }  

  set_leds_all(LOW);

  animation_break_flash_all();

  // random pixels
  for(step = 0; step < 255; step++)
  {
    random_set_all_led();
    delay(10000);
  }

  animation_break_flash_all();

  // "glitter effect"
  // sequentially and overlapping switching through the LEDs
  int16_t onDelay, offDelay;
  for(step = 0; step < 20; step++)
  {
    onDelay = GLITTER_DELAY_ON_FACTOR * step * 125;
    offDelay = GLITTER_DELAY_OFF_FACTOR * step * 125;
    glitter_led(set_led_1206, onDelay, set_led_01005, offDelay);
    glitter_led(set_led_0805, onDelay, set_led_1206, offDelay);
    glitter_led(set_led_0603, onDelay, set_led_0805, offDelay);
    glitter_led(set_led_0402, onDelay, set_led_0603, offDelay);
    glitter_led(set_led_0201, onDelay, set_led_0402, offDelay);
    glitter_led(set_led_01005, onDelay, set_led_0201, offDelay);
  }

  for(step = 20; step > 1; step--)
  {
    onDelay = GLITTER_DELAY_ON_FACTOR * step * 125;
    offDelay = GLITTER_DELAY_OFF_FACTOR * step * 125;
    glitter_led(set_led_1206, onDelay, set_led_01005, offDelay);
    glitter_led(set_led_0805, onDelay, set_led_1206, offDelay);
    glitter_led(set_led_0603, onDelay, set_led_0805, offDelay);
    glitter_led(set_led_0402, onDelay, set_led_0603, offDelay);
    glitter_led(set_led_0201, onDelay, set_led_0402, offDelay);
    glitter_led(set_led_01005, onDelay, set_led_0201, offDelay);
  }

  // make sure all leds are off
  set_leds_all(LOW);

  for(step = 0; step < 8; step++)
  {
    // switch off again
    set_led_powergood(HIGH); 
    delayms(100);
    set_led_powergood(LOW);
    delayms(500);
  } 
  
  // switch off again
  set_led_powergood(LOW); 

  step = 0;

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

    // make sure all leds are off before going to sleep
    set_leds_all(LOW);

    // go to sleep / active halt until the AWU pokes us awake
    __halt();
  }
}

void init_gpio(void)
{
  //
  // to avoid floating pins toggling from static
  // we first set them all to be inputs with internal pull up
  // configuration of the outputs is done laiter
  PA_DDR = 0; PA_CR1 = 255;
  PB_DDR = 0; PB_CR1 = 255;
  PC_DDR = 0; PC_CR1 = 255;
  PD_DDR = 0; PD_CR1 = 255;

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
  // this sets the timeout (given the +-12% precision of the LSI _/\Ö/\_)
  AWU_APR_bit.APR = POWER_SAVE_AWU_APR;
  AWU_TB_bit.AWUTB = POWER_SAVE_AWU_AWUTB;

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
  CLK_PCKENR1_bit.PCKEN17 = 0; // TIM1
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

//
// flashes the led for FLASH_DURATION ms
void flash_led(setledmethod_t ledMethod)
{
  ledMethod(HIGH);
  delayms(FLASH_DURATION);
  ledMethod(LOW);
}

//
// uses ledOnMethod and ledOffMethod to implement a "glitter effect"
// when called in sequence
void glitter_led(setledmethod_t ledOnMethod, uint16_t onDelay, setledmethod_t ledOffMethod, uint16_t offDelay)
{
  ledOnMethod(HIGH);
  delay(onDelay);
  ledOffMethod(LOW);
  delay(offDelay);
}

//--------------------------------------------------------------
// IRQ prototypes
//  /!\ SDCC required they are defined in the same file as main()
// /_!_\ Actual implementation can be spread over the application then.
void TIM4_UIF_IRQHandler() __interrupt(ISRV_TIM4);

//
// the auto-wakeup counter runs only when the device is in (active) halt
// mode and the auto-wakeup unit is clocked and enabled
// the counter is automatically reset when the device (re)enters halt mode
// clearing the interrupt flag is mandatory however so we don't hang in the
// ISR
void AWU_IRQHandler() __interrupt(ISRV_AWU)
{    
    volatile uint8_t reg;
    reg = AWU_CSR1; // reading the register to clear the interrupt flag
}
