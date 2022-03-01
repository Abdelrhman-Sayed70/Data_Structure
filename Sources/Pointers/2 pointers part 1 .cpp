#include<iostream>
using namespace std; 
int main() {
	// 2 pointers 
	int* p1 , * p2;
	int v1 = 8, v2 = 9;
	p1 = &v1; 
	p2 = &v2;
	cout << *p1 << " " << *p2 << "\n";  // 8 9 
	// make p1 point to what p2 point
	// put the address of p2 to p1 
	p1 = p2;
	cout << *p1 << " " << *p2 << "\n";  // 9 9 
	
}
