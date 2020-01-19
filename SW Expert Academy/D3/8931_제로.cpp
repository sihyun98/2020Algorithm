#include <iostream>
#include <stack>

using namespace std;

int main() {
	int test, k, num, cnt;
	stack<int> s;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> k;
		cnt = 0;
		for (int j = 0; j < k; j++) {
			cin >> num;
			if (num != 0) {
				s.push(num);
			}
			else {
				s.pop();
			}
		}
		while (!s.empty()) {
			cnt += s.top();
			s.pop();
		}
		cout << "#" << i + 1 << " " <<cnt << endl;
	}
	return 0;
}