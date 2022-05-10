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


	/* pointer for efficient write code      */

	long nImageBytes = pgmValues->width * pgmValues->height * sizeof(unsigned char);

        for (unsigned char *nextGrayValue = pgmValues->imageData; nextGrayValue < pgmValues->imageData + nImageBytes; nextGrayValue++)
                { /* per gray value */

		/* get next char's column        */
		int nextCol = (nextGrayValue - pgmValues->imageData + 1) % pgmValues->width;

		/* write the entry & whitespace  */
		nBytesWritten = fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );

		/* sanity check on write         */
		if (nBytesWritten < 0)
			{ /* data write failed   */
			/* free memory           */
			free(pgmValues->commentLine);
			free(pgmValues->imageData);

			/* return an error code  */
			return(badOutput(argv));

			} /* data write failed   */
		} /* per gray value */

	/* at this point, we are done and can exit with a success code */
	return EXIT_NO_ERRORS;
}
