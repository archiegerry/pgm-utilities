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


//This program converts a Binary PGM to an ASCII PGM

int pgmB2A (char *x, char *y) 
{
    //Variable definition
    int count= 0;

    //Creates an image based on the supplied file
	pgmImage *image = image_constructor(x);
    int valid = pgmValid(x);	
	if (valid != 0)		
		{
	  	return valid;
		}

    //Begin writing to the output file
    FILE *outputFile = fopen(y, "w");
    if (outputFile == NULL) {
        printf("ERROR: Output Failed (%s)\n", y);
        return 9;
    } 
    fprintf(outputFile, "P2\n");
    fprintf(outputFile, "%u %u\n%u\n", image->width, image->height, image->maxGray);

    //Writes each number with a space, as well as a newline once width is reached
    for (int i = 0; i < (image->height * image->width * sizeof(unsigned char)); i++)
        {
        count++;
        fprintf(outputFile, "%u ", image->imageData[i]);
        //Count is effectively the height
        if (count == image->width)
            {
            fprintf(outputFile, "\n");
            count = 0;
            }
        }

    //Tidiness
    free(image);
    fclose(outputFile);
    return 0;
}

 