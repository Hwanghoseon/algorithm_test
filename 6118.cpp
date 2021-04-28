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

const int MAX = 20000 + 1;

int N, M;
vector<int> graph[MAX];
vector<int> result;
bool visited[MAX];
int maxDist = 0;

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}
}

void bfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 거리, 헛간 번호
	pq.push({ 0, 1 });
	visited[1] = true;

	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curX = pq.top().second;
		pq.pop();

		if (curDist == maxDist)
			result.push_back(curX);
		else {
			result.clear();

			result.push_back(curX);

			maxDist = curDist;
		}

		for (int i = 0; i < graph[curX].size(); i++) {
			int nextX = graph[curX][i];

			if (!visited[nextX]) {
				visited[nextX] = true;

				pq.push({ curDist + 1, nextX });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	bfs();

	sort(result.begin(), result.end());

	cout << result[0] << " " << maxDist << " " << result.size();

	return 0;
}
