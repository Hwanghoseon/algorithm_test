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
int board[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
queue<pair<int, int>> cheese;
bool visited[MAX][MAX];

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;

			// 치즈 : 1, 외부 공기 : 0, 내부 공기 : 2
			if (!temp) board[i][j] = 2;
			else {
				board[i][j] = temp;

				cheese.push({ i, j });
			}
		}

	board[0][0] = 0;
}

void checkOutside(int x, int y) {
	if (visited[x][y]) return;

	visited[x][y] = true;

	board[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if (board[nextX][nextY] != 1)
				checkOutside(nextX, nextY);
	}
}

int bfs() {
	int temp[MAX][MAX];
	
	int sec = 0;

	while (!cheese.empty()) {
		memset(visited, false, sizeof(visited));

		// 외부 공기와 내부 공기 구분
		checkOutside(0, 0);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp[i][j] = board[i][j];

		int len = cheese.size();

		while (len--) {
			int curX = cheese.front().first;
			int curY = cheese.front().second;
			cheese.pop();

			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dirX[i];
				int nextY = curY + dirY[i];

				if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
					if (!temp[nextX][nextY])
						cnt++;
				}
			}

			if (cnt >= 2)
				board[curX][curY] = 0;
			else
				cheese.push({ curX, curY });
		}

		sec++;
	}

	return sec;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << bfs();

	return 0;
}
