/*
9.8 (Printing Numbers in Various Field Widths)
Write a program to test the results of printing the integer value 12345 and 
the floating-point value 1.2345 in fields of various sizes. What happens
when the values are printed in fields containing fewer digits than the values?
ANSWER: values printed ignoring the field width
*/
#include <stdio.h>
int main (int argc, char *argv[])
{
	int int_value = 12345;
	double float_value = 1.2345;
	unsigned int field_width = 0;
	for (field_width = 0; field_width < 10; ++field_width) {
		printf("integer value %-*d with field width %d\n", 
			field_width, int_value, field_width);
	}
	for (field_width = 0; field_width < 16; ++field_width) {
		printf("floating-point value %-*lf with field width %d\n", 
			field_width, float_value, field_width);
	}
	return 0;
}