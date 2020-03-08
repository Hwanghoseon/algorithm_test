#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 20;
const int AZ = 'Z' - 'A' + 1;

char board[MAX][MAX];
bool alpha[AZ];
int R, C;
int cnt;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
vector<int> minCnt;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
}

bool check(int x, int y) { // 주변에 중복되지 않은 알파벳 있는지 확인
	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
			if (!alpha[board[nextX][nextY] - 'A']) {
				return true;
			}
		}
	}
	return false;
}

void func(int a, int b, int cnt) {

	alpha[board[0][0] - 'A'] = true;

	if (check(a, b)) {
		for (int i = 0; i < 4; i++) {
			int nextX = a + dirX[i];
			int nextY = b + dirY[i];

			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
				if (!alpha[board[nextX][nextY] - 'A']) {
					alpha[board[nextX][nextY] - 'A'] = true;
					func(nextX, nextY, cnt + 1);
					alpha[board[nextX][nextY] - 'A'] = false;
				}
			}
		}
	}
	else minCnt.push_back(cnt + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0, 0);

	sort(minCnt.begin(), minCnt.end(), desc);

	cout << minCnt.front();

	return 0;
}
