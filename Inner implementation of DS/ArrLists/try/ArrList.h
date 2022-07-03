#pragma once
template <class T>
class ArrList
{
	T* arr;
	int size, count;
public:
	ArrList();
	int Length();
	void Append(T);
	void Expand();
	T At(int);
	void insertAt(int, T);
	void deleteAt(int);
	~ArrList(void);
};

