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
#include<climits>

using namespace std;

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 9;

int dp[MAX];

void func() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < MAX; i++)
		dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}

	return 0;
}
