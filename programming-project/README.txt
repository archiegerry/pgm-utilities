Created by Archie Alistair Andrew Gerry for the Semester 2 Programming Project

These utilities manipulate PGM image files in various ways. This includes echoing images, comparing two images, converting images from binary to ASCII (and vice-versa), and reducing an image by a given factor. All third-party images used are used for test purposes only.

To run the utilities, use the command:
"make all"
From here, the makefile should create all the excecutables.

To run these type the following:
./pgm<excecutablename> <usage>

<excecutablename> refers to the name of the excecutable
<usage> refers to the following:
	Usage: ./pgmEcho inputImage.pgm outputImage.pgm
	Usage: ./pgmComp inputImage.pgm inputImage.pgm
	Usage: ./pgma2b inputImage.pgm outputImage.pgm
	Usage: ./pgmb2a inputImage.pgm outputImage.pgm
	Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm


