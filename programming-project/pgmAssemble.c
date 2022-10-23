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

int main(int argc, char **argv)
{
    if (argc == 1)			
			{ 
			printf("Usage: ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+\n");
			return 0;
			}

    pgmImage *image = image_constructor(argv[1]);
		int valid = pgmValid(argv[1]);	
		if (valid != 0)		
			{
			return valid;
			}
    
    printf("ASSEMBLED");
    free(image);
    return 0;
}
