
/* reverse the list
* 1->2->3->4->5
* 5->4->3->2->1
*/
 
#include <stdio.h>
#include <stdlib.h>

struct node;
void print_list(struct node *x);



#define LLIST(x) \
	print_list(x);


struct node {
	int val;
	struct node *next;
};



void print_list(struct node *x) {
	for(; x != NULL; x = x->next) { 
		printf("value is %d\n", x->val); 
	}
	return;
}

struct node * create_node(int value) {
	struct node *tmp = (struct node *) malloc(sizeof(struct node ));
	tmp->val = value;
	tmp->next = NULL;
	return tmp;
}

struct node * rev_list(struct node *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	struct node *tmp = rev_list(head->next);
	head->next->next = head;
	head->next = NULL;
	return tmp;
}

void clean_up(struct node ** root) {
	if(*root == NULL)
		return;
	clean_up(&(*root)->next);
	free(*root);
	*root = NULL;
}

int main(void) {
	struct node *root = NULL, *ref = NULL;
	for(int i = 0; i< 100; i++) {
		if(root == NULL) {
			root = create_node(i);
			ref = root;
			continue;
		}
		root->next = create_node(i);
        	root = root->next;
    	}
	root = ref;
	root = rev_list(ref);
	LLIST(root);
	clean_up(&root);
	if(root != NULL) {
		printf("clean-up unsuccessful\n");
	}

	printf("Clean-up done\n");
	return 0;
}
