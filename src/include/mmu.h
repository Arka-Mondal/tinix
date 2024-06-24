/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
*/

#ifndef _TINIX_MMU_H_
#define _TINIX_MMU_H_

#define CR0_PE          0x00000001    // Protection Enable (bit 0 of %cr0)
#define CR0_WP          0x00010000    // Write Protect (bit 16 of %cr0)
#define CR0_PG          0x80000000    // Paging (bit 31 of %cr0)

#define CR4_PSE         0x00000010    // Page Size Extension (bit 4 of %cr4)

// Page directory constrants
#define NPDENTRIES      1024          // Page directory entries

#define PGSIZE          4096          // Page size
#define PDXSHIFT        22            // Page directory offset shift

#define PGROUNDUP(sz)   (((sz) + PGSIZE - 1) & (~(PGSIZE - 1)))
#define PGROUNDDW(sz)   ((sz) & (~(PGSIZE - 1)))

// Page directory flags
#define PDE_P           0x1           // Present; must be 1 to map a 4-MByte page
#define PDE_W           0x2           // Write permission
#define PDE_PS          0x80          // Page size; must be 1 for 4-MByte page size

#endif  /* _TINIX_MMU_H_ */
