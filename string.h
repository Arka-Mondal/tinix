/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#ifndef _TINIX_STRING_H_
#define _TINIX_STRING_H_

#include "types.h"

void * memset(void * dst, uchar c, uint n);
uint64 strlen(const char * str);
int strcmp(const char * str1, const char * str2);
int strncmp(const char * str1, const char * str2, uint64 n);

#endif /* _TINIX_STRING_H_ */
