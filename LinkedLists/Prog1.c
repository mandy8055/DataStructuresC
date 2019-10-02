#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "linkedListHeader.h"

// Return second last node address from the given linked list
struct node* rtnScndLstNodeAdrs(struct node* start){
	
//	Base case
	if(start == NULL){
		return;
	}
	
	if(start->next == NULL){
		return;
	}
	
	struct node* previous = NULL;
	
	while(start->next != NULL){
		previous = start;
		start = start->next;
	}
	return previous;
}

// Insert a node with data x before node containing data y
struct node* insertXBeforeY(struct node* s, int x, int y){
//	Create the node
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = x;
	
	if(s == NULL){
		return NULL;
	}
	struct node* previous = NULL;
	struct node* s1 = s;
	while(s1->data != y && s1->next != NULL){
		previous = s1;
		s1 = s1->next;
	}
	if(s1->data == y){
		previous->next = newNode;
		newNode->next = s1;
		return s;
	}else{
		return NULL;
	}
}

// Print the linked list
void printLL(struct node* s){	
	if(s == NULL){
		printf("The Linked list is empty");
	}else{
		printf("Contents:\n");	
	}
	
	while(s != NULL){
		printf("%d-->", s->data);
		 s= s->next;
	}
	printf("NULL\n");
	
}

// Delete the last node of the linked list
struct node* deleteLast(struct node* s){
	if(s == NULL)return NULL;
	struct node* s1 = s;
	struct node* previous = NULL;
	while(s1->next != NULL){
		previous = s1;
		s1 = s1->next;
	} 
	previous->next = NULL;
	free(s1);
	s1 = NULL;
	
	return s;
}

// Delete the node containing data X
struct node* deleteX(struct node* s, int x){
	if(s == NULL)return NULL;
	struct node* s1 = s;
	struct node* previous = NULL;
	while(s1->data != x && s1->next != NULL){
		previous = s1;
		s1 = s1->next;
	}
	
	if(s1->data == x){
		previous->next = s1->next;
//		free(s1);
//		s1 = NULL;
		return s;
	}else{
//		Data x NOT found in the Linked List
		return NULL;
	}
	
	
	
}

// Reversing a linked list
struct node* reverseLL(struct node* s){
//	Base cases
	if(s == NULL)return;
	if(s->next == NULL) return s;
//	Main case
	struct node* previous = NULL;
	struct node* middle = NULL;
	while(s != NULL){
		previous = middle;
		middle = s;
		s = s->next;
		middle->next = previous;
	}
	s = middle;
	return s;
}

// Finding mid element and return it in the given singly linked list(Slower Method)
int mid_Algo1(struct node* s){
//	Base cases
	if(s == NULL)return 0;
	if(s->next == NULL) return s->data;
	int count = 0;
	struct node* s1 = s;
//	Counting the size of the linked list.
	while(s1 != NULL){
		count++;
		s1 = s1->next;
	}
	count = (int)ceil((double)count / 2);
//	Finding the mid element
	while (count != 1){
		count--;
		s = s->next;
	}
	
	return s->data;
}

// Finding the mid element and return it in the given linked list(Fast and Slow Pointer Approach)
// Efficient Algorithm to find middle of the element in the linked list
int mid_Algo2(struct node* s){
//	Base cases
	if(s == NULL)return 0;
	if(s->next == NULL)return s->data;
	
	struct node* fast = s->next;
	struct node* slow = s;
	
	while(fast != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
	
}

// Main function
int main(void){
	
	struct node* getLL = returnLL();
	printf("Linked List before insetion/Deletion/Reversal:\n");
	printLL(getLL);
//	printf("Linked List after insetion/Deletion:\n");
//	printLL(insertXBeforeY(getLL, 110, 30));
//	printLL(deleteLast(getLL));
//	printLL(deleteX(getLL, 30));
//	printf("Linked List after reversal:\n");
//	printLL(reverseLL(getLL));
	printf("The element at the middle of the given linked list is %d\n", mid_Algo2(getLL));
	
//	printf("The address of second last node is: %u", rtnScndLstNodeAdrs(getLL));
	return 0;
}
