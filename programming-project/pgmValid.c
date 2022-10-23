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

//Defines relevant constants
#define RAW_MAGIC_NUMBER 53
#define ASCII_MAGIC_NUMBER 50
#define MAX_COMMENT_LENGTH 128
#define MAX_DIMENSION 65535
#define MIN_DIMENSION 0
#define MAX_GRAY_VALUE 255

//This utiliy is intended to verify a given pgmImage object and determine whether it is compliant
//It cannot be called as its own program, and rather is used by other programmes for validation

int pgmValid(char *x) 
    {
    //Creates an image
    pgmImage *image = image_constructor(x);
    if (image == NULL)
    {
        free(image);
        printf("ERROR: Miscellaneous (Failed to create pgmImage object)\n");
        return 100;
    }

    //Indicates that there has been an error creating an image
    //Validation is needed throughout the image creation process, so these codes denote different error stages
    //The validation done after is redundancy for empty images created by utilities like pgmReduce 
    if (image->errorcode != 0)
    {
        if (image->errorcode == 7) 
        {
            free(image);
            printf("ERROR: Image Malloc Failed (%s)\n", x);
            return 7;
        }

        if (image->errorcode == 8) 
        {
            free(image);
            printf("ERROR: Bad File Name (%s)\n", x);
            return 2;
        }

        if (image->errorcode == 9) 
        {
            free(image);
            printf("ERROR: Bad Data (%s)\n", x);
            return 8;
        }

        if (image->errorcode == 4) 
        {
            free(image);
            printf("ERROR: Bad Comment Line (%s)\n", x);
            return 4;
        }

        if (image->errorcode == 5) 
        {
            free(image);
            printf("ERROR: Bad Dimensions (%s)\n", x);
            return 5;
        }

        if (image->errorcode == 6) 
        {
            free(image);
            printf("ERROR: Bad Max Gray Value (%s)\n", x);
            return 6;
        }
    }
    
    //No P means the magic number is corrupted
        if (image->hasP == 0)
        {
        printf("ERROR: Bad Magic Number (%s)\n", x);
        free(image);
        return 3;
        }

    //If the number that proceeds the P is not 2 or 5 then it is not defined as a pgm file
    if ((image->magic_number != RAW_MAGIC_NUMBER) && (image->magic_number != ASCII_MAGIC_NUMBER))
        {
        printf("ERROR: Bad Magic Number (%s)\n", x);
        free(image);
        return 3;
        } 

    //If the size of the comment line is too large then an error will occur
    if ((sizeof(image->commentLine) > MAX_COMMENT_LENGTH) || (sizeof(image->commentString) > MAX_COMMENT_LENGTH))
        {
        printf("ERROR: Bad Comment Line (%s)\n", x);
        free(image);
        return 4;
        }

    //The width cannot be too high
    if (image->width > MAX_DIMENSION)
        {
        printf("%d\n", image->width);
        printf("ERROR: Bad Dimensions (%s)\n", x);
        free(image);
        return 5;
        }
    
    //The height cannot be too high
    if (image->height > MAX_DIMENSION)
        {
        printf("%d\n", image->width);
        printf("ERROR: Bad Dimensions (%s)\n", x);
        free(image);
        return 5;
        }

    //The width cannot be too low
    if (image->width < MIN_DIMENSION)
        {
        printf("%d\n", image->width);
        printf("ERROR: Bad Dimensions (%s)\n", x);
        free(image);
        return 5;
        }

    //The height cannot be too low
    if (image->height < MIN_DIMENSION)
        {
        printf("%d\n", image->width);
        printf("ERROR: Bad Dimensions (%s)\n", x);
        free(image);
        return 5;
        }

    //The max grey value must not exceed a cetrain value
    if (image->maxGray > MAX_GRAY_VALUE)
        {
        printf("ERROR: Bad Max Gray Value (%s)\n", x);
        free(image);
        return 6;
        }

    //The max grey value can never be negative
    if (image->maxGray < 0)
        {
        printf("ERROR: Bad Max Gray Value (%s)\n", x);
        free(image);
        return 6;
        }    
    
    //Success!
    free(image);    
    return 0;
    }

