/*
The implementation of my interface for working with Queues
for solving Deitels' exercises
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "list.h"
#include "queue.h"

struct list {
	Item value;
	struct list *next;
};

Queue initQueue(Queue *head) {
	return initList(head);
}

void freeQueue(Queue *head) {
	freeList(head);
}

Queue enqueue(Queue *head, Item value) {
	return insertTail(head, value);
}

Item dequeue(Queue *head) {
	Item topValue = getNodeValue(head);
	deleteHead(head);
	return topValue;
}

int isEmptyQueue(const Queue *const head) {
	return isEmptyList(head);
}

unsigned int getQueueSize(const Queue *const head) {
	return getListSize(head);
}

void printQueue(const Queue *const head, void (*printNode)(Item value)) {
	traverseList(head, printNode);
}