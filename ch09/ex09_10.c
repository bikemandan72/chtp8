/*
9.10 (Temperature Conversions)
Write a program that converts integer Fahrenheit temperatures from 0 to 212 degrees 
to floating-point Celsius temperatures with 3 digits of precision. Perform the
calculation using the formula celsius = 5.0 / 9.0 * (fahrenheit - 32);
The output should be printed in two right-justified columns of 10 characters each, 
and the Celsius temperatures should be preceded by a sign for both positive and 
negative values.
*/
#include <stdio.h>

int main (int argc, char *argv[])
{
	int fahrenheit = 0;
	double celsius = 0.0;
	printf("%10s%10s\n", "Fahrenheit", "Celsius");
	for (fahrenheit = 0; fahrenheit <= 212; ++fahrenheit) {
		printf("%i\n", fahrenheit);
		celsius = 5.0 / 9.0 * (fahrenheit - 32);
//if fahrenheit is unsigned int celsius gets overflow numbers in the following line //till fahrenheit becomes at least 32
//TODO explore this case further after learning bitwise operations in C
		printf("%10d%+10.3lf\n", fahrenheit, celsius);
	}
	return 0;
}