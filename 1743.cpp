#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX = 100 + 1;

int N, M, K;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
int cnt = 0;

void input() {
	cin >> N >> M >> K;

	while (K--) {
		int x, y;
		cin >> x >> y;

		map[x][y] = 1;
	}
}

void dfs(int x, int y) {
	if (visited[x][y]) return;

	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= M)
			if (map[nextX][nextY] && !visited[nextX][nextY])
				dfs(nextX, nextY);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cnt = 0;

			if (map[i][j] && !visited[i][j]) {
				dfs(i, j);

				result = max(result, cnt);
			}
		}
	}

	cout << result;

	return 0;
}
