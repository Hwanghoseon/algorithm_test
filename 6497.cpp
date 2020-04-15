#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 200000 + 1;

int n, m;
vector<pair<int, int>> house[MAX];
bool visit[MAX];
int start;
int total;

void input() {
	cin >> n >> m;

	if (n == 0 && m == 0) exit(0);

	total = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		house[a].push_back(make_pair(c, b));
		house[b].push_back(make_pair(c, a));
		
		total += c;
		start = a;
	}
}

int func() {
	int ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visit[cur.second]) continue;

		visit[cur.second] = true;

		ans += cur.first;

		for (int i = 0; i < house[cur.second].size(); i++)
			if (!visit[house[cur.second][i].second])
				pq.push(house[cur.second][i]);
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		input();

		cout << total - func() << "\n";

		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++)
			house[i].clear();
	}

	return 0;
}
