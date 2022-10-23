/***********************************/
/* COMP 1921M Programming Project  */
/* 2021-22 Spring Semester         */
/*                                 */
/* Archie Gerry                    */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "pgmUtilities.h"
#include "pgmImage.h"

//This program converts an ASCII PGM to a Binary PGM
//Will not be called unless pgmValid has been called prior

int pgmA2B (char *x, char *y) 
{
    //Creates an image based on the supplied file
    pgmImage *image = image_constructor(x);
    int valid = pgmValid(x);	
	if (valid != 0)		
		{
	  	return valid;
		}
	
    //Begin writing to the output file
    FILE *outputFile = fopen(y, "wb");
    if (outputFile == NULL) {
        printf("ERROR: Output Failed (%s)\n", y);
        return 9;
    }  
    fprintf(outputFile, "P5\n");
    fprintf(outputFile, "%u %u\n%u\n", image->width, image->height, image->maxGray);

    //Writes the required data to the file using the existing dimensions as the basis for the size to be written
    fwrite(image->imageData, 1, (image->height * image->width * sizeof(unsigned char)), outputFile);

    //Tidiness
    free(image);
    fclose(outputFile);
	return 0;
}
