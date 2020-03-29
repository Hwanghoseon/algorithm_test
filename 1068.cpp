#include<iostream>
#include<vector>

using namespace std;

const int MAX = 50;

vector<int> tree[MAX];
bool visit[MAX];
int n;
int root;
int cnt = 0;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (temp != -1) {
			tree[i].push_back(temp);
			tree[temp].push_back(i);
		}
		else root = i;
	}

	int deleteNode;
	cin >> deleteNode;

	visit[deleteNode] = true;
}

bool check(int node) {
	for (int i = 0; i < tree[node].size(); i++) {
		int possibleNode = tree[node][i];

		if (!visit[possibleNode]) return true;
	}

	return false;
}

void dfs(int node) {
	if (visit[node]) return;

	visit[node] = true;

	if (!check(node)) cnt++;
	else {
		for (int i = 0; i < tree[node].size(); i++) {
			int nextNode = tree[node][i];

			if (!visit[nextNode])
				dfs(nextNode);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	dfs(root);

	cout << cnt;

	return 0;
}
