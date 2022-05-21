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
 * Header files
 */
#include "pgmRead.h"
#include "pgmImage.h"
#include "pgmError.h"
#include "pgmCodes.h"


/* 
 * Magic Number Check
 */
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

/* 
 * Comment Line Check
 */
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
		 * fgets() reads in a line
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

/* 
 * Dimensions and Max Gray Value Check
 */
int dimensionsGrayCheck (pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/*
	 * Reads in width, height and gray value
	 */
	int scanCount = fscanf(inputFile, " %u %u %u", &(pgmValues->width), &(pgmValues->height), &(pgmValues->maxGray));
	
	/*
	 * Checks whether correct number of values have been read in
	 * Checks whether these values are correct
	 */
	if ((scanCount != 3) || (pgmValues->width < MIN_IMAGE_DIMENSION) ||
	    (pgmValues->width > MAX_IMAGE_DIMENSION) ||
	    (pgmValues->height < MIN_IMAGE_DIMENSION) ||
	    (pgmValues->height > MAX_IMAGE_DIMENSION)) {

		/* 
		 * free up the memory and close file pointer
		 */
		free(pgmValues->commentLine);
		fclose(inputFile);

		/*
		 * return error code
		 */
		return(badDimensions(argv));
		}
	
	/*
	 * Checks gray value
	 */	
	if (pgmValues->maxGray !=255) {
		
		/*
		 * free up memory, close file pointer and return error code
		 */
		free(pgmValues->commentLine);
		fclose(inputFile);
		return(badGrayValue(argv));
	}	

	return READ_SUCCESS;
}

/*
 * Malloc check
 */
int mallocCheck (pgmStruct *pgmValues, FILE *inputFile, char **argv) {
	
	/*
	 * Allocates memory to imageData which is the total size of the 2D array
	 * Then allocates memory to each row in the array
	 */
	pgmValues->imageData = (unsigned char **) malloc(pgmValues->height * sizeof(unsigned char *));
	
	for (int i=0; i < pgmValues->height; i++) {
		pgmValues->imageData[i] = (unsigned char *) malloc (pgmValues->width * sizeof(unsigned char));
	}
	
	/* 
	 * malloc check for entire array
	 */
	if (pgmValues->imageData == NULL) {

		/* 
		 * free up memory, close file pointer and return error code
		 */
		free(pgmValues->commentLine);
		fclose(inputFile);
		return(badMalloc(argv));
	}
	
	/*
	 * malloc check for each row in array
	 */
	for (int i=0; i < pgmValues->height; i++) {

		if (pgmValues->imageData[i] == NULL) {

			/* 
			 * free up memory, close file pointer and return error code
			 */
			free(pgmValues->commentLine);
			fclose(inputFile);
			return(badMalloc(argv));
		}
	}

	return READ_SUCCESS;	
}


/* 
 * data check
 */
int dataCheck (pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/*
	 * Reads in every pixel of file and writes it to 2D array
	 */
	for (int i=0; i < pgmValues->height; i++) {
		for (int j=0; j < pgmValues->width; j++) {

			/*
			 * Reads in next value
			 */
			int grayValue = -1;
			int scanCount = fscanf(inputFile, " %u", &grayValue);

			/*
			 * data check
			 */
			if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255)) {

				/* 
				 * free memory
				 */
				free(pgmValues->commentLine);
				free(pgmValues->imageData);	

				/*
				 * close file pointer and return error code
				 */
				fclose(inputFile);
				return(badData(argv));
			}
			
			/*
			 * Writes pixel value to imageData
			 */
			pgmValues->imageData[i][j] = grayValue;
		}
	}

	/* 
	 * Check whether all pixel values have been read in file
	 */
	int grayValue = -1;
	int scanCount = fscanf(inputFile, " %u", &grayValue);
	
	if (scanCount != EOF) {
		
		/*
		 * free memory, close file pointer and return error code
		 */
		free(pgmValues->commentLine);
		free(pgmValues->imageData);	
		fclose(inputFile);
		return(badData(argv));
	}

	return READ_SUCCESS;
}

