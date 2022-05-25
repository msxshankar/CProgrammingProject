// Programming Project

/*
 * Mayur Shankar
 */

/*
 * Defining error codes
 */
#define EXIT_NO_ARGS 0
#define EXIT_NO_ERRORS 0
#define EXIT_WRONG_ARG_COUNT 1
#define EXIT_BAD_INPUT_FILE 2
#define EXIT_BAD_MAGIC_NUMBER 3
#define EXIT_BAD_COMMENT_LINE 4
#define EXIT_BAD_DIMENSIONS 5
#define EXIT_BAD_GRAY 6
#define EXIT_BAD_MALLOC 7
#define EXIT_BAD_DATA 8
#define EXIT_OUTPUT_FAILED 9
#define EXIT_BAD_LAYOUT 10
#define EXIT_MISC 100

/*
 * Defining boundary values
 */
#define MAGIC_NUMBER_RAW_PGM 0x3550
#define MAGIC_NUMBER_ASCII_PGM 0x3250
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65535
#define MAX_COMMENT_LINE_LENGTH 128

#define READ_SUCCESS 0
#define MAX_COMMENT_LINE_LENGTH 128

#define MAX_GREY_VALUE 255
#define MIN_GREY_VALUE 0
#define WIDTH 0
#define HEIGHT 0

/* 
 * ASCII and Binary
 */
#define READ_ASCII 200
#define READ_BINARY 300

/* Program Names */
#define PGMA2B 20
#define PGMB2A 21


