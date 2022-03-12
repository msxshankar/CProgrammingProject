#Programming Project

# Mayur Shankar

###################
# TEST SCRIPT     #
###################

#!/bin/bash

# cleans up files and makes all
make clean
make all

# no arguments passed
echo "Testing no arguments passed"

var=$(./pgmEcho)

echo $?
echo $var

# automate checking outputs
var=$(./pgmEcho)
test $? -eq 0 && echo "Correct return value" || echo "Incorrect return value"
test "$var" = "Usage: ./pgmEcho inputImage.pgm outputImage.pgm" && echo "Correct output string" || echo "Incorrect output string"


# incorrect number of arguments
echo "Testing incorrect number of arguments"

var=$(./pgmEcho inputImage.pgm outputImage.pgm extraImage.pgm)

echo $?
echo $var

# automate checking outputs
var=$(./pgmEcho inputImage.pgm outputImage.pgm extraImage.pgm)
test $? -eq 1 && echo "Correct return value" || echo "Incorrect return value"
test "$var" = "ERROR: Bad Argument Count" && echo "Correct output string" || echo "Incorrect output string"

