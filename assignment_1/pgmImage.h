// COMP1921 Programming Project

/*
 * Mayur Shankar
 */

/*
 * Libraries
 */
#include <stdio.h>

/*
 * Header files
 */
#include "pgmCodes.h"


/*
 * Struct containing values for the pgmImage
 */
typedef struct pgmStruct {

	/*
	 * magic number stored as two bytes
	 */
	unsigned char magicnumber[2];
	unsigned short *magicNumber;
	
	/*
	 * comment line pointer
	 */	
	char *commentLine;

	/*
	 * logical width & height
	 */
	unsigned int width;
	unsigned int height;

	/*
	 * maximum gray value
	 */
	unsigned int maxGray;

	/*
	 * double pointer to raw image data
	 * will be used as a 2D array
	 */
	unsigned char **imageData;
} pgmStruct;


/*
 * Function declarations
 */
void structInit(pgmStruct *pgmValues);

