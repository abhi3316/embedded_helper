//Leet : 53
#include <stdio.h>


int main(void) {
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int arrSize = sizeof(arr)/ sizeof(int);
	int sum = arr[0], t_sum = arr[0], p1 = 0, p2 = 0;
	for(int i = 1; i< arrSize; i++) {
		if(t_sum + arr[i] > arr[i]) {
			p2++;
			t_sum += arr[i];
		}
		else {
			t_sum = arr[i];
			p1 = i;
		}
		sum = sum > t_sum ? sum : t_sum;
	}
	printf("The Sum is %d, pos is %d , %d\n", sum, p1, p2);
}			
