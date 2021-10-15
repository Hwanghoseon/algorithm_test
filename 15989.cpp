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

const int MAX = 1e4 + 1;

int dp[MAX];

void func() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i < MAX; i++)
		dp[i] = dp[i - 3] + (i / 2) + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int T;
	cin >> T;

	while (T--) {
		int num;
		cin >> num;

		cout << dp[num] << "\n";
	}

	return 0;
}
