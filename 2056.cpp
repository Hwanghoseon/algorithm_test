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

const int MAX = 10000 + 1;

int N;
vector<int> graph[MAX];
int inDegree[MAX];
int sec[MAX];
int result[MAX];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> sec[i];

		int M;
		cin >> M;

		inDegree[i] = M;

		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;

			graph[temp].push_back(i);
		}
	}
}

int bfs() {
	queue<int> q;

	for (int i = 1; i <= N; i++)
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

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, result[i]);

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << bfs();

	return 0;
}
