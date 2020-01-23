#include <iostream>
#include <vector>

using namespace std;

int main() {
	// initialize variables
	int n, ability, maxPro, score = 0;
	bool done = false;
	vector <vector <int> > level;

	// input
	cin >> n;
	cin >> ability;
	cin >> maxPro;
	level.assign(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		cin >> level[i][0];
		cin >> level[i][1];
	}

	// algorithm
	while (1) {
		// difficult problems
		for (int i = 0; i < n; i++) {
			if (level[i][1] != 0 && level[i][1] <= ability) {
				level[i][0] = 0;
				level[i][1] = 0;
				score += 140;
				maxPro--;
			}
			// while end condition
			if (maxPro == 0) {
				done = true;
				break;
			}
		}
		// while end condition
		if (done == true) {
			break;
		}
		else {
			// easy problems
			for (int i = 0; i < n; i++) {
				if (level[i][0] != 0 && level[i][0] <= ability) {
					level[i][0] = 0;
					level[i][1] = 0;
					score += 100;
					maxPro--;
				}
				// while end condition
				if (maxPro == 0) {
					done = true;
					break;
				}
			}
		}
		// while end condition
		if (done = true) {
			break;
		}
	}

	// output
	cout << score;
	return 0;
}