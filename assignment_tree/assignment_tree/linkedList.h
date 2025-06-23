#pragma once
#include <iostream>

template <typename T>
class Node {
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

		~LinkedList() {
			Node<T>* iterator = first;
			if (iterator == nullptr)
				return;

			Node<T>* aux = nullptr;
			while (iterator != nullptr) {
				aux = iterator->next; //necesitamos un auxiliar ya que el iterador se elimina y no hay manera de accesar al siguiente si no fuera por el auxilar
				delete iterator;
				iterator = aux;
			}
		}

		void PushBack(T data);
		void PrintList();
		void PopBack();
		int GetSize();
		Node<T>* Search(T data);
		void PopFront();
		void PushFront(T data);
};

template <typename T>
void printFound(Node<T>*);

void Linked();