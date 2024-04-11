#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int __init print_self_init(void) {
	struct task_struct *task = current;

	const char *get_state(int state) {
    switch (state) {
        case 0:
            return "TASK_RUNNING";
        case 1:
            return "TASK_INTERRUPTIBLE";
        case 2:
            return "TASK_UNINTERRUPTIBLE";
        case 4:
            return "TASK_STOPPED";
        case 8:
            return "TASK_TRACED";
        case 16:
            return "EXIT_ZOMBIE";
        case 32:
            return "EXIT_DEAD";
        case 64:
            return "TASK_NONINTERACTIVE";
        default:
            return "Unknown";
    }
}
	
	printk(KERN_INFO "PID: %d\n", task->pid);
	printk(KERN_INFO "Process Name: %s\n ", task->comm);
	printk(KERN_INFO "Process State: %s\n", get_state(task->state));
	
	while (task->parent != task) {
		task = task->parent;
		printk(KERN_INFO "Parent PID: %d\n", task->pid);
		printk(KERN_INFO "Parent Process Name: %s\n", task->comm);
		printk(KERN_INFO "Parent Process State: %s\n", get_state(task->state));
	}

	return 0;
}

void print_self_cleaning_module(void) {
	printk(KERN_INFO "Cleaned module\n");
}

module_init(print_self_init);
module_exit(print_self_cleaning_module);

MODULE_LICENSE("GPL");
