#pragma once
#include <iostream>

template <typename T>
class Node  {
	public:
		T data;
		Node<T>* next;
		Node<T>* predecessor;
};

template <typename T>
class LinkedList {	
	protected: 
		Node<T>* first;
		Node<T>* last;
		int size;

	public:
		LinkedList() {
			first = nullptr;
			last = nullptr;
			size = 0;
		}

		void PushBack(T data);
		void PrintList();
		void PopBack();
		int GetSize();
		Node<T>* Search(T data);
};

template <typename T>
void printFound(Node<T>*);
