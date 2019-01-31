#include <linux/fs.h>
#include <linux/stat.h>
#include <linux/module.h>
#include <linux/dcache.h>
#include <linux/debugfs.h>

#include "eudyptula_debugfs_id_file.h"

static ssize_t id_file_read(struct file *filp, char *buffer,
			    size_t len, loff_t *offset)
{
	return simple_read_from_buffer(buffer, len, offset, EUDYPTULA_ID "\n",
			strlen(EUDYPTULA_ID) + 1);
}

static ssize_t id_file_write(struct file *filp, const char *buffer,
			     size_t len, loff_t *offset)
{
	ssize_t ret = -1;
	char id_buffer[sizeof(EUDYPTULA_ID)] = {0};

	ret = simple_write_to_buffer(id_buffer, sizeof(id_buffer), offset,
				     buffer, len - 1);
	if (ret < 0)
		return ret;
	if (strncmp(EUDYPTULA_ID, id_buffer, sizeof(EUDYPTULA_ID)) != 0)
		return -EINVAL;

	return len;
}

static const struct file_operations id_file_ops = {
	.owner = THIS_MODULE,
	.read = id_file_read,
	.write = id_file_write
};

/**
 * eudyptula_debugfs_create_id_file - create id file,
 * the id file mimcs the misc driver created in Task06
 *
 * @parent: a pointer to the parent dentry for this file.  This should be a
 *          directory dentry if set.  If this parameter is NULL, then the
 *          file will be created in the root of the debugfs filesystem.
 *
 * The function will return a pointer to dentry if successful, NULL otherwise.
 * the pointer returned must be passed to eudyptula_debugfs_remove_id_file.
 */
struct dentry *eudyptula_debugfs_create_id_file(struct dentry *parent)
{
	return debugfs_create_file(EUDYPTULA_DEBUGFS_ID_FILENAME, S_IRUGO,
			           parent, NULL, &id_file_ops);
}

/**
 * eudyptula_debugfs_remove_id_file - removes the id file created by
 * `eudyptula_debugfs_create_id_file`.
 *
 * @id_file: a pointer to the entry of the earlier created id_file
 *
 * on first look this function may seem redundant.
 * i find it cleaner and logically right for the entity initializing resources
 * to be the one responsible for clearning it.
 */
void eudyptula_debugfs_remove_id_file(struct dentry *id_file)
{
	debugfs_remove(id_file);
}
