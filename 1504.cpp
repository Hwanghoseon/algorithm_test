#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int MAX = 800 + 1;
const int INF = 987654321;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graph[MAX];
vector<int> node(MAX);
int N, E, V1, V2;

void input() {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		graph[from].push_back(make_pair(value, to));
		graph[to].push_back(make_pair(value, from));
	}

	cin >> V1 >> V2;
}

vector<int> dijkstra(int start, int end) {
	fill(node.begin(), node.end(), INF);

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
	
	
	return node;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	vector<int> temp1 = dijkstra(1, N);
	vector<int> temp2 = dijkstra(V1, N);
	vector<int> temp3 = dijkstra(V2, N);

	int result;

	result = min(temp1[V1] + temp2[V2] + temp3[N], temp1[V2] + temp3[V1] + temp2[N]);

	if (result >= INT_MAX || result < 0)
		result = -1;

	cout << result;

	return 0;
}
