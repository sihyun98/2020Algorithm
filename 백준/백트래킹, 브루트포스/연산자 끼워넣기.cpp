#include <iostream>
#include <cstdio>

int number[100] = { 0, };
int mini = 1000000001;
int maxi = -1000000001;

void cal(int plus, int minus, int mul, int div, int cnt, int ch, int cur) {
	if (cnt == 0) {
		if (cur < mini) {
			mini = cur;
		}
		if (cur > maxi) {
			maxi = cur;
		}
		return;
	}
	if (plus > 0) {
		cal(plus - 1, minus, mul, div, cnt - 1, ch + 1, cur + number[ch]);
	}
	if (minus > 0) {
		cal(plus, minus - 1, mul, div, cnt - 1, ch + 1, cur - number[ch]);
	}
	if (mul > 0) {
		cal(plus, minus, mul - 1, div, cnt - 1, ch + 1, cur * number[ch]);
	}
	if (div > 0) {
		cal(plus, minus, mul, div - 1, cnt - 1, ch + 1, cur / number[ch]);
	}
}

int main() {
	int N = 0, plus = 0, minus = 0, mul = 0, div = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}
	scanf("%d %d %d %d", &plus, &minus, &mul, &div);

	int temp = plus + minus + mul + div;
	cal(plus, minus, mul, div, temp, 1, number[0]);

	printf("%d\n", maxi);
	printf("%d", mini);
	return 0;
}