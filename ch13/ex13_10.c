/*
13.10 (Totaling an Array’s Contents)
Write a program that defines and uses macro SUMARRAY to sum the values in a numeric
array. The macro should receive the array and the number of elements in the array as
arguments.
*/
#include <stdio.h>

#define SUMARRAY(arr, size) sumArray(arr, size)
#define SIZE 5

int sumArray(int arr[], unsigned int size);

int main(int argc, char *argv[])
{
	int array[SIZE] = {9, 1, 7, 3, 5};
	printf("Sum of the array elements is %d\n", SUMARRAY(array, SIZE));
    return 0;
}
int sumArray(int arr[], unsigned int size) {
	int sum = 0;
	for (unsigned int i = 0; i < SIZE; ++i)
	{
		sum += arr[i];
	}
	return sum;
}