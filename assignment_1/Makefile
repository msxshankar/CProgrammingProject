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

# Set of subordinate routines
MODULES = pgmError.o pgmArgument.o pgmImage.o

# Set of main routines
MAIN= pgmEcho.o

# Set of executables
TARGETS = pgmEcho
 

# Compiles all files 
all:    ${TARGETS}	

# Removes all object files (.o), executables and temporary files
clean:
	rm -f ${TARGETS} ${MAIN} ${MODULES} *.o


# Links object files for pgmEcho
pgmEcho: 	pgmEcho.o ${MODULES}
	${CC} ${CCFLAGS} -o $@ pgmEcho.o ${MODULES}


# dependencies
depend: 
	makedepend -Y *.c

# rules
.SUFFIXES: .o .c
.c.o:
	${CC} ${CCFLAGS} -c -o $*.o $*.c

# program dependencies
pgmEcho.o: pgmEcho.h pgmImage.h pgmError.h pgmArgument.h
pgmErrors.o: pgmErrors.h 
pgmArgument.o: pgmArgument.h
pgmImage.o: pgmImage.h
 
 
