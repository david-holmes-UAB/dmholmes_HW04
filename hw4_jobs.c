#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#include "queue.h"

#define TRUE 1
#define FALSE 0

// job structure to hold information about each job being run
typedef struct job {
    
}

void *job_handler(void *arg) {

}

void *job_runner(void *arg) {

}


int main(int argc, char **argv) {
    int p_cores;
    int isActive; // Determines if program should still be running
    char *errFile; // Filename of the error output file

    // Program starting only accepts one argument.
    if (argc > 2) {
        printf("Too many arguments given. Usage: %s <number of cores>", argv[0]);
        exit(-1); // Exit with -1 to show issue with program
    }
    p_cores = atoi(argv[1]); // p_cores is argv[1], which is the number of core specifed by the user
    isActive = TRUE;

    do {



    } while(isActive == TRUE);






    return 0;
}

