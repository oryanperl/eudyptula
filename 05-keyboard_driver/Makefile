obj-m += hello_world_keyboard_driver.o

CFLAGS_hello_world_keyboard_driver.o += -DDEBUG

KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

