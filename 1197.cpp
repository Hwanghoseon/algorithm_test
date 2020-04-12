#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 10000 + 1;

int V, E, A, B, C;
bool visit[MAX];
vector<pair<int, int>> edge[MAX];

void input() {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;

		edge[A].push_back(make_pair(C, B));
		edge[B].push_back(make_pair(C, A));
	}
}

long long prim() {
	long long ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visit[cur.second]) continue;

		visit[cur.second] = true;

		ans += cur.first;

		for (int i = 0; i < edge[cur.second].size(); i++)
			if (!visit[edge[cur.second][i].second])
				pq.push(edge[cur.second][i]);
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << prim();

	return 0;
}
