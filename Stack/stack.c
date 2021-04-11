#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

nodeptr createNode(stackItem item){
	nodeptr p;
	p = (nodeptr)malloc(sizeof(struct node));
	p->item = item;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

Stack newStack(){
	Stack s;
	s = createNode(0);
	return s;
}

void push(Stack s, stackItem item){
	nodeptr p = createNode(item);
	p->prev = s;
	p->next = s->next;
	if( s->next!= NULL )
		s->next->prev = p;
	s->next = p;
}

void pop(Stack s){
	if( !isEmpty(s) ){
		nodeptr p = s->next;
		if( p->next != NULL)
			p->next->prev = s;
		s->next = p->next;
		free(p);
	}
	else printf("\nStack is EMPTY cannot POP");	
}

int isEmpty(Stack s){	
	return s->next==NULL;
}

void clear(Stack s){
	while(!isEmpty(s)){
		nodeptr p = s->next;		
		s->next = p->next;
		free(p);
	}
}

stackItem top(const Stack s){
	if( !isEmpty(s) ){
		return s->next->item;
	}
	else {
		printf("\nStack is EMPTY cannot see TOP");
		return -1;	
	}
}

void display(Stack s){
	if( !isEmpty(s) ){
		printf("\nElements in Stack : ");
		nodeptr p = s-> next;
		while( p->next != NULL ){
//			printf("%d ",p->item);	//TAKE THIS COMMENT OUT TO MAKE it O(n)
			p = p->next;
		}
		while( p->prev != s->prev){  	//Comment
			printf("%d ",p->item);		//this	
			p = p->prev;				//section
		}								//out to make it O(n)
	}
	else printf("\nElements in Stack : ");
}

void destroy(Stack *s){
	clear(*s);
	free(*s); // free the header
}
