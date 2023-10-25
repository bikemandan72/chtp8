/*
My interface for working with Linked Lists for solving Deitels' exercises
*/
#ifndef LIST_H
#define LIST_H
typedef struct list * List;

List initList(List *head);
void freeList(List *head);

List insertAfter(List *head, int value);
List insertHead(List *head, int value);
List insertTail(List *head, int value);

List deleteHead(List *head);
List deleteTail(List *head);
List deleteFirst(List *head, int value);
List deleteAll(List *head, int value);

List getNextNode(const List *const node);
int getNodeValue(const List *const node);

void traverseList(const List *const head, void (*nodeFunc)(int value));

int isEmptyList(const List *const head);
unsigned int getListSize(const List *const head);

#endif