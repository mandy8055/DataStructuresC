#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5
int arr[SIZE];
int top = -1;
// Implementing stack using Arrays
void push(int data);
int pop();
int peek();
bool isEmpty();

bool isEmpty(){
  return top == -1;
}

void push(int data){
  if(top == SIZE - 1){
    printf("Stack Overflow: Stack is full");
    return;
  }
  arr[++top] = data;
}

int pop(){
  if(isEmpty()){
    printf("Stack is empty. Nothing to pop...");
    return top;
  }
  return arr[top--];
}
int peek(){
  if(isEmpty()){
    printf("Stack is empty. Nothing to pop...");
    return -1;
  }
  return arr[top];
}
