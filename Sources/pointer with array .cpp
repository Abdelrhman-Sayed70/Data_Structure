#include<iostream>
using namespace std; 
int main() {
	char msg[] = "Hello";
	char* ptr;
	// pointer will point to the adress of the index 0 in the array
	ptr = msg;
	cout << *ptr << "\n"; //display value of index 0 >> H 
	// change value of index 0 
	*ptr = 'M';
	// pointer will point to the next index (1) ;
	ptr++;
	// change the value of index 1 to a
	*ptr = 'a';
	cout << msg << "\n";  // display Mallo
	// -----------------------------------------
	int* ptr2; 
	int arr[] = { 1,2,3 };
	ptr2 = arr; 
	for (int i = 0; i < 3; i++) {
		cout << *(ptr2 + i) << " " ;
		// we can also write : cout << *ptr++ ;
	}
	// will display 1 2 3 ;
}