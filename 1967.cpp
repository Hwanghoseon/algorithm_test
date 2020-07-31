#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 10000 + 1;

vector<pair<int, int>> graph[MAX];
int n;
bool visit[MAX];
int graphLen = 0;	// 그래프 반지름
int endPoint = 0;

void input() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		int parent, child, length;
		cin >> parent >> child >> length;

		graph[parent].push_back(make_pair(child, length));
		graph[child].push_back(make_pair(parent, length));
	}
}

void dfs(int start, int len) {
	if (visit[start]) return;

	visit[start] = true;

	if (graphLen < len) {
		graphLen = len;
		endPoint = start;
	}

	for (int i = 0; i < graph[start].size(); i++)
		dfs(graph[start][i].first, len + graph[start][i].second);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	dfs(1, 0);

	memset(visit, false, sizeof(visit));

	dfs(endPoint, 0);

	cout << graphLen;

	return 0;
}
