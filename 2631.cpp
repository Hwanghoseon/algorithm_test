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

using namespace std;

const int MAX = 200 + 1;

int N;
int list[MAX];
int dp[MAX];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> list[i];
}

int solution() {
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;

		for (int j = 1; j < i; j++)
			if (list[i] > list[j])
				dp[i] = max(dp[i], dp[j] + 1);
	}

	int ans = 0;

	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[i]);

	return N - ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
