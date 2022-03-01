#include <iostream>
using namespace std;
int main() {
	// delete pointer
	int* p1;
	p1 = new int;
	*p1 = 4;
	cout << "p1=" << *p1 << endl; // 4 
	delete p1;
	*p1 = 7;
	cout << "p1=" << *p1 << endl; // not display
	return 0;
}