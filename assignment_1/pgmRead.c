// Programming Project COMP1921

// Mayur Shankar

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
		pgmValues->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH);

		/* 
		 * fgets() reads a line
		 */
		char *commentString = fgets(pgmValues->commentLine, MAX_COMMENT_LINE_LENGTH, inputFile);

		if (commentString == NULL || strlen(commentString) == MAX_COMMENT_LINE_LENGTH - 1) {
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


int mallocCheck (pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/* allocate the data pointer             */
	long nImageBytes = pgmValues->width * pgmValues->height * sizeof(unsigned char);
	pgmValues->imageData = (unsigned char *) malloc(nImageBytes);

	/* sanity check for memory allocation    */
	if (pgmValues->imageData == NULL)
		{ /* malloc failed */
		/* free up memory                */
		free(pgmValues->commentLine);

		/* close file pointer            */
		fclose(inputFile);

		/* return error code             */
		return(badMalloc(argv));
		}
	return READ_SUCCESS;	
}

int dataCheck (pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	long nImageBytes = pgmValues->width * pgmValues->height * sizeof(unsigned char);

	for (unsigned char *nextGrayValue = pgmValues->imageData; nextGrayValue < pgmValues->imageData + nImageBytes; nextGrayValue++)
		{ /* per gray value */

		/* read next value               */
		int grayValue = -1;
		int scanCount = fscanf(inputFile, " %u", &grayValue);

		/* sanity check	                 */
		if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255))
			{ /* fscanf failed */
			/* free memory           */
			free(pgmValues->commentLine);
			free(pgmValues->imageData);	

			/* close file            */
			fclose(inputFile);
			
			return(badData(argv));
			} /* fscanf failed */

		/* set the pixel value           */
		*nextGrayValue = (unsigned char) grayValue;
		} /* per gray value */

		int grayValue = -1;
		int scanCount = fscanf(inputFile, " %u", &grayValue);

		if (scanCount != EOF)
			{
			free(pgmValues->commentLine);
			free(pgmValues->imageData);	

			fclose(inputFile);
			
			return(badData(argv));
			}

	return READ_SUCCESS;
}

