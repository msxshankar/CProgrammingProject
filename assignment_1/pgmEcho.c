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

/*
 * macros
 */
#define END_FUNC 0
#define EXIT_NO_ARGS 0
#define EXIT_WRONG_NO_ARGS 1
#define EXIT_BAD_MAGIC_NUMBER 3
#define EXIT_BAD_COMMENT_LINE 4
#define EXIT_BAD_DIMENSION 5
#define EXIT_BAD_GRAYVALUE 6
#define MAGIC_NUMBER_ASCII_PGM 0x3250


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
		return EXIT_BAD_DIMENSION;
	}
	else if (valueDimensionsGray == 6) {
		return EXIT_BAD_GRAYVALUE;
      	} 

	/*
	 * Frees struct memory
	 */
    	free(pgmValues);
}

