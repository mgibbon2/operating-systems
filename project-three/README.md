NAME OF PROJECT: Project 3: POSIX Thread Programming
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
The files are located in `~/operating-systems/project-three`
.git/ - source control files
README.txt - this file
writeup.docx - contains pseudocode and other writeup information


Part 1
substring_sequential.c - supplied sequential algorithm
substring_parallel.c - custom program that utilizes threads to achieve same purpose as substring_sequential.c
strings.txt - first test file for substring_parallel.c
strings1.txt - second test file for substring_parallel.c
strings2.txt - third test file for substring_parallel.c
strings3.txt - fourth test file for substring_parallel.c


Part 2
producer_consumer.c - condition variable utilization program
message.txt - message to be read/written


Part 3
list-forming.c - supplied file for baseline analysis
mylist-forming.c - file with custom modifications for execution time improvement


ROOT PASSWORD: NoReallyHaveAGreatDay24
==============

PROBLEM DESCRIPTION AND REMEDIATION:
====================================
Task 1:
=======
Description: Given a sequential program that accomplishes the task of counting substrings, implement a similar algorithm to accomplish the same task but utilizing multithreading to accomplish a pseudo-parallel program.

1. If you partition s1 among threads, you will miss those s2’s at the partition boundaries. Instead of partitioning the data, can you partition the task(s)?

Task 2:
=======
Description: The program utilizes condition variables to synchronize access between the producer and consumer threads, ensuring orderly reading from the file and sequential writing into the circular queue. This enables efficient management of data flow, maintaining the integrity of the original message order throughout the process.

Task 3: 
=======
Description: Given a program that utilizes a K value and a num thread parameter, modify the program to reduce the runtime. Perform analysis on the resulting runtime data.

1. Since the problem does not require a specific order of the nodes in the global list, there are two ways to add nodes. First, a node could be added to the global list immediately after it is created by a thread. Alternatively, a thread could form a local list of K nodes and add the local list to the global list in one run. Will the choice in how to add nodes make a difference? Why?

Yes, the choice of how to add nodes can significantly impact performance and concurrency. Adding nodes immediately after creation can result in increased contention for the global list, especially if multiple threads are simultaneously creating nodes. This contention may lead to higher overhead due to synchronization mechanisms like locks. Conversely, forming local lists of nodes and adding them in batches to the global list can reduce contention and synchronization overhead. This approach promotes independent thread execution until a batch of nodes is ready for insertion, enhancing scalability and performance, particularly in high-contention scenarios. We implemented the second approach and noticed better performance compared to the original code in list-forming.c.

2. The original program uses pthread mutex trylock. Will the use of pthread mutex lock make a difference? Why?

Indeed, the switch from pthread mutex trylock to pthread mutex lock can alter thread behavior and performance. While trylock attempts to acquire the mutex lock and returns immediately if unavailable, lock will block the calling thread until the lock is acquired. Frequent unavailability of the lock due to contention may lead to increased thread blocking and latency with lock-based synchronization. However, pthread mutex lock simplifies the programming model by ensuring mutual exclusion without the need for explicit error handling.

3. Each thread is pinned to a specific CPU (according to the thread id). Will letting threads run on all CPUs make a difference? Why?

Allowing threads to run on all CPUs versus pinning them to specific CPUs can yield different outcomes depending on workload and hardware characteristics. Pinning threads to specific CPUs can enhance cache utilization and reduce cache thrashing by localizing thread data to particular cores. However, it may lead to uneven CPU utilization and potential overload on certain cores. Conversely, letting threads run on all CPUs can distribute the workload more evenly, potentially improving overall system throughput and scalability. Nonetheless, this approach may introduce increased cache contention and synchronization overhead.

MORE INFORMATION IN FOUND IN writeup.docx
=========================================