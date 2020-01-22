#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 100 + 1;

int num, line_num, sum = 0;
bool check[MAX];
vector<int> con[MAX];

void dfs(int n) {
	if (check[n]) return;

	check[n] = true;
	//cout << n << " ";
	sum++;

	for (int i = 0; i < con[n].size(); i++) {
		dfs(con[n][i]);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int current_node = q.front();
		q.pop();
		//cout << current_node << " ";
		sum++;

		for (int i = 0; i < con[current_node].size(); i++) {
			int next_node = con[current_node][i];

			if (!check[next_node]) {
				q.push(next_node);
				check[next_node] = true;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num >> line_num;

	for (int i = 0; i < line_num; i++) {
		int from, to;
		cin >> from >> to;

		con[from].push_back(to);
		con[to].push_back(from);
	}

	//dfs(1);
	bfs(1);

	cout << sum  - 1 << endl;

	return 0;
}
