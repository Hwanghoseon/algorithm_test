#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 50;

int map[MAX][MAX];
bool check[MAX][MAX];

int N, M, K, cnt;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void dfs(int a, int b) {
	check[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = a + dirX[i];
		int nextY = b + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if (map[nextX][nextY] && !check[nextX][nextY])
				dfs(nextX, nextY);
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
		cnt = 0;

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;

			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !check[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}
