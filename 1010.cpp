#include<iostream>

using namespace std;

const int MAX = 30;

int dp[MAX][MAX];
int n, m;

void func() {
	// 서쪽 사이트의 개수가 1개일 경우
	for (int i = 1; i < MAX; i++)
		dp[1][i] = i;

	for (int i = 1; i < MAX - 1; i++) {
		int sum = 0;
		for (int j = i; j < MAX - 1; j++) {
			sum += dp[i][j];

			dp[i + 1][j + 1] = sum;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	func();

	while (T--) {
		cin >> n >> m;

		cout << dp[n][m] << "\n";
	}

	return 0;
}
