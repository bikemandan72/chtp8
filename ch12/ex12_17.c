/*
12.17 (Binary Search Tree of Strings)
Write a program based on the program of Fig. 12.19 that inputs a line of text,
tokenizes the sentence into separate words, inserts the words in a binary search
tree, and prints the in-order, pre-order, and post-order traversals of the tree.
[Hint: Read the line of text into an array. Use strtok to tokenize the text.
When a token is found, create a new node for the tree, assign the pointer returned by
strtok to member string of the new node, and insert the node in the tree.]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 100
#define WORDSIZE 15

// self-referential structure
struct treeNode {
	struct treeNode *leftPtr; // pointer to left subtree
	char data[WORDSIZE]; // node value
	struct treeNode *rightPtr; // pointer to right subtree
}; 

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, char *value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void outputTree(TreeNodePtr *treePtr);
void printIndentation(unsigned int depth);
void freeTree(TreeNodePtr *treePtr);

// function main begins program execution
int main(void)
{ 
	TreeNodePtr rootPtr = NULL; // tree initially empty

	//char inputStr[STRSIZE] = "function main begins program main execution function";
	char inputStr[STRSIZE] = "";
	char *tokenPtr = NULL;

	puts("Enter the sentence:");
	fgets(inputStr, STRSIZE - 1, stdin);
	strtok(inputStr, "\n");
	
	tokenPtr = strtok(inputStr, " ");
	while (tokenPtr != NULL) {
		insertNode(&rootPtr, tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}

	// traverse the tree preOrder
	puts("\n\nThe preOrder traversal is:");
	preOrder(rootPtr);

	// traverse the tree inOrder
	puts("\n\nThe inOrder traversal is:");
	inOrder(rootPtr);

	// traverse the tree postOrder
	puts("\n\nThe postOrder traversal is:");
	postOrder(rootPtr);
	
	puts("");
	printf("Root node is '%s'\n", rootPtr->data);
	puts("");
	outputTree(&rootPtr);
	puts("");
	
	freeTree(&rootPtr);
}
void outputTree(TreeNodePtr *treePtr) {
	static unsigned int depth = 0;
	if (*treePtr != NULL) {
		depth++;
		outputTree(&((*treePtr)->rightPtr));
		depth--;
		printIndentation(depth);
		printf("%s\n", (*treePtr)->data);
		depth++;
		outputTree(&((*treePtr)->leftPtr));
		depth--;
	} else {
		printIndentation(depth);
		puts("NULL");
	}
}
void freeTree(TreeNodePtr *treePtr) {
	if (*treePtr != NULL) {
		freeTree(&((*treePtr)->leftPtr));
		freeTree(&((*treePtr)->rightPtr));
		free((*treePtr)->leftPtr);
		(*treePtr)->leftPtr = NULL;
		free((*treePtr)->rightPtr);
		(*treePtr)->rightPtr = NULL;
		free(*treePtr);
		*treePtr = NULL;
	}
}
void printIndentation(unsigned int depth) {
	for (size_t i = 0; i < depth; ++i) {
		printf("%c", '\t');
	}
}
// insert node into tree
void insertNode(TreeNodePtr *treePtr, char *value)
{ 
	// if tree is empty
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		// if memory was allocated, then assign data
		if (*treePtr != NULL) { 
			strcpy((*treePtr)->data, value);
			strcat((*treePtr)->data, "");
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} else {
			printf("'%s' not inserted. No memory available.\n", value);
		}
	} else { // tree is not empty
		// data to insert is less than data in current node
		if (strcmp(value, (*treePtr)->data) < 0) {
			insertNode(&((*treePtr)->leftPtr), value);
		}// data to insert is greater than data in current node
		else if (strcmp(value, (*treePtr)->data) > 0) {
			insertNode(&((*treePtr)->rightPtr), value);
		} else { // duplicate data value ignored
			printf("Duplicate '%s' was ignored\n", value);
		}
	}
}

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{ 
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf(" %s ", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

// begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		printf(" %s ", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

// begin postorder traversal of tree
void postOrder(TreeNodePtr treePtr)
{ 
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf(" %s ", treePtr->data);
	}
}