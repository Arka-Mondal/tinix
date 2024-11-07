/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#include "stdarg.h"
#include "tty.h"

static void kputc(char c)
{
  tty_putchar(c);
}

static void kprintint(int value, int base, int sign)
{
  static const char * const digits = "0123456789abcdef";
  char buf[64];

  int i, neg;
  uint nvalue;

  i = 0;
  neg = 0;

  if ((sign == 1) && (value < 0))
  {
    neg = 1;
    nvalue = (uint) -value;
  }
  else
  {
    nvalue = (uint) value;
  }

  do
  {
    buf[i] = digits[nvalue % base];
    i++;
  } while ((i < 64) && (nvalue /= base) != 0);

  if (neg == 1)
    kputc('-');

  while (--i >= 0)
    kputc(buf[i]);
}

// %d, %u, %#x, %x, %#o, %o, %p, %c, %p
void printk(const char * format, ...)
{
  char * str;
  int c, i, state, value;
  va_list arglist;

  state = 0;
  value = 0;

  va_start(arglist, format);

  for (i = 0; format[i] != '\0'; i++)
  {
    c = format[i] & 0xff;

    if (state == 0)
    {
      if (c == '%')
        state = '%';
      else
        kputc(c);
    }
    else if (state == '%' || state == '#')
    {
      if (c == 'd')
      {
        value = va_arg(arglist, int);
        kprintint(value, 10, 1);
      }
      else if (c == 'u')
      {
        value = va_arg(arglist, int);
        kprintint(value, 10, 0);
      }
      else if (c == 'x' || c == 'p')
      {
        value = va_arg(arglist, int);
        if (state == '#' || c == 'p')
        {
          kputc('0');
          kputc('x');
        }
        kprintint(value, 16, 0);
      }
      else if (c == 'o')
      {
        value = va_arg(arglist, int);

        if (state == '#')
          kputc('0');

        kprintint(value, 8, 0);
      }
      else if (c == 's')
      {
        str = va_arg(arglist, char *);

        if (str == 0)
          str = "(null)";
        while (*str != 0)
        {
          kputc(*str);
          str++;
        }
      }
      else if (c == 'c')
      {
        value = va_arg(arglist, char);
        kputc(value);
      }
      else if (c == '%')
      {
        kputc(c);
      }
      else if (c == '#')
      {
        state = '#';
        continue;
      }
      else
      {
        kputc('%');
        if (state == '#')
          kputc('#');
        kputc(c);
      }
      state = 0;
    }
  }

  va_end(ap);
}

void write(const char * message, uint64 len)
{
  tty_write(message, len);
}
