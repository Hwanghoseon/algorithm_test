#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100;

int map[MAX][MAX];
bool visit[MAX][MAX];
priority_queue<int> pq;

int N;
int cnt = 0;
int highMax = 0;
int rainHigh = 100;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void dfs(int a, int b) {
	visit[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = a + dirX[i];
		int nextY = b + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
			if (!visit[nextX][nextY] && map[nextX][nextY] > highMax)
				dfs(nextX, nextY);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (highMax < map[i][j])
				highMax = map[i][j];
		}

	while (highMax >= 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > highMax && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		pq.push(cnt);
		
		for (int i = 0; i < N; i++) {
			fill_n(visit[i], N, false);
		}

		highMax--;
		cnt = 0;
	}
	cout << pq.top();
	
	return 0;
}
