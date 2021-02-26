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

const int MAX = 200;

int board[MAX][MAX];
int N, R1, C1, R2, C2;

bool isPossible(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return true;

	return false;
}

int func() {
	queue<pair<pair<int, int>, int>> q;		// R, C, cnt
	q.push({ {R1, C1}, 0 });
	board[R1][C1] = 1;

	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curCnt = q.front().second;
		q.pop();

		if (curX == R2 && curY == C2) return curCnt;

		int nextX, nextY;

		// (r - 2, c - 1)
		nextX = curX - 2;
		nextY = curY - 1;
		
		if (isPossible(nextX, nextY) && !board[nextX][nextY]) {
			board[nextX][nextY] = 1;

			q.push({ {nextX, nextY}, curCnt + 1 });
		}

		// (r - 2, c + 1)
		nextX = curX - 2;
		nextY = curY + 1;

		if (isPossible(nextX, nextY) && !board[nextX][nextY]) {
			board[nextX][nextY] = 1;

			q.push({ {nextX, nextY}, curCnt + 1 });
		}

		// (r, c - 2)
		nextX = curX;
		nextY = curY - 2;

		if (isPossible(nextX, nextY) && !board[nextX][nextY]) {
			board[nextX][nextY] = 1;

			q.push({ {nextX, nextY}, curCnt + 1 });
		}

		// (r, c + 2)
		nextX = curX;
		nextY = curY + 2;

		if (isPossible(nextX, nextY) && !board[nextX][nextY]) {
			board[nextX][nextY] = 1;

			q.push({ {nextX, nextY}, curCnt + 1 });
		}

		// (r + 2, c - 1)
		nextX = curX + 2;
		nextY = curY - 1;

		if (isPossible(nextX, nextY) && !board[nextX][nextY]) {
			board[nextX][nextY] = 1;

			q.push({ {nextX, nextY}, curCnt + 1 });
		}

		// (r + 2, c + 1)
		nextX = curX + 2;
		nextY = curY + 1;

		if (isPossible(nextX, nextY) && !board[nextX][nextY]) {
			board[nextX][nextY] = 1;

			q.push({ {nextX, nextY}, curCnt + 1 });
		}
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> R1 >> C1 >> R2 >> C2;

	cout << func();

	return 0;
}
