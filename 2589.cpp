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

using namespace std;

const int MAX = 50;

int N, M;
int board[MAX][MAX];
int temp[MAX][MAX];
int result = 0;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.length(); j++) {
			if (temp[j] == 'L')
				board[i][j] = 1;
			else board[i][j] = 0;
		}
	}
}

void copyBoard() {
	for (int i = 0; i  < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = board[i][j];
}

void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	temp[x][y] = 0;

	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curCnt = q.front().second;
		q.pop();

		result = max(result, curCnt);

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (temp[nextX][nextY]) {
					q.push({ {nextX, nextY}, curCnt + 1 });

					temp[nextX][nextY] = 0;
				}
			}
		}
	}
}

int solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) {
				copyBoard();

				bfs(i, j);
			}
		}
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
