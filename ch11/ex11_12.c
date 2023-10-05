/*
11.12 (Hardware Inventory) 
You’re the owner of a hardware store and need to keep an inventory that can tell you
what tools you have, how many you have and the cost of each one. Write a program that
initializes the file "hardware.dat" to 100 empty records, lets you input the data
concerning each tool, enables you to list all your tools, lets you delete a record 
for a tool that you no longer have and lets you update any information in the file. 
The tool identification number should be the record number.
Use the following information to start your file:
Record # Tool name Quantity Cost
3 Electric sander 7 57.98
17 Hammer 76 11.99
24 Jig saw 21 11.00
39 Lawn mower 3 79.50
56 Power saw 18 99.99
8 Screwdriver 106 6.99
77 Sledge hammer 11 21.50
83 Wrench 34 7.50
*/
#include <stdio.h>
#include <stdlib.h>//for EXIT_* macros

#define FILENAME "hardware.dat"
#define MODE_READ "rb+"
#define MODE_WRITE "wb"

#define OPTIONS 4
#define RECORDS 10 //for testing purposes number of records has been reduced

struct hardware {
	unsigned int record_number;
	char tool_name[16];
	unsigned int quantity;
	double cost;
};

int initFile(void);
int listRecords(FILE *rfPtr);
int inputRecord(FILE *rfPtr);
int updateRecord(FILE *rfPtr);
int deleteRecord(FILE *rfPtr);
void printMenu(void);

