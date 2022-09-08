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

int N, M;
map<string, int> list;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;

		list[st] = 1;
	}
}

int solution() {
	int ans = 0;

	for (int i = 0; i < M; i++) {
		string st;
		cin >> st;

		if (list[st])
			ans++;
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
