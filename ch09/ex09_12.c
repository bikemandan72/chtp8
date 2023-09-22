/*
9.12 (Printing a Question Mark)
Write a program that determines whether ? can be printed as part of a printf format
control string as a literal character rather than using the \? escape sequence.
ANSWER: works in both cases!
*/
#include <stdio.h>

int main (int argc, char *argv[])
{
	char exclamation_mark = '!';
	//? can be printed as part of a printf format control string as a literal character
	printf("How do you do?%c\n", exclamation_mark);
	//? can be printed as part of a printf format control string as an \? escape sequence.
	printf("How do you do\?%c\n", exclamation_mark);
	return 0;
}