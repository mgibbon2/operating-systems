#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int __init print_self_init(void) {
	struct task_struct *task = current;
	
	printk(KERN_INFO "PID: %d\n", task->pid);
	printk(KERN_INFO "Process Name: %s\n ", task->comm);
	printk(KERN_INFO "Process State: %ld\n", task->state);
	
	while (task->parent != task) {
		task = task->parent;
		printk(KERN_INFO "Parent PID: %d\n", task->pid);
		printk(KERN_INFO "Parent Process Name: %s\n", task->comm);
		printk(KERN_INFO "Parent Process State: %ld\n", task->state);
	}

	return 0;
}

void print_self_cleaning_module(void) {
	printk(KERN_INFO "Cleaned module\n");
}

module_init(print_self_init);
module_exit(print_self_cleaning_module);

MODULE_LICENSE("GPL");
