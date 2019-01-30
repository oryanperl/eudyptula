# Solution for task #07 of the eudyptula challenge.

So this time we want to compile a linux-next branch.

Reading the [linux-next documentation](https://www.kernel.org/doc/man-pages/linux-next.html) is recommended.

the stages i took in order to pass the task we took the following stages:

```
1. cd /path/to/clone/linux

2. git remote add linux-next https://git.kernel.org/pub/scm/linux/kernel/git/next/linux-next.git

3. git fetch linux-next

4. git fetch --tags linux-next

4. git checkout next-`date +%Y%m%d`

// compile the kernel using linux next after moving to the fitting tag.
5. make olddefconfig

6. make -j 4

7. make -j 4 modules_install

8. make -j 4 install
```
