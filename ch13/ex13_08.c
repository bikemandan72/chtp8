/*
13.8 (Printing a String)
Write a program that defines and uses macro PRINT to print a string value.
*/
#include <stdio.h>

#define PRINT(x) printf(#x"=%s\n", x)

int main(int argc, char *argv[])
{
	for (unsigned int i = 0; i < argc; ++i) {
		PRINT(argv[i]);
	}
    return 0;
}