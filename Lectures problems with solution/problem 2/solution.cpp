<<<<<<< HEAD
#include <iostream>
#include<stack>
using namespace std;
int main() {
	int n; 
	string S;
	cin >> n >> S;
	stack<char>st;
	for (int i = 0; i < S.size(); i++) {
		if (st.empty()) { st.push(S[i]); }
		else {
			if (st.top() == S[i]) { st.pop(); }
			else { st.push(S[i]); }
		}
	}
	if (st.size() <= 3) { cout << "YES";  }
	else { cout << "NO"; }
=======
#include <iostream>
#include<stack>
using namespace std;
int main() {
	int n; 
	string S;
	cin >> n >> S;
	stack<char>st;
	for (int i = 0; i < S.size(); i++) {
		if (st.empty()) { st.push(S[i]); }
		else {
			if (st.top() == S[i]) { st.pop(); }
			else { st.push(S[i]); }
		}
	}
	if (st.size() <= 3) { cout << "YES";  }
	else { cout << "NO"; }
>>>>>>> e021a963a2604b08842969780e0da8af9d39d536
}