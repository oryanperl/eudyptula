# Solution for task #05 of the eudyptula challenge.

to view the solution:

1. compile to module using `make`.

2. introdouce your module to udevd:
```sh
sudo cp /eudyptula/clone/path/05-keyboard_driver/hello_world_keyboard_driver.ko /lib/modules/$(uname -r)/ [ Placing your module in a familiar directory ]
sudo depmod -a [ Allowing the module to be registered in the modules.alias file ]
```

3. Connect your USB Keyboard.

4. Check `dmesg`.

* The module might not be loaded because usbhid is detected to handle the keyboard (can be checked by running `lsmod | grep "usbhid"`), in that case you can use the following:

	1. go through steps 1 and 2 from above.

	2. remove usbhid `sudo rmmod usbhid`. [ Your USB devices will stop working at that point since we removed their driver from the kernel ]

	3. reconnect your USB Keyboard. [ This will load both your driver and usbhid which will handle your devices ]

	4. view `dmesg`.

