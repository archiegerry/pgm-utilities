To run the submission, use the command:
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
	Usage: ./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm
	Usage: ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+

