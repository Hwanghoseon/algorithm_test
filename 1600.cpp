#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int x, y;
}Dir;

const int MAX = 200;

int K, W, H;
int board[MAX][MAX];
bool visit[MAX][MAX][30 + 1];
Dir monkeyDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
Dir horseDir[8] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
int cnt = 0;

void input() {
	cin >> K >> H >> W;

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++)
			cin >> board[i][j];
	}
}

int bfs() {
	queue<pair<pair<int, int>, int>> monkey;	// x, y, K
	monkey.push(make_pair(make_pair(0, 0), 0));
	visit[0][0][0] = true;

	while (!monkey.empty()) {
		int monkeySize = monkey.size();

		while (monkeySize--) {
			int curX = monkey.front().first.first;
			int curY = monkey.front().first.second;
			int horseCnt = monkey.front().second;
			monkey.pop();

			if (curX == W - 1 && curY == H - 1) return cnt;

			// 말의 능력이 존재할 경우
			if (horseCnt < K) {
				for (int i = 0; i < 8; i++) {
					int nextX = curX + horseDir[i].x;
					int nextY = curY + horseDir[i].y;
					
					if (nextX >= 0 && nextX < W && nextY >= 0 && nextY < H) {
						if (!visit[nextX][nextY][horseCnt + 1] && !board[nextX][nextY]) {
							visit[nextX][nextY][horseCnt + 1] = true;
							monkey.push(make_pair(make_pair(nextX, nextY), horseCnt + 1));
						}
					}
				}
			}

			// 말의 능력이 존재하지 않을 경우
			for (int i = 0; i < 4; i++) {
				int nextX = curX + monkeyDir[i].x;
				int nextY = curY + monkeyDir[i].y;

				if (nextX >= 0 && nextX < W && nextY >= 0 && nextY < H) {
					if (!visit[nextX][nextY][horseCnt] && !board[nextX][nextY]) {
						visit[nextX][nextY][horseCnt] = true;
						monkey.push(make_pair(make_pair(nextX, nextY), horseCnt));
					}
				}
			}
		}
		cnt++;
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << bfs();

	return 0;
}
