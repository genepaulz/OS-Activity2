#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue q = newQueue();
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	enqueue(q,4);
	enqueue(q,5);
	display(q);
	printf("\nHead : %d",head(q));
	printf("\nTail : %d",tail(q));
	enqueue(q,6);
	display(q);
	printf("\nHead : %d",head(q));
	printf("\nTail : %d",tail(q));
	dequeue(q);
	display(q);
	if(isEmpty(q)) printf("\nQueue is EMPTY");
	else printf("\nQueue is !EMPTY");
	clear(q);
	if(isEmpty(q)) printf("\nQueue is EMPTY");
	else printf("\nQueue is !EMPTY");
	display(q);
	
	
	destroy(&q);
	return 0;
}
