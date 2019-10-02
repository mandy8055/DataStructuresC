#include<stdio.h>
#include "queueimplt.h"

int main(void){
//	Program fails below
//	circularDequeue();
	
	circularEnqueue(1);
    circularEnqueue(2);
    circularEnqueue(3);
    circularEnqueue(4);
    circularEnqueue(5);
    circularEnqueue(6);
    // Fails to enqueue because front == 0 && rear == SIZE - 1
//    circularEnqueue(7);
    display();
    circularDequeue();
    
    display();
    
    circularEnqueue(7);
    display();
    
    // Fails to enqueue because front == rear + 1
//    circularEnqueue(8);
    
	return 0;
}
