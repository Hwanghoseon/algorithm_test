#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 1000 + 1;

int n, m;
int inDegree[MAX];
vector<int > graph[MAX];
vector<int> result;

void input() {
	cin >> n >> m;

	int list[100];
	while (m--) {
		int sz;		// 담당한 가수의 수
		cin >> sz;

		for (int i = 0; i < sz; i++)
			cin >> list[i];

		for (int i = 0; i < sz - 1; i++) {
			graph[list[i]].push_back(list[i + 1]);
			inDegree[list[i + 1]]++;
		}
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

		result.push_back(cur);

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

	if (result.size() == n)
		for (int i = 0; i < n; i++)
			cout << result[i] << "\n";
	else cout << "0";

	return 0;
}
