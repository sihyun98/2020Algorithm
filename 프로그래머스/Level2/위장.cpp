#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, vector<string> > today;
	for (int i = 0; i<clothes.size(); i++) {
		cout << clothes[i][0] << endl;
		vector<string> temp = today[clothes[i][1]];
		temp.push_back(clothes[i][0]);
		today[clothes[i][1]] = temp;
	}
	auto it = today.begin();
	for (it; it != today.end(); it++) {
		answer *= it->second.size() + 1;
	}
	answer--;
	return answer;
}