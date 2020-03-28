#include<iostream>

using namespace std;

const int MAX = 100000000;

int num[9];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	num[1] = 9;
	num[9] = 1;
	int sum = 9;
	for (int i = 2; i <= 8; i++) {
		int temp = 1;
		for (int j = 1; j <= i; j++)
			temp *= 10;

		num[i] = temp - 1 - sum;

		sum += num[i];
	}

	int n;
	cin >> n;

	int cnt = 0;
	int x = 0;	// 시도 횟수
	sum = 0;

	for (int i = 1; i <= 9; i++) {
		if (sum + num[i] <= n) {
			cnt += (num[i] * i);
			sum += num[i];
		}
		else {
			cnt += (i * (n - sum));
			break;
		}
	}

	cout << cnt;

	return 0;
}
