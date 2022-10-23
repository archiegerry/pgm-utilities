CC=gcc
CCFLAGS = -g -std=c99
REDUCEFLAG = -g -lm -std=c99

all: pgmEcho pgmComp pgma2b pgmb2a pgmReduce pgmTile pgmAssemble

pgmEcho:	pgmEcho.c pgmUtilities.h pgmImage.h
	${CC} ${CCFLAGS} -o pgmEcho pgmEcho.c pgmValid.c pgmImage.c pgmImage.h pgmUtilities.h

pgmComp: 	pgmComp.c pgmUtilities.h pgmImage.h
	${CC} ${CCFLAGS} -o pgmComp pgmComp.c pgmB2A.c pgmA2B.c pgmValid.c pgmImage.c pgmImage.h pgmUtilities.h

pgma2b: 	pgma2b.c pgmUtilities.h pgmImage.h
	${CC} ${CCFLAGS} -o pgma2b pgma2b.c pgmA2B.c pgmValid.c pgmImage.c pgmImage.h pgmUtilities.h

pgmb2a:		pgmb2a.c pgmUtilities.h pgmImage.h
	${CC} ${CCFLAGS} -o pgmb2a pgmb2a.c pgmB2A.c pgmValid.c pgmImage.c pgmImage.h pgmUtilities.h

pgmReduce: pgmReduce.c pgmUtilities.h pgmImage.h
	${CC} ${REDUCEFLAG} -o pgmReduce pgmReduce.c pgmB2A.c pgmA2B.c pgmValid.c pgmImage.c pgmImage.h pgmUtilities.h

pgmTile: pgmTile pgmUtilities.h pgmImage.h
	${CC} ${CCFLAGS} -o pgmTile pgmTile.c pgmValid.c pgmImage.c pgmImage.h pgmUtilities.h

pgmAssemble: pgmAssemble pgmUtilities.h pgmImage.h
	${CC} ${CCFLAGS} -o pgmAssemble pgmAssemble.c pgmValid.c pgmImage.c pgmImage.h pgmUtilities.h

clean:
		rm -f pgmEcho pgmComp pgmb2a pgma2b pgmReduce pgmTile pgmAssemble *c.o
