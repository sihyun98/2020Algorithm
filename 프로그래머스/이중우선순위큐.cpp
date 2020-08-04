#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//pair<int, int> max = make_pair(0, -1);
//pair<int, int> min = make_pair(0, -1);

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	int min = 0, max = 0;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			answer.push_back(stoi(operations[i].substr(2, operations[i].size())));
			sort(answer.begin(), answer.end());
		}
		else {
			if (answer.size() != 0) {
				if (operations[i].size() == 3) {
					answer.pop_back();
				}
				else {
					answer.erase(answer.begin());
				}
			}
		}
	}
	//answer.clear();
	if (answer.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		min = answer[0];
		max = answer[answer.size() - 1];
		answer.clear();
		answer.push_back(max);
		answer.push_back(min);
	}
	return answer;
}

int main() {
	vector<int> ans = solution({ "I 16", "D 1" });
	//vector<int> ans = solution({ "I 7", "I 5", "I -5", "D -1" });
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}