#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
	int x, y, len;
}dir;

const int MAX = 100;

int map[MAX][MAX];
bool visit[MAX][MAX];
string graph[MAX];

int N, M;
int result = 0;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void bfs(int a, int b, int c) {
	queue<dir> q;
	q.push({ a, b, c });

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int curLen = q.front().len;

		q.pop();
		visit[a][b] = true;

		if (curX == N - 1 && curY == M - 1) {
			result = curLen;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (map[nextX][nextY] && !visit[nextX][nextY]) {
					visit[nextX][nextY] = true;
					q.push({ nextX, nextY, curLen + 1 });
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> graph[i];

		for (int j = 0; j < M; j++) {
			map[i][j] = graph[i][j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visit[i][j]) {
				bfs(i, j, 1);
			}
		}
	}

	cout << result << endl;

	return 0;
}
