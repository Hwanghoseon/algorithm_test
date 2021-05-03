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

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		board[from][to] = 1;
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
		for (int j = 1; j <= N; j++) {
			if (i == j || board[i][j] == INF) continue;

			path[i]++;
			path[j]++;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << N - 1 - path[i] << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	floyd_warshall();

	return 0;
}
