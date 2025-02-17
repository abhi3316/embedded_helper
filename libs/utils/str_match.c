#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


bool check_match(char *s, char *ch) {
	int len = strlen(s);
	int len2 = strlen(ch);
	int to_iter = (len - len2);
	for(int i = 0; i <= to_iter; i++) {
		if(!strncmp((s + i), ch, len2)) {
			return true;
		}
	}
	return false;
}

int main() {
	char s[100] = "Helloworld!";
	if(check_match(s, "world"))
		printf("Match is Found!\n");
	return 0;
}
