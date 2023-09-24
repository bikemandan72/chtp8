/*
10.6 Given the following structure and variable definitions, write an expression 
that can be used to access the structure members in each of the following parts:
*/
#include <stdio.h>
#include <string.h>

struct customer {
	char lastName[15];
	char firstName[15];
	unsigned int customerNumber;
	struct {
		char phoneNumber[11];
		char address[50];
		char city[15];
		char state[3];
		char zipCode[6];
	} personal;
} customerRecord, *customerPtr;
typedef struct customer Customer;

int main (int argc, char *argv[])
{
	Customer customerRecord = {"Elon", "Musk", 2, {"800FLOWERS",
		"#60, Cambridge Av.", "Los Angeles", "NJ", "12345"}};
	Customer *customerPtr = &customerRecord;
	//My initialization:
	/*
	strcpy(customerRecord.lastName, "Elon");
	strcpy(customerRecord.firstName, "Musk");
	customerRecord.customerNumber = 1;
	strcpy(customerRecord.personal.phoneNumber, "800FLOWERS");
	strcpy(customerRecord.personal.address, "#60, Cambridge Av.");
	strcpy(customerRecord.personal.city, "Los Angeles");
	strcpy(customerRecord.personal.state, "NJ");
	strcpy(customerRecord.personal.zipCode, "12345");
	*/
	//a) Member lastName of structure customerRecord.
	//b) Member lastName of the structure pointed to by customerPtr.
	printf("lastName: %s (%s)\n", customerRecord.lastName, customerPtr->lastName);
	//c) Member firstName of structure customerRecord .
	//d) Member firstName of the structure pointed to by customerPtr.
	printf("firstName: %s (%s)\n", customerRecord.firstName, customerPtr->firstName);
	//e) Member customerNumber of structure customerRecord.
	//f) Member customerNumber of the structure pointed to by customerPtr.
	printf("customerRecord: %u (%u)\n", 
		customerRecord.customerNumber, customerPtr->customerNumber);
	//g) Member phoneNumber of member personal of structure customerRecord.
	//h) Member phoneNumber of member personal of the structure pointed to by customerPtr.
	printf("phoneNumber: %s (%s)\n", 
		customerRecord.personal.phoneNumber, customerPtr->personal.phoneNumber);
	//i) Member address of member personal of structure customerRecord.
	//j) Member address of member personal of the structure pointed to by customerPtr.
	printf("address: %s (%s)\n", 
		customerRecord.personal.address, customerPtr->personal.address);
	//k) Member city of member personal of structure customerRecord.
	//l) Member city of member personal of the structure pointed to by customerPtr.
	printf("city: %s (%s)\n", 
		customerRecord.personal.city, customerPtr->personal.city);
	//m) Member state of member personal of structure customerRecord.
	//n) Member state of member personal of the structure pointed to by customerPtr.
	printf("state: %s (%s)\n", 
		customerRecord.personal.state, customerPtr->personal.state);
	//o) Member zipCode of member personal of structure customerRecord.
	//p) Member zipCode of member personal of the structure pointed to by customerPtr.
	printf("zipCode: %s (%s)\n", 
		customerRecord.personal.zipCode, customerPtr->personal.zipCode);
		
	return 0;
}
