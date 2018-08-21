#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int do_sleep(int sleep_ms)
{
	udelay(sleep_ms * 10);

	if (sleep_ms < 10)
		pr_info("We slept a short time!");

	return sleep_ms * sleep_ms;
}

int my_init(void)
{
	return do_sleep(10);
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);
