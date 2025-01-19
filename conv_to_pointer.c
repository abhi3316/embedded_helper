//convert pass by value to pass by reference

#include <stdio.h>

void change_var(int *x);

#define change(x) \
    (change_var(&x)) \
    

void change_var(int *x) {
    *x = *x+6;
}

int main() {
    // Write C code here
    //printf("Try programiz.pro");
    int x = 10;
    change(x);
    printf("x is %d\n", x);
    return 0;
}
