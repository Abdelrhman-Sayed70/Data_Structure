#include <iostream>
#include<string>
#include<stack>
#include"linked.cpp" 
using namespace std;
int main() {
	LinkedList<int>L;
	// put your code here :
	L.append(1);
	L.append(2);
	L.append(3);
	L.append(4);

	//_____________________________________
	cout << "Befor undo :\n";
	for (int i = 0; i < L.length(); i++) {
		cout << L.at(i) << " ";
	}
	//put here your undo operations :
	L.myswap(3, 4);
	
	//___________________________________
	cout << "\nAfter Undo :\n";
	for (int i = 0; i < L.length(); i++) {
		cout << L.at(i) << " ";
	}
}