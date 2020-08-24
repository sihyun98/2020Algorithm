#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n = 0, r = 0, c = 0;
	cin >> n >> r >> c;

	int nn = n;
	int ans = 0;

	while (1) {
		if (nn == 0) {
			break;
		}
		nn--;
		if (r < pow(2, nn) && c >= pow(2, nn)) { // 2
			ans += pow(2, nn) * pow(2, nn);
		}
		else if (r >= pow(2, nn) && c < pow(2, nn)) { // 3
			ans += 2 * pow(2, nn) * pow(2, nn);
		}
		else if (r >= pow(2, nn) && c >= pow(2, nn)) { // 4
			ans += 3 * pow(2, nn) * pow(2, nn);
		}
		r %= (int)pow(2, nn);
		c %= (int)pow(2, nn);
	}
	cout << ans << endl;

	return 0;
}