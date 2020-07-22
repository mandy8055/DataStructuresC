#include <stdio.h>
#include "bTCreation.h"

int main(void){
	struct BTNode* root = newNode(1);
	root->leftC = newNode(2);
	root->rightC = newNode(3);
	
	root->leftC->leftC  = newNode(4); 
    	root->leftC->rightC = newNode(5); 
    	root->rightC->leftC  = newNode(6); 
    	root->rightC->rightC = newNode(7); 
    	root->leftC->leftC->leftC = newNode(8);
  
  	print2D(root);
	printf("\n\n\n\n");
	printf("The total number of nodes in the given binary tree is %d\n", countTotalNodes(root));
	printf("The total number of leaf nodes in the given binary tree is %d\n", countLeaf(root));
	printf("The total number of non-leaf(Internal) nodes in the given binary tree is %d\n", countNonLeaf(root));
	printf("The height of the given binary tree is %d\n", calcHeight(root));
	
//	if(checkSBT(root))printf("The given binary tree is a strict binary tree\n");
//	else printf("The given binary tree is not a strict binary tree\n");	

//  Convert the given tree into its mirror image
	struct BTNode* root2 = mirrorImage(root);
	print2D(root2);
	
	if(checkBTEqual(root, root2))printf("The given two trees are equal");
	else printf("The given two trees are not equal");
		
	
//	
	return 0;
}
