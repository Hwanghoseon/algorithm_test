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

const int MAX = 33333 + 1;
const int MOD = 1e9 + 9;

long long dp[MAX];

void func() {
	dp[2] = 2;

	for (int i = 3; i <= MAX; i++)
		dp[i] = (dp[i - 1] * 3) % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int N;
	cin >> N;

	cout << dp[N];

	return 0;
}
