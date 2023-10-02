/*
11.16 (Outputting Type Sizes to a File) 
Write a program that uses the sizeof operator to determine the sizes in bytes of 
the various data types on your computer system. Write the results to the file 
"datasize.dat" so you may print the results later. The format for the results
in the file should be as follows (the type sizes on your computer might be 
different from those shown in the sample output):
Data type				Size
char					1
unsigned char			1
short int				2
unsigned short int		2
int						4
unsigned int			4
long int				4
unsigned long int		4
float					4
double					8
long double				16
*/
#include <stdio.h>
#include <stdlib.h>//for EXIT_* macros

#define FILENAME "datasize.dat"
#define MODE_WRITE "w"
#define MODE_READ "r"

int main (int argc, char *argv[])
{
	FILE *tfPtr;
	char type_str[21] = "";
	int bytes = 0;
	
	//write to file
	tfPtr = fopen(FILENAME, MODE_WRITE);
	if (tfPtr == NULL) {
		puts("File could not be opened!");
		return EXIT_FAILURE;
	}
	fprintf(tfPtr, "%s %d\n", "char", sizeof(char));
	fprintf(tfPtr, "%s %d\n", "unsigned char", sizeof(unsigned char));
	fprintf(tfPtr, "%s %d\n", "short int", sizeof(short int));
	fprintf(tfPtr, "%s %d\n", "unsigned short int", sizeof(unsigned short int));
	fprintf(tfPtr, "%s %d\n", "int", sizeof(int));
	fprintf(tfPtr, "%s %d\n", "unsigned int", sizeof(unsigned int));
	fprintf(tfPtr, "%s %d\n", "long int", sizeof(long int));
	fprintf(tfPtr, "%s %d\n", "unsigned long int", sizeof(unsigned long int));
	fprintf(tfPtr, "%s %d\n", "float", sizeof(float));
	fprintf(tfPtr, "%s %d\n", "double", sizeof(double));
	//next line without \n symbol at the end
	//so that feof function below could return true and 
	//printf won't double output of the last line from file datasize.dat
	fprintf(tfPtr, "%s %d", "long double", sizeof(long double));
	fclose(tfPtr);
	
	//read from file
	tfPtr = fopen(FILENAME, MODE_READ);
	if (tfPtr == NULL) {
		puts("File could not be opened!");
		return EXIT_FAILURE;
	}
	printf("%-20s%-4s\n", "Data type", "Size");
	while (!feof(tfPtr)) {
		//read the string from file till the first digit
		//otherwise fscanf returns when it'll meet first whitespace
		fscanf(tfPtr, "%20[^0-9]s", type_str);
		//that's why I split reading of one line in the file to 2 fscanf calls
		fscanf(tfPtr, "%d", &bytes);
		fgetc(tfPtr);
		printf("%-20s%-4d\n", type_str, bytes);
	}
	fclose(tfPtr);
	
	return EXIT_SUCCESS;
}