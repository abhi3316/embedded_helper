//Hello World! -> World! Hello

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef struct stack_ds {
	char *data[SIZE];
	int top;
} stackds_t;


int push(char *value, stackds_t *stk, int len ) {
	if(stk->top == SIZE - 1 ) {
		printf("\nstack is overflow\n");
		return -1;
	}
	stk->data[++stk->top] = (char*) malloc(sizeof(char) * len +1);
	strncpy(stk->data[stk->top], value, len);
	return 0;
}

int pop (stackds_t *stk, char *s) {
	if(stk->top == -1) {
		printf("\nstack is underflow\n");
		return -1;
	}
	memcpy(s, stk->data[stk->top], strlen(stk->data[stk->top]));
	free(stk->data[stk->top]);
	stk->top--;
	return 0;
}


int init_stack(stackds_t *stack) {
	if(stack == NULL) {
		printf("stack is NULL\n");
		return -1;
	}
	stack->top = -1;
	return 0;
}

int parse_string_store(char *str, stackds_t *stack) {
	int len = strlen(str);
	int slen = 0;
	for(int i = 0, m = 0; i <= len; i++) {
		if(str[i] == ' ' || str[i] == '\0') {
			slen = i - m;
			push(&str[m], stack, slen); 
			m = i+1;
		}
	}
	return 0;
}

int main(void) {
	stackds_t my_stack = {0};
	init_stack(&my_stack);
	int res;
	char *inp = "Hello World!", ret[512];
	parse_string_store(inp, &my_stack);
	for(int i = 0; i < 10; i++) {
		res = pop(&my_stack, ret);
		if(res == -1)
			break;
		printf("%s",ret);
	}
	printf("\n");
}	
