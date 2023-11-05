/*
12.23 (Level Order Binary Tree Traversal)
The program of Fig. 12.19 illustrated three recursive methods of traversing a binary
tree—inorder traversal, preorder traversal, and postorder traversal.
This exercise presents the level order traversal of a binary tree in which the node
values are printed level-by-level starting at the root node level. The nodes on each
level are printed from left to right.
The level order traversal is not a recursive algorithm. It uses the queue data
structure to control the output of the nodes. The algorithm is as follows:
1) Insert the root node in the queue
2) While there are nodes left in the queue,
	Get the next node in the queue
	Print the node’s value
	If the pointer to the left child of the node is not NULL
	Insert the left child node in the queue
	If the pointer to the right child of the node is not NULL
	Insert the right child node in the queue.
Write function levelOrder to perform a level order traversal of a binary tree.
The function should take as an argument a pointer to the root node of the binary tree.
Modify the program of Fig. 12.19 to use this function. Compare the output from this
function to the outputs of the other traversal algorithms to see that it worked
correctly. [Note: You’ll also need to modify and incorporate the queue-processing
functions of Fig. 12.13 in this program.]
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue_tree.h"

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

void levelOrder(TreeNodePtr *treePtr);
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
	//to increase the chance of more balanced tree we put middle value first [1..15]
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
	
	// traverse the tree levelOrder
	puts("\n\nThe levelOrder traversal is:");
	levelOrder(&rootPtr);
		
	puts("");
	printf("Random generator seed is %d\n", seed);
	printf("Root node is %d\n", rootPtr->data);
	puts("");
	outputTree(&rootPtr);

	puts("");
	freeTree(&rootPtr);
}
void levelOrder(TreeNodePtr *treePtr) {
	QueueNodePtr queue = NULL;
	queue = initQueue(&queue);
	if (treePtr != NULL) {
		enqueue(&queue, treePtr);
		while (!isEmptyQueue(&queue)) {
			TreeNodePtr extractedTreePtr = dequeue(&queue);
			printf(" %d ", extractedTreePtr->data);
			if (extractedTreePtr->leftPtr != NULL) {
				enqueue(&queue, &(extractedTreePtr->leftPtr));
			}
			if (extractedTreePtr->rightPtr != NULL) {
				enqueue(&queue, &(extractedTreePtr->rightPtr));
			}
		}
	} else {
		puts("NULL");
	}
	puts("");
	freeQueue(&queue);
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