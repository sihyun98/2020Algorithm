#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt = 0;
int map[25][25];
int visited[25][25];
int xset[4] = { 1, 0, -1, 0 };
int yset[4] = { 0, 1, 0, -1 };

int dfs(int cur_y, int cur_x) {
	// increase # of houses
	cnt++;
	// for each 4 directions
	for (int i = 0; i < 4; i++) {
		// next position
		int next_x = cur_x + xset[i];
		int next_y = cur_y + yset[i];

		// if next position is NOT in the map
		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) {
			continue;
		}

		// if can go and not visited
		if (map[next_y][next_x] == 1 && visited[next_y][next_x] == 0) {
			map[next_y][next_x] = 0;
			visited[next_y][next_x] = 1; // check visited
			dfs(next_y, next_x); // check near houses
		}
	}
	// return number of houses
	return cnt;
}

int main() {
	// initialization
	int x = 0, y = 0;
	vector<int> v;
	
	// input
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]); // for each digit input
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// initialize
			cnt = 0;
			// only if there is any house
			if (map[i][j] == 0) {
				continue;
			}
			else
			{
				map[i][j] = 0;
				visited[i][j] = 1;
				v.push_back(dfs(i, j));
			}
		}
	}

	// sort vector in ascending order
	sort(v.begin(), v.end());

	// output
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}