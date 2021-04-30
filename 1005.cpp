#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<climits>

using namespace std;

const int MAX = 1000 + 1;

int N, K;
vector<int> graph[MAX];
int inDegree[MAX];
int sec[MAX];
int result[MAX];

void input() {
	cin >> N >> K;

	for (int i = 0; i < MAX; i++)
		graph[i].clear();

	for (int i = 1; i <= N; i++)
		result[i] = 0;

	for (int i = 1; i <= N; i++)
		cin >> sec[i];

	for (int i = 0; i < K; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		inDegree[to]++;
	}
}

int bfs(int target) {
	queue<int> q;

	for(int i = 1; i <= N; i++)
		if (!inDegree[i]) {
			q.push(i);

			result[i] = sec[i];
		}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			inDegree[next]--;

			result[next] = max(result[next], result[cur] + sec[next]);

			if (!inDegree[next])
				q.push(next);
		}
	}

	return result[target];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();

		int target;
		cin >> target;

		cout << bfs(target) << "\n";
	}

	return 0;
}
