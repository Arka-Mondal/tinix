/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
OUTPUT_ARCH(i386)
ENTRY (_start)

kernel_start = .;

SECTIONS
{
  . = 0x00100000;

  .text ALIGN(0x1000) :
  {
    KEEP(*(.multiboot))
    *(.text)
  }

  .rodata ALIGN(0x1000) :
  {
    *(.rodata)
  }

  .data ALIGN(0x1000) :
  {
    *(.data)
  }

  .bss ALIGN(0x1000) :
  {
    *(COMMON)
    *(.bss)
  }

}

kernel_end = .;
