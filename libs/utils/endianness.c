#if defined __EH_APP__
#include <app.h>
#include <utils.h>
#else
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#endif

//Lsb in lower addr => little endian

#if defined __EH_APP__
char * check_endian(void) {
#else
int main(void) {
#endif
	int x = 0x1234;
	char *t = (char*)&x;
	char *ret = malloc(sizeof(char) * 20);
	if(*t == 0x34) 
		strcpy(ret, "Little Endian");
	else
		strcpy(ret, "Big Endian");
#if defined __EH_APP__
	return ret;
#else
	printf("Endianess : %s\n", ret);
	return 0;
#endif

}

#if defined __EH_APP__
void assign_call(void *arg) {
	/*assign the cb function here */
	printf("Checking the endianess of the system\n");
	char *endi = check_endian();
	printf("Endianess is : %s\n", endi); 
	free(endi);
	return ;
}

struct utils endian = {
	.util_func = assign_call,
	.name = "check endianness"
};

void endianchk(void *arg) {
	register_utils(&endian);
}

#endif
