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

const int MAX = 5;

char board[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
set<int> list;

void input() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> board[i][j];
}

void dfs(int x, int y, string num) {
	if (num.length() == 6) {
		list.insert(stoi(num));

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < MAX && nextY >= 0 && nextY < MAX)
			dfs(nextX, nextY, num + board[nextX][nextY]);
	}
}

int solution() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			dfs(i, j, "");

	return list.size();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
