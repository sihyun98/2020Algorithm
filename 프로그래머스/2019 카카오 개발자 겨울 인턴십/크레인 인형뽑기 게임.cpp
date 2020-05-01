#include <iostream>
#include <vector>

using namespace std;

int board[30][30];
int index[30] = {30, };
vector<int> stack;

int solution(vector<vector<int> > board, vector<int> moves) {
	int answer = 0;
	/* 인형의 현재 위치를 저장하는 index 배열 */
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			/* 0 이 아니면 저장하고 탈출 */
			if (board[j][i] != 0) {
				index[i] = j;
				break;
			}
		}
	}
	/* 인형뽑기 및 스택 저장 */
	for (int i = 0; i < moves.size(); i++) {
		int c = moves[i] - 1;
		if (index[c] < board.size()) { // 현재 위치가 보드 크기를 넘지 않으면
			stack.push_back(board[index[c]][c]); // 스택에 저장
			index[c]++; // 현재 위치 늘리기
			/* 스택에서 검사 */
			while (stack.size() > 1) { // 스택의 원소 개수가 최소 2개
				/* 맨 위 두개 값이 같은 경우 */
				if (stack[stack.size() - 1] == stack[stack.size() - 2]) {
					stack.erase(stack.begin() + (stack.size() - 1)); // 맨 위 원소 삭제
					stack.erase(stack.begin() + (stack.size() - 1)); // 맨 위 원소 삭제
					answer += 2;
				}
				else {
					break;
				}
			}
		}
	}
	return answer;
}

int main() {
	cout << solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 }) << endl;
}