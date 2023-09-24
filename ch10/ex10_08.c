/*
10.8 (Using Unions) 
Create union integer with members char c , short s , int i and long b.
Write a program that inputs values of type char , short , int and long and 
stores the values in union variables of type union integer. 
Each union variable should be printed as a char , a short , an int and a long.
Do the values always print correctly?
*/
#include <stdio.h>

union integer {
	char c;
	short s;
	int i;
	long b;
};
typedef union integer Integer;

int main (int argc, char *argv[])
{
	Integer unionValue = {'\0'};
	
	puts("Enter char:");
	scanf("%c", &unionValue.c);
	printf("Union as a char: %c\n", unionValue.c);
	printf("char: %c, short: %hd, int: %d, long: %ld\n", 
		unionValue.c, unionValue.s, unionValue.i, unionValue.b);
	
	puts("Enter short:");
	getchar();
	scanf("%hd", &unionValue.s);
	printf("Union as a short: %hd\n", unionValue.s);
	printf("char: %c, short: %hd, int: %d, long: %ld\n", 
		unionValue.c, unionValue.s, unionValue.i, unionValue.b);
		
	puts("Enter int:");
	getchar();
	scanf("%d", &unionValue.i);
	printf("Union as an int: %d\n", unionValue.i);
	printf("char: %c, short: %hd, int: %d, long: %ld\n", 
		unionValue.c, unionValue.s, unionValue.i, unionValue.b);
		
	puts("Enter long:");
	getchar();
	scanf("%ld", &unionValue.b);
	printf("Union as a long: %ld\n", unionValue.b);
	printf("char: %c, short: %hd, int: %d, long: %ld\n", 
		unionValue.c, unionValue.s, unionValue.i, unionValue.b);
	
	return 0;
}