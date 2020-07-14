#include<iostream>

using namespace std;

const int MAX = 10000 + 1;

int n, k;
int coin[100];
int dp[MAX];

int func() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	dp[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];

	return dp[k];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << func();

	return 0;
}
