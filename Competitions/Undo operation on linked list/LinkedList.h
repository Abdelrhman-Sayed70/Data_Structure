#include<stack>
#include<string>
#include<iostream>
using namespace std; 
template<class T>
class Node {
public :
	T value;
	Node<T>* nextpointer;

	Node();
	Node(T);
};

template<class T>
class LinkedList {	 
 
	int count;
	Node<T>* head;
	Node<T>* tail;
public:

	stack<string>operations_done; // will contain type of operation like append , delete ,insertat
	stack<int>values_taken; // will contain index of the inserted element 
	stack<pair<int, T>>values_deleted;
	LinkedList(); 
	T at(int);
	int length();
	void insertat(int,T);
	void insertfirst(T);
	void append(T);
	void deletat(int);
	void Undo();
	~LinkedList(void); 
};

