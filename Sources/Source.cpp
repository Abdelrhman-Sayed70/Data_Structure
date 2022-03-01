#include<iostream>
using namespace std; 
int main() {
	// Decleration pointers : 
	int* ptr;	     
	int i = 5; 
	// make pointer point to the same address of i
	ptr = &i;		
	// * ptr mean the value that the pointer point to 
	cout << *ptr << "\n";     // 5 
	cout << ptr <<"\n";		 // will display address of pointer
	cout << i << "\n";		// i = 5 ;
	*ptr = 3;
	cout << *ptr << "\n";	// 3 ;
	cout << i << "\n" ;     // 3 ;
}