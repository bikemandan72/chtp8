/*
9.9 (Rounding Floating-Point Numbers)
Write a program that prints the value 100.453627 rounded to the nearest 
digit, tenth, hundredth, thousandth and ten-thousandth.
*/
#include <stdio.h>

int main(int argc, char **argv)
{
	double float_value = 100.453627;
	unsigned int precision = 0;
	for (precision = 0; precision < 5; ++precision) {
		printf("floating-point value 100.453627 with precision %d is %-.*lf \n", 
			precision, precision, float_value);
	}
	return 0;
}

