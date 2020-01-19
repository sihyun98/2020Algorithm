#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int a, b;
	string one, two;
	vector <char> name;
	vector <int> arr, copy;
	cin >> a >> b;
	cin >> one >> two;
	if (a >= b) {
		for (int i = 0; i < b; i++) {
			name.push_back(one.at(i));
			name.push_back(two.at(i));
		}
		for (int i = b; i < a; i++) {
			name.push_back(one.at(i));
		}
	}
	else {
		for (int i = 0; i < a; i++) {
			name.push_back(one.at(i));
			name.push_back(two.at(i));
		}
		for (int i = a; i < b; i++) {
			name.push_back(two.at(i));
		}
	}
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == 'E') {
			arr.push_back(4);
		}
		else if (name[i] == 'A' || name[i] == 'F' || name[i] == 'H' || name[i] == 'K' || name[i] == 'M') {
			arr.push_back(3);
		}
		else if (name[i] == 'B' || name[i] == 'D' || name[i] == 'N' || name[i] == 'P' || name[i] == 'Q'
			|| name[i] == 'R' || name[i] == 'T' || name[i] == 'X' || name[i] == 'Y') {
			arr.push_back(2);
		}
		else {
			arr.push_back(1);
		}
	}
	while (copy.size() != 2) {
		copy.clear();
		for (int i = 1; i < arr.size(); i++) {
			if ((arr[i] + arr[i - 1]) >= 10) {
				copy.push_back(arr[i] + arr[i - 1] - 10);
			}
			else {
				copy.push_back(arr[i] + arr[i - 1]);
			}
		}
		arr.clear();
		arr = copy;
	}
	if (copy[0] == 0) {
		cout << copy[1] << "%";
	}
	else {
		cout << copy[0] << copy[1] << "%";
	}
	return 0;
}