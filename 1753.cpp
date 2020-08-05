#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

const int MAX = 20000 + 1;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int V, E, K;
vector<pair<int, int>> graph[MAX];
vector<int> node(MAX);

void input() {
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		graph[from].push_back(make_pair(value, to));
	}

	fill(node.begin(), node.end(), INT_MAX);
}

void func() {
	pq.push(make_pair(0, K));
	node[K] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (node[idx] != dist) continue;

		for (int i = 0; i < graph[idx].size(); i++) {
			int cost = graph[idx][i].first;
			int nidx = graph[idx][i].second;

			if (node[nidx] > cost + dist) {
				node[nidx] = cost + dist;
				pq.push(make_pair(node[nidx], nidx));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	for (int i = 1; i <= V; i++) {
		if (node[i] == INT_MAX) cout << "INF\n";
		else cout << node[i] << "\n";
	}

	return 0;
}
