#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> name;
	for (int i = 0; i<participant.size(); i++) {
		if (!name[participant[i]]) {
			name[participant[i]] = 1;
		}
		else {
			name[participant[i]]++;
		}
	}
	for (int i = 0; i<completion.size(); i++) {
		name[completion[i]]--;
		if (name[completion[i]] == 0) {
			name.erase(completion[i]);
		}
	}
	answer = name.begin()->first;
	return answer;
}