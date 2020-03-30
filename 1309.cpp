#include<iostream>

using namespace std;

const int MAX = 100000 + 1;
const int MOD = 9901;

int dp[MAX];
int n;

void func() {
	dp[1] = 3;
	dp[2] = 7;
	
	for (int i = 3; i <= n; i++)
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	func();

	cout << dp[n];

	return 0;
}
