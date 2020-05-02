#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> m;

long long search(long long n) {
	if (!m[n]) {
		m[n] = n+1;
		return n + 1;
	}
	else {
		long long temp = search(m[n]);
		m[n] = temp;
		return temp;
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	long long temp;
	for (long long i = 0; i < room_number.size(); i++) {
		if (!m[room_number[i]]) {
			m[room_number[i]] = room_number[i] + 1;
			answer.push_back(room_number[i]);
		}
		else {
			temp = search(room_number[i]);
			answer.push_back(temp - 1);
		}
	}
	return answer;
}

int main() {
	vector<long long> ans = solution(10, { 1, 3, 4, 1, 3, 1 });
	for (long long i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}