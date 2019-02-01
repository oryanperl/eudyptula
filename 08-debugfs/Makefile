obj-m += eudyptula_debugfs.o 

eudyptula_debugfs-objs += eudyptula_debugfs_main.o eudyptula_debugfs_id_file.o

KDIR ?= /lib/modules/$(shell uname -r)/build

.PHONY: all
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

