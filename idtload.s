# idtload.s : load the idt descriptor
# Licensed under GPLv3
# Author    : Arka Mondal
# Copyright (C) 2024  Arka Mondal

.text
.global idt_load
.type idt_load, @function
idt_load:
  pushl     %ebp
  movl      %esp, %ebp

  # load the idt descriptor
  movl      8(%ebp), %eax
  lidt      (%eax)

  movl      %ebp, %esp
  popl      %ebp
  ret
