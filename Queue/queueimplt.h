#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

// Global Variables
int front = -1, rear = -1;
int arr[SIZE];

// Is Full Method implemented here
int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}
// Is Empty method implemented here
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}

// Enqueue Method for Linear Queue implemented here
void enqueue(int x){
//	Base Case
	if(isFull())
//		Queue overflow condition
		printf("\n Queue is full!! \n");
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
	if(isEmpty()){
//		Queue underflow condition
		printf("\n Queue is empty !! \n");
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

// Circular Enqueue Implementation here
void circularEnqueue(int x){
	if(isFull()){
		printf("\n Queue Full. Insertion impossible!! \n");
		return;
	}else{
		if(rear == -1){
			front = rear = 0;
			arr[rear] = x;
		}else{
			rear = (rear + 1) % SIZE;
			arr[rear] = x;
		}
	}
}

// Circular Dequeue Implementation here
int circularDequeue(){
	int y;
//	Base case
	if(isEmpty()){
		printf("\n Queue is empty. Deletion Impossible!! \n");
		return -1;
	}
	else{
		y = arr[front];
		if(front == rear){
			front = rear = -1;
		}else{
			front = (front + 1) % SIZE;
		}
	}
	return y;
}

// Display Elements of the queue
void display(){
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i !=rear; i=(i+1)%SIZE) {
            printf("%d ",arr[i]);
        }
        printf("%d ",arr[i]);
        printf("\n Rear -> %d \n",rear);
    }
}






