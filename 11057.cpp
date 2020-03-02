#include<iostream>

using namespace std;

const int MAX = 1001;
const int MOD = 10007;

int dp[MAX][10];

void func(int n) {
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;		// 한자리 숫자라면 1개

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= MOD;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	func(num);

	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += dp[num][i];

	cout << sum % MOD;

	return 0;
}
