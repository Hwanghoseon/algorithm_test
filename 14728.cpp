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

const int MAX = 100 + 1;

int N, T;
int weight[MAX];
int value[MAX];
int dp[MAX][10000 + 1];

void input() {
	cin >> N >> T;

	for (int i = 1; i <= N; i++)
		cin >> weight[i] >> value[i];
}

int solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (j >= weight[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[N][T];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();

	cout << solution();

	return 0;
}
