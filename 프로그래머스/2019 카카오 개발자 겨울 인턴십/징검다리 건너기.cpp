#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int max = 0;
	/* ¡�˴ٸ� �Ѱ� �ִ� ��� */
	if (stones.size() == 1) {
		answer = stones[0];
		return answer;
	}
	/* ���ҵ��� �� �� max ���ϱ� */
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] > max) {
			max = stones[i];
		}
	}
	int num = max / 2; // �ִ밪���� �� ���� ������ ����
	int left = 1; // ����
	int right = max; // ������
	bool flag; // k���� ���ӵ� ���Ұ� �ִ���
	while (1) {
		int cnt = 0; // ���ӵ� ���� ���� ����
		int temp = 0; // num�̶� ���ϱ� ���� ���
		flag = false;
		for (int i = 0; i < stones.size(); i++) {
			/* num���� �۰ų� ���� ���ӵ� �����̸� */
			if (stones[i] <= num) {
				cnt++;
			}
			/* �ƴϸ� ���� */
			else {
				cnt = 0;
			}
			/* k���� ���ӵ� ���Ұ� ������ Ż�� */
			if (cnt == k) {
				flag = true;
				break;
			}
		}
		/* k���� ���ӵ� ���Ұ� ������ */
		if (flag) {
			temp = num - ((num - left) / 2);
			right = num;
			answer = num; // ���� �� ����
		}
		else {
			temp = num + ((right - num) / 2);
			left = num;
		}
		/* ���̻� �� ���� ������ */
		if (temp == num) {
			return answer;
		}
		/* ���ο� num ������Ʈ */
		num = temp;
	}
}

int main() {
	//cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << endl;
	cout << solution({ 2 }, 1) << endl;
	return 0;
}