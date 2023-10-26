/*
12.21 (Recursively Search a List)
Write a function searchList that recursively searches a linked list for a specified
value. The function should return a pointer to the value if it’s found; otherwise,
NULL should be returned. Use your function in a test program that creates a list of
integers. The program should prompt the user for a value to locate in the list.
*/
#include <stdio.h>
#include <stdlib.h>

#include "../lib/list.h"

#define SIZE 10

void printNode(Item value);
void printList(List head);
List searchList(List *head, Item value);

int main (int argc, char *argv[])
{
	List list_1 = NULL;
	list_1 = initList(&list_1);
	int value = 12;
	for (size_t i = 0; i < SIZE; ++i) {
		insertAfter(&list_1, (Item)(i * 2));
	}
	printList(list_1);
	
	puts("Enter a value to locate in the list:");
	scanf("%d", &value);
	
	List nodePtr = searchList(&list_1, value);
	if (nodePtr != NULL) {
		printf("Value %d is found at address %p, \n", getNodeValue(&nodePtr), nodePtr);
	} else {
		printf("Value %d wasn't found!\n", value);
	}
	puts("");
	
	freeList(&list_1);
		
	return 0;
}

List searchList(List *head, Item value) {
	List nextNode = NULL;
	if (*head != NULL) {
		printf("Address is %p, value is %d\n", *head, getNodeValue(head));
		if (value != getNodeValue(head)) {
			nextNode = getNextNode(head);
			return searchList(&nextNode, value);
		}
	}
	return *head;
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