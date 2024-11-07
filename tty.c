/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#include "string.h"
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

  cursor_location = tty_row * FRAMEBUFFER_WIDTH + tty_col;

  outb(FRAMEBUFFER_CMD_PORT, FRAMEBUFFER_HIGH_BYTE_CMD);
  outb(FRAMEBUFFER_DATA_PORT, cursor_location >> 8);
  outb(FRAMEBUFFER_CMD_PORT, FRAMEBUFFER_LOW_BYTE_CMD);
  outb(FRAMEBUFFER_DATA_PORT, cursor_location & 0xff);
}

static void tty_scroll(void)
{
  int i;

  if (tty_row < FRAMEBUFFER_HIGHT)
    return;

  for (i = 0; i < (FRAMEBUFFER_HIGHT - 1) * FRAMEBUFFER_WIDTH; i++)
  {
      tty_buffer[i] = tty_buffer[i + FRAMEBUFFER_WIDTH];
  }

  for (i = (FRAMEBUFFER_HIGHT - 1) * FRAMEBUFFER_WIDTH; i < FRAMEBUFFER_HIGHT * FRAMEBUFFER_WIDTH; i++)
  {
    tty_buffer[i] = vga_entry(' ', tty_color);
  }

  tty_row = FRAMEBUFFER_HIGHT - 1;
}

void tty_init(void)
{
  uint64 x, y, index;

  tty_row = 0;
  tty_col = 0;
  tty_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
  tty_buffer = FRAMEBUFFER_ADDR;

  for (y = 0; y < FRAMEBUFFER_HIGHT; y++)
  {
    for (x = 0; x < FRAMEBUFFER_WIDTH; x++)
    {
      index = y * FRAMEBUFFER_WIDTH + x;
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

  index = y * FRAMEBUFFER_WIDTH + x;
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

  if (tty_col >= FRAMEBUFFER_WIDTH)
  {
    tty_col = 0;
    tty_row++;
  }

  tty_scroll();
  update_cursor();
}

void tty_write(const char * buf, uint64 len)
{
  for (uint64 i = 0; i < len; i++)
    tty_putchar(buf[i]);
}

void tty_writestr(const char * str)
{
  tty_write(str, strlen(str));
}
