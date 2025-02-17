//Leet_11

#include <stdio.h>


int main(void) {
	int height[] = {1,8,6,2,5,4,8,3,7};
	int heightSize = sizeof(height) / sizeof(int);
	int max_index = heightSize - 1;
        int min_index = 0;

        int width = 0, h = 0, a = 0, p1 = 0, p2 = 0;

        while(min_index != max_index) {
                h = (height[min_index] < height[max_index]) ? height[min_index] : height[max_index];
                width = max_index - min_index;
                if((h * width) > a) {
                        a = h * width;
                        p1 = min_index;
                        p2 = max_index;
                }
                if(height[min_index] < height[max_index]) {
                        min_index++;
                }
                else {
                        max_index--;
                }
        }
        printf("Area is %d , positions: %d, %d\n", a, ++p1, ++p2);
    return a;
}
