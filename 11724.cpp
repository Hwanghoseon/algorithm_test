#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000 + 1;

int node[MAX];
bool visit[MAX];
vector<int> con[MAX];

int N, M;
int cnt = 0;
int sum = 0;

void dfs(int n) {
	if (visit[n]) return;

	visit[n] = true;
	sum++;

	for (int i = 0; i < con[n].size(); i++)
		dfs(con[n][i]);
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
		dfs(i);

		if (sum != 0)
			cnt++;

		sum = 0;
	}

	cout << cnt;

	return 0;
}
