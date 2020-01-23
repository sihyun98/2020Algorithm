#include <iostream>
#include <vector>

using namespace std;

int main() {
	// initialize variables
	char c;
	int cnt;
	vector<char> MS;
	vector<char> TK;

	// input
	for (int i = 0; i < 2; i++) {
		cin >> c;
		MS.push_back(c);
	}
	for (int i = 0; i < 2; i++) {
		cin >> c;
		TK.push_back(c);
	}

	//algorithm
	// when MS wins
	for (int i = 0; i < 2; i++) {
		// check cases when MS wins both
		cnt = 0;
		for (int j = 0; j < 2; j++) {
			if (MS[i] == 'R' && TK[j] == 'S') {
				cnt++;
			}
			else if (MS[i] == 'S' && TK[j] == 'P') {
				cnt++;
			}
			else if (MS[i] == 'P' && TK[j] == 'R') {
				cnt++;
			}
			else {
				continue;
			}
		}
		if (cnt == 2) {
			cout << "MS";
			return 0;
		}
	}
	// when TK wins
	for (int i = 0; i < 2; i++) {
		// check cases when TK wins both
		cnt = 0;
		for (int j = 0; j < 2; j++) {
			if (TK[i] == 'R' && MS[j] == 'S') {
				cnt++;
			}
			else if (TK[i] == 'S' && MS[j] == 'P') {
				cnt++;
			}
			else if (TK[i] == 'P' && MS[j] == 'R') {
				cnt++;
			}
			else {
				continue;
			}
		}
		if (cnt == 2) {
			cout << "TK";
			return 0;
		}
	}
	// when draw
	if (cnt != 2) {
		cout << "?";
	}
	return 0;
}