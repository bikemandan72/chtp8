/*
12.14 (Postfix Evaluator Modification)
Modify the postfix evaluator program of Exercise 12.13
so that it can process integer operands larger than 9.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#include "../lib/stack.h"

#define SIZE 50
#define OPERATORS 6
#define DELIMITER " "

void printNode(Item value);
int evaluatePostfixExpression(char *expr);
int isOperator(char *symbol);
int calculate(int subtop, int top, char *operator);

int main (int argc, char *argv[])
{
	//char postfix[SIZE + 1] = "40 20 - 3 ^ 2 +";
	char copy_postfix[SIZE + 1] = "";

	char postfix[SIZE + 1];
	puts("Enter a postfix expression (49 symbols max):");
	fgets(postfix, SIZE - 1, stdin);
	strtok(postfix, "\n");
	
	strcat(copy_postfix, postfix);
	printf("The result of the expression %s = %d\n",
		copy_postfix, evaluatePostfixExpression(postfix));
		
	return EXIT_SUCCESS;
}
int evaluatePostfixExpression(char *expr) {
	int result = INT_MIN;
	Stack stack_1 = NULL;
	stack_1 = initStack(&stack_1);
	
	char *tokenPtr = strtok(expr, DELIMITER);
	while(tokenPtr != NULL) {
		if (isOperator(tokenPtr) >= 0) {
			int stack_top = popFromStack(&stack_1);
			int stack_subtop = popFromStack(&stack_1);
			pushToStack(&stack_1, (Item)calculate(stack_subtop, stack_top, tokenPtr));
		} else {
			pushToStack(&stack_1, (Item)strtol(tokenPtr, NULL, 10));
		}
		tokenPtr = strtok(NULL, DELIMITER);
	}
	
	if (!isEmptyStack(&stack_1)) {
		result = popFromStack(&stack_1);
	}
	
	freeStack(&stack_1);
	return result;
}
int calculate(int subtop, int top, char *operator) {
	int result = INT_MIN;
	if (strcmp("+", operator) == 0) {
		result = subtop + top;
	}
	if (strcmp("-", operator) == 0) {
		result = subtop - top;
	}
	if (strcmp("*", operator) == 0) {
		result = subtop * top;
	}
	if (strcmp("/", operator) == 0) {
		if (top != 0) {
			result = subtop / top;
		} else {
			printf("ERROR! Division by zero: %d / %d\n", subtop, top);
		}
	}
	if (strcmp("^", operator) == 0) {
		result = pow(subtop, top);
	}
	if (strcmp("%", operator) == 0) {
		result = subtop % top;
	}
	printf("%d %s %d = %d\n", subtop, operator, top, result);
	return result;
}
int isOperator(char *symbol) {
	char *operators[OPERATORS] = {"+", "-", "*", "/", "^", "%"};
	int indexOperator = -1;
	for (size_t i = 0; i < OPERATORS; ++i) {
		if (strcmp(operators[i], symbol) == 0) {
			indexOperator = i;
			break;
		}
	}
	return indexOperator;
}
void printNode(Item value) {
	printf("%c", value);
}