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

const int MAX = 100 + 2;

int N, M;
int board[MAX][MAX];
int temp[MAX][MAX];
int dirX[] = { 1, -1, 0 ,0 };
int dirY[] = { 0, 0, 1, -1 };
bool visited[MAX][MAX];
int cheeseCnt = 0;	// 치즈의 갯수

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];

			if (board[i][j]) cheeseCnt++;
			else board[i][j] = 2;
		}
}

void dfs(int x, int y) {
	if (visited[x][y]) return;

	visited[x][y] = true;
	board[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX <= N && nextY >= 0 && nextY <= M)
			if (board[nextX][nextY] != 1)
				dfs(nextX, nextY);
	}
}

void cheeseChange() {
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			temp[i][j] = board[i][j];

	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (temp[i][j] != 1) continue;

			for (int k = 0; k < 4; k++) {
				int nextX = i + dirX[k];
				int nextY = j + dirY[k];

				if (!temp[nextX][nextY]) {
					board[i][j] = 0;

					break;
				}
			}
		}
}

int countCheese() {
	int cnt = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (board[i][j] == 1) cnt++;

	return cnt;
}

void solution() {
	// 치즈 1, 외부공기 0, 내부공기 2
	int cnt;
	int sec = 0;

	while (cheeseCnt) {
		cnt = cheeseCnt;

		memset(visited, false, sizeof(visited));

		dfs(0, 0);

		cheeseChange();

		cheeseCnt = countCheese();

		sec++;
	}

	cout << sec << "\n" << cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
