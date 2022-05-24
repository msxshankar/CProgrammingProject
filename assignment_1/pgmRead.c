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
 * Read function
 * Uses functions that are defined below
 */
int read(pgmStruct *pgmValues, FILE *inputFile, char **argv, int program) {
	
	/* Calls magic number check */
	int valueMagic = magicNumberCheck(pgmValues, inputFile, argv);
	if (valueMagic == 3) {
		return EXIT_BAD_MAGIC_NUMBER;	
	}

	if (program == PGMA2B) {
		if (valueMagic == READ_BINARY) {
			return(badMagicNumber(argv));
		}
	}
	
	/* Calls comment check */
	int valueComment = commentLineCheck (pgmValues, inputFile, argv);
	if (valueComment == 4) {
		return EXIT_BAD_COMMENT_LINE;
	}

	/* Calls dimensions and gray value check */
	int valueDimensionsGray = dimensionsGrayCheck (pgmValues, inputFile, argv);
	if (valueDimensionsGray == 5) {
		return EXIT_BAD_DIMENSIONS;
	}

	else if (valueDimensionsGray == 6) {
		return EXIT_BAD_GRAY;
	}
	
	/*/ Calls malloc check */
	int valueMalloc = mallocCheck (pgmValues, inputFile, argv);
	if (valueMalloc == 7) {
		return EXIT_BAD_MALLOC;
	}
	
	/* Calls data check for ascii */
	if (valueMagic == 200) {
		int valueData = dataCheckASCII (pgmValues, inputFile, argv); 
		if (valueData == 8) {
			return EXIT_BAD_DATA;
		}
		else {
			return valueMagic;
		}
	}
	
	/* Calls data check for binary */	
	else if (valueMagic == 300) {
		int valueDataBin = dataCheckBinary(pgmValues, inputFile, argv);
		if (valueDataBin == 8) {
			return EXIT_BAD_DATA;
		}
		else {
			return valueMagic;
		}
	}
	
	/* File is read successfully */
	return READ_SUCCESS;
}


/* 
 * Magic Number Check
 */
int magicNumberCheck(pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/* Reads in magic number */
	pgmValues->magicnumber[0] = getc(inputFile);
	pgmValues->magicnumber[1] = getc(inputFile);
	
	/* Checks if image is ascii or binary */
	if (*(pgmValues->magicNumber) != MAGIC_NUMBER_ASCII_PGM) {
		if (*(pgmValues->magicNumber) != MAGIC_NUMBER_RAW_PGM) {

			 /* closes file and returns error */
			 fclose(inputFile);
			 return(badMagicNumber(argv));
		}
		
		 /* Will read in binary image */
		return READ_BINARY;
	}

	else {
		/* Will read in ascii image */
		return READ_ASCII;
	}
 }

/* 
 * Comment Line Check
 */
int commentLineCheck(pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/* scan whitespace */
	int scanCountComment = fscanf(inputFile, " ");

	/* check for a comment line */
	char nextChar = fgetc(inputFile);

	if (nextChar == '#') {

		/* allocate buffer */
		pgmValues->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH);

		/* fgets() reads in a line */
		char *commentString = fgets(pgmValues->commentLine, MAX_COMMENT_LINE_LENGTH, inputFile);

		if (commentString == NULL || strlen(commentString) == MAX_COMMENT_LINE_LENGTH - 1) {

			/* frees memory, closes file and returns error code */
			free(pgmValues->commentLine);
			fclose(inputFile);
			return(badCommentLine(argv));
		}
	}
	else {
		/* put character back */
		ungetc(nextChar, inputFile);
	}

	return READ_SUCCESS;
}

/* 
 * Dimensions and Max Gray Value Check
 */
