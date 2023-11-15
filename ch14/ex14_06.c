/*
14.6 (Dynamic Array Allocation)
Write a program that dynamically allocates an array of integers. The size of the array
should be input from the keyboard. The elements of the array should be assigned values
input from the keyboard. Print the values of the array. Next, reallocate the memory for
the array to half of the current number of elements. Print the values remaining in the
array to confirm that they match the first half of the values in the original array.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void printArray(const int *arr, unsigned int arrSize);

int main (int argc, char *argv[])
{
	//input array size
	unsigned int arraySize = SIZE;

//to compile in DEBUG mode use one of this commands:
//make ex14_06 CFLAGS='-DDEBUG -g -lm -Wall'
//gcc ex14_06.c -o ex14_06 -Wall -g -DDEBUG	
#ifndef DEBUG
	do {
		puts("Enter array size:");
		scanf("%u", &arraySize);
	} while (arraySize <= 0);
	getchar();//eat '\n' from buffer
#endif

	//allocate memory for array's size using malloc and then calloc
	int *array = NULL;
	//array = malloc(arraySize * sizeof(int));
	array = calloc(arraySize, sizeof(int));
	if (array == NULL) {
		puts("Unable to allocate memory!");
		return EXIT_FAILURE;
	}
	//print empty array for malloc and calloc
	//if you use malloc above then printArray valgrind gives errors:
	//Uninitialised value was created by a heap allocation
	//printArray(array, arraySize);
	
#if defined(DEBUG)
	int input[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//fill in the array
	for (size_t i = 0; i < SIZE; ++i) {
		array[i] = input[i];
	}
#else
	//fill in the array
	for (size_t i = 0; i < arraySize; ++i) {
		puts("Enter the next array element:");
		scanf("%u", &array[i]);
		getchar();
	}
#endif

	//print array
	printArray(array, arraySize);
	//realloc double the size of the array
	int *arrRealloc = NULL;
	//I use different pointer for realloc to make sure its call was successful
	arrRealloc = realloc(array, sizeof(int) * arraySize / 2);
	if (arrRealloc == NULL) {
		puts("Unable to reallocate memory!");
		free(array);
		return EXIT_FAILURE;
	}
	array = NULL;
	//print the array
	//we MUST use arrRealloc
	printArray(arrRealloc, arraySize / 2);
	//memory by "old" array pointer is not guaranted to be contigious anymore
	//printArray(array, arraySize * 2);

	//there's no need to free array, because realloc free'd it upon successful call above
	//free(array);
	free(arrRealloc);
	arrRealloc = NULL;
	
	return EXIT_SUCCESS;
}
void printArray(const int *arr, unsigned int arrSize) {
	for (size_t i = 0; i < arrSize; ++i) {
		printf("%d ", arr[i]);
	}
	puts("");
}