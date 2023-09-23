/*
9.11 (Escape Sequences) Write a program to test the escape sequences
\' , \" , \? , \\ , \a , \b , \n , \r and \t .
For the escape sequences that move the cursor, print a character before and after
printing the escape sequence so it’s clear where the cursor has moved.
*/
#include <stdio.h>

#define CHAR_BEFORE 'A'
#define CHAR_AFTER 'B'

int main (int argc, char *argv[])
{
	char escape_sequence[] = {'\'', '\"', '\?', '\\', '\a',
		 '\b', '\n', '\r', '\t', '\0'};
	unsigned int i = 0;
	while (escape_sequence[i] != '\0') {
		printf("%c%c%c\n", CHAR_BEFORE, escape_sequence[i], CHAR_AFTER);
		++i;
	}
	return 0;
}