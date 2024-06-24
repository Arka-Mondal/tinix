/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
OUTPUT_ARCH(i386)
ENTRY (_start)

SECTIONS
{
  . = 0x80100000;

  .text ALIGN(4K) : AT(0x100000)
  {
    KEEP(*(.multiboot))
    *(.text)
  }

  PROVIDE(etext = .);

  .rodata ALIGN(4K) :
  {
    *(.rodata)
  }

  .data ALIGN(4K) :
  {
    *(.data)
  }

  PROVIDE(edata = .);

  .bss ALIGN(4K) :
  {
    *(COMMON)
    *(.bss)
  }

  PROVIDE(end = .);
}
