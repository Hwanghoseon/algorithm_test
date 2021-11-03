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

const int MAX = 1000;
const int INF = 1e8;
int N;
string input;
int dp[MAX];

bool isExist(int x, int y) {
	if (input[x] == 'B' && input[y] == 'O') return true;
	if (input[x] == 'O' && input[y] == 'J') return true;
	if (input[x] == 'J' && input[y] == 'B') return true;

	return false;
}

int func() {
	for (int i = 1; i < MAX; i++)
		dp[i] = INF;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (!isExist(j, i)) continue;

			dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
		}
	}

	if (dp[N - 1] == INF) dp[N - 1] = -1;

	return dp[N - 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> input;

	cout << func();

	return 0;
}
