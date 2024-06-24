# entry.S    : complete the boot process, before jumping to kernel main
# Licensed under GPLv3
# Author    : Arka Mondal
# Copyright (C) 2024  Arka Mondal

#include "memlayout.h"
#include "mmu.h"
#include "param.h"

# .set KSTACKSIZE, 4096
.set MULTIBOOT2_HEADER_MAGIC, 0xE85250D6
.set GRUB_MULTIBOOT_ARCHITECTURE_I386, 0
.set CHECKSUM, -(MULTIBOOT2_HEADER_MAGIC + GRUB_MULTIBOOT_ARCHITECTURE_I386 + (multiboot_header_end - multiboot_header))

.section .multiboot
.align 8
multiboot_header:
  # magic
  .long MULTIBOOT2_HEADER_MAGIC
  # isa : i386
  .long GRUB_MULTIBOOT_ARCHITECTURE_I386
  # header length
  .long multiboot_header_end - multiboot_header
  # checksum
  .long CHECKSUM

  # general tag structure
  # this marks the end of tag buffer space
  .short 0    # type
  .short 0    # flags
  .long 8     # size

multiboot_header_end:

.bss
.align 16
.comm stack, KSTACKSIZE

.data

.text
.global _start
.type _start, @function
_start:
  # Turn on page size extension for 4MB pages
  movl        %cr4, %ecx
  orl         $(CR4_PSE), %ecx
  movl        %ecx, %cr4

  # Set up bootstrap page table
  movl        $(VTP_W0(pgdirentries)), %ecx
  movl        %ecx, %cr3

  # Turn on paging
  movl        %cr0, %ecx
  orl         $(CR0_WP | CR0_PG), %ecx
  movl        %ecx, %cr0

  # Set up the stack pointer
  movl        $(stack + KSTACKSIZE), %esp

  # call main() function to start kernel initialization
  call        main

  # clear interrupts and loops indefinitely if we ever return
  # from kmain()
  cli
jmphere:
  hlt
  jmp         jmphere

.size _start, .-_start
