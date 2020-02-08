#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	// initialize variables
	int n, m, red, green, blue, sum = 0;

	// input
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// input
			scanf("%d", &red);
			scanf("%d", &green);
			scanf("%d", &blue);

			// calculate RGB sum
			sum = 2126 * red + 7152 * green + 722 * blue;
			if (sum < 510000) {
				printf("#");
			}
			else if (sum < 1020000) {
				printf("o");
			}
			else if (sum < 1530000) {
				printf("+");
			}
			else if (sum < 2040000) {
				printf("-");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}