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

const int MAX = 250;

char board[MAX][MAX];
int R, C;
bool visited[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
pair<int, int> result = { 0, 0 };
int oCnt, vCnt;

void input() {
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
}

void dfs(int x, int y) {
	if (visited[x][y]) return;

	visited[x][y] = true;
	
	if (board[x][y] == 'o') oCnt++;
	else if (board[x][y] == 'v') vCnt++;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && board[nextX][nextY] != '#' && !visited[nextX][nextY])
			dfs(nextX, nextY);
	}
}

void func() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != '#' && !visited[i][j]) {
				oCnt = vCnt = 0;

				dfs(i, j);

				// 양이 늑대보다 많을 경우
				if (oCnt > vCnt)
					result.first += oCnt;
				// 양이 늑대보다 같거나 적을 경우
				else
					result.second += vCnt;
			}
		}
	}

	cout << result.first << " " << result.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	return 0;
}
