#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>

#define SHM_KEY (0x102)

char str[1024];


int main(void) {
	char s[1024] = "shared memory example";
	int id = shmget(SHM_KEY, 1024, 0644|IPC_CREAT);
	if(id < 0) {
		printf("ID not valid for write\n");
		exit(1);
	}

	char *sw = shmat(id, NULL, 0);	
	
	if(sw == (char*)-1) {
		printf("NO MEM assigned for write\n");
		exit(1);
	}
	
	memcpy(sw, s, sizeof(s));


	int id1 = shmget(SHM_KEY, 1024, 0644|IPC_CREAT);
	if(id1 < 0) {
		printf("ID not valid for read\n");
		goto done;
	}

	char *sr = shmat(id1, NULL, 0);
	if(sr == (char *)-1) {
		printf("NO MEM assigned for read\n");
		goto done;
	}
	
	//read the value in shared memory	

	printf("str is	:=> %s\n", sr);

	shmdt(sr);
done:
	shmdt(sw);
	return 0;
}
	
	
	  
