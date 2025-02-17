#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};


#define SIZE (1024)

struct stack {
	int list[SIZE];
	int tos;
};

struct node * create_node(int val) {
	struct node *tmp = (struct node *) malloc(sizeof(struct node));
	tmp->data = val;
	tmp->next = NULL;
	return tmp;
}



int insert_stack(struct stack *s, int val) {
	if(s->tos > SIZE -1) {
		printf("Stack overflow\n");
		return -1;
	}
	s->list[++(s->tos)] = val;
	return 0;
}

int pop_stack(struct stack *s) {
	if(s->tos == -1) {
		printf("Stack underflow\n");
		return -1;
	}
	return s->list[(s->tos)--];
}

int check_stack(struct node *n, struct stack *s) {
	for(int i = s->tos; i >= 0; i--) {
		if(n->data > s->list[i]){
			pop_stack(s);
			continue;
		}
	}
	insert_stack(s, n->data); 
	return 0;
}

int fill_stack(struct node *n, struct stack *s) {
	for(; n != NULL; n = n->next) {
		check_stack(n, s);
	}
	struct node *tmp = NULL;
	return 0; 
}


struct node * sorted_node(struct node *n, struct stack *s) {
	int val;
	struct node *tmp , *temp, *ref = n;
	val = pop_stack(s);
	if(val == -1) {
		return n;
	}
	tmp = malloc(sizeof(struct node));
	tmp->next = n;
	tmp->data = val;
	temp = sorted_node(tmp, s);
	return temp;
}

void clean_up(struct node **n) {
	if((*n) == NULL) {
		return;
	}
	clean_up(&(*n)->next);
	free(*n);
	*n = NULL;
}

void print_list(struct node *x) {
	for(; x != NULL; x = x->next)
		printf("Value from list is %d\n", x->data);

}


#define L_PRINT(x) print_list(x)

int main() {
	struct stack s = {0};
	s.tos = -1;
	struct node *root = NULL, *ret = NULL, *res = NULL;

	root = create_node(5);
	root->next = create_node(2);
	root->next->next = create_node(13);
	root->next->next->next = create_node(3);
	root->next->next->next->next = create_node(8);

#if defined TEST_1
	root = create_node(1);
	root->next = create_node(1);
	root->next->next = create_node(1);
	root->next->next->next = create_node(1);
	root->next->next->next->next = create_node(1);
#endif

	fill_stack(root, &s);
	res = sorted_node(ret,&s);
	
	printf("\n\nSorted List\n\n");

	L_PRINT(res);
	return 0;

}

