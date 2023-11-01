/*
12.15 (Supermarket Simulation)
Write a program that simulates a check-out line at a supermarket. The line is a queue.
Customers arrive in random integer intervals of 1 to 4 minutes. Also, each customer is
serviced in random integer intervals of 1 to 4 minutes. Obviously, the rates need to
be balanced. If the average arrival rate is larger than the average service rate,
the queue will grow infinitely. Even with balanced rates, randomness can still cause
long lines. Run the supermarket simulation for a 12-hour day (720 minutes) using
the following algorithm:
1) Choose a random integer between 1 and 4 to determine the minute at which the first
customer arrives.
2) At the first customer’s arrival time:
	Determine customer’s service time (random integer from 1 to 4);
	Begin servicing the customer;
	Schedule arrival time of next customer (random integer 1 to 4 added to the
	current time).
3) For each minute of the day:
If the next customer arrives,
	Say so;
	Enqueue the customer;
	Schedule the arrival time of the next customer.
If service was completed for the last customer,
	Say so;
	Dequeue next customer to be serviced;
	Determine customer’s service completion time
	(random integer from 1 to 4 added to the current time).
Now run your simulation for 720 minutes and answer each of the following:
a) What’s the maximum number of customers in the queue at any time?
b) What’s the longest wait any one customer experienced?
c) What happens if the arrival interval is changed from 1 to 4 minutes to 1 to 3 minutes?
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "../lib/queue.h"

#define MINUTES 720
#define ARRIVAL 4
#define SERVICE 4

void printNode(Item value);
int getArrivalTime(void);
int getServiceTime(void);

int main (int argc, char *argv[])
{	
	Queue queue_1 = NULL;
	queue_1 = initQueue(&queue_1);
	Queue queue_time = NULL;
	queue_time = initQueue(&queue_time);
	
	unsigned int currentTime, arrivalTime, serviceTime;
	currentTime = arrivalTime = serviceTime = 0;
	
	unsigned int waitTime, longestWaitTime;
	waitTime = longestWaitTime = 0;
	
	unsigned int queueSize, maxQueueSize;
	queueSize = maxQueueSize = 0;
	
	unsigned int customer = 1, longestWaitCustomer = 1, servicedCustomer = 1;
	srand(time(NULL));
	arrivalTime = getArrivalTime();
	
	puts("Day begins!");
	for (currentTime = 1; currentTime <= MINUTES; ++currentTime) {
		printf("#%u: ", currentTime);
		if (currentTime == arrivalTime) {
			printf("Customer #%u has arrived. ", customer);
			if (isEmptyQueue(&queue_1)) {
				serviceTime = currentTime + getServiceTime();
			}
			enqueue(&queue_1, (Item)customer);
			enqueue(&queue_time, (Item)currentTime);
			customer++;
			arrivalTime = currentTime + getArrivalTime();
		}
		if (currentTime == serviceTime) {
			servicedCustomer = dequeue(&queue_1);
			printf("Customer #%u has been serviced. ", servicedCustomer);
			waitTime = currentTime - dequeue(&queue_time);
			if (waitTime > longestWaitTime) {
				longestWaitTime = waitTime;
				longestWaitCustomer = servicedCustomer;
			}
			if (!isEmptyQueue(&queue_1)) {
				serviceTime = currentTime + getServiceTime();
			}
		}
		queueSize = getQueueSize(&queue_1);
		printf("Queue size is %u.\n", queueSize);
		if (queueSize > maxQueueSize) {
			maxQueueSize = queueSize;
		}
	}
	puts("Day has ended.");
	if (!isEmptyQueue(&queue_1)) {
		puts("There are unserviced customers left in a queue:");
		printQueue(&queue_1, printNode);
		puts("");
	}
	printf("Maximum queue size today was %u.\n", maxQueueSize);
	printf("Customer #%u experienced the longest wait of %u minutes.\n",
		longestWaitCustomer, longestWaitTime);
	
	freeQueue(&queue_1);
	freeQueue(&queue_time);
	return EXIT_SUCCESS;
}
int getArrivalTime(void) {
	return rand() % ARRIVAL + 1;
}
int getServiceTime(void) {
	return rand() % SERVICE + 1;
}
void printNode(Item value) {
	printf("%d --> ", value);
}