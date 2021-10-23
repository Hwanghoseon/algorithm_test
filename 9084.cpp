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
int N, money;
vector<int> coin;

void input() {
	cin >> N;

	coin.resize(N);

	for (int i = 0; i < N; i++)
		cin >> coin[i];

	cin >> money;
}

int solution() {
	dp[0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= money; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	return dp[money];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		memset(dp, 0, sizeof(dp));
		coin.clear();

		input();

		cout << solution() << "\n";
	}

	return 0;
}
