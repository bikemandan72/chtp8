/*
9.4 Write a printf or scanf statement for each of the following:
a) Print unsigned integer 40000 left justified in a 15-digit field with 8 digits.
b) Read a hexadecimal value into variable hex.
c) Print 200 with and without a sign.
d) Print 100 in hexadecimal form preceded by 0x.
e) Read characters into array s until the letter p is encountered.
f) Print 1.234 in a 9-digit field with preceding zeros.
g) Read a time of the form hh:mm:ss , storing the parts of the time in the integer
variables hour , minute and second . Skip the colons ( : ) in the input stream. 
Use the assignment suppression character.
h) Read a string of the form "characters" from the standard input. Store the string in
character array s . Eliminate the quotation marks from the input stream.
i) Read a time of the form hh:mm:ss , storing the parts of the time in the integer
variables hour , minute and second . Skip the colons ( : ) in the input stream.
Do not use the assignment suppression character.
*/
#include <stdio.h>

int main(void) {
	//a) Print unsigned integer 40000 left justified in a 15-digit field with 8 digits.
	unsigned int ui = 40000;
	printf("%-15.8u\n", ui);
	//b) Read a hexadecimal value into variable hex.
	int hex = 0;
	puts("Input a hexadecimal value:");
	scanf("%i", &hex);
	printf("%x\n", hex);
	//c) Print 200 with and without a sign.
	printf("%+i %i\n", 200, 200);
	//d) Print 100 in hexadecimal form preceded by 0x.
	printf("%#x\n", 100);
	//e) Read characters into array s until the letter p is encountered.
	char s[27] = "";
	puts("Enter characters into array s until the letter p is encountered:");
	scanf("%26[^p]s", s);
	printf("%s\n", s);
	//f) Print 1.234 in a 9-digit field with preceding zeros.
	printf("%09f\n", 1.234);
	/*
	g) Read a time of the form hh:mm:ss , storing the parts of the time in the integer
	variables hour , minute and second . Skip the colons ( : ) in the input stream. 
	Use the assignment suppression character.
	*/
	int hour, minutes, seconds;
	puts("enter time in format hh:mm:ss:");
	
	getchar();//grab the \n character from stdin so that subsequent scanf call would work 
	scanf("%2d%*c%2d%*c%2d", &hour, &minutes, &seconds);
	
	printf("entered time: %02d:%02d:%02d\n", hour, minutes, seconds);
	/*
	h) Read a string of the form "characters" from the standard input. Store the string in
	character array s . Eliminate the quotation marks from the input stream.
	*/
	puts("enter string in a format \"characters\"");
	char str[20]="";
	
	getchar();//grab the \n character from stdin so that subsequent scanf call would work
	scanf("\"%19[^\"]s", str);
	
	printf("%s\n", str);
	/*
	i) Read a time of the form hh:mm:ss , storing the parts of the time in the integer
	variables hour , minute and second . Skip the colons ( : ) in the input stream.
	Do not use the assignment suppression character.
	*/
	puts("enter time in format hh:mm:ss:");
	
	getchar();//grab the \n character from stdin so that subsequent scanf call would work
	scanf("%2d:%2d:%2d", &hour, &minutes, &seconds);
	
	printf("entered time: %02d:%02d:%02d\n", hour, minutes, seconds);
	return 0;
}