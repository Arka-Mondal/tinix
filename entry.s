# entry.s    : complete the boot process, before jumping to kernel main
# Licensed under GPLv3
# Author    : Arka Mondal
# Copyright (C) 2024  Arka Mondal

.set MULTIBOOT_HEADER_MAGIC, 0x1BADB002
.set FLAGS, 0x00000001
.set CHECKSUM, -(MULTIBOOT_HEADER_MAGIC + FLAGS)

.set KSTACKSIZE, 4096

.section .multiboot
.align 4
multiboot_header:
  .long MULTIBOOT_HEADER_MAGIC
  .long FLAGS
  .long CHECKSUM

.bss
.align 4
.comm kstack, KSTACKSIZE

.text
.align 4
.global _start
.type _start, @function
_start:
  movl              $(kstack + KSTACKSIZE), %esp

  pushl             %ebx
  pushl             %eax
  call              kmain

loophere:
  jmp               loophere
