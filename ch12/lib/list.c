/*
The implementation of my interface for working with Linked Lists
for solving Deitels' exercises
*/
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list {
	int value;
	struct list *next;
};

List initList(List *head) {
	*head = NULL;
	return *head;
}

void freeList(List *head) {
	while(*head != NULL) {
		List temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	free(*head);	
	*head = NULL;
}

List insertAfter(List *head, int value) {
	List new = NULL;
	new = malloc(sizeof(struct list));
	if (new == NULL) {
		return new;
	}
	new->value = value;
	new->next = NULL;
	List cur = NULL, prev = NULL;
	cur = *head;
	//walk till the end of the list or value found
	while(cur != NULL && cur->value < value) {
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL) {
		return insertHead(head, value);
	} else if (cur == NULL) {
		return insertTail(head, value);
	} else {
		prev->next = new;
		new->next = cur;
		return new;
	}
}

List insertHead(List *head, int value) {
	List new = NULL;
	new = malloc(sizeof(struct list));
	if (new == NULL) {
		return new;
	}
	new->value = value;
	if (*head == NULL) {
		new->next = NULL;
	} else {
		new->next = *head;
	}
	*head = new;
	return *head;
}

List insertTail(List *head, int value) {
	List new = NULL;
	new = malloc(sizeof(struct list));
	if (new == NULL) {
		return new;
	}
	new->value = value;
	new->next = NULL;
	List cur = NULL, prev = NULL;
	cur = *head;
	//walk till the end of the list
	while(cur != NULL) {
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL) {
		//list is empty
		*head = new;
		return *head;
	} else {
		prev->next = new;
		return new;
	}
}

List deleteHead(List *head) {
	if (*head == NULL)
		return *head;
	List temp = NULL;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	temp = NULL;
	return *head;
}

List deleteTail(List *head) {
	if (*head == NULL)
		return *head;
	List cur = NULL, prev = NULL;
	cur = *head;
	//walk till the end of the list
	while(cur->next != NULL) {
		prev = cur;
		cur = cur->next;
	}
	if (prev == *head) {
		List temp = NULL;
		temp = *head;
		*head = NULL;
		free(temp);
		temp = NULL;
	} else {
		free(cur);
		cur = NULL;
		prev->next = NULL;
	}
	return *head;
}

List deleteFirst(List *head, int value) {
	if (*head == NULL)
		return *head;
	if ((*head)->value == value) {
		return deleteHead(head);
	}
	List cur = NULL, prev = NULL;
	cur = *head;
	//walk till the end of the list or value found
	while(cur->next != NULL && cur->value != value) {
		prev = cur;
		cur = cur->next;
	}
	List temp = NULL;
	if (cur->next != NULL || cur->value == value) {
		prev->next = cur->next;
		temp = cur;
		free(temp);
		temp = NULL;
	}
	return *head;
}
//TODO
List deleteAll(List *head, int value) {
	/*
	condition *head != NULL MUST be the first one
	to avoid segfault while checking the 2nd condition
	*/
	while (*head != NULL && (*head)->value == value) {
		deleteHead(head);
	}
	if (*head == NULL)
		return *head;
	List cur = NULL, prev = NULL;
	cur = *head;
	List temp = NULL;
	//walk till the end of the list or value found
	while(cur != NULL) {
		if (cur->value == value) {
			prev->next = cur->next;
			temp = cur;
			cur = cur->next;
			free(temp);
			temp = NULL;
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
	return *head;
}

List getNextNode(const List *const node) {
	return (*node)->next;
}

int getNodeValue(const List *const node) {
	return (*node)->value;
}

void traverseList(const List *const head, void (*nodeFunc)(int value)) {
	List cur = *head;
	while(cur != NULL) {
		(*nodeFunc)(cur->value);
		cur = cur->next;
	}
}

int isEmptyList(const List *const head) {
	return *head == NULL;
}

unsigned int getListSize(const List *const head) {
	unsigned int list_size = 0;
	if (*head == NULL)
		return list_size;
	List cur = *head;
	while(cur != NULL) {
		list_size++;
		cur = cur->next;
	}
	return list_size;
}