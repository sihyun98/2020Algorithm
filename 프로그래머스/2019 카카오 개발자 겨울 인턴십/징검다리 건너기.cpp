#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int max = 0;
	/* 징검다리 한개 있는 경우 */
	if (stones.size() == 1) {
		answer = stones[0];
		return answer;
	}
	/* 원소들의 값 중 max 구하기 */
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] > max) {
			max = stones[i];
		}
	}
	int num = max / 2; // 최대값에서 반 나눈 값으로 시작
	int left = 1; // 왼쪽
	int right = max; // 오른쪽
	bool flag; // k개의 연속된 원소가 있는지
	while (1) {
		int cnt = 0; // 연속된 원소 세는 변수
		int temp = 0; // num이랑 비교하기 위해 사용
		flag = false;
		for (int i = 0; i < stones.size(); i++) {
			/* num보다 작거나 같은 연속된 숫자이면 */
			if (stones[i] <= num) {
				cnt++;
			}
			/* 아니면 리셋 */
			else {
				cnt = 0;
			}
			/* k개의 연속된 원소가 있으면 탈출 */
			if (cnt == k) {
				flag = true;
				break;
			}
		}
		/* k개의 연속된 원소가 있으면 */
		if (flag) {
			temp = num - ((num - left) / 2);
			right = num;
			answer = num; // 현재 답 저장
		}
		else {
			temp = num + ((right - num) / 2);
			left = num;
		}
		/* 더이상 갈 곳이 없으면 */
		if (temp == num) {
			return answer;
		}
		/* 새로운 num 업데이트 */
		num = temp;
	}
}

int main() {
	//cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << endl;
	cout << solution({ 2 }, 1) << endl;
	return 0;
}