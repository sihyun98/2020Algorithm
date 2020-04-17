#include <iostream>

using namespace std;

int time[15];
int pay[15];
int N;
int maximum = 0;

void profit(int d, int t) {
	if (d >= N) {
		if (maximum < t) {
			maximum = t;
		}
		return;
	}
	if (d + time[d] <= N) {
		profit(d + time[d], t + pay[d]);
	}
	profit(d + 1, t);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> time[i] >> pay[i];
	}
	profit(0, 0);
	cout << maximum;
	return 0;
}