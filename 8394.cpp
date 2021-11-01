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

const int MAX = 1e7 + 1;

int dp[MAX];

void func() {
	dp[0] = dp[1] = 1;
	
	for (int i = 2; i < MAX; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
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
