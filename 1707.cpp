// 부모 노드와 자식 노드에 색을 채우는데
// 부모 노드와 자식 노드의 색을 항상 다르게 한다.


#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 20000 + 1;

vector<int> graph[MAX];
int nodeColor[MAX];
int V, E;

void input() {
	for (int i = 1; i < MAX; i++)
		graph[i].clear();

	memset(nodeColor, 0, sizeof(nodeColor));

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}
}

// 방문하지 않은 노드 0, 빨간색 노드 1, 검정색 노드 2
void dfs(int node, int color) {
	if (nodeColor[node]) return;

	nodeColor[node] = color;

	for (int i = 0; i < graph[node].size(); i++) {
		if (!nodeColor[graph[node][i]])
			dfs(graph[node][i], 3 - color);
	}
}

bool checkColor() {
	for (int i = 1; i <= V; i++)
		for (int j = 0; j < graph[i].size(); j++)
			if (nodeColor[i] == nodeColor[graph[i][j]])
				return false;

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();

		for(int i = 1; i <= V; i++)
			if(!nodeColor[i])
				dfs(i, 1);

		if (checkColor()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
