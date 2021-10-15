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
const int MOD = 1e9;

int N;
int dp[MAX];

void func() {
	dp[0] = 1;

	for (int i = 0; i < 20; i++) {
		int temp = pow(2, i);

		for (int j = temp; j < MAX; j++) {
			dp[j] += dp[j - temp];

			dp[j] %= MOD;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	func();

	cout << dp[N];

	return 0;
}
