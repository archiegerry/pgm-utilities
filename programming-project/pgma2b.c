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

//This is the [ int main() ] component of the corresponding utility
//This exists standalone to avoid linking issues

int main(int argc, char **argv)
{
    //Variable definitions
    int errorcode, valid;

    //CLI compliance
	if (argc == 1)			
		{ 
		printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
		return 0;
		} 
		else if (argc != 3)
		{
		printf("ERROR: Bad Argument Count (%s)\n", argv[0]);
		return 1;
		}

    pgmImage *image = image_constructor(argv[1]);

    //Checks if the given PGM file is valid 
    valid = pgmValid(argv[1]);	
	if (valid != 0)		
		{
	  	return valid;
		}

    //Checks to see if the magic number matches the utility
     if (image->magic_number == '5')
        {
        printf("ERROR: Bad Magic Number (%s)\n", argv[1]);
        free(image);	
	    return 3;
        } 

    //Runs the named utility and returns a message if successful
    //Returns an error code if not, however pgmValid should have caught this
    errorcode = pgmA2B(argv[1], argv[2]);
    if (errorcode == 0)
        {
        printf("CONVERTED\n");
        free(image);
        return errorcode;
        } 
	    else
        {
        free(image);
        printf("ERROR: Miscellaneous (Error code: %i)\n", errorcode);
        return errorcode;
        } 
}