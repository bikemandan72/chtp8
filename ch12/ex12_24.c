/*
12.24 (Printing Trees)
Write a recursive function outputTree to display a binary tree on the screen.
The function should output the tree row-by-row with the top of the tree at the left
of the screen and the bottom of the tree toward the right of the screen. Each row is
output vertically.
For example, the binary tree illustrated in Fig. 12.22 is output as follows:
			99
		97
			92
	83
			72
		71
			69
49
			44
		40
			32
	28
			19
		18
			11
Note that the rightmost leaf node appears at the top of the output in the rightmost
column, and the root node appears at the left of the output. Each column of output
starts five spaces to the right of the previous column. Function outputTree should
receive as arguments a pointer to the root node of the tree and an integer
totalSpaces representing the number of spaces preceding the value to be output
(this variable should start at zero so that the root node is output at the left
of the screen). The function uses a modified inorder traversal to output
the tree. The algorithm is as follows:
While the pointer to the current node is not NULL
Recursively call outputTree with the current node’s right subtree and totalSpaces + 5 .
Use a for statement to count from 1 to totalSpaces and output spaces.
Output the value in the current node.
Recursively call outputTree with the current node’s left subtree and totalSpaces + 5 .
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure
struct treeNode {
	struct treeNode *leftPtr; // pointer to left subtree
	int data; // node value
	struct treeNode *rightPtr; // pointer to right subtree
}; 

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);
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

	//srand(time(NULL));
	int seed = 1699108271;
	srand(seed);
	//nice seeds: 1699107993, 1699108173, 1699108171, 1699108271
	puts("The numbers being placed in the tree are:");

	insertNode(&rootPtr, 10);
	// insert random values between 0 and 14 in the tree
	for (unsigned int i = 1; i <= 20; ++i) { 
		int item = rand() % 15;
		printf("%3d", item);
		insertNode(&rootPtr, item);
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
	printf("Random generator seed is %d\n", seed);
	printf("Root node is %d\n", rootPtr->data);
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
		printf("%d\n", (*treePtr)->data);
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
void insertNode(TreeNodePtr *treePtr, int value)
{ 
	// if tree is empty
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		// if memory was allocated, then assign data
		if (*treePtr != NULL) { 
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} else {
			printf("%d not inserted. No memory available.\n", value);
		}
	} else { // tree is not empty
		// data to insert is less than data in current node
		if (value < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);
		}// data to insert is greater than data in current node
		else if (value > (*treePtr)->data) {
			insertNode(&((*treePtr)->rightPtr), value);
		} else { // duplicate data value ignored
			printf("%s", "dup");
		}
	}
}

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{ 
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%3d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

// begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		printf("%3d", treePtr->data);
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
		printf("%3d", treePtr->data);
	}
}