//missing number by binary search algorithm

#include <iostream>

using namespace std;

class Algo {
	int *arr;
public:
	Algo(int *ar);
	int missing_number(int count);
};

Algo::Algo(int *ar) {
	arr = ar;
	cout << "Array Loaded" << endl;
}

int Algo::missing_number(int count) {
	int l = 0, h = count -1, mid = 0;
	while(h - l > 1){
		mid = (l + h)/2;
		if((arr[l] - l) != (arr[mid] - mid))
			h = mid;
		else
			l = mid;		
	}
	return arr[l] + 1;
}

int main(void) {
	int arr[] = {1,2,3,4,6}; // 3 is the missing number;
	Algo a(arr);
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "The Missing Number is: " << a.missing_number(size) << endl;
	return 0;
}

