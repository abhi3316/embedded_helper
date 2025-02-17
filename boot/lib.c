
char x[1024];

void printfn() {

}

void printf(char *c) {
        for(int xx = 0; xx < 1024; xx++) {
                x[xx] = '\0';
        }
        for(int i = 0; c[i] != '\0'; i++) {
                x[i] = c[i];
        }
	printfn();
}

void entry() {
	printf("Helloworld Abhijith");
}
