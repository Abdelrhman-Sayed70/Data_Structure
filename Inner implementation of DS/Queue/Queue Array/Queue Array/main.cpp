#include <iostream>
#include "QueueArr.cpp"

using namespace std;

int main()
{
	QueueArr<char> q;
	q.enqueue('s');
	q.enqueue('a');
	q.dequeue();
	q.enqueue('w');

	cout<<"the queue contains:"<<endl;
	while(!q.empty())
	{
		cout<<q.Front()<<endl;
		q.dequeue();
	}
	
	return 0;
}  
