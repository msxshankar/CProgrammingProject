// Programming Project COMP1921

// Mayur Shankar

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Dependencies
 */
#include "pgmRead.h"
#include "pgmImage.h"
#include "pgmError.h"
#include "pgmCodes.h"

/* Magic Number Check */
int magicNumberCheck(pgmStruct *pgmValues, FILE *inputFile, char **argv) {
	/*
	 * Reads in magic number
	 */
	pgmValues->magicnumber[0] = getc(inputFile);
	pgmValues->magicnumber[1] = getc(inputFile);

	  if (*(pgmValues->magicNumber) != MAGIC_NUMBER_ASCII_PGM) {
		 /*
		  * close the file
		  */
		 fclose(inputFile);
   
		 /*
		  * print an error message
		  * and returns correct value
		  */
		  return(badMagicNumber(argv));
	}
	  else {
		  return READ_SUCCESS;
	}
 }


/* Comment Line Check */
int commentLineCheck(pgmStruct *pgmValues, FILE *inputFile, char **argv) {
	/* 
	 * scan whitespace
	 */
	int scanCount = fscanf(inputFile, " ");

	/*
	 * check for a comment line
	 */
	char nextChar = fgetc(inputFile);

	if (nextChar == '#') {
		/* 
		 * allocate buffer
		 */
		pgmValues->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH + 2);

		/* 
		 * fgets() reads a line
		 */
		char *commentString = fgets(pgmValues->commentLine, MAX_COMMENT_LINE_LENGTH + 2, inputFile);

		if (commentString == NULL) {
			/* 
			 * free memory
			 */
			free(pgmValues->commentLine);

			/* 
			 * close file
			 */
			fclose(inputFile);
			
			/*
			 * Returns error
			 */
			return(badCommentLine(argv));
		}
	}
	else {
		/* 
		 * put character back
		 */
		ungetc(nextChar, inputFile);
	}
	return READ_SUCCESS;
}

/* Dimensions and Max Gray Value Check */
int dimensionsGrayCheck (pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/* whitespace to skip blanks             */
	int scanCount = fscanf(inputFile, " %u %u %u", &(pgmValues->width), &(pgmValues->height), &(pgmValues->maxGray));
	
	if ((scanCount != 3) || (pgmValues->width < MIN_IMAGE_DIMENSION) ||
	    (pgmValues->width > MAX_IMAGE_DIMENSION) ||
	    (pgmValues->height < MIN_IMAGE_DIMENSION) ||
	    (pgmValues->height > MAX_IMAGE_DIMENSION))
		{ /* failed size sanity check    */
		/* free up the memory            */
		free(pgmValues->commentLine);

		/* be tidy: close file pointer   */
		fclose(inputFile);

		/*
		 * return
		 */

		return(badDimensions(argv));

		} /* failed size sanity check    */
	
	if (pgmValues->maxGray !=255) {

		free(pgmValues->commentLine);
		
		fclose(inputFile);

		return(badGrayValue(argv));
	}	

	return READ_SUCCESS;
}


