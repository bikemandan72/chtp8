/*
12.16 (Allowing Duplicates in a Binary Tree)
Modify the program of Fig. 12.19 to allow the binary tree to contain duplicate values.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure
struct treeNode {
	struct treeNode *leftPtr; // pointer to left subtree
	int data; // node value
	unsigned int count; //number of this values in the tree
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
TreeNodePtr dumbBinaryTreeSearch(const TreeNodePtr *const treePtr, int searchKey);
TreeNodePtr binaryTreeSearch(const TreeNodePtr *const treePtr, int searchKey);

// function main begins program execution
int main(void)
{ 
	TreeNodePtr rootPtr = NULL; // tree initially empty

	int seed = time(NULL);
	srand(seed);
	
	puts("The numbers being placed in the tree are:");
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
		printf("%d(%u)\n", (*treePtr)->data, (*treePtr)->count);
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
			(*treePtr)->count = 1;
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
			(*treePtr)->count++;
		}
	}
}

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{ 
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%3d(%u)", treePtr->data, treePtr->count);
		inOrder(treePtr->rightPtr);
	}
}

// begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		printf("%3d(%u)", treePtr->data, treePtr->count);
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
		printf("%3d(%u)", treePtr->data, treePtr->count);
	}
}