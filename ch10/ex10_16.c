/*
10.16 (What’s the Value of X ?) 
The following program uses function multiple to determine if the integer entered 
from the keyboard is a multiple of some integer X. Examine the function multiple,
then determine X ’s value.
ANSWER: 1024
*/
#include <stdio.h>

int multiple(int num); // prototype

int main(void)
{ 
	int y; // y will hold an integer entered by the user 
	
	puts("Enter an integer between 1 and 32000: ");
	//32000 equals 15 binary digits (111 1101 0000 0000)
	scanf("%d", &y);
	
	//a multiple of a number is a number that is the product of 
	//a given number (factor1) and some other natural number (factor2)
	
	// if y is a multiple of X
	if (multiple(y)) {
		printf("%d is a multiple of X\n", y);
	} 
	else {
		printf("%d is not a multiple of X\n", y);
	} 
} 

// determine whether num is a multiple of X
int multiple(int num)
{ 
	int mask = 1; // initialize mask
	int mult = 1; // initialize mult
	
	//we check only 10 binary digits (i<=10)
	for (int i = 1; i <= 10; ++i, mask <<= 1) {
		if ((num & mask) != 0) { 
			//bitwise AND gives 1 only when both args equals 1
			//since mask is always 1, then we come here only when digit of num is 1
			mult = 0;
			break;
		} 
	} 
	//mult = 1 if 10 least significant binary digits of num equals 0 (set to 0)
	//smallest such a number is (1 00000 00000) = 1024
	return mult;
} 

 

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
