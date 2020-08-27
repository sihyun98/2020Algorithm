#include <iostream>
#include <vector>

using namespace std;

int map[101][101] = { 0, };

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	for (int i = 0; i < puddles.size(); i++) {
		map[puddles[i][1]][puddles[i][0]] = -1; // ¹°¿õµ¢ÀÌ
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == -1) { // ¹°¿õµ¢ÀÌ
				map[i][j] = 0; // ¸ø°¨
			}
			else if (i == 1 && j == 1) { // Ã¹ ½ÃÀÛÁ¡
				map[i][j] = 1;
			}
			else { // ´õÇÏ±â
				map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007; // È¿À²¼º
			}
		}
	}
	answer = map[n][m];
	return answer;
}

int main() {
	//int ans = solution(4, 3, { {2, 2} });
	int ans = solution(4, 3, { { 1, 2 }, {4,3} });
	cout << ans << endl;
	return 0;
}