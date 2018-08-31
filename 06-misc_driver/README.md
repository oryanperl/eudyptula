# Solution for task #06 of the eudyptula challenge.

to view the solution:

1. compile to module using `make`

2. load the kernel module using `sudo insmod eudyptula_misc_device.ko`

3. check the solution on the newly created `/dev/eudyptula`:
```sh
cat /dev/eudyptula
echo "SOME_INPUT" > /dev/eudyptula
echo "0a02c8c3ca21" > /dev/eudyptula [ The actual eudyptula id - valid input ]
echo "0a02c8c3ca21X" > /dev/eudyptula [ To check the substring validation ]
```
