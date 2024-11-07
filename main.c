/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#include "gdt.h"
#include "idt.h"
#include "types.h"
#include "kio.h"
#include "serial.h"
#include "tty.h"

void kinit(void)
{
  gdt_init();
  serial_init();
  tty_init();
  idt_init();
}

int kmain(uint32 magic, uint32 mbootaddr)
{
  if (magic != 0x2BADB002)
    return 1;

  kinit();

  printk("Booting...\n");
  printk("Multiboot struct address: %p\n", mbootaddr);

  return 1;
}
