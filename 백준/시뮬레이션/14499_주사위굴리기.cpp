#include <iostream>
#include <vector>

using namespace std;

int N, M, cur_x, cur_y, step;
vector<int> dice(6);
vector<vector<int> > map(20, vector<int>(20, 0));

void changeNum() {
	if (map[cur_y][cur_x] == 0) {
		map[cur_y][cur_x] = dice[5];
	}
	else {
		dice[5] = map[cur_y][cur_x];
		map[cur_y][cur_x] = 0;
	}
}

int main() {
	cin >> N >> M >> cur_y >> cur_x >> step;
	vector<int> order(step);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < step; i++) {
		cin >> order[i];
		int temp = dice[5];

		if (order[i] == 1 && cur_x+1<M) { // east
			cur_x++;
			dice[5] = dice[3];
			dice[3] = dice[0];
			dice[0] = dice[2];
			dice[2] = temp;
			changeNum();
		}
		else if (order[i] == 2 && cur_x-1>=0) { // west
			cur_x--;
			dice[5] = dice[2];
			dice[2] = dice[0];
			dice[0] = dice[3];
			dice[3] = temp;
			changeNum();
		}
		else if (order[i] == 3 && cur_y-1>=0) { // north
			cur_y--;
			dice[5] = dice[4];
			dice[4] = dice[0];
			dice[0] = dice[1];
			dice[1] = temp;
			changeNum();
		}
		else if (order[i] == 4 && cur_y+1<N) { // south
			cur_y++;
			dice[5] = dice[1];
			dice[1] = dice[0];
			dice[0] = dice[4];
			dice[4] = temp;
			changeNum();
		}
		else {
			continue;
		}
		cout << dice[0] << endl;
	}
	return 0;
}