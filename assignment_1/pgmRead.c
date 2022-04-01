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

#define READ_SUCCESS 0
#define MAGIC_NUMBER_ASCII_PGM 0x3250 
#define MAX_COMMENT_LINE_LENGTH 128
#define EXIT_BAD_INPUT_FIL

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
