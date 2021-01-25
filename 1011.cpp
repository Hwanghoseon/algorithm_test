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

const int MAX = 100000;

long long dp[MAX];

void func() {
	for (long long i = 1; i < MAX; i++)
		dp[i] = dp[i - 1] + i * 2;
}

int solution(int x, int y) {
	long long temp = y - x;
	int cnt = 0;
	long long sum = 0;
	int idx;

	for (int i = 0; i < MAX; i++) {
		if (temp < dp[i]) 
			break;

		idx = i;
	}

	sum = dp[idx];
	cnt = idx * 2;

	// idx + 1이 가능한지 확인
	if (sum + idx + 1 <= temp) {
		idx++;
		sum += idx;
		cnt++;
	}

	temp -= sum;

	if (temp % idx == 0) cnt += (temp / idx);
	else cnt += (temp / idx + 1);

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	func();

	while (T--) {
		int x, y;
		cin >> x >> y;
		
		cout << solution(x, y) << "\n";
	}

	return 0;
}
