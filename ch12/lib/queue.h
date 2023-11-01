/*
My interface for working with Queues for solving Deitels' exercises
*/
#ifndef QUEUE_H
#define QUEUE_H

typedef struct list *Queue;
typedef int Item;

Queue initQueue(Queue *head);
void freeQueue(Queue *head);

Queue enqueue(Queue *head, Item value);
Item dequeue(Queue *head);

int isEmptyQueue(const Queue *const head);
unsigned int getQueueSize(const Queue *const head);

void printQueue(const Queue *const head, void (*printNode)(Item value));

#endif