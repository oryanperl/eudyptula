obj-m += hello_world_keyboard_driver.o

ccflags-y += -DDEBUG

KDIR ?= /lib/modules/$(shell uname -r)/build

.PHONY: all
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

