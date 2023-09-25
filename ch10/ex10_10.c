/*
10.10 (Right Shifting Integers)
Write a program that right shifts an integer variable 4 bits.
The program should print the integer in bits before and after the shift operation. 
Does your system place 0 s or 1 s in the vacated bits?
ANSWER: my system places 0s in the vacated bits
*/
#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value); // prototype

int main (int argc, char *argv[])
{ 
	unsigned int number = 4000000000; // initialize number
	
	// demonstrate bitwise right shift
	puts("\nThe result of right shifting");
	displayBits(number);
	number >>= 4;
	puts("4 bit positions using the right shift operator >> is");
	displayBits(number);
	
	return 0;
}

// display bits of an unsigned int value
void displayBits(unsigned int value)
{
	unsigned int portableIntSize = CHAR_BIT * sizeof(unsigned int);
	
	// define displayMask and left shift 31 bits
	unsigned int displayMask = 1 << (portableIntSize - 1);
	
	printf("%10u = ", value);
	
	// loop through bits
	for (unsigned int c = 1; c <= portableIntSize; ++c) {
		putchar(value & displayMask ? '1' : '0');
		value <<= 1; // shift value left by 1     
		
		if (c % 8 == 0) { // output space after 8 bits
			putchar(' ');
		}
	}
	
	putchar('\n');
}