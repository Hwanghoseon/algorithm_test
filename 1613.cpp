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
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();

	floyd_warshall();

	int T;
	cin >> T;

	while (T--) {
		int from, to;
		cin >> from >> to;

		if (board[from][to] == INF && board[to][from] == INF) cout << "0\n";
		else if (board[from][to] != INF) cout << "-1\n";
		else cout << "1\n";
	}

	return 0;
}
