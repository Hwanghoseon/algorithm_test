#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 32000 + 1;

int n, m;
int inDegree[MAX];
vector<int> graph[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		inDegree[to]++;
	}
}

void bfs() {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++)
		if (!inDegree[i])
			pq.push(i);

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			inDegree[graph[cur][i]]--;
			if (!inDegree[graph[cur][i]])
				pq.push(graph[cur][i]);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	bfs();

	return 0;
}
