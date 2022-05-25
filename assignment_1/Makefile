# COMP 1921 Programming Project                 

# Assignement 1 & 2
# 25/05/22
  
# Mayur Shankar  
  
   
# Makefile  

 
# Compiler and compiler flags 
CC = gcc
CCFLAGS = -g -std=c99 -Wall

# All routines
MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of subordinate routines for pgmEcho
PGM_ECHO_MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of subordinate routines for pgmComp
PGM_COMP_MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of subordinate routines for pgma2b
PGM_A2B_MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of subordinate routines for pgmb2a
PGM_B2A_MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of subordinate rountines for pgmReduce
PGM_REDUCE_MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of main routines
MAIN= pgmEcho.o pgmComp.o pgma2b.o pgmb2a.o pgmReduce.o

# Set of executables
TARGETS = pgmEcho pgmComp pgma2b pgmb2a pgmReduce
 

# Compiles all files 
all:    ${TARGETS}	

# Removes all object files (.o), executables and temporary files
clean:
	rm -f ${TARGETS} ${MAIN} ${MODULES} *.o


# Links object files for pgmEcho
pgmEcho: 	pgmEcho.o ${PGM_ECHO_MODULES}
	${CC} ${CCFLAGS} -o $@ pgmEcho.o ${PGM_ECHO_MODULES}

# Links object files for pgmComp
pgmComp:     	pgmComp.o ${PGM_COMP_MODULES}
	${CC} ${CCFLAGS} -o $@ pgmComp.o ${PGM_COMP_MODULES}

# Links object files for pgma2b
pgma2b:     	pgma2b.o ${PGM_A2B_MODULES}
	${CC} ${CCFLAGS} -o $@ pgma2b.o ${PGM_A2B_MODULES}

# Links object files for pgmb2a
pgmb2a:     	pgmb2a.o ${PGM_B2A_MODULES}
	${CC} ${CCFLAGS} -o $@ pgmb2a.o ${PGM_B2A_MODULES}

# Links object files for pgmReduce
pgmReduce:     	pgmReduce.o ${PGM_REDUCE_MODULES}
	${CC} ${CCFLAGS} -o $@ pgmReduce.o ${PGM_REDUCE_MODULES}


# dependencies
depend: 
	makedepend -Y *.c

# rules
.SUFFIXES: .o .c
.c.o:
	${CC} ${CCFLAGS} -c -o $*.o $*.c

# program dependencies
pgmEcho.o: pgmImage.h pgmError.h pgmArgument.h pgmRead.h pgmWrite.h
pgmComp.o: pgmComp.h pgmImage.h pgmError.h pgmArgument.h pgmRead.h pgmWrite.h
pgma2b.o: pgmImage.h pgmError.h pgmArgument.h pgmRead.h pgmWrite.h
pgmb2a.o: pgmImage.h pgmError.h pgmArgument.h pgmRead.h pgmWrite.h
pgmReduce.o: pgmImage.h pgmError.h pgmArgument.h pgmRead.h pgmWrite.h
pgmErrors.o: pgmErrors.h 
pgmArgument.o: pgmArgument.h
pgmImage.o: pgmImage.h
pgmRead.o: pgmRead.h
pgmWrite.o: pgmWrite.h
 
 
