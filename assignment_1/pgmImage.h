// Programming Project


/*
 * Mayur Shankar
 */

/*
 * Libraries
 */
#include <stdio.h>

#include "pgmCodes.h"

/*
 * Struct containing values for the pgmImage
 */
typedef struct pgmStruct {

	/*
	 * magic number
	 * stored as two bytes
	 */
	unsigned char magicnumber[2];
	unsigned short *magicNumber;
	
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
	 * pointer to raw image data
	 */
	unsigned char **imageData;
} pgmStruct;


/*
 * Function declarations
 */
void structInit(pgmStruct *pgmValues);
void magicNumberRead(pgmStruct *pgmValues, FILE **readFile);
void commentLine(pgmStruct *pgmValues);
void imageData (pgmStruct *pgmValues);

