#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue newQueue(){
    Queue q = (Queue)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue q,qItem item){
    nodeptr temp = (nodeptr)malloc(sizeof(struct queue));
    temp->item = item;
    temp->next = NULL;

    if( q->rear != NULL )
        q->rear->next = temp;    
    else
        q->front = temp;    
    q->rear = temp;
}

void dequeue(Queue q){
    nodeptr p = q->front;
    if( p != NULL){
        q->front = p->next;
        free(p);
        if( q->front == NULL)
            q->rear = NULL;
    }
}

int isEmpty(Queue q){
    return q->front == NULL;
}

void clear(Queue q){
    while( !isEmpty(q) ){
        dequeue(q);
    }
}

qItem head(Queue q){
	if( !isEmpty(q) )
    	return q->front->item;
    else {
    	printf("\nQueue is EMPTY cannot ACQUIRE HEAD");
    	return -1;
	}
}

qItem tail(Queue q){
	if( !isEmpty(q) )
    	return q->rear->item;
    else {
    	printf("\nQueue is EMPTY cannot ACQUIRE TAIL");
    	return -1;
	}
}

void display(Queue q){
    if(!isEmpty(q)){
        printf("\nElements in Queue : ");
        nodeptr p = q->front;
        while( p != NULL ){
            printf("%d ",p->item);
            p = p->next;
        }
    }
    else printf("\nElements in Queue : ");
}

void destroy(Queue *q){
	clear(*q);
	free(*q);
	*q=NULL;
}
