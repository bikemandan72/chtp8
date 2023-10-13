/*
11.17 (Simpletron with File Processing) 
In Exercise 7.28, you wrote a software simulation of a computer that used a special
machine language called Simpletron Machine Language (SML). In the simulation, each
time you wanted to run an SML program, you entered the program into the simulator
from the keyboard. If you made a mistake while typing the SML program, the simulator 
was restarted and the SML code was reentered. It would be nice to be able to read 
the SML program from a file rather than type it each time. This would reduce time 
and mistakes in preparing to run SML programs.
a) Modify the simulator you wrote in Exercise 7.28 to read SML programs from a file
specified by the user at the keyboard.
b) After the Simpletron executes, it outputs the contents of its registers and memory 
on the screen. It would be nice to capture the output in a file, so modify the
simulator to write its output to a file in addition to displaying it on the screen.
ANSWER: To make Simpletron read source code from file specify it as an argument, i.e. 
./ex11_17 ex07_27a.sml
*/
#include <stdio.h>

//operation codes as constants
//Input/output operations:
#define READ 10
#define WRITE 11
//Load/store operations:
#define LOAD 20
#define STORE 21
//Arithmetic operations:
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
//Transfer-of-control operations:
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
//memory size
#define MEM_SIZE 100

//miscellaneous
#define QUESTION_MARK '?'
#define SENTINEL -99999
#define DUMP "simpletron.dump"
#define WRITE_MODE "w"
#define READ_MODE "r"

//function prototypes
void load(int memory[MEM_SIZE], int *instructionCounter, int *instructionRegister);
int loadFromFile(const char * filename, 
	int memory[MEM_SIZE], int *instructionCounter, int *instructionRegister);
void execute(int memory[MEM_SIZE],
	int *instructionCounter, int *instructionRegister,
	int *accumulator,
	int *operationCode, int *operand);
void dump(int memory[MEM_SIZE],
	int *instructionCounter, int *instructionRegister,
	int *accumulator,
	int *operationCode, int *operand,
	FILE *outputStream);

