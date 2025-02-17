#include <stdio.h>
#include <stdlib.h>


#define TEST_2SUM

int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

struct hash_table {
	int key;
	int value;
	int set;
};

int find_pos(struct hash_table *h, int key) {
	if(h[key].set) 
		return h[key].value;
	return -99999;
}

int check_val(struct hash_table *h, int key) {
	if(h[key].set) 
		return 1;
	return 0;
}

int insert_value(struct hash_table *h, int key, int value) {
	h[key].key = key;
	h[key].value = value;
	h[key].set = 1;
	return 0;
}

int main(void) {
	int arr[] = {2,7,11,15};
	int target = 9, pos1 = 0, pos2 = 0;


	struct hash_table *h = (struct hash_table *) malloc(sizeof(struct hash_table) * ((sizeof(arr))/ sizeof(int)));

#if defined TEST_HASH
	insert_value(h, 3, 56);
	printf("value is %d\n", find_pos(h, 3));
	free(h);
#endif

#if defined TEST_2SUM
	for(int i = 0; i< sizeof(arr)/ sizeof(int); i++) {
		if(check_val(h, (target - arr[i]))) {
			pos1 = i;
			pos2 = find_pos(h, (target - arr[i]));
			break;
		}
		else {
			insert_value(h, arr[i], i);		
		}
	}
	printf("pos1 %d, pos2 %d\n", pos1, pos2);
	free(h);
#endif
	return 0;
}		
	
