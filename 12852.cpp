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

int X;
int dp[MAX];
int before[MAX];

void func() {
	dp[1] = 0;
	
	for (int i = 1; i < MAX; i++) {
		dp[i] = i - 1;

		before[i] = i - 1;
	}

	for (int i = 2; i < MAX; i++) {
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;

			before[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
			dp[i] = dp[i / 2] + 1;

			before[i] = i / 2;
		}

		if (dp[i] > dp[i - 1] + 1) {
			dp[i] = dp[i - 1] + 1;

			before[i] = i - 1;
		}
	}
}

void solution() {
	cout << dp[X] << "\n";

	int cur = X;
	while (true) {
		cout << X << " ";

		if (X == 1) break;

		X = before[X];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	cin >> X;

	solution();

	return 0;
}
