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

const int MAX = 1e5;

int N;
vector<int> list;
int dp[MAX][2];	// 연속된 합, 제거 여부

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

int solution() {
	dp[0][0] = dp[0][1] = list[0];
	int ans = list[0];

	for (int i = 1; i < N; i++) {
		// 수를 제거하지 않을 경우
		if (dp[i - 1][1] + list[i] < list[i])
			dp[i][1] = list[i];
		else
			dp[i][1] = dp[i - 1][1] + list[i];

		if (dp[i - 1][0] + list[i] < list[i])
			dp[i][0] = list[i];
		else
			dp[i][0] = dp[i - 1][0] + list[i];

		// 수를 제거하는 경우
		dp[i][0] = max(dp[i][0],dp[i - 1][1]);
		ans = max(ans, dp[i][0]);
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
