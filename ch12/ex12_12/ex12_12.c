/*
12.12 (Infix-to-Postfix Converter)
Stacks are used by compilers to help in the process of evaluating expressions and
generating machine-language code. In this and the next exercise, we investigate how
compilers evaluate arithmetic expressions consisting only of constants, operators
and parentheses.
Humans generally write expressions like 3 + 4 and 7 / 9 in which the operator
( + or / here) is written between its operands—this is called infix notation.
Computers “prefer” postfix notation in which the operator is written to the right
of its two operands. The preceding infix expressions would appear in postfix notation
as 3 4 + and 7 9 / , respectively.
To evaluate a complex infix expression, some compilers first convert the expression to
postfix notation, and then evaluate the postfix version. Each of these algorithms
requires only a single left-to-right pass of the expression. Each algorithm uses a
stack in support of its operation, and in each the stack is used for a different
purpose.
In this exercise, you’ll write a version of the infix-to-postfix conversion algorithm.
In the next exercise, you’ll write a version of the postfix-expression evaluation
algorithm.
Write a program that converts an ordinary infix arithmetic expression (assume a valid
expression is entered) with single-digit integers such as (6 + 2) * 5 - 8 / 4
to a postfix expression. The postfix version of the preceding infix expression is
6 2 + 5 * 8 4 / -
The program should read the expression into character array infix and use the stack
functions implemented in this chapter to help create the postfix expression in
character array postfix . The algorithm for creating a postfix expression is as follows:
1) Push a left parenthesis '(' onto the stack.
2) Append a right parenthesis ')' to the end of infix .
3) While the stack is not empty, read infix from left to right and do the following:
If the current character in infix is a digit, copy it to the next element of postfix .
If the current character in infix is a left parenthesis, push it onto the stack.
If the current character in infix is an operator,
	Pop operators (if there are any) at the top of the stack while they have equal or
		higher precedence than the current operator, and insert the popped
		operators in postfix .
	Push the current character in infix onto the stack.
If the current character in infix is a right parenthesis
	Pop operators from the top of the stack and insert them in postfix until a left
	parenthesis is at the top of the stack.
	Pop (and discard) the left parenthesis from the stack.
The following arithmetic operations are allowed in an expression:
+ addition
- subtraction
* multiplication
/ division
^ exponentiation
% remainder
The stack should be maintained with the following declarations:
struct stackNode {
	char data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;
The program should consist of main and eight other functions with the following function headers:
void convertToPostfix(char infix[], char postfix[])
	Convert the infix expression to postfix notation.
int isOperator(char c)
	Determine whether c is an operator.
int precedence(char operator1, char operator2)
	Determine whether the precedence of operator1 is less than, equal to, or greater than
	the precedence of operator2 . The function returns -1 , 0 and 1 , respectively.
void push(StackNodePtr *topPtr, char value)
	Push a value on the stack.
char pop(StackNodePtr *topPtr)
	Pop a value off the stack.
char stackTop(StackNodePtr topPtr)
	Return the top value of the stack without popping the stack.
int isEmpty(StackNodePtr topPtr)
	Determine whether the stack is empty.
void printStack(StackNodePtr topPtr)
	Print the stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../lib/stack.h"

#define SIZE 50
#define OPERATORS 6
#define LEFT_PARETHESIS '('
#define RIGHT_PARETHESIS ')'
#define R_L 1
#define L_R 0

void printNode(Item value);
void convertToPostfix(const char *const input, char *output);
int isOperator(char symbol);

int main (int argc, char *argv[])
{
	//char infix[SIZE + 1] = "(6 + 2) * 5 - 8 / 4";
	//char infix[SIZE + 1] = "3+4*2/(1-5)^2^3";
	//char infix[SIZE + 1] = "(4-2)^3+2";
	char postfix[SIZE + 1];
	char infix[SIZE + 1];
	
	puts("Enter an infix expression (49 symbols max):");
	fgets(infix, SIZE - 1, stdin);
	strtok(infix, "\n");
	
	strcat(infix, ")");
	convertToPostfix(infix, postfix);
	
	puts(postfix);
		
	return EXIT_SUCCESS;
}
void convertToPostfix(const char *const input, char *output) {
	int precedence[OPERATORS] = {0, 0, 1, 1, 2, 1};
	//0 - left-to-right (L_R), 1 - right-to-left (R_L)
	int associativity[OPERATORS] = {L_R, L_R, L_R, L_R, R_L, L_R};
	Stack stack_1 = NULL;
	stack_1 = initStack(&stack_1);
	
	pushToStack(&stack_1, LEFT_PARETHESIS);
	for (size_t i = 0; input[i] != '\0' && input[i] != '\n'; ++i) {
		printStack(&stack_1, printNode);
		puts("");
		if (!isgraph(input[i])) {
			//ignore non-printable characters and spaces
			continue;
		}
		if (isdigit(input[i])) {
			*output = input[i];
			output++;
			continue;
		}
		if (input[i] == LEFT_PARETHESIS) {
			pushToStack(&stack_1, input[i]);
			continue;
		}
		int infixOperator = isOperator(input[i]);
		if (infixOperator >= 0) {
			do {
				char stackTop = (char)getTopValue(&stack_1);
				int stackOperator = isOperator(stackTop);
				if (stackOperator >= 0) {
					if (precedence[stackOperator] >= precedence[infixOperator]) {
						if (associativity[infixOperator] != R_L) {
							*output = (char)popFromStack(&stack_1);
							output++;
							continue;
						}
					}
				}
				break;
			} while (1);
			pushToStack(&stack_1, input[i]);
		}
		if (input[i] == RIGHT_PARETHESIS) {
			while ((char)getTopValue(&stack_1) != LEFT_PARETHESIS) {
				*output = (char)popFromStack(&stack_1);
				output++;
			}
			popFromStack(&stack_1);
		}
	}
	*output = '\0';
	
	freeStack(&stack_1);
}
int isOperator(char symbol) {
	char operators[OPERATORS] = {'+', '-', '*', '/', '^', '%'};
	int indexOperator = -1;
	for (size_t i = 0; i < OPERATORS; ++i) {
		if (operators[i] == symbol) {
			indexOperator = i;
			break;
		}
	}
	
	return indexOperator;
}
void printNode(Item value) {
	printf("%c", value);
}