#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

const int MAX = 300000 + 1;

int N, M, K, startPoint;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// value, to
vector<pair<int, int>> graph[MAX];	// value, to
vector<int> node(MAX);
vector<int> pre(MAX);

void input() {
	cin >> N >> M >> K >> startPoint;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(make_pair(1, to));
	}

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
			int nextDist = graph[idx][i].first;
			int nextIdx = graph[idx][i].second;

			if (node[nextIdx] > dist + nextDist) {
				node[nextIdx] = dist + nextDist;

				pq.push(make_pair(node[nextIdx], nextIdx));
				pre[nextIdx] = idx;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (node[i] == K) {
			cout << i << "\n";
			cnt++;
		}
	}

	if (!cnt) cout << "-1";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	return 0;
}
