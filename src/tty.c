/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
*/

#include "defs.h"
#include "tty.h"
#include "x86.h"

static uint16 tty_row;
static uint16 tty_col;
static uint8 tty_color;
static uint16 * tty_buffer;

static inline uint8 vga_entry_color(vga_color_t fg, vga_color_t bg)
{
  return (fg & 0xf) | (bg << 4);
}

static inline uint16 vga_entry(uchar uc, uint8 color)
{
  return (uint16) uc | (uint16) color << 8;
}

static void update_cursor(void)
{
  uint16 cursor_location;

  cursor_location = tty_row * VGA_WIDTH + tty_col;

  outb(0x3d4, 14);
  outb(0x3d5, cursor_location >> 8);
  outb(0x3d4, 15);
  outb(0x3d5, cursor_location & 0xff);
}

static void tty_scroll(void)
{
  int i;

  if (tty_row < VGA_HIGHT)
    return;

  for (i = 0; i < (VGA_HIGHT - 1) * VGA_WIDTH; i++)
  {
      tty_buffer[i] = tty_buffer[i + VGA_WIDTH];
  }

  for (i = (VGA_HIGHT - 1) * VGA_WIDTH; i < VGA_HIGHT * VGA_WIDTH; i++)
  {
    tty_buffer[i] = vga_entry(' ', tty_color);
  }

  tty_row = VGA_HIGHT - 1;
}

void tty_init(void)
{
  uint64 x, y, index;

  tty_row = 0;
  tty_col = 0;
  tty_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
  tty_buffer = (uint16 *) 0xb8000;

  for (y = 0; y < VGA_HIGHT; y++)
  {
    for (x = 0; x < VGA_WIDTH; x++)
    {
      index = y * VGA_WIDTH + x;
      tty_buffer[index] = vga_entry(' ', tty_color);
    }
  }

  update_cursor();
}

void tty_setcolor(uint8 color)
{
  tty_color = color;
}

void tty_putat(char c, uint8 color, uint64 x, uint64 y)
{
  uint64 index;

  index = y * VGA_WIDTH + x;
  tty_buffer[index] = vga_entry(c, color);
}

void tty_putchar(char c)
{
  // handle a backspace - move the cursor's x backward one step
  if ((c == 0x08) && (tty_col != 0))
  {
    tty_col--;
  }

  // handle a tab by increasing the cursor's x, but only to a point
  // where it is divisible by 8
  else if (c == 0x09)
  {
    tty_col = (tty_col + 8) & (~7);
  }

  // handle carriage return
  else if (c == 0x0d)
  {
    tty_col = 0;
  }

  // handle newline character
  else if (c == 0x0a)
  {
    tty_col = 0;
    tty_row++;
  }

  // other printable characters
  else if (c >= 0x20)
  {
    tty_putat(c, tty_color, tty_col, tty_row);
    tty_col++;
  }

  if (tty_col >= VGA_WIDTH)
  {
    tty_col = 0;
    tty_row++;
  }

  tty_scroll();
  update_cursor();
}

void tty_write(const char * data, uint64 size)
{
  for (uint64 i = 0; i < size; i++)
    tty_putchar(data[i]);
}

void tty_writestr(const char * str)
{
  tty_write(str, strlen(str));
}
