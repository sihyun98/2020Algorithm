#include <iostream>
#include <vector>

using namespace std;

int main() {
	// initialize variables
	int n, bonus = 0, score = 0;
	char c;
	vector <char> answer;

	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		answer.push_back(c);
	}

	// check answer for each problem
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == 79) { // if O
			score += (i + 1 + bonus); // increase score by question NO. and bonus
			bonus++; // increase bonus
		}
		else { // if X
			bonus = 0; // reset bonus
		}
	}

	// output
	cout << score;
	return 0;
}