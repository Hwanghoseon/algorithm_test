#include<iostream>
#include<vector>

using namespace std;

const int MAX = 90 + 1;

vector<long long> dp;
int n;

void func() {
	dp.resize(MAX);

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	func();

	cout << dp[n];

	return 0;
}
