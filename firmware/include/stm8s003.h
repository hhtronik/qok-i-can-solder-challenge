/* SPDX-License-Identifier: GPL-3.0-only */
/* Copyright © 2020 Staudt Technologies GmbH / Yannic Staudt */

#ifndef STM8S003_H
#define STM8S003_H

#include "macros.h"
#include <stdint.h>

#define LOW   0
#define HIGH  1

/**
 * Port structs
 */

typedef struct
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} reg_odr_bits;

typedef struct
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} reg_idr_bits;

typedef struct
{
  unsigned char DDR0        : 1;
  unsigned char DDR1        : 1;
  unsigned char DDR2        : 1;
  unsigned char DDR3        : 1;
  unsigned char DDR4        : 1;
  unsigned char DDR5        : 1;
  unsigned char DDR6        : 1;
  unsigned char DDR7        : 1;
} reg_ddr_bits;

typedef struct
{
  unsigned char C10         : 1;
  unsigned char C11         : 1;
  unsigned char C12         : 1;
  unsigned char C13         : 1;
  unsigned char C14         : 1;
  unsigned char C15         : 1;
  unsigned char C16         : 1;
  unsigned char C17         : 1;
} reg_cr1_bits;

typedef struct
{
  unsigned char C20         : 1;
  unsigned char C21         : 1;
  unsigned char C22         : 1;
  unsigned char C23         : 1;
  unsigned char C24         : 1;
  unsigned char C25         : 1;
  unsigned char C26         : 1;
  unsigned char C27         : 1;
} reg_cr2_bits;

/* PORT A */
#define PA_ODR                          _SFR_(0x00)
#define PA_IDR                          _SFR_(0x01)
#define PA_DDR                          _SFR_(0x02)
#define PA_CR1                          _SFR_(0x03)
#define PA_CR2                          _SFR_(0x04)

#define PA_ODR_bit                      _SFR_STRUCT_(0x00, reg_odr_bits)
#define PA_IDR_bit                      _SFR_STRUCT_(0x01, reg_idr_bits)
#define PA_DDR_bit                      _SFR_STRUCT_(0x02, reg_ddr_bits)
#define PA_CR1_bit                      _SFR_STRUCT_(0x03, reg_cr1_bits)
#define PA_CR2_bit                      _SFR_STRUCT_(0x04, reg_cr2_bits)

/* PORT B */
#define PB_ODR                          _SFR_(0x05)
#define PB_IDR                          _SFR_(0x06)
#define PB_DDR                          _SFR_(0x07)
#define PB_CR1                          _SFR_(0x08)
#define PB_CR2                          _SFR_(0x09)

#define PB_ODR_bit                      _SFR_STRUCT_(0x05, reg_odr_bits)
#define PB_IDR_bit                      _SFR_STRUCT_(0x06, reg_idr_bits)
#define PB_DDR_bit                      _SFR_STRUCT_(0x07, reg_ddr_bits)
#define PB_CR1_bit                      _SFR_STRUCT_(0x08, reg_cr1_bits)
#define PB_CR2_bit                      _SFR_STRUCT_(0x09, reg_cr2_bits)

/* PORT C */
#define PC_ODR                          _SFR_(0x0A)
#define PC_IDR                          _SFR_(0x0B)
#define PC_DDR                          _SFR_(0x0C)
#define PC_CR1                          _SFR_(0x0D)
#define PC_CR2                          _SFR_(0x0E)

#define PC_ODR_bit                      _SFR_STRUCT_(0x0A, reg_odr_bits)
#define PC_IDR_bit                      _SFR_STRUCT_(0x0B, reg_idr_bits)
#define PC_DDR_bit                      _SFR_STRUCT_(0x0C, reg_ddr_bits)
#define PC_CR1_bit                      _SFR_STRUCT_(0x0D, reg_cr1_bits)
#define PC_CR2_bit                      _SFR_STRUCT_(0x0E, reg_cr2_bits)

/* PORT D */
#define PD_ODR                          _SFR_(0x0F)
#define PD_IDR                          _SFR_(0x10)
#define PD_DDR                          _SFR_(0x11)
#define PD_CR1                          _SFR_(0x12)
#define PD_CR2                          _SFR_(0x13)

#define PD_ODR_bit                      _SFR_STRUCT_(0x0F, reg_odr_bits)
#define PD_IDR_bit                      _SFR_STRUCT_(0x10, reg_idr_bits)
#define PD_DDR_bit                      _SFR_STRUCT_(0x11, reg_ddr_bits)
#define PD_CR1_bit                      _SFR_STRUCT_(0x12, reg_cr1_bits)
#define PD_CR2_bit                      _SFR_STRUCT_(0x13, reg_cr2_bits)

/* Flash */

typedef struct
{
  unsigned char FIX         : 1;
  unsigned char IE          : 1;
  unsigned char AHALT       : 1;
  unsigned char HALT        : 1;
} reg_flash_CR1;

#define FLASH_CR1                       _SFR_(0x5a)
#define FLASH_CR1_bit                   _SFR_STRUCT_(0x5a, reg_flash_CR1)

typedef struct
{
  unsigned char PRG         : 1;
  unsigned char             : 3;
  unsigned char FPRG        : 1;
  unsigned char ERASE       : 1;
  unsigned char WPRG        : 1;
  unsigned char OPT         : 1;
} reg_flash_CR2;

#define FLASH_CR2                       _SFR_(0x5b)
#define FLASH_CR2_bit                   _SFR_STRUCT_(0x5b, reg_flash_CR2)

typedef struct
{
  unsigned char NPRG        : 1;
  unsigned char             : 3;
  unsigned char NFPRG       : 1;
  unsigned char NERASE      : 1;
  unsigned char NWPRG       : 1;
  unsigned char NOPT        : 1;
} reg_flash_NCR2;

#define FLASH_NCR2                      _SFR_(0x5c)
#define FLASH_NCR2_bit                  _SFR_STRUCT_(0x5c, reg_flash_NCR2)
#define FLASH_FPR                       _SFR_(0x5d)
#define FLASH_NFPR                      _SFR_(0x5e)

typedef struct
{
  unsigned char WR_PG_DIS     : 1;
  unsigned char PUL           : 1;
  unsigned char EOP           : 1;
  unsigned char DUL           : 1;
  unsigned char               : 2;
  unsigned char HVOFF         : 1;
} reg_flash_IAPSR;

