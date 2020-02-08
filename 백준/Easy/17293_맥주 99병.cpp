#include <iostream>
#include <string>

using namespace std;

int main() {
	// initialize variables
	int n, buy;
	string b = "bottles";

	// input
	cin >> n;
	buy = n;

	// output
	while (n > 0) {
		// when bottle = 1
		if (n == 1) {
			b = "bottle";
		}
		cout << n << " " << b << " of beer on the wall, " << n << " " << b << " of beer." << endl;
		n--;
		// when bottle = 1
		if (n == 1) {
			b = "bottle";
		}
		else if (n == 0) {
			break;
		}
		cout << "Take one down and pass it around, " << n << " " << b << " of beer on the wall." << endl;
		cout << endl;
	}
	// when bottle = 0
	cout << "Take one down and pass it around, no more bottles of beer on the wall." << endl;
	cout << endl;
	cout << "No more bottles of beer on the wall, no more bottles of beer." << endl;
	if (buy == 1) {
		b = "bottle";
	}
	else {
		b = "bottles";
	}
	cout << "Go to the store and buy some more, " << buy << " " << b << " of beer on the wall.";

	return 0;
}