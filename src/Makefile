# Licensed under GPLv3
# Author    : Arka Mondal
# Copyright (C) 2024  Arka Mondal

BINNAME := tinix.bin
INCLDIR := include

CC := gcc
ARCH32FLAG := -m32
DILECTFLAG := -ffreestanding
CCFLAG := -Wall -Wextra

LDFLAG := -z noexecstack
LDPAGESIZE := -z max-page-size=4096

OBJECTS = entry.o main.o tty.o printk.o string.o

$(BINNAME) : $(OBJECTS) kernel.ld
	$(CC) -o $@ $(OBJECTS) -T kernel.ld $(ARCH32FLAG) $(DILECTFLAG) -nostdlib -lgcc $(LDFLAG) $(LDPAGESIZE)

entry.o : entry.S
	$(CC) -o $@ -c $< $(ARCH32FLAG) -I $(INCLDIR)

tty.o : tty.c include/defs.h include/tty.h include/x86.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG) -I $(INCLDIR)

main.o : main.c include/defs.h include/tty.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG) -I $(INCLDIR)

printk.o : printk.c include/defs.h include/stdarg.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG) -I $(INCLDIR)

string.o : string.c include/defs.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG) -I $(INCLDIR)

.PHONY : clean
clean :
	rm -vf $(OBJECTS) $(BINNAME)
