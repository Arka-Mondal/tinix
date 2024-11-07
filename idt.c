/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#include "idt.h"

struct idtentry kidt[256];
struct idtdesc kidtdesc = {.limit = sizeof(kidt) - 1, .address = kidt};

void idt_init(void)
{
  idt_load(&kidtdesc);
}

void idt_setgate(uint intrno, void * offset,
                 uint16 segselect, uint8 flag)
{
  kidt[intrno].offsetlow = ((uint32) offset) & 0xffff;
  kidt[intrno].segselector = segselect;
  kidt[intrno].reserved = 0x0;
  kidt[intrno].flags = flag;
  kidt[intrno].offsethigh = (((uint32) offset) >> 16) & 0xffff;
}

void idt_enablegate(unsigned int intrno)
{
  IDT_FLAG_SET(kidt[intrno].flags, IDT_FLAG_PRESENT);
}

void idt_disablegate(unsigned int intrno)
{
  IDT_FLAG_UNSET(kidt[intrno].flags, IDT_FLAG_PRESENT);
}
