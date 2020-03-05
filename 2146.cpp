#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 100;

int map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q;
vector<int> lenBridge;

int n;
int cnt = -1;
int cntIsland = 1;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void dfs(int a, int b) {	// 각 섬을 숫자로 구분해주기 위한 함수
	if (visit[a][b]) return;

	visit[a][b] = true;
	map[a][b] = cntIsland;

	for (int i = 0; i < 4; i++) {
		int nextX = a + dirX[i];
		int nextY = b + dirY[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
			if (map[nextX][nextY] && !visit[nextX][nextY])
				dfs(nextX, nextY);
		}
	}
}

void bfs() {
	while (true) {
		int len = q.size();
		cnt++;

		while (len--) {
			int curX = q.front().first;
			int curY = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dirX[i];
				int nextY = curY + dirY[i];

				if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
					if (!map[nextX][nextY] && !visit[nextX][nextY]) {
						visit[nextX][nextY] = true;
						q.push(make_pair(nextX, nextY));
					}
					if (map[nextX][nextY] != 0 && map[nextX][nextY] != cntIsland) {
						lenBridge.push_back(cnt);
						return;
					}
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	// 각 섬을 숫자로 구분
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !visit[i][j]) {
				dfs(i, j);
				cntIsland++;
			}
		}
	}
	cntIsland--;

	while (cntIsland) {
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == cntIsland) {
					for (int k = 0; k < 4; k++) {
						int nextX = i + dirX[k];
						int nextY = j + dirY[k];

						if (!map[nextX][nextY]) {
							q.push(make_pair(i, j));
							break;
						}
					}
				}

			}
		}

		bfs();
		cnt = -1;

		while (!q.empty()) q.pop();
		cntIsland--;
	}

	sort(lenBridge.begin(), lenBridge.end());

	cout << lenBridge.front();

	return 0;
}
