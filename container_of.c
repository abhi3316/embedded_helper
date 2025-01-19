#include <stdio.h>


struct my_data {
	int dat1;
	int dat2;
	int dat3;
};

#define container_of(x,y,z) \
	(x *)((size_t)&y - (size_t)&((x*)0)->z)

int main(void) {
	struct my_data d = {0}, *t = NULL;
	d.dat1 = 23;
	d.dat3 = 34;
	d.dat2 = 98;
	t = container_of(struct my_data, d.dat3, dat3);
	printf("dat1 %d & dat2 %d\n", t->dat1, t->dat2);
	return 0;
}

	
	