int main(int argc, char *argv[])
{
	int accumulator = 0;
	int instructionCounter = 0;
	int instructionRegister = 0;
	int operationCode = 0;
	int operand = 0;
    int memory[MEM_SIZE] = {0};
	
	puts("*** Welcome to Simpletron! ***");
	if (argc == 2) {
		if (loadFromFile(argv[1], memory, 
			&instructionCounter, &instructionRegister) != 0) {
			load(memory, &instructionCounter, &instructionRegister);
		}
	} else {
		load(memory, &instructionCounter, &instructionRegister);
	}
	
	execute(memory, &instructionCounter, &instructionRegister,
		&accumulator, &operationCode, &operand);
	
	dump(memory, &instructionCounter, &instructionRegister,
		&accumulator, &operationCode, &operand, stdout);
		
	FILE *dfPtr = NULL;
	dfPtr = fopen(DUMP, WRITE_MODE);
	if (dfPtr == NULL) {
		printf("Couldn't dump memory to file %s\n", DUMP);
	} else {
		dump(memory, &instructionCounter, &instructionRegister,
			&accumulator, &operationCode, &operand, dfPtr);
		fclose(dfPtr);
	}
	
	return 0;
}
void execute(int memory[MEM_SIZE],
	int *instructionCounter, int *instructionRegister,
	int *accumulator,
	int *operationCode, int *operand) {
	
	puts("*** Program execution begins ***");
	int fatalError = 0;
	*instructionCounter = 0;
	do {
		*instructionRegister = memory[*instructionCounter];
		*operationCode = *instructionRegister / 100;
		*operand = *instructionRegister % 100;
		switch(*operationCode) {
			case READ: {
				printf("%c ", QUESTION_MARK);
				scanf("%d", &memory[*operand]);
				break;
			}
			case WRITE: {
				printf("%d\n", memory[*operand]);
				break;
			}
			case LOAD: {
				*accumulator = memory[*operand];
				break;
			}
			case STORE: {
				memory[*operand] = *accumulator;
				break;
			}
			case ADD: {
				*accumulator += memory[*operand];
				break;
			}
			case SUBTRACT: {
				*accumulator -= memory[*operand];
				break;
			}
			case MULTIPLY: {
				*accumulator *= memory[*operand];
				break;
			}
			case DIVIDE: {
				if (memory[*operand] != 0)
					*accumulator /= memory[*operand];
				else {
					puts("*** Attempt to divide by zero ***");
					fatalError = 1;
				}
				break;
			}
			case BRANCH: {
				*instructionCounter = *operand;
				break;
			}
			case BRANCHNEG: {
				if (*accumulator < 0)
					*instructionCounter = *operand;
				else
					*instructionCounter += 1;
			break;
			}
			case BRANCHZERO: {
				if (*accumulator == 0)
					*instructionCounter = *operand;
				else
					*instructionCounter += 1;
				break;
			}
			case HALT: {
				puts("*** Simpletron execution terminated ***");
				break;
			}
			default: {
				puts("*** Invalid operation code ***");
				fatalError = 1;
				break;
			}
		}
		
		if (!(*operationCode == BRANCH || 
			*operationCode == BRANCHNEG || 
			*operationCode == BRANCHZERO)) {
			if (*accumulator < -9999 || *accumulator > 9999) {
				puts("*** Arithmetic operation overflow ***");
				fatalError = 1;
			} else
				*instructionCounter += 1;
		}
		if (fatalError == 1) {
			puts("*** Simpletron execution abnormally terminated ***");
			break;
		}
	} while (*instructionCounter < MEM_SIZE && *operationCode != HALT);
}
int loadFromFile(const char * filename, 
	int memory[MEM_SIZE], int *instructionCounter, int *instructionRegister) {
	
	*instructionRegister = 0;
	*instructionCounter = 0;
	
	FILE *sfPtr = NULL;
	sfPtr = fopen(filename, READ_MODE);
	if (sfPtr == NULL) {
		printf("Couldn't open the source file %s\n", filename);
		return 1;//failure
	}
	puts("*** Loading program from file ***");
	fscanf(sfPtr, "%d", instructionRegister);
	while (!feof(sfPtr) &&
		*instructionRegister != SENTINEL && 
		*instructionCounter < MEM_SIZE) {
		
		if (*instructionRegister > -9999 && *instructionRegister < 9999) {
			memory[*instructionCounter] = *instructionRegister;
			*instructionCounter += 1;
		} else if (*instructionRegister != SENTINEL) {
			puts("Input is out of range [-9999:9999].");
			fclose(sfPtr);
			return 1;//failure
		}
		fscanf(sfPtr, "%d", instructionRegister);
	}
	puts("*** Program loading completed ***");
	if (sfPtr != NULL) {
		fclose(sfPtr);
	}
	return 0;//success
}
void load(int memory[MEM_SIZE], int *instructionCounter, int *instructionRegister) {
	puts("*** Please enter your program one instruction ***");
	puts("*** (or data word) at a time. I will type the ***");
	puts("*** location number and a question mark (?). ***");
	puts("*** You then type the word for that location. ***");
	puts("*** Type the sentinel -99999 to stop entering ***");
	puts("*** your program. ***");
	*instructionRegister = 0;
	*instructionCounter = 0;
	do {
		printf("%02d %c ", *instructionCounter, QUESTION_MARK);
		scanf("%d", instructionRegister);
		if (*instructionRegister > -9999 && *instructionRegister < 9999) {
			memory[*instructionCounter] = *instructionRegister;
			*instructionCounter += 1;
		}
		else if (*instructionRegister != SENTINEL) {
			puts("Input is out of range [-9999:9999].");
			puts("Reenter a valid instruction.");
		}
	} while (*instructionRegister != SENTINEL && *instructionCounter < MEM_SIZE);
	puts("*** Program loading completed ***");
}
void dump(int memory[MEM_SIZE],
             int *instructionCounter, int *instructionRegister,
             int *accumulator,
             int *operationCode, int *operand,
             FILE *outputStream) {
	
	fprintf(outputStream, "%s\n", "REGISTERS:");
	fprintf(outputStream, "%-30s%+05d\n", "accumulator", *accumulator);
	fprintf(outputStream, "%-30s%02d\n", "instructionCounter", *instructionCounter);
	fprintf(outputStream, "%-30s%+05d\n", "instructionRegister", *instructionRegister);
	fprintf(outputStream, "%-30s%02d\n", "operationCode", *operationCode);
	fprintf(outputStream, "%-30s%02d\n", "operand", *operand);
	
	fprintf(outputStream, "\nMEMORY:\n");
	fprintf(outputStream, "%s", "  ");
	
	for (int i = 0; i < 10; ++i)
		fprintf(outputStream, "  %5d", i);
	
	int i = 0;
	for (int row = 0; row < 10; row++){
		fprintf(outputStream, "\n%02d", row * 10);
		for (int col = 0; col < 10; col++){
			fprintf(outputStream, "  %+05d", memory[i]);
			i++;
		}
	}
	fprintf(outputStream, "%s", "\n");
}
