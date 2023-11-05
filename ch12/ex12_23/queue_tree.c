/*
The implementation of my interface for working with Queues
for solving Deitels' ex. 12.23
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "queue_tree.h"

struct queueNode {
	TreeNodePtr treePtr;
	struct queueNode *next;
};

QueueNodePtr initQueue(QueueNodePtr *head) {
	*head = NULL;
	return *head;
}

void freeQueue(QueueNodePtr *head) {
	if (!isEmptyQueue(head)) {
		QueueNodePtr nextNode = (*head)->next;
		free(*head);
		*head = NULL;
		freeQueue(&nextNode);
	}
}

QueueNodePtr enqueue(QueueNodePtr *head, TreeNodePtr *treeNodePtr) {
	QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(struct queueNode));
	if (newNode == NULL) {
		puts("ERROR: Out of memory!");
		return NULL;
	} else {
		//init new node members
		newNode->treePtr = *treeNodePtr;
		newNode->next = NULL;
		if (isEmptyQueue(head)) {
			*head = newNode;
		} else {
			QueueNodePtr cur = *head;
			while (cur->next != NULL) {
				cur = cur->next;
			}
			//cur now contains address of the last node in the queue
			cur->next = newNode;
		}
	}
	return *head;
}

TreeNodePtr dequeue(QueueNodePtr *head) {
	TreeNodePtr treeNodePtr = NULL;
	if (!isEmptyQueue(head)) {
		treeNodePtr = (*head)->treePtr;
		QueueNodePtr temp = *head;
		*head = (*head)->next;
		free(temp);
		temp = NULL;
	}
	return treeNodePtr;
}

int isEmptyQueue(const QueueNodePtr *const head) {
	return *head == NULL;
}