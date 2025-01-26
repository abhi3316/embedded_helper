#include <stdio.h>

//Lsb in lower addr => little endian
int main(void) {
	int x = 0x1234;
	char *t = (char*)&x;
	if(*t == 0x34) {
		puts("Little Endian");
	}
	else
		puts("Big Endian");
	return 0;
}

