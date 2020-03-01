#include<iostream>

using namespace std;

const int MAX = 100000 + 1;

int n;
int list[3][MAX];
int dp[2][MAX];

void input() {
	cin >> n;

	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> list[i][j];
}

void func() {
	for (int i = 1; i <= n; i++) {
		if (n == 1) {
			dp[1][1] = list[1][1];
			dp[2][1] = list[2][1];
		}
		else if (n == 2) {
			dp[1][2] = list[1][2] + dp[2][1];
			dp[2][2] = list[2][2] + dp[1][1];
		}
		else {
			dp[1][i] = list[1][i] + dp[2][i - 1] > list[1][i] + dp[2][i - 2] ? list[1][i] + dp[2][i - 1] : list[1][i] + dp[2][i - 2];
			dp[2][i] = list[2][i] + dp[1][i - 1] > list[2][i] + dp[1][i - 2] ? list[2][i] + dp[1][i - 1] : list[2][i] + dp[1][i - 2];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();
		
		func();

		cout << (dp[1][n] > dp[2][n] ? dp[1][n] : dp[2][n]) << "\n";
	}

	return 0;
}
