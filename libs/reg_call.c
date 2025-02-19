/* The layer to register all the calls available in the 
* module */
#include <app.h>
#include <utils.h>
#include <eng.h>
	

void (*eh_reg[MAX_SIZE])(void *);
		
struct eh_engine eh_eng;

int register_utils(struct utils *ut) {
	if(!ut) {
		printf("no utils provided\n");
		return -1;
	}
	if(eh_eng.count > MAX_SIZE -1) {
		printf("Engine overflow");
	}
	memcpy(&eh_eng.util[eh_eng.count++], ut, sizeof(struct utils));
	return 0;
}

void init_engine(void) {
	eh_reg[0] = endianchk;
	for(int i = 0; i < MAX_SIZE; i++) {
		if(!eh_reg[i])
			return;
		else
			(void)eh_reg[i](NULL);
	}
	return;
}

void engine_cap(void) {
	printf("LIB Capabilities()\n");
	int x = 0;
	for(int i = 0; i < eh_eng.count; i++) 
		printf("%d : %s\n",i , eh_eng.util[i].name); 

	printf("Inp:");
	scanf("%d", &x);
	if(!eh_reg[x]) {
		printf("Invalid Input\n");
		return;
	}
	eh_eng.util[x].util_func(NULL); 
}
