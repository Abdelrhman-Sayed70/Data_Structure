#include <iostream>
using namespace std;
int main()
{
   // print array elements using pointers
	int arr[5] = { 1,2,3 };
	int* ptr = arr; 
	for (int i = 0; i < 3 ; i++) {
		cout << arr[i] << " "; // or 
		//cout << ptr[i] << " "; or
		//cout << *(ptr + i) << " "; or 
		//cout << *(arr + i) << " ";or 
		//cout << *ptr++ << " ";
	}
}