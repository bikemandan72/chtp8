/*
The implementation of my interface for working with Stacks
for solving Deitels' exercises
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "list.h"
#include "stack.h"

struct list {
	Item value;
	struct list *next;
};

Stack initStack(Stack *top) {
	return initList(top);
}

void freeStack(Stack *top) {
	freeList(top);
}

Stack pushToStack(Stack *top, Item value) {
	return insertHead(top, value);
}

Item popFromStack(Stack *top) {
	Item topValue = getNodeValue(top);
	deleteHead(top);
	return topValue;
}

Item getTopValue(const Stack *const top) {
	return getNodeValue(top);
}

int isEmptyStack(const Stack *const top) {
	return isEmptyList(top);
}

unsigned int getStackSize(const Stack *const top) {
	return getListSize(top);
}

void printStack(const Stack *const top, void (*printNode)(Item value)) {
	traverseList(top, printNode);
}