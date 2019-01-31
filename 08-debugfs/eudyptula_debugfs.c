#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/dcache.h>
#include <linux/debugfs.h>

#include "eudyptula_debugfs.h"
#include "eudyptula_debugfs_id_file.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oryan Perlmutter");
MODULE_DESCRIPTION("A simple module creating a debugfs directory named 'eudyptula' and interacts with usermode");

struct dentry *debugfs_dir;
struct dentry *eudyptula_debugfs_id_file;

static int __init init_eudyptula_debugfs_module(void)
{
	pr_info("Initializing eudyptula debugfs directory");

	debugfs_dir = debugfs_create_dir(EUDYPTULA_DEBUGFS_DIRNAME, NULL);
	if (!debugfs_dir) {
		pr_err("Failed creating eudyptula debugfs directory");
		return -EAGAIN;
	}

	eudyptula_debugfs_id_file =
		eudyptula_debugfs_create_id_file(debugfs_dir);
	if (!eudyptula_debugfs_id_file) {
		pr_err("Failed creating eudyptula debugfs id file");
		debugfs_remove(debugfs_dir);
	}

	return 0;
}

static void __exit cleanup_eudyptula_debugfs_module(void)
{
	pr_info("Cleaning eudyptula debugfs directory");
	eudyptula_debugfs_remove_id_file(eudyptula_debugfs_id_file);
	debugfs_remove(debugfs_dir);
}

module_init(init_eudyptula_debugfs_module);
module_exit(cleanup_eudyptula_debugfs_module)
