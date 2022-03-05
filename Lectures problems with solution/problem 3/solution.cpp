#include <iostream>
#include<queue> 
#include<deque>
using namespace std;
int main() {
	int n; 
	while (cin >> n) {
		if (n == 0) { break; }
		else {
			deque<int>q, ans;
			int remain;
			for (int i = 0; i < n; i++) {
				q.push_back(i + 1);
			}
			while (1) {
				ans.push_back(q.front());
				q.pop_front();
				q.push_back(q.front());
				q.pop_front();
				if (q.size() == 1) { remain = q.front(); break; }
			}
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";
			cout << remain<<"\n";
		}
	}
}