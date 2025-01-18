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
	int val = 4; //max 10 bit
	int rem = val;
	while (val > 0) {
		push(val%2, &my_stack);
		val /= 2;
	}
	while(my_stack.top != -1) {
		printf("%d", pop(&my_stack));
	}
	printf("\n");	
	return 0;
}	
