/*
9.6
Find the error(s) in each of the following program segments. Explain how each error can be
corrected.
a) printf("%s\n", 'Happy Birthday');
b) printf("%c\n", 'Hello');
c) printf("%c\n", "This is a string");
d) The following statement should print " Bon Voyage ":
printf(""%s"", "Bon Voyage");
e)
char day[] = "Sunday";
printf("%s\n", day[3]);
f) puts('Enter your name: ');
g) printf(%f, 123.456);
h) The following statement should print the characters ' O ' and ' K ':
printf("%s%s\n", 'O', 'K');
i)
char s[10];
scanf("%c", s[7]);
*/
#include <stdio.h>
int main (int argc, char *argv[])
{
	//a) printf("%s\n", 'Happy Birthday');
	printf("%s\n", "Happy Birthday");
	//b) printf("%c\n", 'Hello');
	printf("%s\n", "Hello");
	//c) printf("%c\n", "This is a string");
	printf("%s\n", "This is a string");
	//d) The following statement should print " Bon Voyage ":
	//printf(""%s"", "Bon Voyage");
	printf("\"%s\"\n", "Bon Voyage");
	/*
	e)
	char day[] = "Sunday";
	printf("%s\n", day[3]);
	*/
	char day[] = "Sunday";
	printf("%c\n", day[3]);
	//f) puts('Enter your name: ');
	puts("Enter your name: ");
	//g) printf(%f, 123.456);
	printf("%f\n", 123.456);
	/*
	h) The following statement should print the characters ' O ' and ' K ':
	printf("%s%s\n", 'O', 'K');
	*/
	printf("%c%c\n", 'O', 'K');
	/*
	i)
	char s[10];
	scanf("%c", s[7]);
	*/
	char s[10];
	scanf("%c", &s[7]);
	
	return 0;
}
