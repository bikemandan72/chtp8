/*
5.18 (Even or Odd) Write a program that inputs a series of integers and passes them one
at a time to function isEven , which uses the remainder operator to determine whether
an integer is even. The function should take an integer argument and return 1 if the
integer is even and 0 otherwise.
*/
#include <stdio.h>

int isEven (int num);

int main () {
	int number;
	for (int i = 1; i <= 5; ++i) {
		puts ("enter next number: ");
		scanf ("%d", &number);
		printf ("number %d is ", number);
		(isEven (number) == 1) ? printf ("even\n") : printf ("odd\n");
	}
	return 0;
}

int isEven (int num) {
	int even;
	(num % 2 == 0) ? (even = 1) : (even = 0);
	return even;
}