#define FLASH_IAPSR                     _SFR_(0x5f)
#define FLASH_IAPSR_bit                 _SFR_STRUCT_(0x5f, reg_flash_IAPSR)

/* Flash program memory unprotection key register */
#define FLASH_PUKR                      _SFR_(0x62)
#define FLASH_PUKR_KEY1                 0x56
#define FLASH_PUKR_KEY2                 0xAE

/* Data EEPROM unprotection key register */
#define FLASH_DUKR                      _SFR_(0x64)
#define FLASH_DUKR_KEY1                 FLASH_PUKR_KEY2
#define FLASH_DUKR_KEY2                 FLASH_PUKR_KEY1

/* Option bytes */

#define OPT0                            (*(volatile uint8_t *)(0x4800))
#define OPT1                            (*(volatile uint8_t *)(0x4801))
#define NOPT1                           (*(volatile uint8_t *)(0x4802))
#define OPT2                            (*(volatile uint8_t *)(0x4803))
#define NOPT2                           (*(volatile uint8_t *)(0x4804))
#define OPT3                            (*(volatile uint8_t *)(0x4805))
#define NOPT3                           (*(volatile uint8_t *)(0x4806))
#define OPT4                            (*(volatile uint8_t *)(0x4807))
#define NOPT4                           (*(volatile uint8_t *)(0x4808))
#define OPT5                            (*(volatile uint8_t *)(0x4809))
#define NOPT5                           (*(volatile uint8_t *)(0x480a))

typedef struct
{
  unsigned char AFR0     : 1;
  unsigned char AFR1     : 1;
  unsigned char AFR2     : 1;
  unsigned char AFR3     : 1;
  unsigned char AFR4     : 1;
  unsigned char AFR5     : 1;
  unsigned char AFR6     : 1;
  unsigned char AFR7     : 1;
} reg_opt2;

#define OPT2_bit                        (*(volatile reg_opt2 *)(0x4803))

typedef struct
{
  unsigned char NAFR0     : 1;
  unsigned char NAFR1     : 1;
  unsigned char NAFR2     : 1;
  unsigned char NAFR3     : 1;
  unsigned char NAFR4     : 1;
  unsigned char NAFR5     : 1;
  unsigned char NAFR6     : 1;
  unsigned char NAFR7     : 1;
} reg_nopt2;

#define NOPT2_bit                        (*(volatile reg_nopt2 *)(0x4804))

/* DMA1 */
typedef struct
{
  unsigned char GEN         : 1;
  unsigned char GB          : 1;
  unsigned char TO          : 6;
} reg_DMA1_GCSR;

#define DMA1_GCSR                       _SFR_(0x70)
#define DMA1_GCSR_bit                   _SFR_STRUCT_(0x70, reg_DMA1_GCSR)


typedef struct
{
  unsigned char IFC0        : 1;
  unsigned char IFC1        : 1;
  unsigned char IFC2        : 1;
  unsigned char IFC3        : 1;
} reg_DMA1_GIR1;

#define DMA1_GIR1                       _SFR_(0x71)
#define DMA1_GIR1_bit                   _SFR_STRUCT_(0x71, reg_DMA1_GIR1)

typedef struct
{
  unsigned char EN          : 1;
  unsigned char TCIE        : 1;
  unsigned char HTIE        : 1;
  unsigned char DIR         : 1;
  unsigned char CIRC        : 1;
  unsigned char MINCDEC     : 1;
} reg__DMA1_CxCR;

typedef struct
{
  unsigned char             : 1;
  unsigned char TCIF        : 1;
  unsigned char HTIF        : 1;
  unsigned char TSIZE       : 1;
  unsigned char PL0         : 1;
  unsigned char PL1         : 1;
  unsigned char PEND        : 1;
  unsigned char BUSY        : 1;
} reg_DMA1_CxSPR
;

typedef struct
{
  unsigned char EN          : 1;
  unsigned char TCIE        : 1;
  unsigned char HTIE        : 1;
  unsigned char DIR         : 1;
  unsigned char CIRC        : 1;
  unsigned char MINCDEC     : 1;
} reg_DMA1_CxCR;

// DMA1 / Ch. 0
#define DMA1_C0CR                       _SFR_(0x75)
#define DMA1_C0CR_bit                   _SFR_STRUCT_(0x75, reg_DMA1_CxCR)
#define DMA1_C0SPR                      _SFR_(0x76)
#define DMA1_C0SPR_bit                  _SFR_STRUCT_(0x76, reg_DMA1_CxSPR)
#define DMA1_C0NDTR                     _SFR_(0x77)
#define DMA1_C0PARH                     _SFR_(0x78)
#define DMA1_C0PARL                     _SFR_(0x79)
#define DMA1_C0M0ARH                    _SFR_(0x7B)
#define DMA1_C0M0ARL                    _SFR_(0x7C)

// DMA1 / Ch. 1
#define DMA1_C1CR                       _SFR_(0x7F)
#define DMA1_C1CR_bit                   _SFR_STRUCT_(0x7F, reg_DMA1_CxCR)
#define DMA1_C1SPR                      _SFR_(0x80)
#define DMA1_C1SPR_bit                  _SFR_STRUCT_(0x80, reg_DMA1_CxSPR)
#define DMA1_C1NDTR                     _SFR_(0x81)
#define DMA1_C1PARH                     _SFR_(0x82)
#define DMA1_C1PARL                     _SFR_(0x83)
#define DMA1_C1M0ARH                    _SFR_(0x85)
#define DMA1_C1M0ARL                    _SFR_(0x86)

// DMA1 / Ch. 2
#define DMA1_C2CR                       _SFR_(0x89)
#define DMA1_C2CR_bit                   _SFR_STRUCT_(0x89, reg_DMA1_CxCR)
#define DMA1_C2SPR                      _SFR_(0x8A)
#define DMA1_C2SPR_bit                  _SFR_STRUCT_(0x89, reg_DMA1_CxSPR)
#define DMA1_C2NDTR                     _SFR_(0x8B)
#define DMA1_C2PARH                     _SFR_(0x8C)
#define DMA1_C2PARL                     _SFR_(0x8D)
#define DMA1_C2M0ARH                    _SFR_(0x8F)
#define DMA1_C2M0ARL                    _SFR_(0x90)

