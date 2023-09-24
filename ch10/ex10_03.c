/*
10.3 Write code to accomplish each of the following:
a) Define a structure called part containing unsigned int variable partNumber and char
array partName with values that may be as long as 25 characters (including the terminat-
ing null character).
b) Define Part to be a synonym for the type struct part .
c) Use Part to declare variable a to be of type struct part , array b[10 ] to be of
type struct part and variable ptr to be of type pointer to struct part .
d) Read a part number and a part name from the keyboard into the individual members
of variable a .
e) Assign the member values of variable a to element 3 of array b.
f) Assign the address of array b to the pointer variable ptr.
g) Print the member values of element 3 of array b using the variable ptr and 
the structure pointer operator to refer to the members.
*/
#include <stdio.h>

//a)
struct part {
	unsigned int partNumber;
	char partName[25];
};
//b)
typedef struct part Part;

int main (int argc, char *argv[])
{
	//c)
	Part a;
	struct part b[10];
	struct part *ptr;
	//d)
	puts("Enter part number:");
	scanf("%u", &a.partNumber);
	puts("Enter part name:");
	scanf("%24s", a.partName);
	//debug print
	printf("partNumber: %u, partName: %s\n", a.partNumber, a.partName);
	//e)
	b[3] = a;
	//f)
	ptr = b;
	//g)
	printf("partNumber: %u, partName: %s\n", (ptr + 3)->partNumber, (ptr + 3)->partName);
	
	return 0;
}
