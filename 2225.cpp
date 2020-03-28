#include<iostream>

using namespace std;

const int MOD = 1000000000;
const int MAX = 200 + 1;

long long dp[MAX][MAX];

int n, k;

void func() {
	for (int i = 1; i <= k; i++)
		dp[1][i] = i;

	for (int i = 2; i <= n; i++) {
		long long sum = 0;
		for (int j = 1; j <= k; j++) {
			sum = (sum + dp[i - 1][j]) % MOD;

			dp[i][j] = sum;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	func();

	cout << dp[n][k] % MOD;

	return 0;
}
