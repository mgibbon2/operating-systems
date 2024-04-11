NAME OF PROJECT: Project 2: Kernel Module and Processes
================

MEMBERS: Matthew Gibbons and Noah Storms
========

STATEMENT:
==========
We have neither given nor received unauthorized assistance on this work.

VIRTUAL MACHINE (VM) INFORMATION:
=================================
NAME OF VIRTUAL MACHINE (VM): VirtualMachine
USERNAME: BestGroup
PASSWORD: HaveAGreatDay24

Describe where the files can be found.
The files are located in `~/operating-systems/project-two`
Each module has its own subdirectory `/module-[ModuleNumber]/` where a respective Makefile and .c file can be found.

ROOT PASSWORD: NoReallyHaveAGreatDay24
==============

PROBLEM DESCRIPTION AND REMEDIATION:
====================================
PART 1: CREATE A HELLO WORLD KERNEL MODULE
==========================================
1. Do you see any errors when you make? If so, how to fix the error?

During the development process, we encountered issues related to the hello.c file. To ensure smooth execution, the following steps outlined below were followed:

Header Installation:
Ensure all necessary headers are installed correctly by executing the following command:
sudo yum install "kernel-devel-uname-r == $(uname -r)"

Function Renaming in hello.c:
To avoid conflicts with reserved names, rename the init_module and cleanup_module functions in the hello.c file. As an example, we did initialization_module and cleaning_module.

2. Notice the different timestamps when Hello world! and Goodbye world! are printed.

Timestamp Discrepancy in dmesg Output:
When inspecting the logs from the kernel ring buffer using the dmesg command, you may notice a difference in the timestamps between the printing of "Hello world!" and "Goodbye world!" messages.

"Hello world!" is displayed with a timestamp of 13:05:40.

"Goodbye world!" is displayed with a timestamp of 13:06:01.

This variation in timestamps is a normal occurrence and can result from factors such as system clock precision, message generation timing, interrupt handling, and other kernel-related operations.

3. If I want to print the messages from init module and cleanup module to the standard output in addition to the kernel ring buffer, what should I change?

If I want to print the messages from init_module and cleanup_module to the standard output in addition to the kernel ring buffer, we needed to....

PART 2: CREATE A PRINT SELF KERNEL MODULE 
=========================================
Steps to load, remove, and see output of module:

`make` This will compile the .ko file

`sudo insmod print_self.ko` This will load the module in the kernel

`dmesg -T | tail` This will contain the output

`sudo rmmod print_self` This will remove the module from the kernel

`make clean` This will remove the temporary files

1. The macro current returns a pointer to the task struct of the current running process. See the following link: https://linuxgazette.net/133/saha.html When you load your module, which process is recognized as current?

The macro current returns a pointer to the task struct of the current running process. When the module is loaded, the process recognized as current is typically the process that initiated the loading action. This could be a user-space process executing a system call to load the module or a kernel-level process executing code that triggers the loading of the module. In either case, the "current" process within the context of the module's execution would be the one responsible for the module's loading.

2. As discussed in our lecture, in old kernels the mother of all processes is called init. In newer kernels, what is it called and what do you see from your module’s output?

In older kernels, the initial process is called "init". In newer kernels, particularly those using systemd as the init system, the initial process is often referred to as "systemd" or "systemd-init." This process serves as the root of the process tree in the system, similar to how "init" functioned in older kernels. Therefore, if you were to trace back from the current process to the root process (which would be "init" or "systemd"), you would see its name and process ID in the output of our module.

3. To see the different states of a process, please refer to the same page above https: //linuxgazette.net/133/saha.html When printing state in your code, please map 3 the numeric state to its string state, e.g., print TASK RUNNING if state is 0. From your module’s output, which state(s) are observed?

The observed states in my module's output are mostly TASK_INTERRUPTIBLE, with a couple of instances of TASK_RUNNING.


PART 3: CREATE A PRINT OTHER KERNEL MODULE
==========================================
Steps to load, remove, and see output of module:

`pgrep bash` This will find an active process' id to be used in the insmod command

`make` This will compile the .ko file

`sudo insmod print_other.ko process_id=[(int) ChosenProcessId]` This will load the module in the kernel with the parameter value of process_id=(int) ChosenProcessId

`dmesg -T | tail` This will contain the output

`sudo rmmod print_other` This will remove the module from the kernel

`make clean` This will remove the temporary files

PART 4: KERNEL MODULES AND SYSTEM CALLS
========================================
1. What's the difference between a kernel module and a system call?

A kernel module is like an add-on for the operating system. It's a small piece of software that can be added or removed the kernel. These modules usually help the operating system support new hardware devices, file systems, or other features that weren't included originally. An example would be if you plug in a new USB device, then the operating system might load a specific module to handle it.

A system call is a way for regular programs to ask the operating system to do something for them. When a program needs to read or write a file, create a new process, or even just get the current time, it asks the operating system through system calls. The operating system provides a list of functions that programs can use to make these requests, like opening a file or creating a new process. These functions are usually accessed through standard libraries provided by the operating system.

2. This article is over 20 years old. If you try [this example] from the article in your VM, does it still work? Use your own words to explain why you think this may be a good (or bad) thing.
