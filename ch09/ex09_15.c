/*
9.15 (Reading Strings in Quotes)
In some programming languages, strings are entered surrounded by either single or
double quotation marks. Write a program that reads the three strings suzy, "suzy" and
'suzy' . Are the single and double quotes ignored by C or read as part of the string?
ANSWER: nothing ignored by C. After conversion strings appear the same as entered.
*/
#include <stdio.h>

int main (int argc, char *argv[])
{
	char str1[10] = "", str2[10] = "", str3[10] = "";

	puts("Enter 3 strings suzy, \"suzy\" and 'suzy':");
	scanf("%9s%9s%9s", str1, str2, str3);
	puts("Entered strings after conversion:");
	printf("%s, %s, %s\n", str1, str2, str3);

	return 0;
}