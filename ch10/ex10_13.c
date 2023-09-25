/*
10.13 (Unpacking Characters from an Integer) 
Using the right-shift operator, the bitwise AND operator and a mask, 
write function unpackCharacters that takes the unsigned int from Exercise 10.12 and
unpacks it into four characters. 
To unpack characters from a four-byte unsigned int, 
combine the unsigned int with the mask 4278190080 ( 11111111 00000000 00000000 00000000 )
and right shift the result 8 bits. Assign the resulting value to a char variable. Then
combine the unsigned int with the mask 16711680 ( 00000000 11111111 00000000 00000000 ). 
Assign the result to another char variable. Continue this process with the masks 
65280 and 255. The program should print the unsigned int in bits before it’s unpacked,
then print the characters in bits to confirm that they were unpacked correctly.
*/
#include <stdio.h>
#include <limits.h>

#define BITS_IN_BYTE 8

void displayBits(unsigned int value); // prototype
unsigned int packCharacters(const char *characters, unsigned int num_characters);
void printChars(const char *characters);
void unpackCharacters(unsigned int packed_characters, char *characters);

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
	printChars(characters);

	printf("Packed characters %u in binary format:\n", packed_characters);
	displayBits(packed_characters);
	
	unpackCharacters(packed_characters, characters);
	printChars(characters);
	
	return 0;
}
void unpackCharacters(unsigned int packed_characters, char *characters) {

	*characters = '\0';
	unsigned int num_characters = BITS_IN_BYTE * sizeof(unsigned int) / CHAR_BIT;
	unsigned int i = 0;

	//int size in bits
	unsigned int portableIntSize = CHAR_BIT * sizeof(unsigned int);
	unsigned int bitMask = 255 << (portableIntSize - CHAR_BIT);
	unsigned int holder = 0;
	
	while (i < num_characters) {
		displayBits(bitMask);//debug print
		holder = packed_characters & bitMask;
		characters[i] = holder >> CHAR_BIT * (num_characters - i - 1);
		printf("%c\n", characters[i]);//debug print
		bitMask >>= CHAR_BIT;
		++i;
	}
}
void printChars(const char *characters) {
	
	unsigned int i = 0;
	
	while (characters[i] != '\0') {
		printf("Character '%c' (ASCII: %d) in binary format:\n", 
			characters[i], characters[i]);
		displayBits(characters[i]);
		++i;
	}
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