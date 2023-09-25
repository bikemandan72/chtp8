/*
10.11 (Left Shifting Integers)
Left shifting an unsigned int by 1 bit is equivalent to multiplying the value by 2.
Write function power2 that takes two integer arguments number and pow and 
calculates number * 2^pow
Use the shift operator to calculate the result.
Print the values as integers and as bits.
*/
#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value); // prototype
unsigned int power2(unsigned int number, unsigned int pow);

int main (int argc, char *argv[])
{ 
	unsigned int number = 8;
	unsigned int pow = 5;
	unsigned int result = 0;
	
	// demonstrate bitwise right shift
	puts("\nNumber:");
	displayBits(number);
	
	result = power2(number, pow);
	printf("%u * 2^%u = %u\n", number, pow, result);
	displayBits(result);
	
	return 0;
}
unsigned int power2(unsigned int number, unsigned int pow) {
	
	return number << pow;
	
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