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

const int MAX = 5;

int R, C, K;

int board[MAX][MAX];
bool visited[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
int result = 0;

void input() {
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.length(); j++)
			board[i][j] = temp[j];
	}

	visited[R - 1][0] = true;
}

void func(int cnt, int x, int y) {
	if (cnt == K && x == 0 && y == C - 1) {
		result++;

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
			if (!visited[nextX][nextY] && board[nextX][nextY] == '.') {
				visited[nextX][nextY] = true;
				func(cnt + 1, nextX, nextY);
				visited[nextX][nextY] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(1, R - 1, 0);

	cout << result;

	return 0;
}
