/*
10.12 (Packing Characters into an Integer)
The left-shift operator can be used to pack four character values into a four-byte
unsigned int variable.
Write a program that inputs four characters from the keyboard and passes them to
function packCharacters.
To pack four characters into an unsigned int variable, assign the first character 
to the unsigned int variable, shift the unsigned int variable left by 8 bit positions
and combine the unsigned variable with the second character using the bitwise 
inclusive OR operator. 
Repeat this process for the third and fourth characters.
The program should output  the characters in their bit format before and after 
they’re packed into the unsigned int to prove that the characters are in fact packed
correctly in the unsigned int variable.
*/
#include <stdio.h>
#include <limits.h>

#define BITS_IN_BYTE 8

void displayBits(unsigned int value); // prototype
unsigned int packCharacters(const char *characters, unsigned int num_characters);

int main (int argc, char *argv[])
{
	char characters[33] = "";
	//32+'\0' just to be long enough, we need just 4
	//but let's make it portable to some extent
	unsigned int num_characters = BITS_IN_BYTE * sizeof(unsigned int) / CHAR_BIT;
	
	unsigned int packed_characters = 0;
	
	printf("Enter at least %u characters in a row (no spaces between them):\n",
		num_characters);
	scanf("%s", characters);
	
	packed_characters = packCharacters(characters, num_characters);
	
	for (unsigned int i = 0; i < num_characters; ++i) {
		printf("Character '%c' (ASCII: %d) in binary format:\n", 
			characters[i], characters[i]);
		displayBits(characters[i]);
	}

	printf("Packed characters %u in binary format:\n", packed_characters);
	displayBits(packed_characters);
	
	return 0;
}
unsigned int packCharacters(const char *characters, unsigned int num_characters) {
	
	unsigned int packed_characters = 0;
	unsigned int i = 0;
	
	packed_characters |= characters[i];
	while (i < num_characters) {
		packed_characters <<= CHAR_BIT;
		packed_characters |= characters[i];
		++i;
	}
	
	return packed_characters;
}
// display bits of an unsigned int value
void displayBits(unsigned int value)
{
	//int size in bits
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