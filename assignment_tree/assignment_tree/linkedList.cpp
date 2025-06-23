#include "linkedList.h"
#include <iostream>
#include <string>
using namespace std;

void Linked() {
	LinkedList<int>* linkedListOne = new LinkedList<int>();
	linkedListOne->PushBack(10);
	linkedListOne->PushBack(5);
	linkedListOne->PushBack(3);
	linkedListOne->PushBack(7);
	linkedListOne->PushBack(6);
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	//buscando un elmento que si esta en la lista e imprimiendolo con formato
	Node<int>* nodeFound = linkedListOne->Search(6);
	printFound(nodeFound);

	//eliminando elementos prexistentes
	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	//tratando de eliminar elementos aunque la lista este vacia para probar validacion
	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	linkedListOne->PopBack();
	linkedListOne->PrintList();
	cout << "Size: " << linkedListOne->GetSize() << endl;

	//buscando un elemento que no exsite en la lista para checar validacion
	Node<int>* nodeFTwo = linkedListOne->Search(8);
	printFound(nodeFTwo);

	//reingresando los elementos eliminados
	linkedListOne->PushBack(10);
	linkedListOne->PushBack(5);
	linkedListOne->PushBack(3);
	linkedListOne->PushBack(7);
	linkedListOne->PushBack(6);
	linkedListOne->PrintList();

	//probando e eliminando con PopFront() todos los elementos de la lista
	linkedListOne->PopFront();
	linkedListOne->PrintList();

	linkedListOne->PopFront();
	linkedListOne->PrintList();

	linkedListOne->PopFront();
	linkedListOne->PrintList();

	linkedListOne->PopFront();
	linkedListOne->PrintList();

	linkedListOne->PopFront();
	linkedListOne->PrintList();

	//probando validacion de PopFront() cuando no hay elementos en la lista
	linkedListOne->PopFront();
	linkedListOne->PrintList();

	//probando PushFront()
	linkedListOne->PushFront(10);
	linkedListOne->PrintList();

	linkedListOne->PushFront(5);
	linkedListOne->PrintList();


	linkedListOne->PushFront(2);
	linkedListOne->PrintList();

	//probando PushBack()
	linkedListOne->PushBack(8);
	linkedListOne->PrintList();

	linkedListOne->PushBack(4);
	linkedListOne->PrintList();

	//probando PushFront()
	linkedListOne->PushFront(27);
	linkedListOne->PrintList();

	//probando PopFront()
	linkedListOne->PopFront();
	linkedListOne->PrintList();

	//probando PopBack()
	linkedListOne->PopBack();
	linkedListOne->PrintList();

	//eliminando todos los elementos con PopFront()
	linkedListOne->PopFront();
	linkedListOne->PopFront();
	linkedListOne->PopFront();
	linkedListOne->PopFront();
	linkedListOne->PrintList();

	//PushBack() y PushFront() test
	linkedListOne->PushBack(4);
	linkedListOne->PushFront(10);
	linkedListOne->PushBack(7);
	linkedListOne->PushFront(3);
	linkedListOne->PrintList();

	//liberando la memoria del objeto linkedListOne mediante su destructor
	delete linkedListOne;
}

//definiciones de los metodos de la clase LinkedList
template <typename T>
void LinkedList<T>::PushBack(T data) {
	size++; //se aumenta el tamano de la lista cada vez que se invoca PushBack ya que siempre PushBack() toma efecto
	Node<T>* newNode = new Node<T>(); //creando un nuevo nodo de tipo T
	newNode->data = data;

	if (first == nullptr) /*si la lista esta vacia*/ {
		first = newNode; //primer nodo de la lista es el nuevo nodo

		/*como es el unico nodo, es el primero y ultimo elemento
		y su siguiente nodo es nullptr*/
		first->next = nullptr;
		last = first;

		first->predecessor = nullptr; //no tiene nodo anterior por ser primero
		return;
	}
	//si la lista no esta vacia, si o si se ejecuta el snippet de abajo:
	last->next = newNode; //el ultimo nodo apunta al nuevo nodo
	newNode->next = nullptr; // el nuevo nodo apunta a vacio ya que va a ser el ultimo
	newNode->predecessor = last; //el nodo anterior a newNode va ser el que ya no va a ser ultimo
	last = newNode; // el nuevo ultimo es newNode
}

