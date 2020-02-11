Name: Ben mikailenko

Description: program that turns a postfix regular expression to an NFA and prints it to stdout

To make:

	make

To run: 

	1. open terminal to folder location

	2. make the program:

		"make"

	3. run the program with test file:

		"./user Sample\ Testfile.txt"

To clean:

	make clean

Files:

	user.c: contains the main c code for the program
	stack.c/.h: contains the stack structure code
	nfa.c/.h: contains the nfa structure code
	transitions.c/.h: contains the transisions structure code
	Makefile: make file for the c code
	README.txt: explains how to run the program
	Sample Testfile.txt: text file of postfix RE to run though the program
	
