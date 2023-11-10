/*
13.8 (Printing a String)
Write a program that defines and uses macro PRINT to print a string value.
*/
#include <stdio.h>

#define PRINT(x) puts(x)

int main(int argc, char *argv[])
{
	PRINT(argv[0]);
    return 0;
}