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

int N;
int dp[MAX];

void func() {
	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i < MAX; i += 2)
		dp[i] = dp[i - 2] * 4 - dp[i - 4];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	cin >> N;

	cout << dp[N];

	return 0;
}
