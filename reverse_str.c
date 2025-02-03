#include <stdio.h>
#include <string.h>

void reverse_str(char *x, int len) {
	for(int i = 0; i < (len/2); i++) {
		x[i] = x[i] + x[len - i];
		x[len - i] = x[i] - x[len - i];
		x[i] = x[i] - x[len - i];
	}
	return;
}

int main() {
	char str[25] = "Helloworld!";
	/* the declaration char *str above causes 
	 * undefined behaviour, because in this case
	 * the string is stored in the read only section
	 * of the memory and attemptin to modify this 
	 * location caused undefined behaviour. If this 
	 * has to be done with *str do malloc to *str and 
	 * use the same.
	*/
	int len = strlen(str) -1;
	reverse_str(str, len);
	printf("Reversed string is: %s\n", str);
	return 0;
}
