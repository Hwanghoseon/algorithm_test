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

const int MAX = 50000 + 1;

int N;
int dp[MAX];

void func() {
	int maxNum = sqrt(MAX);

	for (int i = 1; i < MAX; i++)
		dp[i] = i;

	for (int i = 2; i < maxNum; i++) {
		int temp = pow(i, 2);

		for (int j = temp; j < MAX; j++) {
			dp[j] = min(dp[j], dp[j - temp] + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	cin >> N;

	cout << dp[N];

	return 0;
}
