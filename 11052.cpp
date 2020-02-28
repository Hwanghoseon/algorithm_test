#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1000 + 1;

int n;
vector<int> list;
vector<int> dp;

void input() {
	cin >> n;

	list.resize(MAX);
	dp.resize(MAX);

	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
}

void func() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i / 2; j++) {
			int gap = i - j;
			dp[i] = (dp[i] > dp[i - gap] + dp[gap] ? dp[i] : dp[i - gap] + dp[gap]);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	cout << dp[n];

	return 0;
}
