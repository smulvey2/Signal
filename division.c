////////////////////////////////////////////////////////////////////////////////
// Main File:        division.c
// This File:        division.c
// Other Files:      intdate.c sendsig.c
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

int divCount = 0;  // tracks successful divisions


 // catches signal sent after division by 0 attempt.  prints number of successful
 // divisions then exits the program
void arithmeticHandler(int sig) {
    printf("Error: a division by 0 operation was attempted.\n");
    printf("Total number of operations completed successfully: %d\n", counter);
    printf("The program will be terminated.\n");
    exit(0);
}


 // catches signal sent by user typing ctrl + c.  Prints number of successful
 // divisions then exits the program
void sigintHandler(int sig) {
    printf("\n");
    printf("Total number of operations completed successfully: %d\n", counter);
    printf("The program will be terminated.\n");
    exit(0);
}


 // an infinite loop to calculate division of the two user selected numbers
int main() {
    // Initializes sigaction struct for sigintHandler
    struct sigaction ac;
    memset (&ac, 0, sizeof(ac));
    ac.sa_handler = sigintHandler;
    sigaction(SIGINT, &ac, NULL);

    // Initializes sigaction struct for arithmeticHandler
    struct sigaction act;
    memset (&act, 0, sizeof(act));
    act.sa_handler = arithmeticHandler;
    sigaction(SIGFPE, &act, NULL);

    // Infinite loop dividing user ints
    while (1) {
        char firstInt[10];
        char secondInt[10];
        printf("Enter first integer: ");
        fgets(firstInt, 10, stdin);
        printf("Enter second integer: ");
        fgets(secondInt, 10, stdin);
        int intOne = atoi(firstInt);
        int intTwo = atoi(secondInt);
        int quotient = intOne / intTwo;
        int remainder = intOne % intTwo;
        printf("%d / %d is %d with a remainder of %d\n", 
        intOne, intTwo, quotient, remainder);
        divCount += 1;
    }
    return 0;
}
