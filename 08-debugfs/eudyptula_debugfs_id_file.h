#ifndef __EUDYPTULA_DEBUGFS_ID_FILE_H__
#define __EUDYPTULA_DEBUGFS_ID_FILE_H__
#include <linux/stat.h>
#include <linux/dcache.h>

#define EUDYPTULA_DEBUGFS_ID_FILENAME "id"
#define EUDYPTULA_ID_FILE_PERM (S_IRUGO | S_IWUGO)
#define EUDYPTULA_ID "0a02c8c3ca21"

/**
 * eudyptula_debugfs_create_id_file - create id file,
 * the id file mimics the misc driver created in Task06
 *
 * @parent: a pointer to the parent dentry for this file.  This should be a
 *          directory dentry if set.  If this parameter is NULL, then the
 *          file will be created in the root of the debugfs filesystem.
 *
 * The function will return a pointer to dentry if successful, NULL otherwise.
 * the pointer returned must be passed to eudyptula_debugfs_remove_id_file.
 */
struct dentry *eudyptula_debugfs_create_id_file(struct dentry *parent);

/**
 * eudyptula_debugfs_remove_id_file - removes the id file created by
 * `eudyptula_debugfs_create_id_file`.
 *
 * @id_file: a pointer to the entry of the earlier created id_file
 *
 * on first look this function may seem redundant,
 * i find it cleaner and logically right for the entity initializing resources
 * to be the one responsible for clearning it.
 */
void eudyptula_debugfs_remove_id_file(struct dentry *id_file);

#endif // ___EUDYPTULA_DEBUGFS_ID_FILE_H__
