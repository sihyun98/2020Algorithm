#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i<phone_book.size(); i++) {
		cout << phone_book[i] << " ";
	}
	cout << endl;
	for (int i = 0; i<phone_book.size() - 1; i++) {
		for (int j = i + 1; j<phone_book.size(); j++) {
			//cout << phone_book[j] << " / " << phone_book[i] << endl;
			if (phone_book[j].length() >= phone_book[i].length()) {
				int cnt = 0;
				for (int k = 0; k<phone_book[i].length(); k++) {
					if (phone_book[i][k] == phone_book[j][k]) {
						cnt++;
					}
				}
				if (cnt == phone_book[i].length()) {
					answer = false;
					return answer;
				}
			}
		}
	}
	return answer;
}