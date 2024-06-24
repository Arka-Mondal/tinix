/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
*/

#include "defs.h"
#include "memlayout.h"
#include "mmu.h"
#include "tty.h"
#include "types.h"

__attribute__((__aligned__(PGSIZE)))
pde_t pgdirentries[NPDENTRIES] = {
  [0] = 0x0 | PDE_P | PDE_W | PDE_PS,
  [KERNELBASE >> PDXSHIFT] = 0x0 | PDE_P | PDE_W | PDE_PS
};

void kinit(void)
{
  tty_init();
}

void main(void)
{
  kinit();

  printk("Welcome to Newbix\n");
}
