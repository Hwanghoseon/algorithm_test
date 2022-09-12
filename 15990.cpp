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

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 9;

int dp[MAX][4];	// 끝자리 수의 따른 합의 갯수

void func() {
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;

	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;


	for (int i = 4; i < MAX; i++)
		for (int j = 1; j < 4; j++)
			for (int k = 1; k < 4; k++)
				if (k != j) {
					dp[i][j] += dp[i - j][k];

					dp[i][j] %= MOD;
				}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int sum = 0;

		for (int i = 1; i < 4; i++) {
			sum += dp[N][i];

			sum %= MOD;
		}

		cout << sum << "\n";
	}

	return 0;
}
