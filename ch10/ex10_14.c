/*
10.15 (Portable displayBits Function)
Modify function displayBits of Fig. 10.7 so it’s portable between systems 
using 2-byte integers and systems using 4-byte integers. 
[Hint: Use the sizeof operator to determine the size of an integer 
on a particular machine.]
*/
#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value); // prototype
unsigned int reverseBits(unsigned int value);

int main (int argc, char *argv[])
{
	unsigned int x; // variable to hold user input
	unsigned int reversed_bits;
	
	printf("%s", "Enter a nonnegative int: ");
	scanf("%u", &x);
	
	displayBits(x);
	
	reversed_bits = reverseBits(x);
	
	puts("Bits in a reversed order:");
	displayBits(reversed_bits);
	printf("or as an unsigned int: %u\n", reversed_bits);
	return 0;
}
unsigned int reverseBits(unsigned int value) {
	
	unsigned int portableIntSize = CHAR_BIT * sizeof(unsigned int);//in bits
	unsigned int bitMask = 1;
	unsigned int reversed_bits = 0;
	unsigned int buffer = 0;
	
	for (unsigned int i = 0; i < portableIntSize; ++i) {
		buffer = value & bitMask;
		buffer >>= i;
		reversed_bits <<= 1;
		reversed_bits |= buffer;
		bitMask <<= 1;
	}
	return reversed_bits;
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
/*
This portability tip is a Copyright P. Deitel & H. Deitel, Pearson Education
Portability Tip 10.7 
Figure 10.7 can be made more generic and portable by replacing the integers 31 (line 21)
and 32 (line 26) with expressions that calculate these integers, based on the size of an
unsigned int for the platform on which the program executes. The symbolic constant
CHAR_BIT (defined in <limits.h> ) represents the number of bits in a byte (normally 8).
Recall sizeof determines the number of bytes used to store an object or type. The expres-
sion sizeof(unsigned int) evaluates to 4 for 32-bit unsigned int s and 8 for 64-bit un-
signed int s. You can replace 31 with CHAR_BIT * sizeof(unsigned int) - 1 and replace
32 with CHAR_BIT * sizeof(unsigned int) . For 32-bit unsigned int s, these expressions
evaluate to 31 and 32 , respectively. For 64-bit unsigned int s, they evaluate to 63 and 64 .
*/