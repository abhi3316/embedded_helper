
// convert binary to octal string;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE (3)

int main() {
	char *x = "11001111";
	int len = strlen(x);
	int fill =  (len % BASE) ? BASE - (strlen(x) % BASE): 0;
	char *y = (char *) malloc(sizeof(char) * (len + fill));
	char *z = (char *) malloc(sizeof(char) * (len + fill)/3);
	char *t = z, *q = y;
	for(int i = 0; i < fill; i++){
		y[i] = '0';
	}
	strncpy((y+fill), x, strlen(x));
	for(int temp = 0; temp < (fill + len)/BASE  ; temp++) {
		if(!strncmp("000", y, BASE)) {
			printf("match for 0\n");
			*z = '0';
		}
		if(!strncmp("001", y, BASE)) {
			printf("match for 1\n");
			*z = '1';
		}
		if(!strncmp("010", y, BASE)) {
			printf("match for 2\n");
			*z = '2';
		}
		if(!strncmp("011", y, BASE)) {
			printf("match for 3\n");
			*z = '3';
		}
		if(!strncmp("100", y, BASE)) {
			printf("match for 4\n");
			*z = '4';
		}
		if(!strncmp("101", y, BASE)) {
			printf("match for 5\n");
			*z = '5';
		}
		if(!strncmp("110", y, BASE)) {
			printf("match for 6\n");
			*z = '6';
		}
		if(!strncmp("111", y, BASE)) {
			printf("match for 7\n");
			*z = '7';
		}
		y = y + BASE;
		z++;        
	}
	printf("oct_val is str:%s =>  %d\n", t, atoi(t));
	free(q);
	free(t);
	return 0;
}
