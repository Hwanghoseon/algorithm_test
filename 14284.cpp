#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

const int MAX = 5000 + 1;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// value, to
vector<pair<int, int>> graph[MAX];
vector<int> node(MAX);
vector<int> pre(MAX);
int n, m;
int startPoint, endPoint;

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		graph[from].push_back(make_pair(value, to));
		graph[to].push_back(make_pair(value, from));
	}

	fill(node.begin(), node.end(), INT_MAX);

	cin >> startPoint >> endPoint;
}

void func() {
	pq.push(make_pair(0, startPoint));
	node[startPoint] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (node[idx] != dist) continue;

		for (int i = 0; i < graph[idx].size(); i++) {
			int nextDist = graph[idx][i].first;
			int nextIdx = graph[idx][i].second;

			if (node[nextIdx] > dist + nextDist) {
				node[nextIdx] = dist + nextDist;

				pq.push(make_pair(node[nextIdx], nextIdx));
				pre[nextIdx] = idx;
			}
		}
	}

	cout << node[endPoint];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	return 0;
}
