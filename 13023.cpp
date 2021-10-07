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

const int MAX = 2000;

int N, M;
vector<int> graph[MAX];
bool visited[MAX], isSatisfied = false;

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}
}

void dfs(int node, int cnt) {
	visited[node] = true;

	if (cnt == 5) {
		isSatisfied = true;

		return;
	}

	for (int i = 0; i < graph[node].size(); i++)
		if (!visited[graph[node][i]])
			dfs(graph[node][i], cnt + 1);

	visited[node] = false;
}

int solution() {
	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));

		dfs(i, 1);

		if (isSatisfied)
			return 1;
	}

	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