// DMA1 / Ch. 3
#define DMA1_C3CR                       _SFR_(0x93)
#define DMA1_C3CR_bit                   _SFR_STRUCT_(0x93, reg_DMA1_CxCR)
#define DMA1_C3SPR                      _SFR_(0x94)
#define DMA1_C3SPR_bit                  _SFR_STRUCT_(0x94, reg_DMA1_CxSPR)
#define DMA1_C3NDTR                     _SFR_(0x95)
#define DMA1_C3PARH_C3M1ARH             _SFR_(0x96)
#define DMA1_C3PARL_C3M1ARL             _SFR_(0x97)
#define DMA1_C3M0EAR                    _SFR_(0x98)
#define DMA1_C3M0ARH                    _SFR_(0x99)
#define DMA1_C3M0ARL                    _SFR_(0x9A)

/* SYSCFG */

typedef struct
{
  unsigned char SPI1_REMAP  : 1;
  unsigned char USART3TR_REMAP: 1;
  unsigned char USART3CK_REMAP: 1;
  unsigned char TIM3_CH1_REMAP: 1;
  unsigned char TIM3_CH2_REMAP: 1;
  unsigned char CCO_REMAP   : 1;
  unsigned char TIM2_CH1_REMAP: 1;
  unsigned char TIM2_CH2_REMAP: 1;
} reg_SYSCFG_RMPCR3;

#define SYSCFG_RMPCR3                   _SFR_(0x9D)
#define SYSCFG_RMPCR3_bit               _SFR_STRUCT_(0x9D, reg_SYSCFG_RMPCR3)

typedef struct
{
  unsigned char ADC1DMA_REMAP: 2;
  unsigned char TIM4DMA_REMAP: 2;
  unsigned char USART1TR_REMAP: 2;
  unsigned char USART1CK_REMAP: 1;
  unsigned char SPI1_REMAP  : 1;
} reg_SYSCFG_RMPCR1;

#define SYSCFG_RMPCR1                   _SFR_(0x9E)
#define SYSCFG_RMPCR1_bit               _SFR_STRUCT_(0x9E, reg_SYSCFG_RMPCR1)

typedef struct
{
  unsigned char ADC1TRIG_REMAP: 1;
  unsigned char TIM2TRIG_REMAP: 1;
  unsigned char TIM3TRIG_REMAP: 1;
  unsigned char TIM2TRIGLSE_REMAP: 1;
  unsigned char TIM3TRIGLSE_REMAP: 1;
  unsigned char SPI2_REMAP  : 1;
  unsigned char TIM3TRIG_REMAP2: 1;
  unsigned char TIM23BKIN_REMAP: 1;
} reg_SYSCFG_RMPCR2;

#define SYSCFG_RMPCR2                   _SFR_(0x9F)
#define SYSCFG_RMPCR2_bit               _SFR_STRUCT_(0x9F, reg_SYSCFG_RMPCR2)

/* ITC */
typedef struct
{
  unsigned char PAIS        : 2;
  unsigned char PBIS        : 2;
  unsigned char PCIS        : 2;
  unsigned char PDIS        : 2;
} reg_EXTI_CR1;

#define EXTI_CR1                        _SFR_(0xA0)
#define EXTI_CR1_bit                    _SFR_STRUCT_(0xA0, reg_EXTI_CR1)

typedef struct
{
  unsigned char PEIS        : 2;
  unsigned char TLIS        : 1;
} reg_EXTI_CR2;

#define EXTI_CR2                        _SFR_(0xA1)
#define EXTI_CR2_bit                    _SFR_STRUCT_(0xA1, reg_EXTI_CR2)

#define EXTI_CRx_PxIS_FallingEdgeAndLow     0
#define EXTI_CRx_PxIS_RisingEdgeOnly        1
#define EXTI_CRx_PxIS_FallingEdgeOnly       2
#define EXTI_CRx_PxIS_RisingAndFallingEdge  3

/* RST */

#define RST_CR                          _SFR_(0xB3)

typedef struct
{
  unsigned char WWDGF        : 1;
  unsigned char IWDGF        : 1;
  unsigned char ILLOPF       : 1;
  unsigned char SWIMF        : 1;
  unsigned char EMCF         : 1;
} reg_RST_SR;

#define RST_SR                          _SFR_(0xB1)
#define RST_SR_bit                      _SFR_STRUCT_(0xB1, reg_RST_SR)

/* Clock */

typedef struct
{
  unsigned char HSIEN       : 1;
  unsigned char HSIRDY      : 1;
  unsigned char FHWU        : 1;
  unsigned char LSIEN       : 1;
  unsigned char LSIRDY      : 1;
  unsigned char REGAH       : 1;
} reg_CLK_ICKR;

#define CLK_ICKR                        _SFR_(0xC0)
#define CLK_ICKR_bit                   _SFR_STRUCT_(0xC0, reg_CLK_ICKR)

typedef struct
{
  unsigned char HSEEN       : 1;
  unsigned char HSERDY      : 1;
} reg_CLK_ECKR;

#define CLK_ECKR                       _SFR_(0xC1)
#define CLK_ECKR_bit                   _SFR_STRUCT_(0xC1, reg_CLK_ECKR)
#define CLK_CMSR                       _SFR_(0xC3)
#define CLK_SWR                         _SFR_(0xC8)

typedef struct
{
  unsigned char SWBSY       : 1;
  unsigned char SWEN        : 1;
  unsigned char SWIEN       : 1;
  unsigned char SWIF        : 1;
} reg_CLK_SWCR;

#define CLK_SWCR                        _SFR_(0xC5)
#define CLK_SWCR_bit                    _SFR_STRUCT_(0xC5, reg_CLK_SWCR)

typedef struct
{
  unsigned char CPUDIV0       : 1;
  unsigned char CPUDIV1       : 1;
  unsigned char CPUDIV2       : 1;
  unsigned char HSIDIV0       : 1;
  unsigned char HSIDIV1       : 1;
} reg_CLK_CKDIVR;

#define CLK_CKDIVR                      _SFR_(0xC6)
#define CLK_CKDIVR_bit                  _SFR_STRUCT_(0xC6, reg_CLK_CKDIVR)

typedef struct
{
  unsigned char PCKEN10     : 1;
  unsigned char PCKEN11     : 1;
  unsigned char PCKEN12     : 1;
  unsigned char PCKEN13     : 1;
  unsigned char PCKEN14     : 1;
  unsigned char PCKEN15     : 1;
  unsigned char PCKEN16     : 1;
  unsigned char PCKEN17     : 1;
} reg_CLK_PCKENR1;

