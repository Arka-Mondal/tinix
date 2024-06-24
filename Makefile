# Licensed under GPLv3
# Author    : Arka Mondal
# Copyright (C) 2024  Arka Mondal

ISODIR := isodir
SRCDIR := src
ISONAME := tinix.iso
BINNAME := tinix.bin

$(ISONAME) : $(ISODIR)/boot/$(BINNAME) $(ISODIR)/boot/grub/grub.cfg
	grub2-mkrescue -o $(ISONAME) $(ISODIR)

$(ISODIR)/boot/$(BINNAME) : $(SRCDIR)/$(BINNAME)
	cp -v $< $(ISODIR)/boot

$(SRCDIR)/$(BINNAME) :
	$(MAKE) -C $(SRCDIR)

.PHONY : buildbin
buildbin :
	$(MAKE) -C $(SRCDIR)

.PHONY : clean
clean :
	$(MAKE) -C $(SRCDIR) clean && rm -vf $(ISODIR)/boot/$(BINNAME) $(ISONAME)
