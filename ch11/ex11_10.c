/*
11.10 (File Matching with Multiple Transactions) 
It’s possible (actually common) to have several transaction records with the same
record key. This occurs because a particular customer might make several purchases 
and cash payments during a business period. Rewrite your accounts receivable file-
matching program of Exercise 11.8 to provide for the possibility of handling several
transaction records with the same record key. Modify the test data of Exercise 11.7 
to include the following additional transaction records:
Account number 	Dollar amount
300 			83.89
700 			80.78
700 			1.53
*/
#include <stdio.h>
#include <stdlib.h>

#define OLDMAST "oldmast.dat"
#define NEWMAST "newmast.dat"
#define TRANS "trans.dat"

#define WRITE_MODE "w"
#define READ_MODE "r"

#define MASTER_RECORDS 4
#define TRANS_RECORDS 7

int initFiles();

int main (int argc, char *argv[])
{
	if (initFiles() != 0) {
		return EXIT_FAILURE;
	}
	//return EXIT_SUCCESS;
	//master data
	unsigned int account_number = 0;
	char name[16] = "";
	double balance = 0.00;
	//transaction data
	unsigned int trans_account_number = 0, next_trans_account_number = 0;
	double trans = 0.00, next_trans = 0.00;
	
	FILE *omfPtr = NULL, *nmfPtr = NULL, *tfPtr = NULL;
	//open files
	omfPtr = fopen(OLDMAST, READ_MODE);
	if (omfPtr == NULL) {
		printf("Couldn't open the file %s!", OLDMAST);
		return EXIT_FAILURE;
	}
	nmfPtr = fopen(NEWMAST, WRITE_MODE);
	if (nmfPtr == NULL) {
		printf("Couldn't open the file %s!", NEWMAST);
		return EXIT_FAILURE;
	}
	tfPtr = fopen(TRANS, READ_MODE);
	if (tfPtr == NULL) {
		printf("Couldn't open the file %s!", TRANS);
		return EXIT_FAILURE;
	}
	//begin file-matching by looping trough trans.dat
	fscanf(tfPtr, "%u%lf", &trans_account_number, &trans);
	/*
	When the last line in a text file is simply \n 
		we need first fscanf() it and then check feof()
		if !feof() then printf()
		otherwise when we first fscanf() and printf() in the loop
			we duplicate the last line we've read
	*/
	//TODO fscanf считывает пробелы до и после строки
	fscanf(omfPtr, "%u%15[a-z A-Z]s", &account_number, name);
	fscanf(omfPtr, "%lf", &balance);
	int write_to_newmast = 0;
	int read_from_oldmast = 1;
	while (!feof(tfPtr)) {
		//simply copy old data of trans < tran acct.#
		while (!feof(omfPtr) && (account_number < trans_account_number) && 
			(read_from_oldmast == 1)) {
				//because name contains leading and trailing spaces
				//we exclude delimiting spaces in format conversion string
				fprintf(nmfPtr, "%u%s%.2lf\n", account_number, name, balance);
				fscanf(omfPtr, "%u%15[a-z A-Z]s", &account_number, name);
				fscanf(omfPtr, "%lf", &balance);
		}
		//read next transaction
		fscanf(tfPtr, "%u%lf", &next_trans_account_number, &next_trans);
		if (next_trans_account_number == trans_account_number) {
			write_to_newmast = 0;
			read_from_oldmast = 0;
		} else {
			write_to_newmast = 1;
			read_from_oldmast = 1;
		}
		//update data
		if (account_number == trans_account_number) {
			if (write_to_newmast == 1) {
				balance += trans;
				fprintf(nmfPtr, "%u%s%.2lf\n", account_number, name, balance);
				//read the next line of oldmast to avoid duplication account# < trans#
				if (!feof(omfPtr)) {
					fscanf(omfPtr, "%u%15[a-z A-Z]s", &account_number, name);
					fscanf(omfPtr, "%lf", &balance);
				}
			}
		} else {
			printf("Unmatched transaction record for account number #%u\n",
				trans_account_number);
			//we copy data for account number greater than trans acct.#
			//otherwise they'll get lost i.e.
			//(old acct.# already fscanfed > unmached trans acct.#)
			//or duplicated in the cycle above (old acct.# < unmached trans acct.#)
			//and here without this condition
			if (account_number > trans_account_number) {
				fprintf(nmfPtr, "%u%s%.2lf\n", account_number, name, balance);
				//read the next line of oldmast to avoid duplication account# < trans#
				if (!feof(omfPtr)) {
					fscanf(omfPtr, "%u%15[a-z A-Z]s", &account_number, name);
					fscanf(omfPtr, "%lf", &balance);
				}
			}
		}
		if (write_to_newmast == 1) {
			//next_trans_account_number != trans_account_number
			trans = next_trans;
		} else {
			//next_trans_account_number == trans_account_number
			trans += next_trans;
		}
		trans_account_number = next_trans_account_number;
	}//loop through trans.dat

	//close files
	fclose(tfPtr);
	fclose(omfPtr);
	fclose(nmfPtr);
	
	return EXIT_SUCCESS;
}
int initFiles() {
	//master data
	char *name[] = {"Alan Jones", "Mary Smith", "Sam Sharp", "Suzy Green"};
	unsigned int account_number[] = {100, 		300, 	500, 	700};
	double balance[] = 				{348.17, 	27.19, 	0.00, 	-14.22};
	//transaction data
	unsigned int trans_account_number[] = 
						{100, 	300, 	300, 	400, 	700, 	700, 	900};
	double trans[] = 	{27.14, 62.11, 	83.89, 	100.56, 80.78, 	1.53, 	82.17};
	
	FILE *mfPtr = NULL, *tfPtr = NULL;
	
	mfPtr = fopen(OLDMAST, WRITE_MODE);
	if (mfPtr == NULL) {
		printf("Couldn't open the file %s!", OLDMAST);
		return 1;//failure
	}
	tfPtr = fopen(TRANS, WRITE_MODE);
	if (tfPtr == NULL) {
		printf("Couldn't open the file %s!", TRANS);
		return 1;//failure
	}
	for (size_t i = 0; i < MASTER_RECORDS; ++i) {
		fprintf(mfPtr, "%u %s %.2lf\n", account_number[i], name[i], balance[i]);
	}
	for (size_t i = 0; i < TRANS_RECORDS; ++i) {
		fprintf(tfPtr, "%u %.2lf\n", trans_account_number[i], trans[i]);
	}
	
	fclose(tfPtr);
	fclose(mfPtr);
	return 0;//success
}