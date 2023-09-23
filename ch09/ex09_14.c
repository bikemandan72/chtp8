/*
9.14 (Outputting a Number with the Floating-Point Conversion Specifiers)
Write a program that uses each of the conversion specifiers e , f and g 
to input the value 1.2345 . Print the values of each variable to prove 
that each conversion specifier can be used to input this same value.
*/
#include <stdio.h>

int main(void)
{ 
	float a;
	float b;
	float c;
	
	puts("Enter value 1.2345 three times:");
	scanf("%e%f%g", &a, &b, &c);
	
	puts("Here are the numbers printed with the same conversion specifier as entered:");
	printf("%e\n%f\n%g\n", a, b, c);
}