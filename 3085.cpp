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

const int MAX = 50;

int N;
int maxCandy = 0;
string board[MAX];
string arr[MAX];	// 인접한 사탕을 교환한 배열
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> board[i];
}

void checkCandyNum(int curX, int curY, int nextX, int nextY) {
	for (int i = 0; i < N; i++)
		arr[i] = board[i];

	char temp = arr[curX][curY];
	arr[curX][curY] = arr[nextX][nextY];
	arr[nextX][nextY] = temp;

	int len = 0;

	// 가로
	for (int i = 0; i < N; i++) {
		char before = ' ';
		int cnt = 1;

		for (int j = 0; j < N; j++) {
			if (before == arr[i][j])
				cnt++;
			else {
				len = max(len, cnt);
				cnt = 1;

				before = arr[i][j];
			}
		}

		len = max(len, cnt);
	}

	// 세로
	for (int j = 0; j < N; j++) {
		char before = ' ';
		int cnt = 1;

		for (int i = 0; i < N; i++) {
			if (before == arr[i][j])
				cnt++;
			else {
				len = max(len, cnt);
				cnt = 1;

				before = arr[i][j];
			}
		}

		len = max(len, cnt);
	}

	maxCandy = max(maxCandy, len);
}

void bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int nextX = i + dirX[k];
				int nextY = j + dirY[k];

				if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
					if (board[i][j] != board[nextX][nextY]) {

						checkCandyNum(i, j, nextX, nextY);
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

	bfs();

	cout << maxCandy;

	return 0;
}
