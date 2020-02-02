#include<iostream>

using namespace std;

const int MAX = 40 + 1;

int dp[MAX][2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		dp[0][0] = dp[1][1] = 1;

		for (int i = 2; i < MAX; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
			dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
		}
		cout << dp[n][0] << " " << dp[n][1] << endl;
	}

	return 0;
}
