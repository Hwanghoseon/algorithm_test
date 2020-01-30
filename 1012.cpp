#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 50;

int map[MAX][MAX];
bool check[MAX][MAX] = { false };

int N, M, K, cnt;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };


void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	check[a][b] = true;

	while (!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = first + dirX[i];
			int nextY = second + dirY[i];

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (map[nextX][nextY] && !check[nextX][nextY]) {
					q.push({ nextX, nextY });
					check[nextX][nextY] = true;
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
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				map[i][j] = 0;
				check[i][j] = false;
			}
		}

		cin >> M >> N >> K;
		cnt = 0;

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;

			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !check[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}

	cout << endl;

	return 0;
}