#define CLK_PCKENR1                     _SFR_(0xC7)
#define CLK_PCKENR1_bit                 _SFR_STRUCT_(0xC7, reg_CLK_PCKENR1)


typedef struct
{
  unsigned char CSSEN       : 1;
  unsigned char AUX         : 1;
  unsigned char CSSDIE      : 1;
  unsigned char CSSD        : 1;
} reg_CLK_CSSR;

#define CLK_CSSR                        _SFR_(0xC8)
#define CLK_CSSR_bit                    _SFR_STRUCT_(0xC8, reg_CLK_CSSR)


typedef struct
{
  unsigned char CCOEN       : 1;
  unsigned char CCOSEL      : 4;
  unsigned char CCORDY      : 1;
  unsigned char CCOBSY      : 1;
} reg_CLK_CCOR;

#define CLK_CCOR                        _SFR_(0xC9)
#define CLK_CCOR_bit                    _SFR_STRUCT_(0xC9, reg_CLK_CCOR)

typedef struct
{
  unsigned char PCKEN20     : 1;
  unsigned char PCKEN21     : 1;
  unsigned char PCKEN22     : 1;
  unsigned char PCKEN23     : 1;
  unsigned char PCKEN24     : 1;
  unsigned char PCKEN25     : 1;
  unsigned char PCKEN26     : 1;
  unsigned char PCKEN27     : 1;
} reg_CLK_PCKENR2;

#define CLK_PCKENR2                     _SFR_(0xCA)
#define CLK_PCKENR2_bit                 _SFR_STRUCT_(0xCA, reg_CLK_PCKENR2)

#define CLK_HSITRIMR                    _SFR_(0xCC)
#define CLK_SWIMCCR                     _SFR_(0xCD)

/* Watchdog */
#define IWDG_KR                         _SFR_(0xE0)
#define IWDG_KEY_ENABLE                 0xCC
#define IWDG_KEY_REFRESH                0xAA
#define IWDG_KEY_ACCESS                 0x55

#define IWDG_PR                         _SFR_(0xE1)
#define IWDG_RLR                        _SFR_(0xE2)

#define WWDG_CR                         _SFR_(0xD1)
#define WWDG_WR                         _SFR_(0xD2)

/* AWU */
typedef struct
{
  unsigned char MSR           : 1;
  unsigned char               : 3;
  unsigned char AWUEN         : 1;
  unsigned char AWUF          : 1;
} reg_AWU_CSR1;

#define AWU_CSR1                        _SFR_(0xF0)
#define AWU_CSR1_bit                    _SFR_STRUCT_(0xF0, reg_AWU_CSR1)

typedef struct
{
  unsigned char APR         : 6;
} reg_AWU_APR;

#define AWU_APR                         _SFR_(0xF1)
#define AWU_APR_bit                     _SFR_STRUCT_(0xF1, reg_AWU_APR)

typedef struct
{
  unsigned char AWUTB       : 4;
} reg_AWU_TB;

#define AWU_TB                          _SFR_(0xF2)
#define AWU_TB_bit                      _SFR_STRUCT_(0xF2, reg_AWU_TB)

/* Beeper */
typedef struct
{
  unsigned char MSR         : 1;
} reg_BEEP_CSR1;

#define BEEP_CSR1                       _SFR_(0xF0)
#define BEEP_CSR1_bit                   _SFR_STRUCT_(0xF0, reg_BEEP_CSR1)

typedef struct
{
  unsigned char BEEPDIV     : 5;
  unsigned char BEEPEN      : 1;
  unsigned char BEEPSEL     : 2;
} reg_BEEP_CSR2;

#define BEEP_CSR2                       _SFR_(0xF3)
#define BEEP_CSR2_bit                   _SFR_STRUCT_(0xF3, reg_BEEP_CSR2)

/* SPI1 */
typedef struct
{
  unsigned char CPHA        : 1;
  unsigned char CPOL        : 1;
  unsigned char MSTR        : 1;
  unsigned char BR          : 3;
  unsigned char SPE         : 1;
  unsigned char LSBFIRST    : 1;
} reg_SPI1_CR1;

#define SPI1_CR1                        _SFR_(0x200)
#define SPI1_CR1_bit                    _SFR_STRUCT_(0x200, reg_SPI1_CR1)

typedef struct
{
  unsigned char SSI         : 1;
  unsigned char SSM         : 1;
  unsigned char RXONLY      : 1;
  unsigned char             : 1;
  unsigned char CRCNEXT     : 1;
  unsigned char CRCEN       : 1;
  unsigned char BDOE        : 1;
  unsigned char BDM         : 1;
} reg_SPI1_CR2;

#define SPI1_CR2                        _SFR_(0x201)
#define SPI1_CR2_bit                    _SFR_STRUCT_(0x201, reg_SPI1_CR2)

typedef struct
{
  unsigned char RXDMAEN     : 1;
  unsigned char TXDMAEN     : 1;
  unsigned char             : 2;
  unsigned char WKIE        : 1;
  unsigned char ERRIE       : 1;
  unsigned char RXIE        : 1;
  unsigned char TXIE        : 1;
} reg_SPI1_ICR;

#define SPI1_ICR                        _SFR_(0x202)
#define SPI1_ICR_bit                    _SFR_STRUCT_(0x202, reg_SPI1_ICR)

typedef struct
{
  unsigned char RXNE        : 1;
  unsigned char TXE         : 1;
  unsigned char             : 1;
  unsigned char WKUP        : 1;
  unsigned char CRCERR      : 1;
  unsigned char MODF        : 1;
  unsigned char OVR         : 1;
  unsigned char BSY         : 1;
} reg_SPI1_SR;

#define SPI1_SR                         _SFR_(0x203)
#define SPI1_SR_bit                     _SFR_STRUCT_(0x203, reg_SPI1_SR)

#define SPI1_DR                         _SFR_(0x204)
#define SPI1_CRCPR                      _SFR_(0x205)
#define SPI1_RXCRCR                     _SFR_(0x206)
#define SPI1_TXCRCR                     _SFR_(0x207)

/* I2C1 */

typedef struct
{
  unsigned char PE          : 1;
  unsigned char SMBUS       : 1;
  unsigned char             : 1;
  unsigned char SMBTYPE     : 1;
  unsigned char ENARP       : 1;
  unsigned char ENPEC       : 1;
  unsigned char ENGC        : 1;
  unsigned char NOSTRETCH   : 1;
} reg_I2C1_CR1;

