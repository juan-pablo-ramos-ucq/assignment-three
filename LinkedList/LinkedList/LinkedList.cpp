#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
	LinkedList<int> linkedListOne;
	linkedListOne.PushBack(10);
	linkedListOne.PushBack(5);
	linkedListOne.PushBack(3);
	linkedListOne.PushBack(7);
	linkedListOne.PushBack(6);
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;

	linkedListOne.PopBack();
	linkedListOne.PrintList();
	cout << "Size: " << linkedListOne.GetSize() << endl;
}

template <typename T>
void LinkedList<T>::PushBack(T data) {
	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	if (first == nullptr) {
		first = newNode;
		first->next = nullptr;
		last = first;
		first->predecessor = nullptr;
	} else {
		last->next = newNode;
		newNode->next = nullptr;
		newNode->predecessor = last;
		last = newNode;
	}
	size++;
}

template <typename T>
void LinkedList<T>::PrintList() {	
	cout << "{";
	Node<T>* iterator = first;
	if (iterator == nullptr) {
		cout << "}" << endl;
		return;
	}
	while (iterator -> next != nullptr) {
		cout << iterator->data << ", ";
		iterator = iterator->next;
	}
	cout << iterator->data << "}" << endl;
}

template <typename T>
void LinkedList<T>::PopBack() {
	if (first == nullptr || last == nullptr) {
		cout << "No hay elementos que eliminar" << endl;
		return;
	}

	if (last -> predecessor != nullptr) {
		Node<T>* copyLast = last;
		last = copyLast->predecessor;
		delete copyLast;
		copyLast = nullptr;
		last->next = nullptr;
		size--;
	} else {
		cout << "------------------------------------------------------------" << endl;
		cout << "Proof last and first point to the same memory address:" << endl;
		cout << "last: "  << last << endl;
		cout << "first: " << first << endl;
		cout << "------------------------------------------------------------" << endl;

		delete first;
		first = nullptr; 
		last = nullptr; //placing null to also last. Because we eliminated first, last will point to an invalid address
		size--;
	}
}

template <typename T>
int LinkedList<T>::GetSize() {
	return size;
}





