#include<stdio.h>
// Creating a Node data type
struct node{
	int data;
	struct node* next;
};

struct node first = {10, NULL};
struct node second = {20, NULL};
struct node third = {30, NULL};
struct node fourth = {40, NULL};
struct node fifth = {50, NULL};



struct node* returnLL(){	
	
	//	Linking the nodes
	first.next = &second;
	second.next = &third;
	third.next = &fourth;
	fourth.next = &fifth;
	
	struct node* linkedList = &first;
	
	return linkedList;
}
