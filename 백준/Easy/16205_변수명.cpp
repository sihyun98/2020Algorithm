#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	// initialize variables
	int num, left = 0;
	vector<string> word, copy;
	string var;

	// input
	cin >> num;
	cin >> var;
	// save words to vector 'word'
	for (int i = 1; i < var.size(); i++) {
		if (var.at(i) == 95) {
			word.push_back(var.substr(left, i - left));
			left = i + 1;
		}
		else if (var.at(i) < 97) {
			word.push_back(var.substr(left, i - left));
			left = i;
		}
	}
	word.push_back(var.substr(left, var.size() - left));
	// copy vector 'word' to vector 'copy'
	copy = word;

	// output
	// 1. camel
	if (num == 3) {
		word[0].at(0) += 32;
	}
	cout << word[0];
	for (int i = 1; i < word.size(); i++) {
		if (num == 2) {
			word[i].at(0) -= 32;
		}
		cout << word[i];
	}
	cout << endl;

	// 2. snake
	word = copy;
	if (num == 3) {
		word[0].at(0) += 32;
	}
	cout << word[0];
	for (int i = 1; i < word.size(); i++) {
		if (num != 2) {
			word[i].at(0) += 32;
		}
		cout << "_" << word[i];
	}
	cout << endl;

	// 3. pascal
	word = copy;
	if (num != 3) {
		word[0].at(0) -= 32;
	}
	cout << word[0];
	for (int i = 1; i < word.size(); i++) {
		if (num == 2) {
			word[i].at(0) -= 32;
		}
		cout << word[i];
	}

	return 0;
}