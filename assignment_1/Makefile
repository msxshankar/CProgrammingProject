#  
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
CC=gcc
CCFLAGS = -g -std=c99 -Wall
 
# Compiles all files 
all: pgmEcho 
 
# Compiles pgmEcho 
pgmEcho:	pgmEcho.c pgmMacro.h
	${CC} ${CCFLAGS} -o pgmEcho pgmEcho.c
 
 
# Removes all object files (.o), executables and temporary files
clean:
	rm -f pgmEcho
 