int main (int argc, char *argv[])
{
	FILE *rfPtr = NULL;
	int option = 0;
	int (*menu[OPTIONS])(FILE *rfPtr) = 
		{listRecords, inputRecord, updateRecord, deleteRecord};
	
	rfPtr = fopen(FILENAME, MODE_READ);
	if (rfPtr == NULL) {
		//maybe the file doesn't exist
		//then let's try to create it
		if (initFile() != 0) {
			return EXIT_FAILURE;
		} else {
			//trying once again
			rfPtr = fopen(FILENAME, MODE_READ);
			if (rfPtr == NULL) {
				return EXIT_FAILURE;
			}
		}
	}

	printMenu();
	scanf("%d", &option);
	getchar();
	while (option > 0 && option <= OPTIONS) {
		if ((*menu[option - 1])(rfPtr) != 0) {
			fclose(rfPtr);
			return EXIT_FAILURE;
		}
		printMenu();
		scanf("%d", &option);
		getchar();
	}
	fclose(rfPtr);
	
	return EXIT_SUCCESS;
}
void printMenu(void) {
	puts("");
	puts("Welcome to Hardware Inventory!");
	puts("Choose the options below:");
	puts("1 - List all records");
	puts("2 - Input new record");
	puts("3 - Update a record");
	puts("4 - Delete a record");
	puts("5 - Exit the program");
	printf("%s", "?> ");
}
int initFile(void) {
	FILE *wfPtr = NULL;
	
	wfPtr = fopen(FILENAME, MODE_WRITE);
	if (wfPtr == NULL) {
		return 1;//failure
	}
	//init structure
	struct hardware hardware_record = {0, "", 0, 0.0};
	for (size_t i = 1; i <= RECORDS; ++i) {
		fwrite(&hardware_record, sizeof(struct hardware), 1, wfPtr);
	}
	fclose(wfPtr);
	
	return 0;//success
}
int listRecords(FILE *rfPtr){
	struct hardware hardware_record_file;
	
	rewind(rfPtr); // sets pointer to beginning of file
	printf("%-8s %-15s %8s %13s\n",
		"Record #",
		"Tool name",
		"Quantity",
		"Cost");
	// read all records from random-access file
	while (!feof(rfPtr)) { 
		int result = 
			fread(&hardware_record_file, sizeof(struct hardware), 1, rfPtr);
		
		// write single record to text file
		if (result != 0 && hardware_record_file.record_number != 0) {
			printf("%-8u %-15s %8u %13.2lf\n",
				hardware_record_file.record_number, 
				hardware_record_file.tool_name, 
				hardware_record_file.quantity,        
				hardware_record_file.cost);      
		}
	}
	
	return 0;//success
}
int inputRecord(FILE *rfPtr){
	struct hardware hardware_record, hardware_record_file;
	
	printf("Input new record number (1-%d): ", RECORDS);
	scanf("%u", &hardware_record.record_number);
	getchar();
	if (hardware_record.record_number < 1 || hardware_record.record_number > RECORDS) {
		puts("Invalid record number!");
		return 1;//failure
	}
	fseek(rfPtr, (hardware_record.record_number - 1) * sizeof(struct hardware),
		SEEK_SET);
	if (fread(&hardware_record_file, sizeof(struct hardware), 1, rfPtr) == 0) {
		printf("Failed to read Record #%u from file!\n", hardware_record.record_number);
		return 1;//failure
	}
	
	if (hardware_record.record_number == hardware_record_file.record_number) {
		printf("Record #%u already exist!\n", hardware_record.record_number);
		return 1;//failure
	}
	
	printf("Input tool name for record #%u: ", hardware_record.record_number);
	scanf("%15[^\n]s", hardware_record.tool_name);
	getchar();
	
	printf("Input quantity of %s: ", hardware_record.tool_name);
	scanf("%u", &hardware_record.quantity);
	getchar();
	
	printf("Input cost of %s: ", hardware_record.tool_name);
	scanf("%lf", &hardware_record.cost);
	getchar();
	
	fseek(rfPtr, (hardware_record.record_number - 1) * sizeof(struct hardware),
		SEEK_SET);
	if (fwrite(&hardware_record, sizeof(struct hardware), 1, rfPtr) == 1) {
		printf("Record #%u has been created successfully!", 
			hardware_record.record_number);
	}
	
	return 0;//success
}
int updateRecord(FILE *rfPtr){
	struct hardware hardware_record, hardware_record_file;
	
	printf("Input the number (1-%d) of a record to update: ", RECORDS);
	scanf("%u", &hardware_record.record_number);
	getchar();
	if (hardware_record.record_number < 1 || hardware_record.record_number > RECORDS) {
		puts("Invalid record number!");
		return 1;//failure
	}
	fseek(rfPtr, (hardware_record.record_number - 1) * sizeof(struct hardware),
		SEEK_SET);
	if (fread(&hardware_record_file, sizeof(struct hardware), 1, rfPtr) == 0) {
		printf("Failed to read Record #%u from file!\n", hardware_record.record_number);
		return 1;//failure
	}
	
	if (hardware_record_file.record_number == 0) {
		printf("Record #%u doesn't exist!\n", hardware_record.record_number);
		return 1;//failure
	}
	
	printf("Update tool name for record #%u (current is %s):\n", 
		hardware_record.record_number, hardware_record_file.tool_name);
	scanf("%15[^\n]s", hardware_record.tool_name);
	getchar();
	
	printf("Update quantity of %s (current is %u): ", 
		hardware_record.tool_name, hardware_record_file.quantity);
	scanf("%u", &hardware_record.quantity);
	getchar();
	
	printf("Update cost of %s (current is %lf): ", 
		hardware_record.tool_name, hardware_record_file.cost);
	scanf("%lf", &hardware_record.cost);
	getchar();
	
	fseek(rfPtr, (hardware_record.record_number - 1) * sizeof(struct hardware),
		SEEK_SET);
	if (fwrite(&hardware_record, sizeof(struct hardware), 1, rfPtr) == 1) {
		printf("Record #%u has been updated successfully!", 
			hardware_record.record_number);
	}
	
	return 0;//success
}
int deleteRecord(FILE *rfPtr){
	struct hardware hardware_record = {0, "", 0, 0.0}, hardware_record_file;
	
	printf("Input the number (1-%d) of a record to delete: ", RECORDS);
	scanf("%u", &hardware_record.record_number);
	getchar();
	if (hardware_record.record_number < 1 || hardware_record.record_number > RECORDS) {
		puts("Invalid record number!");
		return 1;//failure
	}
	fseek(rfPtr, (hardware_record.record_number - 1) * sizeof(struct hardware),
		SEEK_SET);
	if (fread(&hardware_record_file, sizeof(struct hardware), 1, rfPtr) == 0) {
		printf("Failed to read Record #%u from file!\n", hardware_record.record_number);
		return 1;//failure
	}
	
	if (hardware_record_file.record_number == 0) {
		printf("Record #%u doesn't exist!\n", hardware_record.record_number);
		return 1;//failure
	}
	
	fseek(rfPtr, (hardware_record.record_number - 1) * sizeof(struct hardware),
		SEEK_SET);
	hardware_record.record_number = 0;
	if (fwrite(&hardware_record, sizeof(struct hardware), 1, rfPtr) == 1) {
		printf("Record #%u has been deleted successfully!", 
			hardware_record_file.record_number);
	}
	
	return 0;//success
}