#define I2C1_CR1                        _SFR_(0x210)
#define I2C1_CR1_bit                    _SFR_STRUCT_(0x210, reg_I2C1_CR1)

typedef struct
{
  unsigned char START       : 1;
  unsigned char STOP        : 1;
  unsigned char ACK         : 1;
  unsigned char POS         : 1;
  unsigned char PEC         : 1;
  unsigned char ALERT       : 1;
  unsigned char             : 1;
  unsigned char SWRST       : 1;
} reg_I2C1_CR2;

#define I2C1_CR2                        _SFR_(0x211)
#define I2C1_CR2_bit                    _SFR_STRUCT_(0x211, reg_I2C1_CR2)

typedef struct
{
  unsigned char FREQ        : 6;
} reg_I2C1_FREQR;

#define I2C1_FREQR                      _SFR_(0x212)
#define I2C1_FREQR_bit                  _SFR_STRUCT_(0x212, reg_I2C1_FREQR)


typedef struct
{
  unsigned char ADD0        : 1;
  unsigned char ADD1        : 1;
  unsigned char ADD2        : 1;
  unsigned char ADD3        : 1;
  unsigned char ADD4        : 1;
  unsigned char ADD5        : 1;
  unsigned char ADD6        : 1;
  unsigned char ADD7        : 1;
} reg_I2C1_OARL;

#define I2C1_OARL                       _SFR_(0x213)
#define I2C1_OARL_bit                   _SFR_STRUCT_(0x213, reg_I2C1_OARL)

typedef struct
{
  unsigned char             : 1;
  unsigned char ADD8        : 1;
  unsigned char ADD9        : 1;
  unsigned char             : 3;
  unsigned char ADDCONF     : 1;
  unsigned char ADDMODE     : 1;
} reg_I2C1_OARH;

#define I2C1_OARH                       _SFR_(0x214)
#define I2C1_OARH_bit                   _SFR_STRUCT_(0x214, reg_I2C1_OARH)

#define I2C1_DR                         _SFR_(0x216)

typedef struct
{
  unsigned char SB          : 1;
  unsigned char ADDR        : 1;
  unsigned char BTF         : 1;
  unsigned char ADD10       : 1;
  unsigned char STOPF       : 1;
  unsigned char             : 1;
  unsigned char RXNE        : 1;
  unsigned char TXE         : 1;
} reg_I2C1_SR1;

#define I2C1_SR1                        _SFR_(0x217)
#define I2C1_SR1_bit                    _SFR_STRUCT_(0x217, reg_I2C1_SR1)

typedef struct
{
  unsigned char BERR        : 1;
  unsigned char ARLO        : 1;
  unsigned char AF          : 1;
  unsigned char OVR         : 1;
  unsigned char PECERR      : 1;
  unsigned char WUFH        : 1;
  unsigned char TIMEOUT     : 1;
  unsigned char SMBALERT    : 1;
} reg_I2C1_SR2;

#define I2C1_SR2                        _SFR_(0x218)
#define I2C1_SR2_bit                    _SFR_STRUCT_(0x218, reg_I2C1_SR2)

typedef struct
{
  unsigned char MSL         : 1;
  unsigned char BUSY        : 1;
  unsigned char TRA         : 1;
  unsigned char             : 1;
  unsigned char GENCALL     : 1;
  unsigned char SMBDEFAULT  : 1;
  unsigned char SMBHOST     : 1;
} reg_I2C1_SR3;

#define I2C1_SR3                        _SFR_(0x219)
#define I2C1_SR3_bit                    _SFR_STRUCT_(0x219, reg_I2C1_SR3)

typedef struct
{
  unsigned char ITERREN     : 1;
  unsigned char ITEVTEN     : 1;
  unsigned char ITBUFEN     : 1;
  unsigned char DMAEN       : 1;
  unsigned char LAST        : 1;
} reg_I2C1_ITR;

#define I2C1_ITR                        _SFR_(0x21A)
#define I2C1_ITR_bit                    _SFR_STRUCT_(0x21A, reg_I2C1_ITR)

typedef struct
{
  unsigned char CCR0        : 1;
  unsigned char CCR1        : 1;
  unsigned char CCR2        : 1;
  unsigned char CCR3        : 1;
  unsigned char CCR4        : 1;
  unsigned char CCR5        : 1;
  unsigned char CCR6        : 1;
  unsigned char CCR7        : 1;
} reg_I2C1_CCRL;

#define I2C1_CCRL                       _SFR_(0x21B)
#define I2C1_CCRL_bit                   _SFR_STRUCT_(0x21B, reg_I2C1_CCRL)

typedef struct
{
  unsigned char CCR8        : 1;
  unsigned char CCR9        : 1;
  unsigned char CCR10       : 1;
  unsigned char CCR11       : 1;
  unsigned char             : 2;
  unsigned char DUTY        : 1;
  unsigned char F_S         : 1;
} reg_I2C1_CCRH;

#define I2C1_CCRH                       _SFR_(0x21C)
#define I2C1_CCRH_bit                   _SFR_STRUCT_(0x21C, reg_I2C1_CCRH)

typedef struct
{
  unsigned char TRISE       : 6;
} reg_I2C1_TRISER;

#define I2C1_TRISER                     _SFR_(0x21D)
#define I2C1_TRISER_bit                 _SFR_STRUCT_(0x21D, reg_I2C1_TRISER)

#define I2C1_PECR                       _SFR_(0x21E)

/* USART1 */

typedef struct
{
  unsigned char PE          : 1;
  unsigned char FE          : 1;
  unsigned char NF          : 1;
  unsigned char OR          : 1;
  unsigned char IDLE        : 1;
  unsigned char RXNE        : 1;
  unsigned char TC          : 1;
  unsigned char TXE         : 1;
} reg_USART1_SR;

#define USART1_SR                       _SFR_(0x230)
#define USART1_SR_bit                   _SFR_STRUCT_(0x230, reg_USART1_SR)

#define USART1_DR                       _SFR_(0x231)

typedef struct
{
  unsigned char USART_DIV4  : 1;
  unsigned char USART_DIV5  : 1;
  unsigned char USART_DIV6  : 1;
  unsigned char USART_DIV7  : 1;
  unsigned char USART_DIV8  : 1;
  unsigned char USART_DIV9  : 1;
  unsigned char USART_DIV10 : 1;
  unsigned char USART_DIV11 : 1;
} reg_USART1_BRR1;

