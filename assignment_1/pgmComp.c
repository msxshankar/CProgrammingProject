// COMP 1921 Programming Project

/*
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
#include "pgmComp.h"
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
	 * first file will be now be read
	 */
	FILE *inputFile1 = fopen(argv[1], "r");
	
	/*
	 * checks if first file is null
	 * returns value and prints correct error message
	 * using pgmError.c
	 */
	if (inputFile1 == NULL) {
		return(badFileName(argv));
	}

	/*
	 * Allocating memory to struct pointer for first file
	 * For storing image data
	 */
	pgmStruct *pgmValuesFile1 = (pgmStruct *) malloc (sizeof(pgmStruct));
	structInit(pgmValuesFile1);

	/*
	 * Reads in magic number for first file
	 * using pgmRead.c and .h
	 */
	int valueMagicFile1 = magicNumberCheck(pgmValuesFile1, inputFile1, argv);
	if (valueMagicFile1 == 3) {
		return EXIT_BAD_MAGIC_NUMBER;
	}
	
	/*
	 * Reads in comment line for first file
	 * using pgmRead.c and .h
	 */
	int valueCommentFile1 = commentLineCheck(pgmValuesFile1, inputFile1, argv);
	if (valueCommentFile1 == 4) {
		return EXIT_BAD_COMMENT_LINE;
	}	

	/* Reads in dimensions and max gray value for first file
	 * using pgmRead.c and .h
	 */
	int valueDimensionsGrayFile1 = dimensionsGrayCheck(pgmValuesFile1, inputFile1, argv); 
	if (valueDimensionsGrayFile1 == 5) {
		return EXIT_BAD_DIMENSIONS;
	}
	else if (valueDimensionsGrayFile1 == 6) {
		return EXIT_BAD_GRAY;
      	} 
	
	/*
	 * Checks for failed malloc for first file
	 * using pgmRead.c and .h
	 */	
	int valueMallocFile1 = mallocCheck(pgmValuesFile1, inputFile1, argv);
	if (valueMallocFile1 == 7) {
		return EXIT_BAD_MALLOC;
	}

	/*
	 * Checks for bad data for first file
	 * using pgmRead.c and .h	
	 */
	int valueDataFile1 = dataCheckASCII(pgmValuesFile1, inputFile1, argv);
	if (valueDataFile1 == 8) {
		return EXIT_BAD_DATA;
	}

	/*
	 * closes first file
	 */
	fclose(inputFile1);


	/*
	 * opens second file and checks if it equals null
	 */
	FILE *inputFile2 = fopen(argv[2], "r");

	if (inputFile2 == NULL) {
		return(badFileName(argv));
	}

	/*
	 * Allocating memory to struct pointer for second file
	 * For storing image data
	 */
	pgmStruct *pgmValuesFile2 = (pgmStruct *) malloc (sizeof(pgmStruct));
	structInit(pgmValuesFile2);

	/*
	 * Reads in magic number for second file
	 * using pgmRead.c and .h
	 */
	int valueMagicFile2 = magicNumberCheck(pgmValuesFile2, inputFile2, argv);
	if (valueMagicFile2 == 3) {
		return EXIT_BAD_MAGIC_NUMBER;
	}

	/*
	 * Reads in comment line for second file
	 * using pgmRead.c and .h
	 */
	int valueCommentFile2 = commentLineCheck(pgmValuesFile1, inputFile2, argv);
	if (valueCommentFile2 == 4) {
		return EXIT_BAD_COMMENT_LINE;
	}
	
	/* Reads in dimensions and max gray value for second file
	 * using pgmRead.c and .h
	 */
	int valueDimensionsGrayFile2 = dimensionsGrayCheck(pgmValuesFile2, inputFile2, argv); 
	if (valueDimensionsGrayFile2 == 5) {
		return EXIT_BAD_DIMENSIONS;
	}
	else if (valueDimensionsGrayFile2 == 6) {
		return EXIT_BAD_GRAY;
      	} 
	
	/*
	 * Checks for failed malloc for second file
	 * using pgmRead.c and .h
	 */	
	int valueMallocFile2 = mallocCheck(pgmValuesFile2, inputFile2, argv);
	if (valueMallocFile2 == 7) {
		return EXIT_BAD_MALLOC;
	}

	/*
	 * Checks for bad data for second file
	 * using pgmRead.c and .h	
	 */
	int valueDataFile2 = dataCheckASCII(pgmValuesFile2, inputFile2, argv);
	if (valueDataFile2 == 8) {
		return EXIT_BAD_DATA;
	}
	
	/* Closes second file
	 */
	fclose(inputFile2);

	int final = compare(pgmValuesFile1, pgmValuesFile2);
	return final;
}

int compare (pgmStruct *pgmValuesFile1, pgmStruct *pgmValuesFile2) {
	
	/*
	 * Compares magic number
	 */
	if (*(pgmValuesFile1->magicNumber) != *(pgmValuesFile2->magicNumber)) {
		printf("DIFFERENT");
		return READ_SUCCESS;
	}
	
	if (pgmValuesFile1->commentLine != pgmValuesFile2->commentLine) {
		printf("DIFFERENT");
		return READ_SUCCESS;	
	}
	
	if (pgmValuesFile1->width != pgmValuesFile2->width) {
		printf("DIFFERENT");
		return READ_SUCCESS;
	}

	if (pgmValuesFile1->height != pgmValuesFile2->height) {
		printf("DIFFERENT");
		return READ_SUCCESS;
	}

	if (pgmValuesFile1->maxGray != pgmValuesFile2->maxGray) {
		printf("DIFFERENT");
		return READ_SUCCESS;
	}

	for (int i=0; i < pgmValuesFile1->height; i++) {
       		for (int j=0; j < pgmValuesFile1->width; j++) {
			
			if (pgmValuesFile1->imageData[i][j] != pgmValuesFile2->imageData[i][j])	{
				printf("DIFFERENT");
				return READ_SUCCESS;
			}
		}
	}
	
	printf("IDENTICAL\n");
	return READ_SUCCESS;
}
