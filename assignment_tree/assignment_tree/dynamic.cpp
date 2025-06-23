#include "dynamic.h"
#include "template.h"

#define MOVES 1

#if MOVES 1
int moveCount = 0; //global variable for counting the moves done by Move()
#endif

//Main program of dynamic Array 
void Dynamic() {
	DynamicArray<int>* arrOne = new DynamicArray<int>();
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(1);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(4);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(9);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(14);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(7);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(9);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(3);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(10);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(24);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	cout << "Last element: " << arrOne->GetArray()[8] << endl;

	arrOne->PopBack();
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PopBack();
	arrOne->PopBack();
	arrOne->PopBack();
	arrOne->PopBack();
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->ShrinkToFit();
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PopBack();
	arrOne->PopBack();
	arrOne->PopBack();
	arrOne->PopBack();
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PopBack();
	arrOne->PopBack();
	arrOne->PopBack();
	arrOne->PopBack();

	arrOne->PushBack(1);
	arrOne->PushBack(4);
	arrOne->PushBack(9);
	arrOne->PushBack(14);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(7);
	arrOne->PushBack(4);
	arrOne->PushBack(9);
	arrOne->PushBack(14);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->PushBack(7);
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	arrOne->ShrinkToFit();
	PrintArray(arrOne->GetArray(), arrOne->GetCapacity());

	DynamicArray<string>* arrTwo = new DynamicArray<string>();
	arrTwo->PushBack("Hello");
	PrintArray(arrTwo->GetArray(), arrTwo->GetCapacity());
	
	arrTwo->PopBack();
	PrintArray(arrTwo->GetArray(), arrTwo->GetCapacity());

	arrTwo->PopBack();

	DynamicArray<bool>* arrThree = new DynamicArray<bool>();
	PrintArray(arrThree->GetArray(), arrThree->GetCapacity());

	DynamicArray<char>* arrFour = new DynamicArray<char>();;
	PrintArray(arrFour->GetArray(), arrFour->GetCapacity());

	#if MOVES 1
	cout << "Total moves done by the Move() method throughout the program: " << moveCount << endl;
	#endif

	delete arrOne;
	delete arrTwo;
	delete arrThree;
	delete arrFour;
}

//definition of major methods of DynamicArray class
template <typename T>
void DynamicArray<T>::Move(T*& source, T*& destination, int srcSize) {
	//srcSize es el tamano de source
	//source es que vas a mover. Destination es hacia donde vas a mover
	for (int i = 0; i < srcSize; i++) {
		//we are only interested in traversing completely the source
		destination[i] = source[i]; //copy every element of source to destination at the same position
		//because of srcSize, the default values of destination that overflow source are left intact.
		#if MOVES 1
				moveCount++;
		#endif
	}
	delete arr; // free memory location not longer used
	arr = destination; // assign pointer arr to the new size memory location of destination
}

template <typename T>
void DynamicArray<T>::PushBack(T pT) {
	if (size >= capacity) {
		capacity *= 2;
		T* doubArr = new T[capacity](); // creating a new default array pointer with double capacity
		Move(arr, doubArr, capacity / 2 /*the original capacity of arr*/);
	}
	arr[size] = pT; /*we leverage size as current index since incrementing it comes afterwards.
	Current index is the next available spot to push back. This statement works for any case.*/
	size += 1;
}

template <typename T>
void DynamicArray<T>::PopBack() {
	if (size == 0) {
		cout << "Invalid operation. The array is \"empty.\" " << endl;
		return;
	}

	size -= 1;
	arr[size] = T{}; // T{} means gracefully assigning the corresponding default value for any type T
}

template <typename T>
void DynamicArray<T>::ShrinkToFit() {
	T* doubArr = new T[size]; //a new array sized exactly to fit the used elements
	Move(arr, doubArr, size); /*moving programmer-defined elements to doubArr.
	The default-valued elements of arr will be dismissed.*/
	capacity = size; //now capacity and size are the same.
}

//getter definitions of DynamicArray class
template <typename T>
T* DynamicArray<T>::GetArray() {
	return arr;
}

template <typename T>
int DynamicArray<T>::GetCapacity() {
	return capacity;
}

template <typename T>
int DynamicArray<T>::GetSize() {
	return size;
}
