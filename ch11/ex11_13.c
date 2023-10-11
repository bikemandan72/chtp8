/*
11.13 (Telephone-Number Word Generator) 
Standard telephone keypads contain the digits 0–9. The numbers 2–9 each have 
three letters associated with them, as is indicated by the following table:
Digit 	Letter 	Digit 	Letter
2 		A B C 	6 		M N O
3 		D E F 	7 		P R S
4 		G H I 	8 		T U V
5 		J K L 	9 		W X Y
Many people find it difficult to memorize phone numbers, so they use the correspondence
between digits and letters to develop seven-letter words that correspond to their phone
numbers.
For example, a person whose telephone number is 686-2377 might use the correspondence 
indicated in the above table to develop the seven-letter word “NUMBERS.”
Businesses frequently attempt to get telephone numbers that are easy for their clients to
remember. If a business can advertise a simple word for its customers to dial, then, 
no doubt, the business will receive a few more calls.
Each seven-letter word corresponds to exactly one seven-digit telephone number. 
The restaurant wishing to increase its take-home business could surely do so with the
number 825-3688 (i.e.,  “TAKEOUT”).
Each seven-digit phone number corresponds to many separate seven-letter words.
Unfortunately, most of these represent unrecognizable juxtapositions of letters. 
It’s possible, however, that the owner of a barber shop would be pleased to know that
the shop’s telephone number, 424-7288, corresponds to “HAIRCUT.” The owner of a liquor
store would, no doubt, be delighted to find that the store’s telephone number,
233-7226, corresponds to “BEERCAN.” A veterinarian with the phone number 738-2273 would
be pleased to know that the number corresponds to the letters “PETCARE.”
Write a C program that, given a seven-digit number, writes to a file every possible
seven-letter word corresponding to that number. There are 2187 (3 to the seventh power)
such words. Avoid phone numbers with the digits 0 and 1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ASCII_OFFSET 50 //'2' starts from 50
#define DIGITS 8
#define LETTERS 3
#define STRSIZE 10

#define FILENAME "phone_words.txt"
#define WRITE_MODE "w"

void digitToChar(const char *phone_str_ptr, size_t digit, FILE *pwPtr);

char letters[DIGITS][LETTERS] = 
{
	{'A', 'B', 'C'},	//2
	{'D', 'E', 'F'},	//3
	{'G', 'H', 'I'},	//4
	{'J', 'K', 'L'},	//5
	{'M', 'N', 'O'},	//6
	{'P', 'R', 'S'},	//7
	{'T', 'U', 'V'},	//8
	{'W', 'X', 'Y'}		//9
};
char word[DIGITS] = "ZZZZZZZ";

int main (int argc, char *argv[])
{

	//printf("%c\n", letters['9' - ASCII_OFFSET][2]);
	char phone_str[STRSIZE] = "738-22-73";
	FILE *pwPtr = NULL;
	
	puts("Input a seven-digit number in a format XXX-XX-XX (avoid 0s and 1s!):");
	fgets(phone_str, STRSIZE, stdin);
	//cut-off newline character at the end of the string
	strtok(phone_str, "\n");
	
	pwPtr = fopen(FILENAME, WRITE_MODE);
	if (pwPtr == NULL) {
		printf("Couldn't open the file %s for output!", FILENAME);
		return EXIT_FAILURE;
	}
	
	digitToChar(phone_str, 0, pwPtr);
	
	fclose(pwPtr);
	return EXIT_SUCCESS;
}

void digitToChar(const char *phone_str_ptr, size_t digit, FILE *pwPtr) {
	static int k = -1;//index for output word array
	if (phone_str_ptr[digit] != '\0' && digit <= DIGITS) {
		if (isdigit(phone_str_ptr[digit]) && 
			phone_str_ptr[digit] != '0' && phone_str_ptr[digit] != '1') {
				++k;
				for (size_t i = 0; i < LETTERS; ++i) {
					word[k] = letters[phone_str_ptr[digit] - ASCII_OFFSET][i];
					digitToChar(phone_str_ptr, digit + 1, pwPtr);
				}
				--k;
		} else {
			digitToChar(phone_str_ptr, digit + 1, pwPtr);
		}
	} else {
		fprintf(pwPtr, "%s\n", word);
	}
}