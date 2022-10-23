#ifndef PGM_IMAGE
#define PGM_IMAGE

//A pgmImage object contains all the neccesary information to reconstruct a pgm image
typedef struct __pgmImage 
{
    unsigned char *imageData;
    int width, height, maxGray;
    int hasP;
    char magic_number;
    char errorcode;
    char *commentLine;
    char *commentString;
} pgmImage;

pgmImage *image_constructor(char* filename);
pgmImage *blank_image_constructor();

#endif

