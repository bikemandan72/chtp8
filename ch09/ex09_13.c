/*
9.13 (Reading an Integer with Each scanf Conversion Specifier) 
Write a program that inputs the value 437 using each of the scanf 
integer conversion specifiers. Print each input value using all the
integer conversion specifiers.
*/
#include <stdio.h>

int main(void)
{ 
	int a; 
	int b; 
	int c; 
	int d; 
	int e; 
	int chars_entered;
	
	//do {
		puts("Enter 437 five times: ");
		scanf("%d%i%o%u%x%n", &a, &b, &c, &d, &e, &chars_entered);
		getchar();
	//} while (nums_entered != 5);
	
	puts("\nThe input displayed as decimal integer octal unsigned"
		" and hexadecimal (total chars entered):");
	printf("%d %i %o %u %x (%d)\n", a, b, c, d, e, chars_entered);
	//ANSWER:
	//when you print it with the same conversion that it was scanf'ed they don't change!
} 
