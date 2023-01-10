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

int N;
int list[1000 + 1];
int DP[1000 + 1];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> list[i];

		DP[i] = MAX;
	}
}

int solution() {
	DP[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= list[i]; j++) {
			if (DP[i] != MAX)
				DP[i + j] = min(DP[i + j], DP[i] + 1);
		}
	}

	if (DP[N - 1] == MAX) return -1;
	return DP[N - 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
