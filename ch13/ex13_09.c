/*
13.9 (Printing an Array)
Write a program that defines and uses macro PRINTARRAY to print an array of integers.
The macro should receive the array and the number of elements in the array as arguments.
*/
#include <stdio.h>

#define PRINTARRAY(arr, size)			\
for (unsigned int i = 0; i < SIZE; ++i)	\
{										\
	printf("%d ", arr[i]);				\
}										\
puts("")

#define SIZE 5

int main(int argc, char *argv[])
{
	int array[SIZE] = {9, 1, 7, 3, 5};
	PRINTARRAY(array, SIZE);
    return 0;
}