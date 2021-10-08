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

int N, M, cnt = 0;
vector<int> list;

void input() {
	cin >> N >> M;

	list.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> list[i];

		if (list[i] < 0)
			cnt++;
	}

	sort(list.begin(), list.end());
}

int solution() {
	int len = 0;

	// 음수 좌표의 책
	for (int i = 0; i < cnt; i += M)
		len += abs(list[i] * 2);

	// 양수 좌표의 책
	for (int i = N - 1; i >= cnt; i -= M)
		len += abs(list[i] * 2);

	int temp = max(abs(list[0]), abs(list[N - 1]));

	len -= temp;

	return len;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
