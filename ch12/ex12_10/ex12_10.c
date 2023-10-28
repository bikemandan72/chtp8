/*
12.10 (Reversing the Words of a Sentence)
Write a program that inputs a line of text and uses a stack to print the line reversed.
*/
#include <stdio.h>
#include <stdlib.h>

#include "../lib/stack.h"

#define SIZE 51

void printNode(Item value);

int main (int argc, char *argv[])
{
	char text[SIZE];
	puts("Enter the line of text (50 symbols max):");
	fgets(text, SIZE - 1, stdin);
	
	Stack stack_1 = NULL;
	stack_1 = initStack(&stack_1);
	
	for (size_t i = 0; text[i] != '\n'; ++i) {
		pushToStack(&stack_1, (Item)text[i]);
	}
	printStack(&stack_1, printNode);
	puts("");
	
	freeStack(&stack_1);
		
	return EXIT_SUCCESS;
}

void printNode(Item value) {
	printf("%c", value);
}