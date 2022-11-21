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
#define MAXJOBS 100
#define MAXQUEUE 50

queue *jobQueue; // Made this a global variable due to being unsure of how to update it across methods

// job structure to hold information about each job being run
// Implementation inspired by work on Lab 12, which also used structures to run a program on threads
/*
/ 
/
*/
typedef struct job {
    int jobid; // Number of job in the queue
    char *job_comm; // The command/name of the job
    char *status; // The status of the job e.g., Running, Waiting
    char *outFile; // The file that stdout is redirected to <jobid>.out
    char *errFile; // The file that stderr is redirected to <jobid>.err

} job;
// makes a job to add it to the queue
job *init_job(int id, char *command) {
    struct job newJob;

    newJob->jobid = id;
    newJob->job_comm = command;
    newJob->status = "Waiting...";
    sprintf(newJob.outFile, "%d.out", id);
    sprintf(newJob.errFile, "%d.out", id);

    return newJob;
}

// Job-centric commands
// Displays the jobs in the queue
void show_jobs() {

}
// Handles the jobs, lol
void *job_handler(void *arg) {

}
// runs each job
void *job_runner(void *arg) {

}


int main(int argc, char **argv) {
    // User input stuff
    int p_cores;
    int isActive; // Determines if program should still be running
    char *input[BUFFERSIZE]; // entirety of user input
    char *usr_cmd; // variable to store user command
    char *arg_cmd; // Program specified to be used by the sumbit command
    char *arg_cmdArg; // I think this variable name is funny; used if the argument has arguments
    pthread_t tid; // obligatory tid

    // Job stuff
    job jobList[MAXJOBS]; // Array of all jobs
    jobQueue = queue_init(MAXQUEUE); // initialize queue with job amount cap od MAXQUEUE (50 here)

    // Predefined stuff
    char *poss_cmds = {"submit", "showjobs", "quit"}; 

    // Program starting only accepts one argument.
    if (argc > 2) {
        printf("Too many arguments given. Usage: %s <number of cores>", argv[0]);
        exit(-1); // Exit with -1 to show issue with program
    }
    else if (argc < 2) {
        printf("No core input given, defaulting to usage of P = 2 (two cores).\n");
        p_cores = 2;
    }
    else {
        p_cores = atoi(argv[1]); // p_cores is argv[1], which is the number of core specifed by the user
    }

    isActive = TRUE;
    printf("Welcome. \nAvailable commands: \nsubmit <program> <arguments> | showjobs\n");
    printf("Use command 'quit' to exit.\n");

    pthread_create(&tid, NULL, job_handler, NULL); // Do stuff with all the jobs while the "UI" is running

    // The horrific block of user input handling
    int jobcnt = 0;
    do {
        printf("Enter command. >> ");
        if ((getline(&input, &BUFFERSIZE, stdin) != -1) && ((usr_cmd = strdup(strtok(input, " \n"))) != NULL)){
            // User command provided is "submit"
            if (strcmp(usr_cmd, poss_cmds[0]) == TRUE && i < 100) {
                arg_cmd = strdup(strtok(NULL, " \n"));
                if ((arg_cmdArg = strdup(strtok(NULL, " \n"))) != NULL) {
                    strcat(arg_cmd, " ");
                    strcat(arg_cmd, arg_cmdArg);
                }
                jobList[i] = init_job(i, arg_cmd);
                queue_insert(jobQueue, jobList + i);
                printf("Job %d has been added to the queue.\n", i++);
            }
            // User command provided is "showjobs" or "quit"
            else if (strcmp(usr_cmd, poss_cmds[1]) || strcmp(usr_cmd, poss_cmds[2])) {
                switch(usr_cmd) {
                    // "showjobs"
                    case poss_cmds[1]:
                    show_jobs();
                    break;
                    // "quit"
                    case poss_cmds[2]:
                    printf("Exiting program.\n");
                    isActive == FALSE;
                    break;
                    // If this shows at all, something went incredibly wrong
                    default:
                    printf("An error has occured. Exiting..."); // You literally should not see this
                    exit(-1);
                }
            }
            else {
                if (i > 99 && strcmp(usr_cmd, posscmds[0]) == TRUE) {
                    printf("The maximum number of jobs in memory (%d) has been reached. Please restart the program if you would like to add more.\n", MAXJOBS);
                }
                else {
                    printf("Unrecognized and/or unsupported command.\n");
                }
            }
        }

    } while(isActive == TRUE);

    if (isActive == FALSE)
        exit(0);

    return 0;
}

