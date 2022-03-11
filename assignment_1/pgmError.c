// Programming Project


/*
 * Mayur Shankar
 */


#include <stdio.h>

#include "pgmError.h"


/*
 * defining exit return values
 */
#define EXIT_NO_ERRORS 0
#define EXIT_WRONG_ARG_COUNT
#define EXIT_BAD_INPUT_FILE
#define EXIT_BAD_OUTPUT_FILE

#define MAGIC_NUMBER_RAW_PGM 0x3550
#define MAGIC_NUMBER_ASCII_PGM 0x3250
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65536
#define MAX_COMMENT_LINE_LENGTH 128


/*
 * functions for returning error codes
 */
int noArgumentCount (char **argv) {
	/*
	 * prints error message
	 */
	printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);

	return EXIT_NO_ERRORS;
}
