/*
14.8 ( goto Statement)
Write a program that uses goto statements and only the following three printf
statements to simulate a nested looping structure that prints a square of asterisks
as shown below:
printf("%s", "*");
printf("%s", " ");
printf("%s", "\n");
*****
*   *
*   *
*   *
*****
*/
#include <stdio.h>
int main (int argc, char *argv[])
{
	int row, col;
	row = 1;
	nextrow:
	if (row <= 5) {
		col = 1;
		nextcol:
		if (col <= 5) {
			if (row == 1 || row == 5 || col == 1 || col == 5) {
				printf("%s", "*");
			} else {
				printf("%s", " ");
			}
			col++;
			goto nextcol;
		}
		printf("%s", "\n");
		row++;
		goto nextrow;
	}
	
	return 0;
}
