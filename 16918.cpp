#include<iostream>
#include<queue>

using namespace std;

const int MAX = 200;

int R, C, N;
int map[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	cin >> R >> C >> N;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;

			if (c == '.') map[i][j] = 1;
			else map[i][j] = 0;	// '0'가 폭탄
		}
}

void bfs() {
	int cnt = 1;

	while (cnt != N) {
		queue<pair<int, int>> boom;
		for(int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if (!map[i][j])
					boom.push(make_pair(i, j));
			}

		int boomSize = boom.size();

		while (boomSize--) {
			int curX = boom.front().first;
			int curY = boom.front().second;
			boom.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dirX[i];
				int nextY = curY + dirY[i];

				if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
					if (map[nextX][nextY]) {
						map[nextX][nextY] = 0;
						boom.push(make_pair(nextX, nextY));
					}
				}
			}
		}
		
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 1) map[i][j] = 0;
				else map[i][j] = 1;
			}

		cnt += 2;

		if (cnt == N) return;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	if (!(N % 2)) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				cout << "O";
			cout << "\n";
		}
	}
	else {
		bfs();

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j]) cout << ".";
				else cout << "O";
			}
			cout << "\n";
		}
	}

	return 0;
}
