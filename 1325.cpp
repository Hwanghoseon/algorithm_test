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

const int MAX = 1e5 + 1;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
vector<int> result;
int cnt = 0;

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> to >> from;

		graph[from].push_back(to);
	}
}

void dfs(int idx) {
	visited[idx] = true;

	cnt++;

	for (int i = 0; i < graph[idx].size(); i++) {
		int nextIdx = graph[idx][i];

		if (!visited[nextIdx])
			dfs(nextIdx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int linkCnt = 0;
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));

		cnt = 0;
		dfs(i);

		if (linkCnt == cnt)
			result.push_back(i);
		else if (linkCnt < cnt) {
			linkCnt = cnt;
			result.clear();
			result.push_back(i);
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}
