/*
14.4 (Sorting Integers)
Write a program that sorts an array of integers into ascending or descending order.
Use command-line arguments to pass either argument -a for ascending order or -d for
descending order.
[Note: This is the standard format for passing options to a program in UNIX.]
Exercise's code heavily based on source code of Fig. 7.26: fig07_26.c Multipurpose
sorting program using function pointers from Deitel's C How To Program 8
*/

#include <stdio.h>
#include <unistd.h>

#define SIZE 10

// prototypes
void bubble(int work[], size_t size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);
int getOrderFromOpts(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	// initialize unordered array a
	int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	
	int order = getOrderFromOpts(argc, argv);
	
	puts("\nData items in original order");
	
	// output original array
	for (size_t counter = 0; counter < SIZE; ++counter) {
		printf("%5d", a[counter]);
	}
	
	// sort array in ascending order; pass function ascending as an
	// argument to specify ascending sorting order
	if (order == 1) {
		bubble(a, SIZE, ascending);
		puts("\nData items in ascending order");
	}  
	else { // pass function descending
		bubble(a, SIZE, descending);
		puts("\nData items in descending order");
	}
	
	// output sorted array
	for (size_t counter = 0; counter < SIZE; ++counter) {
		printf("%5d", a[counter]);
	}
	
	puts("\n");
}
int getOrderFromOpts(int argc, char *argv[]) {
	int order = 1;
	int aflag = 0;
	int dflag = 0;
	int index;
	int c;
	opterr = 0;//suppress printing errors from getopt()
	while ((c = getopt (argc, argv, "ad")) != -1) {
		switch (c)
		{
			case 'a':
				aflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
			default:
				printf("Unknown option: %c\n", (char)optopt);
				break;
		}
	}
	printf ("-a option = %d, -d option = %d\n",	aflag, dflag);
	for (index = optind; index < argc; index++) {
		printf ("Non-option argument %s\n", argv[index]);
	}
	if (aflag && !dflag) {
		order = 1;
	} else if (!aflag && dflag) {
		order = 0;
	} else if (!aflag && !dflag) {
		puts("Sorting order is not set - sorting by default.");
		order = 1;
	} else {
		//(aflag && dflag)
		puts("Sorting order is mutually exlusive - sorting by default.");
		order = 1;
	}
	return order;
}
// multipurpose bubble sort; parameter compare is a pointer to
// the comparison function that determines sorting order
void bubble(int work[], size_t size, int (*compare)(int a, int b))
{
	void swap(int *element1Ptr, int *element2ptr); // prototype
	
	// loop to control passes
	for (unsigned int pass = 1; pass < size; ++pass) {
		// loop to control number of comparisons per pass
		for (size_t count = 0; count < size - 1; ++count) {
			// if adjacent elements are out of order, swap them
			if ((*compare)(work[count], work[count + 1])) {
				swap(&work[count], &work[count + 1]);
			}
		}
	}
}

// swap values at memory locations to which element1Ptr and 
// element2Ptr point
void swap(int *element1Ptr, int *element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

// determine whether elements are out of order for an ascending
// order sort
int ascending(int a, int b)
{
	return b < a; // should swap if b is less than a
}

// determine whether elements are out of order for a descending
// order sort
int descending(int a, int b)
{
	return b > a; // should swap if b is greater than a
}

