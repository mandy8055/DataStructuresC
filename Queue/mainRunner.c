#include<stdio.h>
#include "queueimplt.h"

int main(void) {
  /* Testing linear queue operations starts here.
  printf("%d\n", peek());
  enqueue(45);
  printf("%d\n", peek());
  enqueue(32);
  enqueue(67);
  dequeue();
  printf("%d\n", peek());
  enqueue(91);
  enqueue(20);
  enqueue(24);
  dequeue();
  dequeue();
  printf("%d\n", peek());
  Testing linear queue operations ends here.*/
/* Testing circular queue operations starts here.
  printf("%d\n", peek());
  circularEnqueue(45);
  printf("%d\n", peek());
  circularEnqueue(32);
  circularEnqueue(67);
  circularDequeue();
  printf("%d\n", peek());
  circularEnqueue(91);
  circularEnqueue(20);
  circularEnqueue(24);
  circularDequeue();
  circularDequeue();
  
  circularEnqueue(49);
  circularEnqueue(62);
  circularEnqueue(23);

  displayQueue();

  printf("%d\n", peek());
  // circularEnqueue(23);
  Testing circular queue ends here.*/
  struct Queue* head = createQueue();

  // linkListDequeue(head);
  linkListEnqueue(head, 45);
  linkListEnqueue(head, 32);
  linkListEnqueue(head, 67);
  linkListEnqueue(head, 91);
  linkListDequeue(head);
  linkListEnqueue(head, 49);
  printf("Queue Front: %d\n", head -> front -> data);
  printf("Queue Rear: %d\n", head -> rear -> data);

  return 0;
}

