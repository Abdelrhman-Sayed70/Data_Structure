#include "LinkedStack.h"
#include<iostream>

template <class T>
StackNode<T>::StackNode() {
	data = 0;
	next = NULL;
}

template <class T>
StackNode<T>::StackNode(T d) {
	data = d;
	next = NULL;
}

template <class T>
LinkedStack<T>::LinkedStack() {
	size = 0;
	head = NULL; //head = 0;
}

template <class T>
bool LinkedStack<T>::isEmpty() {
	if (size == 0)
		return true;
	else
		return false;
	return(size == 0);
}

template <class T>
void LinkedStack<T>::push(T val) {
	
}


template <class T>
T LinkedStack<T>::pop() {

}

template <class T>
void LinkedStack<T>::clear() {

}

template <class T>
LinkedStack<T>::~LinkedStack() {
	clear();
}
