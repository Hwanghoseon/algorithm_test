#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 300 + 1;

int n;
vector<int> stair(MAX);	// 각 계단의 점수를 표시하기 위한 벡터
vector<int> Dp(MAX);	// 각 계단까지의 점수의 합을 표시하기 위한 벡터

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	for (int i = 1; i <= 3; i++) {
		if (i != 3)
			Dp[i] = Dp[i - 1] + stair[i];
		else
			Dp[i] = max(Dp[i - 2] + stair[i], stair[i - 1] + stair[i]);
	}

	// 현재의 계단 전을 밟았을때와 그렇지 않을 경우로 나눠서 생각한다.
	for (int i = 4; i <= n; i++)
		Dp[i] = max(Dp[i - 2] + stair[i], Dp[i - 3] + stair[i - 1] + stair[i]);

	cout << Dp[n];

	return 0;
}
