/*
14.2 (Variable-Length Argument List: Calculating Products)
Write a program that calculates the product of a series of integers that are passed to
function product using a variable-length argument list. Test your function with several
calls, each with a different number of arguments.
*/
#include <stdio.h>
#include <stdarg.h>

#define SIZE 5

int product(int num, ...); // function must have at least one argument

int main (int argc, char *argv[])
{
	int ints[SIZE] = {1, 2, 3, 4, 5};
	printf("Product of %d and %d is %d\n",
		ints[0], ints[1], product(2, ints[0], ints[1]));
	printf("Product of %d, %d and %d is %d\n",
		ints[0], ints[1], ints[2], product(3, ints[0], ints[1], ints[2]));
	printf("Product of %d, %d, %d and %d is %d\n",
		ints[0], ints[1], ints[2], ints[3],
		product(4, ints[0], ints[1], ints[2], ints[3]));
	printf("Product of %d, %d, %d, %d and %d is %d\n",
		ints[0], ints[1], ints[2], ints[3], ints[4],
		product(5, ints[0], ints[1], ints[2], ints[3], ints[4]));
	return 0;
}

int product(int num, ...) {
	int result = 0;
	va_list val;
	va_start(val, num);
	result = va_arg(val, int);
	for (int i = 2; i <= num; ++i) {
		result *= va_arg(val, int);
	}
	va_end(val);
	return result;
}