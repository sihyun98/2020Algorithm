#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check[8];
set<string> s;

/* ��� ����� �� Ȯ�� */
void calc(int num, string c, vector<string> user_id, vector<string> banned_id) {
	/* ���� ���̵� ��� �ϼ� */
	if (num == banned_id.size()) {
		sort(c.begin(), c.end());
		s.insert(c); // �ߺ� ����
		return;
	}

	for (int i = 0; i < user_id.size(); i++) {
		/* �̹� ���Ǿ��ų� ������ ���̵�� �ҷ� ����� ���̵� �ٸ� ��� */
		if (check[i] || (user_id[i].length() != banned_id[num].length())) {
			continue;
		}
		bool flag = true;
		for (int j = 0; j < user_id[i].length(); j++) {
			/* '*'�̸� �Ѿ */
			if (banned_id[num][j] == '*') {
				continue;
			}
			/* �� ���ڶ� �ٸ��� ���� ���̵�� �̵� */
			else if (user_id[i][j] != banned_id[num][j]) {
				flag = false;
				break;
			}
		}

		/* ��� ������ */
		if (flag) {
			check[i] = true; // ����ߴٰ� ǥ��
			calc(num + 1, c + char(i), user_id, banned_id); // ���� ���̵�� �̵�, �迭 �ε��� ����
			check[i] = false; // �ٸ� ����ڿ� �����ϴ� ���
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	calc(0, "", user_id, banned_id);
	int answer = s.size();
	return answer;
}

int main() {
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" }) << endl;
	return 0;
}