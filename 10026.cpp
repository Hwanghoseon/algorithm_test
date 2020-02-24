#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 100;

char graph[MAX][MAX];
char graph2[MAX][MAX];	// 적록색약이 보는 구역
bool visit[MAX][MAX];
int n;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
char curColor;

void init() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];

			if (graph[i][j] == 'G')
				graph2[i][j] = 'R';
			else
				graph2[i][j] = graph[i][j];
		}
}

void dfs(int a, int b) {
	if (visit[a][b]) return;

	visit[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = a + dirX[i];
		int nextY = b + dirY[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n)
			if (graph[nextX][nextY] == curColor && !visit[nextX][nextY])
				dfs(nextX, nextY);
	}
}

void dfs2(int a, int b) {
	if (visit[a][b]) return;

	visit[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = a + dirX[i];
		int nextY = b + dirY[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n)
			if (graph2[nextX][nextY] == curColor && !visit[nextX][nextY])
				dfs2(nextX, nextY);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	vector<int> num(2);	// 구역의 수 저장하기 위한 변수
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				if (graph[i][j] == 'R')
					curColor = 'R';
				else if (graph[i][j] == 'G')
					curColor = 'G';
				else
					curColor = 'B';

				dfs(i, j);
				cnt++;
			}
		}
	}
	
	num[0] = cnt;

	memset(visit, false, sizeof(visit));

	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				if (graph2[i][j] == 'R')
					curColor = 'R';
				else
					curColor = 'B';

				dfs2(i, j);
				cnt++;
			}
		}
	}

	num[1] = cnt;

	cout << num[0] << "\n" << num[1];

	return 0;
}
