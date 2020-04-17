#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T = 0, N = 0, num = 0;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int total = 0;
		cin >> N;
		vector<int> score;
		for (int j = 0; j < N; j++) {
			cin >> num;
			score.push_back(num);
			total += num;
		}
		vector<int> Index(total+1);
		vector<int> Tcase;
		Tcase.push_back(0);
		Index[0] = 1;
		for (int j = 0; j < N; j++) {
			int max = Tcase.size();
			for (int k = 0; k < max; k++) {
				int ans = score[j] + Tcase[k];
				if (!Index[ans]) {
					Tcase.push_back(ans);
					Index[ans] = 1;
				}
			}
		}
		if (!Index[total]) {
			Tcase.push_back(total);
			Index[total] = 1;
		}
		cout << "#" << i+1 << " " << Tcase.size() << endl;
	}
	return 0;
}