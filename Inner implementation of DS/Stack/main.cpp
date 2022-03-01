#include <iostream>
#include "stackArr.h"
using namespace std;
int main() {
	stackArr st;
	st.push(3);
	st.push(2);
	st.push(1);
	while (!st.empty()){
		cout << st.top() << "\n";
		st.pop();
	}
}