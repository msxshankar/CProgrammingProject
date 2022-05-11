# COMP 1921 Programming Project                 
#
# Assignement 1
# 18/03/22
#  
# Mayur Shankar  
#  
#   
# Makefile  

 
# Compiler and compiler flags 
CC = gcc
CCFLAGS = -g -std=c99 -Wall

# All routines
MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of subordinate routines for pgmEcho
PGM_ECHO_MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

PGM_COMP_MODULES = pgmError.o pgmArgument.o pgmImage.o pgmRead.o pgmWrite.o

# Set of main routines
MAIN= pgmEcho.o pgmComp.o

# Set of executables
TARGETS = pgmEcho pgmComp
 

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

# dependencies
depend: 
	makedepend -Y *.c

# rules
.SUFFIXES: .o .c
.c.o:
	${CC} ${CCFLAGS} -c -o $*.o $*.c

# program dependencies
pgmEcho.o: pgmEcho.h pgmImage.h pgmError.h pgmArgument.h pgmRead.h pgmWrite.h
pgmComp.o: pgmImage.h pgmError.h pgmArgument.h pgmRead.h pgmWrite.h
pgmErrors.o: pgmErrors.h 
pgmArgument.o: pgmArgument.h
pgmImage.o: pgmImage.h
pgmRead.o: pgmRead.h
pgmWrite.o: pgmWrite.h
 
 
