/*
12.11 (Palindrome Tester)
Write a program that uses a stack to determine whether a string is a palindrome (i.e.,
the string is spelled identically backward and forward). The program should ignore
spaces and punctuation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../lib/stack.h"

#define SIZE 51

void printNode(Item value);
int isPalindrome(const char *const inputStr, Stack *top);

int main (int argc, char *argv[])
{
	char text[SIZE];
	puts("Enter the line of text (50 symbols max):");
	fgets(text, SIZE - 1, stdin);
	
	Stack stack_1 = NULL;
	stack_1 = initStack(&stack_1);
	
	for (size_t i = 0; text[i] != '\n'; ++i) {
		if (isalpha(text[i])) {
			pushToStack(&stack_1, (Item)text[i]);
		}
	}
	printStack(&stack_1, printNode);
	puts("");
	
	printf("The entered string is%sa palindrome.\n",
		isPalindrome(text, &stack_1) ? " " : " not ");
		
	printStack(&stack_1, printNode);
	puts("");
	
	freeStack(&stack_1);
		
	return EXIT_SUCCESS;
}
int isPalindrome(const char *const inputStr, Stack *top) {
	int palindrome = 1;
	
	for (size_t i = 0; inputStr[i] != '\n'; ++i) {
		if (isalpha(inputStr[i])) {
			if (inputStr[i] != popFromStack(top)) {
				palindrome = 0;
				break;
			}
		}
	}
	
	return palindrome;
}
void printNode(Item value) {
	printf("%c", value);
}