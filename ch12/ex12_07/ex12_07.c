/*
12.7 (Merging Ordered Lists)
Write a program that merges two ordered lists of integers into a single ordered list of
integers. Function merge should receive pointers to the first node of each of the lists
to be merged and return a pointer to the first node of the merged list.
*/
#include <stdio.h>
#include <stdlib.h>

#include "../lib/list.h"

#define SIZE 5

void printNode(Item value);
void printList(List head);
void merge(List head_1, List head_2, List *head_3);

int main (int argc, char *argv[])
{
	List list_1 = NULL;
	list_1 = initList(&list_1);
	
	List list_2 = NULL;
	list_2 = initList(&list_2);

	List list_3 = NULL;
	list_3 = initList(&list_3);
		
	for (size_t i = 0; i < SIZE; ++i) {
		insertAfter(&list_1, i);
		insertAfter(&list_2, i * 2);
	}
	printList(list_1);
	printList(list_2);
	
	merge(list_1, list_2, &list_3);
	printList(list_3);
	
	freeList(&list_1);
	freeList(&list_2);
	freeList(&list_3);
	
	return 0;
}

void merge(List head_1, List head_2, List *head_3) {
	while (head_1 != NULL) {
		insertAfter(head_3, getNodeValue(&head_1));
		head_1 = getNextNode(&head_1);
	}
	while (head_2 != NULL) {
		insertAfter(head_3, getNodeValue(&head_2));
		head_2 = getNextNode(&head_2);
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