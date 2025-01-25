//Leet 24:
//1->2->3->4;
//2->1->4->3

#include <stdio.h>
#include <stdlib.h>


struct node;

#define LLIST(x) \
	for(; x!= NULL; x = x->next) \
		printf("val is %d\n", x->val);


typedef struct node {
	int val;
	struct node *next;
}node_t;


struct node * create_node(int value) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL) {
		printf("Mem Error\n");
	}
	temp->val = value;
	temp->next = NULL;
	return temp;
}

struct node *swap_node(struct node *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	struct node *tmp = swap_node(head->next->next);
	struct node *tmp1 = head->next;
	tmp1->next = head;
	head->next = tmp;
	return tmp1;
}

void clean_up(struct node **n) {
	if(*n == NULL)
		return;
	clean_up(&(*n)->next);
	free(*n);
	*n = NULL;
	return;
}	

int main(void) {
	node_t *n = NULL, *ref = NULL;
	for(int i =0; i< 4; i++) {
		if(n == NULL) {
			n = create_node(i);
			ref = n;
			continue;
		}
		n->next = create_node(i);
		n = n->next;
	}
	n = ref;
	n = swap_node(n);
	LLIST(n);
	clean_up(&ref);
	return 0;

}

		
