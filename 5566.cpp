#include<iostream>

using namespace std;

const int MAX = 1000 + 1;

int board[MAX];
int dice[MAX];
int n, m;

void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> board[i];

	for (int i = 1; i <= m; i++)
		cin >> dice[i];
}

int func() {
	int cur = 1;	// 말의 현재 위치
	int cnt = 0;	// 주사위 횟수

	for (int i = 1; i <= m; i++) {
		cnt++;

		cur += dice[i];
		cur += board[cur];

		if (cur >= n) break;
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << func();

	return 0;
}
