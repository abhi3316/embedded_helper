
/* count no.of 1's in the given int binary input and store the count and 
corresponding position in an array */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int main() {
    // 346; //0001,0101,1010
    int k = 5657; //0001,0110,0001,1001
    int y = k;
    int count = 0;
    int val = 0x40000000;
    int pos = 0;
    int a_val = 0, b_val = 2;
    int *x = malloc(sizeof(int) * 32);
    for(int i = 0, t = 0, d=1; i < 31; i++) {
        if(y & (val >> i)) {
            if(!t) {
                for(int q = 0; q < 8; q++) {
                    if(i >= a_val && i <= b_val) {
                        pos = i - a_val;
                        break;
                    }
                    a_val = (b_val +1); b_val +=4;
                }
                t += 1;
            }
            x[d++] = (pos + 1);  
            count ++;
        }
        if(t)
            pos++;
    }
    x[0] = count;
    for(int i =0; i <= x[0]; i++) {
        printf("%d\n", x[i]);
    }
    return 0;
