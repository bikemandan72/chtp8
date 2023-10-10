/*
11.8 (File Matching)
Exercise 11.3 asked the reader to write a series of single statements. 
Actually, these statements form the core of an important type of file-processing
program, namely, a file-matching program. In commercial data processing, 
it’s common to have several files in each system.
In an accounts receivable system, for example, there’s generally a master file
containing detailed information about each customer such as the customer’s name,
address, telephone number, outstanding balance, credit limit, discount terms, contract
arrangements and possibly a condensed history of recent purchases and cash payments.
As transactions occur (i.e., sales are made and cash payments arrive in the mail), 
they’re entered into a file. At the end of each business period (i.e., a month 
for some companies, a week for others and a day in some cases) the file of transactions
(called "trans.dat" in Exercise 11.3) is applied to the master file (called
"oldmast.dat" in Exercise 11.3), thus updating each account's record of purchases and
payments. After each of these updates runs, the master file is rewritten as a
new file ( "newmast.dat" ), which is then used at the end of the next business period
to begin the updating process again.
File-matching programs must deal with certain problems that do not exist in single-file
programs. For example, a match does not always occur. A customer on the master file
might not have made any purchases or cash payments in the current business period, and
therefore no record for this customer will appear on the transaction file. Similarly, a
customer who did make some purchases or cash payments might have just moved to this
community, and the company may not have had a chance to create a master record for this
customer.
Use the statements written in Exercise 11.3 as the basis for a complete file-matching
accounts receivable program. Use the account number on each file as the record key for
matching purposes.
Assume that each file is a sequential file with records stored in increasing
account-number order.
When a match occurs (i.e., records with the same account number appear on both the master
file and the transaction file), add the dollar amount on the transaction file to the
current balance on the master file and write the "newmast.dat" record. (Assume that
purchases are indicated by positive amounts on the transaction file, and that payments
are indicated by negative amounts.)
When there’s a master record for a particular account but no corresponding transaction
record, merely write the master record to "newmast.dat" . When there’s a 
transaction record but no corresponding master record, print the message "Unmatched
transaction record for account number... " (fill in the account number from 
the transaction record).
*/
#include <stdio.h>
#include <stdlib.h>

#define OLDMAST "oldmast.dat"
#define NEWMAST "newmast.dat"
#define TRANS "trans.dat"
#define WRITE_MODE "w"
#define READ_MODE "r"

int main (int argc, char *argv[])
{
	//master data
	unsigned int account_number = 0;
	char name[16] = "";
	double balance = 0.00;
	//transaction data
	unsigned int trans_account_number = 0;
	double trans = 0.00;
	
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
	while (!feof(tfPtr)) {
		/*
		When the last line in a text file is simply \n 
			we need first fscanf() it and then check feof()
			if !feof() then printf()
			otherwise when we first fscanf() and printf() in the loop
				we duplicate the last line we've read
		*/
		//int unmatched_account = 1;
		fscanf(omfPtr, "%u%15[a-z A-Z]s", &account_number, name);
		fscanf(omfPtr, "%lf", &balance);
		//simply copy old data
		while (!feof(omfPtr) && (account_number < trans_account_number)) {
			//because name contains leading and trailing spaces
			//we exclude delimiting spaces in format conversion string
			fprintf(nmfPtr, "%u%s%.2lf\n", account_number, name, balance);
			fscanf(omfPtr, "%u%15[a-z A-Z]s", &account_number, name);
			fscanf(omfPtr, "%lf", &balance);
		}
		//update data
		if (account_number == trans_account_number) {
			balance += trans;
			fprintf(nmfPtr, "%u%s%.2lf\n", account_number, name, balance);
		} else {
			printf("Unmatched transaction record for account number #%u\n",
				trans_account_number);
			//we copy data for account number greater than trans acct.#
			//otherwise they'll get lost i.e.
			//(old acct.# already scanfed > unmached trans acct.#)
			//or duplicated in the cycle above (old acct.# < unmached trans acct.#)
			//and here without this condition
			if (account_number > trans_account_number) {
				fprintf(nmfPtr, "%u%s%.2lf\n", account_number, name, balance);
			}
		}
		//read next transaction
		fscanf(tfPtr, "%u%lf", &trans_account_number, &trans);
	}//loop thruogh trans.dat

	//close files
	fclose(tfPtr);
	fclose(omfPtr);
	fclose(nmfPtr);
	
	return EXIT_SUCCESS;
}