#include <iostream>
#include <vector>

using namespace std;

int board[30][30];
int index[30] = {30, };
vector<int> stack;

int solution(vector<vector<int> > board, vector<int> moves) {
	int answer = 0;
	/* ������ ���� ��ġ�� �����ϴ� index �迭 */
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			/* 0 �� �ƴϸ� �����ϰ� Ż�� */
			if (board[j][i] != 0) {
				index[i] = j;
				break;
			}
		}
	}
	/* �����̱� �� ���� ���� */
	for (int i = 0; i < moves.size(); i++) {
		int c = moves[i] - 1;
		if (index[c] < board.size()) { // ���� ��ġ�� ���� ũ�⸦ ���� ������
			stack.push_back(board[index[c]][c]); // ���ÿ� ����
			index[c]++; // ���� ��ġ �ø���
			/* ���ÿ��� �˻� */
			while (stack.size() > 1) { // ������ ���� ������ �ּ� 2��
				/* �� �� �ΰ� ���� ���� ��� */
				if (stack[stack.size() - 1] == stack[stack.size() - 2]) {
					stack.erase(stack.begin() + (stack.size() - 1)); // �� �� ���� ����
					stack.erase(stack.begin() + (stack.size() - 1)); // �� �� ���� ����
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