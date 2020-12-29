#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>

using namespace std;

const int MOD = 1000000007;
const int MAX = 8;

long long dp[MAX];
int D;

void sumDp(int D) {
	long long temp[MAX];

	while (D--) {
		temp[0] = dp[1] + dp[2];
		temp[1] = dp[0] + dp[2] + dp[3];
		temp[2] = dp[0] + dp[1] + dp[3] + dp[5];
		temp[3] = dp[1] + dp[2] + dp[4] + dp[5];
		temp[4] = dp[3] + dp[5] + dp[7];
		temp[5] = dp[2] + dp[3] + dp[4] + dp[6];
		temp[6] = dp[5] + dp[7];
		temp[7] = dp[4] + dp[6];

		for (int i = 0; i < MAX; i++)
			dp[i] = temp[i] % MOD;
	}
}

long long func() {
	cin >> D;

	dp[0] = 1;

	sumDp(D);

	return dp[0];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << func();

	return 0;
}
