#include <iostream>
#include <vector>

using namespace std;

int visited[200] = { 0, };

void dfs(int net, int n, vector<vector<int> > computers) {
	visited[net] = 1; // ��ǻ�� �湮
	for (int i = 0; i < n; i++) { // �ٸ� ��ǻ�� Ž��
		if (visited[i] == 0 && computers[net][i] == 1) { // �湮���� ���� ��ǻ�� && ����� ��ǻ��
			dfs(i, n, computers); // ����� ��ǻ�� Ž�� (�ش� ��ǻ�ͺ���)
		}
	}
}

int solution(int n, vector<vector<int> > computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) { // ��� ��ǻ��
		if (visited[i] == 0) { // �湮���� ���� ��ǻ��
			answer++; // ��Ʈ��ũ ����
			dfs(i, n, computers); // ����� ��ǻ�� Ž�� (���ο� ��ǻ�ͺ���)
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