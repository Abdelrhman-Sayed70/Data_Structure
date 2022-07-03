template <class T>
class  StackNode
{
public:
	T data;
	StackNode<T> *next;
	StackNode();
	StackNode(T);
};

template <class T>
class LinkedStack
{
	int size;
	StackNode<T> *head;
public:
	LinkedStack();
	~LinkedStack();
	bool isEmpty();
	void push(T);
	T pop();
	void clear();

};

