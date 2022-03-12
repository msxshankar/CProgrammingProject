// COMP 1921 Programming Project

/*
 * Due 18/03/22
 * Mayur Shankar
 *
 */


/*
 * I/O and memory libraries
 */
#include <stdio.h>
#include <stdlib.h>


/* 
 * pgm header files
 */
#include "pgmImage.h"
#include "pgmError.h"

/*
#include "pgmError.h"
#include "pgmClean.h"
#include "pgmRead.h"
#include "pgmConvert.h"
#include "pgmCheck.h"
*/


int main (int argc, char **argv) {
	/*
	 * check if no arguments are passed
	 * return value and prints correct error message
	 * using pgmError.c and .h
	 */
	if (argc == 1) {
		return(noArgumentCount(argv));
	}

	/*
	 * checks if wrong number of arguments are passed
	 * returns value and prints correct error message
	 * using pgmError.c and .h
	 */
	else if (argc != 3) {
		return(badArgumentCount());
	}
	
	else {
		printf("open file");
	}

}


