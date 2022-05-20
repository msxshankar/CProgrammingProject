// Programming Project COMP1921

// Mayur Shankar

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Dependencies
 */
#include "pgmRead.h"
#include "pgmImage.h"
#include "pgmError.h"
#include "pgmCodes.h"
#include "pgmWrite.h"

int writeCheck (pgmStruct *pgmValues, FILE *outputFile, char **argv) {

	/* write magic number, size & gray value */
	size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", pgmValues->width, pgmValues->height, pgmValues->maxGray);

	/* check that dimensions wrote correctly */
	if (nBytesWritten < 0)
		{ /* dimensional write failed    */
		/* free memory                   */
		free(pgmValues->commentLine);
		free(pgmValues->imageData);


		/* return an error code          */
		return(badOutput(argv));
		} /* dimensional write failed    */


	/*
	 * Writing from 2D array to file
	 */
	
	for (int i=0; i < pgmValues->height; i++) {
		for (int j=0; j < pgmValues->width; j++) {

			int nextCol = (pgmValues->width - j) - 1;

			nBytesWritten = fprintf(outputFile, "%d%c", pgmValues->imageData[i][j], (nextCol ? ' ' : '\n') );

			if (nBytesWritten < 0)	{
				/* free memory           */
				free(pgmValues->commentLine);
				free(pgmValues->imageData);

				/* return an error code  */
				return(badOutput(argv));
			}
		}
	}

	/* at this point, we are done and can exit with a success code */
	return EXIT_NO_ERRORS;
}
        
