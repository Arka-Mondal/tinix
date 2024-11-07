# Licensed under GPLv3
# Author    : Arka Mondal
# Copyright (C) 2024  Arka Mondal

BINNAME := tinix.bin

ISODIR := isodir
ISONAME := tinix.iso

CC := gcc
ARCH32FLAG := -m32
DILECTFLAG := -ffreestanding
CCFLAG := -Wall -Wextra

LDFLAG := -z noexecstack
LDPAGESIZE := -z max-page-size=4096

OBJECTS = entry.o gdtload.o idtload.o gdt.o idt.o main.o tty.o serial.o kio.o string.o

$(ISONAME) : $(ISODIR)/boot/$(BINNAME) $(ISODIR)/boot/grub/grub.cfg
	grub2-mkrescue -o $(ISONAME) $(ISODIR)

$(ISODIR)/boot/$(BINNAME) : $(BINNAME)
	cp -v $< $(ISODIR)/boot

$(BINNAME) : $(OBJECTS) kernel.ld
	$(CC) -o $@ $(OBJECTS) -T kernel.ld $(ARCH32FLAG) $(DILECTFLAG) -nostdlib -lgcc $(LDFLAG) $(LDPAGESIZE)

entry.o : entry.s
	$(CC) -o $@ -c $< $(ARCH32FLAG)

gdtload.o : gdtload.s
	$(CC) -o $@ -c $< $(ARCH32FLAG)

idtload.o : idtload.s
	$(CC) -o $@ -c $< $(ARCH32FLAG)

gdt.o : gdt.c gdt.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG)

idt.o : idt.c idt.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG)

tty.o : tty.c tty.h x86.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG)

serial.o : serial.c tty.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG)

main.o : main.c tty.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG)

kio.o : kio.c stdarg.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG)

string.o : string.c string.h
	$(CC) -o $@ -c $< $(ARCH32FLAG) $(DILECTFLAG) $(CCFLAG)

.PHONY : cleanbuild
cleanbuild : $(ISODIR)/boot/$(BINNAME) $(ISODIR)/boot/grub/grub.cfg
	$(MAKE) $(ISONAME) && rm -vf $(OBJECTS) $(BINNAME) $(ISODIR)/boot/$(BINNAME)

.PHONY : clean
clean :
	rm -vf $(OBJECTS) $(BINNAME) $(ISODIR)/boot/$(BINNAME) $(ISONAME)
