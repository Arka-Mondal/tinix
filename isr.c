/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#include "gdt.h"
#include "idt.h"
#include "isr.h"
#include "kio.h"

static void isr_register_handlers(void)
{
  idt_setgate(0, int_handler_0, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(1, int_handler_1, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(2, int_handler_2, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(3, int_handler_3, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(4, int_handler_4, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(5, int_handler_5, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(6, int_handler_6, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(7, int_handler_7, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(8, int_handler_8, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(9, int_handler_9, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(10, int_handler_10, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(11, int_handler_11, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(12, int_handler_12, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(13, int_handler_13, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(14, int_handler_14, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(15, int_handler_15, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(16, int_handler_16, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(17, int_handler_17, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(18, int_handler_18, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(19, int_handler_19, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(20, int_handler_20, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(21, int_handler_21, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(22, int_handler_22, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(23, int_handler_23, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(24, int_handler_24, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(25, int_handler_25, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(26, int_handler_26, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(27, int_handler_27, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(28, int_handler_28, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(29, int_handler_29, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(30, int_handler_30, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
  idt_setgate(31, int_handler_31, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INTR);
}

void isr_initialize(void)
{
  isr_register_handlers();
  for (int i = 0; i < 32; i++)
    idt_enablegate(i);
}

void isr_handler(struct stackframe *regis)
{
  printk("isr_handler: %d\n", regis->int_no);
}
