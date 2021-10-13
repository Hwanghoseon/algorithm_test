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

const int MAX = 100 + 1;

int N, cnt = 0;
int node[MAX];
bool visited[MAX];
bool cycle[MAX];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> node[i];

		if (node[i] == i) {
			cnt++;

			visited[i] = cycle[i] = true;
		}
	}
}

bool dfs(int idx, int start) {
	if (visited[idx]) return false;

	visited[idx] = true;

	if (idx == start || dfs(node[idx], start)) {
		cnt++;
		cycle[idx] = true;

		return true;
	}

	return false;
}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			visited[j] = cycle[j];

		dfs(node[i], i);
	}

	cout << cnt << "\n";
	for (int i = 1; i <= N; i++)
		if (cycle[i])
			cout << i << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
