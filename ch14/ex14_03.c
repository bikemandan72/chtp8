/*
14.3 (Printing Command-Line Arguments)
Write a program that prints the command-line arguments of the program.
*/
#include <stdio.h>
int main (int argc, char *argv[])
{
	puts("Command-line arguments supplied to the program are:");
	for (size_t i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}
	return 0;
}