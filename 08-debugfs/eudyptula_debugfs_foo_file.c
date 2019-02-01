#include <linux/fs.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/dcache.h>
#include <linux/debugfs.h>

#include "eudyptula_debugfs_foo_file.h"

static char stored_data[PAGE_SIZE] = {0};

static ssize_t foo_file_read(struct file *filp, char *buffer,
			     size_t len, loff_t *offset)
{
	ssize_t ret = -1;
	spin_lock(&filp->f_lock);
	ret = simple_read_from_buffer(buffer, len, offset, stored_data,
				      PAGE_SIZE);
	spin_unlock(&filp->f_lock);
	return ret;
}

static ssize_t foo_file_write(struct file *filp, const char *buffer,
			      size_t len, loff_t *offset)
{
	ssize_t ret = -1;
	spin_lock(&filp->f_lock);
	ret = simple_write_to_buffer(stored_data, sizeof(stored_data), offset,
				     buffer, len - 1);
	spin_unlock(&filp->f_lock);
	return ret;
}

static const struct file_operations foo_file_fops = {
	.owner = THIS_MODULE,
	.read = foo_file_read,
	.write = foo_file_write
};

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
struct dentry *eudyptula_debugfs_create_foo_file(struct dentry *parent)
{
	return debugfs_create_file(EUDYPTULA_DEBUGFS_FOO_FILENAME,
				   EUDYPTULA_FOO_FILE_PERM, parent,
				   NULL, &foo_file_fops);
}

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
void eudyptula_debugfs_remove_foo_file(struct dentry *foo_file)
{
	debugfs_remove(foo_file);
}
