#include <stdio.h>
#include <stdlib.h>


#define SIZE (100)


struct t_node {
	struct t_node *left;
	struct t_node *right;
	int value;
};	

struct queue {
	struct t_node t[SIZE];
	int front;
	int rear;
};


int init_queue(struct queue *q) {
	if(q == NULL) {
		printf("MEM error\n");
		return -1;
	}
	q->front = 0;
	q->rear = 0;
	return 0;
}

int enque(struct t_node *node, struct queue *q) {
	if(node == NULL || q->front == SIZE -1) {
		//printf("Error in enque\n");
		return -1;
	}
	q->t[q->front++] = *node;
	return 0;
}


int deque( struct t_node *node, struct queue *q) {
	if(node == NULL || q->front == q->rear) {
		printf("Error in deque\n");
		return -1;
	}
	*node = q->t[q->rear++];
	return 0;
} 	

int print_inorder_list(struct t_node *node) {
	struct queue q;
	struct t_node temp;
	init_queue(&q);
	temp = *node;
	enque(node, &q);
	//enque(node->left, &q);
	//enque(node->right, &q);
	while(deque(&temp, &q) != -1) {
		printf("value are %d\n", temp.value);
		enque((temp.left), &q);
		enque((temp.right), &q);
	} 
	return 0;
}


void clean_tree(struct t_node **root) {
	if (*root == NULL) {
		return;
	}
	clean_tree(&(*root)->left);
	clean_tree(&(*root)->right);
	free(*root);
	*root = NULL;
	return;
  
}

struct t_node * create_tree(int value) {
	struct t_node *t1 = (struct t_node *) malloc(sizeof(struct t_node));
	t1->value = value;
	t1->left = NULL;
	t1->right = NULL;
	return t1;
}


int main(void) {
	struct t_node *root = NULL;
	root = create_tree(1);
	root->left = create_tree(2);
	root->right = create_tree(3);
	root->left->left = create_tree(4);
	root->left->right = create_tree(5);
	root->right->left = create_tree(6);
	root->right->right = create_tree(7); 
	
	print_inorder_list(root);
	clean_tree(&root);
	if(root != NULL) {
		printf("Clean unsucessfull\n");
		return -1;
	}
	return 0;

}

