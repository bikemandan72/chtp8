/*
My interface for working with Stacks for solving Deitels' exercises
*/
#ifndef STACK_H
#define STACK_H

typedef struct list *Stack;
typedef int Item;

Stack initStack(Stack *top);
void freeStack(Stack *top);

Stack pushToStack(Stack *top, Item value);
Item popFromStack(Stack *top);
Item getTopValue(const Stack *const top);

int isEmptyStack(const Stack *const top);
unsigned int getStackSize(const Stack *const top);

void printStack(const Stack *const top, void (*printNode)(Item value));

#endif