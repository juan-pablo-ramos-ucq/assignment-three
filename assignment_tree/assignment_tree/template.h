#pragma once
#include <iostream>
using namespace std;

template <typename T>
void PrintArray(T arr[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			cout << arr[i] << ", ";
		}
		else {
			cout << arr[i] << "]" << endl;
		}
	}
}
