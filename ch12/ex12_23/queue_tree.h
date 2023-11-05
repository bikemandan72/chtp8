/*
My interface for working with Queues for solving Deitels' ex. 12.23
*/
#ifndef QUEUE_TREE_H
#define QUEUE_TREE_H

typedef struct queueNode *QueueNodePtr;
typedef struct treeNode *TreeNodePtr;

QueueNodePtr initQueue(QueueNodePtr *head);
void freeQueue(QueueNodePtr *head);

QueueNodePtr enqueue(QueueNodePtr *head, TreeNodePtr *treeNodePtr);
TreeNodePtr dequeue(QueueNodePtr *head);

int isEmptyQueue(const QueueNodePtr *const head);

#endif