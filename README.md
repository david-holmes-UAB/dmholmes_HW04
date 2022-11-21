# dmholmes_HW04
Homework 4 for CS332

This assignment implements a job scheduler and viewer.
My implementation currently results in a segfault, which I've been dealing with for a while and was unable to troubleshoot in time.

Compilation instructions are:
> gcc -Wall jobstuff.c hw4_jobs.c -lpthread -o hw4

To run:
> ./hw4 <number of cores>' e.g. './hw4 3

The main program accepts the commands "submit", "showjobs", and "quit"

Also: I was completely unable to get the enscript command to work for me, so I'm currently waiting for a different pdf converter to finish working. 
