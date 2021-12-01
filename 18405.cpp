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

const int MAX = 200 + 1;

int N, K, S, X, Y;
int board[MAX][MAX];
priority_queue < pair<pair<int, int>, pair<int, int>>, vector < pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];

			if (board[i][j])
				pq.push({ {0, board[i][j]}, {i, j } });
		}

	cin >> S >> X >> Y;
}

int bfs() {
	while (S--) {
		int len = pq.size();

		for (int i = 0; i < len; i++) {
			int curCnt = pq.top().first.first;
			int curNum = pq.top().first.second;
			int curX = pq.top().second.first;
			int curY = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dirX[i];
				int nextY = curY + dirY[i];

				if (nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= N) {
					if (!board[nextX][nextY]) {
						board[nextX][nextY] = curNum;

						pq.push({ {curCnt + 1, curNum}, {nextX, nextY} });
					}
				}
			}
		}

		
	}

	return board[X][Y];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << bfs();

	return 0;
}
