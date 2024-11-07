/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#ifndef _TINIX_X86_H_
#define _TINIX_X86_H_

#include "types.h"

static inline uint8 inb(uint16 port)
{
  uint8 data;

  asm volatile("inb %1, %0" : "=a" (data) : "d" (port));
  return data;
}

static inline uint16 inw(uint16 port)
{
  uint16 data;

  asm volatile("inw %1, %0" : "=a" (data) : "d" (port));
  return data;
}

static inline void outb(uint16 port, uint8 data)
{
  asm volatile("outb %0, %1" : : "a" (data), "d" (port));
}

static inline void outw(uint16 port, uint16 data)
{
  asm volatile("outw %0, %1" : : "a" (data), "d" (port));
}

static inline void cli(void)
{
  asm volatile("cli");
}

static inline void sti(void)
{
  asm volatile("sti");
}

static inline uint xchg(volatile uint *addr, uint newval)
{
  uint result;

  asm volatile("lock; xchgl %0, %1" :
               "+m" (*addr), "=a" (result) :
               "1" (newval) :
               "cc");
  return result;
}

#endif /* _TINIX_X86_H_ */
