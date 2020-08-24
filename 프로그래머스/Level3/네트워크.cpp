#include <iostream>
#include <vector>

using namespace std;

int visited[200] = { 0, };

void dfs(int net, int n, vector<vector<int> > computers) {
	visited[net] = 1; // 컴퓨터 방문
	for (int i = 0; i < n; i++) { // 다른 컴퓨터 탐색
		if (visited[i] == 0 && computers[net][i] == 1) { // 방문하지 않은 컴퓨터 && 연결된 컴퓨터
			dfs(i, n, computers); // 연결된 컴퓨터 탐색 (해당 컴퓨터부터)
		}
	}
}

int solution(int n, vector<vector<int> > computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) { // 모든 컴퓨터
		if (visited[i] == 0) { // 방문하지 않은 컴퓨터
			answer++; // 네트워크 증가
			dfs(i, n, computers); // 연결된 컴퓨터 탐색 (새로운 컴퓨터부터)
		}
	}
	return answer;
}

int main() {
	int ans;
	ans = solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} });
	cout << ans << endl;
	ans = solution(3, { { 1, 1, 0 },{ 1, 1, 1 },{ 0, 1, 1 } });
	cout << ans << endl;
	return 0;
}