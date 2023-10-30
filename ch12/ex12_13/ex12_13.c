/*
12.13 (Postfix Evaluator)
Write a program that evaluates a postfix expression (assume it’s valid) such as
6 2 + 5 * 8 4 / -
The program should read a postfix expression consisting of single digits and operators into a character array. Using the stack functions implemented earlier in this chapter, the program should scan the expression and evaluate it. The algorithm is as follows:
1) Append the null character ( '\0' ) to the end of the postfix expression.
When the null character is encountered, no further processing is necessary.
2) While '\0' has not been encountered, read the expression from left to right.
If the current character is a digit,
	Push its integer value onto the stack (the integer value of a digit character is
	its value in the computer’s character set minus the value of '0' in the computer’s
	character set).
Otherwise, if the current character is an operator,
	Pop the two top elements of the stack into variables x and y .
	Calculate y operator x .
	Push the result of the calculation onto the stack.
3) When the null character is encountered in the expression, pop the top value of the stack.
This is the result of the postfix expression.
[Note:
In 2) above, if the operator is '/' , the top of the stack is 2 , and the next element in the stack is 8 , then pop 2 into x , pop 8 into y , evaluate 8 / 2 , and push the result, 4 , back onto the stack. This note also applies to the other binary operators.]
The arithmetic operations allowed in an expression are:
+ addition
- subtraction
* multiplication
/ division
^ exponentiation
% remainder
The stack should be maintained with the following declarations:
struct stackNode {
int data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;
The program should consist of main and six other functions with the following
function headers:
int evaluatePostfixExpression(char *expr)
	Evaluate the postfix expression.
int calculate(int op1, int op2, char operator)
	Evaluate the expression op1 operator op2 .
void push(StackNodePtr *topPtr, int value)
	Push a value on the stack.
int pop(StackNodePtr *topPtr)
	Pop a value off the stack.
int isEmpty(StackNodePtr topPtr)
	Determine whether the stack is empty.
void printStack(StackNodePtr topPtr)
	Print the stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#include "../lib/stack.h"

#define SIZE 50
#define OPERATORS 6
#define ASCII_OFFSET 48

void printNode(Item value);
int evaluatePostfixExpression(char *expr);
int isOperator(char symbol);
int calculate(int subtop, int top, char operator);

int main (int argc, char *argv[])
{
	//char postfix[SIZE + 1] = "62+5*84/-";
	//char postfix[SIZE + 1] = "42-3^2+";
	char postfix[SIZE + 1];
	puts("Enter a postfix expression (49 symbols max):");
	fgets(postfix, SIZE - 1, stdin);
	strtok(postfix, "\n");
	
	printf("The result of the expression %s = %d\n",
		postfix, evaluatePostfixExpression(postfix));
		
	return EXIT_SUCCESS;
}
int evaluatePostfixExpression(char *expr) {
	int result = INT_MIN;
	Stack stack_1 = NULL;
	stack_1 = initStack(&stack_1);
	
	for (size_t i = 0; expr[i] != '\0' && expr[i] != '\n'; ++i) {
		if (isOperator(expr[i]) >= 0) {
			int stack_top = popFromStack(&stack_1);
			int stack_subtop = popFromStack(&stack_1);
			pushToStack(&stack_1, (Item)calculate(stack_subtop, stack_top, expr[i]));
		} else {
			pushToStack(&stack_1, (Item)(expr[i] - ASCII_OFFSET));
		}
	}
	
	if (!isEmptyStack(&stack_1)) {
		result = popFromStack(&stack_1);
	}
	
	freeStack(&stack_1);
	return result;
}
int calculate(int subtop, int top, char operator) {
	int result = INT_MIN;
	switch (operator) {
		case '+': {
			result = subtop + top;
			break;
		}
		case '-': {
			result = subtop - top;
			break;
		}
		case '*': {
			result = subtop * top;
			break;
		}
		case '/': {
			if (top != 0) {
				result = subtop / top;
			} else {
				printf("ERROR! Division by zero: %d / %d\n", subtop, top);
			}		
			break;
		}
		case '^': {
			result = pow(subtop, top);
			break;
		}
		case '%': {
			result = subtop % top;
			break;
		}								
		default: {
			result = INT_MIN;
			break;
		}
	}
	printf("%d %c %d = %d\n", subtop, operator, top, result);
	return result;
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