#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define COUNT 10

// Creating a binary Tree node
struct BTNode{
	int data;
	struct BTNode* leftC;
	struct BTNode* rightC;
}; 
// Helper Function to allocate a new Node to the binary tree
struct BTNode* newNode(int data){
	struct BTNode* btNode = (struct BTNode*)malloc(sizeof(struct BTNode));
	btNode->data = data;
	btNode->leftC = btNode->rightC = NULL;
	return btNode;
}	

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct BTNode *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->rightC, space); 
  
    // Print current node after space 
    // count 
    printf("\n");
	int i; 
    for (i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->leftC, space); 
} 	 

// Wrapper over print2DUtil() 
void print2D(struct BTNode *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
}


// ---------------------------Data Structure Functions-------------------------




// Remember --> Recursion is usually preferred in case of implementing tree problems.

// Count the total number of nodes in a tree
int countTotalNodes(struct BTNode* root){
//	Base Case
	if(root == NULL)return 0;
	else{
		return 1 + countTotalNodes(root->leftC) + countTotalNodes(root->rightC);
	}
	
}

// Count total number of leaf nodes in a given binary tree
int countLeaf(struct BTNode* root){
//	Base case
	if(root == NULL)return 0;
//	Termination Condition
	if(root->leftC == NULL && root->rightC == NULL)
		return 1;
	else{
		return countLeaf(root->leftC) + countLeaf(root->rightC);
	}
}

// Count total number of non-leaf(internal) nodes in a given binary tree
int countNonLeaf(struct BTNode* root){
//	Base case
	if(root == NULL)return 0;
//	Termination condition
	if(root->leftC == NULL && root->rightC == NULL)
		return 0;
	else{
		return 1 + countNonLeaf(root->leftC) + countNonLeaf(root->rightC);
	}
}

// Find the height of a given binary tree
int calcHeight(struct BTNode* root){
	if(root == NULL)return 0;
	if(root->leftC == NULL && root->rightC == NULL)return 0;
	else{
		// Adding one in order to count the height of the exisitng node.
		return (1 + MAX(calcHeight(root->leftC), calcHeight(root->rightC)));
	}
}

// Check whether a given Binary Tree is a strict binary tree or not. Strict binary tree contains either a leaf node or a node having exactly 2 children.
bool checkSBT(struct BTNode* root){
//	Base Case
	if(root == NULL)return true;
//	Leaf Node
	if(root->leftC == NULL && root->rightC == NULL)return true;
//	Node containing exactly 2 children
	if(root->leftC != NULL && root->rightC != NULL)
		return (checkSBT(root->leftC) && checkSBT(root->rightC));	
	return false;
}

// Convert the given binary tree into its mirror
struct BTNode* mirrorImage(struct BTNode* root){
//	Base Case
	if(root == NULL)return root;
	// If leaf node
	if(root->leftC == NULL && root->rightC == NULL)return root;
	else{
		struct BTNode* temp = NULL;
//		Do the trees(Non-tail recursion)
		mirrorImage(root->leftC);
		mirrorImage(root->rightC);
		
//		Swap the left and right child
		temp = mirrorImage(root->leftC);
		root->leftC = root->rightC;
		root->rightC = temp;
		
		return root;
	}
}

// Check whether two given Binary trees are equal or not
bool checkBTEqual(struct BTNode* root1, struct BTNode* root2){
//	Base Case
	if(root1 == NULL && root2 == NULL)return true;
	if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))return false;
	// Recurse if both tree's current nodes are equal. 
	if(root1->data == root2->data){
		return (checkBTEqual(root1->leftC, root2->leftC) && checkBTEqual(root1->rightC, root2->rightC)); 
	}
	return false;
}
