#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

const int MAX = 1000 + 1;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// value, to
int n, m;
int startPoint, endPoint;	// 출발점, 도착점
vector<pair<int, int>> graph[MAX];	// value, to
vector<int> node(MAX);
vector<int> pre(MAX);

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, value;

		cin >> from >> to >> value;

		graph[from].push_back(make_pair(value, to));
	}
	cin >> startPoint >> endPoint;

	fill(node.begin(), node.end(), INT_MAX);
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
			int cost = graph[idx][i].first;
			int nidx = graph[idx][i].second;

			if (node[nidx] > cost + dist) {
				node[nidx] = cost + dist;
				pq.push(make_pair(node[nidx], nidx));
				pre[nidx] = idx;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	cout << node[endPoint] << "\n";

	vector<int> path;
	int cur = endPoint;

	while (cur != startPoint) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);

	reverse(path.begin(), path.end());

	cout << path.size() << "\n";

	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";

	return 0;
}
