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
The files are located in ~/operating-systems/project-two

ROOT PASSWORD: NoReallyHaveAGreatDay24
==============

PROBLEM DESCRIPTION AND REMEDIATION:
====================================

PART 4: KERNEL MODULES AND SYSTEM CALLS:
========================================
1. DIFFERENCE BETWEEN KERNEL MODULE AND SYSTEM CALL:
- A kernel module is like an add-on for the operating system. It's a small piece of software that can be added or removed the kernel. These modules usually help the operating system support new hardware devices, file systems, or other features that weren't included originally. An example would be if you plug in a new USB device, then the operating system might load a specific module to handle it.
- A system call is a way for regular programs to ask the operating system to do something for them. When a program needs to read or write a file, create a new process, or even just get the current time, it asks the operating system through system calls. The operating system provides a list of functions that programs can use to make these requests, like opening a file or creating a new process. These functions are usually accessed through standard libraries provided by the operating system.

2. 
