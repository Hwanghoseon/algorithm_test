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

const int MAX = 100 + 1;
const int INF = 1e8;

int N, M;
int board[MAX][MAX];
int path[MAX];
bool visited[MAX];
vector<int> list[MAX];
vector<int> result;

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		board[from][to] = 1;
		board[to][from] = 1;
	}

	for (int i = 1; i <= N; i++)
		board[i][i] = 0;
}

void floyd_warshall() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (board[i][j] > board[i][k] + board[k][j])
					board[i][j] = board[i][k] + board[k][j];

	for (int i = 1; i <= N; i++) {
		int cnt = 0;

		for (int j = 1; j <= N; j++) {
			if (!visited[j] && board[i][j] != INF) {
				list[i].push_back(j);

				visited[j] = true;
			}

			if (board[i][j] != INF)
				cnt = max(cnt, board[i][j]);
		}

		path[i] = cnt;
	}

	for (int i = 1; i <= N; i++) {
		if (!list[i].size()) continue;

		int temp = INF;
		int idx;
		for (int j = 0; j < list[i].size(); j++) {
			if (temp > path[list[i][j]]) {
				temp = path[list[i][j]];

				idx = list[i][j];
			}
		}

		result.push_back(idx);
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	floyd_warshall();

	return 0;
}
