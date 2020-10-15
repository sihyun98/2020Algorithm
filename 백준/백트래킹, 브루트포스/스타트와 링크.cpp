#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int table[20][20] = { 0, };
int N = 0;
int total = 0;
int mini = 1000000000;

void combi(int n, int ch, int cnt, vector<int> visited) {
	if (cnt == n) {
		int one = 0, two = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] == 0 && visited[j] == 0) {
					one += table[i][j];
				}
				if (visited[i] == 1 && visited[j] == 1) {
					two += table[i][j];
				}
			}
		}
		if (abs(one - two) < mini) {
			mini = abs(one - two);
		}
		return;
	}
	if (ch == N) {
		return;
	}
	visited[ch] = 1;
	combi(n, ch + 1, cnt + 1, visited);
	visited[ch] = 0;
	combi(n, ch + 1, cnt, visited);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &table[i][j]);
			total += table[i][j];
		}
	}
	vector<int> v;
	for (int i = 0; i < N; i++) {
		v.push_back(0);
	}

	combi(N / 2, 0, 0, v);

	printf("%d", mini);
	return 0;
}