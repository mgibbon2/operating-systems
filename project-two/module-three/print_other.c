#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int __init print_other_init(void) {

	return 0;
}

void print_other_cleaning_module(void) {
	printk(KERN_INFO "Cleaned module\n");
}

module_init(print_other_init);
module_exit(print_other_cleaning_module);

MODULE_LICENSE("GPL");
