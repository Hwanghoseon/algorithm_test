#include<iostream>

using namespace std;

const int MOD = 10007;
const int MAX  = 1000 + 1;

int n;
int dp[MAX] = { 0, };

void func() {
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	func();

	cout << dp[n] % MOD;

	return 0;
}
