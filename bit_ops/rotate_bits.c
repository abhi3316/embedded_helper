#include <stdio.h>

#define BIT_LEN (8)

int main(void) {
	unsigned int x = 0x28; //rotation is 0x14	
	for(int i = 0; i< (BIT_LEN/2); i++) {
		if(!(x & (1 << i)) && (x &(1 << ((BIT_LEN -1) - i)))) {
			x |= (1 << i);
			x &= ~(1 << ((BIT_LEN -1) -i));
			continue;	
		}
		if((x & (1 << i)) && !(x &(1 << ((BIT_LEN -1) - i)))){
			x &= ~(1 << i);
			x |= (1 << ((BIT_LEN - 1) - i));
			continue;
		}
			
	}
	printf("x is %x\n", x);
	return 0;
}
