/*
13.5 (Adding Two Numbers)
Write a program that defines macro SUM with two arguments, x and y ,
and use SUM to produce the following output:
The sum of x and y is 13
*/
#include <stdio.h>

#define SUM(x,y) ((x) + (y))

int main (int argc, char *argv[])
{
	double a = 0, b = 0;
	puts("Enter two numbers:");
	scanf("%lf %lf", &a, &b);
	printf("The sum of %lf and %lf is %lf\n.", a, b, SUM(a, b));
	return 0;
}