#define USART1_BRR1                     _SFR_(0x232)
#define USART1_BRR1_bit                 _SFR_STRUCT_(0x232, reg_USART1_BRR1)

typedef struct
{
  unsigned char USART_DIV0  : 1;
  unsigned char USART_DIV1  : 1;
  unsigned char USART_DIV2  : 1;
  unsigned char USART_DIV3  : 1;
  unsigned char USART_DIV12 : 1;
  unsigned char USART_DIV13 : 1;
  unsigned char USART_DIV14 : 1;
  unsigned char USART_DIV15 : 1;
} reg_USART1_BRR2;

#define USART1_BRR2                     _SFR_(0x233)
#define USART1_BRR2_bit                 _SFR_STRUCT_(0x233, reg_USART1_BRR2)

typedef struct
{
  unsigned char PIEN        : 1;
  unsigned char PS          : 1;
  unsigned char PCEN        : 1;
  unsigned char WAKE        : 1;
  unsigned char M           : 1;
  unsigned char USARTD      : 1;
  unsigned char T8          : 1;
  unsigned char R8          : 1;
} reg_USART1_CR1;

#define USART1_CR1                      _SFR_(0x234)
#define USART1_CR1_bit                  _SFR_STRUCT_(0x234, reg_USART1_CR1)

typedef struct
{
  unsigned char SBK         : 1;
  unsigned char RWU         : 1;
  unsigned char REN         : 1;
  unsigned char TEN         : 1;
  unsigned char ILIEN       : 1;
  unsigned char RIEN        : 1;
  unsigned char TCIEN       : 1;
  unsigned char TIEN        : 1;
} reg_USART1_CR2;

#define USART1_CR2                      _SFR_(0x235)
#define USART1_CR2_bit                  _SFR_STRUCT_(0x235, reg_USART1_CR2)

typedef struct
{
  unsigned char LBCL        : 1;
  unsigned char CPHA        : 1;
  unsigned char CPOL        : 1;
  unsigned char CLKEN       : 1;
  unsigned char STOP0       : 1;
  unsigned char STOP1       : 1;
} reg_USART1_CR3;

#define USART1_CR3                      _SFR_(0x236)
#define USART1_CR3_bit                  _SFR_STRUCT_(0x236, reg_USART1_CR3)

typedef struct
{
  unsigned char ADD0        : 1;
  unsigned char ADD1        : 1;
  unsigned char ADD2        : 1;
  unsigned char ADD3        : 1;
} reg_USART1_CR4;

#define USART1_CR4                      _SFR_(0x237)
#define USART1_CR4_bit                  _SFR_STRUCT_(0x237, reg_USART1_CR4)

typedef struct
{
  unsigned char EIE         : 1;
  unsigned char IREN        : 1;
  unsigned char IRLP        : 1;
  unsigned char HDSEL       : 1;
  unsigned char NACK        : 1;
  unsigned char SCEN        : 1;
  unsigned char DMAR        : 1;
  unsigned char DMAT        : 1;
} reg_USART1_CR5;

#define USART1_CR5                      _SFR_(0x238)
#define USART1_CR5_bit                  _SFR_STRUCT_(0x238, reg_USART1_CR5)

#define USART1_GTR                      _SFR_(0x239)
#define USART1_PSCR                     _SFR_(0x23A)

/* TIM1 */

typedef struct
{
  unsigned char CEN         : 1;
  unsigned char UDIS        : 1;
  unsigned char URS         : 1;
  unsigned char OPM         : 1;
  unsigned char DIR         : 1;
  unsigned char CMS         : 2;
  unsigned char ARPE        : 1;
} reg_TIM1_CR1;

#define TIM1_CR1                        _SFR_(0x250)
#define TIM1_CR1_bit                    _SFR_STRUCT_(0x250, reg_TIM1_CR1)


typedef struct
{
  unsigned char CCPC        : 1;
  unsigned char             : 1;
  unsigned char COMS        : 1;
  unsigned char             : 1;
  unsigned char MMS         : 3;
} reg_TIM1_CR2;

#define TIM1_CR2                        _SFR_(0x251)
#define TIM1_CR2_bit                    _SFR_STRUCT_(0x251, reg_TIM1_CR2)

#define TIM1_SMCR                       _SFR_(0x252)
#define TIM1_ETR                        _SFR_(0x253)
#define TIM1_IER                        _SFR_(0x254)
#define TIM1_SR1                        _SFR_(0x255)
#define TIM1_SR2                        _SFR_(0x256)
#define TIM1_EGR                        _SFR_(0x257)


typedef struct
{
  unsigned char CC1S         : 2;
  unsigned char OC1FE        : 1;
  unsigned char OC1PE        : 1;
  unsigned char OC1M         : 3;
  unsigned char OC1CE        : 1;
} reg_TIM1_CCMR1_out;


typedef struct
{
  unsigned char CC1S         : 2;
  unsigned char IC1PSC       : 2;
  unsigned char IC1F         : 4;
} reg_TIM1_CCMR1_in;


#define TIM1_CCMR1                      _SFR_(0x258)
#define TIM1_CCMR1_out_bit              _SFR_STRUCT_(0x258, reg_TIM1_CCMR1_out)
#define TIM1_CCMR1_int_bit              _SFR_STRUCT_(0x258, reg_TIM1_CCMR1_in)

#define TIM1_CCMR2                      _SFR_(0x259)
#define TIM1_CCMR3                      _SFR_(0x25A)
#define TIM1_CCMR4                      _SFR_(0x25B)

typedef struct
{
  unsigned char CC1E        : 1;
  unsigned char CC1P        : 1;
  unsigned char CC1NE       : 1;
  unsigned char CC1NP       : 1;
  unsigned char CC2E        : 1;
  unsigned char CC2P        : 1;
  unsigned char CC2NE       : 1;
  unsigned char CC2NP       : 1;
} reg_TIM1_CCER1;

#define TIM1_CCER1                      _SFR_(0x25C)
#define TIM1_CCER1_bit                  _SFR_STRUCT_(0x25C, reg_TIM1_CCER1)

