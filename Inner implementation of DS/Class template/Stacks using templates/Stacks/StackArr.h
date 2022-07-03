#pragma once
//template <class T>
template<class T> 
class StackArr
{
	T* arr;
	int count;
	int size;
public:
	StackArr(void);
	int Length();
	void Push(T);
	void Pop();
	T Top();
	bool empty();
	void Expand();
	~StackArr(void);
};

