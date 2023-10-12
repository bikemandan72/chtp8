/*
11.15 (Using File-Processing Functions with Standard Input/Output Streams) 
Modify the example of Fig. 8.11 to use functions fgetc and fputs rather than 
getchar and puts . The program should give the user the option to read from the
standard input and write to the standard output or to read from a specified file 
and write to a specified file. If the user chooses the second option, have
the user enter the filenames for the input and output files.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 80
#define MODE_INPUT 0
#define MODE_OUTPUT 1
#define APPEND "a"
#define READ "r"

FILE * chooseStream(int mode);

int main(void)
{ 
	int c; // variable to hold character input by user
	char sentence[SIZE]; // create char array
	int i = 0; // initialize counter i
	FILE *inputPtr = stdin, *outputPtr = stdout;
	
	fputs("Program enters a line of text.\n", stdout); 
	fputs("And then outputs it.\n", stdout);
	
	inputPtr = chooseStream(MODE_INPUT);
	outputPtr = chooseStream(MODE_OUTPUT);
	
	if (inputPtr == stdin)
		fputs("Now enter a line of text:\n", stdout);
	while ((i < SIZE - 1) && (c = fgetc(inputPtr)) != '\n') {
		sentence[i++] = c;
	}
	sentence[i] = '\0'; // terminate string
	
	// use puts to display sentence
	fputs("\nThe line entered was:\n", outputPtr);
	fputs(sentence, outputPtr);
	fputs("\n", outputPtr);
	
	if (inputPtr != NULL)
		fclose(inputPtr);
	if (outputPtr != NULL)
		fclose(outputPtr);
		
	return EXIT_SUCCESS;
}
FILE * chooseStream(int mode) {
	FILE *fPtr = NULL;
	int c = 1;
	char filename[SIZE];
	
	do {
		printf("Choose the %s:\n", 
			(mode == MODE_INPUT) ? "source of input" : "destination of output");
		printf("%s - press 1\n",
			(mode == MODE_INPUT) ? "Keyboard (stdin)" : "Screen (stdout)");
		fputs("File - press 2\n", stdout);
		scanf("%d", &c);
		getchar();
	} while (c != 1 && c != 2);
	if (c == 2) {
		puts("Enter filename (max 15 characters without spaces):");
		scanf("%15s", filename);
		getchar();
		
		fPtr = fopen(filename, (mode == MODE_INPUT) ? READ : APPEND);
		if (fPtr == NULL) {
			printf("Couldn't open the file %s for %s.\n", filename,
				(mode == MODE_INPUT) ? "input" : "output");
			printf("%s will be used.\n", (mode == MODE_INPUT) ? "stdin" : "stdout");
			fPtr = (mode == MODE_INPUT) ? stdin : stdout;
		}
	} else {
		fPtr = (mode == MODE_INPUT) ? stdin : stdout;
	}

	return fPtr;
}