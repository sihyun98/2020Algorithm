
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int map[50][50];
int N, M, ans = 100000000;
int selected[14];
vector<int> house_x;
vector<int> house_y;
vector<int> chicken_x;
vector<int> chicken_y;

void cases(int cur, int tot) {
	if (cur > chicken_x.size()) {
		return;
	}
	if (tot == M) {
		int temp, min, distance = 0;
		for (int i = 0; i < house_x.size(); i++) {
			min = 100000000;
			for (int j = 0; j < chicken_x.size(); j++) {
				if (selected[j]) {
					temp = abs(house_x[i] - chicken_x[j]) + abs(house_y[i] - chicken_y[j]);
					if (temp < min) {
						min = temp;
					}
				}
			}
			distance += min;
		}
		if (distance < ans) {
			ans = distance;
		}
		return;
	}
	selected[cur] = 1;
	cases(cur + 1, tot + 1);
	selected[cur] = 0;
	cases(cur + 1, tot);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house_x.push_back(j);
				house_y.push_back(i);
			}
			else if (map[i][j] == 2) {
				chicken_x.push_back(j);
				chicken_y.push_back(i);
			}
		}
	}

	cases(0, 0);
	cout << ans;

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N, M;
int map[50][50];
int d[50][50] = {0,};
bool check[2500] = {true,};
vector<int> house_x, house_y, chicken_x, chicken_y;

int dist(int i, int j) {
	int dist = 0;
	dist = abs(chicken_x[i] - house_x[j]) + abs(chicken_y[i] - house_y[j]);
	return dist;
}

int mini(bool c[]) {
	int result = 0;
	for (int i = 0; i < house_x.size(); i++) {
		int min = d[0][i];
		for (int j = 0; j < chicken_x.size(); j++) {
			if (c[j] == true) {
				if (d[j][i] < min) {
					min = d[j][i];
				}
			}
		}
		result += min;
	}
	return result;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house_x.push_back(j);
				house_y.push_back(i);
			}
			else if (map[i][j] == 2) {
				chicken_x.push_back(j);
				chicken_y.push_back(i);
			}
		}
	}

	for (int i = 0; i < chicken_x.size(); i++) {
		for (int j = 0; j < house_x.size(); j++) {
			d[i][j] = dist(i, j);
			cout << d[i][j];
		}
		cout << endl;
	}

	int temp = 0;
	for (int i = chicken_x.size() - 1; i >= M; i++) {
		check[i] = false;
	}
	temp = mini(check);

	for (int i = chicken_x.size()-1; i >= M; i++) {
		check[i] = true;
	}

	for (int i = 0; i < chicken_x.size(); i++) {
		check[i] = false;
		if (mini(check) > temp) {
			check[i] = true;
			continue;
		}
		else {
			for (int j = i + 1; j < chicken_x.size(); j++) {
				check[j] = false;
				if (mini(check) < temp) {
					temp = mini(check);
				}
				check[j] = true;
			}
		}
		check[i] = true;
	}

	cout << temp;
	return 0;
}
*/