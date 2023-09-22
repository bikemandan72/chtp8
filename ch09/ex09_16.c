/*
9.16 (Printing a Question Mark as a Character Constant)
Write a program that determines whether ? can be printed as the character constant '?'
rather than the character constant escape sequence '\?' using conversion specifier %c
in the format control string of a printf statement.
ANSWER: works in both cases!
*/
#include <stdio.h>

#define CHAR_CONST '?'
#define ESC_SEQ '\?'

int main (int argc, char *argv[])
{
	//? can be printed as the character constant '?'
	printf("character constant '?': %c\n", CHAR_CONST);
	//? can be printed as the character constant escape sequence '\?'
	printf("character constant escape sequence '\?': %c\n", ESC_SEQ);
	return 0;
}