#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 15
// Global Variables
int arr[SIZE];
int front = -1;
int rear = -1;
// Linear Queue operations starts here
bool isEmpty(){
  return front == -1;
}

bool isFull(){
  return (rear == SIZE - 1 && front == 0);
}

void enqueue(int el){
  if(isFull()){
    printf("Linear Queue is full cannot enqueue new element\n");
    return;
  }
  else{
    if(rear == -1)front = 0;
    rear++;
    arr[rear] = el;
  }
}

int peek(){
  if(!isEmpty())
    return arr[front];
  else{
    printf("Queue is empty. Nothing to show...\n");
    return -1;
  }
}

void dequeue(){
  if(isEmpty()){
    printf("Underflow!!! Nothing to dequeue\n");
    return;
  }
  else{
    int y;
    if(front == rear){
      y = arr[front];
      rear = front = -1;
    }else{
      y = arr[front];
      front++;
    }
    printf("Dequeued element: %d\n", y);
  }
}
// Linear Queue operations ends here.
// Circular Queue operations starts here.
bool isCircularQueueFull(){
  return (rear + 1) % SIZE == front;
}

// Circular queue empty condition same as linear queue.

void circularEnqueue(int data){
  // Base case
  if(isCircularQueueFull()){
    printf("Circular queue is full\n");
    return;
  }
  
  else if(isEmpty()){
    front = rear = 0;
  }
  
  else if(rear == SIZE - 1 && front != 0){
    rear = 0;
  }
  else{
    rear++;
  }
  arr[rear] = data;
}

void circularDequeue(){
  int temp;
  if(isEmpty()){
    printf("Nothing to delete. Queue is empty...");
    return;
  }
  temp = arr[front];
  if(rear == front){
    rear = front = -1;
  }else{
    front = (front + 1) % SIZE;
  }
  printf("Dequeued Element: %d\n", temp);
}

void displayQueue(){
  int i, j;
  if(rear < front){
    for(i = front; i < SIZE; i++){
      printf("%d ", arr[i]);
    }
    for(j = 0; j <= rear; j++){
      printf("%d ", arr[j]);
    }
  }else{
    for(i = front; i <= rear; i++){
      printf("%d ", arr[i]);
    }  
  }
  for(i = front; i <= rear; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Implementing Queue using Singly Linked List

// Creating a Node
struct node{
  int data;
  struct node* next;
};
// Initializing front and rear pointers for the node
struct Queue{
  struct node* front;
  struct node* rear;
};
// Function to create a new node with data k. Analyze carefully.
struct node* newNode(int k){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp -> data = k;
  temp -> next = NULL;
  return temp;
};
// Utility function to create a new queue. Analyze carefully. 
struct Queue* createQueue(){
  struct Queue* head = (struct Queue*) malloc(sizeof(struct Queue));
  head -> front = head -> rear = NULL;
  return head;
}

void linkListEnqueue(struct Queue* head, int k){
  struct node* q = newNode(k);
  // Base Case If the queue is initially empty and the first node is being inserted.
  if(head -> rear == NULL){
    head -> front = head -> rear = q;
    return;
  }
  head -> rear -> next = q;
  head -> rear = q;
}

void linkListDequeue(struct Queue* head){
  if(head == NULL){
    printf("Queue is empty. Nothing to delete...");
    return;
  }
  int tempData = head -> front -> data;
  struct node* s = head -> front;
  head -> front = head -> front -> next;
  if(head -> front == NULL)head -> rear = NULL;
  s = NULL;
  free(s);
  printf("Dequeued element: %d\n", tempData);
}





