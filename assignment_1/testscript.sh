# COMP1921 Programming Project

# Mayur Shankar

###################
#   TEST SCRIPT   #
###################

#!/bin/bash

# cleans up files and makes all
make clean
make all

echo -en "\n"

#################################################

# color coding for clarity
red='\033[0;31m'
green='\033[0;32m'
reset='\033[0m'

#################################################

# no arguments passed

noArguments () {
	echo "Testing no arguments passed"

	var=$(./pgmEcho)

	# Program outputs
	echo $?
	echo $var

	# automate checking outputs
	var=$(./pgmEcho)

	# if return value equals 0
	if [ $? -eq 0 ]; then
	       	echo -e "${green}CORRECT return value${reset}"
	else
	       	echo -e "${red}INCORRECT return value${reset}"
	fi

	# if output equals required string
	if [ "$var" == "Usage: ./pgmEcho inputImage.pgm outputImage.pgm" ]; then
		echo -e "${green}CORRECT output string${reset}"
	else
		echo -e "${red}INCORRECT output string${reset}"
	fi
	
	echo -en "\n"
}


#################################################

# incorrect number of arguments

wrongNumArguments () {
	echo "Testing incorrect number of arguments"

	var=$(./pgmEcho inputImage.pgm outputImage.pgm extraImage.pgm)
	
	# Program outputs
	echo $?
	echo $var

	# automate checking outputs
	# return value
	var=$(./pgmEcho inputImage.pgm outputImage.pgm extraImage.pgm)

	if [ $? -eq 1 ]; then
		echo -e "${green}CORRECT return value${reset}"
	else
		echo -e "${red}INCORRECT return value${reset}"
	fi

	# String output
	if [ "$var" == "ERROR: Bad Argument Count" ]; then
	       	echo -e "${green}CORRECT output string${reset}"
	else 
		echo -e "${red}INCORRECT output string${reset}"
	fi

	echo -en "\n"
}

#################################################

# bad filename
badFilename () {
	echo "Testing bad filename"

	var=$(./pgmEcho one two)

	# Program outputs
	echo $?
	echo $var

	#automate checking outputs
	#return value
	var=$(./pgmEcho one two)
	
	if [ $? -eq 2 ]; then
	       	echo -e "${green}CORRECT return value${reset}"
	else
		echo -e "${red}INCORRECT return value${reset}"
	fi

	# Testing string output
	if [ "$var" == "ERROR: Bad File Name (one)" ]; then
		echo -e "${green}CORRECT output string${reset}"
	else
		echo -e "${red}INCORRECT output string${reset}"
	fi

	echo -en "\n"
}
#################################################

# bad magic number
badMagicNumber () {
	echo "Testing bad magic number"

	var=$(./pgmEcho magic.pgm magic.pgm)

	# Program outputs
	echo $?
	echo $var

	#automate checking outputs
	#return values
	var=$(./pgmEcho magic.pgm magic.pgm)

	if [ $? -eq 3 ]; then
		echo -e "${green}CORRECT return value${reset}"
	else
		echo -e "${red}INCORRECT return value${reset}"
	fi

	# Testing string output
	if [ "$var" == "ERROR: Bad Magic Number (magic.pgm)" ]; then
		echo -e "${green}CORRECT output string${reset}"
	else 
		echo -e "${red}INCORRECT output string${reset}"

	fi	

	echo -en "\n"
}
#################################################

# bad comment line
badCommentLine () {
	echo "Testing bad comment line"

	var=$(./pgmEcho comment.pgm comment.pgm)

	# Program outputs
	echo $?
	echo $var

	#automate checking outputs
	#return values
	var=$(./pgmEcho comment.pgm comment.pgm)

	if [ $? -eq 4 ]; then
		echo -e "${green}CORRECT return value${reset}"
	else
		echo -e "${red}INCORRECT return value${reset}"
	fi

	# Testing string output
	if [ "$var" == "ERROR: Bad Comment Line (comment.pgm)" ]; then
		echo -e "${green}CORRECT output string${reset}"
	else 
		echo -e "${red}INCORRECT output string${reset}"

	fi	

	echo -en "\n"
}
#################################################

# bad dimensions

badDimensions() {
	echo "Testing bad dimensions"

	var=$(./pgmEcho dimensions.pgm dimensions.pgm)

	# Program outputs
	echo $?
	echo $var

	#automate checking outputs
	#return values
	var=$(./pgmEcho dimensions.pgm dimensions.pgm)

	if [ $? -eq 5 ]; then
		echo -e "${green}CORRECT return value${reset}"
	else
		echo -e "${red}INCORRECT return value${reset}"
	fi

	# Testing string output for dimensions
	if [ "$var" == "ERROR: Bad Dimensions (dimensions.pgm)" ]; then
		echo -e "${green}CORRECT output string${reset}"
	else 
		echo -e "${red}INCORRECT output string${reset}"
	fi

	echo -en "\n"
}

#################################################

# bad max gray value

badMaxGrayValue () {
	echo "Testing bad gray value"

	var=$(./pgmEcho gray.pgm gray.pgm)

	# Program outputs
	echo $?
	echo $var

	# Return values for max gray values
	var=$(./pgmEcho gray.pgm gray.pgm)

	if [ $? -eq 6 ]; then
		echo -e "${green}CORRECT return value${reset}"
	else
		echo -e "${red}INCORRECT return value${reset}"
	fi	

	# Testing string output for max gray value
	if [ "$var" == "ERROR: Bad Max Gray Value (gray.pgm)" ]; then
		echo -e "${green}CORRECT output string${reset}"
	else 
		echo -e "${red}INCORRECT output string${reset}"
	fi

	echo -en "\n"
}

################################################

# bad malloc

badMalloc () {
	echo "Testing bad malloc"

	var=$(./pgmEcho malloc.pgm malloc.pgm)

	# Program outputs
	echo $?
	echo $var

	#automate checking outputs
	#return values
	var=$(./pgmEcho malloc.pgm malloc.pgm)

	if [ $? -eq 7 ]; then
		echo -e "${green}CORRECT return value${reset}"
	else
		echo -e "${red}INCORRECT return value${reset}"
	fi

	# Testing string output
	if [ "$var" == "ERROR: Image Malloc Failed" ]; then
		echo -e "${green}CORRECT output string${reset}"
	else 
		echo -e "${red}INCORRECT output string${reset}"
	fi
	
	echo -en "\n"
}
	

# Runs functions

noArguments
wrongNumArguments
badFilename
badMagicNumber
badCommentLine
badDimensions
badMaxGrayValue
badMalloc

diff <(xxd pepper.pgm) <(xxd var)
