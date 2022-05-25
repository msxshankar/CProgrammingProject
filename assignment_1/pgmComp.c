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
	
	/* Reads in file*/
	int file1Read = read(pgmValuesFile1, inputFile1, argv);

	/* Checks what value is returned and returns if an error has occurred */
	if (file1Read != 0) {
		if (file1Read != 200) {
			if (file1Read != 300) {
				return file1Read;
			}
		}
	}

	fclose(inputFile1);


	/* opens second file and checks if it equals null */
	FILE *inputFile2 = fopen(argv[2], "r");
	
	/* Checks second input file */
	if (inputFile2 == NULL) {
		return(badFileName(argv));
	}

	/*
	 * Allocating memory to struct pointer for second file
	 * For storing image data
	 */
	pgmStruct *pgmValuesFile2 = (pgmStruct *) malloc (sizeof(pgmStruct));
	structInit(pgmValuesFile2);

	/* Reads second file in and checks return values */	
	int file2Read = read(pgmValuesFile2, inputFile2, argv);
	if (file2Read != 0) {
		if (file2Read != 200) {
			if (file2Read != 300) {
				return file2Read;
			}
		}
	}
	
	/* Closes second file */
	fclose(inputFile2);
	
	/* Compares files */
	int final = compare(pgmValuesFile1, pgmValuesFile2);
	return final;
}

/* Compare function */
int compare (pgmStruct *pgmValuesFile1, pgmStruct *pgmValuesFile2) {

	/* Checks comment line difference */
	if (pgmValuesFile1->commentLine != pgmValuesFile2->commentLine) {
		printf("DIFFERENT\n");
		return READ_SUCCESS;	
	}

	/* Checks width difference */	
	if (pgmValuesFile1->width != pgmValuesFile2->width) {
		printf("DIFFERENT\n");
		return READ_SUCCESS;
	}
	
	/* Checks height difference */
	if (pgmValuesFile1->height != pgmValuesFile2->height) {
		printf("DIFFERENT\n");
		return READ_SUCCESS;
	}
	
	/* Checks max gray value difference */
	if (pgmValuesFile1->maxGray != pgmValuesFile2->maxGray) {
		printf("DIFFERENT\n");
		return READ_SUCCESS;
	}
	
	/* Checks image data difference */
	for (int i=0; i < pgmValuesFile1->height; i++) {
       		for (int j=0; j < pgmValuesFile1->width; j++) {
			
			if (pgmValuesFile1->imageData[i][j] != pgmValuesFile2->imageData[i][j])	{
				printf("DIFFERENT\n");
				return READ_SUCCESS;
			}
		}
	}
	
	/* Files are identical */	
	printf("IDENTICAL\n");
	return READ_SUCCESS;
}
