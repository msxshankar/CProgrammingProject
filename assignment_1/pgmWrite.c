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
 * Writes data to file
 */
int writeCheck (pgmStruct *pgmValues, FILE *outputFile, char **argv) {

	/*
	 * Writes width, height and gray value
	 */
	size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", pgmValues->width, pgmValues->height, pgmValues->maxGray);

	/* 
	 * dimension and gray value check
	 */
	if (nBytesWritten < 0) {
		/* 
		 * free memory and return error code
		 */
		free(pgmValues->commentLine);
		free(pgmValues->imageData);
		return(badOutput(argv));
	}

	/*
	 * Writes imageData from 2D array to file
	 */
	for (int i=0; i < pgmValues->height; i++) {
		for (int j=0; j < pgmValues->width; j++) {

			/*
			 * Determines whether a space or new line should be added after each pixel
			 */
			int nextCol = (pgmValues->width - j) - 1;
			
			/* 
			 * Writes imageData
			 */
			nBytesWritten = fprintf(outputFile, "%d%c", pgmValues->imageData[i][j], (nextCol ? ' ' : '\n') );

			/*
			 * imageData check
			 */
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

	/* we are done and can exit with a success code */
	return EXIT_NO_ERRORS;
}
        
