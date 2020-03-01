#include <iostream>
#include <queue>

using namespace std;

int xset[4] = { 0, 1, 0, -1 };
int yset[4] = { 1, 0, -1, 0 };
int map[100][100];
int visited[100][100];

int main() {
	// initialization
	int cur_y = 0;
	int cur_x = 0;
	int N, M = 0;
	queue<pair<int, int> > q;
	// put initial values into the queue
	q.push(pair<int, int>(cur_y, cur_x));

	// input
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]); // for each digit input
			visited[i][j] = 0;
		}
	}

	while (!q.empty()) {
		// current position
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		// destination
		if (cur_y == N - 1 && cur_x == M - 1) {
			break;
		}

		// for each 4 directions
		for (int i = 0; i < 4; i++) {
			// next position
			int next_y = cur_y + yset[i];
			int next_x = cur_x + xset[i];
			// if satisfy conditions
			if (next_y >=0 && next_x >= 0 && next_y < N && next_x < M && visited[next_y][next_x] == 0 && map[next_y][next_x] == 1) {
				visited[next_y][next_x] = visited[cur_y][cur_x] + 1; // update distance
				q.push(pair<int, int>(next_y, next_x)); // add next position to the queue
			}
		}
	}

	// output
	printf("%d", visited[N - 1][M - 1]+1);
	return 0;
}