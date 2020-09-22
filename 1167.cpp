#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 100000;

vector<pair<int, int>> graph[MAX];
int N;
bool visit[MAX];
int startNode;	// 지름의 끝부분
int sumValue = 0;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int from, to, value;
		cin >> from >> to;

		while(to != -1) {
			cin >> value;

			graph[from].push_back(make_pair(to, value));

			cin >> to;
		}
	}
}

void dfs(int node, int sum) {
	if (visit[node]) return;

	visit[node] = true;

	if (sumValue < sum) {
		sumValue = sum;
		startNode = node;
	}

	for (int i = 0; i < graph[node].size(); i++)
		dfs(graph[node][i].first, sum + graph[node][i].second);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	// 지름의 끝부분 중 한 점 구한다.
	dfs(1, 0);

	memset(visit, false, sizeof(visit));

	dfs(startNode, 0);

	cout << sumValue;
	
	return 0;
}
