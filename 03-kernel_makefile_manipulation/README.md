# Solution for task #3 of the eudyptula challenge.

to view the solution:
1) `cat /eudyptula/clone/path/03-kernel_makefile_manipulation/0001-Added-eudyptula-to-linux-extraversion.patch`

solution:
```sh
cd /linux/clone/path
vim Makefile
git commit -m "<commit_message>"
git format-patch --signoff HEAD^ -o <output_directory>
```
edit Makefile and add "-eudyptula" to its "EXTRAVERSION" field (check solution).
