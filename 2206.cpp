#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

const int MAX = 1000;

int map[MAX][MAX];
int visit[MAX][MAX][2];

int N, M;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
string graph[MAX];

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visit[0][0][1] = 1;

	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int block = q.front().second;

		q.pop();

		// 도달할 경우
		if (curX == N - 1 && curY == M - 1)
			return visit[curX][curY][block];

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				// 벽이 존재하고 벽을 부순적이 없을 경우
				if (map[nextX][nextY] && block) {
					visit[nextX][nextY][block - 1] = visit[curX][curY][block] + 1;
					q.push(make_pair(make_pair(nextX, nextY), block - 1));
				}
				// 벽이 없고, 방문한 적이 없을 경우
				else if (!map[nextX][nextY] && !visit[nextX][nextY][block]) {
					visit[nextX][nextY][block] = visit[curX][curY][block] + 1;
					q.push(make_pair(make_pair(nextX, nextY), block));
				}
			}
		}
	}

	return -1;
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

	cout << bfs() << endl;

	return 0;
}
