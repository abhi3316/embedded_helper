// delete a given node with value from a link list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
        int value;
        struct node *next;
}node_t;

struct node * insert_node(int val) {
        struct node *node = NULL;
        node = malloc(sizeof(struct node));
        if(node == NULL){
                printf("MEM Error\n");
                return NULL;
        }
        (node)->value = val;
        node->next = NULL;
        return node;
}


struct node * delete_element(struct node *node, int val) {
        struct node *tmp = NULL, *ref = node, *temp = NULL;
        for(;node != NULL; tmp = node, node = node->next) {
                if(node->value == val) {
                        if(node->next != NULL) {
                                temp = node->next;
                                memcpy(node, node->next, sizeof(struct node));
                                free(temp);
				break;
                        }
                        else {
                                free(tmp->next);
                                tmp->next = NULL;
				break;
                        }
                }
        }
        return ref;
}


void clean_up(struct node **root) {
        if(*root == NULL) {
                return;
        }
        clean_up(&(*root)->next);
        free(*root);
        *root = NULL;
        return;
}


int main(void) {
        struct node *root = NULL, *ref = NULL, *tmp = NULL;
        int arr[] = {2,3,4,5,7};
        for(int i = 0; i < sizeof(arr)/ sizeof(int); i++) {
                tmp = insert_node(arr[i]);
                if(root == NULL) {
                        ref = tmp;
                        root = tmp;
                        continue;
                }
                root->next = tmp;
                root = root->next;
        }
        root = ref;

	ref = delete_element(root, 7);
	root = ref;
	for(; root != NULL; root = root->next) {
		printf("value is %d\n", root->value);
	}
	root = ref;

        clean_up(&root);
	if(root != NULL) {
		printf("cleanup unsuccess\n");
		return -1;
	}
	return 0;
}
