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
#include "pgmRead.h"
#include "pgmWrite.h"
#include "pgmCodes.h"

int main (int argc, char **argv) {
	/*
	 * handles arguments
	 */	

	/*
	 * checks if no arguments are passed
	 * returns value and prints correct error message
	 * using pgmArgument.c and .h
	 */
	if (argc == 1) {
		return(check_noArguments(argc, argv));
	}


	/*
	 * checks if wrong number of arguments are passed
	 * returns value and prints correct error message
	 * using pgmArgument.c and .h
	 */
	else if (argc != 3) {
		return(check_badArguments(argc));
	}


	/*
	 * arguments are accepted
	 * file will be now be read
	 */
	FILE *inputFile = fopen(argv[1], "r");
	
	/*
	 * checks if file is null
	 * returns value and prints correct error message
	 * using pgmError.c
	 */
	if (inputFile == NULL) {
		return(badFileName(argv));
	}
	
	/*
	 * Allocating memory to struct pointer
	 * For storing image data
	 */
	pgmStruct *pgmValues = (pgmStruct *) malloc (sizeof(pgmStruct));
	structInit(pgmValues);

	/*
	 * Reads in magic number
	 * using pgmRead.c and .h
	 */
	int valueMagic = magicNumberCheck(pgmValues, inputFile, argv);
	if (valueMagic == 3)
		return EXIT_BAD_MAGIC_NUMBER;
	
	/*
	 * Reads in comment line
	 * using pgmRead.c and .h
	 */
	int valueComment = commentLineCheck(pgmValues, inputFile, argv);
	if (valueComment == 4)
		return EXIT_BAD_COMMENT_LINE;
	
	/* Reads in dimensions and max gray value
	 * using pgmRead.c and .h
	 */
	int valueDimensionsGray = dimensionsGrayCheck(pgmValues, inputFile, argv); 
	if (valueDimensionsGray == 5) {
		return EXIT_BAD_DIMENSIONS;
	}
	else if (valueDimensionsGray == 6) {
		return EXIT_BAD_GRAY;
      	} 
	
	int valueMalloc = mallocCheck(pgmValues, inputFile, argv);
	if (valueMalloc == 7)
		return EXIT_BAD_MALLOC;

	int valueData = dataCheck(pgmValues, inputFile, argv);
	if (valueData == 8)
		return EXIT_BAD_DATA;
	
	fclose(inputFile);
	FILE *outputFile = fopen(argv[2], "w");
	
	if (outputFile == NULL) {
		free(pgmValues->commentLine);
		free(pgmValues->imageData);
		return(badOutput(argv));
	}
	
	int valueWrite = writeCheck(pgmValues, outputFile, argv);
	if (valueWrite == 9)
		return EXIT_OUTPUT_FAILED;
	else {
		printf("ECHOED\n");
		return EXIT_NO_ERRORS;
	}

	/*
	 * Frees struct memory
	 */
    	free(pgmValues);
}

