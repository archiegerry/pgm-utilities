/***********************************/
/* COMP 1921M Programming Project  */
/* 2021-22 Spring Semester         */
/*                                 */
/* Archie Gerry and Hamish Carr    */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "pgmUtilities.h"
#include "pgmImage.h"

//This utility builds off of the original pgmEcho by Hamish Carr
//It will take an ascii or binary pgm and echo it

int main(int argc, char **argv)
	{ 
	//CLI compliance
	if (argc == 1)			
		{ 
		printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
		return 0;
		} else if (argc != 3)
		{
		printf("ERROR: Bad Argument Count (%s)\n", argv[0]);
		return 1;
		}

	//This pgmValid function determines if a given PGM file is valid/compliannt
	//Non-zero valid indicates an error has occured

	//Creates an image based on the given file
  pgmImage *image = image_constructor(argv[1]);
	int valid = pgmValid(argv[1]);	
	if (valid != 0)		
		{
			return valid;
		}
	//Opens a new output file with the designated name	 
	FILE *outputFile = fopen(argv[2], "w");
	if (outputFile == NULL)
		{ 
		free(image);
		free(outputFile);
		printf("ERROR: Output Failed (%s)\n", argv[2]);	
		return 9;
		} 

	//Writes the dimensions
  size_t bytesWritten = fprintf(outputFile, "P%c\n%d %d\n%d\n", image->magic_number, image->width, image->height, image->maxGray);
	if (bytesWritten < 0)
		{ 
		free(image);
		free(outputFile);
		printf("ERROR: Bad Layout \n");	
		return 10;
		} 
	
	//Sets the number of bytes to be written to using the dimensions as a basis
	long imageBytes = image->width * image->height * sizeof(unsigned char);

	//If the file is ASCII, it will echo in ASCII
	if (image->magic_number == '2')
		{
		size_t nextCol;
		//Copied from the original pgmEcho
		//Used to echo the file with the correct amount of whitespace
		for (unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + imageBytes; nextGrayValue++)
        { 
				nextCol = (nextGrayValue - image->imageData + 1) % image->width;
				bytesWritten = fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );
				//Something seriously wrong must have occured for negative bytes to be written 
				if (bytesWritten < 0)
					{ 
					free(image);
					free(outputFile);
					printf("ERROR: Bad Layout \n");					
					return 10;
					} 
				}
		}

	//If the file is Binary, it will echo in Binary
	if (image->magic_number == '5')
		{
		//So easy!!
		fwrite(image->imageData, 1, imageBytes, outputFile);
		}
	
	//Tidiness
  printf("ECHOED\n");
	fclose(outputFile);
	free(image);
	free(outputFile);
	return 0;
	}




    