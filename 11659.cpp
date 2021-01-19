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

const int MAX = 100000 + 1;

int sum[MAX];
int N, M;

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;

		sum[i] = sum[i - 1] + temp;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	while (M--) {
		int from, to;
		cin >> from >> to;

		int result = sum[to] - sum[from - 1];

		cout << result << "\n";
	}

	return 0;
}
