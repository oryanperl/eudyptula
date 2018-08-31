obj-m += eudyptula_misc_device.o

KDIR ?= /lib/modules/$(shell uname -r)/build

.PHONY: all
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

