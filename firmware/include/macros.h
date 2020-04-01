/* SPDX-License-Identifier: GPL-3.0-only */
/* Copyright © 2020 Staudt Technologies GmbH / Yannic Staudt */

#ifndef __MACROS_H__
#define __MACROS_H__

#define _MEM_(mem_addr)                 (*(volatile uint8_t *)(mem_addr))
#define _MEM_STRUCT_(mem_addr, sname)   (*(volatile sname *)((mem_addr)))

#define _SFR_(mem_addr)                 (*(volatile uint8_t *)(0x5000 + (mem_addr)))
#define _SFR16_(mem_addr)               (*(volatile uint16_t *)(0x5000 + (mem_addr)))
#define _SFR_STRUCT_(mem_addr, sname)   (*(volatile sname *)(0x5000 + (mem_addr)))

#endif