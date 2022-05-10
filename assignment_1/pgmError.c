// Programming Project


/*
 * Mayur Shankar
 */


#include <stdio.h>

#include "pgmError.h"
#include "pgmCodes.h"

/*************************************
 * Functions for returning error codes
 ************************************/

/*
 * If a bad file name is given
 * Returns value and prints string
 */
int badFileName(char **argv) {
	printf("ERROR: Bad File Name (%s)\n", argv[1]);
	return EXIT_BAD_INPUT_FILE;
}

int badMagicNumber(char **argv) {
	printf("ERROR: Bad Magic Number (%s)\n", argv[1]);
	return EXIT_BAD_MAGIC_NUMBER;
}

int badCommentLine(char **argv) {
	printf("ERROR: Bad Comment Line (%s)\n", argv[1]);	
	return EXIT_BAD_COMMENT_LINE;
}
			
int badDimensions(char **argv) {
	printf("ERROR: Bad Dimensions (%s)\n", argv[1]);
	return EXIT_BAD_DIMENSIONS;
}

int badGrayValue(char **argv) {
	printf("ERROR: Bad Max Gray Value (%s)\n", argv[1]);
	return EXIT_BAD_GRAY;
}

int badMalloc(char **argv) {
	printf("ERROR: Image Malloc Failed");
	return EXIT_BAD_MALLOC;
}

int badData(char **argv) {
	printf("ERROR: Bad Data (%s)\n", argv[1]);
	return EXIT_BAD_DATA;
}

int badOutput(char **argv) {
	printf("ERROR: Output Failed (%s)\n", argv[2]);
	return EXIT_OUTPUT_FAILED;
}
