/*
10.9 (Using Unions) 
Create union floatingPoint with members float f , double d and long double x.
Write a program that inputs values of type float , double and long double and 
stores the values in union variables of type union floatingPoint.
Each union variable should be printed as a float, a double and a long double .
Do the values always print correctly?
*/
#include <stdio.h>

union floatingPoint {
	float f;
	double d;
	long double x;
};
typedef union floatingPoint FloatingPoint;

int main (int argc, char *argv[])
{
	FloatingPoint unionValue = {0.0};
	
	puts("Enter float:");
	scanf("%f", &unionValue.f);
	printf("Union as a float: %f\n", unionValue.f);
	printf("float: %f, double: %lf, long double: %Lf\n", 
		unionValue.f, unionValue.d, unionValue.x);

	puts("Enter double:");
	getchar();
	scanf("%lf", &unionValue.d);
	printf("Union as a double: %lf\n", unionValue.d);
	printf("float: %f, double: %lf, long double: %Lf\n", 
		unionValue.f, unionValue.d, unionValue.x);
	
	puts("Enter long double:");
	getchar();
	scanf("%Lf", &unionValue.x);
	printf("Union as a long double: %Lf\n", unionValue.x);
	printf("float: %f, double: %lf, long double: %Lf\n", 
		unionValue.f, unionValue.d, unionValue.x);
	
	return 0;
}