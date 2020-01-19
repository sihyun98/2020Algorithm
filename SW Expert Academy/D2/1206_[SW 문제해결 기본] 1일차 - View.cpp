#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> v, int n);

int max(vector<int> v, int n) {
	int maximum = 0, temp1 = 0, temp2 = 0;
	if (v[n - 2] < v[n - 1]) {
		temp1 = v[n - 1];
	}
	else {
		temp1 = v[n - 2];
	}
	if (v[n + 1] > v[n + 2]) {
		temp2 = v[n + 1];
	}
	else {
		temp2 = v[n + 2];
	}
	if (temp1 > temp2) {
		maximum = temp1;
	}
	else {
		maximum = temp2;
	}
	return maximum;
}

int main()
{
	for (int i = 0; i < 10; i++) {
		int num, len;
		int cnt = 0;
		vector <int> v;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> len;
			v.push_back(len);
		}
		for (int j = 2; j < num - 2; j++) {
			if ((v[j] - max(v, j)) > 0) {
				cnt += (v[j] - max(v, j));
			}
			else {
				continue;
			}
		}
		cout << "#" << i+1 << " " << cnt << endl;
	}
	return 0;
}