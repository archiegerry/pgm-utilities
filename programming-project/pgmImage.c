/***********************************/
/* COMP 1921M Programming Project  */
/* 2021-22 Spring Semester         */
/*                                 */
/* Archie Gerry                    */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   
#include "pgmImage.h"
#include "pgmUtilities.h"

//Defines some neccesary validation values
#define MAX_DIMENSION 65535
#define MIN_DIMENSION 0
#define MAX_GRAY_VALUE 255
#define MAX_COMMENT_LENGTH 128
#define MAX_DATA_SIZE 4294836225


//This utiltiy forms the basis for the rest of the project
//It is the constructor for the image object defined in image.h
//These images are used to build pgm files from a set of attributes
//However, it is called standalone - validation is done (where applicable) externally in pgmValid.

//This is the constructor for when a file already exists
pgmImage *image_constructor(char* filename) 
    {
    //Creates the image object and allocates it space on the heap
    pgmImage *image = malloc(sizeof(pgmImage));
    if (image == NULL)
        {
         //Allows pgmValid to know there has been an error with the image malloc
        image->errorcode = 7;
        return image;
        }

    //Opens the file from the provided name
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL)
        {
        //Allows pgmValid to know there has been an error with the file name
        image->errorcode = 8;
        return image;
        }
    
    //Ensures that the pgm file has a full magic number component
    image->magic_number = getc(inputFile);
    if (image->magic_number == 'P')
        {
        image->hasP = 1;
        } 
    else
        {
        image->hasP = 0;
        return image;
        }
    
    //Sets the magic number field of the image object (2 or 5)
    image->magic_number = getc(inputFile);
    fscanf(inputFile, " ");

    //This section will determine if a comment is present
    char nextChar = fgetc(inputFile);
    if (nextChar == '#')
		{ 
		image->commentLine = (char *) malloc(MAX_COMMENT_LENGTH);
        int count = 0;
        int finished = 0;	
        //Once comment has been established it will count each comment character
		while (finished != 1)
            {
            nextChar = fgetc(inputFile);
            count++;
            //If the comment length exceeds the max length, an error is thrown
            if (count > MAX_COMMENT_LENGTH)
                {
                image->errorcode = 4;
                return image;
                }
            
            //If the end of the comment is reached, the loop exits
            if (nextChar == '\n')
                {
                ungetc(nextChar, inputFile);
                finished = 1;
                }            
            }
		} 
	else
        {        
        image->commentLine = NULL;
        image->commentString = NULL;
		ungetc(nextChar, inputFile);
		}

    //Scans in the dimensions
    fscanf(inputFile, "%d %d %d ", &(image->width), &(image->height), &(image->maxGray));
    
    //Validation is required internally in order to proceed with image
    if ((image->width > MAX_DIMENSION) || (image->height > MAX_DIMENSION) || (image->width < MIN_DIMENSION) || (image->height < MIN_DIMENSION))
    {
        image->errorcode = 5;
        return image;
    }

    if ((image->maxGray > MAX_GRAY_VALUE) || (image->maxGray < 0))
    {
        image->errorcode = 6;
        return image;
    }
    
    
    //If the file is a ASCII
    if (image->magic_number == '2')
        {
        int grayValue = -1;
        long imageBytes = image->width * image->height * sizeof(unsigned char);
        //Sets the size of imageData field based on the other attributes
	    image->imageData = (unsigned char *) malloc(imageBytes);
        if (image->imageData == NULL)
            {
             //Allows pgmValid to know there has been an error with the image malloc
            image->errorcode = 7;
            return image;
            }
        //Copied from the original pgmEcho - scans in charaters into imageData using nextGrayValue to iterate over imagData
        for (unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + imageBytes; nextGrayValue++)
		    { 
		    grayValue = -1;
		    fscanf(inputFile, " %u", &grayValue);
            if (grayValue < 0 || grayValue > 255)
            {
                //Allows pgmValid to know there has been an error with the data
                image->errorcode = 9;
                return image;
            }   
		    *nextGrayValue = (unsigned char) grayValue;
		    }
        
        fscanf(inputFile, " ");
        //The next character that should be retrieved should be the EOF
        char tooLong = fgetc(inputFile);
        //If it is not then this indicates the data is misformatted (bad data)
        if ((tooLong != EOF) && (tooLong != '\n'))
            {
            image->errorcode = 9;
            return image; 
            }
        }

    //If the file is Binary
    if (image->magic_number == '5')
        {
        long imageBytes = image->width * image->height * sizeof(unsigned char);
         //Sets the size of imageData field based on the other attributes
	    image->imageData = (unsigned char *) malloc(imageBytes);
        if (image->imageData == NULL)
            {
            image->errorcode = 7;
            return image;
            }
        
        //Scans in anty whitespace before the read
        fscanf(inputFile, " ");
        //totalElements is the number of elements that fread has put into imageData
        size_t totalElements = fread(image->imageData, 1, imageBytes, inputFile);
        //If totalElements differs from imageBytes, then this indicates that EOF was reached
        //This means that there was not enough data in the file, so the image has bad data
        if (totalElements != imageBytes)        
        {
            image->errorcode = 9;
            return image;
        }
        //Scans in anty whitespace after the read
        fscanf(inputFile, " ");

        //The next character that should be retrieved should be the EOF
        char tooLong = fgetc(inputFile);
        //If it is not then this indicates the data is misformatted (bad data)
        if ((tooLong != EOF) && (tooLong != '\n'))
            {
            image->errorcode = 9;
            return image; 
            }
        }
    
    image->errorcode = 0;
    fclose(inputFile);
    return image;
    }

//The blank constructor is required for pgmReduce as we have to create an image from scratch
pgmImage *blank_image_constructor()
    {
    pgmImage *image = malloc(sizeof(pgmImage));
    image->hasP = 0;
    image->magic_number = ' ';
    image->height = 0;
    image->width = 0;
    image->maxGray = 0;
    image->errorcode = 0;
    image->commentLine = NULL;
    image->commentString = NULL;
    image->imageData = NULL;
    return image;
    }



