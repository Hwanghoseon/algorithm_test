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

const int MAX = 30 + 1;

typedef struct {
	int x, y, z, sec;
}position;

char board[MAX][MAX][MAX];	// 세로, 가로, 높이
int L, R, C;
int startX, startY, startZ, endX, endY, endZ;
bool visited[MAX][MAX][MAX];
int dirX[] = { 1, -1, 0, 0, 0, 0 };
int dirY[] = { 0, 0, 1, -1, 0, 0 };
int dirZ[] = { 0, 0, 0, 0, 1, -1 };

void input() {
	for(int k = 0; k < L; k++)
		for(int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				cin >> board[i][j][k];

				if (board[i][j][k] == 'S') {
					startX = i;
					startY = j;
					startZ = k;
				}
				else if (board[i][j][k] == 'E') {
					endX = i;
					endY = j;
					endZ = k;
				}
			}

	for (int k = 0; k < L; k++)
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				visited[i][j][k] = false;
}

int bfs() {
	queue<position> q;
	position temp = { startX, startY, startZ, 0 };
	q.push(temp);
	visited[startX][startY][startZ] = true;

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int curZ = q.front().z;
		int curSec = q.front().sec;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];
			int nextZ = curZ + dirZ[i];

			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && nextZ >= 0 && nextZ < L) {
				if (board[nextX][nextY][nextZ] == '.' && !visited[nextX][nextY][nextZ]) {
					visited[nextX][nextY][nextZ] = true;

					temp = { nextX, nextY, nextZ, curSec + 1 };

					q.push(temp);
				}
				// 출구일 경우
				else if (board[nextX][nextY][nextZ] == 'E' && !visited[nextX][nextY][nextZ])
					return curSec + 1;
			}
		}
	}

	return -1;
}

void getResult(int n) {
	if (n == -1)
		cout << "Trapped!\n";
	else
		cout << "Escaped in " << n << " minute(s).\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> L >> R >> C;

		if (!L && !R && !C) break;

		input();

		getResult(bfs());
	}

	return 0;
}
