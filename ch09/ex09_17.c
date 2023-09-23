/*
9.17 (Using %g with Various Precisions)
Write a program that uses the conversion specifier g to output the value 9876.12345.
Print the value with precisions ranging from 1 to 9.
*/
#include <stdio.h>

int main(int argc, char **argv)
{
	double float_value = 9876.12345;
	unsigned int precision = 1;
	for (precision = 1; precision < 10; ++precision) {
		printf("floating-point value 9876.12345 with precision %d is %-.*g \n", 
			precision, precision, float_value);
	}
	return 0;
}

