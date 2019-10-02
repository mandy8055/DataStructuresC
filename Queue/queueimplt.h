#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

// Global Variables
int front = -1, rear = -1;
int arr[SIZE];


// Enqueue Method for Linear Queue implemented here
void enqueue(int x){
//	Base Case
	if((rear + 1) == SIZE)
//		Queue overflow condition
		exit(1);
	else{
		if(rear == -1)
			front = 0;
		rear++;
		arr[rear] = x;
	}
}

// Dequeue method for Linear Queue implemented here
int dequeue(){
	int y;
//	Base Case
	if(front == -1){
//		Queue underflow condition
		exit(1);
	}
	else{
		y = arr[front];
		if(front == rear){
			front = rear = -1;
		}else{
			front += 1;
		}
		
	}
	return y;
}


