#include <linux/module.h>
#include <linux/kernel.h>

int initialization_module(void) {
	printk(KERN_INFO "Hello world!\n");
	return 0;
}

void cleaning_module(void) {
	printk(KERN_INFO "Goodbye world!\n");
}

module_init(initialization_module);
module_exit(cleaning_module);

MODULE_LICENSE("GPL");
