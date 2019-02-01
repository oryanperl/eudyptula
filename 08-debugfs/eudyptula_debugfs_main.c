#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/dcache.h>
#include <linux/debugfs.h>

#include "eudyptula_debugfs_main.h"
#include "eudyptula_debugfs_id_file.h"
#include "eudyptula_debugfs_jiffies_file.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oryan Perlmutter <oryan.perl1997@gmail.com>");
MODULE_DESCRIPTION("A simple module creating a debugfs directory named 'eudyptula' and interacts with usermode");

struct dentry *debugfs_dir;
struct dentry *eudyptula_debugfs_id_file;
struct dentry *eudyptula_debugfs_jiffies_file;

static int __init init_eudyptula_debugfs_module(void)
{
	pr_info("Initializing eudyptula debugfs directory");

	debugfs_dir = debugfs_create_dir(EUDYPTULA_DEBUGFS_DIRNAME, NULL);
	if (!debugfs_dir) {
		pr_err("Failed creating eudyptula debugfs directory");
		goto dir_error;
	}

	eudyptula_debugfs_id_file =
		eudyptula_debugfs_create_id_file(debugfs_dir);
	if (!eudyptula_debugfs_id_file) {
		pr_err("Failed creating eudyptula debugfs id file");
		goto id_file_error;
	}

	eudyptula_debugfs_jiffies_file =
		eudyptula_debugfs_create_jiffies_file(debugfs_dir);
	if (!eudyptula_debugfs_jiffies_file) {
		pr_err("Failed creating eudyptula debugfs jiffies file");
		goto jiffies_file_error;
	}

	return 0;

jiffies_file_error:
	eudyptula_debugfs_remove_id_file(eudyptula_debugfs_id_file);
id_file_error:
	debugfs_remove(debugfs_dir);
dir_error:
	return -EAGAIN;
}

static void __exit cleanup_eudyptula_debugfs_module(void)
{
	pr_info("Cleaning eudyptula debugfs directory");
	eudyptula_debugfs_remove_jiffies_file(eudyptula_debugfs_jiffies_file);
	eudyptula_debugfs_remove_id_file(eudyptula_debugfs_id_file);
	debugfs_remove(debugfs_dir);
}

module_init(init_eudyptula_debugfs_module);
module_exit(cleanup_eudyptula_debugfs_module)
