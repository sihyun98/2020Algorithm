#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check[8];
set<string> s;

/* 모든 경우의 수 확인 */
void calc(int num, string c, vector<string> user_id, vector<string> banned_id) {
	/* 제재 아이디 목록 완성 */
	if (num == banned_id.size()) {
		sort(c.begin(), c.end());
		s.insert(c); // 중복 제거
		return;
	}

	for (int i = 0; i < user_id.size(); i++) {
		/* 이미 사용되었거나 응모자 아이디와 불량 사용자 아이디가 다른 경우 */
		if (check[i] || (user_id[i].length() != banned_id[num].length())) {
			continue;
		}
		bool flag = true;
		for (int j = 0; j < user_id[i].length(); j++) {
			/* '*'이면 넘어감 */
			if (banned_id[num][j] == '*') {
				continue;
			}
			/* 한 글자라도 다르면 다음 아이디로 이동 */
			else if (user_id[i][j] != banned_id[num][j]) {
				flag = false;
				break;
			}
		}

		/* 모두 같으면 */
		if (flag) {
			check[i] = true; // 사용했다고 표시
			calc(num + 1, c + char(i), user_id, banned_id); // 다음 아이디로 이동, 배열 인덱스 저장
			check[i] = false; // 다른 사용자와 연결하는 경우
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