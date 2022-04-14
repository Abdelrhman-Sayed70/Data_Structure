#include"LinkedList.h"
#include<assert.h>
#include<stack>
template<class T>
Node<T>::Node() {
	value = 0;
	nextpointer = 0 ;
}
template<class T>
Node<T>::Node(T val){
	value = val;
	nextpointer = 0;
}

template<class T>
LinkedList<T>::LinkedList() {
 
	head = tail = 0; 
	count = 0;
}
template<class T>
int LinkedList<T>::length() {
	return count;
}
template<class T>
void LinkedList<T>::append(T val) {
	Node<T>* newnode = new Node<T>(val);
	if (count == 0) {
		head = tail = newnode;
	}
	else {
		tail->nextpointer = newnode; // make the last element in the list point to the added node
		tail = newnode;
	}
	count++;
	operations_done.push("append"); 
}
template<class T>
void LinkedList<T>::insertfirst(T val) {
	Node<T>* newnode = new Node<T>(val);
	if (count == 0) {
		head = tail = newnode;
	}
	else {
		newnode->nextpointer = head;
		head = newnode;
	}
	count++;
}
template<class T>
T LinkedList<T>::at(int pos) {
	// we need to iterate over linkedlist using pointer : this pointer will point tp node 
	assert(pos >= 0 and pos < count);
	Node<T>* tmppointer=head; 
	for (int i = 0; i < pos; i++) {
		tmppointer = tmppointer->nextpointer;
	}
	return tmppointer->value;
}
template<class T >
void LinkedList<T>::insertat(int pos, T val) {
	assert(pos >= 0 and pos <= count);

	Node<T>* newnode= new Node<T>(val);
	if (count == 0) {
		head = tail = newnode;
	}
	else if (pos == 0) {
		newnode->nextpointer = head;
		head = newnode;
	}
	else {
		Node<T>* tmppointer = head;
		for (int i = 0; i < pos - 1; i++) {
			tmppointer = tmppointer->nextpointer;
		}
		newnode->nextpointer = tmppointer->nextpointer;
		tmppointer->nextpointer = newnode;
	}
	count++;
	operations_done.push("insert_at");
	values_taken.push(pos);
}
template<class T >
void LinkedList<T>::deletat(int pos) {
	assert(count != 0 and pos >= 0 and pos < count);
	T deletedvalue;
	Node<T>* tmppointer = head;
	if (pos == 0) {
		deletedvalue = head->value;
		head = head->nextpointer;
		delete tmppointer;
	}
	else {
		Node<T>* del;
		for (int i = 0; i < pos - 1; i++) {
			tmppointer = tmppointer->nextpointer;
		}
		del = tmppointer->nextpointer;
		deletedvalue = del->value;
		if (pos==count-1) {
			tail = tmppointer;
		}
		else {
			tmppointer->nextpointer = del->nextpointer;
		}
		delete del;
	}
	count--;
	operations_done.push("delet_at");
	values_deleted.push({ pos,deletedvalue });
}
template<class T >
void LinkedList<T>::Undo() {
	assert(!operations_done.empty());
	if (operations_done.top() == "append") {
		deletat(count - 1);
		values_deleted.pop();
		operations_done.pop();
		operations_done.pop();
	}
	else if (operations_done.top() == "insert_at") {
		assert(!values_taken.empty());
		deletat(values_taken.top());
		values_taken.pop();
		operations_done.pop();
		operations_done.pop();
		values_deleted.pop();
	}
	else if (operations_done.top() == "delet_at") {
		assert(!values_deleted.empty());
		insertat(values_deleted.top().first, values_deleted.top().second);
		values_deleted.pop();
		operations_done.pop();
		operations_done.pop();
		values_taken.pop();
	}
}
template<class T> 
LinkedList<T>::~LinkedList() {
	while (count != 0) {
		deletat(0);
	}
}