/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#ifndef _TINIX_IDT_H_
#define _TINIX_IDT_H_

#include "types.h"

struct idtentry {
  uint16 offsetlow;
  uint16 segselector;
  uint8 reserved;
  uint8 flags;
  uint16 offsethigh;
} __attribute__((packed));

struct idtdesc {
  uint16 limit;
  struct idtentry * address;
} __attribute__((packed));

enum idtflag {
  IDT_FLAG_GATE_TASK          = 0x5,
  IDT_FLAG_GATE_16BIT_INTR    = 0x6,
  IDT_FLAG_GATE_16BIT_TRAP    = 0x7,
  IDT_FLAG_GATE_32BIT_INTR    = 0xe,
  IDT_FLAG_GATE_32BIT_TRAP    = 0xf,

  IDT_FLAG_RING0              = 0x00,       // (0 << 5)
  IDT_FLAG_RING1              = 0x20,       // (1 << 5)
  IDT_FLAG_RING2              = 0x40,       // (2 << 5)
  IDT_FLAG_RING3              = 0x60,       // (3 << 5)

  IDT_FLAG_PRESENT            = 0x80
};

#define IDT_FLAG_SET(x, flag) ((x) |= (flag))
#define IDT_FLAG_UNSET(x, flag) ((x) &= ~(flag))

void idt_load(struct idtdesc *);
void idt_init(void);
void idt_setgate(uint, void *, uint16, uint8);
void idt_enablegate(uint);
void idt_disablegate(uint);

#endif /* _TINIX_IDT_H_ */
