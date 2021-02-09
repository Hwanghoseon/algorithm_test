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

using namespace std;

const int MAX = 40 + 1;

int dp[MAX];
int N, M;
vector<int> list;

void input() {
	cin >> N >> M;

	int before = 0;
	int temp;

	while (M--) {
		cin >> temp;

		list.push_back(temp - before - 1);

		before = temp;
	}

	list.push_back(N - before);
}

void func() {
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < MAX; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
}

int solution() {
	int result = 1;

	for (int i = 0; i < list.size(); i++)
		result *= dp[list[i]];

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	input();

	cout << solution();

	return 0;
}
