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

const int MAX = 30 + 1;

int D, K;
int dp[MAX];

void func() {
	dp[3] = dp[4] = 1;

	for (int i = 5; i < MAX; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
}

void solution() {
	for (int i = 1; i < 1e5 + 1; i++) {
		int temp = K - dp[D] * i;

		if (temp % dp[D + 1] == 0) {
			cout << i << "\n" << temp / dp[D + 1];

			return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	cin >> D >> K;

	solution();

	return 0;
}
