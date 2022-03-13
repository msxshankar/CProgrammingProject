// Programming Project


/*
 * Mayur Shankar
 */


/*
 * Collecting constants
 */
#define MAX_GREY_VALUE 255
#define MIN_GREY_VALUE 0
#define WIDTH 0
#define HEIGHT 0


/*
 * Struct containing values for the pgmImage
 */

struct pgm_image {

	/*
	 * magic number
	 * stored as two bytes
	 */
	unsigned char magic_number[2];
	unsigned short *magic_Number;
	
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
	unsigned char *imageData;
};
