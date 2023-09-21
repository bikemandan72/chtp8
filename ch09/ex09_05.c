/*
9.5 Show what each of the following statements prints.
If a statement is incorrect, indicate why.
*/
#include <stdio.h>

int main (int argc, char *argv[])
{
	//a)printf("%-10d\n", 10000); - 10000_____
	printf("%-10d\n", 10000);
	//b)printf("%c\n", "This is a string"); - incorrect, need string conversion not char
	printf("%s\n", "This is a string");
	//c)printf("%*.*lf\n", 8, 3, 1024.987654); - 1024.988
	printf("%*.*lf\n", 8, 3, 1024.987654);
	//d)printf("%#o\n%#X\n%#e\n", 17, 17, 1008.83689); - 021 0X11 1.008837e+03
	printf("%#o\n%#X\n%#e\n", 17, 17, 1008.83689);
	//e)printf("% ld\n%+ld\n", 1000000, 1000000); - _1000000 +1000000
	printf("% d\n%+d\n", 1000000, 1000000);//int needed instead of long
	//f)printf("%10.2E\n", 444.93738); - __4.45E+02
	printf("%10.2E\n", 444.93738);
	//g)printf("%10.2g\n", 444.93738); - ___4.4e+02 (g includes sign, therefore less than e)
	printf("%10.2g\n", 444.93738);
	//h)printf("%d\n", 10.987); - incorrect, float specifier needed 6 significant digits - 10.987000
	printf("%f\n", 10.987);
	
	return 0;
}