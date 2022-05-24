// COMP 1921 Programming Project

/*
 * Due 25/05/22
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
	 * returns value and prints correcct error message
	 * using pgmArgument.c and .h
	 */	

	/* checks if no arguments are passed */
	if (argc == 1) {
		return(check_noArguments(argc, argv));
	}

	/* checks if wrong number of arguments are passed */
	else if (argc != 3) {
		return(check_badArguments(argc));
	}

	/* first file is opened and checks for NULL */
	FILE *inputFile = fopen(argv[1], "r");
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
	 * Reads in File
	 * using pgmRead.c and .h
	 */
	int returnValue = read(pgmValues, inputFile, argv);	
	
	/* if the image does not contain P2 or P5 */
	 if (returnValue != 200) {
		if (returnValue != 300) {
			return returnValue;
		}
	}

	/* Closes file */
	fclose(inputFile);

	/*
	 * Opens second file and checks for NULL
	 */
	FILE *outputFile = fopen(argv[2], "w");
	if (outputFile == NULL) {
		free(pgmValues->commentLine);
		free(pgmValues->imageData);
		return(badOutput(argv));
	}
	
	/*
	 * Writes to file
	 */ 
	return(write (pgmValues, outputFile, argv, returnValue));
		
	/*
	 * Frees struct memory
	 */
    	free(pgmValues);
}

