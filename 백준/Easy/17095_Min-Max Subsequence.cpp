#include <iostream>
#include <vector>

using namespace std;

int main() {
	// initialize variables
	int n, num, temp = 0, max = 1, min = 100000, maxIdx = 0, minIdx = 0, length = 100000;
	vector <int> sequence;

	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sequence.push_back(num);
	}

	// algorithm
	for (int i = 0; i < sequence.size(); i++) {
		// find min
		if (sequence[i] <= min) {
			min = sequence[i];
			minIdx = i;
		}
		// find max
		if (sequence[i] >= max) {
			max = sequence[i];
			maxIdx = i;
		}

		// if min, max value changes
		if (temp < max - min) {
			temp = max - min;
			// change length
			if (minIdx > maxIdx) {
				length = minIdx - maxIdx + 1;
			}
			else {
				length = maxIdx - minIdx + 1;
			}
		}
		else { // if min, max value does not change
			// change length to shortest
			if (minIdx > maxIdx) {
				if (length > minIdx - maxIdx + 1) {
					length = minIdx - maxIdx + 1;
				}
			}
			else {
				if (length > maxIdx - minIdx + 1) {
					length = maxIdx - minIdx + 1;
				}
			}
		}
	}

	// output
	cout << length;
	return 0;
}