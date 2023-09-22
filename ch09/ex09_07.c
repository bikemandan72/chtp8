/*
9.7 (Differences Between %d and %i)
Write a program to test the difference between the %d and %i 
conversion specifiers when used in scanf statements.
Ask the user to enter two integers separated by a space.
Use the statements
	scanf("%i%d", &x, &y);
	printf("%d %d\n", x, y);
to input and print the values. Test the program with the following sets of input data:
10		10
010		010
-10		-10
0x10	0x10
*/
#include <stdio.h>

int main (int argc, char *argv[])
{
	int x = 0, y = 0;
	for (int i = 0; i < 4; ++i) {
		puts("Enter 2 integers separated by a space:");
		scanf("%i%d", &x, &y);
		puts("Entered numbers after conversion:");
		printf("%d %d\n", x, y);
		getchar();
	}
	return 0;
}