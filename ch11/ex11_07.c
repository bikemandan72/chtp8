/*
11.7 (Creating Data for a File-Matching Program)
Write a simple program to create some test data for checking out the program of
Exercise 11.8. Use the following sample account data:
Master File:
Account number 	Name 		Balance
100 			Alan Jones 	348.17
300 			Mary Smith 	27.19
500 			Sam Sharp 	0.00
700 			Suzy Green 	-14.22
Transaction File:
Account number 	Dollar amount
100 			27.14
300 			62.11
400 			100.56
900 			82.17
*/
#include <stdio.h>
#include <stdlib.h>

#define OLDMAST "oldmast.dat"
#define TRANS "trans.dat"
#define WRITE_MODE "w"
#define MASTER_RECORDS 4

int main (int argc, char *argv[])
{
	//master data
	unsigned int account_number[] = {100, 300, 500, 700};
	char *name[] = {"Alan Jones", "Mary Smith", "Sam Sharp", "Suzy Green"};
	double balance[] = {348.17, 27.19, 0.00, -14.22};
	//transaction data
	unsigned int trans_account_number[] = {100, 300, 400, 900};
	double trans[] = {27.14, 62.11, 100.56, 82.17};
	
	FILE *mfPtr = NULL, *tfPtr = NULL;
	
	mfPtr = fopen(OLDMAST, WRITE_MODE);
	if (mfPtr == NULL) {
		printf("Couldn't open the file %s!", OLDMAST);
		return EXIT_FAILURE;
	}
	tfPtr = fopen(TRANS, WRITE_MODE);
	if (tfPtr == NULL) {
		printf("Couldn't open the file %s!", TRANS);
		return EXIT_FAILURE;
	}
	for (size_t i = 0; i < MASTER_RECORDS; ++i) {
		fprintf(mfPtr, "%u %s %.2lf\n", account_number[i], name[i], balance[i]);
		fprintf(tfPtr, "%u %lf\n", trans_account_number[i], trans[i]);
	}
	
	fclose(tfPtr);
	fclose(mfPtr);
	
	return EXIT_SUCCESS;
}
