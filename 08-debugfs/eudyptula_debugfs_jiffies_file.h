#ifndef __EUDYPTULA_DEBUGFS_JIFFIES_FILE_H__
#define __EUDYPTULA_DEBUGFS_JIFFIES_FILE_H__
#include <linux/stat.h>
#include <linux/dcache.h>

#define EUDYPTULA_DEBUGFS_JIFFIES_FILENAME "jiffies"
#define EUDYPTULA_JIFFIES_FILE_PERM (S_IRUGO)

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
struct dentry *eudyptula_debugfs_create_jiffies_file(struct dentry *parent);

/**
 * eudyptula_debugfs_remove_jiffies_file - removes the jiffies file created by
 * `eudyptula_debugfs_create_jiffies_file`.
 *
 * @jiffies_file: a pointer to the entry of the earlier created jiffies_file
 *
 * on first look this function may seem redundant,
 * i find it cleaner and logically right for the entity initializing resources
 * to be the one responsible for clearning it.
 */
void eudyptula_debugfs_remove_jiffies_file(struct dentry *jiffies_file);

#endif // ___EUDYPTULA_DEBUGFS_JIFFIES_FILE_H__
