#include <iostream>
#include <string.h> // memset

using namespace std;

int ans, M, N = 0;
int yset[4] = { 0, 1, 0, -1 };
int xset[4] = { 1, 0, -1, 0 };
int map[50][50] = {0,};
int visited[50][50] = {0,};

void dfs(int y, int x) {
	// direction changes in clockwise from east
	for (int i = 0; i < 4; i++) {
		int newY = y + yset[i];
		int newX = x + xset[i];
		if (newY < 0 || newX < 0 || newY >= M || newX >= N) {
			continue;
		}
		if (map[newY][newX] == 1 && visited[newY][newX] == 0) {
			visited[newY][newX] = 1;
			dfs(newY, newX); // recursion
		}
	}
}

int main() {
	int test, K, a, b;
	// input
	scanf("%d", &test);

	for (int k = 0; k < test; k++) {
		// initialize
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		ans = 0;

		// input
		scanf("%d %d %d", &M, &N, &K);

		// coordinates input
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &a, &b);
			map[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				// if yes and not visited
				if (map[i][j] == 1 && visited[i][j] == 0) {
					ans++;
					visited[i][j] = 1;
					dfs(i, j); // call function
				}
			}
		}
		// output
		printf("%d\n", ans);
	}

	return 0;
}