#pragma once
//#include "QueueArr.cpp"

template <class T>
class QueueArr
{
	T* arr;
	int count, size;
	int front, back; // indecies
public:
	QueueArr();
	int length();
	void enqueue(T);
	void dequeue();
	T Front();
	bool empty();
	bool full();
	~QueueArr();
};

