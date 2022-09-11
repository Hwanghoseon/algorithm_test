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

const int MAX = 1e3 + 1;

int N;
int list[MAX];
int dp[MAX];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> list[i];
}

int solution() {
	int maxNum = 0;

	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], list[i]);

		for (int j = 1; j < i; j++)
			if (list[j] < list[i] && dp[i] < dp[j] + list[i])
				dp[i] = dp[j] + list[i];

		maxNum = max(maxNum, dp[i]);
	}

	return maxNum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
