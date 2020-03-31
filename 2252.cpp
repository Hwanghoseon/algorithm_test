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
		int first, second;
		cin >> first >> second;

		graph[first].push_back(second);
		inDegree[second]++;
	}
}

void bfs() {
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (!inDegree[i])
			q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			inDegree[graph[cur][i]]--;

			if (!inDegree[graph[cur][i]])
				q.push(graph[cur][i]);
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
