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

const int MAX = 1e6;

long long N, M;
long long list[MAX];
long long rest[1000];	// 나머지 갯수

void input() {
	cin >> N >> M;

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;

		sum += temp;

		list[i] = sum;
	}
}

long long solution() {
	for (int i = 0; i < N; i++)
		rest[list[i] % M]++;

	long long ans = rest[0];

	for (int i = 0; i < M; i++) {
		if (rest[i] < 2) continue;

		ans += rest[i] * (rest[i] - 1) / 2;
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
