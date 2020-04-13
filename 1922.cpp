#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 1000 + 1;

int n, m;
vector<pair<int, int>> computer[MAX];
bool visit[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		computer[a].push_back(make_pair(c, b));
		computer[b].push_back(make_pair(c, a));
	}
}

int prim(int x) {
	int ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visit[cur.second]) continue;

		visit[cur.second] = true;
		ans += cur.first;

		for (int i = 0; i < computer[cur.second].size(); i++)
			if (!visit[computer[cur.second][i].second])
				pq.push(computer[cur.second][i]);
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << prim(1) << "\n";

	return 0;
}
