
//n1: 1->4->5
//n2: 2->3->5

//out: 1->2->2->4->5->5
//Example to merge from 0..99
#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

#define LLTEST(x) \
	for(; x != NULL; x = x->next) \
		printf("Value is : %d\n", x->value);


struct node *create_node(int value) {
	struct node *temp = NULL;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = value;
	temp->next = NULL;
	return temp;
}


void clean_up(struct node **node) {
	if(*node == NULL) {
		return;
	}
	clean_up(&(*node)->next);
	free(*node);
	*node = NULL;
	return;
}

struct node * sort_list(struct node *n1, struct node *n2) {

	if(n1 == NULL) {
		return n2;
	}
	else if(n2 == NULL) {
		return n1;
	}

	if(n1->value < n2->value) {
		n1->next = sort_list(n1->next, n2);
		return n1;
	}
	n2->next = sort_list(n2->next, n1);
	return n2; 
}


int main(void) {
	
	struct node *root = NULL, *ref = NULL, *n1 = NULL, *n2 = NULL;

	for(int i =1; i< 100; i = i +2) {
		if(n1 == NULL) {
			n1 = create_node(i);
			ref = n1;
			continue;
		}
		n1->next = create_node(i);
		n1 = n1->next;
	}

	n1 = ref;
	
	for(int i = 0; i< 100; i = i +2) {
		if(n2 == NULL) {
			n2 = create_node(i);
			ref = n2;
			continue;
		}
		n2->next = create_node(i);
		n2 = n2->next;
	}
	
	n2 =ref;

	//LLTEST(n1);
	//LLTEST(n2);

#if defined TEST
	n1 = create_node(1);
	n1->next = create_node(2);
	n1->next->next = create_node(5);
	n2 = create_node(2);
	n2->next = create_node(3);
	n2->next->next = create_node(5);
	
#endif
	root = sort_list(n1, n2);
	ref = root;

	LLTEST(ref);	
	
	clean_up(&root);
	
	if(root != NULL) {
		printf("Clean up Unsuccessful\n");
	}
	printf("Clean up successful\n");
	return 0;
		
}	
