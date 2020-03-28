#include<iostream>
#include<vector>

using namespace std;

const int MAX = 100000 + 1;

int n;
vector<int> tree[MAX];
bool visit[MAX];
int head[MAX];

void input() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;

		tree[from].push_back(to);
		tree[to].push_back(from);
	}
}

void dfs(int node) {
	if (visit[node]) return;

	visit[node] = true;

	for (int i = 0; i < tree[node].size(); i++) {
		int nextNode = tree[node][i];

		if (!visit[nextNode]) {
			head[tree[node][i]] = node;
			dfs(tree[node][i]);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << head[i] << "\n";

	return 0;
}