#define TIM1_CCER2                      _SFR_(0x25D)
#define TIM1_CNTRH                      _SFR_(0x25E)
#define TIM1_CNTRL                      _SFR_(0x25F)
#define TIM1_PSCRH                      _SFR_(0x260)
#define TIM1_PSCRL                      _SFR_(0x261)
#define TIM1_ARRH                       _SFR_(0x262)
#define TIM1_ARRL                       _SFR_(0x263)
#define TIM1_RCR                        _SFR_(0x264)
#define TIM1_CCR1H                      _SFR_(0x265)
#define TIM1_CCR1L                      _SFR_(0x266)
#define TIM1_CCR2H                      _SFR_(0x267)
#define TIM1_CCR2L                      _SFR_(0x268)
#define TIM1_CCR3H                      _SFR_(0x269)
#define TIM1_CCR3L                      _SFR_(0x26A)
#define TIM1_CCR4H                      _SFR_(0x26B)
#define TIM1_CCR4L                      _SFR_(0x26C)

typedef struct
{
  unsigned char LOCK        : 2;
  unsigned char OSSI        : 1;
  unsigned char OSSR        : 1;
  unsigned char BKE         : 1;
  unsigned char BKP         : 1;
  unsigned char AOE         : 1;
  unsigned char MOE         : 1;
} reg_TIM1_BKR;

#define TIM1_BKR                        _SFR_(0x26D)
#define TIM1_BKR_bit                    _SFR_STRUCT_(0x26D, reg_TIM1_BKR)
#define TIM1_DTR                        _SFR_(0x26E)
#define TIM1_OISR                       _SFR_(0x2DF)

/* TIM2 */
#define TIM2_CR1                        _SFR_(0x300)
#define TIM2_IER                        _SFR_(0x303)
#define TIM2_SR1                        _SFR_(0x304)
#define TIM2_SR2                        _SFR_(0x305)
#define TIM2_EGR                        _SFR_(0x306)
#define TIM2_CCMR1                      _SFR_(0x307)
#define TIM2_CCMR2                      _SFR_(0x308)
#define TIM2_CCMR3                      _SFR_(0x309)
#define TIM2_CCER1                      _SFR_(0x30A)
#define TIM2_CCER2                      _SFR_(0x30B)
#define TIM2_CNTRH                      _SFR_(0x30C)
#define TIM2_CNTRL                      _SFR_(0x30D)
#define TIM2_PSCR                       _SFR_(0x30E)
#define TIM2_ARRH                       _SFR_(0x30F)
#define TIM2_ARRL                       _SFR_(0x310)
#define TIM2_CCR1H                      _SFR_(0x311)
#define TIM2_CCR1L                      _SFR_(0x312)
#define TIM2_CCR2H                      _SFR_(0x313)
#define TIM2_CCR2L                      _SFR_(0x314)
#define TIM2_CCR3H                      _SFR_(0x315)
#define TIM2_CCR3L                      _SFR_(0x316)

/* TIM4 */
typedef struct
{
  unsigned char CEN         : 1;
  unsigned char UDIS        : 1;
  unsigned char URS         : 1;
  unsigned char OPM         : 1;
  unsigned char             : 3;
  unsigned char ARPE        : 1;
} reg_TIM4_CR1;

#define TIM4_CR1                        _SFR_(0x340)
#define TIM4_CR1_bit                    _SFR_STRUCT_(0x340, reg_TIM4_CR1)


typedef struct
{
  unsigned char UIE         : 1;
  unsigned char             : 5;
  unsigned char TIE         : 1;
} reg_TIM4_IER;

#define TIM4_IER                        _SFR_(0x343)
#define TIM4_IER_bit                    _SFR_STRUCT_(0x343, reg_TIM4_IER)

typedef struct
{
  unsigned char UIF         : 1;
  unsigned char             : 5;
  unsigned char TIF         : 1;
} reg_TIM4_SR1;

#define TIM4_SR1                         _SFR_(0x344)
#define TIM4_SR1_bit                     _SFR_STRUCT_(0x344, reg_TIM4_SR1)


typedef struct
{
  unsigned char UG          : 1;
  unsigned char             : 5;
  unsigned char TG          : 1;
} reg_TIM4_EGR;

#define TIM4_EGR                        _SFR_(0x345)
#define TIM4_EGR_bit                    _SFR_STRUCT_(0x345, reg_TIM4_EGR)

#define TIM4_CNTR                       _SFR_(0x346)

typedef struct
{
  unsigned char PSC         : 4;
} reg_TIM4_PSCR;

#define TIM4_PSCR                       _SFR_(0x347)
#define TIM4_PSCR_bit                   _SFR_STRUCT_(0x347, reg_TIM4_PSCR)

#define TIM4_ARR                        _SFR_(0x348)

/* ADC1 */
#define ADC_DB0RH                       _SFR_(0x3E0)
#define ADC_DB0RL                       _SFR_(0x3E1)
#define ADC_DB1RH                       _SFR_(0x3E2)
#define ADC_DB1RL                       _SFR_(0x3E3)
#define ADC_DB2RH                       _SFR_(0x3E4)
#define ADC_DB2RL                       _SFR_(0x3E5)
#define ADC_DB3RH                       _SFR_(0x3E6)
#define ADC_DB3RL                       _SFR_(0x3E7)
#define ADC_DB4RH                       _SFR_(0x3E8)
#define ADC_DB4RL                       _SFR_(0x3E9)
#define ADC_DB5RH                       _SFR_(0x3EA)
#define ADC_DB5RL                       _SFR_(0x3EB)
#define ADC_DB6RH                       _SFR_(0x3EC)
#define ADC_DB6RL                       _SFR_(0x3ED)
#define ADC_CSR                         _SFR_(0x400)
#define ADC_CR1                         _SFR_(0x401)
#define ADC_CR2                         _SFR_(0x402)
#define ADC_CR3                         _SFR_(0x403)
#define ADC_DRH                         _SFR_(0x404)
#define ADC_DRL                         _SFR_(0x405)
#define ADC_TDRH                        _SFR_(0x406)
#define ADC_TDRL                        _SFR_(0x407)
#define ADC_HDRH                        _SFR_(0x408)
#define ADC_HDRL                        _SFR_(0x409)
#define ADC_LDRH                        _SFR_(0x40A)
#define ADC_LDRL                        _SFR_(0x40B)
#define ADC_AWSRH                       _SFR_(0x40C)
#define ADC_AWSRL                       _SFR_(0x40D)
#define ADC_AWCRH                       _SFR_(0x40E)
#define ADC_AWCRL                       _SFR_(0x40F)

