#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// initialize variables
	int n, m, num, quiz;
	string group, name;
	vector<vector<string> > girl;
	vector<string> ans;

	// input
	cin >> n;
	cin >> m;
	girl.assign(n, vector<string>());
	for (int i = 0; i < n; i++) {
		cin >> group;
		girl[i].push_back(group);
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> name;
			girl[i].push_back(name);
		}
		// sort in ascending order
		sort(girl[i].begin()+1, girl[i].end());
	}

	// quiz
	for (int i = 0; i < m; i++) {
		cin >> name;
		cin >> quiz;
		if (quiz == 0) {
			for (int j = 0; j < girl.size(); j++) {
				if (name == girl[j][0]) {
					for (int k = 1; k < girl[j].size(); k++) {
						ans.push_back(girl[j][k]);
					}
				}
			}
		}
		else {
			for (int j = 0; j < girl.size(); j++) {
				for (int k = 1; k < girl[j].size(); k++) {
					if (name == girl[j][k]) {
						ans.push_back(girl[j][0]);
					}
				}
			}
		}
	}

	// output
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}