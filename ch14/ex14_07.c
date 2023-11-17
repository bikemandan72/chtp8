/*
14.7 (Command-Line Arguments)
Write a program that takes two command-line arguments that are filenames, reads the
characters from the first file one at a time and writes the characters in reverse order
to the second file.
*/
#include <stdio.h>
#include <stdlib.h>

void reverse(FILE *fromFilePtr, FILE *toFilePtr);

int main (int argc, char *argv[])
{
	if (argc != 3) {
		puts("Usage: myreverse fromfile tofile");
		exit(EXIT_FAILURE);
	}
	
	FILE *fromFilePtr = NULL, *toFilePtr = NULL;
	fromFilePtr = fopen(argv[1], "r");
	if (fromFilePtr == NULL) {
		printf("Unable to open the file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	toFilePtr = fopen(argv[2], "w");
	if (toFilePtr == NULL) {
		printf("Unable to open the file \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	reverse(fromFilePtr, toFilePtr);
	
	fclose(fromFilePtr);
	fclose(toFilePtr);
	
	return EXIT_SUCCESS;
}
void reverse(FILE *fromFilePtr, FILE *toFilePtr) {
	char c;
	if ((c = getc(fromFilePtr)) != EOF) {
		reverse(fromFilePtr, toFilePtr);
		putc(c, toFilePtr);
	}
}