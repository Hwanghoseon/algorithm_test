#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000 + 1;

int node[MAX];
bool visit[MAX];
vector<int> con[MAX];

int N, M;
int cnt = 0;

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = true;

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		for (int i = 0; i < con[currentNode].size(); i++) {
			int nextNode = con[currentNode][i];

			if (!visit[nextNode]) {
				q.push(nextNode);
				visit[nextNode] = true;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		con[x].push_back(y);
		con[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		sort(con[i].begin(), con[i].end());
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
