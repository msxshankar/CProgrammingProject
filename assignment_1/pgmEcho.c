// COMP 1921 Programming Project

/*
 * Due 18/03/22
 * Mayur Shankar
 */


/*
 * I/O and memory libraries
 */
#include <stdio.h>
#include <stdlib.h>


/* 
 * pgm header files
 */
#include "pgmEcho.h"
#include "pgmArgument.h"
#include "pgmError.h"
#include "pgmImage.h"

/*
 * macros
 */
#define END_FUNC 0
#define EXIT_NO_ARGS 0
#define EXIT_WRONG_NO_ARGS 1


int main (int argc, char **argv) {
	/*
	 * handles arguments
	 */	
	arguments(argc, argv);

	if (argumentReturnValue == 0)
		return EXIT_NO_ARGS;

	else if (argumentReturnValue == 1)
		return EXIT_WRONG_NO_ARGS;

	printf("ok");
}


void arguments (int argc, char **argv) {
	/*
	 * checks if no arguments are passed
	 * return value and prints correct error message
	 * using pgmArguments.c and .h
	 */
	if (argc == 1) {
		argumentReturnValue = check_noArguments(argc, argv);
	}

	/*
	 * checks if wrong number of arguments are passed
	 * returns value and prints correct error message
	 * using pgmError.c and .h
	 */
	else if (argc !=3) {
		argumentReturnValue = check_badArguments(argc);
	}
	
	/*
	 * arguments are accepted
	 * file will be now be read
	 */
	else {
		return;
	}
}


