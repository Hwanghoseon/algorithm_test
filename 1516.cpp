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

const int MAX = 500 + 1;

int N;
vector<int> graph[MAX];
int inDegree[MAX];
int sec[MAX];
int result[MAX];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int value;
		cin >> value;

		sec[i] = value;

		int cnt = 0;

		while (true) {
			int temp;
			cin >> temp;

			if (temp == -1) break;

			graph[temp].push_back(i);

			cnt++;
		}

		inDegree[i] = cnt;
	}
}

void bfs() {
	queue<pair<int, int>> q;	// 현재 건물, 이전에 지어야하는 건물

	for (int i = 1; i <= N; i++)
		if (!inDegree[i]) {
			q.push({ i, 0 });

			result[i] = sec[i];
		}

	while (!q.empty()) {
		int cur = q.front().first;
		int before = q.front().second;
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			inDegree[graph[cur][i]]--;

			result[graph[cur][i]] = max(result[graph[cur][i]], sec[graph[cur][i]] + result[cur]);

			if (!inDegree[graph[cur][i]])
				q.push({ graph[cur][i], cur });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	bfs();

	for (int i = 1; i <= N; i++)
		cout << result[i] << "\n";

	return 0;
} 
