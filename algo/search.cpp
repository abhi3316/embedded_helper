//============================================================================
// Name        : algorithms.cpp
// Author      : Abhi
// Version     :
// Copyright   : Your copyright notice
// Description : Algorithms in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Algorithms {
	int *arr;
public:
	Algorithms(int *ar);
	int binary_search(int sv, int count);
	int print_array(int count);
};

Algorithms::Algorithms(int *ar) {
	arr = ar;
	cout << "Assigning the array" << endl;
}

int Algorithms::print_array(int count){
	for(int i =0; i< count; i++)
		cout << "Value is " << arr[i] << endl;
	return 0;
}

int Algorithms::binary_search(int sv, int count) {
	int l = 0, h = count, mid = 0;
	while(l <= h) {
		mid = (l + h)/2;
		if(sv < arr[mid])
			h = mid -1;
		else if(sv > arr[mid])
			l = mid + 1;
		else
			return true;

	}
	return false;
}
int main() {
	cout << "Binary Search to find the median of an given array" << endl;
	int arr[] = {1,2,3,4,5};
	Algorithms algo(arr);
	//algo.print_array(sizeof(arr)/sizeof(int));
	
	/* Search the value 3 */
	cout << "Program to search the value 3 in array {1,2,3,4,5} with Binary Search" << endl;
	if(algo.binary_search(3, sizeof(arr)/sizeof(int)))
		cout << "Value found in Array" << endl;
	return 0;
}

