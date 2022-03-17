// Programming Project

// Due: 18/03/22
// Mayur Shankar

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>


#include "pgmImage.h"


/*
 * Macros
 */
#define MAX_COMMENT_LINE_LENGTH 128

/*
 * Initialising struct
 */
void structInit (pgmStruct *pgmValues) {
	pgmValues->magicnumber[0] = '0';
	pgmValues->magicnumber[1] = '0';
	pgmValues->magicNumber = (unsigned short *) pgmValues->magicnumber;
	pgmValues->commentLine = NULL;
	pgmValues->width = 0;
	pgmValues->height = 0;
	pgmValues->maxGray= 255;
	pgmValues->imageData = NULL;
}

/*
 * Reading in magic number
 */
void magicNumberRead (pgmStruct *pgmValues, FILE **readFile) {
	pgmValues->magicnumber[0] = getc(*readFile);
	pgmValues->magicnumber[1] = getc(*readFile);
}	

/*
 * Reading in comment line
 */
void commentLine (pgmStruct *pgmValues) {
	pgmValues->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH);
}

/*
 * Reading in image data
 */
void imageData (pgmStruct *pgmValues) {
	long nImageBytes = pgmValues->width * pgmValues->height * sizeof(unsigned char);
	pgmValues->imageData = (unsigned char *) malloc(nImageBytes);
}
