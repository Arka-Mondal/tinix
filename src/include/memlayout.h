/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
*/

#ifndef _TINIX_MEMLAYOUT_H_
#define _TINIX_MEMLAYOUT_H_

#define KERNELBASE 0x80000000

#define VTP_W0(addr) ((addr) - KERNELBASE)
#define PTV_W0(addr) ((addr) + KERNELBASE)

#endif  /* _TINIX_MEMLAYOUT_H_ */
