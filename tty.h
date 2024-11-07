/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#ifndef _TINIX_TTY_H_
#define _TINIX_TTY_H_

#include "types.h"

typedef enum {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE,
  VGA_COLOR_GREEN,
  VGA_COLOR_CYAN,
  VGA_COLOR_RED,
  VGA_COLOR_MAGENTA,
  VGA_COLOR_BROWN,
  VGA_COLOR_LIGHT_GREY,
  VGA_COLOR_DARK_GREY,
  VGA_COLOR_LIGHT_BLUE,
  VGA_COLOR_LIGHT_GREEN,
  VGA_COLOR_LIGHT_CYAN,
  VGA_COLOR_LIGHT_RED,
  VGA_COLOR_LIGHT_MAGENTA,
  VGA_COLOR_LIGHT_BROWN,
  VGA_COLOR_WHITE
} vga_color_t;

#define FRAMEBUFFER_WIDTH             80
#define FRAMEBUFFER_HIGHT             25

#define FRAMEBUFFER_CMD_PORT          0x3d4
#define FRAMEBUFFER_DATA_PORT         0x3d5

#define FRAMEBUFFER_HIGH_BYTE_CMD     14
#define FRAMEBUFFER_LOW_BYTE_CMD      15

#define FRAMEBUFFER_ADDR              ((uint16 *) 0xb8000)

void tty_init(void);
void tty_setcolor(uint8);
void tty_putat(char, uint8, uint64, uint64);
void tty_putchar(char);
void tty_write(const char *, uint64);
void tty_writestr(const char *);

#endif  /* _TINIX_TTY_H_ */
