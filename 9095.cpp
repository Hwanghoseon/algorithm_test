#include<iostream>

using namespace std;

const int MAX = 11;

int dp[MAX];

void func() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < MAX; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	func();

	while (T--) {
		int n;
		cin >> n;

		cout << dp[n] << "\n";
	}

	return 0;
}
