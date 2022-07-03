#include<iostream>
#include"BST.cpp" 
using namespace std; 
int main(){
	BST<int>b; 
	int n; 
	cout << "Enter size of your tree\n"; 
	cin >> n;
	cout << "Enter tree elements\n";
	int val;
	while (n--) {
		cin >> val;
		b.insert(val);
	}
	int value;
	cout << "Enter value to get removed : " ; 
	cin >> value;
	b.remove(value);
	b.traverse(1);
}