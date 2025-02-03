#include <stdio.h>

int main() {
    //reverse a number;
    int check = 46789, rnum = 0; //op -> 98764
    for(; check > 0; check /= 10) {
        rnum = (rnum * 10) + (check % 10);
    }
    printf("num is %d\n", rnum);
    return 0;
}
