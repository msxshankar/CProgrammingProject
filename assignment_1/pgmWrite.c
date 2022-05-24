// COMP1921 Programming Project 

/* 
 * Mayur Shankar
 */

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Dependencies
 */
#include "pgmRead.h"
#include "pgmImage.h"
#include "pgmError.h"
#include "pgmCodes.h"
#include "pgmWrite.h"

/*
 * Write function
 * Uses functions defined below
 */
int write(pgmStruct *pgmValues, FILE *outputFile, char **argv, int asciiBinary) {

	/* Calls write check for ascii */
	if (asciiBinary == 200) {
		int valueWrite = writeCheckASCII(pgmValues, outputFile, argv);
		if (valueWrite == 9) {
			return EXIT_OUTPUT_FAILED;
		}

		/* Write ascii check is successfull */
		else {
			printf("ECHOED\n");
			return EXIT_NO_ERRORS;
		}
	}
	
	/* Calls write check for binary */	
	else if (asciiBinary == 300) {	
		int valueWriteBin = writeCheckBinary(pgmValues, outputFile, argv);
		if (valueWriteBin == 9) {
			return EXIT_OUTPUT_FAILED;
		}

		/* Write binary check is successfull */
		else {
			printf("ECHOED\n");
			return EXIT_NO_ERRORS;
		}
	}
	return READ_SUCCESS;
}

/*
 * Writes ascii data to file
 */
int writeCheckASCII (pgmStruct *pgmValues, FILE *outputFile, char **argv) {

	/* Writes width, height and gray value */
	size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", pgmValues->width, pgmValues->height, pgmValues->maxGray);

	/* failed write for width, height or gray value */
	if (nBytesWritten < 0) {

		/* free memory and return error code */
		free(pgmValues->commentLine);
		free(pgmValues->imageData);
		return(badOutput(argv));
	}

	/* Writes imageData from 2D array to file */
	for (int i=0; i < pgmValues->height; i++) {
		for (int j=0; j < pgmValues->width; j++) {

			/* Determines whether a space or new line should be added after each pixel */
			int nextCol = (pgmValues->width - j) - 1;
			
			/* Writes imageData */
			nBytesWritten = fprintf(outputFile, "%d%c", pgmValues->imageData[i][j], (nextCol ? ' ' : '\n') );

			/* failed write for imageData */
			if (nBytesWritten < 0)	{

				/* 
				 * free memory and return error code
				 */
				free(pgmValues->commentLine);
				free(pgmValues->imageData);
				return(badOutput(argv));
			}
		}
	}

	/* ascii write finished
	 * exit with a success code
	 */
	return EXIT_NO_ERRORS;
}

/*
 * Writes binary data to file
 */
int writeCheckBinary (pgmStruct *pgmValues, FILE *outputFile, char **argv) {

	/* Writes width, height and gray value */
	size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d", pgmValues->width, pgmValues->height, pgmValues->maxGray);

	/* failed write for width, height or gray value */
	if (nBytesWritten < 0) {

		/* free memory and return error code */
		free(pgmValues->commentLine);
		free(pgmValues->imageData);
		return(badOutput(argv));
	}

	/* Writes binary imageData from 2D array to file */
	for (int i=0; i < pgmValues->height; i++) {
		for (int j=0; j < pgmValues->width; j++) {

			/* Writes imageData */
//			printf("%u\n", pgmValues->imageData[511][511]);
			nBytesWritten = fwrite(&pgmValues->imageData[i][j], sizeof(unsigned char), 1, outputFile);

			/* failed imageData write */
			if (nBytesWritten < 0)	{
				/* free memory and return error code */
				free(pgmValues->commentLine);
				free(pgmValues->imageData);
				return(badOutput(argv));
			}
		}
	}

	/* 
	 * binary write finished
	 * Exit with a success code
	 */
	return EXIT_NO_ERRORS;
}
