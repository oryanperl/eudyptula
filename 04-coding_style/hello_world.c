#define DEBUG

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int __init hello_world_init(void)
{
	pr_debug("Hello World!");
	return 0;
}

static void __exit hello_world_cleanup(void)
{
}

module_init(hello_world_init);
module_exit(hello_world_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oryan Perlmutter <oryan.perl1997@gmail.com>");
MODULE_DESCRIPTION("Simple hello world kernel module");
