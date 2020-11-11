#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int MAX = 1000 + 1;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graph[MAX];
vector<int> node(MAX);
int N, M;
int startNode, endNode;

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		graph[from].push_back(make_pair(value, to));
	}

	cin >> startNode >> endNode;

	fill(node.begin(), node.end(), INT_MAX);
}

void diljstra(int start) {
	pq.push(make_pair(0, start));
	node[start] = 0;

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
			}
		}
	}

	cout << node[endNode];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	diljstra(startNode);

	return 0;
}
