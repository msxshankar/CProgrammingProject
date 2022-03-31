// Programming Project COMP1921

// Mayur Shankar

/*
 * Libraries
 */
#include <stdio.h>

/*
 * Dependencies
 */
#include "pgmRead.h"
#include "pgmImage.h"
#include "pgmError.h"

#define READ_SUCCESS 0
#define MAGIC_NUMBER_ASCII_PGM 0x3250 

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
