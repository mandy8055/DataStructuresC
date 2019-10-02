#include<stdio.h>
#include "queueimplt.h"

int main(void){
//	enqueue(20);
//	enqueue(10);
	enqueue(13);
	enqueue(200);
	enqueue(203);
//	enqueue(109);
	printf("The element deleted from queue is %d\n", dequeue());
	printf("The element deleted from queue is %d\n", dequeue());
	printf("The element deleted from queue is %d\n", dequeue());
//	printf("The element deleted from queue is %d\n", dequeue());		
//	enqueue(105);
	return 0;
}
