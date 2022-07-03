#include "StackArr.h"
#include <assert.h>

template <class T>
StackArr<T>::StackArr()
{
	size=10;
	count=0;
	arr=new T[size];
}



template <class T>
int StackArr<T>::Length()
{
	return count;
}

template <class T>
void StackArr<T>::Push(T val)
{
	if(count==size)
		Expand();
	arr[count]=val;
	count++;
}

template <class T>
void StackArr<T>::Pop()
{
	assert(!empty());
	count--;
}

template <class T>
T StackArr<T>::Top()
{
	assert(!empty());
	return arr[count-1];
}

template <class T>
bool StackArr<T>::empty()
{
	return (count==0);
}

template <class T>
void StackArr<T>::Expand()
{
	size+=5;
	T* tmp=new T[size];
	for(int i=0;i<count;i++)
		tmp[i]=arr[i];
	delete[] arr;
	arr=tmp;
}

template <class T>
StackArr<T>::~StackArr(void)
{
	delete[] arr;
}
