#ifndef __EUDYPTULA_DEBUGFS_FOO_FILE_H__
#define __EUDYPTULA_DEBUGFS_FOO_FILE_H__
#include <linux/stat.h>
#include <linux/dcache.h>

#define EUDYPTULA_DEBUGFS_FOO_FILENAME "foo"
#define EUDYPTULA_FOO_FILE_PERM (S_IWUSR | S_IRUGO)

/**
 * eudyptula_debugfs_create_foo_file - create foo file,
 * the foo file stores data up to one page of data.
 * the foo file is writeable by owner (root) only, and stores the written data.
 * the foo file is readable by any user and on read it returns the data stored,
 *
 * @parent: a pointer to the parent dentry for this file.  This should be a
 *          directory dentry if set.  If this parameter is NULL, then the
 *          file will be created in the root of the debugfs filesystem.
 *
 * The function will return a pointer to dentry if successful, NULL otherwise.
 * the pointer returned must be passed to eudyptula_debugfs_remove_foo_file.
 */
struct dentry *eudyptula_debugfs_create_foo_file(struct dentry *parent);

/**
 * eudyptula_debugfs_remove_foo_file - removes the foo file created by
 * `eudyptula_debugfs_create_foo_file`.
 *
 * @foo_file: a pointer to the entry of the earlier created foo_file
 *
 * on first look this function may seem redundant,
 * i find it cleaner and logically right for the entity initializing resources
 * to be the one responsible for clearning it.
 */
void eudyptula_debugfs_remove_foo_file(struct dentry *foo_file);

#endif // ___EUDYPTULA_DEBUGFS_FOO_FILE_H__
