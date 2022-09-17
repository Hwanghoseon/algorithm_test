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

const int MAX = 100;

int N, M;
char board[MAX][MAX];
bool visited[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
int cnt = 0;

void input() {
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
}

void dfs(int x, int y, char target) {
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if(!visited[nextX][nextY] && board[nextX][nextY] == target)
				dfs(nextX, nextY, target);
	}
}

void solution() {
	pair<int, int> sum;	// B, W

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				cnt = 0;
				dfs(i, j, board[i][j]);

				if (board[i][j] == 'B')
					sum.first += cnt * cnt;
				else
					sum.second += cnt * cnt;
			}
		}
	}

	cout << sum.second << " " << sum.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
