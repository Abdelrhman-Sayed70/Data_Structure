#include <iostream>
using namespace std;
int main() {
	// Expand size of Dynamic arrayes
	int size = 5;
	int* oldarr = new int[size];
	int* newarr = new int[size + 5];
	for (int i = 0; i < size; i++) {
		newarr[i] = oldarr[i]; 
	}
	size += 5;
	delete[]oldarr;
	oldarr = newarr;
}