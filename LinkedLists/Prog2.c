#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
	int data;
	struct node* next;
};

// Print the linked list
void printLL(struct node* s){	
	if(s == NULL){
		printf("The Linked list is empty");
	}else{
		printf("Contents:\n");	
	}
	
	while(s != NULL){
		printf("%d-->", s->data);
		s = s->next;
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

// Reverse a linked List
struct node* reverseLL(struct node* s){
	if(s == NULL)return;
	if(s->next == NULL)return s;
	
	struct node* previous = NULL;
	struct node*  middle = NULL;
	while(s != NULL){
		previous = middle;
		middle = s;
		s = s->next;
		middle->next = previous;
	}
	s = middle;
	return s;
}

// Finding and returning the middle element of the linked list
int middle_Algo1(struct node* s){
	if(s == NULL)return 0;
	if(s->next == NULL)return s->data;
	struct node* s1 = s;
	int count = 0;
	while(s1 != NULL){
		count++;
		s1 = s1->next;
	}
	count = (int)ceil((double)count / 2);
	while(count != 1){
		count--;
		s = s->next;
	}
	
	return s->data;
}

int main(void){
	struct node first = {10, NULL};
	struct node second = {20, NULL};
	struct node third = {30, NULL};
	struct node fourth = {40, NULL};
	struct node fifth = {50, NULL};
	
	first.next = &second;
	second.next = &third;
	third.next = &fourth;
	fourth.next = &fifth;
	
	struct node* linkedList = &first;
	
	printLL(linkedList);
	
//	printLL(deleteLast(linkedList));

//	printLL(reverseLL(linkedList));
	printf("The middle element of the given linked list is %d", middle_Algo1(linkedList));
	
	return 0;
}
