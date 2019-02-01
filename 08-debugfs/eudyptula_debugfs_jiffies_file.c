#include <linux/dcache.h>
#include <linux/debugfs.h>
#include <linux/jiffies.h>

#include "eudyptula_debugfs_jiffies_file.h"

/**
 * eudyptula_debugfs_create_jiffies_file - create jiffies file,
 * the jiffies file is readable by any user and on read it returns
 * the current value of the kernel jiffies timer.
 *
 * @parent: a pointer to the parent dentry for this file.  This should be a
 *          directory dentry if set.  If this parameter is NULL, then the
 *          file will be created in the root of the debugfs filesystem.
 *
 * The function will return a pointer to dentry if successful, NULL otherwise.
 * the pointer returned must be passed to eudyptula_debugfs_remove_jiffies_file.
 */
struct dentry *eudyptula_debugfs_create_jiffies_file(struct dentry *parent)
{
	return debugfs_create_u32(EUDYPTULA_DEBUGFS_JIFFIES_FILENAME,
				  EUDYPTULA_JIFFIES_FILE_PERM, parent,
				  (u32 *)&jiffies);
}

/**
 * eudyptula_debugfs_remove_jiffies_file - removes the jiffies file created by
 * `eudyptula_debugfs_create_jiffies_file`.
 *
 * @jiffies_file: a pointer to the entry of the earlier created jiffies_file
 *
 * on first look this function may seem redundant.
 * i find it cleaner and logically right for the entity initializing resources
 * to be the one responsible for clearning it.
 */
void eudyptula_debugfs_remove_jiffies_file(struct dentry *jiffies_file)
{
	debugfs_remove(jiffies_file);
}