int dimensionsGrayCheck (pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/* Reads in width, height and gray value */
	int scanCountDimensions = fscanf(inputFile, " %u %u %u", &(pgmValues->width), &(pgmValues->height), &(pgmValues->maxGray));
	
	/*
	 * Checks whether correct number of values have been read in
	 * Checks whether these values are correct
	 */
	if ((scanCountDimensions != 3) || (pgmValues->width < MIN_IMAGE_DIMENSION) ||
	    (pgmValues->width > MAX_IMAGE_DIMENSION) ||
	    (pgmValues->height < MIN_IMAGE_DIMENSION) ||
	    (pgmValues->height > MAX_IMAGE_DIMENSION)) {

		/* free up the memory, close file pointer and return error code */
		free(pgmValues->commentLine);
		fclose(inputFile);
		return(badDimensions(argv));
		}
	
	/* Checks gray value */
	if (pgmValues->maxGray !=255) {
		
		/* free up memory, close file pointer and return error code */
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
	
	/* malloc check for entire array */
	if (pgmValues->imageData == NULL) {

		/* free up memory, close file pointer and return error code */
		free(pgmValues->commentLine);
		fclose(inputFile);
		return(badMalloc(argv));
	}
	
	/* malloc check for each row in array */
	for (int i=0; i < pgmValues->height; i++) {

		if (pgmValues->imageData[i] == NULL) {

			/* free up memory, close file pointer and return error code */
			free(pgmValues->commentLine);
			fclose(inputFile);
			return(badMalloc(argv));
		}
	}

	return READ_SUCCESS;	
}


/* 
 * image data check for ascii images
 */
int dataCheckASCII (pgmStruct *pgmValues, FILE *inputFile, char **argv) {

	/* Reads in every pixel of file and writes it to 2D array */
	for (int i=0; i < pgmValues->height; i++) {
		for (int j=0; j < pgmValues->width; j++) {

			/* Reads in next value */
			int grayValue = -1;
			int scanCountData = fscanf(inputFile, " %u", &grayValue);

			/* data check */
			if ((scanCountData != 1) || (grayValue < 0) || (grayValue > 255)) {

				/* free memory, close file pointer and return error code */
				free(pgmValues->commentLine);
				free(pgmValues->imageData);	
				fclose(inputFile);
				return(badData(argv));
			}
			
			/* Writes pixel value to imageData */
			pgmValues->imageData[i][j] = grayValue;
		}
	}

	/* Check whether all pixel values have been read in file */
	int grayValueEOF = -1;
	int scanCountEOF = fscanf(inputFile, " %u", &grayValueEOF);
	
	if (scanCountEOF != EOF) {
		
		/* free memory, close file pointer and return error code */
		free(pgmValues->commentLine);
		free(pgmValues->imageData);	
		fclose(inputFile);
		return(badData(argv));
	}

	return READ_SUCCESS;
}

/* 
 * data check for binary images
 */
int dataCheckBinary (pgmStruct *pgmValues, FILE *inputFile, char **argv) {
	
//	unsigned char *dataString = (unsigned char *) malloc(pgmValues->width * pgmValues->height * sizeof(unsigned char));

	int grayValueBin = -1;

	/* Reads in every pixel of file and writes it to 2D array */
	for (int i=0; i < pgmValues->height; i++) {
		for (int j=0; j < pgmValues->width; j++) {
			
			int scanCountDataBin = fread(&grayValueBin, sizeof(unsigned char), 1, inputFile);
	//		printf("%i\n", scanCountDataBin);
	//		printf("%i\n", grayValueBin);

			//if ((scanCountDataBin != 1) || (grayValueBin < -257) || (grayValueBin > 255)) {
			if (scanCountDataBin != 1) {

				/* free memory, close file pointer and return error code */
				free(pgmValues->commentLine);
				free(pgmValues->imageData);	
				fclose(inputFile);
				return(badData(argv));
			}
			
			/* Writes pixel value to imageData */
			pgmValues->imageData[i][j] = grayValueBin;
		}
	}

	/* Check whether all pixel values have been read in file */
	int grayValue = -1;
//  	int scanCount = fscanf(inputFile, " %u", &grayValue);
	int scanCountEOF = fread(&grayValue, sizeof(unsigned char), 1, inputFile);
//	printf("%i", scanCountEOF);
	
	if (scanCountEOF != 1) {

		/* free memory, close file pointer and return error code */
		free(pgmValues->commentLine);
		free(pgmValues->imageData);	
		fclose(inputFile);
		return(badData(argv));
	}

	return READ_SUCCESS;
}
