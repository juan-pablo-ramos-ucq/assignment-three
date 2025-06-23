#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
	private:
		T* arr; 
		int size; //the number of actual defined elements by the programmer in the array.
		int capacity; // the total elements it can occupy--including default and programmer-defined ones.

		void Move(T*& source, T*& destination, int srcSize);

	public:
		DynamicArray() {
			size = 0;
			capacity = 4;
			arr = new T[capacity](); // the () are for initializing to default type values all array elements
		}

		~DynamicArray() {
			delete[] arr;
		}

		void PushBack(T pT);
		void PopBack();
		void ShrinkToFit();

		//Getters
		T* GetArray();
		int GetCapacity();
		int GetSize();
};

void Dynamic();