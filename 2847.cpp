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

int N;
vector<pair<int, int>> list;

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;

		list[i - 1] = { i, temp };
	}
}

int solution() {
	int cnt = 0;

	sort(list.begin(), list.end());

	int before = list[N - 1].second;
	for (int i = N - 2; i >= 0; i--) {
		if (list[i].second < before) {
			before = list[i].second;
		}
		else {
			before--;

			cnt += (list[i].second - before);
		}
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
