#include <iostream>
#include<string>
#include<stack>
#include"linked.cpp" 
using namespace std;
int main() {
	LinkedList<int>L;
	// put your code here :
	

	//_____________________________________
	cout << "after undo :\n";
	for (int i = 0; i < L.length(); i++) {
		cout << L.at(i) << " ";
	}
	//put here your undo operations :

	
	//___________________________________
	cout << "\nBefor Undo:\n";
	for (int i = 0; i < L.length(); i++) {
		cout << L.at(i) << " ";
	}
}



 