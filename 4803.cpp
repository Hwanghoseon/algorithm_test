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

const int MAX = 500 + 1;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
bool isGraph = true;

void dfs(vector<int> graph[], int n, int before) {
	if (visited[n]) return;

	visited[n] = true;

	if (!isGraph) return;

	for (int i = 0; i < graph[n].size(); i++) {
		if (graph[n][i] == before) continue;
		// cycle 생길 경우
		if (visited[graph[n][i]]) isGraph = false;
		if (!visited[graph[n][i]])
			dfs(graph, graph[n][i], n);
	}
}

void printResult(int cnt, int num) {
	cout << "Case " << num << ": ";

	if (cnt == 1)
		cout << "There is one tree." << "\n";
	else if (cnt == 0)
		cout << "No trees." << "\n";
	else
		cout << "A forest of " << cnt << " trees." << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;

	while (true) {
		cin >> N >> M;

		if (N == 0 && M == 0) break;

		vector<int> graph[MAX];

		for (int i = 0; i < M; i++) {
			int from, to;
			cin >> from >> to;

			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		memset(visited, false, sizeof(visited));

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				isGraph = true;

				dfs(graph, i, 0);

				if(isGraph) cnt++;
			}
		}

		printResult(cnt, t);
		t++;
	}

	return 0;
}
