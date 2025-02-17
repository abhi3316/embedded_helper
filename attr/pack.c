#include <stdio.h>

/* In the below structure without the attribute packed, the size
 * will be 12 bytes, but with the packed attribute the size changes
 * to 9 bytes 
 */  

struct MyData {
	int data;
	int val;
	char s;
}__attribute__((packed));

int main() {
	printf("Size of MyData : %ld\n", sizeof(struct MyData));
	return 0;
}
