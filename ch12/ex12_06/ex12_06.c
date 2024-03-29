/*
12.6 (Concatenating Lists) Write a program that concatenates two linked lists of
characters. The program should include function concatenate that takes pointers
to both lists as arguments and concatenates the second list to the first list.
*/
#include <stdio.h>
#include <stdlib.h>

#include "../lib/list.h"

#define SIZE 5
#define ASCII_OFFSET 65

void printNode(Item value);
void printList(List head);
void concatenate(List head_1, List head_2);

int main (int argc, char *argv[])
{
	List list_1 = NULL;
	list_1 = initList(&list_1);
	
	List list_2 = NULL;
	list_2 = initList(&list_2);
	
	for (size_t i = ASCII_OFFSET; i < SIZE + ASCII_OFFSET; ++i) {
		insertAfter(&list_1, (Item)i);
		insertAfter(&list_2, (Item)(i + 10));
	}
	printList(list_1);
	printList(list_2);

	concatenate(list_1, list_2);

	printList(list_1);
	
	freeList(&list_1);
	freeList(&list_2);
		
	return 0;
}

void concatenate(List head_1, List head_2) {
	while (head_2 != NULL) {
		insertTail(&head_1, getNodeValue(&head_2));
		head_2 = getNextNode(&head_2);
	}
}

void printNode(Item value) {
	printf("%c --> ", value);
}

void printList(List head) {
	while (head != NULL) {
		printNode(getNodeValue(&head));
		head = getNextNode(&head);
	}
	puts("NULL");
}