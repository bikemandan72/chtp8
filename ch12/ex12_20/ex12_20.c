/*
12.20 (Recursively Print a List Backward)
Write a function printListBackward that recursively outputs the items in a list in
reverse order. Use your function in a test program that creates a sorted list of integers and prints the list in reverse order.
*/
#include <stdio.h>
#include <stdlib.h>

#include "../lib/list.h"

#define SIZE 10

void printNode(Item value);
void printList(List head);
void printListBackward(List head);

int main (int argc, char *argv[])
{
	List list_1 = NULL;
	list_1 = initList(&list_1);
	
	for (size_t i = 0; i < SIZE; ++i) {
		insertAfter(&list_1, (Item)i);
	}
	printList(list_1);
	printListBackward(list_1);
	puts("");
	
	freeList(&list_1);
		
	return 0;
}

void printListBackward(List head) {
	if (head != NULL) {
		printListBackward(getNextNode(&head));
		printNode(getNodeValue(&head));
	}
}

void printNode(Item value) {
	printf("%d --> ", value);
}

void printList(List head) {
	while (head != NULL) {
		printNode(getNodeValue(&head));
		head = getNextNode(&head);
	}
	puts("NULL");
}