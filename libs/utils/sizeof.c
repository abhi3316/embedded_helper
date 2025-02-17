#include <stdio.h>


#define fsize(x) \
	((ssize_t)(&x+1) - (ssize_t)&x)


int main(void) {
	int x, y[3] = {0};
	printf("%ld %ld\n", fsize(x), fsize(y));

	/* array size method 2 */
	int (*z)[3] = &y;
	printf("%ld\n", (size_t)(z +1) - (size_t)(z));
	return 0;
}
