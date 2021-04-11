#ifndef QUEUE_H
#define QUEUE_H

typedef int qItem;

typedef struct node *nodeptr;
struct node{
	qItem item;
	nodeptr next;
};

struct queue{
	nodeptr front;
	nodeptr rear;
};

typedef struct queue *Queue;

Queue newQueue();
void enqueue(Queue q,qItem item);
void dequeue(Queue q);
int isEmpty(Queue q);
void clear(Queue q);
qItem head(Queue q);
qItem tail(Queue q);
void display(Queue q);
void destroy(Queue *q);

#endif
