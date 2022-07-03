#include <iostream>
#include "StackArr.cpp"

using namespace std;

int main()
{
	StackArr<char> S;
	S.Push('a');
	S.Push('b');
	S.Push('c');

	cout<<"top= "<<S.Top()<<endl;

	while(!S.empty())
	{
		cout<<S.Top()<<endl;
		S.Pop();
	}
	
	return 0;
}