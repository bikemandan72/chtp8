/*
12.9 (Creating a Linked List, Then Reversing Its Elements)
Write a program that creates a linked list of 10 characters,
then creates a copy of the list in reverse order.
*/
#include <stdio.h>
#include <stdlib.h>

#include "../lib/list.h"

#define SIZE 10
#define ASCII_OFFSET 65

void printNode(Item value);
void printList(List head);
void reverseAndCopy(List from_head, List *to_head);

int main (int argc, char *argv[])
{
	List list_1 = NULL;
	list_1 = initList(&list_1);
	
	List list_2 = NULL;
	list_2 = initList(&list_2);
	
	for (size_t i = ASCII_OFFSET; i < SIZE + ASCII_OFFSET; ++i) {
		insertAfter(&list_1, (Item)i);
	}
	printList(list_1);
	reverseAndCopy(list_1, &list_2);
	printList(list_2);
	
	freeList(&list_1);
	freeList(&list_2);
		
	return 0;
}

void reverseAndCopy(List from_head, List *to_head) {
	while (from_head != NULL) {
		insertHead(to_head, getNodeValue(&from_head));
		from_head = getNextNode(&from_head);
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