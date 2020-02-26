#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100000;

vector<int> list;
vector<int> dp;
int n;

void input() {
	cin >> n;

	list.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; i++)
		cin >> list[i];
}

int desc(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	dp[0] = list[0];

	for (int i = 1; i < n; i++) {
		if (dp[i - 1] + list[i] > list[i])
			dp[i] = dp[i - 1] + list[i];
		else
			dp[i] = list[i];
	}

	sort(dp.begin(), dp.end(), desc);

	cout << dp[0];

	return 0;
}
