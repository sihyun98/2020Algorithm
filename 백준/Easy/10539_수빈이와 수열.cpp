#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, num, temp;
	vector <int> sequence, nsequence;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sequence.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		temp = sequence[i] * (i + 1);
		for (int j = 0; j < i; j++) {
			temp -= nsequence[j];
		}
		nsequence.push_back(temp);
	}
	for (int i = 0; i < nsequence.size(); i++) {
		cout << nsequence[i] << " ";
	}
	return 0;
}