#include<iostream>

using namespace std;

const int MAX = 250;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dirY[] = { 1, -1, 0, 1, -1, 1, -1, 0 };

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

void dfs(int x, int y) {
	if (visited[x][y]) return;

	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if(map[nextX][nextY])
				dfs(nextX, nextY);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++){
			if (map[i][j] && !visited[i][j]) {
				dfs(i, j);

				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}
