/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#include "types.h"

void * memset(void * dst, uchar c, uint n)
{
  for (uint i = 0; i < n; i++)
    ((uchar *)dst)[i] = c;

  return dst;
}

uint64 strlen(const char * str)
{
  uint len;

  len = 0;

  while (str[len] != '\0')
    len++;

  return len;
}

int strcmp(const char * str1, const char * str2)
{
  for (; *str1 == *str2; str1++, str2++)
  {
    if (*str1 == '\0')
      return 0;
  }

  return (*(const uchar *) str1 < *(const uchar *) str2) ? -1 : 1;
}

int strncmp(const char * str1, const char * str2, uint64 n)
{
  for (; 0 < n; n--, str1++, str2++)
  {
    if (*str1 != *str2)
      return (*(const uchar *) str1 < *(const uchar *) str2) ? -1 : 1;
    else if (*str1 == '\0')
      break;
  }

  return 0;
}
