#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/stat.h>
#include <linux/miscdevice.h>

#include "eudyptula_misc_device.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oryan Perlmutter");
MODULE_DESCRIPTION("A simple miscellaneous driver which interacts with usermode");

static ssize_t eudyptula_misc_read(struct file *filp, char *buffer,
				   size_t len, loff_t *offset)
{
	return simple_read_from_buffer(buffer, len, offset, EUDYPTULA_ID "\n",
			strlen(EUDYPTULA_ID) + 1);
}

static ssize_t eudyptula_misc_write(struct file *filp, const char *buffer,
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

static const struct file_operations eudyptula_misc_fops = {
	.owner = THIS_MODULE,
	.read = eudyptula_misc_read,
	.write = eudyptula_misc_write
};

static struct miscdevice eudyptula_misc_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = MISC_DEVNAME,
	.fops = &eudyptula_misc_fops,
	.mode = S_IRWXUGO
};

module_misc_device(eudyptula_misc_device);
