
void printf(char *c);

void my_entry() {
	printf("Helloworld Binary");
}

void check_endianness() {
	//printf("Helloworld Abhi");
	int x = 0x1234;
        char *t = (char*)&x;
        if(*t == 0x34)
                printf("Endianness of the system is : Little Endian\n");
        else
                printf("Endianness of the system is : Big Endian\n");
       
}
	
