NAME OF PROJECT: Project 1: Makefile
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
The files are located in `~/operating-systems/project-one`

Describe each file and the purpose it serves.
.git - source control files
list.c - linked list implementation written in c
list.h - header file for the c file
list_test.c - tests written for the list implementation, also written in c
Makefile - required makefile for executing the c programs, also cleans the files afterwards
README.txt - this file

Provide any special instructions to access or run your program.
'make run clean' - compiles list.c and test_list.c into a single executable, runs the executable, and then removes object and executable files from directory
'make' - compiles list.c and test_list.c into a single executable
'make run' - compiles list.c and test_list.c into a single executable and then runs the executable
'make clean' - removes object and executable files from directory

ROOT PASSWORD: NoReallyHaveAGreatDay24
==============

PROBLEM DESCRIPTION AND REMEDIATION:
====================================

	PART 0: SET UP
	==============
	The preparation section outlines the initial steps required to set up the development environment for the project. Updating the CentOS 7 operating system to ensure that the latest security patches and software updates are installed. After, a reboot is initiated to apply the changes and ensure the system is running the latest kernel version. Essential development tools are then installed, including the GCC compiler, ncurses-devel, make, wget, and perl. These tools are necessary for compiling and building C programs effectively. Once installed, the environment is ready for development.

	PART 1: LINKED LIST
	===================
	The Linked List component of this project involves creating a linked list data structure in C. Each node in the list stores a character string called 'item' and a pointer called 'next' pointing to the next node in the list. The task includes implementing various functions to manipulate the linked list, such as adding nodes, removing nodes, printing the list, flushing the list, and freeing the memory allocated to the list.

	PART 2: WRITING A MAKEFILE
	===========================
	The Makefile was heavily influenced from Makefile 4 and Makefile 5 from https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ (recommended tutorial)
