#Programming Project

# Mayur Shankar

###################
# TEST SCRIPT     #
###################

#!/bin/bash

# cleans up files and makes all
make clean
make all

#################################################

# no arguments passed
echo "Testing no arguments passed"

var=$(./pgmEcho)

echo $?
echo $var

# automate checking outputs
var=$(./pgmEcho)

# if return value equals 0
test $? -eq 0 && echo "CORRECT return value" || echo "INCORRECT return value"

# if output equals required string
test "$var" = "Usage: ./pgmEcho inputImage.pgm outputImage.pgm" && echo "CORRECT output string" || echo "INCORRECT output string"

#################################################

# incorrect number of arguments
echo "Testing incorrect number of arguments"

var=$(./pgmEcho inputImage.pgm outputImage.pgm extraImage.pgm)

echo $?
echo $var

# automate checking outputs
var=$(./pgmEcho inputImage.pgm outputImage.pgm extraImage.pgm)
test $? -eq 1 && echo "CORRECT return value" || echo "INCORRECT return value"
test "$var" = "ERROR: Bad Argument Count" && echo "CORRECT output string" || echo "INCORRECT output string"

#################################################

# bad filename
echo "Testing bad filename"

var=$(./pgmEcho one two)

echo $?
echo $var

#automate checking outputs
var=$(./pgmEcho one two)
test $? -eq 2 && echo "CORRECT return value" || echo "INCORRECT return value"
test "$var" = "ERROR: Bad File Name (one)" && echo "CORRECT output string" || echo "INCORRECT output string"

#################################################

# bad magic number
echo "Testing bad magic number"

var=$(./pgmEcho magic.pgm magic.pgm)

echo $?
echo $var

#automate checking outputs
var=$(./pgmEcho magic.pgm magic.pgm)
test $? -eq 2 && echo "CORRECT return value" || echo "INCORRECT return value"
test "$var" = "ERROR: Bad File Name (magic.pgm)" && echo "CORRECT output string" || echo "INCORRECT output string"

