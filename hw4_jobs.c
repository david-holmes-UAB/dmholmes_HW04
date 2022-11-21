#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

#include "queue.h"

#define TRUE 0
#define FALSE 1
#define BUFFERSIZE 1024 // Not going to lie, I just looked up "what is a good buffer size" to determine this
                        // and was recommended use of a base 2 number, of which 1024 was suggested



// job structure to hold information about each job being run
// Implementation inspired by work on Lab 12, which also used structures to run a program on threads
/*
/ W
/
*/
typedef struct job {
    int jobid; // Number of job in the queue
    char *job_comm; // The command/name of the job
    char *status; // The status of the job e.g., Running, Waiting
    char *outFile; // The file that stdout is redirected to <jobid>.out
    char *errFile; // The file that stderr is redirected to <jobid>.err

} job;

job *init_job(int id, char *command) {
    struct job newJob;

    newJob->jobid = id;
    newJob->job_comm = command;
    newJob->status = "Waiting...";
    sprintf(newJob.outFile, "%d.out", id);
    sprintf(newJob.errFile, "%d.out", id);

    return newJob;
}

void *job_handler(void *arg) {

}

void *job_runner(void *arg) {

}


int main(int argc, char **argv) {
    int p_cores;
    int isActive; // Determines if program should still be running
    char *input[BUFFERSIZE]; // entirety of user input
    char *usr_cmd; // variable to store user command
    char *specProg; // Program specified to be used by the sumbit command
    char *poss_cmds = {"submit", "showjobs", "quit"}; 

    // Program starting only accepts one argument.
    if (argc > 2) {
        printf("Too many arguments given. Usage: %s <number of cores>", argv[0]);
        exit(-1); // Exit with -1 to show issue with program
    }
    p_cores = atoi(argv[1]); // p_cores is argv[1], which is the number of core specifed by the user
    isActive = TRUE;
    printf("Welcome. \nAvailable commands: \nsubmit <program> <arguments> | showjobs\n");
    printf("Use command 'quit' to exit.\n");

    int jobcnt = 0;
    do {
        printf("Enter command. >> ");
        if ((getline(&input, &BUFFERSIZE, stdin) != -1) && ((usr_cmd = strdup(strtok(input, " \n"))) != NULL)){
            if (strcmp(usr_cmd, poss_cmds[0]) == TRUE) {
                
            }
        }


z
    } while(isActive == TRUE);






    return 0;
}

