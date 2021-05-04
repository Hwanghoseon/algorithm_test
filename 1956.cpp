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

const int MAX = 400 + 1;
const int INF = 1e8;

int N, M;
int board[MAX][MAX];

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		board[from][to] = min(board[from][to], value);
	}

	for (int i = 1; i <= N; i++)
		board[i][i] = 0;
}

int floyd_warshaal() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (board[i][j] > board[i][k] + board[k][j])
					board[i][j] = board[i][k] + board[k][j];

	int ans = INF;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || board[i][j] == INF || board[j][i] == INF) continue;

			int temp = board[i][j] + board[j][i];

			ans = min(ans, temp);
		}
	}

	if (ans == INF) ans = -1;

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << floyd_warshaal();

	return 0;
}
