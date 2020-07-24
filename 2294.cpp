#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

const int MAX = INT_MAX;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int dp[100000 + 1];
	int coin[100];

	dp[0] = 0;
	for (int i = 1; i <= k; i++)
		dp[i] = MAX;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];

		dp[coin[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i] == 1) break;
			else if (i - coin[j] < 0 || dp[i - coin[j]] == MAX) continue;
			else dp[i] = min(dp[i], 1 + dp[i - coin[j]]);
		}
	}

	if (dp[k] == MAX) cout << "-1";
	else cout << dp[k] << "\n";

	return 0;
}
