#ifndef STACK_H
#define STACK_H

typedef char stackItem;
typedef struct node *nodeptr;
struct node{
	stackItem item;
	nodeptr prev;
	nodeptr next;
};
typedef nodeptr Stack;

Stack newStack();
void push(Stack s, stackItem item);
void pop(Stack s);
int isEmpty(Stack s); 
void clear(Stack s); 
stackItem top(const Stack s); //Peek
void display(Stack s); //O(2n) kay ang naa sa PDF naka arrange first to last pushed :)
void destroy(Stack *s);

#endif
