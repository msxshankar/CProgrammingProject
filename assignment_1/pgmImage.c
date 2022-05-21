// Programming Project

/*
 * Mayur Shankar
 */

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Header files
 */
#include "pgmImage.h"
#include "pgmCodes.h"

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
