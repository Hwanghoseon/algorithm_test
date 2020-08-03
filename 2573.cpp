#include<iostream>
#include<cstring>

using namespace std;

typedef struct {
	int x, y;
}Dir;

const int MAX = 300;

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int iceCnt = 0;
bool isPossible = true;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void dfs(int x, int y) {
	if (visit[x][y]) return;

	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dir[i].x;
		int nextY = y + dir[i].y;

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
			if (map[nextX][nextY])
				dfs(nextX, nextY);
	}
}

int checkIce() {
	memset(visit, false, sizeof(visit));

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] &&!visit[i][j]) {
				dfs(i, j);
				cnt++;
			}

	return cnt;
}

void bfs() {
	while (true) {
		// 빙산의 갯수 체크
		if (checkIce() == 1) {}
		else if (checkIce() >= 2) {
			isPossible = true;
			return;
		}
		else if(checkIce() == 0) {
			isPossible = false;
			return;
		}

		// 빙하가 녹는 경우 (1초가 지난 경우)
		int temp[MAX][MAX];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int zeroCnt = 0;
				if (map[i][j]) {
					for (int k = 0; k < 4; k++) {
						int nextX = i + dir[k].x;
						int nextY = j + dir[k].y;

						if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
							if (!map[nextX][nextY]) zeroCnt++;
					}
					temp[i][j] = zeroCnt;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] < temp[i][j]) map[i][j] = 0;
				else map[i][j] -= temp[i][j];
			}
		}
		iceCnt++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	bfs();

	if (!isPossible) cout << "0";
	else cout << iceCnt;

	return 0;
}
