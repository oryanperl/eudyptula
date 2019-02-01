#include <linux/usb.h>
#include <linux/hid.h>
#include <linux/init.h>
#include <linux/module.h>

static const struct usb_device_id hello_world_id_table[] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
			     USB_INTERFACE_SUBCLASS_BOOT,
			     USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{}
};

MODULE_DEVICE_TABLE(usb, hello_world_id_table);

static int __init hello_world_keyboard_driver_init(void)
{
	pr_debug("Initializing hello_world_keyboard_driver!\n");
	return 0;
}

static void __exit hello_world_keyboard_driver_cleanup(void)
{
	pr_debug("Cleaning hello_world_keyboard_driver!\n");
}

module_init(hello_world_keyboard_driver_init);
module_exit(hello_world_keyboard_driver_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oryan Perlmutter <oryan.perl1997@gmail.com>");
MODULE_DESCRIPTION("Driver which notifies whenever a USB-Keyboard is connected");
