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
#include<climits>

using namespace std;

const int MAX = 1e3;

int board[MAX][MAX];
int N, target;
int dirX[] = { 1, 0, -1, 0 };
int dirY[] = { 0, 1, 0, -1 };
pair<int, int> targetPoint;

void input() {
	cin >> N >> target;
}

void solution() {
	int Num = pow(N, 2);
	int curX, curY;
	curX = curY = 0;

	// 아래쪽, 오른쪽, 위쪽, 왼쪽 순서
	int dirNum = 0;

	while (Num) {
		board[curX][curY] = Num;

		if (Num == target) targetPoint = { curX + 1, curY + 1 };

		if (curX + dirX[dirNum] >= 0 && curX + dirX[dirNum] < N && curY + dirY[dirNum] >= 0 && curY + dirY[dirNum] < N && !board[curX + dirX[dirNum]][curY + dirY[dirNum]]) {
			curX += dirX[dirNum];
			curY += dirY[dirNum];
		}
		else {
			dirNum++;
			dirNum %= 4;

			curX += dirX[dirNum];
			curY += dirY[dirNum];
		}

		Num--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";

		cout << "\n";
	}
	cout << targetPoint.first << " " << targetPoint.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
