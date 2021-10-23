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

const int MAX = 1e4 + 1;

int money, N;
int dp[MAX];
vector<pair<int, int>> coin;

void input() {
	cin >> money >> N;

	for (int i = 0; i < N; i++) {
		int price, num;
		cin >> price >> num;

		coin.push_back({ price, num });
	}

	sort(coin.begin(), coin.end());
}

int solution() {
	dp[0] = 1;

	for (int i = 0; i < coin.size(); i++) {
		for (int j = money; j > 0; j--) {
			int sum = 0;

			for (int k = 0; k < coin[i].second; k++) {
				sum += coin[i].first;

				if (j - sum >= 0 && dp[j - sum])
					dp[j] += dp[j - sum];
			}
		}
	}

	return dp[money];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
