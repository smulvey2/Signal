////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      sendsig.c division.c
// Semester:         CS 354 Spring 2018
// Lecture:          002
//
// Author:           Steven Mulvey
// Email:            smulvey2@wisc.edu
// CS Login:         mulvey
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          
//                   
//
// Online sources:   
//                    
//                   
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// sets alarm length
int seconds = 3; 

// tracks amount of times program receives SIGUSR1
int count = 0;

// catches the alarm signal and prints the PID and time

void alarmHandler(int sig) {
    // Prints time and PID
    time_t curtime;
    time(&curtime);
    printf("PID: %d", getpid());
    printf(" | Current time: %s", ctime(&curtime));

    // Calls alarm
    alarm(seconds);
}
// catches the SIGUSR1 signal and increments the count.

void sigusr1Handler(int sig) {
    count += 1;
    printf("SIGUSR1 caught!\n");
}

// catches the SIGINT signal, prints the amount of times
// a SIGUSR1 signal was caught, then exits the program.
 
void sigintHandler(int sig) {
    printf("\n");
    printf("SIGINT received.\n");
    printf("SIGUSR1 was received %d times. Exiting now.\n", count);
    exit(0);
}

// runs an infinite loop, alarm is called every 3 seconds.
 
int main() {
    printf("Pid and time will be printed every 3 seconds.\n");
    printf("Enter ^C to end the program.\n");

    // Initializes sigaction struct for alarmHandler
    struct sigaction act;
    memset (&act, 0, sizeof(act));
    act.sa_handler = alarmHandler;
    sigaction(SIGALRM, &act, NULL);

    // Initializes sigaction struct for sigusr1Handler
    struct sigaction action;
    memset (&action, 0, sizeof(action));
    action.sa_handler = sigusr1Handler;
    sigaction(SIGUSR1, &action, NULL);

    // Initializes sigaction struct for sigintHandler
    struct sigaction ac;
    memset (&ac, 0, sizeof(ac));
    ac.sa_handler = sigintHandler;
    sigaction(SIGINT, &ac, NULL);

    // Calls alarm
    alarm(seconds);

    // Infinite loop
    while (1) {
    }
    return 0;
}






























