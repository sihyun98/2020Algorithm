#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 50;

bool isDiff(string a, string b) {
	int diff = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) {
			diff++;
		}
	}
	if (diff == 1) {
		return true;
	}
	else {
		return false;
	}
}

void next(vector<string> words, string cur, int cnt, string target) {
	if (cur.compare(target) == 0) {
		answer = min(answer, cnt);
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		if (isDiff(cur, words[i])) {
			vector<string> new_words = words;
			new_words.erase(new_words.begin() + i);
			next(new_words, words[i], cnt + 1, target);
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target) {
			break;
		}
		if (i == words.size() - 1) {
			answer = 0;
			return answer;
		}
	}
	next(words, begin, 0, target);
	if (answer == 50) {
		answer = 0;
	}
	return answer;
}

int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
	answer = 50;
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log"}) << endl;
	answer = 50;
	cout << solution("hot", "lot", { "dot", "dog", "lot", "log" }) << endl;
	answer = 50;
	cout << solution("hit", "wow", { "hot", "dot", "dog", "lot", "log", "cog", "wow" }) << endl;
	return 0;
}