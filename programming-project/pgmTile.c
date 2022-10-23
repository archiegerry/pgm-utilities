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

//This is a stub file which has yet to be implemented.

int main(int argc, char **argv)
{
		//Ensures the special usage mesage is shown for no CLA's
    if (argc == 1)			
			{ 
			printf("Usage: ./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm\n");
			return 0;
			} else if (argc != 4)
			{
			//The argument count must be 4 for pgmTile
			printf("ERROR: Bad Argument Count (%s)\n", argv[0]);
			return 1;
			}

	//Creates an image based on the ouputImage
  pgmImage *image = image_constructor(argv[1]);
	//Validates the image based on pgmValid
	int valid = pgmValid(argv[1]);	
	if (valid != 0)		
		{
		return valid;
		}
    
  printf("TILED");
  free(image);
  return 0;
}