/* Interrupt vectors */
#define ISRV_TLI                        0x00
#define ISRV_AWU                        0x01
#define ISRV_CLK                        0x02
#define ISRV_EXTI0_PORTA                0x03
#define ISRV_EXTI1_PORTB                0x04
#define ISRV_EXTI2_PORTC                0x05
#define ISRV_EXTI3_PORTD                0x06
#define ISRV_EXTI4_PORTE                0x07
#define ISRV_SPI                        0x0A
#define ISRV_TIM1_OVF                   0x0B
#define ISRV_TIM1_CAPCOM                0x0C
#define ISRV_TIM2_OVF                   0x0D
#define ISRV_TIM2_CAPCOM                0x0E
#define ISRV_UART1_TXC                  0x11
#define ISRV_UART1_RXF                  0x12
#define ISRV_I2C                        0x13
#define ISRV_ADC1                       0x16
#define ISRV_TIM4                       0x17
#define ISRV_FLASH                      0x18

/* CPU */
typedef struct
{
  unsigned char C           : 1;
  unsigned char Z           : 1;
  unsigned char N           : 1;
  unsigned char I0          : 1;
  unsigned char H           : 1;
  unsigned char I1          : 1;
  unsigned char             : 1;
  unsigned char V           : 1;
} reg_CPU_CCR;

#define CPU_CCR                         _MEM_(0x7F60)
#define CPU_CCR_bit                         _MEM_STRUCT_(0x7F60, reg_CPU_CCR)

typedef struct
{
  unsigned char SWD         : 1;
  unsigned char AL          : 1;
} reg_CPU_CFG_GCR;

#define CPU_CFG_GCR                         _MEM_(0x7F60)
#define CPU_CFG_GCR_bit                         _MEM_STRUCT_(0x7F60, reg_CPU_CFG_GCR)

typedef struct
{
  unsigned char VECT0SPR    : 2;
  unsigned char VECT1SPR    : 2;
  unsigned char VECT2SPR    : 2;
  unsigned char VECT3SPR    : 2;
} reg_ITC_SPR1;


#define ITC_SPR1                        _MEM_(0x7F70)
#define ITC_SPR1_bit                        _MEM_STRUCT_(0x7F70, reg_ITC_SPR1)

typedef struct
{
  unsigned char VECT4SPR    : 2;
  unsigned char VECT5SPR    : 2;
  unsigned char VECT6SPR    : 2;
  unsigned char VECT7SPR    : 2;
} reg_ITC_SPR2;

#define ITC_SPR2                        _MEM_(0x7F71)
#define ITC_SPR2_bit                        _MEM_STRUCT_(0x7F71, reg_ITC_SPR2)

typedef struct
{
  unsigned char VECT8SPR    : 2;
  unsigned char VECT9SPR    : 2;
  unsigned char VECT10SPR   : 2;
  unsigned char VECT11SPR   : 2;
} reg_ITC_SPR3;

#define ITC_SPR3                        _MEM_(0x7F72)
#define ITC_SPR3_bit                        _MEM_STRUCT_(0x7F72, reg_ITC_SPR3)

typedef struct
{
  unsigned char VECT12SPR   : 2;
  unsigned char VECT13SPR   : 2;
  unsigned char VECT14SPR   : 2;
  unsigned char VECT15SPR   : 2;
} reg_ITC_SPR4;

#define ITC_SPR4                        _MEM_(0x7F73)
#define ITC_SPR4_bit                        _MEM_STRUCT_(0x7F73, reg_ITC_SPR4)

typedef struct
{
  unsigned char VECT16SPR   : 2;
  unsigned char VECT17SPR   : 2;
  unsigned char VECT18SPR   : 2;
  unsigned char VECT19SPR   : 2;
} reg_ITC_SPR5;

#define ITC_SPR5                        _MEM_(0x7F74)
#define ITC_SPR5_bit                        _MEM_STRUCT_(0x7F74, reg_ITC_SPR5)

typedef struct
{
  unsigned char VECT20SPR   : 2;
  unsigned char VECT21SPR   : 2;
  unsigned char VECT22SPR   : 2;
  unsigned char VECT23SPR   : 2;
} reg_ITC_SPR6;

#define ITC_SPR6                        _MEM_(0x7F75)
#define ITC_SPR6_bit                        _MEM_STRUCT_(0x7F75, reg_ITC_SPR6)

typedef struct
{
  unsigned char VECT24SPR   : 2;
  unsigned char VECT25SPR   : 2;
  unsigned char VECT26SPR   : 2;
  unsigned char VECT27SPR   : 2;
} reg_ITC_SPR7;

#define ITC_SPR7                        _MEM_(0x7F76)
#define ITC_SPR7_bit                        _MEM_STRUCT_(0x7F76, reg_ITC_SPR7)

typedef struct
{
  unsigned char VECT28SPR   : 2;
  unsigned char VECT29SPR   : 2;
} reg_ITC_SPR8;

#define ITC_SPR8                        _MEM_(0x7F77)
#define ITC_SPR8_bit                        _MEM_STRUCT_(0x7F77, reg_ITC_SPR8)

/* DM */
#define DM_BK1RE        *(unsigned char*)0x7F90
#define DM_BK1RH        *(unsigned char*)0x7F91
#define DM_BK1RL        *(unsigned char*)0x7F92
#define DM_BK2RE        *(unsigned char*)0x7F93
#define DM_BK2RH        *(unsigned char*)0x7F94
#define DM_BK2RL        *(unsigned char*)0x7F95
#define DM_CR1          *(unsigned char*)0x7F96
#define DM_CR2          *(unsigned char*)0x7F97
#define DM_CSR1         *(unsigned char*)0x7F98
#define DM_CSR2         *(unsigned char*)0x7F99
#define DM_ENFCTR       *(unsigned char*)0x7F9A

/* SWIM */
#define SWIM_CSR        *(unsigned char*)0x7F80

#define __enable_interrupts()             __asm__("rim");
#define __disable_interrupts()            __asm__("sim");
#define __no_operation()                  __asm__("NOP");
#define __halt()                          __asm__("HALT");
#define __trap()                          __asm__("TRAP");
#define __wait_for_event()                __asm__("WFE");
#define __wait_for_interrupt()            __asm__("WFI");

#endif /* STM8S003_H */