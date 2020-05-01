#include <iostream>
#include <string>
#include <vector>

using namespace std;

int index[500] = { 0, };
int v[500][500];

vector<int> solution(string s) {
	vector<int> answer;
	vector<int> temp;
	vector<vector<int> > v(500);
	for (int i = 0; i < 500; i++) {
		vector<int> t;
		v.push_back(t);
	}
	string num = "";
	for (int i = 1; i < s.length() - 1; i++) {
		/* 배열 초기화 */
		if (s[i] == '{') {
			temp.clear();
		}
		/* 배열 저장 */
		else if (s[i] == '}') {
			v[temp.size() - 1] = temp; // 해당 인덱스에 저장
		}
		else if (s[i] == ',') {
			continue;
		}
		else if (s[i + 1] == '}' || s[i + 1] == ',') {
			num += s[i];
			/* 한 자리 숫자 */
			if (num.length() == 1) {
				temp.push_back(s[i] - 48);
			}
			/* 두 자리 수*/
			else {
				temp.push_back(stoi(num));
			}
			num = "";
		}
		else {
			num += s[i];
		}
	}
	for (int i = 0; i < v.size(); i++) {
		/* 배열이 비었는지 확인 */
		if (v[i].empty()) {
			break;
		}
		for (int j = 0; j < v[i].size(); j++) {
			/* 해당 숫자를 저장하지 않았으면 */
			if (index[v[i][j]-1] == 0) {
				index[v[i][j]-1] = 1;
				answer.push_back(v[i][j]); // 숫자 저장
			}
		}
	}
	return answer;
}

int main() {
	//vector<int> ans = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	//vector<int> ans = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
	//vector<int> ans = solution("{{20,111},{111}}");
	vector<int> ans = solution("{{123}}");

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}