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

const int MAX = 50;

int N, M;
int board[MAX][MAX];
int dirX[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dirY[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

void input() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
}

void dfs(int x, int y) {
	if (!board[x][y]) return;

	board[x][y] = 0;

	for (int i = 0; i < 8; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			dfs(nextX, nextY);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> M >> N;

		if (!N && !M) break;

		input();

		int cnt = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				if (board[i][j]) {
					dfs(i, j);

					cnt++;
				}

		cout << cnt << "\n";
	}

	return 0;
}
