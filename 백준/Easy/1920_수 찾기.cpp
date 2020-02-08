#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	// initialize variables
	int n, m;

	// input
	scanf("%d", &n);
	int *narr = new int[n];
	// save numbers to array 'narr'
	for (int i = 0; i < n; i++) {
		scanf("%d", &narr[i]);
	}
	scanf("%d", &m);
	int *marr = new int[m];
	// save numbers to array 'marr'
	for (int i = 0; i < m; i++) {
		scanf("%d", &marr[i]);
	}

	// sort array 'narr' in ascending order
	sort(narr, narr + n);

	// output
	for (int i = 0; i < m; i++) {
		// if found
		if (binary_search(narr, narr+n, marr[i])) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}