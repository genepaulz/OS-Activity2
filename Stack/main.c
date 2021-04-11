#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack s = newStack();
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	push(s,5);
	display(s);
	printf("\nTop : %d",top(s));
	push(s,6);
	display(s);
	printf("\nTop : %d",top(s));
	pop(s);
	display(s);
	pop(s);
	display(s);
	if(isEmpty(s))
	printf("\nStack is EMPTY");
	else printf("\nStack is !EMPTY");
	clear(s);
	if(isEmpty(s))
	printf("\nStack is EMPTY");
	else printf("\nStack is !EMPTY");
	display(s);
	destroy(&s);
	return 0;
}
