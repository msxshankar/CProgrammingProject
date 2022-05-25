/* COMP1921 Programming Project */

/*
 * Mayur Shankar
 */

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Dependencies */
#include "pgmArgument.h"
#include "pgmCodes.h"
#include "pgmError.h"
#include "pgmImage.h"
#include "pgmRead.h"
#include "pgmWrite.h"

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
	else if (argc != 4) {
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
	int reduceReadValue = read(pgmValues, inputFile, argv);	
	
	/* Checks return values and returns if an error has occurred */
	if (reduceReadValue != 0) {
		if (reduceReadValue != 200) {
			if (reduceReadValue != 300) {
				return reduceReadValue;
			}
		}
	}
	
	return READ_SUCCESS;
}	
