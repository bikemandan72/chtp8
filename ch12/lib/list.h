/*
My interface for working with Linked Lists for solving Deitels' exercises
*/
#ifndef LIST_H
#define LIST_H

typedef struct list * List;
typedef int Item;

List initList(List *head);
void freeList(List *head);

List insertAfter(List *head, Item value);
List insertHead(List *head, Item value);
List insertTail(List *head, Item value);

List deleteHead(List *head);
List deleteTail(List *head);
List deleteFirst(List *head, Item value);
List deleteAll(List *head, Item value);

List getNextNode(const List *const node);
Item getNodeValue(const List *const node);

void traverseList(const List *const head, void (*nodeFunc)(Item value));

int isEmptyList(const List *const head);
unsigned int getListSize(const List *const head);

#endif