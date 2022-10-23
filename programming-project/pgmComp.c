/***********************************/
/* COMP 1921M Programming Project  */
/* 2021-22 Spring Semester         */
/*                                 */
/* Archie Gerry                    */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgmUtilities.h"
#include "pgmImage.h"

//This program compares two PGM files and determines whether they are logically equal

int main(int argc, char **argv) 
  	{
    //Variable declaration
    int valid = 0;
		int new_file_one = 0, new_file_two = 0;

    //CLI compliance
    if (argc == 1)			
		{ 
		printf("Usage: %s inputImage.pgm inputImage.pgm\n", argv[0]);
		return 0;
		} else if (argc != 3)
		{
		printf("ERROR: Bad Argument Count (%s)\n", argv[0]);
		return 1;
		}
    
    //Check if PGM files are valid 
    valid = pgmValid(argv[1]);	
	if (valid != 0)		
		{
	  	return valid;
		}

	valid = pgmValid(argv[2]);	
	if (valid != 0)		
		{
	  	return valid;
		}

	//Creates images baes on the given files once validation has occured
	pgmImage *imageone = image_constructor(argv[1]);
	pgmImage *imagetwo = image_constructor(argv[2]);

	//Compares the image widths'
	if (imageone->width != imagetwo->width)
		{
		printf("DIFFERENT\n");
		return 0;
		}

	//Compares the image heights'
	if (imageone->height != imagetwo->height)
		{
		printf("DIFFERENT\n");
		return 0;
		}

	//Compares the image maxGrays'
	if (imageone->maxGray != imagetwo->maxGray)
		{
		printf("DIFFERENT\n");
		return 0;
		}

	//If either of the provided files are in binary, this changes them to ASCII
	//This allows me to use the strcmp function to determine array equality
	//This is due to the fact that strcmp is not binary-safe
	//It also makes comparison easier as both files are guaranteed to be in the same form
	if (imageone->magic_number == '5')
		{
		pgmB2A(argv[1], "temporary_one.pgm");
		pgmImage *imageone = image_constructor("temporary_one.pgm");
		remove("temporary_one.pgm");
		}

	//Temporary files are created in order to utilise the pgmB2A utility (which takes a filename)
	if (imagetwo->magic_number == '5')
		{
		pgmB2A(argv[2], "temporary_two.pgm");
		pgmImage *imagetwo = image_constructor("temporary_two.pgm");
		remove("temporary_two.pgm");
		}

	//If the data is equal then strcmp will return zero (strcmp ignores whitespace)
	if ((strcmp(imageone->imageData, imagetwo->imageData) == 0))
		{
		printf("IDENTICAL\n");
		free(imageone);
		free(imagetwo);
		return 0;
		} 
	else
		{
		free(imageone);
		free(imagetwo);
		printf("DIFFERENT\n");
		return 0;
		}				
}
		
  
