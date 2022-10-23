/***********************************/
/* COMP 1921M Programming Project  */
/* 2021-22 Spring Semester         */
/*                                 */
/* Archie Gerry                    */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pgmUtilities.h"
#include "pgmImage.h"

//This utility takes a given pgmImage and reduces it by a reduction factor
//Image creation and validation is done by pgmImage and pgmValid

int main(int argc, char **argv)
    {
    //Variable definitions
     int newWidth, newHeight;
    
    //CLI compliance
    if (argc == 1)			
		{ 
		printf("Usage: %s inputImage.pgm reduction_factor outputImage.pgm\n", argv[0]);
		return 0;
		} else if (argc != 4)
		{
		printf("ERROR: Bad Argument Count (%s)\n", argv[0]);
		return 1;
		} 
    
    //This section ensures that the second argument must be an integer
    if ((atoi(argv[2]) == 0) || (atoi(argv[2]) == 1) || (atoi(argv[2]) < 0))
        {
        printf("ERROR: Miscellaneous (%s)\n", argv[0]);
		return 100;
        }

    //Check if the given PGM file is valid 
    int valid = pgmValid(argv[1]);	
	if (valid != 0)		
		{
	  	return valid;                                                      
		}

    //Builds the image from the given file                                                                                                             
    pgmImage *inputImage = image_constructor(argv[1]);
    //Creates a blank image for use later
    pgmImage *outputImage = blank_image_constructor();

    //Changes the input image to its ASCII counterpart if the binary version is supplied
    if (inputImage->magic_number == '5')
        {
        pgmB2A(argv[1], "temporary.pgm");
        pgmImage *inputImage = image_constructor("temporary.pgm");
        remove("temporary.pgm");
        }

    //Creates the new dimensions using the ceiling function + 1 to ensure that the dimensions are always rounded up 
    //The check below is to ensure that if it is perfectly divisible, the plus one is not included as it causes image corruption
    if ((inputImage->width)%(atoi(argv[2])) == 0)
        {
        newWidth = ((inputImage->width)/atoi(argv[2]));
        } else
        {
        newWidth = 1 + ceil((inputImage->width)/atoi(argv[2]));
        }

    //Creates the new dimensions using the ceiling function + 1 to ensure that the dimensions are always rounded up 
    //The check below is to ensure that if it is perfectly divisible, the plus one is not included as it causes image corruption
    if ((inputImage->height)%(atoi(argv[2])) == 0)
        {
        newHeight = ((inputImage->height)/atoi(argv[2]));
        } else
        {
        newHeight = 1 + ceil((inputImage->height)/atoi(argv[2]));
        }
    
    //Determines the size of the supplied image
    size_t imageSize = (inputImage->width * inputImage->height * sizeof(unsigned char));
    //Determines the size for the image we will create
    size_t newImageSize = (newWidth * newHeight * sizeof(unsigned char));
    //Populates the fields for the image we will create
    outputImage->width = newWidth;
    outputImage->height = newHeight;
    outputImage->hasP = 1;
    outputImage->magic_number = '2';
    outputImage->errorcode = 0;
    outputImage->maxGray = inputImage->maxGray;
    outputImage->imageData = (unsigned char *) malloc(newImageSize);

    //J refers to the start of the outputImage->imageData array
    int height = 0, j = 0, count = 0;

    //This for loop will iterate over every pixel of the input image
    for (size_t i = 0; i < imageSize; i++)
        {
        count++;
        //The count keeps track of the height of the input image
        if ((count) == inputImage->width)
            {
            height++;
            count = 0;    
            }

        //This is the real magic 
        //The pixel is only transferred to the output image once the
        //height MOD reduction factor is zero (i.e a multiple) AND
        //when this is also the case for the selected pixel of the input image
        //(i.e the width)
        if (((height % (atoi(argv[2]))) == 0) && ((i % (atoi(argv[2])))==0))
            {
            outputImage->imageData[j] = inputImage->imageData[i];
            j++;
            }            
        }
        
    //Then this data in the outputImage is written to a file.
    FILE *outputFile = fopen(argv[3], "w");
    if (outputFile == NULL) {
        printf("ERROR: Output Failed (%s)\n", argv[3]);
        return 9;
    }
    fprintf(outputFile, "P2\n");
    fprintf(outputFile, "%u %u\n%u\n", outputImage->width, outputImage->height, outputImage->maxGray);
    count = 0;
    //This is done based on the calculated size of the new image
    for (int i = 0; i < newImageSize; i++)
        {
        count++;
        fprintf(outputFile, "%u ", outputImage->imageData[i]);
        if (count == outputImage->width)
            {
            fprintf(outputFile, "\n");
            count = 0;
            }
        }
    
    //Tidiness
    free(inputImage);
    free(outputImage);
    fclose(outputFile);
    printf("REDUCED\n");
    return 0;
    }