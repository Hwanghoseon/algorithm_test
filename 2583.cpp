#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100;

int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> v;

int cnt = 0;
int sizeSum = 0;
int N, M, K;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void dfs(int a, int b) {
	visit[a][b] = true;

	sizeSum++;
	for (int i = 0; i < 4; i++) {
		int nextX = a + dirX[i];
		int nextY = b + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
			if (!map[nextX][nextY] && !visit[nextX][nextY])
				dfs(nextX, nextY);
		}
	}
}

bool check(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;

	int x1, x2, y1, y2;

	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int xGap = x2 - x1;
		int yGap = y2 - y1;

		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				map[j][k] = 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] && !visit[i][j]) {
				sizeSum = 0;
				dfs(i, j);
				v.push_back(sizeSum);
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	sort(v.begin(), v.end(), check);

	while (!v.empty()) {
		cout << v.back() << " ";
		v.pop_back();
	}

	return 0;
}
