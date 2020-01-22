#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000 + 1;

int N, M, V;
bool check[MAX];
vector<int> con[MAX];

void dfs_stack(int start) {
	std::fill_n(check, MAX, false);	//check 방문기록 초기화

	stack<int> s;
	s.push(start);
	check[start] = true;
	cout << start << " ";

	while(!s.empty()) {
		int current_node = s.top();
		s.pop();

		for (int i = 0; i < con[current_node].size(); i++) {
			int next_node = con[current_node][i];

			if (!check[next_node]) {
				check[next_node] = true;
				cout << next_node << " ";
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}
	}

	cout << endl;
}

void dfs_recursion(int n) {
	if (check[n]) return;

	check[n] = true;
	cout << n << " ";

	for (int i = 0; i < con[n].size(); i++)
		dfs_recursion(con[n][i]);
}

void bfs(int start) {
	std::fill_n(check, MAX, false);	//check 방문기록 초기화

	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int current_node = q.front();
		q.pop();
		cout << current_node << " ";

		for (int i = 0; i < con[current_node].size(); i++) {
			int next_node = con[current_node][i];

			if (!check[next_node]) {
				check[next_node] = true;
				q.push(next_node);
			}
		}
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		con[to].push_back(from);
		con[from].push_back(to);
	}

	for (int i = 1; i <= N; i++)
		sort(con[i].begin(), con[i].end());

	dfs_stack(V);

	bfs(V);

	return 0;
}
