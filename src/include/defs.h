/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
*/

#ifndef _TINIX_DEFS_H_
#define _TINIX_DEFS_H_

#include "types.h"

// printk.c
void printk(const char *, ...);

// string.c
void * memset(void *, uchar, uint);
uint64 strlen(const char *);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, uint64);

// tty.c
void tty_init(void);
void tty_setcolor(uint8);
void tty_putat(char, uint8, uint64, uint64);
void tty_putchar(char);
void tty_write(const char *, uint64);
void tty_writestr(const char *);

#endif  /* _TINIX_DEFS_H_ */
