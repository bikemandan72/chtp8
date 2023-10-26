/*
12.8 (Inserting into an Ordered List)
Write a program that inserts 25 random integers from 0 to 100 in order in a linked
list. The program should calculate the sum of the elements and the floating-
point average of the elements.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/list.h"

#define SIZE 25
#define RANGE 101

void printNode(Item value);
void printList(List head);
int sumListValues(List head);

int main (int argc, char *argv[])
{
	srand(100);
	//srand(time(NULL));
	int randomValue = 0;
	
	int sum = 0;
	double avr = 0.0;
	
	List list_1 = NULL;
	list_1 = initList(&list_1);
	
	for (size_t i = 0; i < SIZE; ++i) {
		randomValue = rand() % RANGE;
		insertAfter(&list_1, randomValue);
	}
	printList(list_1);
	sum = sumListValues(list_1);
	
	printf("Sum of list elements is %d\n", sum);
	printf("Number of list elements is %u\n", getListSize(&list_1));

	avr = (double)sum / getListSize(&list_1);
	printf("Floating-point average of list elements is %.2lf\n", avr);
	
	freeList(&list_1);
	
	return 0;
}

int sumListValues(List head) {
	int sum = 0;
	while (head != NULL) {
		sum += (int)getNodeValue(&head);
		head = getNextNode(&head);
	}
	return sum;
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