#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/moduleparam.h>

int process_id = 0;
// allows read access to user
module_parameter(process_id, int, S_IRUSR);

int __init print_other_init(void) {
    struct task_struct *task;
    struct task_struct *parent_task;
    int pid = process_id;

	// if pid is invalid return -1
    if (pid <= 0) {
        printk(KERN_INFO "Invalid process ID provided.\n");
        return -1;
    }
	// if pid isn't found return -1
    task = pid_task(find_vpid(pid), PIDTYPE_PID);
    if (!task) {
        printk(KERN_INFO "Process with PID %d not found.\n", pid);
        return -1;
    }

    // Print information about the specified process and its parents
    while (task != &init_task) {
        printk(KERN_INFO "PID: %d\n", task->pid);
        printk(KERN_INFO "Process Name: %s\n", task->comm);
        printk(KERN_INFO "Process State: %ld\n", task->state);

        parent_task = task->parent;
        if (parent_task) {
            printk(KERN_INFO "Parent PID: %d\n", parent_task->pid);
            printk(KERN_INFO "Parent Process Name: %s\n", parent_task->comm);
            printk(KERN_INFO "Parent Process State: %ld\n", parent_task->state);
        }

        task = parent_task;
    }

    return 0;
}

void print_other_cleaning_module(void) {
	printk(KERN_INFO "Cleaned module\n");
}

module_init(print_other_init);
module_exit(print_other_cleaning_module);

MODULE_LICENSE("GPL");