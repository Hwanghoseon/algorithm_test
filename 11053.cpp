#include<iostream>

using namespace std;

const int MAX = 1000 + 1;

int list[MAX];
int dp[MAX];
int n;

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> list[i];
}

void func() {
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;

		for (int j = 1; j < i; j++) {
			if (list[i] > list[j] && dp[i] < list[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	int maxCnt = 0;
	for (int i = 1; i <= n; i++)
		if (maxCnt < dp[i])
			maxCnt = dp[i];
	
	cout << maxCnt << "\n";

	return 0;
}
