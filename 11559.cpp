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

const int N = 12;
const int M = 6;

char board[N][M];
char temp[N][M];
bool visited[N][M];
int cnt;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;

		for (int j = 0; j < st.length(); j++)
			board[i][j] = st[j];
	}
}

void dfs(int x, int y, char target) {
	if (visited[x][y]) return;

	visited[x][y] = true;

	cnt++;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if(board[nextX][nextY] == target)
				dfs(nextX, nextY, target);
	}
}

void popBoard(int x, int y, char target) {
	if (board[x][y] != target) return;

	board[x][y] = '.';

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if (board[nextX][nextY] == target)
				popBoard(nextX, nextY, target);
	}
}

void changeBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = '.';

	for (int j = 0; j < M; j++) {
		int idx = N - 1;

		for (int i = N - 1; i >= 0; i--) {
			if (board[i][j] != '.') {
				temp[idx][j] = board[i][j];

				idx--;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			board[i][j] = temp[i][j];
}

int solution() {
	int ans = 0;

	changeBoard();

	bool isExist = true;

	while (isExist) {
		isExist = false;

		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] != '.' && !visited[i][j]) {
					cnt = 0;

					dfs(i, j, board[i][j]);

					if (cnt >= 4) {
						popBoard(i, j, board[i][j]);

						isExist = true;
					}
				}
			}
		}

		if (isExist) {
			changeBoard();

			ans++;
		}
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
