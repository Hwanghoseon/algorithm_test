#include<iostream>

using namespace std;

const int MAX = 15 + 1;

int dp[MAX][MAX];	// 첫번째는 상담횟수 두번째는 마지막 상담
int list[2][MAX];
int n;
int maxCost = 0;

void input() {
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 2; j++)
			cin >> list[j][i];
}

void func() {
	for (int i = 1; i <= n; i++) {
		dp[1][i] = list[1][i];
		
		if (maxCost < dp[1][i] && i + list[0][i]  - 1 <= n) maxCost = dp[1][i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = j + list[0][j]; k <= n; k++) {
				if (k + list[0][k] - 1 > n) continue;
				else {
					dp[i][k] = (dp[i][k] > dp[i - 1][j] + list[1][k] ? dp[i][k] : dp[i - 1][j] + list[1][k]);
					if (dp[i][k] > maxCost) maxCost = dp[i][k];
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	input();
	
	func();

	cout << maxCost;
	
	return 0;
}
