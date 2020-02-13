#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 500;

int map[MAX][MAX];
priority_queue<int> pq;
int n, m;
int cnt = 0;
int mapSize = 0;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void dfs(int a, int b) {
	if (!map[a][b]) return;

	map[a][b] = 0;
	mapSize++;

	for (int i = 0; i < 4; i++) {
		int nextX = a + dirX[i];
		int nextY = b + dirY[i];

		if (nextX >= 0 && nextX < MAX && nextY >= 0 && nextY < MAX)
			dfs(nextX, nextY);
	}
}

void init() {


	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j]) {
				dfs(i, j);
				cnt++;
				pq.push(mapSize);
				mapSize = 0;
			}

	if (pq.size())
		cout << cnt << endl << pq.top() << endl;
	else
		cout << "0" << endl << "0" << endl;

	return 0;
}
