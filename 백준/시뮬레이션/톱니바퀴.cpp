#include <iostream>
#include <cstdio>

using namespace std;

int v[4][8] = { 0, };
int vv[4][8] = { 0, };
int direction[4] = { 0, };

void change() {
	for (int i = 0; i < 4; i++) {
		if (direction[i] == 1) {
			v[i][0] = vv[i][7];
			v[i][1] = vv[i][0];
			v[i][2] = vv[i][1];
			v[i][3] = vv[i][2];
			v[i][4] = vv[i][3];
			v[i][5] = vv[i][4];
			v[i][6] = vv[i][5];
			v[i][7] = vv[i][6];
		}
		else if (direction[i] == -1) {
			v[i][0] = vv[i][1];
			v[i][1] = vv[i][2];
			v[i][2] = vv[i][3];
			v[i][3] = vv[i][4];
			v[i][4] = vv[i][5];
			v[i][5] = vv[i][6];
			v[i][6] = vv[i][7];
			v[i][7] = vv[i][0];
		}
	}
}

int main() {
	int answer = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &v[i][j]);
		}
	}

	int K = 0;
	int num = 0;
	int dir = 0;
	cin >> K;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 8; k++) {
				vv[j][k] = v[j][k];
			}
		}
		for (int j = 0; j < 4; j++) {
			direction[j] = 0;
		}
		scanf("%d %d", &num, &dir);
		direction[num - 1] = dir;
		if (num == 1) {
			if (v[0][2] != v[1][6]) {
				direction[1] = -dir;
				if (v[1][2] != v[2][6]) {
					direction[2] = dir;
					if (v[2][2] != v[3][6]) {
						direction[3] = -dir;
					}
				}
			}
		}
		else if (num == 2) {
			if (v[1][6] != v[0][2]) {
				direction[0] = -dir;
			}
			if (v[1][2] != v[2][6]) {
				direction[2] = -dir;
				if (v[2][2] != v[3][6]) {
					direction[3] = dir;
				}
			}
		}
		else if (num == 3) {
			if (v[2][2] != v[3][6]) {
				direction[3] = -dir;
			}
			if (v[1][2] != v[2][6]) {
				direction[1] = -dir;
				if (v[0][2] != v[1][6]) {
					direction[0] = dir;
				}
			}
		}
		else {
			if (v[3][6] != v[2][2]) {
				direction[2] = -dir;
				if (v[2][6] != v[1][2]) {
					direction[1] = dir;
					if (v[1][6] != v[0][2]) {
						direction[0] = -dir;
					}
				}
			}
		}

		change();
	}

	if (v[0][0] == 1) {
		answer += 1;
	}
	if (v[1][0] == 1) {
		answer += 2;
	}
	if (v[2][0] == 1) {
		answer += 4;
	}
	if (v[3][0] == 1) {
		answer += 8;
	}

	printf("%d", answer);
	return 0;
}