template <typename T>
void LinkedList<T>::PrintList() {
	cout << "{"; // si o si, siempre se imprimira la apertura de la lista
	Node<T>* iterator = first; //ocupamos un iterator para transverse la lista
	if (iterator == nullptr) /*si lista esta vacia*/ {
		cout << "}" << endl; // cerrar inmediatamente la lista y no imprimir ningun elemento
		return; //para salida forzosa de la funcion
	}
	//codigo inferior se ejecuta si la lista no esta vacia:
	while (iterator->next != nullptr) /*si no es el ultimo elemento*/ {
		cout << iterator->data << ", "; // imprimir el dato del nodo actual con coma para separar si contiguo siguiente
		iterator = iterator->next;
	}
	//forzosamente despues del while, el iterador es el ultimo elemento:
	cout << iterator->data << "}" << endl; //imprimir el dato del ultimo elemento y cerrar la lista
}

template <typename T>
void LinkedList<T>::PopBack() {
	//validacion:
	if (first == nullptr) /*si la lista esta vacia*/ {
		cout << "No hay elementos que eliminar" << endl;
		return; //salida forzosa de la funcion
	}

	if (last->predecessor != nullptr) /*si la lista no tiene un solo elemento*/ {
		Node<T>* copyLast = last; //copyLast es un apuntador auxilar para actualizar quien es el ultimo
		last = copyLast->predecessor; //el nuevo ultimo es el penultimo
		delete copyLast; //eliminamos el que era anteriormente el ultimo 
		last->next = nullptr; //el siguiente nodo del nuevo ultimo nodo es nada
		size--; //reducir la cuenta del tamano de la lista ligada una unidad 
	}
	else /*si solo hay un elemento*/ {
		//lo siguiente es para entendimiento del programador:
		cout << "------------------------------------------------------------" << endl;
		cout << "Proof last and first point to the same memory address:" << endl;
		cout << "last: " << last << endl;
		cout << "first: " << first << endl;
		cout << "------------------------------------------------------------" << endl;

		delete first; //liberamos la localidad de memoria que apunta first
		first = nullptr; //para evitar un dangling pointer
		last = nullptr; //placing null to also last. Because we eliminated first, last will point to an invalid address
		size--;
	}
}

template <typename T>
int LinkedList<T>::GetSize() {
	//getter
	return size;
}

template <typename T>
Node<T>* LinkedList<T>::Search(T data) {
	if (first == nullptr) /*si la lista esta vacia*/ {
		return nullptr; //regresar un vacio como "invalido"
	}

	Node<T>* iterator = first;

	while (iterator->data != data && iterator->next != nullptr) {
		/*reccorrer la lista hasta que encuentre un nodo con el dato buscado
		o que sea el ultimo nodo*/
		iterator = iterator->next;
	}

	if (iterator->data == data) /*si el nodo "x" tiene el dato buscado*/ {
		return iterator; //regresar el nodo "x" con el dato encontrado
	}
	return nullptr;//si llego al ultimo nodo y no encontro nada, regresa nullptr
}

template <typename T>
void LinkedList<T>::PopFront() {
	if (first == nullptr) /*si la lista esta vacia*/ {
		cout << "Operacion pop front invalida ya que no hay elementos en la lista." << endl;
		return; //para salida forzosa de la funcion
	}

	//the following pop front code works for one element or more:
	Node<T>* oldFirst = first;
	first = first->next; // if there is only one element, first is last, so first->next is nullptr.
	
	if (first != nullptr) {
		first->predecessor = nullptr;// it does not make sense to specify a predecessor to first when is nullptr
	}

	delete oldFirst;
}


template <typename T>
void LinkedList<T>::PushFront(T data) {
	Node<T>* newNode = new Node<T>(); //creando un nuevo nodo de tipo T
	newNode->data = data;
	
	if (first == nullptr) /*si la lista esta vacia*/ {
		first = newNode; /*el primer nodo de la lista es el nuevo nodo*/
		first->next = nullptr;/*el siguiente nodo está vacío porque es el unico elemento*/
		first->predecessor = nullptr; /*el nodo anterior esta vacío porque no hay ninguno antes de first*/
		last = first; /*al ser el unico elemento, es first y last al mismo tiempo*/
	} else /*si la lista no esta vacia*/ {
		Node<T>* oldFirst = first; /*oldFirst es un auxilar para ligar el nuevo first*/
		first = newNode; /*el primer elemento ahora es el nuevo nodo*/
		first->next = oldFirst; /*su siguiente es el que antes era first*/
		first->predecessor = nullptr; /*el predecesor esta vacío porque no hay ningun nodo antes de first*/
	}
}

//definicion de funciones para usar en main
template <typename T>
void printFound(Node<T>* nodeFound) {
	/*esta funcion se complementa con LinkedList::Search()*/
	string result = (nodeFound != nullptr) /*si la busqueda fue exitosa*/ ? to_string(nodeFound->data) /*convertir dato del nodo encontrado a string*/ : "not found.";
	cout << "The node found is: " << result << endl;
}