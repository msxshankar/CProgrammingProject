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


/* pgm header files
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
	 * check for correct number of arguments
	 * prints correct error message
	 */
	if (argc == 1) {
		noArgumentCount(argv);
	}

	else if (argc != 3) {
		badArgumentCount();
	}

}


