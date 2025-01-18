#include <stdio.h>

#define SIZE 10

typedef struct stack {
	int data[SIZE];
	int top;
} stack_t;


int push(int value, stack_t *stk ) {
	if(stk->top == SIZE -1 ) {
		printf("stack is overflow\n");
		return -1;
	}
	stk->data[++stk->top] = value;
	return 0;
}

int pop (stack_t *stk) {
	if(stk->top == -1) {
		printf("stack is underflow\n");
		return -2;
	}
	return stk->data[stk->top--];
}

int init_stack(stack_t *stack) {
	if(stack == NULL) {
		printf("stack is NULL\n");
		return -1;
	}
	stack->top = -1;
	return 0;
}

int main(void) {
	stack_t my_stack = {0};
	init_stack(&my_stack);
	for(int i = 0 ; i < 10; i++) { 
		push(i, &my_stack);
	}
	for(int i = 0; i < 10; i++) {
		printf("%d\n", pop( &my_stack));
	}
}	
