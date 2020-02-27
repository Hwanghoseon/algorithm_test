#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1000 + 1;
const int MOD = 10007;

vector<int> dp;
int n;

void func() {
	dp.resize(MAX);

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (i % 2)
			dp[i] = (dp[i - 1] * 2 - 1) % MOD;
		else
			dp[i] = (dp[i - 1] * 2 + 1) % MOD;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	func();

	cout << dp[n];

	return 0;
}
