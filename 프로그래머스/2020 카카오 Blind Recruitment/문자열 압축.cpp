#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = 1000;
	for (int i = 1; i <= s.length(); i++) {
		string new_s = "";
		string prev = s.substr(0, i);
		int cnt = 0;
		for (int j = 0; j < s.length(); j+=i) {
			if (s.substr(j, i) == prev) {
				cnt++;
			}
			else {
				if (cnt == 1) {
					new_s += prev;
				}
				else {
					new_s += (to_string(cnt) + prev);
				}
				cnt = 1;
				prev = s.substr(j, i);
			}
		}
		if (cnt == 1) {
			new_s += prev;
		}
		else {
			new_s += (to_string(cnt) + prev);
		}
		int len = new_s.length();
		answer = min(len, answer);
	}
	return answer;
}

int main() {
	cout << solution("aabbaccc") << endl;
	cout << solution("ababcdcdababcdcd") << endl;
	cout << solution("abcabcdede") << endl;
	cout << solution("abcabcabcabcdededededede") << endl;
	cout << solution("xababcdcdababcdcd") << endl;
	return 0;
}