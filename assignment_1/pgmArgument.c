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
#include <string.h>


/* 
 * pgm header files
 */
#include "pgmArgument.h"

/*
 * defining return codes
 */
#define EXIT_NO_ARGS 0
#define EXIT_WRONG_ARG_COUNT 1
#define EXIT_NO_ERRORS 0
#define EXIT_MISC 100


/*
 * check if no arguments are given
 */
int check_noArguments(int argc, char **argv) {
	/*
	 * determines which message to print
	 * using strcmp to compare argv[0] to the executable name
	 * prints correct error message and returns value
	 */
	
	// pmgEcho
	if (strcmp(argv[0], "./pgmEcho") == 0) {
		printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
		return EXIT_NO_ARGS;
	}
	
	// pgmComp
	else if (strcmp(argv[0], "./pgmComp") == 0) {
		printf("Usage: %s inputImage.pgm inputImage.pgm\n", argv[0]);
		return EXIT_NO_ARGS;
	}

	// pgma2b
	else if (strcmp(argv[0], "./pgma2b") == 0) {
		printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
		return EXIT_NO_ARGS;
	}

	// pgmb2a
	else if (strcmp(argv[0], "./pgmb2a") == 0) {
		printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
		return EXIT_NO_ARGS;
	}

	// pgmReduce
	else if (strcmp(argv[0], "./pgmReduce") == 0) {
		printf("Usage: %s inputImage.pgm reduction_factor outputImage.pgm\n", argv[0]);
		return EXIT_NO_ARGS;
	}

	// pgmTile
	else if (strcmp(argv[0], "./pgmTile") == 0) {
		printf("Usage: %s inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm\n", argv[0]);
		return EXIT_NO_ARGS;
	}

	// pgmAssemble
	else if (strcmp(argv[0], "./pgmAssemble") == 0) {
		printf("Usage: %s outputImage.pgm width height (row column inputImage.pgm)+\n", argv[0]);
		return EXIT_NO_ARGS;
	}
	
	// Miscellaneous error
	else {
		printf("ERROR: Miscellaneous (Executable name did not match expected values)");
		return EXIT_MISC;
	}
}


/*
 * check if wrong number of arguments are given
 */
int check_badArguments(int argc) {
	/*
	 * returns value and prints correct error message
	 */
	printf("ERROR: Bad Argument Count\n");
	return EXIT_WRONG_ARG_COUNT;
}


