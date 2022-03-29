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

#define MAGIC_NUMBER_ASCII_PGM 0x3250 

int magicNumberCheck(pgmStruct *pgmValues, FILE *inputFile, char **argv) {
	pgmValues->magicnumber[0] = getc(inputFile);
	pgmValues->magicnumber[1] = getc(inputFile);

	printf("%d\n", pgmValues->magicNumber[0]);
	printf("%d", pgmValues->magicNumber[1]);
	printf("%hu", *(pgmValues->magicNumber));

	  if (*(pgmValues->magicNumber) != MAGIC_NUMBER_ASCII_PGM) {
	 /*
	  * close the file
	  */
		 fclose(inputFile);
   
		 /* print an error message */
		 printf("Error: Failed to read pgm image from file %s\n", argv[1]);
		 /* and return                    */                                        

		 return 1;
	}
	  else {
		  return 0;
	}
 }
