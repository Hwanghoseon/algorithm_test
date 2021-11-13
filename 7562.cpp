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

const int MAX = 300;

int N;
int board[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> startPoint, endPoint;
int dirX[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dirY[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

void input() {
	cin >> N;

	cin >> startPoint.first >> startPoint.second >> endPoint.first >> endPoint.second;
}

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { startPoint.first, startPoint.second }, 0 });
	visited[startPoint.first][startPoint.second];

	while (!q.empty()) {
		int len = q.size();

		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curCnt = q.front().second;
		q.pop();

		if (curX == endPoint.first && curY == endPoint.second)
			return curCnt;

		for (int i = 0; i < 8; i++) {
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
				if (!visited[nextX][nextY]) {
					visited[nextX][nextY] = true;

					q.push({ { nextX, nextY }, curCnt + 1 });
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();

		memset(visited, false, sizeof(visited));

		cout << bfs() << "\n";
	}

	return 0;
}
