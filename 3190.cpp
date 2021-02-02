#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>

using namespace std;

const int MAX = 100 + 1;

int N, K, L;
int board[MAX][MAX];
queue<pair<int, int>> snake;
int sec = 0;

int dirX[] = { -1, 0, 1, 0 };	// 위, 오른쪽, 아래, 왼쪽
int dirY[] = { 0, 1, 0, -1 };	// 위, 오른쪽, 아래, 왼쪽
int dir;	// 방향 설정을 위한 변수
int curX, curY;
bool isError = false;

void input() {
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;

		board[x][y] = 2;	// 사과 = 2
	}

	board[1][1] = 1;	// 뱀 = 1

	curX = curY = 1;	// 뱀의 처음 위치는 (1,1)

	snake.push({ 1, 1 });
	dir = 1;	// 뱀은 처음에 오른쪽을 향한다
}

void func() {
	int n;
	char op;

	if(L)
		cin >> n >> op;
	else n = N * N;

	for (int i = sec; i < n; i++) {
		sec++;

		curX += dirX[dir];
		curY += dirY[dir];

		// 벽에 부딪히지 않는 경우
		if (curX >= 1 && curX <= N && curY >= 1 && curY <= N) {
			// 사과가 있을 경우
			if (board[curX][curY] == 2) {
				board[curX][curY] = 1;

				snake.push({ curX, curY });
			}
			// 뱀 자신의 몸과 만나는 경우
			else if (board[curX][curY] == 1) {
				isError = true;

				return;
			}
			// 사과가 없을 경우
			else if (board[curX][curY] == 0) {
				board[curX][curY] = 1;

				snake.push({ curX, curY });

				int snakeX = snake.front().first;
				int snakeY = snake.front().second;
				snake.pop();

				board[snakeX][snakeY] = 0;
			}
		}
		// 벽에 부딪히는 경우
		else {
			isError = true;

			return;
		}
	}

	if (op == 'D')
		dir += 5;
	else
		dir += 3;

		dir %= 4;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cin >> L;

	L++;

	while (L--) {
		func();

		if (isError) break;
	}

	cout << sec;

	return 0;
}
