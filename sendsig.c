////////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
// Other Files:      intdate.c division.c
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
#include <stdlib.h>


 // sends SIGUSR1 and SIGINT signals to other programs
 // based on command line args.  1st arg corresponds to signal and the 2nd
 // arg corresponds to PID.  "-u" sends SIGUSR1 signal and "-i" sends SIGINT
int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "-u") == 0) {
        kill(atol(argv[2]), SIGUSR1);
    }
    if (strcmp(argv[1], "-i") == 0) {
        kill(atol(argv[2]), SIGINT);
    }
    return 0;
}



